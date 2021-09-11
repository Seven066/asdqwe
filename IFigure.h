#pragma once

#include "QGraphicsObject"

class IFigure : public QGraphicsObject
{
public:
    IFigure();

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};
