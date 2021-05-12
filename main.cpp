#include "mainwindow.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            QSize(100,100),  // Меньше чем нужен. Будет увеличен до необходимого
            qApp->desktop()->availableGeometry()
        )
    );
    w.show();

    return a.exec();
}
