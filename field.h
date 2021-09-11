#pragma once

#include <QGraphicsObject>

enum { FIELDSIZE = 70 };

class Field : public QGraphicsObject {

public:
    Field();
    static QPointF fieldPos(int pos);

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    QColor m_color;
    int m_id;
};
