
#ifndef __PROCEDIMIENTOS_IMPRIMIR_JUEGO_H__
#define __PROCEDIMIENTOS_IMPRIMIR_JUEGO_H__


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Le da un espacio en blanco a todas las posiciones de la matriz terreno.
*/
void inicializar_terreno_vacio(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubica las huertas en la matriz terreno.
*/
void mostrar_huertas_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubica las espinas en la matriz terreno.
*/
void mostrar_espinas_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubicalos fertilizantes en la matriz terreno
*/
void mostrar_fertilizantes_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubica el deposito en la matriz terreno.
*/
void mostrar_deposito_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubica el jugador en la matriz terreno.
*/
void mostrar_blancanieves_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Ubica las plagas en la matriz terreno.
*/
void mostrar_plaga_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1], int ubicacion_plaga);


/*
PRE: El struct juego esta inicializado correctamente.
	 La matriz del terreno esta inicializada corrrectamente.
POST: Imprime la matriz terreno.
*/
void imprimir_juego(juego_t	juego, char terreno[FILAS+1][COLUMNAS+1]);


#endif /*__PROCEDIMIENTOS_IMPRIMIR_JUEGO_H__*/