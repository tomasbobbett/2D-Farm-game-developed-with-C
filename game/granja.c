#include <stdio.h>
#include "granja.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "calculo_enanito.h"
#include "funciones_booleanas.h"
#include "procedimientos_huertas.h"
#include "procedimientos_imprimir_juego.h"



/*
PRE:Recibe las funciones defindias correctamente y funcionando de manera correcta. 
	El struct del juego esta bien definido.
POST:LLama todos los procedimientos definidos en la biblioteca de los procedimientos de estas. Asi completando todo el struct huertas y cultivos.
*/
void inicializar_huertas(juego_t* juego){

	generar_coordenadas_cultivo_inicial(juego);
	generar_coordenadas_cultivos_al_rededor(juego);
	inicializar_tipo_huertas(juego);
	inicializar_movimientos_plantado(juego);
	inicializar_plagado(juego);
}


/*
PRE: Recibe la estructura juego de manera correcta.
	 Todas las constantes llegan con el valor correcto definido en el .h de las funciones booleanas
	 Las funciones booleanas definidas en el .h "funciones_booleanas.h" son recibidas y devuelven el valor correcto (1 o 0) o (true o false).
POST:Ubica 5 espinas en el vector objetos de la posición 0 a la 4 sin pisarse con ningun otro objeto o cualquiier cosa que este en el mapa.
*/
void inicializar_espinas(juego_t* juego){

	for(int i = 0; i< CANT_ESPINAS; i++){

		juego->objetos[i].tipo = ESPINA;

		do{   
			juego->objetos[i].posicion.fila = generar_numero_aleatorio();
			juego->objetos[i].posicion.columna = generar_numero_aleatorio();
		}while(se_choca_espina(*juego, i));
		
		juego->tope_objetos++;
	}
}


/*
PRE: El struct juego esta bien definido.
POST: Inicializa los obstaculos.
*/
void inicializar_obstaculos(juego_t* juego){
	
	juego->tope_objetos = 0;
	inicializar_espinas(juego);
}


/*
PRE:Recibe y manda a los procedimientos llamados dentro del procedimiento el struct juego de manera correcta.
	Todas las constantes llegan con el valor correcto definido en el .h de las funciones booleanas.
POST: Inicializa que el jugador al comenzar el juego tiene 3 y solo 3 insecticidas en toda la partida.
*/
void inicializar_insecticidas(juego_t* juego){

	juego->jugador.cant_insecticidas = CANT_INSECTICIDAS_INICIAL;
}


/*
PRE:Recibe el struct juego correctamente.
POST: Inicializa las herramientas. 
*/
void inicializar_herramientas(juego_t* juego){

	inicializar_insecticidas(juego);
}


/*
PRE: Recibe y manda a los procedimientos llamados dentro del procedimiento el struct juego de manera correcta.
	 Recibe las constantes definidas en la biblioteca de las funciones booleanas con el valor correcto asignado en el mismo.
POST:Le da una posicion aleatoria al jugador (blancanieves) sin que se choque con las huertas o con alguna espina que este en el terreno.
*/
void inicializar_posicion_jugador(juego_t* juego){
	do{

	juego->jugador.posicion.fila =  generar_numero_aleatorio();
	juego->jugador.posicion.columna = generar_numero_aleatorio();

	}while(se_choca_personaje(*juego));
}


/*
PRE: Recibe la inicial del tp1 con el dato correcto y valido.
	Recibe de manera correcta el struct juego.
POST: Devuelve la cantidad de moendas incial dependiendo de la incial que te toque luego de jugar el tp1.
*/
void inicializar_monedas_iniciales(juego_t* juego, char enanito){

	if(enanito == GRUÑÓN){
		juego->jugador.cant_monedas = MONEDAS_GRUÑÓN;
	}
	else if(enanito == FELIZ){
		juego->jugador.cant_monedas = MONEDAS_FELIZ;
	}
	else if(enanito == DORMILON){
		juego->jugador.cant_monedas = MONEDAS_DORMILON;
	}
	else if(enanito == SABIO){
		juego->jugador.cant_monedas = MONEDAS_SABIO;
	}
}


/*
PRE: Recibe y manda a los procedimientos llamados dentro del procedimiento el struct juego de manera correcta.
POST: inicializa el tope de la canasta.
*/
void inicializar_canasta(juego_t* juego){
	juego->jugador.tope_canasta = 0;
}


