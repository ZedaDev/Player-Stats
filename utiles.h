#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED

///LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

///MACROS

#define TRUE 1
#define FALSE 0
#define ESC 27
#define SALTO_LINEA printf("\n")
#define BORRAR_PANTALLA system("cls")
#define PAUSE system("pause")
#define ARCHIVOJUGADORES "players.bin"


 ///=== HEADERS FUNCTIONS ===
void gotoxy(int x, int y);
void color(int _color);
void getColors();

void escribirFrase(int x, int y, int sleep, int colore, char texto[]);///Escribe texto, elijiendo pos, color y sleep.
void borrar(int x, int y, char frase[]); /// borra la frase rellenando con espacios '     '.
void pauseWrite(int x, int y, int colore);/// pausa la pantalla con color 0 para borrar las letras, y espera un getch.
void charging(int x, int y);///Genera el EFECTO de carga de la pantalla, interfaz hacia otra interfaz.

#endif // UTILES_H_HINCLUDED



