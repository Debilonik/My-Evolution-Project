#include "cell.h"
#include "qmath.h"

Cell::Cell()
{
    clear();
}

void Cell::clear()
{
    //sets all info to null
    type = -1;
    direction = -1;
    numTurn = 0;
}

void Cell::fill(int type)
{
    direction = qrand()%4;
    this->type = type;
    if (type == 2) numTurn = 1;
}

