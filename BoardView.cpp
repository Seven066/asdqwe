#include "BoardView.h"
#include <QDebug>
#include <QMouseEvent>
#include "IFigure.h"
#include "Field.h"

BoardView::BoardView(Board *b, BoardScene *s) : QGraphicsView()
{
    Brd = b;
    Scene = s;
    setScene(Scene);
    setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));

    setFixedSize(300, 300);
    setSceneRect(0, 0, 300, 300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ActiveFigure = 0;
}

void BoardView::changeFixedSize(int size)
{
    setFixedSize(size, size);
    setSceneRect(0, 0, size, size);
}

void BoardView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "View pressed";
    QGraphicsItem *pressedItem = itemAt(event->pos());

    if (pressedItem != 0)
    {
        IFigure *fig = dynamic_cast<IFigure*>(pressedItem);
        Field *fld = dynamic_cast<Field*>(pressedItem);

        if (fig != 0)
        {
            ActiveFigure = fig;
        }

        if (fld != 0)
        {
            if (ActiveFigure != 0)
            {
                ActiveFigure->setPos(fld->pos());
                ActiveFigure = 0;
            }
        }
    }

    QGraphicsView::mousePressEvent(event);

}
