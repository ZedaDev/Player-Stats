#ifndef ARCHIVOSCARGA_H_INCLUDED
#define ARCHIVOSCARGA_H_INCLUDED

///DEPENDENCYS
#include "FILAS.h"
#include "utiles.h"


///HEADERS
void Archivo_A_Jugadores1(jugador** jugadores, int validos); ///Pasar Datos Del Archivo Al Array Dinamico Jugadores
int cantidad_Jugadores_Archivo(); /// Contar Cantidad De Jugadores En El Archivo y Retornarlo
void ArchivoEstadisticas_A_Jugadores(stFila* fila, char* name);///Carga las estadisticas en la Lista del jugador.
void cargarJugador_ArchivoJugadoresV1(jugador* personas, int validos);
///Sucede al inicio

///

//void cargarArchivoIndex(indexJugador* players, int validos); ///Carga cada jugador al archivo




#endif // ARCHIVOSCARGA_H_INCLUDED
//void modificarJugador_Archivo(jugador* personas, int validos, int ide);
