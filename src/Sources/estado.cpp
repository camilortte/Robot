#include "src/Headers/estado.h"

Estado::Estado(int x, int y, int padreX, int padreY)
{
    this->x=x;
    this->y=y;
    this->padreX=padreX;
    this->padreY=padreY;
    h=f=g=0;
}

void Estado::setPadre(int padrex, int padreY)
{
    this->padreX=padrex;
    this->padreY=padreY;
}

void Estado::setH(int h)
{
    this->h=h;
}

void Estado::setG(int g)
{
    this->g=g;
}

int Estado::getPadreX()
{
    return this->padreX;
}

int Estado::getPadreY()
{
    return this->padreY;
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


