/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

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
    void imprimirEscenarioGragico();
    void moverRobot(int x,int y);
    //Retorna un item del escenario
    int getItem(int x,int y);
    void setEscenario(int n, int m, int numeroObstaculos);
    bool movimientoIsValid(int i, int j);
    void setItem(int x,int y,int valor);

    int getRobotX(){ return robotX;}
    int getRobotY(){ return robotY;}
    int getSalidaX(){ return salidaX;}
    int getSalidaY(){ return salidaY;}

    void setMatrizEscenario(int **escenario,int robotX,int robotY,int salidaX,int salidaY);
    int ** getMatrizEscenario(){ return this->escenario;}

    void debug(){
        escenario=new int*[5];
        for(int i=0;i<n;i++){
            escenario[i]=new int[5];
        }

        escenario[0][0]=0;
        escenario[0][1]=0;
        escenario[0][2]=4;
        escenario[0][3]=0;
        escenario[0][4]=0;

        escenario[1][0]=0;
        escenario[1][1]=0;
        escenario[1][2]=4;
        escenario[1][3]=0;
        escenario[1][4]=0;

        escenario[2][0]=0;
        escenario[2][1]=0;
        escenario[2][2]=0;
        escenario[2][3]=0;
        escenario[2][4]=5;

        escenario[3][0]=0;
        escenario[3][1]=1;
        escenario[3][2]=4;
        escenario[3][3]=0;
        escenario[3][4]=0;

        escenario[4][0]=0;
        escenario[4][1]=0;
        escenario[4][2]=4;
        escenario[4][3]=0;
        escenario[4][4]=0;

        robotX=3;
        robotY=1;

        salidaX=2;
        salidaY=4;

    }

};

#endif // ESCENARIO_H