/*
PRE:Recibe y manda a los procedimientos llamados dentro del procedimiento el struct juego de manera correcta.
	recibe los procedimientos anteriormente de manera correcta.
POST: Inicializa el jugador dentro del struct juego.
*/
void inicializar_jugador(juego_t* juego, char enanito){

	inicializar_posicion_jugador(juego);
	inicializar_monedas_iniciales(juego, enanito);
	inicializar_canasta(juego);
	juego->jugador.tiene_fertilizante = false;
}

	
/*
PRE:Recibe y manda a los procedimientos llamados dentro del procedimiento el struct juego de manera correcta.
POST: Inicializa el deposito.
*/			
void inicializar_deposito(juego_t* juego){

	do{
		juego->deposito.fila = generar_numero_aleatorio();
		juego->deposito.columna = generar_numero_aleatorio();

	}while(se_choca_deposito(*juego));
}


/*
PRE: Recibe el struct juego con los datos correctops
POST:Inicializa que el jugador hizo 0 movimientos al iniciar el juego.
*/
void inicializar_movimientos(juego_t* juego){
	juego->movimientos = 0;
}


void inicializar_juego(juego_t* juego, char enanito){
	inicializar_movimientos(juego);
	inicializar_huertas(juego);
	inicializar_obstaculos(juego);
	inicializar_herramientas(juego);
	inicializar_jugador(juego, enanito);
	inicializar_deposito(juego);
}




int estado_juego (juego_t juego){

	if(juego.jugador.cant_monedas >= MONEDAS_PARA_GANAR){
		return GANADO;
	}
	else if(juego.jugador.cant_monedas <= 0){
		return PERDIDO;
	}
	else{
		return SIGUE_JUGANDO;
	}
}


/*
PRE:Recibe los valores del struct juego validos y con estos correcto.
	La funcion booleana hay_plaga_en_el_vector funciona correctamente y no genera un bucle infinito con el while
POST: Devuelve un numero entero con la posicion de la plaga en el vector objetos.
*/
int posicion_vector_plaga(juego_t juego){

	int ubicacion_plaga = 0;
	if(hay_plaga_en_el_vector(juego)){

		for(int i = 0; i < juego.tope_objetos; i++){

			if(juego.objetos[i].tipo == PLAGA){

				ubicacion_plaga = i;
			}
		}		
	}	
	return ubicacion_plaga;
}


/*
PRE: Recibe el struct juego con los valor validos y con los mismmos correctos.
	La funcion "posicion_vector_plaga" funciona correctamente y devuelve el valor correcto y valido.
POST: Devuelve y ubica las plagas aleatoriamente sin que se choque con nada que este antes de estas.
*/
void ubicar_plagas(juego_t* juego){

	if((juego->movimientos % INTERVALO_PARA_GENERAR_PLAGAS) == 0  && juego->movimientos > 0 ){
				
		if(hay_plaga_en_el_vector(*juego)){
				
			do{
				juego->objetos[posicion_vector_plaga(*juego)].posicion.fila =generar_numero_aleatorio();
				juego->objetos[posicion_vector_plaga(*juego)].posicion.columna = generar_numero_aleatorio();
				juego->objetos[posicion_vector_plaga(*juego)].tipo = PLAGA;
			}while(se_choca_plaga(*juego, posicion_vector_plaga(*juego)));
			
		}	
		else{
			do{
				juego->objetos[juego->tope_objetos].posicion.fila = generar_numero_aleatorio();
				juego->objetos[juego->tope_objetos].posicion.columna = generar_numero_aleatorio();
				juego->objetos[juego->tope_objetos].tipo = PLAGA ;
			}while(se_choca_plaga(*juego, juego->tope_objetos));

			juego->tope_objetos++;
		}		
		printf("Oh no! hay una plaga en el campo! \n");
	}
}	


