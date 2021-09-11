#pragma once

#include "Board.h"
#include "QGraphicsScene"

class BoardScene : public QGraphicsScene
{
public:
    BoardScene(Board *b);

private:
    Board *Brd;
};
