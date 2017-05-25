#include <iostream>
#include<fstream>
#include <string>
#include <cstring>
#include "Lista.h"
using namespace std;
struct entrenador{
	string nombre,apellido,nacionalidad,seleccion;
};

struct jugador{//datos del jugador 
	string nombre,apellido,nacionalidad,club,posicion;
	int numGoles;
	string estatura;
	string fechaNacimiento;
};
struct equipo{
	string pais, confederacion , puesto;
	Lista<jugador> j;
	entrenador e;
};
class Datos{
	public:
	
	void agregarDatosEquipos(Lista<equipo> *equipos);
	void imprimirEquipo(Lista<equipo> equipos);
	void imprimirJugadores(Lista<equipo> equipos,int numequipo);
	void agregarJugadores(Lista<equipo> *equipos);

};

void Datos::agregarJugadores(Lista<equipo> *equipos){
	//agregar jugadores
		jugador jugadorAux;//Jugador que almacena temporalmente los datos
		ifstream entradaJugadores;//nombre de el stream que se trata
		string datosJugador;//string que pide los datos
		
		entradaJugadores.open("Equipos.txt");//apertura del ficheri
		
		while(!entradaJugadores.eof()){ //pide datos hasta que el fichero este vacio
		
			getline(entradaJugadores,datosJugador);//obtiene cada linea
			char *entradaJu=strdup(datosJugador.c_str());//duplica el dato para que no se pierda por el strtrok
			char *particionJugadores;//almacena el truncamiento 
			particionJugadores=strtok(entradaJu,",");//toma la primera parte separada por coma
			int contJugadores=0;//variable que controla 
			while(particionJugadores!=NULL)//cuando no tenga nada mas que partir se detiene 
			{
				if(contJugadores==0){
					jugadorAux.nombre=particionJugadores;
					contJugadores++;
				}else if(contJugadores==1){
					jugadorAux.apellido=particionJugadores;
					contJugadores++;
				}else if(contJugadores==2){
					jugadorAux.nacionalidad=particionJugadores;
					contJugadores++;
				}else if(contJugadores==3){
					jugadorAux.fechaNacimiento=particionJugadores;
					contJugadores++;
				}else if(contJugadores==4){
					jugadorAux.estatura=particionJugadores;
					contJugadores++;
				}else if(contJugadores==5){
					jugadorAux.club=particionJugadores;
					contJugadores++;
				}else if(contJugadores==6){
					jugadorAux.posicion=particionJugadores;
					contJugadores++;
				}
				particionJugadores=strtok(NULL,",");
			}
			cout<<"nombre: "<<jugadorAux.nombre<<"apellido :"<<jugadorAux.apellido<<"posicion: "<<jugadorAux.posicion;
		
		}
		
		entradaJugadores.close();
		
		
	
	
}
void Datos::agregarDatosEquipos(Lista<equipo> *equipos){
	equipo auxiliarEquipo;//almacena temporalmente los datos del equipo para luego añadirlos
	ifstream entradaEquipos;//buffer de archivo
	string datosEquipo;//datos que toma del equipo
	entradaEquipos.open("Paises.txt");//abre fichero
	
	while(!entradaEquipos.eof()){
	
		getline(entradaEquipos,datosEquipo);
		
	char *entradaEq=strdup(datosEquipo.c_str());//duplica la entrada del equipo para que no se dañe con el strtok
	char *particionEquipos;//char encargado de almacenar los datos 
	particionEquipos=strtok(entradaEq,",");//cambia a la primera particiion
	int contEquipos=0;
	while(particionEquipos!=NULL)//siempre que aun quede que convertir lo hace
	{
		if(contEquipos==0){
			auxiliarEquipo.pais=particionEquipos;
			contEquipos++;
		}
		else if(contEquipos==1){
			auxiliarEquipo.confederacion=particionEquipos;
			contEquipos++;
		}
		else if(contEquipos==2)
		{
			auxiliarEquipo.puesto=particionEquipos;
			contEquipos++;
		}
		
		particionEquipos=strtok(NULL,",");
			//agregar jugadores
		jugador jugadorAux;//Jugador que almacena temporalmente los datos
		ifstream entradaJugadores;//nombre de el stream que se trata
		string datosJugador;//string que pide los datos
		
		entradaJugadores.open("Equipos.txt");//apertura del ficheri
		
		while(!entradaJugadores.eof()){ //pide datos hasta que el fichero este vacio
		
			getline(entradaJugadores,datosJugador);//obtiene cada linea
			char *entradaJu=strdup(datosJugador.c_str());//duplica el dato para que no se pierda por el strtrok
			char *particionJugadores;//almacena el truncamiento 
			particionJugadores=strtok(entradaJu,",");//toma la primera parte separada por coma
			int contJugadores=0;//variable que controla 
			while(particionJugadores!=NULL)//cuando no tenga nada mas que partir se detiene 
			{
				if(contJugadores==0){
					jugadorAux.nombre=particionJugadores;
					contJugadores++;
				}else if(contJugadores==1){
					jugadorAux.apellido=particionJugadores;
					contJugadores++;
				}else if(contJugadores==2){
					jugadorAux.nacionalidad=particionJugadores;
					contJugadores++;
				}else if(contJugadores==3){
					jugadorAux.fechaNacimiento=particionJugadores;
					contJugadores++;
				}else if(contJugadores==4){
					jugadorAux.estatura=particionJugadores;
					contJugadores++;
				}else if(contJugadores==5){
					jugadorAux.club=particionJugadores;
					contJugadores++;
				}else if(contJugadores==6){
					jugadorAux.posicion=particionJugadores;
					contJugadores++;
				}
				particionJugadores=strtok(NULL,",");
			}
			cout<<jugadorAux.nacionalidad;
		
		}
		
		entradaJugadores.close();
		
	}
	
	(*equipos).insertar_final(auxiliarEquipo);	
	}
	
	getline(entradaEquipos,datosEquipo);//toma la linea y saca el dato del equipo
	entradaEquipos.close();//cierra el fichero
	
	
	
	
	
	
	
}
void Datos::imprimirEquipo(Lista<equipo> equipos){
	int i;
	cout<<"Entra el metodo";
	cout<<"\t Pais \t"<<"\t Confederacion \t"<<"\t Ranking \n";
	for(i=1;i<=equipos.tamano_lista();i++){
		equipo aux;
		aux=equipos.obtenerDato(i);
		
		cout<<"\t"<<aux.pais<<"________"<<aux.confederacion<<"________"<<aux.puesto<<"\n";
	}
		
}
void Datos::imprimirJugadores(Lista<equipo> equipos,int numequipo){
	
	int i;
	equipo aux;
	aux=equipos.obtenerDato(numequipo);
	
	
	for(i=1;i<=aux.j.tamano_lista();i++){
		jugador jugaux;
		jugaux=aux.j.obtenerDato(i);
		cout<<i<<"-)"<<jugaux.nombre<<endl;
	}
		
}

int main(){
	Lista<equipo> equipos,*aux;
	aux=& equipos;
	Datos participantes;
	participantes.agregarDatosEquipos(aux);
	//participantes.agregarJugadores(aux);
	//participantes.imprimirEquipo(equipos);	
	//participantes.imprimirJugadores(equipos,1);
	
}

