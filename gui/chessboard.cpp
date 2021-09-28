#include "chessboard.h"

#include "figure.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <sstream>
#include <unordered_map>

namespace Gui {

const QColor border("#764a34");
const QColor white("#f0dab5");
const QColor black("#b58763");

ChessBoard::ChessBoard()
    : m_view(new QGraphicsView(this))
    , m_dragItem(nullptr)
{
    m_view->setFixedSize(FIELDSIZE * 8.5, FIELDSIZE * 8.5);
    setSceneRect(QRectF(0, 0, FIELDSIZE * 8, FIELDSIZE * 8));
}

QWidget* ChessBoard::widget() { return m_view; }

void ChessBoard::setfen(const std::string& fen)
{
    clear();
    int file = 0;
    int rank = 0;
    for (auto c : fen) {
        if (c == ' ')
            break;
        if (c == '/') {
            file = 0;
            rank++;
            continue;
        }
        if (c > '0' && c <= '8') {
            file += c - '0';
            continue;
        }

        addFigure(c, QPoint(file, rank % 8));
        file++;
    }
}

std::string ChessBoard::fen()
{
    std::stringstream fen;
    for (int i = 0; i < 8; i++) {
        int empty = 0;
        for (int j = 0; j < 8; j++) {
            QPoint p(j * FIELDSIZE, i * FIELDSIZE);
            auto it = items(p);
            if (it.size() == 1) {
                Figure* fig = dynamic_cast<Figure*>(it.first());
                if (fig) {
                    if (empty) {
                        fen << empty;
                        empty = 0;
                    }
                    fen << fig->toChar();
                }
            } else
                empty++;
        }
        if (empty)
            fen << empty;
        if (i == 7)
            break;
        fen << '/';
    }
    return fen.str();
}

void ChessBoard::drawBackground(QPainter* painter, const QRectF& rect)
{
    painter->fillRect(rect, border);

    QGraphicsScene::drawBackground(painter, rect);
    QColor color;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            color = (j + i) % 2 ? white : black;
            painter->fillRect(
                QRect(j * FIELDSIZE, i * FIELDSIZE, FIELDSIZE, FIELDSIZE), color);
        }
    }
}

void ChessBoard::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    auto list = items(event->scenePos());
    for (auto i : list) {
        if (dynamic_cast<Figure*>(i)) {
            i->setPos(event->scenePos() - i->boundingRect().bottomRight() / 2);
            m_dragItem = i;
            m_dragItem->setZValue(1);
            break;
        }
    }
}

void ChessBoard::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_dragItem) {
        m_dragItem->setPos(event->scenePos() - m_dragItem->boundingRect().bottomRight() / 2);
    }
}

void ChessBoard::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    Figure* fig = dynamic_cast<Figure*>(m_dragItem);
    if (fig) {
        m_dragItem->setZValue(0);
        m_dragItem = nullptr;

        auto list = items(event->scenePos());
        for (auto i : list) {
            Figure* fig2 = dynamic_cast<Figure*>(i);
            if (fig2 && fig != fig2) {
                if (fig->isWhite() == fig2->isWhite()) {
                    fig->undo();
                    return;
                }
                removeItem(fig2);
            }
        }
        if (!sceneRect().contains(event->scenePos())) {
            fig->undo();
            return;
        }
        if (fig->align())
            emit positionUpdated(QString::fromStdString(fen()));
    }
}

void ChessBoard::addFigure(char c, QPoint pos)
{
    static const int sq = 200;
    static const QPixmap fp(":/figures/imgs/AllFigures.png");
    enum FPix {
        wking,
        wqueen,
        wbishop,
        wknight,
        wrook,
        wpawn,
        bking,
        bqueen,
        bbishop,
        bknight,
        brook,
        bpawn
    };
    static const std::unordered_map<char, FPix> hash {
        { 'r', brook }, { 'b', bbishop }, { 'n', bknight },
        { 'k', bking }, { 'q', bqueen }, { 'p', bpawn },
        { 'R', wrook }, { 'B', wbishop }, { 'N', wknight },
        { 'K', wking }, { 'Q', wqueen }, { 'P', wpawn }
    };

    int id = hash.at(c);
    QPixmap p = fp.copy(QRect(id % 6 * sq, id / 6 * sq, sq, sq));
    Figure* f = new Figure(p, pos, c);
    addItem(f);
}

} // namespace Gui
