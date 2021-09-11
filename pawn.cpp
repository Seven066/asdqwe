#include "pawn.h"
#include <QPainter>
#include <QDebug>

Pawn::Pawn() : Figure()
{
    m_pixmap.load("imgs\\AllFigures.png");
}

QString Pawn::name()
{
    return "Pawn";
}



