#ifndef PAWN_H
#define PAWN_H

#include "IFigure.h"
#include <QPixmap>

class Pawn : public IFigure
{
public:
    Pawn();

private:
    QPixmap Image;
    int Size;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getSize() const;
    void setSize(int value);

    //Debug func
private:
    void nextImg();
    QRectF SourceRect;
};

#endif // PAWN_H
