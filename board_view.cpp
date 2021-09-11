#include "board_view.h"
#include <QDebug>
#include <QMouseEvent>
#include "figure.h"
#include "field.h"

BoardView::BoardView(QGraphicsScene *scene) : QGraphicsView()
{
    setScene(scene);
    setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));

    setFixedSize(300, 300);
    setSceneRect(0, 0, 300, 300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_activeFigure = 0;
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
        Figure *fig = dynamic_cast<Figure*>(pressedItem);
        if (fig != nullptr)
        {
            qDebug() << fig->name() << " was pressed";
            m_activeFigure = fig;
        }

        Field *fld = dynamic_cast<Field*>(pressedItem);
        if (fld != nullptr)
        {
            if (m_activeFigure != 0)
            {
                m_activeFigure->setPos(fld->pos());
                m_activeFigure = 0;
            }
        }
    }

    QGraphicsView::mousePressEvent(event);

}
