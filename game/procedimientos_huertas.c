#include <stdio.h>
#include "granja.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "calculo_enanito.h"
#include "funciones_booleanas.h"
#include "procedimientos_huertas.h"


int generar_numero_aleatorio(){
	int numero_aleatorio = rand () % 19 + 0;
	return numero_aleatorio;
}



void generar_coordenadas_cultivo_inicial(juego_t* juego){

	
	
	for (int i = 0; i < MAX_HUERTA; ++i){

		juego->huertas[i].tope_cultivos = 0;

		do{				
			juego->huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.fila = generar_numero_aleatorio();
			juego->huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.columna = generar_numero_aleatorio();
					
		}while(se_choca_con_huerta(*juego, i) == true);
			
		juego->huertas[i].tope_cultivos++;
			
	}
	 	
}


void generar_coordenadas_cultivos_al_rededor(juego_t* juego){
	
	for (int i = 0; i < MAX_HUERTA; ++i){

		int j = POSICION_CULTIVO_CENTRAL + 1;
		
		for(int k = FILA_SUPERIOR_HUERTA; k <= FILA_INFERIOR_HUERTA; k++){
			
			for(int l = COLUMNA_IZQUIERDA_HUERTA; l <= COLUMNA_DERECHA_HUERTA; l++){

				int fila = juego->huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.fila + k;
				int columna = juego->huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.columna + l;

				if(huerta_fuera_de_terreno(*juego, fila, columna, &j, i) == true ){

					juego->huertas[i].cultivos[j].posicion.fila = fila;
					juego->huertas[i].cultivos[j].posicion.columna = columna;
					juego->huertas[i].tope_cultivos++;
					j++;
				}
			}
		}
	}
}


void inicializar_tipo_huertas(juego_t* juego){
	for (int j = 0; j < MAX_HUERTA; ++j){
	
		for (int i = 0; i < juego->huertas[j].tope_cultivos; ++i){
			
			juego->huertas[j].cultivos[i].ocupado = false;
			juego->huertas[j].cultivos[i].tipo= CULTIVO;
		}

	}

}


void inicializar_movimientos_plantado(juego_t* juego){


	for (int j = 0; j < MAX_HUERTA; ++j){
	
		for (int i = 0; i < juego->huertas[j].tope_cultivos; ++i){
			
			juego->huertas[j].cultivos[i].movimiento_plantado = 0;
		}

	}
}

void inicializar_plagado(juego_t* juego){

	for(int i=0; i < MAX_HUERTA; i++){

		juego->huertas[i].movimientos_plagado = 0;
		juego->huertas[i].plagado = false;
			
	}


}
