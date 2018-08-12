#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

void insertarElementoOrdenado(struct Nodo **array, int dato);
void intercambiaElementos(struct Nodo **elemento1, struct Nodo **elemento2);
struct Nodo *getNodoAProcesar(struct Nodo *array, int dato);
void arrayToString(struct Nodo *array);
struct Nodo * nuevoNodo(int dato);

int main(){
    struct Nodo *arreglo = NULL;
    insertarElementoOrdenado(&arreglo, 10);
    insertarElementoOrdenado(&arreglo, 7);
    insertarElementoOrdenado(&arreglo, 4);
    insertarElementoOrdenado(&arreglo, 2);
    insertarElementoOrdenado(&arreglo, 1);
    insertarElementoOrdenado(&arreglo, 3);

    arrayToString(arreglo);
}

void insertarElementoOrdenado(struct Nodo **array, int dato){
    if (*array == NULL) {
        *array = nuevoNodo(dato);
        return;
    }
    struct Nodo *nuevoElemento = nuevoNodo(dato);
    struct Nodo *nodoProcesado = getNodoAProcesar(*array, dato);

    if(nodoProcesado->dato > dato) {
        if(nodoProcesado == *array) { *array = nuevoElemento; }
        intercambiaElementos(&nodoProcesado, &nuevoElemento);
    } else if(nodoProcesado->siguiente != NULL && nodoProcesado->siguiente->dato > dato) {
        intercambiaElementos(&nodoProcesado->siguiente, &nuevoElemento);
    } else {
        nodoProcesado->siguiente = nuevoElemento;
    }
}

struct Nodo *getNodoAProcesar(struct Nodo *array, int dato) {
    struct Nodo *nodoProcesado = array;
    
    while(nodoProcesado->siguiente != NULL && nodoProcesado->dato < dato && nodoProcesado->siguiente->dato < dato) {
        nodoProcesado = nodoProcesado->siguiente;
    }

    return nodoProcesado;
}

void intercambiaElementos(struct Nodo **elemento1, struct Nodo **elemento2) {
    struct Nodo *aux = *elemento1;

    *elemento1 = *elemento2;
    (*elemento1)->siguiente = aux;
}

struct Nodo * nuevoNodo(int dato){
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    nuevo->dato=dato;
    nuevo->siguiente=NULL;

    return nuevo;
}

void arrayToString(struct Nodo * array) {
    struct Nodo * nodoProcesado = array;
    printf("[");
    while(nodoProcesado->siguiente != NULL) {
        printf("%d, ", nodoProcesado->dato);
        nodoProcesado = nodoProcesado->siguiente;
    }
    printf("%d]", nodoProcesado->dato);
}