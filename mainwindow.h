#pragma once

#include <QMainWindow>
#include <QMenuBar>

class Board;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void addMenus();

private:
    Board *m_board;
    QMenu *m_gameMenu;
    QMenu *m_helpMenu;
};
