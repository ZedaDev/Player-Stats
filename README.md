Player-Stats
Sistema en C para gestionar estadísticas de jugadores de fútbol mediante estructuras compuestas, memoria dinámica y listas enlazadas, con persistencia en archivos binarios.

Descripción
Este proyecto permite almacenar y manipular datos detallados de jugadores y sus estadísticas de partidos. Usa un array dinámico de jugadores, donde cada jugador contiene una lista enlazada con sus estadísticas. El sistema facilita agregar, modificar, consultar y guardar información, asegurando la persistencia entre ejecuciones mediante archivos binarios.

Características principales
Estructuras compuestas y memoria dinámica para manejo eficiente de datos variables.

Lista enlazada para almacenar múltiples estadísticas por jugador.

Interfaz de consola con menús para interacción con el usuario.

Persistencia de datos mediante archivos binarios para garantizar que la información se conserve entre sesiones.

Estructura del proyecto
plaintext
Copiar
Editar
/PlayerStats-C
├── src/                 # Código fuente (.c)
├── include/             # Archivos de cabecera (.h)
├── bin/                 # Ejecutables y binarios generados (no versionado)
├── obj/                 # Archivos objeto (no versionado)
├── README.md            # Documentación principal
├── LICENSE              # Licencia del proyecto (MIT)
└── .gitignore           # Configuración Git para ignorar archivos innecesarios
Flujo de funcionamiento
Inicialización (inicProgram())

Carga jugadores guardados en archivos binarios (cantidad_Jugadores_Archivo(), Archivo_A_Jugadores1()).

Carga las estadísticas asociadas a cada jugador (ArchivoEstadisticas_A_Jugadores()).

Prepara la estructura de datos en memoria para su uso.

Inicia el menú principal (menuPrincipal()).

Menú principal (menuPrincipal())

Agregar un jugador nuevo (cargarJugador()).

Consultar o modificar estadísticas (menu_Estadisticas()).

Guardar datos (cargarArchivoIndex()).

Salir, guardando los cambios automáticamente.

Gestión dinámica de datos

Array dinámico para jugadores con contador de elementos válidos.

Listas enlazadas para manejar estadísticas variables por jugador.

Persistencia

Guardado y carga mediante archivos binarios para evitar pérdida de información.

Requisitos
Entorno: Windows 

IDE recomendado: Code::Blocks 20.3 o superior.

Compilador: GCC compatible con C99 o superior.

Compilación y ejecución
Desde consola, en la raíz del proyecto:

bash
Copiar
Editar
gcc src/*.c -I include -o PlayerStats
./PlayerStats
O abre el proyecto .cbp en Code::Blocks y compílalo directamente.
