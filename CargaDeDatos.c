#include "CargaDeDatos.h"


void cargarArchivoEstadisticas(estadisticas* persona, char* name){
    FILE* archivo = fopen(name, "ab");
        if(archivo){
            fwrite(persona, sizeof(estadisticas), 1, archivo);

            fclose(archivo);
        }else {
            BORRAR_PANTALLA; puts("ERROR AL ABRIR ARCHIVO ESTADISTICAS"); PAUSE;
        }
}

void cargarEstadisticas(jugador* jugadores, int ide, int validos){
        while(TRUE){
            nodo* nuevoNodo = setActual();
            _agregar(&(jugadores[ide-1].fila), nuevoNodo);
            cargarArchivoEstadisticas(&(nuevoNodo->jugador), jugadores[ide-1].jugador.fArchivo);
            if(!intentar_Nuevamente(2,1,"Desea Cargar Otra Estadistica Al Jugador? S (si) / N (no) : ")) break;
        }
}


nodo* setActual(){
            estadisticas persona = ingresarEstadisticas();
            printf("\n\n\t Ingrese El Club Del Jugador : ");
            fgDateCapture(persona.info.equipo, sizeof(persona.info.equipo));
            nodo* nuevoNodo; crearNodoActual(&nuevoNodo, persona);
                return nuevoNodo;
}

void cargarJugador(jugador** jugadores, int* validos){
        char option = 's';
            if((*jugadores) == NULL){
                (*jugadores) = (jugador*) malloc(sizeof(jugador));
            }
        do{
                    BORRAR_PANTALLA;
                    mostrarLogo(47,5);
                    cuadro(88,20,10,43,10); color(10);

                jugador* aux = (jugador*) realloc(*jugadores, sizeof(jugador) * (*validos + 1));
                    if(aux){
                        *jugadores = aux;
                    }
                    else{
                        puts("ERROR AL ASIGNAR MEMORIA");
                        break;
                    }

                   (*jugadores)[*validos] = crearJugadorV1(*validos+1); /// Le Paso La id. validos = 0, id = 1
                  (*validos)++;

            printf("\n ¿Desea Seguir Cargando Jugadores? S / N : ");
             scanf(" %c", &option);

            if(option != 's'){
                break;
            }
                BORRAR_PANTALLA;
        }while(TRUE);

}


jugador crearJugadorV1(int ide){
        cuadro(88,20,10,43,10);
        jugador player;
        inicFila(&player.fila);


            player.jugador.id = ide;
            int x = 47; int y = 21;

            escribirFrase(x+11, y++, 0, 47, " === PLAYER DATA ===");
            for(int i = 1; i < 4; i++){
                  mostrarTextoMismaPos(x, &y, i, &player, 1);
            }
            y+= 4;
                escribirFrase(2,y,0,15, "Ingrese Descripcion Del Jugador : ");
                fgDateCapture(player.jugador.stats_Generales.comentario, sizeof(player.jugador.stats_Generales.comentario));
            sprintf(player.jugador.fArchivo, "estadistica_%03d.bin", ide);
                    escribirFrase(x+14, 43, 0,175, "Carga Exitosa"); color(15); //pauseWrite(x-11, 47,0);


        return player;
}



void verificarDatos(jugador** jugadores, int validos){
            BORRAR_PANTALLA;
            int y;
            while(TRUE){
                    BORRAR_PANTALLA;
                 y = mostrarJugadores(*jugadores, validos);
                escribirFrase(2,++y,0,15,"Ingrese Id Del Jugador A Modificar : ");
                    int ide; fflush(stdin); scanf(" %d", &ide);
                if(ide < 1 || ide > validos){
                    int i = intentar_Nuevamente(3,5,"ID INEXISTENTE, DESEA INTENTAR NUEVAMENTE?");
                    if(!i) break;
                }else{
                        modify_Dates(jugadores, ide, validos);
                    break;
                }
            }
}

void modify_Dates(jugador** jugadores, int ide, int validos){
    do{
        BORRAR_PANTALLA;
        cuadro(86,10,11,38,10);
            escribirFrase(53,11,0,175,"Indique Dato/s A Modificar : ");
            escribirFrase(56,13,0,15,"[1]. Nombre ");
            escribirFrase(56,14,0,15,"[2]. Apodo");
            escribirFrase(56,15,0,15,"[3]. Ambos");
            escribirFrase(56,16,0,15,"[4]. Descripcion Del Jugador");
            escribirFrase(56,17,0,15,"[5]. Club Actual");
            escribirFrase(47,25,0,10,"Digite Su Opcion o Presione ESC Para Salir");
        int number; gotoxy(56,18); fflush(stdin); number = getch(); if(number == ESC){ color(15); break; } ///GETCH devuelve el codigo ASCII de un char
         number = number - '0'; ///PARSEO el char a un int (EJ: char 2 = 10; parseo : 10 de ASCII a 2 de int.
        borrar(47,25,"Digite Su Opcion o Presione ESC Para Salir");
           int x = 51; int y = 18;
        mostrarTextoMismaPos(x, &y, number, &((*jugadores)[ide-1]), 0); ///Le paso la direccion de memoria de lo que apunta jugadores. sin el &, le estaria pasando el valor de lo que apunta jugadores.
        cargarJugador_ArchivoJugadoresV1(*jugadores, validos); ///Cargo el archivo jugadores, con los datos modificados.
        escribirFrase(50,22,0,250,"Jugador Con Id   Ha Sido Modificado");
        gotoxy(50+strlen("Jugador Con Id "), 22); printf("%d", ide);
        escribirFrase(56,23,0,47,"PREES A KEY TO CONTINUE"); pauseWrite(47,35,0);

    }while(TRUE);

}



