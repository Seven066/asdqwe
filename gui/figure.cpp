#include "figure.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>

namespace Gui {

Figure::Figure(QPixmap pixmap, QPoint pos, char c)
    : m_pixmap(pixmap)
    , m_pos(pos)
    , m_c(c)
{
    QGraphicsItem::setPos(m_pos * FIELDSIZE);
    setAcceptDrops(true);
}

void Figure::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
    QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->drawPixmap(boundingRect().toRect(), m_pixmap);
    painter->restore();
}

QRectF Figure::boundingRect() const
{
    return QRectF(0, 0, FIELDSIZE, FIELDSIZE);
}

bool Figure::setPos(QPoint pos)
{
    bool newPos = m_pos != pos;
    m_pos = pos;
    QGraphicsItem::setPos(m_pos * FIELDSIZE);
    return newPos;
}

bool Figure::align()
{
    return setPos((pos() / FIELDSIZE).toPoint());
}

void Figure::undo()
{
    QGraphicsItem::setPos(m_pos * FIELDSIZE);
}

}
