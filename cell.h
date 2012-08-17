#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    Cell();
    void clear();
    void fill(int type);
    unsigned int direction;
    int type;
    int numTurn;
};

#endif // CELL_H
