#pragma once

#include <QGraphicsView>

#include "Board.h"
#include "BoardScene.h"

class IFigure;
class Field;

class BoardView : public QGraphicsView
{
public:
    BoardView(Board *b, BoardScene *s);

    void changeFixedSize(int size);

private:
    Board *Brd;
    BoardScene *Scene;
    IFigure *ActiveFigure;


    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};
