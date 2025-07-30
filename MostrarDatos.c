#include "MostrarDatos.h"



void mostrarBloqueConCuadro(nodo* lista, int ancho, int* y_cursor, int control){
    int altura;
    int y_inicio = *y_cursor;

        mostrar_Estadisticas_Actuales(lista->jugador, &altura, ancho, y_cursor, control);
        cuadro(115, y_inicio, altura, ancho, 10);
}

void mostrar_Estadisticas_Actuales(estadisticas persona,int* altura, int ancho, int* y_cursor, int control){
    int x = 11; //2
    int i;
      int y = *y_cursor;
     int y_inicio = y;
     escribirFrase(ancho/2 - 11, ++y,0, 47, "ESTADISTICAS DEL PARTIDO"); y++;
     mostrar_Fecha_info(x, y, persona.fecha, persona.info, control);
     mostrar_Stats(x, &y, persona.partido, ancho);

            y += 2; color(15);
            i = imprimirComentarioDentroCuadro(8, y, ancho, persona.info.comentariodP);
            y+= i+1;

      *altura = y - y_inicio; /// calcular para hacer el otro recuadro
      *y_cursor = y+1; /// tirar abajo el otro recuadro +2

}


int imprimirComentarioDentroCuadro(int x, int y, int ancho, const char* comentario){
        int x_max = ancho-1;
        int y_return = 0;
        int x_inicio = x;
        for(int i = 0; i < strlen(comentario); i++){
           if(x+1 == x_max){
                if(comentario[i] != ' ' && comentario[i+1] != ' ' && comentario[i+1] != '\0'){
                        gotoxy(x,y); printf("-");
                }
                x = x_inicio; y++; y_return++;
           }
            gotoxy(x, y); if(x == x_inicio && comentario[i] == ' ')i++; printf("%c", comentario[i]);
                x++;
        }
        return y_return;
}

void mostrar_Fecha_info(int x, int y, stFecha e, inf persona, int control){



    if(!control){
            escribirFrase(x, ++y, 0, 10, "[Debut] ");
        color(15); printf("%s %d/%s/%d", e.dia, e.fecha, e.mes, e.anio);
    }else{
        gotoxy(x, ++y); color(10); printf(" [Fecha] ");  color(15); printf(" %s  %d/%s/%d", e.dia, e.fecha, e.mes, e.anio);
    }

    y++;
    gotoxy(x, y); printf(" .Competicion : ");
    verify_Competicion(persona.competicion);
    gotoxy(x+strlen(" .Competicion : "), y); printf("%s", persona.competicion); y++;

    verify_Club(persona.equipo);
    gotoxy(x, y);printf(" .Equipo : %s", persona.equipo);

    color(15);
    gotoxy(x, ++y);printf(" .Rival : %s", persona.rival); y++;

    gotoxy(x, y);printf(" .Estadio : %s", persona.estadio);y++;

    gotoxy(x, y); printf(" .Figura Del Partido : ");
    gotoxy(x+strlen(" .Figura Del Partido : "), y);
    if(persona.figuraDelPartido == 's'){color(175 ); puts("Si");}else{puts("No");} y++;

    color(15); gotoxy(x, y); printf(" .Final Score : %s", persona.resultado);

}

