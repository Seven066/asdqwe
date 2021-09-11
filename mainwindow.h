#pragma once

#include <QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void addMenus();

private:
    QMenu *m_gameMenu;
    QMenu *m_helpMenu;
};