/*
PRE: Recibe el struct juego con los valor validos y con los mismmos correctos.
	 Recibe todas lsa funciones booleanas de manera correecta devolviendo valores validos.
	 El tope objetos es correcto y valido.
	 Las constantes estan definidas correctamente y las recibe de esta manera tambien.
POST:Ubica el fertilizante cada vez q pasan 15 movimientos y lo ubica de manera aleatoria sin que se choque con algo que este antes de q aparezca elo mismo.
*/
void ubicar_fertilizante(juego_t* juego){

		juego->objetos[juego->tope_objetos].tipo = FERTILIZANTE;

		do{
			
			juego->objetos[juego->tope_objetos].posicion.fila = generar_numero_aleatorio();
			juego->objetos[juego->tope_objetos].posicion.columna = generar_numero_aleatorio();
			
		}while(se_choca_fertilizante(*juego));
		printf("Pasaste 15 movimientos, te tiro un fertilizante.\n");
		juego->tope_objetos++;	
}


/*
PRE: Recibe el struct juego de manera valida y cn los datos correctos
POST: Modifica la posicion de blancanieves dependiendo de la accion ingresada,
*/
void mover_blancanieves_arriba(juego_t* juego){
	if(juego->jugador.posicion.fila > FILA_BORDE_SUP){
		juego->jugador.posicion.fila--;
		juego->movimientos++;
	}	
}


/*
PRE: Recibe el struct juego de manera valida y cn los datos correctos
POST: Modifica la posicion de blancanieves dependiendo de la accion ingresada,
*/
void mover_blancanieves_abajo(juego_t* juego){
	if(juego->jugador.posicion.fila < FILA_BORDE_INF){
		juego->jugador.posicion.fila++;
		juego->movimientos++;
	}
}


/*
PRE: Recibe el struct juego de manera valida y cn los datos correctos
POST: Modifica la posicion de blancanieves dependiendo de la accion ingresada,
*/
void mover_blancanieves_izquierda(juego_t* juego){
	if(juego->jugador.posicion.columna > COLUMNA_BORDE_IZQUIERDO){
		juego->jugador.posicion.columna--;
		juego->movimientos++;
	}
}


/*
PRE: Recibe el struct juego de manera valida y cn los datos correctos
POST:Modifica la posicion de blancanieves dependiendo de la accion ingresada,
*/
void mover_blancanieves_derecha(juego_t* juego){
	
	if(juego->jugador.posicion.columna < COLUMNA_BORDE_DERECHO){
		juego->jugador.posicion.columna++;
		juego->movimientos++;			
	}
}


/*
PRE: Recibe los valors del struct juego de manera correcta y con datos validos.
	Las funciones llamadas funcionan correctamente.
POST: Ubica las plagas al pasar 10 movimientos y los fertlizantes al pasar los 15.
*/
void ubicar_plagas_fertilizantes(juego_t* juego){

	if((juego->movimientos % INTERVALO_PARA_GENERAR_PLAGAS) == 0  && juego->movimientos > 0 ){
			ubicar_plagas(juego);	
	}
	if((juego->movimientos % INTERVALO_PARA_GENERAR_FERTILIZANTES) == 0  && juego->movimientos > 0 ){
		ubicar_fertilizante(juego);
	}
}


/*
PRE:Recibe las funciones y procedimientos llamadas correctamente y con datos validos
POST: Cambia la posicion de blancanieves dependiendo de cual sea la accion ingresada.
*/
void mover_blancanieves(juego_t* juego, char accion){

		if(accion == ARRIBA){
			mover_blancanieves_arriba(juego);
			ubicar_plagas_fertilizantes(juego);
		}
		else if(accion == ABAJO){
			mover_blancanieves_abajo(juego);
			ubicar_plagas_fertilizantes(juego);
		}
		else if(accion == IZQUIERDA){
			mover_blancanieves_izquierda(juego);
			ubicar_plagas_fertilizantes(juego);
		}
		else if(accion == DERECHA){
			mover_blancanieves_derecha(juego);
			ubicar_plagas_fertilizantes(juego);
		}
}


/*
PRE: Recibe todos los datos del struct juego correctamente y con datos que sean validos.
POST Le resta 5 monedas al jugador si es que pisa alguna de las 5 espinas distribuidas sobre el terreno.
*/
void cae_blancanieves_en_espina(juego_t* juego){
	
	for(int i = 0; i < CANT_ESPINAS; i++){

		if(blancanieves_se_posiciona_en_espina(*juego, i)){
		
			juego->jugador.cant_monedas = juego->jugador.cant_monedas - VALOR_CAE_ESPINA;
		}
	}
}


