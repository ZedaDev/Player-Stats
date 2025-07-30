#include "FILAS.h"


void inicFila(stFila* fila){
        (*fila).inicio = inicLista();
        (*fila).fin = inicLista();
}


void _mostrarFila(stFila* fila){
    nodo* seg = (fila)->inicio;
        int y = 1;
        int control = 0;
    while(seg){
        mostrarBloqueConCuadro(seg, 111, &y, control);
        if(!control) control = 1;

        seg = seg->siguiente;
    }
    pauseWrite(2,y,0);

}


void _agregar(stFila* fila, nodo* nuevoNodo){

    if (fila->inicio == NULL){
        fila->inicio = nuevoNodo; ///si la lista de la fila es null, se iguala al nuevoNodo.
    }
    else{
       agregarAlFinal(&(fila->inicio),nuevoNodo);///lo agrego al final de la lista de la fila.
    }
        fila->fin = nuevoNodo;///lo agrego al nodo fin de la fila.

}

int _filaVacia(stFila* fila){
    return (fila->inicio == NULL);
}


int mostrarJugadores(jugador* jugadores, int validos){


        int x = 47; int y = 3;
        escribirFrase(x+11, y++,0,47, "[Lista De Jugadores]"); color(15);
    int ancho = 88;
    for(int i = 0; i< validos;i++){
            cuadro(ancho, ++y, 5, 44, 10);
        escribirFrase(x,++y,0,10," Nombre : "); color(15); gotoxy(x+strlen("Nombre : "), y++); printf(" %s", jugadores[i].jugador.nombre);
        escribirFrase(x,y,0,10," Apodo : "); color(15); gotoxy(x+strlen("Apodo : "), y++); printf(" %s", jugadores[i].jugador.apodo);
        escribirFrase(x,y,0,10," Club Actual : "); color(15); gotoxy(x+strlen("Club Actual : "), y++); printf(" %s", jugadores[i].jugador.equipo);
        escribirFrase(x,y,0,15," Id : "); color(47); gotoxy(x+strlen("Id : "), y++); printf(" %d", jugadores[i].jugador.id);
    }
    return y;
}
