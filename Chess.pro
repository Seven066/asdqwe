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
    board_view.cpp \
    field.cpp \
    figure.cpp \
        mainwindow.cpp \
    pawn.cpp

HEADERS  += mainwindow.h \
    board.h \
    board_view.h \
    field.h \
    figure.h \
    pawn.h