/*
PRE: Recibe todos los datos del struct juego correctamente y con datos que sean validos.
	 Recibe constantes definidas en el .h de funciones booleanas con datos validos y correctos.
POST: Planta el tomate en la huerta.
*/
void plantar_tomate(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){

	printf("Genial, plantaste un tomate (-5 moneditas)\n");
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = TOMATE;
	juego->jugador.cant_monedas = juego->jugador.cant_monedas - VALOR_TOMATE;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = true;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].movimiento_plantado = juego->movimientos;
}


/*
PRE: Recibe todos los datos del struct juego correctamente y con datos que sean validos.
	 Recibe constantes definidas en el .h de funciones booleanas con datos validos y correctos.
POST: Planta la zanahoria en la huerta.
*/
void plantar_zanahoria(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){

	printf("Genial, plantaste una zanahoria (-10 moneditas)\n");
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = ZANAHORIA;
	juego->jugador.cant_monedas = juego->jugador.cant_monedas - VALOR_ZANAHORIA;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = true;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].movimiento_plantado = juego->movimientos;	
}


/*
PRE: Recibe todos los datos del struct juego correctamente y con datos que sean validos.
	 Recibe constantes definidas en el .h de funciones booleanas con datos validos y correctos.
POST: Planta el brocoli en la huerta.
*/
void plantar_brocoli(juego_t* juego,  int numero_de_huerta, int numero_de_cultivo){

	printf("Genial, plantaste una BROCOLI (-15 moneditas)\n");
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = BROCOLI;
	juego->jugador.cant_monedas = juego->jugador.cant_monedas - VALOR_BROCOLI;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = true;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].movimiento_plantado = juego->movimientos;
}


/*
PRE: Recibe todos los datos del struct juego correctamente y con datos que sean validos.
	 Recibe constantes definidas en el .h de funciones booleanas con datos validos y correctos.
POST: Planta la lechuga en la huerta.
*/
void plantar_lechuga(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){

	printf("Genial, plantaste una lechuga (-20 moneditas)\n");
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = true;
	juego->jugador.cant_monedas = juego->jugador.cant_monedas - VALOR_LECHUGA;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].movimiento_plantado = juego->movimientos;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = LECHUGA;
}


/*
PRE: El struct juego tiene los valores correctos y validos.
POST: Planta las verduras.
*/
void plantar(juego_t* juego, char accion){

	for(int i = 0; i< MAX_HUERTA; i++){

		for(int j =0; j < MAX_PLANTAS; j++){

			if( condiciones_para_plantar(*juego, i, j) && esta_jugador_en_cultivo(*juego, i, j)){

				if(accion == TOMATE && juego->jugador.cant_monedas >= VALOR_TOMATE){
					plantar_tomate(juego, i, j);
				}
				else if(accion == ZANAHORIA && juego->jugador.cant_monedas >= VALOR_ZANAHORIA){
					plantar_zanahoria(juego, i, j);
				}	
				else if(accion == BROCOLI && juego->jugador.cant_monedas >= VALOR_BROCOLI){
					plantar_brocoli(juego, i, j);
				}
				else if(accion == LECHUGA && juego->jugador.cant_monedas >= VALOR_LECHUGA){
					plantar_lechuga(juego, i, j);
				}
			}
		}
	}
}
			

/*
PRE:El struct juego tiene los valores correctos y validos.
	Las constantes definidas en el .h de las funiones booleanas llegan con los datos correctos y validos.
	Recibe todos los topes con la informacion correcta y valida.
POST: Cosecha el tomate agregandolo a la canasta.
*/
void cosechar_tomate(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){

	printf("El tomate ya esta listo para cosechar, tenes 10 movimientos para cosecharlo.\n");
	juego->jugador.canasta[juego->jugador.tope_canasta] = juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo;
	juego->jugador.tope_canasta++;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = false;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = CULTIVO;
}


/*
PRE:El struct juego tiene los valores correctos y validos.
	Las constantes definidas en el .h de las funiones booleanas llegan con los datos correctos y validos.
	Recibe todos los topes con la informacion correcta y valida.
POST: Cosecha la zanahoria agregandola a la canasta.
*/
void cosechar_zanahoria(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){

	printf("La zanahoria ya esta lista para cosechar, tenes 10 movimientos para cosecharlo antes que se pudra\n");
	juego->jugador.canasta[juego->jugador.tope_canasta] = juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo;
	juego->jugador.tope_canasta++;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = false;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = CULTIVO;
}


