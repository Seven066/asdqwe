#pragma once

#include <QMainWindow>
#include <QMenuBar>

namespace Gui {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    void addMenus();
signals:

private:
    QMenu* m_gameMenu;
    QMenu* m_helpMenu;
};

}
