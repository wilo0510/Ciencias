#ifndef LISTA_H     
#define LISTA_H  
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo{
	
	Nodo<T> *sig,*ant;
	T info;
	
};

template <class T>
class Lista{Nodo <T> *cab,*cola;
            int tam;
     public: Lista(){cab = NULL;
                     tam =0;}
             bool lista_vacia();
             int tamano_lista();
             T obtenerDato(int pos);
             bool eliminar(int pos);
             void insertar_final(T infoNueva);
             void insertar_pos(T infoNueva, int pos);
             void insertar_inicio(T infoNueva);
             bool modificar_elemento(int pos, T elemento);
            
};

template <class T>
void Lista<T>::insertar_pos(T infoNueva, int pos)
{ 
	int i;
	if(pos > tam)
    	 insertar_final(infoNueva);
  	else{if (pos==1)
        	insertar_inicio(infoNueva);
       	else{ Nodo <T> *nuevo, *aux;
             nuevo = new Nodo <T>;
             nuevo->info = infoNueva;
             aux = cab;
             
			 for(i=1;i<=pos+1;i++){
						
						if(i==pos-1){
							nuevo->ant=aux;
						}
						
						else if(i==pos){
							nuevo->sig=aux;
						}
						
							aux=aux->sig;
             }
            nuevo->ant->sig=nuevo;
            nuevo->sig->ant=nuevo;
           tam++;
       }
	}
}

template <class T>
void Lista<T>::insertar_final(T elemento)
{ 	//nodo auxiliar con direcciones nulas para insertarlo al final
	Nodo<T> *aux= new Nodo<T>;
	aux->info=elemento;
	aux->sig=NULL;
	aux->ant=NULL;
	
	if(cab==NULL){ // || cola ==NULL
		cab=aux;
		cola=aux;
	}
			
	else{

		Nodo<T> *ultimo=cola;
		cola=aux;	
		ultimo->sig=cola;
		cola->ant=ultimo;
		cola->ant=ultimo;
		cola->sig=cab;
		cab->ant=cola;
		//delete ultimo; liberar memoria? ver cuaderno
	}
				
	tam++;

}

template <class T>
void Lista<T>::insertar_inicio(T infoNueva)
{ Nodo <T> *nuevo;
  nuevo = new Nodo <T>;
  nuevo->info = infoNueva;
  nuevo->sig = cab;
  cab->ant=nuevo;
  cab = nuevo;
  cab->ant=cola;
  cola->sig=cab;
  tam++;
}


template <class T>
T Lista<T>::obtenerDato(int pos)
{   int i;
	if(cab!=NULL || pos<tam){
			
		Nodo<T> *aux=cab;
		for(i=1;i<pos;i++)
			aux=aux->sig;
						
		return aux->info;
				
	}	
}

template <class T>
bool Lista<T>::eliminar(int pos)
{
	Nodo<T> *ant,*sig;
	int i;			
	if(tam>=pos && cab!=cola){
			
		Nodo<T> *aux=cab,*temp;
		//cabeza 
		if(pos==1){
					
			//como libero la memoria aca?
			cab=cab->sig;
			cab->ant=cola;
			cola->sig=cab;
			tam--;
			delete aux;
			return true;
					
		}
		//cola
		else if(pos==tam){
			
			cola->ant->sig=cab;
			cab->ant=cola->ant;					
			cola=cab->ant;
			tam--;
			delete aux;
			return true;
						
		}
		
		//entre la cola y la cabeza	
		else{
					
			for(i=1;i<pos+1;i++){
						
				if(i==pos-1){
							
					temp=aux;
					aux->sig=aux->sig->sig;
				}
						
				else if(i==pos+1){
							
					aux->ant=temp;
				}
						
				if(aux->sig!=NULL)
					aux=aux->sig;
			}
			tam--;	
			delete aux;
			delete temp;
			return true;
		}
		
	
	}
	
			
	else{
		
		return false;

		}
			
	
}

template <class T>
bool Lista<T>::lista_vacia()
{     if(tam == 0)
        return true;
     else
        return false;
}

template <class T>
int Lista<T>::tamano_lista()
{ return tam;}

template<class T>
bool Lista<T>::modificar_elemento(int pos,T elemento){
			
	int i;
			
			
	if(pos>tam){
			
		return false;
	}
		
	else{
				
		Nodo<T> *aux=cab;
		for(i=1;i<pos;i++)
			aux=aux->sig;
				
		aux->info=elemento;
		return true;
	}
			
}
		

#endif
