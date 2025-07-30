#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED



 ///=== STRUCT'S ===

typedef enum {ACTUAL, LEYENDA} tipoJugador;


typedef struct generalStats {
    int totalPartidos;
    int totalGoles;
    int totalAsistencias;
    int totalGolesTiroLibre;
    int totalGolesPenal;
    int totalHatTricks;
    int totalTarjetaRoja;
    int totalAmarillas;
    int totalMinutosJugados;
    int totalTitular;
    int totalMVP;
    int totalAniosDeCarrera;
    char comentario[1111];
} generalStats;


typedef struct {
    int anio;
    int fecha;
    char mes[11];
    char dia[11];
} stFecha;

typedef struct stats {
    char titular;
    int goles;
    char golTiroLibre;
    int golesTiroLibre;
    int golPenal;
    int asistencias;
    int minutosJugados;
    char roja;
    int amarillas;
} stats;

typedef struct inf{
    char competicion[25];
    char equipo[25];
    char rival[18];
    char estadio[29];
    char resultado[50];
    char figuraDelPartido;
    char comentariodP[1111];
} inf;

typedef struct {
      stFecha fecha;
      stats partido;
      inf info;
}estadisticas;

#endif // JUGADOR_H_INCLUDED




