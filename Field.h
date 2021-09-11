#pragma once

#include <QGraphicsObject>

class Field : public QGraphicsObject
{
public:
    Field(const QColor color);
    QColor getColor() const;

    int getSize() const;
    void setSize(int value);

private:
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    virtual QRectF boundingRect() const;

    QColor Color;
    int Size;
};
