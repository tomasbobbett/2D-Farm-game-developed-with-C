#include <stdio.h>
#include "granja.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "calculo_enanito.h"
#include "funciones_booleanas.h"
#include "procedimientos_huertas.h"

bool se_pudre_plaga(juego_t juego, int numero_de_huerta){
	return (juego.movimientos - juego.huertas[numero_de_huerta].movimientos_plagado >= MOVIMIENTOS_MATA_LA_PLAGA && juego.huertas[numero_de_huerta].plagado == true);
}


bool accion_valida(char accion){
	if(accion != ARRIBA && accion != IZQUIERDA && accion != ABAJO && accion != DERECHA && accion != FERTILIZANTE && accion != INSECTICIDA && accion != TOMATE && accion != ZANAHORIA && accion != BROCOLI && accion != LECHUGA){
		printf("Por favor, ingrese una accion valida, ya sea moverse plantar o usar algun tipo de objeto. Si lo que desea es salir, presione (ctrl + c)\n");
		return true;
	}
	return false;
}

bool condiciones_usar_fertilizante(juego_t* juego, char accion){
	return accion == FERTILIZANTE;
}

bool hay_plaga_en_el_vector(juego_t juego){
	bool esta = false;
	
	for(int i= 0; i < juego.tope_objetos; i++){

		if(juego.objetos[i].tipo == PLAGA){
			esta = true;
		}
	}
	return esta;
}

bool esta_jugador_a_distancia_manhattan_2(juego_t juego){
	return (abs((juego.deposito.fila) - (juego.jugador.posicion.fila)) +  abs( (juego.deposito.columna) - (juego.jugador.posicion.columna)) <= DISTANCIA_MANHATTAN_2);
}


bool condiciones_para_cosechar(juego_t juego, int numero_de_huerta, int numero_de_cultivo){

	return juego.huertas[numero_de_huerta].plagado == false && juego.jugador.tope_canasta < MAX_VERDURAS_COSECHADAS;
}

bool cae_plaga_sobre_huerta(juego_t juego, int numero_de_huerta, int numero_de_cultivo, int ubicacion_plaga){
	return (juego.huertas[numero_de_huerta].cultivos[numero_de_cultivo].posicion.fila == juego.objetos[ubicacion_plaga].posicion.fila && juego.huertas[numero_de_huerta].cultivos[numero_de_cultivo].posicion.columna == juego.objetos[ubicacion_plaga].posicion.columna);
}

bool esta_jugador_sobre_fertilizante(juego_t juego, int posicion_fertilizante){

	return (juego.jugador.posicion.fila == juego.objetos[posicion_fertilizante].posicion.fila && juego.jugador.posicion.columna == juego.objetos[posicion_fertilizante].posicion.columna);
}


bool esta_jugador_en_cultivo(juego_t juego, int numero_de_huerta, int numero_de_cultivo){
	return  juego.jugador.posicion.fila == juego.huertas[numero_de_huerta].cultivos[numero_de_cultivo].posicion.fila && juego.jugador.posicion.columna == juego.huertas[numero_de_huerta].cultivos[numero_de_cultivo].posicion.columna;
}


bool condiciones_para_plantar(juego_t juego, int numero_de_huerta, int numero_de_cultivo){

	return juego.huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado == false && juego.huertas[numero_de_huerta].plagado == false;
}


bool blancanieves_se_posiciona_en_espina(juego_t juego, int numero_de_espina){
	return juego.jugador.posicion.fila == juego.objetos[numero_de_espina].posicion.fila && juego.jugador.posicion.columna == juego.objetos[numero_de_espina].posicion.columna;
}

//			FERTILIZAZNTES
bool se_choca_fertilizante_con_objeto(juego_t juego){
	bool se_choca = false;

	for(int i=0 ;i < juego.tope_objetos; i++){

		if(juego.objetos[i].posicion.fila == juego.objetos[juego.tope_objetos].posicion.fila && juego.objetos[i].posicion.columna == juego.objetos[juego.tope_objetos].posicion.columna){

			se_choca = true;
		}
	}

	return se_choca;
}

