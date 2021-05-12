#include "BoardScene.h"

BoardScene::BoardScene(Board *b) : QGraphicsScene()
{
    Brd = b;
    setBackgroundBrush(Qt::white);
}

