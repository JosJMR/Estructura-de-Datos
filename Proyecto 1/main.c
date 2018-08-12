#include "listas_enlazadas_ordenadas.h"

int main(){
    Array arreglo = NULL;
    insertarElementoOrdenado(&arreglo, 10);
    insertarElementoOrdenado(&arreglo, -5);
    insertarElementoOrdenado(&arreglo, 7);
    insertarElementoOrdenado(&arreglo, 4);
    insertarElementoOrdenado(&arreglo, 2);
    insertarElementoOrdenado(&arreglo, 1);
    insertarElementoOrdenado(&arreglo, 3);

    arrayToString(arreglo);
}