void mostrar_Stats(int x, int* y, stats e, int ancho){
     int mitad = ancho / 2;
      x = mitad + x;
      (*y)++;
    escribirFrase(x, ++(*y), 0, 15, "Titular : ");
    gotoxy(x+strlen("Titular : "), *y);
    if (e.titular == 's') {
        color(175); puts("Si");
    } else if (e.titular == 'n') {
        color(15); puts("No");
    }
    if(e.golTiroLibre == 's'){
         escribirFrase(x+strlen("Titular :           "), *y, 0, 15, "Gol De Tiro Libre : ");
            color(175);
            gotoxy(x+strlen("Titular :           Gol De Tiro Libre : "), *y);
            printf("Si");
            (*y)++;


        escribirFrase(x+strlen("Goles :             "), *y, 0, 15, "Gol/es De Tiro Libre : ");
        color(175);
        gotoxy(x+strlen("Goles :              Gol/es De Tiro Libre : "), *y); printf("%d", e.golesTiroLibre);
    }else ++(*y);

    escribirFrase(x, *y, 0, 15, "Goles : ");
    color((e.goles > 0) ? 10 : 15);
    gotoxy(x+strlen("Goles : "),*y); printf("%d", e.goles);
    (*y)++;

    if(e.golPenal > 0){
        escribirFrase(x+strlen("Asistencias :           "), *y, 0, 15, "Gol De Penal : ");
        color(175);
        gotoxy(x+strlen("Asistencias :             Gol De Penal : "), *y); printf("%d", e.golPenal);
    }

    escribirFrase(x, *y, 0, 15, "Asistencias : ");
    gotoxy(x+strlen("Asistencias : "), *y); printf("%d", e.asistencias);
    (*y)++;

    escribirFrase(x, *y, 0, 15, "Minutos jugados :  ");
    gotoxy(x+strlen("Minutos jugados :  "), *y); if(e.minutosJugados >= 90) color(10);
    printf("%d", e.minutosJugados);
    (*y)++;

    escribirFrase(x, *y, 0, 15, "Tarjeta/s amarilla/s : ");
   gotoxy(x+strlen("Tarjeta/s amarilla/s : "), *y);
    printf("%d", e.amarillas);
    (*y)++;

    escribirFrase(x, *y, 0, 15, "Tarjeta Roja : ");
     gotoxy(x+strlen("Tarjeta Roja : "), *y); if(e.roja == 's'){ color(4); puts("Si"); }else{ puts("No"); } (*y)++;
}

void verify_Competicion(char competicion[]){
        if (_stricmp(competicion, "copa libertadores") == 0){
            color(47);
        }else if (_stricmp(competicion, "liga argentina") == 0) {
            color(252);
        }else if (_stricmp(competicion, "copa argentina") == 0) {
            color(127);
        }else if(_stricmp(competicion, "champions league") == 0){
            color(159);
        }else if(_stricmp(competicion, "Mundial de Clubes") == 0){
            color(207);
        }else if(_stricmp(competicion, "Mundial") == 0){
            color(155);
        }else if(_stricmp(competicion, "copa america") == 0){
            color(95);
        }else if(_stricmp(competicion, "la liga") == 0){
                color(252);
        }else if(_stricmp(competicion, "amistoso") == 0){
                color(177);
        }
}

void verify_Club(char club[]){
        if (_stricmp(club, "River Plate") == 0){
            color(252);
        }else if (_stricmp(club, "Argentina") == 0) {
            color(95);
        }else if (_stricmp(club, "Real Madrid") == 0) {
            color(250);
        }else if(_stricmp(club, "Inter") == 0){
            color(159);
        }
}


void ver_Estadisticas_MasReciente_Recursivo(nodo* lista, int* y, int i){
    nodo* seg = lista;
    BORRAR_PANTALLA;
    if(seg){
       ver_Estadisticas_MasReciente_Recursivo(seg->siguiente, y, i+1);
        mostrarBloqueConCuadro(seg,111,y, 1);
    }

    if(i == 0){
        escribirFrase(47,*y+3,0,47,"PRESS A KEY TO CONTINUE"); pauseWrite(1,*y+5,0);
    }
}


