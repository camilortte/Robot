/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

#ifndef ESTADO_H
#define ESTADO_H

class Estado
{

private:
    int x;
    int y;

    Estado *padre;

    int h;
    int g;
    int f;
public:
    Estado(int x, int y, Estado *padre);

    void setPadre(Estado *padre);
    void setH(int h);
    void setG(int g);

    Estado *getPadre(){return this->padre;}
    int getX();
    int getY();
    int getH();
    int getG();
    int getF();
};

#endif // ESTADO_H
