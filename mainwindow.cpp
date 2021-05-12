#include "mainwindow.h"
#include "BoardWidget.h"
#include "Board.h"
#include "BoardView.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    addMenus();

//    BoardWidget *bw = new BoardWidget();
    Board *b = new Board();
    QWidget *cw = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(cw);
    mainLayout->addWidget(new QLabel("lbl1"));
    mainLayout->addWidget(b->getView());
    mainLayout->addWidget(new QLabel("lbl2"));

    setCentralWidget(cw);
}

MainWindow::~MainWindow()
{

}

MainWindow::addMenus()
{
    menu1 = menuBar()->addMenu("&File");
    menu2 = menuBar()->addMenu("&Gile");
}
