#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"
#include "src/Headers/aestrella.h"

using namespace std;



int main(){
    Escenario *mapa=new Escenario(10,10,10);
    mapa->imprimirEscenario();
    AEstrella todo(mapa);
    todo.calcularCamino();



    return 0;
}

