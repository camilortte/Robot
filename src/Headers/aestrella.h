/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

#ifndef AESTRELLA_H
#define AESTRELLA_H
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <set>

using namespace std;

//Gracias a esto el multiset puede comprara objetos =D , casi que no
struct Cmp {
    bool operator()( Estado *s1, Estado *s2 ) const {
        if(s1->getF()<=s2->getF()){
            if(s1->getX()!=s2->getX() || s1->getY()!=s2->getY())
                return true;
            else
                return false;
        }else{
            return false;
        }

        //return s1->getF()<s2->getF() && si ? true : false ;
    }
};


class AEstrella
{
private:
    vector <Estado*> listaAbierta;
    vector <Estado*> listaCerrada;
    Estado      *robot;
    Escenario   *mapa;
    Estado *salida;
    void agregarSucesores(Estado *estadoPadre);
    bool comprobarListaCerrada(Estado *estado);
    set <Estado*,Cmp> listaAbierta2;
    set <Estado*,Cmp> listaCerrada2;

public:
    AEstrella(Escenario *mapa);
    AEstrella();
    bool calcularCamino();
    int heuristica(int x, int y);
    void segmentarCamino();


};

#endif // AESTRELLA_H
