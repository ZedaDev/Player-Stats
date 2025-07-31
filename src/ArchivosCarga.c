#include "ArchivosCarga.h"


void Archivo_A_Jugadores1(jugador** jugadores, int validos){ ///Inicia el programa, settea los jugadores del archivo al array de jugadores.
    if (validos > 0) {
        *jugadores = malloc(sizeof(jugador) * validos);

        FILE* archivo = fopen(ARCHIVOJUGADORES, "rb");
        if (archivo) {
            indexJugador persona;
            int i = 0;
            while (i < validos && fread(&persona, sizeof(indexJugador), 1, archivo) > 0) {
                (*jugadores)[i].jugador = persona;
                ArchivoEstadisticas_A_Jugadores(&((*jugadores)[i].fila), persona.fArchivo);
                i++;
            }
            fclose(archivo);
        } else {
            puts("NO HAY JUGADORES CARGADOS, ARCHIVO NO EXISTE");
        }
    }
}


int cantidad_Jugadores_Archivo(){ /// Cuenta la cantidad de jugadores del archivo y los retorna obteniendo los validos.
    FILE* archivo = fopen(ARCHIVOJUGADORES, "rb");
            int i = 0;
        if(archivo){
            indexJugador index;
            while(fread(&index, sizeof(indexJugador), 1, archivo) > 0){
                i++;
            }
                fclose(archivo);
        }
            return i;
}


void ArchivoEstadisticas_A_Jugadores(stFila* fila, char* name){ ///Settea las estadisticas del jugador.
        FILE* archivo = fopen(name, "rb");
        estadisticas persona;
        stFila fila1; inicFila(&fila1);

        if(archivo){
            while(fread(&persona, sizeof(estadisticas), 1, archivo) > 0){
                    nodo* nuevoNodo;
                    crearNodoActual(&nuevoNodo, persona);
                    _agregar(&fila1, nuevoNodo);
            }

            fclose(archivo);
        }
            *fila = fila1;
            (*fila).inicio = fila1.inicio;
            (*fila).fin = fila1.fin;
}


void cargarJugador_ArchivoJugadoresV1(jugador* personas, int validos){ ///Carga todos los jugadores en el archivo.

    FILE* archivo = fopen(ARCHIVOJUGADORES, "wb");
        if(archivo){

                for(int i = 0; i<validos;i++){
                    fwrite(&(personas[i].jugador), sizeof(indexJugador), 1, archivo); /// escribo los datos del jugador en el archivo
                }
                      fclose(archivo);    /// cierro el archivo jugadores

              ///Creo el archivo estadisticas del jugador ya seteado jugador_00ID (jugador_001m jugador_002..).

        }else{
            BORRAR_PANTALLA;
            puts("ERROR AL ABRIR ARCHIVO JUGADORES"); PAUSE;
       }
}

