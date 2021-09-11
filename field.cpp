#include "field.h"
#include <QPainter>
#include <QDebug>

Field::Field() {
    static int id = 0;
    m_id = id++;

    const QColor white("#f0dab5");
    const QColor black("#b58763");

    m_color = (m_id + m_id / 8) % 2 ? black : white;
    setPos(fieldPos(m_id));
}

QPointF Field::fieldPos(int pos) {
    return QPointF((pos % 8 ) * FIELDSIZE, (pos / 8) * FIELDSIZE);
}

void Field::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::gray);
    painter->setBrush(m_color);
    painter->drawRect(boundingRect());

    painter->restore();
}

QRectF Field::boundingRect() const {
    return QRectF(0, 0, FIELDSIZE, FIELDSIZE);
}