bool se_choca_fertilizante_blancanieves(juego_t juego){
	
	return (juego.objetos[juego.tope_objetos].posicion.fila == juego.jugador.posicion.fila &&juego.objetos[juego.tope_objetos].posicion.columna == juego.jugador.posicion.columna);

}

bool se_choca_fertilizante_deposito(juego_t juego){

	return (juego.objetos[juego.tope_objetos].posicion.fila == juego.deposito.fila &&juego.objetos[juego.tope_objetos].posicion.columna == juego.deposito.columna);
}

bool se_choca_fertilizante_con_huerta(juego_t juego){
	
	bool se_choca = false;
	
	for(int i = 0; i < MAX_HUERTA; i++){
	
		for(int j=0;j < MAX_PLANTAS; j++){
	
			if(juego.objetos[juego.tope_objetos].posicion.fila == juego.huertas[i].cultivos[j].posicion.fila &&juego.objetos[juego.tope_objetos].posicion.columna == juego.huertas[i].cultivos[j].posicion.columna){
				
				se_choca = true;
			}
		}
	}

	return se_choca;
}

bool se_choca_fertilizante(juego_t juego){

	return (se_choca_fertilizante_con_objeto(juego) || se_choca_fertilizante_con_huerta(juego)|| se_choca_fertilizante_deposito(juego)|| se_choca_fertilizante_blancanieves(juego));
}



bool se_choca_plaga_objeto(juego_t juego, int posicion_plaga_en_vector){

	bool se_choca = false;
	for(int i = 0; i <= juego.tope_objetos; i++){
	
		if(juego.objetos[i].tipo != PLAGA){
	
			if(juego.objetos[i].posicion.fila == juego.objetos[posicion_plaga_en_vector].posicion.fila &&juego.objetos[i].posicion.columna == juego.objetos[posicion_plaga_en_vector].posicion.columna ){
	
				se_choca=true;
			}
		}
	}

	return se_choca;

}
bool se_choca_plaga_blancanieves(juego_t juego, int posicion_plaga_en_vector){
	
	return (juego.objetos[posicion_plaga_en_vector].posicion.fila == juego.jugador.posicion.fila && juego.objetos[posicion_plaga_en_vector].posicion.columna == juego.jugador.posicion.columna);
}

bool se_choca_plaga_deposito(juego_t juego, int posicion_plaga_en_vector){
	
	return (juego.objetos[posicion_plaga_en_vector].posicion.fila == juego.deposito.fila && juego.objetos[posicion_plaga_en_vector].posicion.columna == juego.deposito.columna);
}


bool se_choca_plaga(juego_t juego, int posicion_plaga_en_vector){
	if(hay_plaga_en_el_vector(juego)==true){

		return (se_choca_plaga_deposito(juego, posicion_plaga_en_vector) || se_choca_plaga_objeto(juego, posicion_plaga_en_vector) || se_choca_plaga_blancanieves(juego, posicion_plaga_en_vector));
	}
	return se_choca_plaga_objeto(juego, juego.tope_objetos) || se_choca_plaga_blancanieves(juego, juego.tope_objetos) || se_choca_plaga_deposito(juego, juego.tope_objetos);
}



bool se_choca_con_huerta(juego_t juego, int i){
	bool se_choca = false;
	
	if(i>0){

		for(int r = 1; r <=i; r++){

			for(int k = -2; k <= 2; k++){

				for(int l = -2; l <= 2; l++){

					if(juego.huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.fila == juego.huertas[i-r].cultivos[POSICION_CULTIVO_CENTRAL].posicion.fila + k){
						se_choca = true;
					}
					else if(juego.huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.columna ==juego.huertas[i-r].cultivos[POSICION_CULTIVO_CENTRAL].posicion.columna + l ){
						se_choca = true;
					}
				}	
			}
		}
	}

	return se_choca;

}



