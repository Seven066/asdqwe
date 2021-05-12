#include "BoardWidget.h"

#include <QPen>
#include <QBrush>
#include <QPainter>

#define SQSIZE 100

BoardWidget::BoardWidget() : QWidget()
{

}

void BoardWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.save();
    QBrush brush(Qt::red), brush2;
    brush2.setColor(Qt::darkGray);
    brush2.setStyle(Qt::DiagCrossPattern);
    painter.setPen(Qt::gray);
    painter.setBrush(Qt::red);

    for (int i = 0; i < 64; i++)
    {

        if ((i + i/8)%2)
            brush.setColor(Qt::blue);
        else
            brush.setColor(Qt::red);

        painter.setBrush(brush);

        painter.drawRect((i%8)*SQSIZE, (i/8)*SQSIZE, SQSIZE, SQSIZE);
        painter.setBrush(brush2);
        painter.drawRect((i%8)*SQSIZE, (i/8)*SQSIZE, SQSIZE, SQSIZE);
    }

    //painter.restore();
}

