#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define n 10
#define m 10
#define NUMERO_OBSTACULOS 5

using namespace std;

void crearParque();
void imprimirMapa();
double distanciaEntrePuntos(int,int);
bool movimientoPosible(int,int);
float menorHeuristica(float,float,float);
float menorHeuristica_1(float,float,float,float);
//int *obtenerMejorPosicion();
void moverArriba();
void moverAbajo();
void moverIzquierda();
void moverDerecha();
double calcularHeuristica();


int escenario[n][m];
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
    double h = distanciaEntrePuntos((int)abs(robx-salidax),(int)abs(roby-saliday));
    return h;
}

/*Verifica si es posible moverce a (i,j)*/
bool movimientoPosible(int i, int j){
    bool valido=false;
    if(i<0 || i>n || j<0 || j>m){
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

    double AEstretlla[]={-1,-1,-1,-1};

    moverArriba();
    if(robotx!=roboxAux || roboty!=roboyAux){
        AEstretlla[0]=calcularHeuristica(robotx,roboty)+1;
        roboxAux=robotx;
        roboyAux=roboty;
    }

    moverDerecha();
    if(robotx!=roboxAux || roboty!=roboyAux){
        AEstretlla[1]=calcularHeuristica(robotx,roboty)+1;
        roboxAux=robotx;
        roboyAux=roboty;
    }

    moverAbajo();
    if(robotx!=roboxAux || roboty!=roboyAux){
        AEstretlla[2]=calcularHeuristica(robotx,roboty)+1;
        roboxAux=robotx;
        roboyAux=roboty;
    }

    moverIzquierda();
    if(robotx!=roboxAux || roboty!=roboyAux){
        AEstretlla[3]=calcularHeuristica(robotx,roboty)+1;
        roboxAux=robotx;
        roboyAux=roboty;
    }

    double pminimo=AEstretlla[0];
    int item=0;
     for (int i=0;i<3;i++){ ///recorre
          if(AEstretlla[i]<pminimo && AEstretlla[i]!=-1){ //si encuentra //uno menor -> pminimo = ese menor
             pminimo=AEstretlla[i];
             item=i;
          }
      }

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


void moverArriba(){
    int rx=robotx;
    int ry=roboty;
    if(movimientoPosible(rx-1,ry)==true){
        if(escenario[rx-1][ry]==5){//llego
            salio=true;
        }
        escenario[rx-1][ry]=1;
        escenario[rx][ry]=0;
        robotx=rx-1;
        roboty=ry;
    }else{
        cout<<"movimiento invalido\n";
    }
}

void moverAbajo(){
    int rx=robotx;
    int ry=roboty;
    if(movimientoPosible(rx+1,ry)==true){
        if(escenario[rx+1][ry]==5){//llego
            salio=true;
        }
        escenario[rx+1][ry]=1;
        escenario[rx][ry]=0;
        robotx=rx+1;
        roboty=ry;
    }else{
        cout<<"movimiento invalido\n";
    }
}

void moverDerecha(){
    int rx=robotx;
    int ry=roboty;
    if(movimientoPosible(rx,ry+1)==true){
        if(escenario[rx][ry+1]==5){//llego
            salio=true;
        }
        escenario[rx][ry+1]=1;
        escenario[rx][ry]=0;
        robotx=rx;
        roboty=ry+1;
    }else{
        cout<<"movimiento invalido\n";
    }
}

void moverIzquierda(){
    int rx=robotx;
    int ry=roboty;
    if(movimientoPosible(rx,ry-1)==true){
        if(escenario[rx][ry-1]==5){//llego
            salio=true;
        }
        escenario[rx][ry-1]=1;
        escenario[rx][ry]=0;
        robotx=rx;
        roboty=ry-1;
    }else{
        cout<<"\n\n!movimiento invalido!\n\n";
    }
}



void menu(){
    int input=1;

    do{
            cout<<"\n\n1. mover a la Derecha.\n";
            cout<<"2. mover a la Izquierda.\n";
            cout<<"3. mover hacia Arriba.\n";
            cout<<"4. mover hacia Abajo.\n";
            cout<<"5. ver mapa.\n";
            cout<<"6. ver heuristica.\n";
            cout<<"7. reccomendacion.\n";
            cout<<"0. Salir.\n";
            cout<<"Seleccion: ";
            cin>>input;

            switch ( input ) {
            case 1:
                moverDerecha();
                imprimirMapa();
                break;
            case 2:
                moverIzquierda();
                imprimirMapa();
                break;
            case 3:
                moverArriba();
                imprimirMapa();
                break;
            case 4:
                moverAbajo();
                imprimirMapa();
                break;
            case 5:
                imprimirMapa();
                imprimirMapa();
                break;
            case 6:

                break;
            case 0:
                exit(0);
                break;
            case 7:
                //verRecomendacion();
                break;
            default:
                cout<<"opcion no valida";
            }
    }while (input != 0);
}

int main(){
    crearParque();
    imprimirMapa();
    cout<<endl<<endl;
    int i=0;
    while(robotx!=salidax || roboty!=saliday){
        generacionDeHijos();
        imprimirMapa();
        cout<<endl<<endl;
        cin>>i;
    }

    /*cout<<"\n";
    cout<<"heuristica del robot: ";
    cout<<"  h:"<<calcularHeuristica(robotx,roboty,salidax,saliday);

    system("pause");
    menu();
    */

    return 0;
}