/*
PRE:El struct juego tiene los valores correctos y validos.
	Las constantes definidas en el .h de las funiones booleanas llegan con los datos correctos y validos.
	Recibe todos los topes con la informacion correcta y valida.
POST: Cosecha el brocoli agregandolo a la canasta.
*/
void cosechar_brocoli(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){
						
	printf("El brocoli ya esta listo para cosechar, tenes 15 movimientos para cosecharlo antes que se pudra\n");
	juego->jugador.canasta[juego->jugador.tope_canasta] = juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo;
	juego->jugador.tope_canasta++;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = false;
	juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = CULTIVO;	
}


/*
PRE:El struct juego tiene los valores correctos y validos.
	Las constantes definidas en el .h de las funiones booleanas llegan con los datos correctos y validos.
	Recibe todos los topes con la informacion correcta y valida.
POST: Cosecha la lechuga agregandola a la canasta.
*/
void cosechar_lechuga(juego_t* juego, int numero_de_huerta, int numero_de_cultivo){
		
		juego->jugador.canasta[juego->jugador.tope_canasta] = juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo;
		juego->jugador.tope_canasta++;
		juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].ocupado = false;
		juego->huertas[numero_de_huerta].cultivos[numero_de_cultivo].tipo = CULTIVO;
}


/*
PRE:El struct juego tiene los valores correctos y validos.
	La accion es recibida con el dato correcto y valido.
POST:  Llama a los procedimientos de cosechar guardandolos en la canasta cuando se para sobre los mismos maduros.
*/
void cosechar(juego_t* juego,char accion){
	for(int i = 0; i < MAX_HUERTA; i++){

		for(int j=0; j< MAX_PLANTAS; j++){

			if(condiciones_para_cosechar(*juego, i, j)) {

				if( esta_jugador_en_cultivo(*juego, i, j)){

					int movimientos_plantado = juego->movimientos - juego->huertas[i].cultivos[j].movimiento_plantado;

					if(juego->huertas[i].cultivos[j].tipo == TOMATE && movimientos_plantado >= MADURACION_TOMATE && movimientos_plantado < VIDA_TOMATE){

						cosechar_tomate(juego, i, j);
					}
					else if(juego->huertas[i].cultivos[j].tipo == ZANAHORIA && movimientos_plantado >= MADURACION_ZANAHORIA && movimientos_plantado < VIDA_ZANAHORIA){
						cosechar_zanahoria(juego, i ,j );
					}
					else if(juego->huertas[i].cultivos[j].tipo == BROCOLI && movimientos_plantado >= MADURACION_BROCOLI && movimientos_plantado < VIDA_BROCOLI){
						cosechar_brocoli(juego, i, j);
					}
					else if(juego->huertas[i].cultivos[j].tipo == LECHUGA && movimientos_plantado >= MADURACION_LECHUGA && movimientos_plantado < VIDA_LECHUGA){

						cosechar_lechuga(juego,i ,j);
					}
				}
			}
		}
	}
}


/*
PRE:El struct juego esta inicializado de manera correcta y este lo recibe de la misma forma.
POST: Suma la cantidad de monedas correspondiente a que verdura se vendio.
*/
void vender_verdura(juego_t *juego, int posicion_canasta, int valor_venta){

	juego->jugador.cant_monedas = juego->jugador.cant_monedas + valor_venta;
	juego->jugador.canasta[posicion_canasta] = 0;
}

