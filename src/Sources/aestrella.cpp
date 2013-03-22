/*
    Author: Camilo Antonio Ramirez Morales.
    Email: camilortte@hotmail.com
    Twitter: @camilortte
*/

#include "src/Headers/aestrella.h"

using namespace std;

AEstrella::AEstrella(Escenario *mapa)
{
    robot=NULL;
    this->mapa=mapa;
}

AEstrella::AEstrella()
{
    robot=NULL;
    mapa=new Escenario(10,10,10);
}

bool AEstrella::calcularCamino()
{

    int robotX=mapa->getRobotX();
    int robotY=mapa->getRobotY();
    //El estado inicial lo almacenamos en la lista abierta
    robot=new Estado(robotX,robotY,NULL);
    robot->setH(heuristica(robotX,robotY));
    robot->setG(10);

    //almacenamos todos los suceros de A en la lista abierta
    agregarSucesores(robot);

    //Quitamos A de la lista abierta y la agregamos  a la lista cerrada
    /*listaCerrada.push_back(listaAbierta[0]);
    listaAbierta.erase(listaAbierta.begin());*/


    listaCerrada2.insert(*listaAbierta2.begin());
   // listaAbierta2.erase(listaAbierta2.begin());

    int sx=-1;
    int sy=-1;

    while((sx!=mapa->getSalidaX()|| sy!=mapa->getSalidaY()) && listaAbierta2.empty()!=true ){
        Estado *auxiliar=*listaAbierta2.begin();
        listaCerrada2.insert(auxiliar);
        listaAbierta2.erase(listaAbierta2.begin());
        agregarSucesores(auxiliar);

        sx=auxiliar->getX();
        sy=auxiliar->getY();
        salida=auxiliar;

    }

    segmentarCamino();
    cout<<endl;
    mapa->imprimirEscenarioGragico();
    cout<<endl;
    mapa->imprimirEscenario();




    //===========ZONA_DEBUG========================
    /*set<Estado*>::iterator it;
    cout<<"Se va a imprimir: "<<endl;
    for (it=listaAbierta2.begin(); it!=listaAbierta2.end(); ++it){
        cout<<(*it)->getX()<<" "<<(*it)->getY()<<" heuristica:"<<(*it)->getH()<<endl;
        //cout<<(*it)->getX();
    }
    cout<<"Se imprimio"<<endl;


    cout<<"Se va a imprimir: "<<endl;
    for(int i=0;i<listaAbierta.size();i++){
        cout<<listaAbierta[i]->getX()<<" "<<listaAbierta[i]->getY()<<" heuristica:"<<listaAbierta[i]->getH()<<endl;
    }
    cout<<"Se imprimio: "<<endl;

    cout<<"Se va a imprimir ListaCerrada: "<<endl;
    for (it=listaCerrada2.begin(); it!=listaCerrada2.end(); ++it){
        cout<<(*it)->getX()<<" "<<(*it)->getY()<<" heuristica:"<<(*it)->getH()<<endl;
        //cout<<(*it)->getX();
    }
    cout<<"Se imprimio"<<endl;

    cout<<endl;*/

    //===========END_DEBUG=========================

    if(listaAbierta2.empty() && (sx!=mapa->getSalidaX()|| sy!=mapa->getSalidaY()) )
        return false;
    else
        return true;
}

//H = 10*(abs(Xactual-Xdestino) + abs(Yactual-Ydestino))  Metodo manhattan
int AEstrella::heuristica(int x, int y)
{
    return 10*(abs(x-mapa->getSalidaX()) + abs(y-mapa->getSalidaY()));
}

//modifica el escenario para que se vea la solucion del camino
void AEstrella::segmentarCamino()
{
    Estado *auxliar=salida;
    while(auxliar!=NULL){
        //cout<<auxliar->getX()<<" <-> "<<auxliar->getY()<<endl;
        mapa->setItem(auxliar->getX(),auxliar->getY(),7);
        auxliar=auxliar->getPadre();
    }
}


//AGrega los sucesores de un estado a la lista abierta , si no existe en la lista
//abierta y en la cerrada
void AEstrella::agregarSucesores(Estado *estadoPadre){

    int estadoPadreX=estadoPadre->getX();
    int estadoPadreY=estadoPadre->getY();
    Estado *estado;
    for(int i=0;i<4;i++){
        switch (i){
        case 0:
            if(mapa->getItem(estadoPadreX-1,estadoPadreY)!=-1){
                estado=new Estado(estadoPadreX-1,estadoPadreY,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX-1,estadoPadreY));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    listaAbierta2.insert(estado);

            }
            break;
        case 1:
            if(mapa->getItem(estadoPadreX,estadoPadreY+1)!=-1){
                estado=new Estado(estadoPadreX,estadoPadreY+1,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX,estadoPadreY+1));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        case 2:
            if(mapa->getItem(estadoPadreX+1,estadoPadreY)!=-1){
                estado=new Estado(estadoPadreX+1,estadoPadreY,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX+1,estadoPadreY));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        case 3:
            if(mapa->getItem(estadoPadreX,estadoPadreY-1)!=-1){
                estado=new Estado(estadoPadreX,estadoPadreY-1,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX,estadoPadreY-1));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        }

    }
}


/*Ojo quedo muy gamin esa forma de buscar , hay que mejorar el algoritmo*/
//Rertorna true si lo encontro , de lo contrario false
bool AEstrella::comprobarListaCerrada(Estado *estado)
{
    set<Estado*>::iterator it;
    for (it=listaCerrada2.begin(); it!=listaCerrada2.end(); ++it){
        if((*it)->getX()==estado->getX() && (*it)->getY()==estado->getY()){
            return true;
        }
    }
    return false;
}
