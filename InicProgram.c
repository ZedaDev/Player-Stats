#include "InicProgram.h"


void inicProgram(){
    jugador* jugadores = NULL;
    int validos = cantidad_Jugadores_Archivo();
    Archivo_A_Jugadores1(&jugadores, validos);
    menuPrincipal(&jugadores, &validos);
}






