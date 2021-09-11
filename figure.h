#pragma once

#include "QGraphicsObject"

class Figure : public QGraphicsObject {

public:
    Figure(QPixmap pixmap, int pos);
    void setPos(int pos);
    void align();

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QRectF boundingRect() const override;

protected:
    QPixmap m_pixmap;
};
