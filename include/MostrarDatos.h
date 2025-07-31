#ifndef MOSTRARDATOS_H_INCLUDED
#define MOSTRARDATOS_H_INCLUDED

///DEPENDENDYCS
#include "ListaSimple.h"
#include "FILAS.h"

 ///=== HEADERS FUNCTIONS ===
void mostrarBloqueConCuadro(nodo* lista, int ancho, int* y_cursor, int control);
void mostrar_Estadisticas_Actuales(estadisticas persona,int* altura, int ancho, int* y_cursor, int control);
void mostrar_Fecha_info(int x, int y, stFecha e, inf persona, int control);
void mostrar_Stats(int x, int* y, stats e, int ancho);

int imprimirComentarioDentroCuadro(int x, int y, int ancho, const char* comentario);
void verify_Competicion(char competicion[]);
void verify_Club(char club[]);

void ver_Estadisticas_MasReciente_Recursivo(nodo* lista, int* y, int i);
void ver_Estadisticas_TiroLibre(nodo* lista, int control);


void goals_stats(nodo* lista);
void mostrarLogo(int x, int y);
void prints_Menu_Estadisticas(int x, int* y, int colore);
void view_stats(int x, int y, nodo* lista1, char* actualTeam, char* apodo, char* name, char* comentario, int option);
void prints_Menu_Estadisticas(int x, int* y, int colore);
void prints_Menu();

void mostrar_General_Stats(generalStats generales, char* namePlayer, char* actualTeam, char* apodo, int x, int* y_cursor, int ancho, int* altura, stFecha debut);
void mostrarTextoMismaPos(int x, int* y,int option, jugador* player, int control);

void mostrarEstadisticas_Equipo_Competicion(nodo* lista, generalStats generales, char* actualteam, char* apodo, char* name, stFecha fecha, int control);



#endif // MOSTRARDATOS_H_INCLUDED
