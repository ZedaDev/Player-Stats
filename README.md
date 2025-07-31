# Player-Stats

Sistema de gestión de jugadores de fútbol y sus estadísticas detalladas, desarrollado en lenguaje C con enfoque en manejo de memoria dinámica, estructuras compuestas, listas enlazadas y archivos binarios para persistencia.

---

## Descripción

Player-Stats es una aplicación en C que permite gestionar jugadores de fútbol, almacenar sus datos personales y registrar estadísticas detalladas de partidos. Utiliza memoria dinámica y estructuras avanzadas como listas enlazadas para manejar datos variables, con persistencia en archivos binarios para conservar la información entre ejecuciones.

.Se pueden visualizar las estadisticas generales desde su debut, por equipo, por equipo y competicion, por competicion, por año, por goles(hat-trick, penal, tiro libre), cada estadistica contiene el mismo recuadro con todas las stats de cada estadistica segun que opcion haya seleccionado.
---

## Características

- Carga dinámica de jugadores y sus estadísticas desde archivos binarios.  
- Menú interactivo para agregar, consultar y modificar datos.  
- Manejo de listas enlazadas para almacenar múltiples estadísticas por jugador.  
- Validación y almacenamiento eficiente en memoria.  
- Persistencia segura mediante archivos binarios.
---

## Estructura del Proyecto

Player-Stats/
│
├── src/ # Código fuente (.c)
├── include/ # Archivos de cabecera (.h)
├── bin/ # Ejecutables (ignorado por Git)
├── obj/ # Archivos objeto (ignorado por Git)
├── .gitignore # Archivos y carpetas ignorados por Git
├── LICENSE # Licencia del proyecto
└── README.md # Documentación principal

yaml
Copiar
Editar

---

## Requisitos Previos

- GCC o compilador compatible con C.  
- Terminal o entorno de desarrollo (ej. Code::Blocks).  
- Git para control de versiones.

---

## Compilación y Ejecución

Desde la raíz del proyecto, compilar con:

```bash
gcc src/*.c -I include -o bin/PlayerStats
Ejecutar con:

bash
Copiar
Editar
./bin/PlayerStats
Funciones Principales
inicProgram(): Inicializa la aplicación, carga datos y prepara estructuras.

cantidad_Jugadores_Archivo(): Cuenta jugadores en archivo binario.

Archivo_A_Jugadores1(): Carga jugadores en array dinámico.

ArchivoEstadisticas_A_Jugadores(): Carga listas enlazadas con estadísticas.

menuPrincipal(): Menú interactivo para operaciones del usuario.

cargarJugador(): Agrega un jugador nuevo.

menu_Estadisticas(): Consulta y modifica estadísticas.

cargarArchivoIndex(): Guarda datos actualizados en archivos binarios.
