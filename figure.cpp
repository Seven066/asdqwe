#include "figure.h"
#include "field.h"

#include <QPainter>

Figure::Figure(QPixmap pixmap, int pos) :
    m_pixmap(pixmap) {
    setPos(pos);
}

void Figure::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::gray);
    painter->setBrush(Qt::yellow);
    painter->drawPixmap(boundingRect().toRect(), m_pixmap);
    painter->restore();
}

QRectF Figure::boundingRect() const {
    return QRectF(0, 0, FIELDSIZE, FIELDSIZE);
}

void Figure::setPos(int pos) {
    QGraphicsObject::setPos(Field::fieldPos(pos));
}

void Figure::align() {
    QPoint p = (pos() / FIELDSIZE).toPoint();
    QGraphicsObject::setPos(p * FIELDSIZE);
}
