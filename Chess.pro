#-------------------------------------------------
#
# Project created by QtCreator 2021-04-30T00:24:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Chess
DESTDIR = $$PWD/
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    BoardWidget.cpp \
    Board.cpp \
    BoardScene.cpp \
    BoardView.cpp \
    Field.cpp \
    Pawn.cpp \
    IFigure.cpp \
    Figure.cpp

HEADERS  += mainwindow.h \
    BoardWidget.h \
    Board.h \
    BoardScene.h \
    BoardView.h \
    Field.h \
    Pawn.h \
    IFigure.h \
    Figure.h
