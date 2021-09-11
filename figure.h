#pragma once

#include "QGraphicsObject"

class Figure : public QGraphicsObject
{
public:
    virtual QString name() = 0;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    QPixmap m_pixmap;
    QRectF m_rect;
};