/*
PRE:El struct juego tiene los valores correctos y validos.
	Las constantes definidas con anterioridad son validas y tienen el valor correcto.
	Los topes tienen el valor correcto y valido.
POST: Al estar a una distandia manhattan 2 del deposito, se venden automaticamente todas las verduras que esten en la canasta.
*/
void vender_productos(juego_t* juego){
	
	if(esta_jugador_a_distancia_manhattan_2(*juego)){

		for(int k = 0; k <= juego->jugador.tope_canasta; k++){

			switch(juego->jugador.canasta[k]){

				case TOMATE: 
					vender_verdura(juego, k, VALOR_VENTA_TOMATE);
					printf("Wow un tomate fresco y recien cosechado, gracias por esta bendicion (+30 moneditas)\n\n");
					printf("DATO CURIOSO: Sabias que los tomates luego de ser cosechados siguen madurando? Es por eso que muchas veces se saca antes que este completamente maduro\n\n");
				break;

				case ZANAHORIA: 
					vender_verdura(juego, k, VALOR_VENTA_ZANAHORIA);
					printf("Perfecto, ahi mi socio te paga por tus hermosas zanahorias (+50 moneditas)\n\n");
					printf("DATO CURIOSO: Sabias que en 1982 el transbordador espacial Challenger llevo al espacio un invernadero con zanahorias para experimentar su cultivo en la microgravedad?\n\n");
					
				
				break;

				case BROCOLI: 
					vender_verdura(juego, k, VALOR_VENTA_BROCOLI);
					printf("Que rico el brocoli. Y mas el de su hermoso campo (+70 moneditas)\n\n");
					printf("DATO CURIOSO: Sabias que en 2010 la nasa agrego el brocoli al menu de la Estacion Esacial Internacional? Podriamos decir que son astrocolis.\n\n");
				break;
				
				case LECHUGA : 
					vender_verdura(juego, k, VALOR_VENTA_LECHUGA);
					printf("Que lechuga tan verde por dios!! (+80 moneditas)\n\n");
					printf("DATO CURIOSO: Sabias que la lechuga es una de las verduras mas antiguas que se conocen. Tan antiguas que no se sabe bien de donde vino!\n\n");  
		 		break;		
			}
			
		}
	juego->jugador.tope_canasta = 0;
	}
}


/*
PRE: El struct juego esta bien inicializado y este lo recibe de manera correcta y con datos validos.
POST: Elimina el fertilizante recogido del vector objetos.
*/
void eliminar_fertilizante_recogido(juego_t* juego, int i){
	for(int j = i; i < juego->tope_objetos - 1; i++){			
		juego->objetos[j] = juego->objetos[i+1];	
	}
	juego->tope_objetos -- ;
	juego->jugador.tiene_fertilizante = true;
}



/*
PRE: Recibe las constantes definifas correctamente y validas-
	El struct juego tiene los valores correctos y validos.
	Los topes tienen el valor correcto y valido.
POST: Cuando el jugador pasa por un fertilizante y este no tiene uno antes. El fertlizante desaparece del mapa y del vector. Cambiando a que el jugador tiene un fertilizante.
*/
void agarrar_fertilizante(juego_t* juego){

	for(int i = 0; i < juego->tope_objetos; i++){

		if(juego->objetos[i].tipo == FERTILIZANTE){

			int ubicacion_fertilizante = i;

			if( esta_jugador_sobre_fertilizante(*juego, ubicacion_fertilizante) && juego->jugador.tiene_fertilizante == false){
				
				eliminar_fertilizante_recogido(juego, i);		
			}
		}
	}
}


/*
PRE:El struct juego tiene los valores correctos y validos.
Las constantes utilizadas tienen el valor correcto y este mismo es valido.
POST: Verifica y devuelve el numero entero de cual es la huerta en que esta parado el jugador (si la 0, la 1 o la 2)
*/
int huerta_donde_esta_jugador(juego_t juego){
	int num_huerta = 0; 

	for(int i = 0; i < MAX_HUERTA; i++){

		for (int j = 0 ; j < MAX_PLANTAS; j++){

			if (juego.jugador.posicion.fila == juego.huertas[i].cultivos[j].posicion.fila && juego.jugador.posicion.columna == juego.huertas[i].cultivos[j].posicion.columna){
				
				num_huerta = i;

			}
		}
	}
	return num_huerta;
}


/*
PRE: El struct juego esta inicializado.
POST: Madura todas las verduras de una huerta al usar un fertilizante sobre la misma.
*/
void madurar_verduras(juego_t* juego, int num_huerta, int num_cultivo){

	if(juego->huertas[num_huerta].cultivos[num_cultivo].tipo == TOMATE){

		juego->huertas[num_huerta].cultivos[num_cultivo].movimiento_plantado = juego->movimientos - MADURACION_TOMATE;
	
	}
	else if(juego->huertas[num_huerta].cultivos[num_cultivo].tipo == ZANAHORIA){

		juego->huertas[num_huerta].cultivos[num_cultivo].movimiento_plantado = juego->movimientos - MADURACION_ZANAHORIA;
	}
	else if(juego->huertas[num_huerta].cultivos[num_cultivo].tipo == BROCOLI){

		juego->huertas[num_huerta].cultivos[num_cultivo].movimiento_plantado = juego->movimientos - MADURACION_BROCOLI;
	}
	else if(juego->huertas[num_huerta].cultivos[num_cultivo].tipo == LECHUGA){

		juego->huertas[num_huerta].cultivos[num_cultivo].movimiento_plantado = juego->movimientos - MADURACION_LECHUGA;
	}
}


