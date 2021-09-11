#include "figure.h"

#include <QPainter>

QRectF Figure::boundingRect() const { return m_rect; }

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF target(0, 0, m_rect.x(), m_rect.y());
    painter->drawPixmap(target, m_pixmap, m_rect);
}
