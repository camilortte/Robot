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
float distanciaEntrePuntos(int,int);
int mayor(int,int);
int menor(int,int);
bool movimientoPosible(int,int);
char *obtenerMejorPosicion();
void moverArriba();
void moverAbajo();
void moverIzquierda();
void moverDerecha();

int escenario[n][m];
int robotx;
int roboty;
int salidax;
int saliday;

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
float distanciaEntrePuntos(int p1,int p2){
	return sqrt(pow(p1,2)+pow(p2,2));
}

/*devuelve el mayor entre dos numeros enteros*/
int mayor(int a,int b){
	if(a==b){
		return 0;
	}else{
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	return 0;
}

/*devuelve el menor entre dos numeros enteros*/
int menor(int a, int b){
	if(a==b){
		return 0;
	}else{
		if(a>b){
			return b;
		}else{
			return a;
		}
	}
	return 0;
}


/*calcula la heuristica del robot con respecto a la salida*/
float calcularHeuristica(int robotX, int robotY,int salidaX, int salidaY){
	float h = -1.0;
	if(robotX==salidaX){//misma fila
		if(robotY>salidaY){
			h = robotY-salidaY;
		}else{
			h = salidaY-robotY;
		}
	}else if (robotY==salidaY){//misma columana
		if(robotY>salidaY){
			h = robotX-salidaX;
		}else{
			h = salidaX-robotX;
		}
	}else{//no estan en la misma fila ni en la misma columana
		int x1,x2,y1,y2;
		x1=menor(robotX,salidaX);
		x2=mayor(robotX,salidaX);
		y1=menor(robotY,salidaY);
		y2=mayor(robotY,salidaY);
		h = distanciaEntrePuntos(x2-x1,y2-y1);
	}
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

char *obtenerMejorPosicion(){
   char* pos = new char[2];
   rx = robotx;
   ry = roboty;

   return pos;
}

void moverArriba(){
	int rx=robotx;
	int ry=roboty;
	if(movimientoPosible(rx-1,ry)==true){
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
                cout<<"heuristica :"<<calcularHeuristica(robotx,roboty,salidax,saliday);
                break;
			case 0:
				exit(0);
				break;
			default:
				cout<<"opcion no valida";
			}
	}while (input != 0);
}

int main(){
	crearParque();
	imprimirMapa();
	/*cout<<"\n";
	cout<<"heuristica del robot: ";
	cout<<"  h:"<<calcularHeuristica(robotx,roboty,salidax,saliday);

	system("pause");*/
	menu();
	return 0;
}

