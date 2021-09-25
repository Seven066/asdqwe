QT       += core gui widgets

TARGET = Chess
DESTDIR = $$PWD/bin/
TEMPLATE = app


SOURCES += \
    main.cpp\
    gui/mainwindow.cpp \
    gui/chessboard.cpp \
    gui/figure.cpp \

HEADERS  += \
    gui/mainwindow.h \
    gui/chessboard.h \
    gui/figure.h \

RESOURCES += \
    imgs.qrc
