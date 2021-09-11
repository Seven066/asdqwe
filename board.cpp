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
    m_view->setFixedSize(FIELDSIZE * 9, FIELDSIZE * 9);

    for (int i = 0; i < 64; i++)
        addItem(new Field);

    const int sq = 200;

    QPixmap fp(":/figures/imgs/AllFigures.png");
    QPixmap p = fp.copy(5 * sq, 0, sq, sq);
    for (int i = 8; i > 0; i--) {
        Figure *wpawn = new Figure(p, 56 - i);
        addItem(wpawn);
    }

    p = fp.copy(0, 0, sq, sq);
    Figure *wking = new Figure(p, 60);
    addItem(wking);

    p = fp.copy(0, 1 * sq, sq, sq);
    Figure *bking = new Figure(p, 4);
    addItem(bking);

    p = fp.copy(5 * sq, sq, sq, sq);
    for (int i = 8; i > 0; i--) {
        Figure *bpawn = new Figure(p, 16 - i);
        addItem(bpawn);
    }

}

QWidget *Board::widget() const {
    return m_view;
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QList<QGraphicsItem*> list = items(event->scenePos());
    for (auto i : list) {
        Figure *f = dynamic_cast<Figure*>(i);
        if (f) {
            m_activeFigure = f;
        }
    }
}

void Board::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeFigure)
        static_cast<QGraphicsItem*>(m_activeFigure)->setPos(event->scenePos() - QPointF(FIELDSIZE / 2, FIELDSIZE / 2));
}

void Board::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeFigure) {
        m_activeFigure->align();
        m_activeFigure = nullptr;
    }
}
