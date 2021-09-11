#pragma once

#include <QGraphicsObject>

class Field : public QGraphicsObject
{
public:
    Field();

private:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;
    QRectF boundingRect() const override;

    QColor m_color;
    int m_size;
    int m_id;
};
