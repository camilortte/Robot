#ifndef GREY_H
#define GREY_H

#include "src/Headers/aestrella.h"
#include "src/Headers/escenario.h"

class Grey: public AEstrella
{
public:
    Grey(Escenario *mapa);
    Grey();    
    int heuristica(int x, int y);
};

#endif // GREY_H