/*
PRE: El struct juego tiene los valores correctos y validos.
Las constantes definidas anteriormente en el .h de las funciones booleanas tienen el valor correcto y valido.
La funcion "huerta_donde_esta_jugador" funciona correctamente y devuelve el entero debido.
POST:Si el jugador tiene un fertilizante y presiona F, no imnporta donde este, el fertilzante se gasta. Y si lo usa donde hay culñtivos plantados, estos llegan insantaneamente a su etapa madura.
*/
void usar_fertilizante(juego_t* juego, char accion){
	int num_huerta = huerta_donde_esta_jugador(*juego);

	if(juego->jugador.tiene_fertilizante == true){
	
		for(int j = 0; j< MAX_PLANTAS; j++){
					
			madurar_verduras(juego, num_huerta, j);	
		}

		juego->jugador.tiene_fertilizante = false;
	}	

}



/*
PRE: El struct juego tiene los valores correctos y validos.
Todas las constantes llegan con el valor valido y el correspondiendte a su defincion.
las funciones llamadas funcionan correctamente y devuelven el valor correcto y valido.
POST:  Si la plaga se activa al caer sobre alguna huerta, el jugador no podra cosechar ni plantar en la misma. Solo puede usar el insecticida para matar la plaga y asi desaparece.
Cambia el valor del bool del struct juego si esta plagado.
*/
void activar_plagas(juego_t* juego){
	
	int ubicacion_plaga = posicion_vector_plaga(*juego);

	for(int i = 0; i < MAX_HUERTA; i++){

		for(int j = 0; j < MAX_PLANTAS; j++){

			if(cae_plaga_sobre_huerta(*juego, i, j, ubicacion_plaga)){

				juego->huertas[i].plagado = true;
				juego->huertas[i].movimientos_plagado = juego->movimientos; 	
			}
			if(se_pudre_plaga(*juego, i)){
			
				for(int k = 0; k < MAX_PLANTAS; k++){
						
					juego->huertas[i].cultivos[k].ocupado = false;
					juego->huertas[i].cultivos[k].tipo = CULTIVO;
				}
				juego->huertas[i].plagado = false;
				juego->huertas[i].movimientos_plagado = 0;
			}
		}
	}
}


/*
PRE:  El struct juego tiene los valores correctos y validos.
Recibe la accion correctamente con un dato valido.
Todas las funciones y o procedi9mientos llamados funcionan correctamente y devuelven el valor correcto.
POST: Al usar el insecticida elimina la plaga del vector de objetos y le resta un insecticida al jugador (tiene solo 3).
*/
void usar_insecticida(juego_t* juego, char accion){

	int ubicacion_plaga = posicion_vector_plaga(*juego);
	int num_huerta = huerta_donde_esta_jugador(*juego);
	
	if(juego->huertas[num_huerta].plagado == true && hay_plaga_en_el_vector(*juego) == true){

		for(int j = ubicacion_plaga; j < juego->tope_objetos - 1; j++){

			juego->objetos[j] = juego->objetos[j+1]; 
		}	
		
		juego->huertas[num_huerta].plagado = false;
		juego->tope_objetos--;
	}

	juego->jugador.cant_insecticidas--;
}


/*
PRE: El struct juego tiene los valores correctos y validos.
Las constantes tienen el valor correcto y este mismo es valido.
POST: Cuando se pasa de la vida de la verdura, Este se pudre.
Desaparece del mapa y vuelve a su estado normal como cultivo sin plantacion.
*/
void se_pudre_tomate(juego_t* juego){

	for(int i = 0; i < MAX_HUERTA; i++){
		for (int j = 0; j < MAX_PLANTAS; j++){

	int movimientos_plantado = juego->movimientos - juego->huertas[i].cultivos[j].movimiento_plantado;

			if(movimientos_plantado >= VIDA_TOMATE && juego->huertas[i].cultivos[j].tipo == TOMATE){
				juego->huertas[i].cultivos[j].tipo = CULTIVO;
				juego->huertas[i].cultivos[j].ocupado=false;
				
			}
		}
	}
}


