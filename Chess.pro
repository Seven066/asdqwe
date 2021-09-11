#-------------------------------------------------
#
# Project created by QtCreator 2021-04-30T00:24:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Chess
DESTDIR = $$PWD/bin/
TEMPLATE = app


SOURCES += main.cpp\
    board.cpp \
    field.cpp \
    figure.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    board.h \
    field.h \
    figure.h

RESOURCES += \
    imgs.qrc
