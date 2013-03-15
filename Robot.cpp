#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define n 10
#define m 10
#define NUMERO_OBSTACULOS 10

using namespace std;

void crearParque();
void imprimirMapa();
double distanciaEntrePuntos(int,int);
bool movimientoPosible(int,int);
//int *obtenerMejorPosicion();
void moverArriba();
void moverAbajo();
void moverIzquierda();
void moverDerecha();
double calcularHeuristica();


int escenario[n][m];
int escenarioHeuristico[n][m];
int robotx;
int roboty;
int salidax;
int saliday;
bool salio=false;

void crearParque(){
    /*Generamos el lugar donde estara el robor*/
    srand(time(NULL));
    //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    robotx=0+rand() % (n);
    roboty=0+rand() % (3);


    escenario[robotx][roboty]=1;

    /*Se genera la salida en la ultima columna*/
    salidax=rand() % (n);
    saliday=m-1;
    escenario[salidax][m-1]=5;


    //cout<<"Salidax="<<salidax<<" "<<m<<endl;

    /*Generamos el rio con su puente*/
    int rioy=4+rand() % (m-2-4);
    while(rioy==roboty || rioy==m-1){
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

    for(int i=0;i<NUMERO_OBSTACULOS;i++){
        obstaculox= rand() % (n) ;
        obstaculoy= rand() % (m) ;
        while(obstaculoy==roboty || obstaculoy==rioy || escenario[obstaculox][obstaculoy]==2 ||
            escenario[obstaculox][obstaculoy+1]==3 || escenario[obstaculox][obstaculoy-1]==3 ||
            escenario[obstaculox][obstaculoy]==5 ){// || rescenario[obstaculox][obstaculoy+1    ]==5){
                obstaculox= rand() % (n) ;
                obstaculoy= rand() % (m) ;
            }
        escenario[obstaculox][obstaculoy]=2;
        //cout<<"Obstaculo en y= "<<obstaculoy<<endl;

    }
}

void imprimirMapa(){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<escenario[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*Devuele la distancia Entre dos puntos
haciendo uso del teorema de pitagoras*/
double distanciaEntrePuntos(int p1,int p2){
    return sqrt(pow(p1,2)+pow(p2,2));
}

/*calcula la heuristica del robot con respecto a la salida*/
double calcularHeuristica(int robx,int roby){
    //no estan en la misma fila ni en la misma columana
    return distanciaEntrePuntos((int)abs(robx-salidax),(int)abs(roby-saliday));
}

/*Verifica si es posible moverce a (i,j)*/
bool movimientoPosible(int i, int j){
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


void generacionDeHijos(){
    int roboxAux=robotx;
    int roboyAux=roboty;

    double AEstretlla[]={NULL,NULL,NULL,NULL};
    moverArriba();
    if(robotx!=roboxAux || roboty!=roboyAux){
        cout<<"Se movio el robot arriba: "<<robotx<<"_"<<roboty<<endl;
        AEstretlla[0]=calcularHeuristica(robotx,roboty)+1;
        escenario[roboxAux][roboyAux]=1;
        escenario[robotx][roboty]=0;
        robotx=roboxAux;
        roboty=roboyAux;
    }

    moverDerecha();
    if(robotx!=roboxAux || roboty!=roboyAux){
        cout<<"Se movio el robor derecha: "<<robotx<<"_"<<roboty<<endl;
        AEstretlla[1]=calcularHeuristica(robotx,roboty)+1;
        escenario[roboxAux][roboyAux]=1;
        escenario[robotx][roboty]=0;
        robotx=roboxAux;
        roboty=roboyAux;
    }

    moverAbajo();
    if(robotx!=roboxAux || roboty!=roboyAux){
        cout<<"Se movio el robor abajo: "<<robotx<<"_"<<roboty<<endl;
        AEstretlla[2]=calcularHeuristica(robotx,roboty)+1;
        escenario[roboxAux][roboyAux]=1;
        escenario[robotx][roboty]=0;
        robotx=roboxAux;
        roboty=roboyAux;
    }

    moverIzquierda();
    if(robotx!=roboxAux || roboty!=roboyAux){
        cout<<"Se movio el robor izquierda: "<<robotx<<"_"<<roboty<<endl;
        AEstretlla[3]=calcularHeuristica(robotx,roboty)+1;
        escenario[roboxAux][roboyAux]=1;
        escenario[robotx][roboty]=0;
        robotx=roboxAux;
        roboty=roboyAux;
    }

    double pminimo=AEstretlla[0];
    int item=0;
     for (int i=0;i<3;i++){ ///recorre
         if(pminimo==NULL){
             if(AEstretlla[i]!=NULL){
                 pminimo=AEstretlla[i];
                 item=i;
             }

         }else{
          if(AEstretlla[i]<pminimo && AEstretlla[i]!=NULL){ //si encuentra //uno menor -> pminimo = ese menor
             pminimo=AEstretlla[i];
             item=i;
          }
      }
     }
    cout<<"Se tendria que mover: "<<item<<endl;
    switch (item){
        case 0:
            moverArriba();
            break;
        case 1:
            moverDerecha();
            break;
        case 2:
            moverAbajo();
            break;
        case 3:
            moverIzquierda();
            break;
    }

}


//Operadores
void moverArriba(){
    int robotX=robotx;
    int robotY=roboty;
    if(robotX-1>=0){
        if(escenario[robotX-1][robotY]!=2 && escenario[robotX-1][robotY]!=4){
            escenario[robotX][robotY]=0;
            escenario[robotX-1][robotY]=1;
            robotx=robotX-1;
        }
    }
}

void moverAbajo(){
    int robotX=robotx;
    int robotY=roboty;
    if(robotX+1<n){
        if(escenario[robotX+1][robotY]!=2 && escenario[robotX-1][robotY]!=4){
            escenario[robotX][robotY]=0;
            escenario[robotX+1][robotY]=1;
            robotx=robotX+1;
        }
    }
}

void moverDerecha(){
    int robotX=robotx;
    int robotY=roboty;
    if(robotY+1<m){
        if(escenario[robotX][robotY+1]!=2 && escenario[robotX][robotY+1]!=4){
            escenario[robotX][robotY]=0;
            escenario[robotX][robotY+1]=1;
            roboty=robotY+1;
        }
    }
}

void moverIzquierda(){
    int robotX=robotx;
    int robotY=roboty;
    if(robotY-1>=0){
        if(escenario[robotX][robotY-1]!=2 && escenario[robotX][robotY-1]!=4){
            escenario[robotX][robotY]=0;
            escenario[robotX][robotY-1]=1;
            roboty=robotY-1;
        }
    }
}


int main(){
    crearParque();
    imprimirMapa();
    cout<<endl;
    int i=0;
    while(robotx!=salidax || roboty!=saliday){
        generacionDeHijos();
        imprimirMapa();
        cout<<endl<<endl;
        cin>>i;
    }
    return 0;
}