/*
PRE: El struct juego tiene los valores correctos y validos.
Las constantes tienen el valor correcto y este mismo es valido.
POST: Cuando se pasa de la vida de la verdura, Este se pudre.
Desaparece del mapa y vuelve a su estado normal como cultivo sin plantacion.
*/
void se_pudre_zanahoria(juego_t* juego){

	for(int i = 0; i < MAX_HUERTA; i++){

		for (int j = 0; j < MAX_PLANTAS; j++){

			int movimientos_plantado = juego->movimientos - juego->huertas[i].cultivos[j].movimiento_plantado;

			if(movimientos_plantado >= VIDA_ZANAHORIA && juego->huertas[i].cultivos[j].tipo == ZANAHORIA){
				juego->huertas[i].cultivos[j].tipo = CULTIVO;
				juego->huertas[i].cultivos[j].ocupado=false;
				
			}
		}
	}
}


/*
PRE: El struct juego tiene los valores correctos y validos.
Las constantes tienen el valor correcto y este mismo es valido.
POST: Cuando se pasa de la vida de la verdura, Este se pudre.
Desaparece del mapa y vuelve a su estado normal como cultivo sin plantacion.
*/
void se_pudre_brocoli(juego_t* juego){

for(int i = 0; i < MAX_HUERTA; i++){

		for (int j = 0; j < MAX_PLANTAS; j++){

			int movimientos_plantado = juego->movimientos - juego->huertas[i].cultivos[j].movimiento_plantado;

			if(movimientos_plantado >= VIDA_BROCOLI && juego->huertas[i].cultivos[j].tipo == BROCOLI){
				juego->huertas[i].cultivos[j].tipo = CULTIVO;
				juego->huertas[i].cultivos[j].ocupado=false;
				
			}
		}
	}
}


/*
PRE: El struct juego tiene los valores correctos y validos.
Las constantes tienen el valor correcto y este mismo es valido.
POST: Cuando se pasa de la vida de la verdura, Este se pudre.
Desaparece del mapa y vuelve a su estado normal como cultivo sin plantacion.
*/
void se_pudre_lechuga(juego_t* juego){

	for(int i = 0; i < MAX_HUERTA; i++){

		for (int j = 0; j < MAX_PLANTAS; j++){

			int movimientos_plantado = juego->movimientos - juego->huertas[i].cultivos[j].movimiento_plantado;

			if(movimientos_plantado >= VIDA_LECHUGA && juego->huertas[i].cultivos[j].tipo == LECHUGA){
				juego->huertas[i].cultivos[j].tipo = CULTIVO;
				juego->huertas[i].cultivos[j].ocupado=false;
				
			}
		}
	}
}


/*
PRE:El struct juego tiene los valores correctos y validos.
POST: Llama los procedimientos modificando asi el struct juego.
*/
void pudrir_verduras (juego_t* juego){

	se_pudre_tomate(juego);
	se_pudre_zanahoria(juego);
	se_pudre_brocoli(juego);		
	se_pudre_lechuga(juego);
}


void realizar_jugada(juego_t* juego, char accion){
	
	mover_blancanieves(juego, accion);
	activar_plagas(juego);
	cae_blancanieves_en_espina(juego);
	agarrar_fertilizante(juego);
	plantar(juego, accion);
	pudrir_verduras(juego);
	cosechar(juego, accion);
	vender_productos(juego);
	if(condiciones_usar_fertilizante(juego, accion)){			
		usar_fertilizante(juego, accion);	
	}		
	if(juego->jugador.cant_insecticidas > 0 && accion == INSECTICIDA){

		usar_insecticida(juego, accion);
	}	
}


void imprimir_terreno(juego_t juego){

	char terreno[FILAS + 1][COLUMNAS + 1];

	int ubicacion_plaga = posicion_vector_plaga(juego);

	inicializar_terreno_vacio(juego, terreno);

	mostrar_huertas_en_terreno(juego, terreno);
	
	mostrar_espinas_en_terreno(juego, terreno);
			
	mostrar_fertilizantes_en_terreno(juego, terreno);

	mostrar_deposito_en_terreno(juego, terreno);

	mostrar_blancanieves_en_terreno(juego, terreno);

	mostrar_plaga_en_terreno(juego, terreno, ubicacion_plaga);
	
	imprimir_juego(juego, terreno);
}