#include <stdio.h>
#include "granja.h"
#include "calculo_enanito.h"
#include <stdlib.h>
#include <time.h>
#include "funciones_booleanas.h"
#include "procedimientos_huertas.h"


const char START = 'S';


int main(){
	srand (( unsigned)time(NULL));
	juego_t juego;
	char inicial_enanito;
	char start_input;
	char accion;
	calcular_enanito(&inicial_enanito);

	char enanito = inicial_enanito;

	inicializar_juego(&juego, enanito);
	system("clear");
		
	
	if(inicial_enanito == GRUÑÓN){
		printf("Segun nuestros calculos el enanito que mas se asocia a tu personalidad es el Gruñon. Por lo que empezaras el juego con 150 monedas.\n");
		printf("Tu objetivo es llegar a las mil monedas plantando, cosechando tus verduras y vendiendolas acercandote al deposito (D).\n");
		printf("Recuerda que las plagas pueden arruinar tus cultivos. Si alguna cae sobre tu huerta debes usar el insecticida (solo 3 disponibles) antes que pasen 10 movimientos desde que cayo la plaga.\n");
		printf("Tambien hay ubicadas 5 espinas por el mapa. Si las pisas perderas 5 monedas\n");
		printf("Si llegas a las 0 monedas perdes el juego.\n");	
		printf("Que tengas un buen dia de campo!.\n\n");
		printf("Para iniciar el juego ingrese (S). Si desea salir ingrese cualquier otra tecla.\n");
		scanf(" %c", &start_input);
	}	
	else if(inicial_enanito == DORMILON){
		printf("Segun nuestros calculos el enanito que mas se asocia a tu personalidad es el Dormilon. Por lo que empezaras el juego con 200 monedas.\n");
		printf("Tu objetivo es llegar a las mil monedas plantando, cosechando tus verduras y vendiendolas acercandote al deposito (D).\n");
		printf("Recuerda que las plagas pueden arruinar tus cultivos. Si alguna cae sobre tu huerta debes usar el insecticida (solo 3 disponibles) antes que pasen 10 movimientos desde que cayo la plaga.\n");
		printf("Tambien hay ubicadas 5 espinas por el mapa. Si las pisas perderas 5 monedas\n");
		printf("Si llegas a las 0 monedas perdes el juego.\n");	
		printf("Que tengas un buen dia de campo!.\n\n");
		printf("Para iniciar el juego ingrese (S). Si desea salir ingrese cualquier otra tecla.\n");
		scanf(" %c", &start_input);
	}
	else if(inicial_enanito == SABIO){
		printf("Segun nuestros calculos, el enanito que mas se asocia a tu personalidad es el Sabio. Por lo que empezaras el juego con 250 monedas.\n");
		printf("Tu objetivo es llegar a las mil monedas plantando, cosechando tus verduras y vendiendolas acercandote al deposito (D).\n");
		printf("Recuerda que las plagas pueden arruinar tus cultivos. Si alguna cae sobre tu huerta debes usar el insecticida (solo 3 disponibles) antes que pasen 10 movimientos desde que cayo la plaga.\n");
		printf("Tambien hay ubicadas 5 espinas por el mapa. Si las pisas perderas 5 monedas\n");
		printf("Si llegas a las 0 monedas perdes el juego.\n");	
		printf("Que tengas un buen dia de campo!.\n\n");
		printf("Para iniciar el juego ingrese (S). Si desea salir ingrese cualquier otra tecla.\n");
		scanf(" %c", &start_input);
	}
	else{
		printf("Segun nuestros calculos tu enanito que mas se asocia a tu personalidad es el Feliz. Por lo que empezaras el juego con 300 monedas.\n");
		printf("Tu objetivo es llegar a las mil monedas plantando, cosechando tus verduras y vendiendolas acercandote al deposito (D).\n");
		printf("Recuerda que las plagas pueden arruinar tus cultivos. Si alguna cae sobre tu huerta debes usar el insecticida (solo 3 disponibles) antes que pasen 10 movimientos desde que cayo la plaga.\n");
		printf("Tambien hay ubicadas 5 espinas por el mapa. Si las pisas perderas 5 monedas\n");
		printf("Si llegas a las 0 monedas perdes el juego.\n");	
		printf("Que tengas un buen dia de campo!.\n\n");
		printf("Para iniciar el juego ingrese (S). Si desea salir ingrese cualquier otra tecla.\n");
		scanf(" %c", &start_input);
	}
			
	system("clear");
	if(start_input == START){
		do{

			imprimir_terreno(juego);
			printf("Movimientos:%i\n", juego.movimientos);
			printf("\nMonedas:%i\n",juego.jugador.cant_monedas );

			printf("\nTenes %i insecticidas\n", juego.jugador.cant_insecticidas);
			for(int i = 0; i < MAX_HUERTA; i++){

				for(int j=0; j < juego.huertas[i].tope_cultivos; j++){

					if(juego.huertas[i].cultivos[j].tipo != CULTIVO && juego.huertas[i].cultivos[j].tipo != 0){

						int movimientos_plantado = juego.movimientos - juego.huertas[i].cultivos[j].movimiento_plantado;
						printf("[%c] Edad = %i\n", juego.huertas[i].cultivos[j].tipo, movimientos_plantado);
					}
				}
			}
			printf("Canasta:");

			for (int i = 0; i < juego.jugador.tope_canasta; ++i){

				printf("(%c)", juego.jugador.canasta[i]);
				
				if(i == MAX_VERDURAS-1){

					printf("\nNo te entran mas verduras en la canasta. Hay que ir a vender en el deposito para seguir cosechando.\n");
				}
			}
			do{
				printf("\n");
				scanf(" %c", &accion);

			}while(accion_valida(accion));

			system("clear");

			realizar_jugada(&juego, accion);

			printf("\n");

		}while(estado_juego(juego) == SIGUE_JUGANDO);

		if(estado_juego(juego) == PERDIDO){
			printf("GAME OVER PA :/\n");
		}
		else if(estado_juego(juego) == GANADO){
			printf("Felicidades, ganaste el juego, se ve que sos agil para la agricultura. Con estas 1000 monedas ¿En que pensas gastarlas?\n");
		}
	}
	else{
		system("exit");
	}

	return 0;
}