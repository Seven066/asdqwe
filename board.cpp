#include "board.h"
#include "field.h"
#include "figure.h"

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

Board::Board() {
    QColor border("#764a34");
    setBackgroundBrush(border);

    m_view = new QGraphicsView(this);
    m_view->setFixedSize(FIELDSIZE * 8.5, FIELDSIZE * 8.5);
    setSceneRect(QRectF(0, 0,
                        FIELDSIZE * 8, FIELDSIZE * 8));

    for (int i = 0; i < 64; i++)
        addItem(new Field);

    enum FPix {
        wking, wqueen, wbishop, wknight, wrook, wpawn,
        bking, bqueen, bbishop, bknight, brook, bpawn
    };

    for (int i = 8; i > 0; i--)
        addFigure(wpawn, 56 - i);
    addFigure(wrook, 56);
    addFigure(wknight, 57);
    addFigure(wbishop, 58);
    addFigure(wqueen, 59);
    addFigure(wking, 60);
    addFigure(wbishop, 61);
    addFigure(wknight, 62);
    addFigure(wrook, 63);

    addFigure(brook, 0);
    addFigure(bknight, 1);
    addFigure(bbishop, 2);
    addFigure(bqueen, 3);
    addFigure(bking, 4);
    addFigure(bbishop, 5);
    addFigure(bknight, 6);
    addFigure(brook, 7);
    for (int i = 8; i > 0; i--)
        addFigure(bpawn, 16 - i);
}

QWidget *Board::widget() const {
    return m_view;
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QList<QGraphicsItem*> list = items(event->scenePos());
    for (auto i : list) {
        Figure *f = dynamic_cast<Figure*>(i);
        if (f) {
            m_grabFigure = f;
            i->setZValue(1);
        }
    }
}

void Board::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_grabFigure) {
        static_cast<QGraphicsItem*>(m_grabFigure)->
                setPos(event->scenePos() - QPointF(FIELDSIZE / 2, FIELDSIZE / 2));
    }
}

void Board::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_grabFigure) {
        m_grabFigure->align();
        m_grabFigure->setZValue(0);
        QList<QGraphicsItem*> list = items(event->scenePos());
        for (auto i : list) {
            Figure *f = dynamic_cast<Figure*>(i);
            if (f && f != m_grabFigure) {
                removeItem(f);
            }
        }
        m_grabFigure = nullptr;
    }
}

void Board::addFigure(int id, int pos) {
    static const int sq = 200;
    static QPixmap fp(":/figures/imgs/AllFigures.png");
    QPixmap p = fp.copy(QRect(id % 6 * sq,  id / 6 * sq, sq, sq));
    Figure *f = new Figure(p, pos);
    addItem(f);
}