void ver_Estadisticas_TiroLibre(nodo* lista, int control){

    BORRAR_PANTALLA;
    nodo* seg = lista;
    int y = 1;
    int flag = 0;

     if(!seg){
       escribirFrase(35,11,0,4,"NO SE ENCONTRARON ESTADISTICAS QUE COINCIDENTES");
     }
        if (control == 1){
                while(seg){
                    if(seg->jugador.partido.goles >= 3){
                        mostrarBloqueConCuadro(seg, 111, &y, flag);
                        if(!flag){
                            flag = 1;
                        }
                    }
                        seg = seg->siguiente;
                }
        }else if(control == 2){
          while(seg){
                    if(seg->jugador.partido.golTiroLibre == 's'){
                        mostrarBloqueConCuadro(seg, 111, &y, flag);
                        if(!flag){
                            flag = 1;
                        }
                    }
                        seg = seg->siguiente;
                }
        }else{
              while(seg){
                    if(seg->jugador.partido.golPenal > 0){
                        mostrarBloqueConCuadro(seg, 111, &y, flag);
                        if(!flag){
                            flag = 1;
                        }
                    }
                        seg = seg->siguiente;
                }
        }

            escribirFrase(47,y+3,0,47,"PRESS A KEY TO CONTINUE"); pauseWrite(1,y+5,0);
}


void goals_stats(nodo* lista){
            nodo* seg;
    do{
        BORRAR_PANTALLA;
        mostrarLogo(47,0);
        cuadro(86,14,9,38,10);
            seg = lista;
            escribirFrase(59,15,0,79," === Goals Stats === ");
            escribirFrase(53,17,0,15,"[1]. Ver Por Hats-Trick ");
            escribirFrase(53,19,0,15,"[2]. Ver Por Goles De Tiro Libre");
            escribirFrase(53,21,0,15,"[3]. Ver Por Goles De Penal");
            escribirFrase(47,25,0,47,"Digite Su Opcion  /  Presione ESC para Salir");
                int number; gotoxy(56,22); fflush(stdin); number = getch(); ///GETCH devuelve el codigo ASCII de un char
                    if(number == ESC){
                            color(15);
                        break;
                    }
                    number = number - '0'; ///PARSEO el char a un int (EJ: char 2 = 10; parseo : 10 de ASCII a 2 de int.
                color(15);
            if(number == 1){
                ver_Estadisticas_TiroLibre(seg, number);
            }else if(number == 2){
                ver_Estadisticas_TiroLibre(seg, number);
            }else if(number == 3){
                ver_Estadisticas_TiroLibre(seg, number);
            }else if (!intentar_Nuevamente(50,22,"Respuesta Inexistente, Desea Intentar Nuevamente? ")){
                break; /// Si devuelve 1 no entra al if y sigue el while, si devuelve 0 entra al if y sale del while
            }
    }while(TRUE);
}

