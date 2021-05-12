#ifndef FIGURE_H
#define FIGURE_H

#include "IFigure.h"

class Figure : public IFigure
{
public:
    Figure();

private:
    QPixmap Image;
    int Size;

//protected:
//    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getSize() const;
    void setSize(int value);
};

#endif // FIGURE_H
