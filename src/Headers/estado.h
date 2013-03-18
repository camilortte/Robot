#ifndef ESTADO_H
#define ESTADO_H

class Estado
{

private:
    int x;
    int y;

    int padreX;
    int padreY;

    int h;
    int g;
    int f;
public:
    Estado(int x,int y,int padreX,int padreY);

    void setPadre(int padrex,int padreY);
    void setH(int h);
    void setG(int g);

    int getPadreX();
    int getPadreY();
    int getX();
    int getY();
    int getH();
    int getG();
    int getF();
};

#endif // ESTADO_H
