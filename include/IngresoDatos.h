#ifndef INGRESODATOS_H_INCLUDED
#define INGRESODATOS_H_INCLUDED

 ///DEPENDENCYS
#include "ListaSimple.h"


 ///=== HEADERS FUNCTIONS ===
estadisticas ingresarEstadisticas();
void dateFechaCapture(int x, int* y, stFecha* e);
void dateInfCapture(int x, int* y, inf* persona);
void dateStatsCapture(int x, int* y, stats* e);

void fgDateCapture(char* destino, int cant_bytes);
#endif // INGRESODATOS_H_INCLUDED
