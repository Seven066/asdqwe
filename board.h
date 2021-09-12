#pragma once

#include <QGraphicsScene>

class Figure;

class Board : public QGraphicsScene {

public:
    Board();
    void newGame();
    QWidget *widget() const;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void startPosition();
    void addFigure(int id, int pos);
private:
    QGraphicsView *m_view;
    Figure *m_grabFigure;
};

