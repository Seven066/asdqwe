#include "field.h"
#include <QPainter>
#include <QDebug>

const int FIELDSIZE = 40;

Field::Field() {
    static int id = 0;
    m_id = id++;

    const QColor white(236,220,205,255);
    const QColor black(134,118,102,255);

    m_color = (m_id + m_id / 8) % 2 ? black : white;
    m_size = FIELDSIZE;
    setPos((m_id % 8 ) * FIELDSIZE, (m_id / 8) * FIELDSIZE);
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::gray);
    painter->setBrush(m_color);
    painter->drawRect(boundingRect());

    painter->restore();
}

QRectF Field::boundingRect() const
{
    return QRectF(0, 0, m_size, m_size);
}
