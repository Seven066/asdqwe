#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    BoardWidget();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BOARDWIDGET_H
