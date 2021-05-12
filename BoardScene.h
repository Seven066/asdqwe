#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include "Board.h"
#include "QGraphicsScene"

class BoardScene : public QGraphicsScene
{
public:
    BoardScene(Board *b);

private:
    Board *Brd;
};

#endif // BOARDSCENE_H
