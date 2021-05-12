#include "Board.h"
#include "Field.h"
#include "BoardView.h"
#include "BoardScene.h"
#include "IFigure.h"
#include "Pawn.h"

#define FIELDSIZE 40

Board::Board()
{
    Scene = new BoardScene(this);
    View = new BoardView(this, Scene);
    View->changeFixedSize(FIELDSIZE*8);
    QList<Field*> Fields;
    createFields();
    for (int i = 0; i < 1; i++)
    {
        Pawn *pwn = new Pawn();
        pwn->setSize(FIELDSIZE);
        pwn->setPos((i%8)*pwn->getSize(), (i/8)*pwn->getSize() + pwn->getSize());
        Scene->addItem(pwn);
    }
}

BoardView *Board::getView() const
{
    return View;
}

void Board::createFields()
{
    for (int i = 0; i<64; i++)
    {
        QColor clr;
        if ((i + i/8)%2)
            clr = QColor(134,118,102,255);
        else
            clr = QColor(236,220,205,255);
        Field *f = new Field();
        f->setSize(FIELDSIZE);
        f->setColor(clr);
        f->setPos((i%8)*f->getSize(), (i/8)*f->getSize());
        Scene->addItem(f);
    }

}

