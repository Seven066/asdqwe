#pragma once

#include "figure.h"
#include <QPixmap>

class Pawn : public Figure
{
public:
    Pawn();
    QString name() override;
};
