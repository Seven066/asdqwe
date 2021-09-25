#include "mainwindow.h"

#include <QLabel>
#include <QMenuBar>
#include <QVBoxLayout>

#include "gui/chessboard.h"

namespace Gui {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    Gui::ChessBoard* board = new Gui::ChessBoard();
    QWidget* dummy = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(dummy);
    mainLayout->addWidget(new QLabel("Black"));
    mainLayout->addWidget(board->widget());
    mainLayout->addWidget(new QLabel("White"));
    setCentralWidget(dummy);
    setFixedSize(x(), y());

    board->setfen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    connect(board, &Gui::ChessBoard::positionUpdated, this, [](const QString& fen) {
        //send position to server
    });

    addMenus();
}

void MainWindow::addMenus()
{
    m_gameMenu = menuBar()->addMenu("&Game");
    m_helpMenu = menuBar()->addMenu("&Help");
    m_helpMenu->addAction("About");
    //  m_gameMenu->addAction("New", [this]() { m_board->newGame(); });
    m_gameMenu->addSeparator();
    m_gameMenu->addAction("Exit", [this]() { close(); });
}
}
