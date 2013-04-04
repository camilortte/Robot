/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

#include "src/Headers/escenario.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//constructor , recibe filas , colummnas , numero de obstaculos
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



//genera la aleatoriedad del escenario
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

//Imprime el escenario en la consola
void Escenario::imprimirEscenario()
{
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<escenario[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Escenario::imprimirEscenarioGragico()
{
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                switch (escenario[i][j]) {
                case 0:
                    cout<<" _ ";
                    break;
                case 1:
                    cout<<" R ";
                    break;
                case 2:
                    cout<<" * ";
                    break;
                case 4:
                    cout<<" * ";
                    break;
                case 3:
                    cout<<" _ ";
                    break;
                case 5:
                    cout<<" S ";
                    break;
                case 7:
                    cout<<" R ";
                    break;
                }
                //1cout<<escenario[i][j]<<" ";

            }
            cout<<endl;
        }
}

//Mueve el robot a una posicion x , y
void Escenario::moverRobot(int x, int y)
{
    escenario[robotX][robotY]=0;
    if(x>=0 && x<n && y>=0 && y<m){
        escenario[x][y]=1;
        robotX=x;
        robotY=y;
    }
}

/*Si es una coordenada valida retorna
su contenido , de lo contrario retorna
-1*/
int Escenario::getItem(int x, int y)
{
    if(movimientoIsValid(x,y))
        return escenario[x][y];
    else
        return -1;
}

//Modifica el tamanio del escenario  , los obstaculos y regenera uno nuevo.
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

bool Escenario::movimientoIsValid(int i, int j)
{
    bool valido=false;
    if(i<0 || i>=n || j<0 || j>=m){
        valido=false;
    }else{
        if(escenario[i][j]!=2 && escenario[i][j]!=4){
            valido=true;
        }else{
            valido=false;
        }
    }
    return valido;
}

void Escenario::setItem(int x, int y, int valor)
{
    this->escenario[x][y]=valor;
}

void Escenario::setMatrizEscenario(int **escenario,int robotX,int robotY,int salidaX,int salidaY)
{
    this->escenario=escenario;
    this->robotX=robotX;
    this->robotY=robotY;

    this->salidaX=salidaX;
    this->salidaY=salidaY;
}