void mostrar_General_Stats(generalStats generales, char* namePlayer, char* actualTeam, char* apodo, int x, int* y_cursor, int ancho, int* altura, stFecha debut) {
    int y = *y_cursor;
    int y_inicio = y;

    int izq = x + 5;
    int der = x + ancho / 2 + 5;

    /// -------- COLUMNA IZQUIERDA --------
    escribirFrase(izq-2, ++y, 0, 10, "[Nombre] ");
    color(15); printf("%s", namePlayer); y++;
    gotoxy(izq, ++y);
    color(10); printf(".");color(15); escribirFrase(izq, y, 0, 15, "Apodo : ");
    color(15); printf("%s", apodo);


     gotoxy(izq, ++y); color(10); printf(".");              // Imprime punto verde con espacio
    escribirFrase(izq+1, y, 0, 15, "Club Actual : ");
    if (_strcmpi(actualTeam, "River Plate") == 0)
        color(207);
    else if (_strcmpi(actualTeam, "Real Madrid") == 0)
        color(127);
    else if (_strcmpi(actualTeam, "Seleccion Argentina") == 0)
        color(249);
    else color(15);

    printf("%s", actualTeam);

    gotoxy(izq, ++y); color(10); printf(".");
    color(15); gotoxy(izq+1,y); printf("A%cos De Carrera : ", 164);
    color(10); printf("%d", generales.totalAniosDeCarrera);

    gotoxy(izq, ++y); color(10); printf(".");
    escribirFrase(izq+1, y, 0, 15, "Goles Tiro Libre : ");
    color(175); printf("%d", generales.totalGolesTiroLibre);

        gotoxy(izq, ++y); color(10); printf(".");
    escribirFrase(izq+1, y, 0, 15, "Hat-Tricks : ");
    color(175); printf(" %d", generales.totalHatTricks);

    gotoxy(izq, ++y); color(10); printf(".");
    escribirFrase(izq+1, y, 0, 15, "Tarjetas Amarillas : ");
    color(15); printf("%d", generales.totalAmarillas);

    gotoxy(izq, ++y); color(10); printf(".");
    escribirFrase(izq+1, y, 0, 15, "Tarjetas Rojas : ");
    color(79); printf("%d", generales.totalTarjetaRoja);

    /// -------- COLUMNA DERECHA --------
    int y_col_der = y - 8;

    escribirFrase(der-5, y_col_der, 0, 10, "[Fecha Debut] ");
    color(15); printf("%s %d/%s/%d", debut.dia, debut.fecha, debut.mes, debut.anio);y_col_der++;


    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Partidos : ");
    color(47); printf("%d", generales.totalPartidos);

    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Goles : ");
    color(10); printf("%d", generales.totalGoles);
    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Goles De Penal : ");
    color(10); printf(" %d", generales.totalGolesPenal);

   gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Asistencias : ");
    color(15); printf("%d", generales.totalAsistencias);

    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Minutos Jugados : ");
    color(10); printf("%d", generales.totalMinutosJugados);

    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Titularidades : ");
    color(10); printf("%d", generales.totalTitular);

    gotoxy(der, ++y_col_der); color(10); printf(".");
    escribirFrase(der+1, y_col_der, 0, 15, "Figura Del Partido : ");
    color(47); printf("%d", generales.totalMVP);

    /// -------- COMENTARIO --------
    y+=2; color(15);
    int alturaComentario = imprimirComentarioDentroCuadro(x+4, y, ancho+x, generales.comentario);
    y += alturaComentario;

    *y_cursor = y + 1;
    *altura = y - y_inicio + 1;
}


void mostrarTextoMismaPos(int x, int* y,int option, jugador* player, int control){
        char* texto = NULL;
        int lengt = x;

        if(!control){
            if(option == 3){
                option = 4;
            }else if(option == 4){
                option = 5;
            }else if(option == 5){
                option = 3;
            }
        }

        switch(option){
        case 1:
            texto = ". Nombre : ";
             escribirFrase(x, ++(*y),1,10,texto);  fflush(stdin);
            lengt += strlen(texto);
            color(15);gotoxy(lengt, *y); fgets(player->jugador.nombre, sizeof(player->jugador.nombre), stdin);
            player->jugador.nombre[strcspn(player->jugador.nombre, "\n")] = 0;

            break;
        case 2:
            ++(*y);
            texto = ". Apodo : ";
             escribirFrase(x, ++(*y),1,10,texto);  fflush(stdin);
            lengt += strlen(texto);
            color(15);gotoxy(lengt, *y); fgets(player->jugador.apodo, sizeof(player->jugador.apodo), stdin);
            player->jugador.apodo[strcspn(player->jugador.apodo, "\n")] = 0;
            break;
        case 3:
             ++(*y);
            texto = ". Club Actual : ";
           escribirFrase(x, ++(*y),1,10,texto);  fflush(stdin);
            lengt += strlen(texto);
            color(15);gotoxy(lengt, *y); fgets(player->jugador.equipo, sizeof(player->jugador.equipo), stdin);
            player->jugador.equipo[strcspn(player->jugador.equipo, "\n")] = 0;
            break;
        case 4:
            texto = ". Nombre : ";
             escribirFrase(x, ++(*y),1,10,texto);  fflush(stdin);
            lengt += strlen(texto);
            color(15);gotoxy(lengt, *y); fgets(player->jugador.nombre, sizeof(player->jugador.nombre), stdin);
            player->jugador.nombre[strcspn(player->jugador.nombre, "\n")] = 0;

            texto = ". Apodo : ";
             escribirFrase(x, ++(*y),1,10,texto);  fflush(stdin);
            lengt = x+strlen(texto);
            color(15);gotoxy(lengt, *y); fgets(player->jugador.apodo, sizeof(player->jugador.apodo), stdin);
            player->jugador.apodo[strcspn(player->jugador.apodo, "\n")] = 0;
            break;
        case 5:
            texto = " . Descripcion : ";
             escribirFrase(1, (*y)+8,1,10,texto);
            lengt = strlen(texto);
            color(15);gotoxy(lengt+2, *y+8); fflush(stdin);fgets(player->jugador.stats_Generales.comentario, sizeof(player->jugador.stats_Generales.comentario), stdin);
            player->jugador.stats_Generales.comentario[strcspn(player->jugador.stats_Generales.comentario, "\n")] = 0;
            break;
        }

}



