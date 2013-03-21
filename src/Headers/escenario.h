#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>

class Escenario
{
private:
    int **escenario;
    int robotX;
    int robotY;
    int salidaX;
    int salidaY;
    int n,m;
    int numeroObstaculos;

public:
    Escenario(int n, int m,int numeroObstaculos);
    void reGenerarEscenario();
    void imprimirEscenario();
    void moverRobot(int x,int y);
    //Retorna un item del escenario
    int getItem(int x,int y){ return escenario[x][y];}
    void setEscenario(int n, int m, int numeroObstaculos);

    int getRobotX(){ return robotX;}
    int getRobotY(){ return robotY;}
    int getSalidaX(){ return salidaX;}
    int getSalidaY(){ return salidaY;}

};

#endif // ESCENARIO_H
