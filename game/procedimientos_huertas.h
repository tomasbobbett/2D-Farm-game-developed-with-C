#ifndef __PROCEDIMIENTOS_HUERTAS_H__
#define __PROCEDIMIENTOS_HUERTAS_H__

/*
PRE: -
POST: Devuelve un numero aleatorio entre 0 y 19. 
*/
int generar_numero_aleatorio();


/*
//PRE:	El struct juego tiene informacion valida sobre las cosas a inicializar.
		El generador de numeros aleatorios debe estar funcionando correctamente dentro del os parametros dados.
		Las constantes tienen el dato correcto definido en l .h de las funcions booleanas.
//POST: Posiciona el cultivo cerntral de todas las tres huertas aleatoriamente.

*/
void generar_coordenadas_cultivo_inicial(juego_t* juego);


/*
//PRE:	El struct juego tiene informacion valida sobre las cosas a inicializar.
		Las constantes tienen el dato correcto definido en el .h de las funcions booleanas.
		La funcion huerta_fuera_de_terreno debe estar devolviendo valores validos y correctos. 
//POST: Ubica los cultivos alrededor de este cultivo central inicializado anteriormente.
*/
void generar_coordenadas_cultivos_al_rededor(juego_t* juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST:Inicializa que los culñtivos de las huertas no tienen nada plantado. Osea que no estan ocupados.
	 inicializa el tipo predeterminado de cutlvo que hay en cada huerta. Siendo este representado por una C de Cultivos. Osea que no hay nada plantado.
*/
void inicializar_tipo_huertas(juego_t* juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST:Inicializa la cantidad de movimientos que lleva plantado el cultivo de todas las huertas. Inicializando todas en 0 ya que al empezar el juego no hay nada plantado.
*/
void inicializar_movimientos_plantado(juego_t* juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Inicialza que ningun cultivo de ninguna huerta esta plagado y que porl o tanto los movimientos plagado es 0. Ya que al comenzar el juego no hay ninguna plaga
*/
void inicializar_plagado(juego_t* juego);



#endif /*__PROCEDIMIENTOS_HUERTAS_H__*/