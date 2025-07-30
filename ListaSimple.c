#include "ListaSimple.h"


nodo* inicLista(){
    return NULL;
}

void inicListaSimple(nodo** lista){
    *lista = NULL;
}

void crearNodoActual(nodo** nuevoNodo, estadisticas persona){
    (*nuevoNodo) = (nodo*) malloc(sizeof(nodo));
    (*nuevoNodo)->jugador = persona;
    (*nuevoNodo)->siguiente =  inicLista();
}

nodo* buscarUltimoLista(nodo* lista)
{
    nodo* ultimo = lista;
    if(lista){
        while(ultimo->siguiente){
            ultimo = ultimo->siguiente;
        }
    }
        return ultimo;
}

void agregarAlFinal(nodo** lista, nodo * nuevoNodo){
    if(!(*lista)){
        (*lista) = nuevoNodo;
    }
    else{
        nodo* ultimo = buscarUltimoLista((*lista));
        ultimo->siguiente = nuevoNodo;
    }
}


