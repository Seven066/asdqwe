#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QTimer>
#include <QVBoxLayout>

const ExitGames::Common::JString id("33cc839c-4ac0-494a-a742-afd1e3bdfec8");
const ExitGames::Common::JString version("");

namespace Gui {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_board = new Gui::ChessBoard();
    QWidget* dummy = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(dummy);
    mainLayout->addWidget(new QLabel("Black"));
    mainLayout->addWidget(m_board->widget());
    mainLayout->addWidget(new QLabel("White"));
    setCentralWidget(dummy);
    setFixedSize(x(), y());
    m_board->setfen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    connect(m_board, &Gui::ChessBoard::positionUpdated, this, [this](QString fen) {
        if (m_client->getIsInRoom()) {
            Common::Hashtable evData;
            Common::JString str(fen.toStdString().c_str());
            evData.put((nByte)10, str);
            m_client->opRaiseEvent(false, evData, 1);
            qDebug() << "Send event";
        }
    });

    addMenus();

    m_client = new ExitGames::LoadBalancing::Client(*this, id, version);
    m_client->connect();

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        m_client->service();
    });
    timer->start(100);

    m_box = new QMessageBox(QMessageBox::Information, "Chess onine", "Connecting...\nPlease wait!", QMessageBox::Cancel);
    connect(m_box, &QMessageBox::QDialog::rejected, this, []() {
        exit(1);
    });
    m_box->exec();
}

void MainWindow::debugReturn(int debugLevel, const Common::JString& string)
{
    qDebug() << string;
}

void MainWindow::joinRoomEventAction(int playerNr, const Common::JVector<int>& playernrs, const LoadBalancing::Player& player)
{
    qDebug() << "Player" << playerNr << "joined to the room";
    m_box->setText("Connected\nJoined to the room");
    m_box->accept();
}

void MainWindow::leaveRoomEventAction(int playerNr, bool isInactive)
{
    qDebug() << "Player" << playerNr << "left to the room";
}

void MainWindow::customEventAction(int playerNr, nByte eventCode, const Common::Object& eventContent)
{
    ExitGames::Common::Hashtable content = ExitGames::Common::ValueObject<ExitGames::Common::Hashtable>(eventContent).getDataCopy();
    Common::JString fen = ((Common::ValueObject<Common::JString>*)content.getValue((nByte)10))->getDataCopy();
    m_board->setfen(std::string(fen.UTF8Representation().cstr()));
}

void MainWindow::connectReturn(int errorCode, const Common::JString& errorString, const Common::JString& region, const Common::JString& cluster)
{
    qDebug() << "Connected";
    m_box->setText("Connected\nJoin to the room...");
    m_client->opJoinOrCreateRoom("test");
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
