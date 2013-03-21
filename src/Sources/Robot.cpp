#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"


using namespace std;



int main(){
    Escenario mapa(10,10,5);
    mapa.imprimirEscenario();
    mapa.moverRobot(2,3);
    cout<<endl;
    mapa.imprimirEscenario();
    return 0;
}

