#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"


using namespace std;



int main(){
    Escenario mapa(20,20,5);
    mapa.imprimirEscenario();
    cout<<endl;
    mapa.setEscenario(20,20,20);
    mapa.imprimirEscenario();
    cout<<endl;

    mapa.setEscenario(20,20,15);
    mapa.imprimirEscenario();
    cout<<endl;

    mapa.setEscenario(20,20,30);
    mapa.imprimirEscenario();
    cout<<endl;

    return 0;
}

