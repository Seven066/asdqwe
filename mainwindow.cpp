#include "mainwindow.h"

#include "board.h"

#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    m_board = new Board();
    QWidget *dummy = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(dummy);
    mainLayout->addWidget(new QLabel("Black"));
    mainLayout->addWidget(m_board->widget());
    mainLayout->addWidget(new QLabel("White"));
    setCentralWidget(dummy);
    setFixedSize(x(), y());

    addMenus();
}

void MainWindow::addMenus() {
    m_gameMenu = menuBar()->addMenu("&Game");
    m_helpMenu = menuBar()->addMenu("&Help");
    m_helpMenu->addAction("About");
    m_gameMenu->addAction("New", [this](){ m_board->newGame(); });
    m_gameMenu->addSeparator();
    m_gameMenu->addAction("Exit", [this](){ close(); });
}
