#include "mainwindow.h"

#include "board.h"
#include "board_view.h"

#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    addMenus();

    Board *board = new Board();
    QWidget *dummy = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(dummy);
    mainLayout->addWidget(new QLabel("Black"));
    mainLayout->addWidget(board->getView());
    mainLayout->addWidget(new QLabel("White"));

    setCentralWidget(dummy);
}

void MainWindow::addMenus() {
    m_gameMenu = menuBar()->addMenu("&Game");
    m_helpMenu = menuBar()->addMenu("&Help");
    m_helpMenu->addAction("About");
    m_gameMenu->addAction("New");
    m_gameMenu->addSeparator();
    m_gameMenu->addAction("Exit", [this](){ close(); });
}
