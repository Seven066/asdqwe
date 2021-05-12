#include "Pawn.h"
#include <QPainter>
#include <QDebug>

Pawn::Pawn() : IFigure()
{
    Image.load("imgs\\AllFigures.png");
    Size = 30;
    SourceRect = QRectF(0,0,200,200);
    //setFlags(QGraphicsItem::ItemIsMovable);
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Pawn pressed";
    nextImg();
    update();
}

int Pawn::getSize() const
{
    return Size;
}

void Pawn::setSize(int value)
{
    Size = value;
}

void Pawn::nextImg()
{
    SourceRect.adjust(200,0,200,0);
    if (SourceRect.x()>1000)
    {
        if (SourceRect.y() == 200)
            SourceRect.moveTo(0,0);
        else
            SourceRect.moveTo(0,200);
    }
}

QRectF Pawn::boundingRect() const
{
    //return Image.rect();
    return QRectF(0,0,Size,Size);
}

void Pawn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF target(0,0,Size,Size);
    painter->drawPixmap(target, Image, SourceRect);
}



