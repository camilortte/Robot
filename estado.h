#ifndef ESTADO_H
#define ESTADO_H

class Estado
{

private:
    double costo;
    int item;
public:
    Estado(double costo,int item);
    void setCosto(double costo);
    void setItem(int item);
    double getCosto();
    int getItem();

};

#endif // ESTADO_H