bool huerta_fuera_de_terreno(juego_t juego, int fila, int columna, int *j, int i){


	if(fila == juego.huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.fila && columna == juego.huertas[i].cultivos[POSICION_CULTIVO_CENTRAL].posicion.columna){
		return false;
	}
	else if(columna < COLUMNA_BORDE_IZQUIERDO){
		return false;
	}
	else if(columna > COLUMNA_BORDE_DERECHO){
		return false;
	}
	else if(fila < FILA_BORDE_SUP){
		
		return false;
	}
	else if(fila > FILA_BORDE_INF){
		return false;
	}
	
return true;
}



bool se_choca_espinas_huertas(juego_t juego, int i){
	bool se_choca = false;
	
	for(int j =0 ; j< MAX_HUERTA; j++){

		for(int k = 0; k <= MAX_PLANTAS; k++){

			if(juego.objetos[i].posicion.fila == juego.huertas[j].cultivos[k].posicion.fila && juego.objetos[i].posicion.columna == juego.huertas[j].cultivos[k].posicion.columna){
				se_choca = true;
			}
			
		}
	}

	return se_choca;

}



bool se_choca_espinas_espinas(juego_t juego, int i){
	bool se_choca = false;
		if(i > 0){

			for(int j = 1; j <= juego.tope_objetos; j++){

				if(juego.objetos[i].tipo == ESPINA){

					if(juego.objetos[i].posicion.fila == juego.objetos[i-j].posicion.fila && juego.objetos[i].posicion.columna == juego.objetos[i-j].posicion.columna){
						se_choca = true;
					}	
				}
				
			}
		}
	return se_choca;

}

bool se_choca_espina(juego_t juego, int numero_plaga){

	return (se_choca_espinas_huertas(juego, numero_plaga) == true || se_choca_espinas_espinas(juego, numero_plaga)==true);
}

bool se_choca_personaje_huerta(juego_t juego){
	bool se_choca = false;

	for(int i = 0; i < MAX_HUERTA; i++){

		for(int j = 0; j < MAX_PLANTAS; j++){

			if(juego.jugador.posicion.fila == juego.huertas[i].cultivos[j].posicion.fila && juego.jugador.posicion.columna == juego.huertas[i].cultivos[j].posicion.columna){
				
				se_choca = true;
			}
		}
	}
	return se_choca;
}



bool se_choca_personaje_espinas(juego_t juego){

	for(int i = 0; i <= CANT_ESPINAS; i++){

		if(juego.jugador.posicion.fila == juego.objetos[i].posicion.fila && juego.jugador.posicion.columna == juego.objetos[i].posicion.columna){
			return true;
		}
		
	}
	return false;
}

bool se_choca_personaje(juego_t juego){

	return (se_choca_personaje_huerta(juego) == true || se_choca_personaje_espinas(juego) == true);
}

bool se_choca_deposito_huertas(juego_t juego){
	bool se_choca = false;

	for(int i = 0; i <= MAX_HUERTA; i++){

		for(int j = 0; j < MAX_PLANTAS; j++){

			if(juego.deposito.fila == juego.huertas[i].cultivos[j].posicion.fila && juego.deposito.columna == juego.huertas[i].cultivos[j].posicion.columna){
				se_choca = true;
			}
		}
	}
	return se_choca;
}


bool se_choca_deposito_espinas(juego_t juego){
	bool se_choca = false;
	for(int i =0; i < CANT_ESPINAS; i++){

		if(juego.deposito.fila == juego.objetos[i].posicion.fila && juego.deposito.columna == juego.objetos[i].posicion.columna){
			se_choca = true;
		}
	}
	return se_choca;

}



bool se_choca_deposito_blancanieves(juego_t juego){
	
	return juego.deposito.fila == juego.jugador.posicion.fila && juego.deposito.columna == juego.jugador.posicion.columna;
}

bool se_choca_deposito(juego_t juego){

	return (se_choca_deposito_huertas(juego) == true || se_choca_deposito_espinas(juego) == true || se_choca_deposito_blancanieves(juego) == true);
}






