#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo * siguiente
};
struct nodo * inicio = NULL;
#define Nodo struct nodo;
void insertarOdenado(int);

int main(){
    insertarOrdenado(3);
    insertarOrdenado(4);
    insertarOrdenado(7);
    insertarOrdenado(2);
}

void insertarOrdenado(int dato){
   Nodo *nuevo = nuevo(dato);
   Nodo *aux = inicio;
   Nodo *ant = NULL;
   while((aux!=NULL)&&(aux->dato<dato)){
       ant=aux;
       aux = aux->siguiente;
   }
   if(ant == NULL){
       nuevo->siguiente = inicio;
       inicio=nuevo;
   }else {
       ant->siguiente = nuevo;
       nuevo->siguiente = aux;
   }
}

Nodo *nuevo(int dato){
    Nodo *nuevo = (Nodo *)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}