void mostrarEstadisticas_Equipo_Competicion(nodo* lista, generalStats generales, char* actualTeam, char* apodo, char* name,stFecha fecha, int control){
            BORRAR_PANTALLA;
        int x = 11; int y = 2;
        int altura;
        int ancho = 100;
        int y_inicio = y;

        escribirFrase((ancho / 2) - 2, y-1, 0, 79, "===== TOTAL STATS =====");
         mostrar_General_Stats(generales, name, actualTeam, apodo, x, &y, ancho, &altura, fecha);

            cuadro(111, y_inicio, altura, ancho, 10);
            if(control){
                y+=2;
                int control = 0;
                while(lista){
                    mostrarBloqueConCuadro(lista, 110, &y, control); /// 111
                    if(!control){
                        control = 1;
                    }
                    lista = lista->siguiente;
                }

            }
           escribirFrase(47,y+3,0,47,"PRESS A KEY TO CONTINUE"); pauseWrite(25, y+5,0); borrar(47,y+3,"PRESS A KEY TO CONTINUE");
}


void mostrarLogo(int x, int y){
    const char* lines[] = {
        "______________                           ",
        "___  __ \\__  /_____ _____  ______________",
        "__  /_/ /_  /_  __ `/_  / / /  _ \\_  ___/",
        "_  ____/_  / / /_/ /_  /_/ //  __/  /    ",
        "/_/     /_/  \\__,_/ _\\__, / \\___//_/     ",
        "                    /____/               ",
        "       ____________       _____          ",
        "       __  ___/_  /______ __  /________  ",
        "       _____ \\_  __/  __ `/  __/_  ___/  ",
        "       ____/ // /_ / /_/ // /_ _(__  )   ",
        "       /____/ \\__/ \\__,_/ \\__/ /____/    "
    };
    const int totalLineas = sizeof(lines) / sizeof(lines[0]); ///El total de caracteres dividido uno y saber cuantos caraceres hay.

    for (int i = 0; i < totalLineas; i++) {
        escribirFrase(x, y + i, 0, 5, lines[i]);
    }
}

void prints_Menu(){
        escribirFrase(57,21,0,79,"===== MENU PRINCIPAL =====");
        escribirFrase(59,23,0,15,"1. Cargar Jugador");
        escribirFrase(59,24,0,15,"2. Mostrar Jugadores");
        escribirFrase(59,25,0,15,"3. Modificar Jugador");
        escribirFrase(59,26,0,15,"4. Cargar Estadisticas");
        escribirFrase(59,27,0,15,"5. MENU ESTADISTICAS");
        escribirFrase(53,29,0,10,"Digite Su Opcion o ESC para salir");
}

void prints_Menu_Estadisticas(int x, int* y, int colore){
        escribirFrase(59,(*y)++,0,79,"===== STATS =====");
        escribirFrase(x,++(*y),0,colore,"1. Ver Todas Las Estadisticas");
        escribirFrase(x,++(*y),0,colore,"2. Mas Recientes / Mas Antiguas");
        escribirFrase(x,++(*y),0,colore,"3. Ver Por Equipo");
        escribirFrase(x,++(*y),0,colore,"4. Ver por Competicion");
        gotoxy(x,++(*y));        printf("5. Ver Por A%co", 164);
        escribirFrase(x,++(*y),0,colore,"6. Ver por Goles");
        escribirFrase(x,++(*y),0,colore,"7. Ver Equipo y Competicion");
        escribirFrase(x,++(*y),0,colore,"8. Ver Promedio General");(*y)++;

        escribirFrase(53,34,0,47,"Digite Su Opcion o ESC para salir");
        color(15);
}

