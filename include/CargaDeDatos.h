#ifndef CARGADEDATOS_H_INCLUDED
#define CARGADEDATOS_H_INCLUDED

///DEPENDENCYS
#include "FILAS.h"
#include "IngresoDatos.h"
#include "MostrarDatos.h"



 ///=== HEADERS FUNCTIONS ===
void cargarJugador(jugador** jugadores, int* validos);
jugador crearJugadorV1(int ide);

void cargarEstadisticas(jugador* jugadores, int ide, int validos);
nodo* setActual();

void verificarDatos(jugador** jugadores, int validos);
void modify_Dates(jugador** jugadores, int ide, int validos);

void cargarGeneralStats(nodo* lista, generalStats* generales, char* comentario);
void cargarEtadisticasPorEquipoYCompeticion(nodo* lista, nodo** lista1, char* equipo, char* competicion);
void cargar_Estadisticas_Anio(nodo* lista, nodo** lista1, int anioBuscado);
void cargar_Estadisticas_Competicion(nodo* lista, nodo** lista1, char* competicion);
void cargar_Estadisticas_Equipo(nodo* lista, nodo** lista1, char* equipo, char* apodo, char* name);

#endif // CARGADEDATOS_H_INCLUDED
