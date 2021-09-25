#pragma once

#include <QGraphicsItem>

namespace Gui {

enum { FIELDSIZE = 70 };

class Figure : public QGraphicsItem {
public:
    Figure(QPixmap pixmap, QPoint pos, char c);
    bool setPos(QPoint pos);
    bool align();
    void undo();
    bool isWhite() { return std::isupper(m_c); }
    char toChar() { return m_c; }

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
        QWidget* widget) override;
    QRectF boundingRect() const override;

private:
    QPixmap m_pixmap;
    QPoint m_pos;
    char m_c;
};

}
