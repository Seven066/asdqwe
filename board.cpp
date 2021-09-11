#include "board.h"
#include "field.h"
#include "figure.h"
#include "pawn.h"
#include "board_view.h"

const int FIELDSIZE = 40;

Board::Board() {
    setBackgroundBrush(Qt::white);

    m_view = new BoardView(this);
    m_view->changeFixedSize(FIELDSIZE * 8);

    for (int i = 0; i < 64; i++)
        addItem(new Field);

    Pawn *pwn = new Pawn();
    pwn->setPos(1 * FIELDSIZE, 1 * FIELDSIZE + FIELDSIZE);
    addItem(pwn);
}

BoardView *Board::getView() const
{
    return m_view;
}
