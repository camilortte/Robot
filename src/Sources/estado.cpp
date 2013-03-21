#include "src/Headers/estado.h"

Estado::Estado(int x, int y, Estado *padre)
{
    this->x=x;
    this->y=y;
    h=f=g=0;
    this->padre=padre;
}



void Estado::setH(int h)
{
    f=h+g;
    this->h=h;
}

void Estado::setG(int g)
{
    f=h+g;
    this->g=g;
}



int Estado::getX()
{
    return this->x;
}

int Estado::getY()
{
    return this->y;
}

int Estado::getH()
{
    return this->h;
}

int Estado::getG()
{
    return this->g;
}

int Estado::getF()
{
    return this->f;
}


