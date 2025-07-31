#include "IngresoDatos.h"

estadisticas ingresarEstadisticas(){
    BORRAR_PANTALLA;
    escribirFrase(10, 2, 25, 10, "INGRESE LOS DATOS DEL PARTIDO");

    estadisticas e;

    int y = 4;
    int x = 10;
        dateFechaCapture(x, &y, &e.fecha);
        dateStatsCapture(x, &y, &e.partido);
        dateInfCapture(x, &y, &e.info);
    return e;

}

void fgDateCapture(char* destino, int cant_bytes){
    fgets(destino, cant_bytes, stdin);
    destino[strcspn(destino, "\n")] = '\0';
    ///funcion para capturar strings controlando el buffer y borrar el salto de linea que deja fgets.
    ///fgets &destino, la cantidad de bytes sizeof(*destino), stdin controlar buffer.
///strcspn() va a la direccion de memoria de destino y si encuentra un \n lo cambia por 0 indicando el final de la  cadena.
}

void dateFechaCapture(int x, int* y, stFecha* e){
    int lenght;
   escribirFrase(x, ++(*y), 5, 15, "==== Fecha del Partido ===="); (*y)++;
    gotoxy(x,++(*y)); printf("A%co : ....", 164); lenght = strlen("Aco : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf(" %d", &e->anio); (*y)++;

    escribirFrase(10, *y, 0, 15, "Mes : .........."); lenght = strlen("Mes : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); fgDateCapture(e->mes, sizeof(e->mes));
    (*y)++;

    escribirFrase(10, *y, 0, 15, "Fecha : .."); lenght = strlen("Fecha : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf(" %d", &e->fecha); (*y)++;

    escribirFrase(10, *y, 0, 15, "Dia : ........."); lenght = strlen("Dia : ");
    gotoxy(x+lenght, *y);fflush(stdin);
    fgDateCapture(e->dia, sizeof(e->dia));(*y)++;
}
void dateInfCapture(int x, int* y, inf* persona){
    int lenght;

    escribirFrase(x, ++(*y), 0, 15, "==== Informacion del Partido ===="); (*y)++;
    escribirFrase(x, ++(*y), 0, 15, "Competicion : ......................");
        lenght = strlen("Competicion : ");
    gotoxy(x+lenght, *y); fflush(stdin);
    fgDateCapture(persona->competicion, sizeof(persona->competicion));
    gotoxy(x+lenght, *y);
    printf("                         ");  // Espacios para borrar

    gotoxy(x+lenght, *y);

        verify_Competicion(persona->competicion);
    printf("%s", persona->competicion);(*y)++;

    escribirFrase(x, *y, 0, 15, "Rival : ............."); lenght = strlen("Rival : ");
    gotoxy(x+lenght, *y);
    fgDateCapture(persona->rival, sizeof(persona->rival)); (*y)++;

    escribirFrase(x, *y, 0, 15, "Estadio : ........................"); lenght = strlen("Estadio : ");
    gotoxy(x+lenght, *y); fflush(stdin);
    fgDateCapture(persona->estadio, sizeof(persona->estadio)); (*y)++;

    escribirFrase(x, *y, 0, 15, "Resultado Del Partido?(Ej: River Plate 2 - Real Madrid 1) : ............................");
   lenght = strlen("Resultado Del Partido?(Ej: River Plate 2 - Real Madrid 1) : ");
   gotoxy(x+lenght, *y); fflush(stdin);
    fgDateCapture(persona->resultado, sizeof(persona->resultado)); (*y)++;


    escribirFrase(x, *y, 0, 15, "Figura Del Partido? S/N : ."); lenght = strlen("Figura Del Partido? S/N : ");
    gotoxy(x+lenght, *y); fflush(stdin); //scanf("%c", &persona->figuraDelPartido);
     persona->figuraDelPartido = tolower(getch());
     if(persona->figuraDelPartido == 's') color(175); else color(15);
     gotoxy(x+lenght, *y); printf("%c", persona->figuraDelPartido);
    (*y)++;

    escribirFrase(x, *y, 0, 15, "Comentario del partido: "); lenght = strlen("Comentario del partido: ");
    gotoxy(x+lenght, *y);fflush(stdin);
    fgDateCapture(persona->comentariodP, sizeof(persona->comentariodP)); (*y)++;

}

void dateStatsCapture(int x, int* y, stats* e){
    int lenght;
   escribirFrase(x, ++(*y), 5, 15, "==== Estadisticas del Jugador ===="); (*y)++;
    escribirFrase(x, ++(*y), 0, 15, "Fue titular? S/N : ."); lenght = strlen("Fue titular? S/N : ");
    gotoxy(x+lenght, *y);
    e->titular = tolower(getch()); // Lee y guarda como minúscula
    if (e->titular == 's'){
        color(175);
    } else if (e->titular == 'n'){
        color(4);
    }
    printf("%c", e->titular); (*y)++; // Muestra con color


    escribirFrase(x, *y, 0, 15, "Goles :  "); lenght = strlen("Goles :  ");
    gotoxy(x+lenght, *y); fflush(stdin);
    scanf("%d", &e->goles);  (*y)++;

    if(e->goles > 0){
            escribirFrase(x, *y, 0, 15, "Gol De Tiro Libre? s / n :  "); lenght = strlen("Gol De Tiro Libre? s / n : ");
            gotoxy(x+lenght, *y); fflush(stdin);
            scanf("%c", &e->golTiroLibre);  (*y)++;
        if(e->golTiroLibre == 's'){
                escribirFrase(x+lenght, *y - 1, 0, 175, "Si");
            escribirFrase(x, *y, 0, 15, "Digite Gol/es De Tiro Libre :  "); lenght = strlen("Digite Gol/es De Tiro Libre : ");
            gotoxy(x+lenght, *y); fflush(stdin);
            scanf("%d", &e->golesTiroLibre);  (*y)++;
        }
         escribirFrase(x, *y, 0, 15, "Goles De Penal : ");
             fflush(stdin); scanf(" %d", &e->golPenal);  (*y)++;
    }else{
        e->golPenal = 0;
        e->golesTiroLibre = 0;

    }

    escribirFrase(x, *y, 0, 15, "Asistencias :  "); lenght = strlen("Asistencias : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf("%d", &e->asistencias); (*y)++;

    escribirFrase(x, *y, 0, 15, "Minutos jugados :  "); lenght = strlen("Minutos jugados : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf("%d", &e->minutosJugados); (*y)++;

    escribirFrase(x, *y, 0, 15, "Tarjetas amarillas : "); lenght = strlen("Tarjetas amarillas : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf("%d", &e->amarillas); (*y)++;

    escribirFrase(x, *y, 0, 15, "Recibio tarjeta roja? (s/n) : ."); lenght = strlen("Recibio tarjeta roja? (s/n) : ");
    gotoxy(x+lenght, *y);
    fflush(stdin); scanf(" %c", &e->roja); (*y)++;

}
