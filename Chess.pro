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
        mainwindow.cpp \
    Board.cpp \
    BoardScene.cpp \
    BoardView.cpp \
    Field.cpp \
    Pawn.cpp \
    IFigure.cpp

HEADERS  += mainwindow.h \
    Board.h \
    BoardScene.h \
    BoardView.h \
    Field.h \
    Pawn.h \
    IFigure.h
