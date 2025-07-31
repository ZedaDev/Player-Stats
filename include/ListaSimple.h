#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

///DEPENDENCYS
#include "utiles.h"
#include "Jugador.h"

 ///LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 ///=== STRUCT'S ===
typedef struct nodo{
        estadisticas jugador;
    struct nodo* siguiente;
} nodo;


 ///=== HEADERS FUNCTIONS ===
nodo* inicLista();
void crearNodoActual(nodo** nuevoNodo, estadisticas persona);
void crearNodoLeyenda(nodo** nuevoNodo);
void agregarAlPrincipioListaSimple(nodo** lista, nodo* nuevoNodo);
void mostrarLista(nodo* lista);
nodo* buscarUltimoLista(nodo* lista);
void agregarAlFinal(nodo** lista, nodo * nuevoNodo);

#endif // LISTASIMPLE_H_INCLUDED
