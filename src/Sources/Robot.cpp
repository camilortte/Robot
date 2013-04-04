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
    cout<<endl;
    if(!todo.calcularCamino()){
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<todo.numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          todo.numeroDeNodosVisitados()<<endl;
    cout<<"Contador tiempo: "<<todo.contadorTiempo<<" Unidades "<<endl;


    cout<<"------------------------------------------------------------------------"<<endl<<endl<<endl;

    mapa=new Escenario(10,10,20);
    mapa->imprimirEscenarioGragico();
    Grey *grey=new Grey(mapa);
    cout<<endl<<endl;
    if(!grey->calcularCamino()){
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<grey->numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          grey->numeroDeNodosVisitados()<<endl;
    cout<<"Contador tiempo: "<<grey->contadorTiempo<<" Unidades "<<endl<<endl;



    return 0;
}

