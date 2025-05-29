#include <stdio.h>
#include "granja.h"
#include <stdlib.h>
#include "calculo_enanito.h"
#include "funciones_booleanas.h"
#include "procedimientos_huertas.h"

void inicializar_terreno_vacio(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){
	for(int i = 0; i <= FILAS; i++){

		for(int j = 0; j <= COLUMNAS; j++){

			terreno[i][j] = ' ';
		}
		
	}
}

void mostrar_huertas_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){

for (int i = 0; i < MAX_HUERTA; i++){

		for(int j = 0; j < juego.huertas[i].tope_cultivos; j++){

			terreno[juego.huertas[i].cultivos[j].posicion.fila][juego.huertas[i].cultivos[j].posicion.columna] = juego.huertas[i].cultivos[j].tipo;
		}
	}

}

void mostrar_espinas_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){

	for(int i=0; i < CANT_ESPINAS; i++){

		terreno[juego.objetos[i].posicion.fila][juego.objetos[i].posicion.columna] = juego.objetos[i].tipo;
	}

}

void mostrar_fertilizantes_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){

	if(juego.movimientos >= INTERVALO_PARA_GENERAR_FERTILIZANTES ){

		for(int i = 0; i < juego.tope_objetos; i++){

			if(juego.objetos[i].tipo == FERTILIZANTE){

				terreno[juego.objetos[i].posicion.fila][juego.objetos[i].posicion.columna] = juego.objetos[i].tipo;
			}
		}
	}
}

void mostrar_deposito_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){

	terreno[juego.deposito.fila][juego.deposito.columna] = DEPOSITO;
}

void mostrar_blancanieves_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1]){

	terreno[juego.jugador.posicion.fila][juego.jugador.posicion.columna] = BLANCANIEVES;
}

void mostrar_plaga_en_terreno(juego_t juego, char terreno[FILAS+1][COLUMNAS+1], int ubicacion_plaga){

	if(juego.movimientos >= INTERVALO_PARA_GENERAR_PLAGAS && hay_plaga_en_el_vector(juego)){

		terreno[juego.objetos[ubicacion_plaga].posicion.fila][juego.objetos[ubicacion_plaga].posicion.columna] = PLAGA;
	}
}

void imprimir_juego(juego_t	juego, char terreno[FILAS+1][COLUMNAS+1]){

	for(int i = 0; i < FILAS; i++){

		for(int j = 0; j < COLUMNAS; j++){

			printf("[%c]", terreno[i][j]);
		}
			if(i == 9){
				printf("       | Instrucciones del tio Tom:");
			}
			if(i == 10){
				printf("       |   Los tomates se pueden cosechar a los 20 movimientos");
			}
			if(i == 11){
				printf("       |   Las zanahorias se pueden cosechar a los 15 movimientos");
			}
			if(i == 12){
				printf("       |   Los brocolis se pueden cosechar a los 10 movimientos");
			}
			if(i == 13){
				printf("       |   Las lechugas se pueden cosechar a los 10 movimientos");
			}
		printf("\n");
	}

}
