/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"
#include "src/Headers/aestrella.h"
#include "src/Headers/grey.h"

using namespace std;



int main(){
    Escenario *mapa=new Escenario(10,10,20);
    //mapa->debug();
    mapa->imprimirEscenarioGragico();
    AEstrella todo(mapa);
    if(!todo.calcularCamino()){
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }

    cout<<"-----------------------------------------------------asas---------sass----------"<<endl<<endl<<endl;

    mapa=new Escenario(10,10,20);
    mapa->imprimirEscenarioGragico();
    Grey *grey=new Grey(mapa);
    cout<<endl<<endl;
    if(!grey->calcularCamino()){
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }



    return 0;
}

