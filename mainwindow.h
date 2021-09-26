#pragma once

#include <QMainWindow>

#include "LoadBalancing-cpp/inc/Client.h"
#include "gui/chessboard.h" 4

using namespace ExitGames;
class QMenuBar;
class QMessageBox;

namespace Gui {

class MainWindow : public QMainWindow, LoadBalancing::Listener {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

    // receive and print out debug out here
    void debugReturn(int debugLevel, const Common::JString& string);

    // implement your error-handling here
    void connectionErrorReturn(int errorCode) override { }
    void clientErrorReturn(int errorCode) override { }
    void warningReturn(int warningCode) override { }
    void serverErrorReturn(int errorCode) override { }

    // events, triggered by certain operations of all players in the same room
    void joinRoomEventAction(int playerNr, const Common::JVector<int>& playernrs, const LoadBalancing::Player& player) override;
    void leaveRoomEventAction(int playerNr, bool isInactive) override;

    void customEventAction(int playerNr, nByte eventCode, const Common::Object& eventContent) override;

    // callbacks for operations on the server
    void connectReturn(int errorCode, const Common::JString& errorString, const Common::JString& region, const Common::JString& cluster) override;
    void disconnectReturn(void) override { }
    void leaveRoomReturn(int errorCode, const Common::JString& errorString) override { }

private:
    void addMenus();
signals:

private:
    ExitGames::LoadBalancing::Client* m_client;
    Gui::ChessBoard* m_board;
    QMessageBox* m_box;
    QMenu* m_gameMenu;
    QMenu* m_helpMenu;
};

}
