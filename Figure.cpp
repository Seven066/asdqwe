#include "Figure.h"

Figure::Figure() : IFigure()
{
    Image.load("imgs\\AllFigures.png");
    Size = 30;
    SourceRect = QRectF(0,0,200,200);
    //setFlags(QGraphicsItem::ItemIsMovable);
}

QRectF Figure::boundingRect() const
{

}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF target(0,0,Size,Size);
    painter->drawPixmap(target, Image, SourceRect);
}

int Figure::getSize() const
{
        return Size;
}

void Figure::setSize(int value)
{
        Size = value;
}

