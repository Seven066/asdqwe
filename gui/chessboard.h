#pragma once

#include <QGraphicsScene>

namespace Gui {

class ChessBoard : public QGraphicsScene {
    Q_OBJECT
public:
    ChessBoard();
    QWidget* widget();
    void setfen(const std::string& fen);
    std::string fen();

signals:
    void positionUpdated(const QString& fen);

protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    void addFigure(char c, QPoint pos);
    QGraphicsView* m_view;
    QGraphicsItem* m_dragItem;
};

} // namespace Gui
