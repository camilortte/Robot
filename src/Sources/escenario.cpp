#include "src/Headers/escenario.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Escenario::Escenario(int n, int m,int numeroObstaculos)
{
    srand(time(NULL));
    this->n=n;
    this->m=m;
    this->numeroObstaculos=numeroObstaculos;
    escenario=new int*[n];
    for(int i=0;i<n;i++){
        escenario[i]=new int[m];        
    }   
    reGenerarEscenario();
}

void Escenario::reGenerarEscenario()
{
    //reseteamos todas las coordenadas a cero=0
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            escenario[i][j]=0;
        }
    }
    /*Generamos el lugar donde estara el robor*/
    //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    robotX=rand() % (n);
    robotY=rand() % (3);


    escenario[robotX][robotY]=1;

    /*Se genera la salida en la ultima columna*/
    salidaX=rand() % (n);
    salidaY=m-1;
    escenario[salidaX][m-1]=5;


    //cout<<"salidaX="<<salidaX<<" "<<m<<endl;

    /*Generamos el rio con su puente*/
    int rioy=4+rand() % (m-2-4);
    while(rioy==robotY || rioy==m-1){
        rioy=0+rand() % (m);
    }

    int puentex=0+rand() % (n);


    for(int i=0;i<n;i++){
        if(i==puentex){
            escenario[i][rioy]=3;
        }else{
            escenario[i][rioy]=4;
        }
    }

    /*Generamos los obstaculos*/
    int obstaculox= 0;
    int obstaculoy= 0;

    for(int i=0;i<numeroObstaculos;i++){
        obstaculox= rand() % (n) ;
        obstaculoy= rand() % (m) ;
        while(obstaculoy==robotY || obstaculoy==rioy || escenario[obstaculox][obstaculoy]==2 ||
              escenario[obstaculox][obstaculoy+1]==3 || escenario[obstaculox][obstaculoy-1]==3 ||
              escenario[obstaculox][obstaculoy]==5 ){// || rescenario[obstaculox][obstaculoy+1]==5){
            obstaculox= rand() % (n) ;
            obstaculoy= rand() % (m) ;
        }
        escenario[obstaculox][obstaculoy]=2;
    }
}

void Escenario::imprimirEscenario()
{
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<escenario[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Escenario::moverRobot(int x, int y)
{
    escenario[robotX][robotY]=0;
    if(x>=0 && x<n && y>=0 && y<m){
        escenario[x][y]=1;
        robotX=x;
        robotY=y;
    }
}

void Escenario::setEscenario(int n, int m,int numeroObstaculos)
{
    delete escenario;
    this->n=n;
    this->m=m;
    this->numeroObstaculos=numeroObstaculos;
    escenario=new int*[n];
    for(int i=0;i<n;i++){
        escenario[i]=new int[m];
    }
    reGenerarEscenario();
}