void cargarGeneralStats(nodo* lista, generalStats* generales, char* comentario){
        nodo* seg = lista; /// seteo lista a seg, aunque se copie por valor y no referencia por ser puntero a puntero
        ///se cree buena practica ya que usamos la lista para iterar no para actualizar.

    /// SET GENERALES AT DEFAULT
        (*generales).totalAsistencias = 0;
        (*generales).totalGoles = 0;
        (*generales).totalGolesTiroLibre = 0;
        (*generales).totalHatTricks = 0;
        (*generales).totalGolesPenal = 0;
        (*generales).totalPartidos= 0;
        (*generales).totalTarjetaRoja = 0;
        (*generales).totalAmarillas = 0;
        (*generales).totalTitular = 0;
        (*generales).totalMVP = 0;
        (*generales).totalMinutosJugados = 0;

        ///Nodo anterior para guardar el ultimo y comparar con el primero de la lista, dandome en la resta los años de carrera.
            nodo* anterior;

            while(seg){
                    if(seg->jugador.partido.goles > 0){
                        (*generales).totalGoles += seg->jugador.partido.goles;
                            if(seg->jugador.partido.golTiroLibre == 's'){
                                (*generales).totalGolesTiroLibre += seg->jugador.partido.golesTiroLibre;
                            }
                            if(seg->jugador.partido.golPenal > 0){
                                (*generales).totalGolesPenal += seg->jugador.partido.golPenal;
                            }

                            if(seg->jugador.partido.goles >= 3){
                                (*generales).totalHatTricks += 1;
                            }
                    }

                    if(seg->jugador.partido.asistencias > 0){
                        (*generales).totalAsistencias += seg->jugador.partido.asistencias;
                    }

                    if(seg->jugador.partido.roja == 's'){
                        (*generales).totalTarjetaRoja += 1;
                    }

                        if(seg->jugador.info.figuraDelPartido == 's'){
                            (*generales).totalMVP += 1;
                        }

                        if(seg->jugador.partido.titular == 's'){
                            (*generales).totalTitular += 1;
                        }

                    (*generales).totalPartidos += 1;
                    (*generales).totalMinutosJugados += seg->jugador.partido.minutosJugados;
                    anterior = seg;
                seg = seg->siguiente;
            }

                (*generales).totalAniosDeCarrera = anterior->jugador.fecha.anio - lista->jugador.fecha.anio; /// saco el total de años de carrera, restando la primera fecha con la ultima fecha ingresada.
                strcpy((*generales).comentario, comentario); ///Copio el comentario

}

void cargarEtadisticasPorEquipoYCompeticion(nodo* lista, nodo** lista1, char* equipo, char* competicion){

            nodo* seg = lista;

            while(seg){
                if(_stricmp(seg->jugador.info.equipo, equipo) == 0 && _stricmp(seg->jugador.info.competicion, competicion) == 0 ){
                        nodo* nuevoNodo; crearNodoActual(&nuevoNodo, seg->jugador);
                        agregarAlFinal(lista1, nuevoNodo);
                }
                seg = seg->siguiente;
            }
}


void cargar_Estadisticas_Anio(nodo* lista, nodo** lista1,  int anioBuscado){
    nodo* seg = lista;
        while(seg){
           if(seg->jugador.fecha.anio == anioBuscado){
                nodo* nuevoNodo; crearNodoActual(&nuevoNodo, seg->jugador);
                agregarAlFinal(lista1, nuevoNodo);
           }
           seg = seg->siguiente;
        }
}

void cargar_Estadisticas_Competicion(nodo* lista, nodo** lista1, char* competicion){
        nodo* seg = lista;
            while(seg){
                if(_strcmpi(seg->jugador.info.competicion, competicion) == 0){
                    nodo* nuevoNodo; crearNodoActual(&nuevoNodo, seg->jugador);
                    agregarAlFinal(lista1, nuevoNodo);
                }
                    seg = seg->siguiente;
            }
}




void cargar_Estadisticas_Equipo(nodo* lista, nodo** lista1, char* equipo, char* apodo, char* name){
    nodo* seg = lista;
    while(seg){
       if(_strcmpi(seg->jugador.info.equipo, equipo) == 0){
            nodo* nuevoNodo; crearNodoActual(&nuevoNodo, seg->jugador);
            agregarAlFinal(lista1, nuevoNodo);
       }
       seg = seg->siguiente;
    }
}

