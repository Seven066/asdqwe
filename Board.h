#ifndef BOARD_H
#define BOARD_H

#include <QList>

class BoardScene;
class BoardView;
class Field;

class Board
{
public:
    Board();

    BoardView *getView() const;

private:
    QList<Field*> Fields;
    void createFields();

    BoardScene *Scene;
    BoardView *View;
};

#endif // BOARD_H
