#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

///DEPENDENCYS
#include "ListaSimple.h"


 ///== STRUCT'S ===
typedef struct stFila{
    struct nodo* inicio;
    struct nodo* fin;
} stFila;

typedef struct {
    int id;
    char nombre[25];
    char apodo[11];
    char equipo[25];
    generalStats stats_Generales;
    char fArchivo[50]; // nombre del archivo que guarda las estadísticas
} indexJugador;

typedef struct {
    indexJugador jugador;
    stFila fila;
} jugador;


 ///=== HEADERS FUNCTIONS ===
void inicFila(stFila* fila);
void _mostrarFila(stFila* fila);
int filaVacia(stFila* fila);

int mostrarJugadores(jugador* jugadores, int validos);
#endif // FILAS_H_INCLUDED
