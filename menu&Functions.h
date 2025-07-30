#ifndef MENU&FUNCTIONS_H_INCLUDED
#define MENU&FUNCTIONS_H_INCLUDED

///DEPENDENCYS

#include "MostrarDatos.h"

///HEADERS
void menuPrincipal(jugador** jugadores, int* validos);
void menu_Estadisticas(stFila* fila, char* name, char* actualTeam, char* apodo, char* comentario);

jugador* buscar_Jugador(jugador* jugadores, int validos, int ide);
int verify_players(int x, int y, int validos, char* text);
void pedir_Id(int validos, int* ide);
int intentar_Nuevamente(int x, int y, char* texto);

#endif // MENU&FUNCTIONS_H_INCLUDED
