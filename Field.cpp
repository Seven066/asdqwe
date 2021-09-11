#include "Field.h"
#include <QPainter>

Field::Field(const QColor color) : QGraphicsObject(), Color(color)
{
    //setFlags(QGraphicsItem::ItemIsMovable);
    Size = 30;
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

    painter->setPen(Qt::gray);
    painter->setBrush(Color);
    painter->drawRect(boundingRect());

    painter->restore();
}

QRectF Field::boundingRect() const
{
    return QRectF(0,0,Size,Size);
}

int Field::getSize() const
{
    return Size;
}

void Field::setSize(int value)
{
    Size = value;
}
