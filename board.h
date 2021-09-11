#pragma once

#include <QGraphicsScene>

class BoardView;

class Board : public QGraphicsScene {
public:
    Board();
    BoardView *getView() const;

private:
    BoardView *m_view;
};

