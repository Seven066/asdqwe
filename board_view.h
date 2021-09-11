#pragma once

#include <QGraphicsView>

class Figure;
class Field;

class BoardView : public QGraphicsView
{
public:
    BoardView(QGraphicsScene *scene);

    void changeFixedSize(int size);

private:
    Figure *m_activeFigure;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
