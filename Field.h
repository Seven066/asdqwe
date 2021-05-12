#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsObject>

class Field : public QGraphicsObject
{
public:
    Field();
    QColor getColor() const;
    void setColor(const QColor &value);

    int getSize() const;
    void setSize(int value);

private:
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    virtual QRectF boundingRect() const;

    QColor Color;
    int Size;
};

#endif // FIELD_H
