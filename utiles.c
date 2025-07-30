#include "utiles.h"

void gotoxy(int x, int y){ /// Posiciona el cursor para el mostrado de datos o entrada de datos y/o interfaces.
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int _color){ /// Setea un color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void getColors(){ /// Ver los colores disponibles.

    for(int i = 0; i < 255; i++)
    {
    color(i);
    printf("%d RIVER PLATE River Plate 1901 |@#&%/   \n", i);
    }
    color(7);
}

/**==============================================================================l
                              Utiles Del Projecto                                |
=================================================================================I
*/

///Capturar opcion del usuario S \ N, enviando el mensaje por parametro

char s_n(const char* mensaje) {
    char opcion;
    while (1) {
        	printf("\n%s (S/N): ", mensaje);
        	fflush(stdin); // o usar limpiarBuffer()
        	scanf(" %c", &opcion);
        	opcion = tolower(opcion); // convierte a minúscula
        if (opcion == 's' || opcion == 'n') {
            break;
        } else {
            printf("\t\tOpcion No Valida Solo Ingrese 'S' o 'N'\n Intente Nuevamente\n");
        }
    }
        return opcion;
}

/**se invoca s_n("¿Desea Seguir Cargando Jugadores?"), luego dentro de la funcion, entra al while
printea el mensaje como variable con %s, pide la opcion al usuario con scanf y limpiabuffer,
hace una validacion si la opcion es == 's' o igual a 'n' solo retorna, en caso de ingresar otro caracter,
printea que solo ingrese 'S' o 'N' y se vuelve a ejecutar el while hasta que ingrese correctamente 's' o 'n'*/


///Escribe una frase donde se indique, se le puede agregar un sleep y especificar el color.
void escribirFrase(int x, int y, int sleep, int colore, char texto[]){
        color(colore);
     for(int i = 0; i < strlen(texto); i++){///strlen(texto) seria los validos, hasta que i sea menor a los caracteres validos.
        Sleep(sleep);///le asigno el sleep que quiera por parametro.
        gotoxy(x++, y);///incremento x para correr el printf a la derecha, consiguiendo la union de las letras.
        printf("%c", texto[i]);///printeo la el caracter del indice en cada iteracion.
     }
}


void borrar(int x, int y, char frase[]){

    for(int i = 0; i<strlen(frase); i++){
        gotoxy(x++, y);
        printf(" ");
    }
            ///borra la frase, printeando espacios con la misma logica del strlen como validos.
}

///Pausa la pantalla en posicion elegida mediante parametro y el color
void pauseWrite(int x, int y, int colore){
    gotoxy(x,y); color(colore); PAUSE;
}

///===================Borrar-Escribir-Pausar FUNCIONES AYUDA==================================




///Efecto De Pantalla De Carga
void charging(int x, int y){
        BORRAR_PANTALLA;
        mostrarLogo(47,1);


        int x1 = x+44;
        int y1 = y+3;


        int numero = 1;

        int cargando[100];
        for(int i = 0; i < 100; i++){
            cargando[i] = 219;
        }
            color(10);
            char per = '%';

        for(int i = 0; i < 100; i++){
            Sleep(11.111);
            fflush(stdin);
            gotoxy(x++, y);
            printf("%c", cargando[i]);

            if(numero <= 100){
                fflush(stdin);
                gotoxy(x1, y1);
                printf("Cargando.. %d  %c", numero++, per);
            }
        }

        Sleep(470);
}


///====================================Cuadro Dinamico==============================================
int lineaArriba(int x, int y, int sleep, int cantidad, int numeroInicio, int numeroFinal){

    char *linea = (char*) malloc(sizeof(char) * cantidad);

    linea[0] = numeroInicio;
    linea[cantidad-1] = numeroFinal;

    for (int i = 1; i < (cantidad - 1); i++) {
        linea[i] = 205;  // Rellenar con el carácter '-'
    }
    for(int i = 0; i < cantidad; i++){
        gotoxy(x--, y);
        printf("%c", linea[i]);
        Sleep(sleep);
    }
    free(linea);
    return x+1;

}

int lineaIzquierda(int x, int y, int sleep, int cantidad){

    char *linea = (char*) malloc(sizeof(char) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        linea[i] = 186;
    }

    for(int i = 0; i < cantidad; i++){
        gotoxy(x, ++y);
        printf("%c", linea[i]);
        Sleep(sleep);
    }
    free(linea);
    return y;
}

int lineaAbajo(int x, int y, int sleep, int cantidad, int numeroInicio, int numeroFinal){

    char *linea = (char*) malloc(sizeof(char) * cantidad);

    linea[0] = numeroInicio;
    linea[cantidad-1] = numeroFinal;

    for (int i = 1; i < (cantidad - 1); i++) {
        linea[i] = 205;  // Rellenar con el carácter '-'
    }
    for(int i = 0; i < cantidad; i++){
        gotoxy(x++, y);
        printf("%c", linea[i]);
        Sleep(sleep);
    }

    free(linea);
    return x-1;
}

void lineaDerecha(int x, int y, int sleep, int cantidad){

    char *linea = (char*) malloc(sizeof(char) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        linea[i] = 186;  // Rellenar con el carácter '-'
    }

    for(int i = 0; i < (cantidad-1); i++){
        gotoxy(x, --y);
        printf("%c", linea[i]);
        Sleep(sleep);
    }
    free(linea);
}

void cuadro(int x, int y, int altura, int ancho, int colore){
            color(colore);

        int sleep = 0;

        x = lineaArriba(x, y,sleep,ancho,187,201);
        y = lineaIzquierda(x, y,sleep,altura);
        x = lineaAbajo(x, y,sleep,ancho,200,188);
        lineaDerecha(x, y,sleep,altura);

}