void view_stats(int x, int y, nodo* lista1, char* actualTeam, char* apodo, char* name, char* comentario, int option){

    char team[25];
    char competicion1[25];
    int anio;
    generalStats generales;
        switch(option){
           case 3:{
                escribirFrase(x, ++y,0, 10,"Ingrese Equipo : ");
                gotoxy(x+5,y+1); color(15); fgDateCapture(team, sizeof(team));
                    nodo* lista = inicLista();
                    cargar_Estadisticas_Equipo(lista1, &lista, team, apodo, name);

                if(lista){
                    cargarGeneralStats(lista, &generales, comentario);
                    mostrarEstadisticas_Equipo_Competicion(lista, generales, team, apodo, name, lista->jugador.fecha, 1);
                }else{
                   BORRAR_PANTALLA;  color(4); gotoxy(11,11); printf("No se encontraron estadisticas del jugador en el equipo %s \n", team); pauseWrite(47,14,0); color(15);
                }
           }
                break;
            case 4:{
             escribirFrase(x+2, ++y,0, 10,"Ingrese La Competicion : ");
            gotoxy(x+5,y+1); fgDateCapture(competicion1, sizeof(competicion1));
                    nodo* lista = inicLista();
                cargar_Estadisticas_Competicion(lista1, &lista, competicion1);

                 if(lista){
                    cargarGeneralStats(lista, &generales, comentario);
                    mostrarEstadisticas_Equipo_Competicion(lista, generales, actualTeam, apodo, name, lista->jugador.fecha, 1);
                }else{
                   BORRAR_PANTALLA;  color(4); gotoxy(11,11); printf("No se encontraron estadisticas del jugador en la competicion %s \n", competicion1); pauseWrite(47,14,0); color(15);
                }
        }
                break;
            case 5:{
                    gotoxy(x+2, ++y); printf("Ingrese el A%co : ", 164);
                    gotoxy(x+5,y+1); fflush(stdin);  scanf(" %d", &anio);
                        nodo* lista = inicLista();
                        cargar_Estadisticas_Anio(lista1, &lista, anio);
                    if(lista){
                        cargarGeneralStats(lista, &generales, comentario);
                        mostrarEstadisticas_Equipo_Competicion(lista, generales, actualTeam, apodo, name, lista->jugador.fecha, 1);
                    }else{
                      BORRAR_PANTALLA;   color(4); gotoxy(11,11); printf("No se encontraron estadisticas del jugador en el a%co %d\n",164, anio); pauseWrite(47,14,0); color(15);
                    }
                }
            break;
        case 7:{
                escribirFrase(x, ++y,0, 10,"Equipo : ");
                gotoxy(x+strlen("Equipo :   "),y); color(15); fgDateCapture(team, sizeof(team));
                escribirFrase(x, ++y,0, 10,"Competicion : ");
                gotoxy(x+strlen("Competicion : "),y); color(15); fgDateCapture(competicion1, sizeof(competicion1));

                   nodo* lista = inicLista();
                cargarEtadisticasPorEquipoYCompeticion(lista1, &lista , team, competicion1);

                      BORRAR_PANTALLA;
                if(lista){
                    cargarGeneralStats(lista, &generales, comentario);
                    mostrarEstadisticas_Equipo_Competicion(lista, generales, team, apodo, name, lista->jugador.fecha, 1);
                }else{
                  BORRAR_PANTALLA;  color(4); gotoxy(11,11); printf("No se encontraron estadisticas del jugador en el equipo %s y en la competicion %s \n", team, competicion1); pauseWrite(47,14,0); color(15);
                }

            }
        break;
    }
}
