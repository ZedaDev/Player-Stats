#include "menu&Functions.h"


void menuPrincipal(jugador** jugadores, int* validos){
    int opcion;
    int ide = 0;
    int y;
    jugador* persona;

    do{
            BORRAR_PANTALLA;
            mostrarLogo(47,5);
                cuadro(88,20,10,39,10); color(10);
                prints_Menu(); color(4); gotoxy(56,38); printf("[Made By ZEDA Dev - 2025]"); color(15);
            gotoxy(92, 29); fflush(stdin); opcion = getch(); if(opcion == ESC){ BORRAR_PANTALLA; break; }
            opcion = opcion - '0'; ///'0'  ASCII es = 48, toma el int de opcion a valor de ascii y lo resta al 48 ascci del 0.
        switch(opcion) {
            case 1:
                cargarJugador(jugadores, validos);
                cargarJugador_ArchivoJugadoresV1(*jugadores, *validos);
                break;
            case 2:
                BORRAR_PANTALLA;
                y = mostrarJugadores(*jugadores, *validos);
                cuadro(92,1,y,50,10); escribirFrase(55,y+3,0,47, "PRESS A KEY TO RETURN MENU"); pauseWrite(47, y+6,0);
                break;
            case 3:
                verificarDatos(jugadores, *validos);
                break;
            case 4:
                    if(verify_players(47,14,*validos, "No hay jugadores cargados.")) break;
                 do{
                     pedir_Id(*validos, &ide);
                     if(ide){
                        cargarEstadisticas(*jugadores, ide, *validos);
                       if(!intentar_Nuevamente(2,2,"Desea Cargar Estadisticas A Otro Jugador? S (si) / N (no) : ")){
                            BORRAR_PANTALLA; escribirFrase(44,11,0,47,"CARGA DE ESTADISTICAS FINALIZADA");
                            break;
                        }
                     }else break;
                }while(TRUE);
                            escribirFrase(47,14,0,10,"PRESS A KEY TO RETURN MENU"); pauseWrite(11,18,0);
                    break;
            case 5:
                    BORRAR_PANTALLA;
                    if(verify_players(47,14,*validos, "No hay jugadores cargados.")) break;
                        pedir_Id(*validos, &ide);
                        if(ide <= validos && ide >= 1){
                           persona = buscar_Jugador(*jugadores, *validos, ide);
                            if(!_filaVacia(&(persona->fila))){
                                charging(11,14);
                                menu_Estadisticas(&(persona->fila), persona->jugador.nombre, persona->jugador.equipo, persona->jugador.apodo, persona->jugador.stats_Generales.comentario);
                            }else {
                                 BORRAR_PANTALLA; color(79); printf("\n\t\t %s No Tiene Estadisticas Cargadas", persona->jugador.apodo); pauseWrite(2,5,0); color(15);
                            }
                        }
                break;
            default: BORRAR_PANTALLA;escribirFrase(47, 14, 0, 4, "Opcion No Valida"); getch();
        }
    }while(opcion != 0);
     escribirFrase(47, 25, 0, 4, "Finish Program"); color(0);
}




void menu_Estadisticas(stFila* fila, char* name, char* actualTeam, char* apodo, char* comentario){
        int opcion;
        int anio;
        char competicion1[25];
        char team[25];
        generalStats generales;
        cargarGeneralStats(fila->inicio, &generales, comentario);
   do{
        int x = 52; int y = 20;
        int i = 1;
        BORRAR_PANTALLA;
                mostrarLogo(47,5);
                cuadro(88,19,14,39,10);
                prints_Menu_Estadisticas(x+2, &y, 15);
            gotoxy(74, y+1); fflush(stdin); opcion = getch();
            if(opcion == ESC){ BORRAR_PANTALLA; break; }
         opcion = opcion - '0';

    switch(opcion){
    case 1:
        BORRAR_PANTALLA;
        _mostrarFila(fila);
        break;
    case 2:
         ver_Estadisticas_MasReciente_Recursivo(fila->inicio, &i, 0); ///Mostrado Con Recurcion
        break;
    case 3:
                view_stats(x, y, fila->inicio, actualTeam, apodo, name, comentario, 3);
        break;
    case 4:
                view_stats(x, y, fila->inicio, actualTeam, apodo, name, comentario, 4);
        break;
    case 5:
                view_stats(x, y, fila->inicio, actualTeam, apodo, name, comentario, 5);
        break;
    case 6:
                goals_stats(fila->inicio);
        break;
    case 7:
                view_stats(x, y, fila->inicio, actualTeam, apodo, name, comentario, 7);
        break;
    case 8:
            mostrarEstadisticas_Equipo_Competicion(NULL, generales, actualTeam, apodo, name,fila->inicio->jugador.fecha, 0);
           break;
        }
   }while(TRUE);
}



jugador* buscar_Jugador(jugador* jugadores, int validos, int ide){
            jugador* persona = &jugadores[ide-1];
            (persona)->fila.inicio = jugadores[ide-1].fila.inicio;
            (persona)->fila.fin  = jugadores[ide-1].fila.fin;

        return persona;

}

int verify_players(int x, int y, int validos, char* text){
         int number = 0;
         if (validos <= 0) {
            number = 1;
            BORRAR_PANTALLA; escribirFrase(47, 14, 0, 4, text);
                pauseWrite(47,18,0);
        }
            return number;
}


void pedir_Id(int validos, int* ide){
        int temp;
        *ide = 1;
    while(*ide){
            BORRAR_PANTALLA;
         escribirFrase(2,1,0,15,"Ingrese Id Del Jugador : "); fflush(stdin); scanf(" %d", &temp);
        if(temp <= validos && temp > 0){
                *ide = temp; break;
        }else{
               *ide = intentar_Nuevamente(2,3,"ID INEXISTENTE, DESEA VOLVER A DIGITAR? ");
        }
    }

}

int intentar_Nuevamente(int x, int y, char* texto){
    char option = 's';
    int number;
    int i = 0 ;
    for(int i = 0; i<3; i++){
        BORRAR_PANTALLA;
        escribirFrase(x, y++, 0, 15, texto);
        fflush(stdin); scanf(" %c", &option);
        option = tolower(option);

        if(option == 's'){
            number = 1;
            break;
        } else if(option == 'n'){
            number = 0;
            break;
        } else if(number != 's' && number != 'n'){
            escribirFrase(x, y, 0, 4, "Solo Debe Ingresar s (Si) / n (No) ");
            number = 0;
            color(0); PAUSE;
        }
    }
        return number;
}
