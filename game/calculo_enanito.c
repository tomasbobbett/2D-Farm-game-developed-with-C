#include <stdio.h>
#include "calculo_enanito.h"
#include <stdbool.h>

#define LECHUGA 'A'
#define BROCOLI 'B'
#define ZANAHORIA 'C'
#define TOMATE 'D'
#define VERANO 'V'
#define INVIERNO 'I'
#define GRUÑÓN 'G'
#define DORMILON 'D'
#define SABIO 'S'
#define FELIZ 'F'

#define MAX_PUNTAJE 5
#define MIN_PUNTAJE 0
#define MAX_TIEMPO 120
#define MIN_TIEMPO 40
#define VALOR_LECHUGA 0
#define VALOR_BROCOLI 5
#define VALOR_ZANAHORIA 10
#define VALOR_TOMATE 15 
#define VALOR_VERANO 10

/*
PRE => ---

POST => Se encarga de decidir si el dato ingresado por el usuario esta dentro de los pedidos.
 		Devolviendo TRUE si el dato ingresado no esta dentro de los dados. 
 		Devolviendo FALSE si el dato ingresado esta dentro de los pedidos.
*/

bool verdura_no_valida(char verdura_preferida){

	if((verdura_preferida != LECHUGA) && (verdura_preferida != TOMATE) && (verdura_preferida != ZANAHORIA) && (verdura_preferida != BROCOLI) ){
		
		return true;
	}

return false;
}

/*
PRE => Recibe la variable "estacion_preferida" valida ya inicializada.

POST => Se encarga de decidir si la estacion preferida selecta por el usuario esta entre las opciones a elegir (VERANO o INVIERNO).
		Devuelve TRUE si el usuario ingresa alguna letra no valida.
		Devuelve FALSE si el usuario elige bien alguna de las dos opciones.
*/
bool estacion_no_valida(char estacion_preferida){
	if(estacion_preferida != VERANO && estacion_preferida != INVIERNO ){
		return true;
	}
return false;
}

/*
PRE =>  Recibe la variable "nivel_enojo_mosquito" y "nivel_enojo_trabajar_bajo_lluvia" valida ya inicializada.

POST => Esta funcion booleana esta encargada de decidir si el dato que ingreso el usuario esta dentro del rango pedido (< a 5 y > a 0).
		Devuelve TRUE si lo que ingresa el usuario no esta dentro del rango.
		Devuelve FALSE si lo que ingrea el usuario esta bien.
		En este caso verifica el nivel de enojo de dos cosas distintas ("nivel_enojo_mosquito" y "nivel_enojo_trabajar_bajo_lluvia").
*/
bool nivel_enojo_no_valido(int nivel_enojo_mosquito, int nivel_enojo_trabajar_bajo_lluvia){

	if(nivel_enojo_mosquito > MAX_PUNTAJE || nivel_enojo_mosquito < MIN_PUNTAJE){
		return true;
	}
	else if(nivel_enojo_trabajar_bajo_lluvia > MAX_PUNTAJE || nivel_enojo_trabajar_bajo_lluvia < MIN_PUNTAJE){
		return true;
	}
return false;
}

/*
PRE => Recibe la variable "tiempo_cosecha" valida ya inicializada.
POST => Esta encargada de decidir si el tiempo para cosechar ingresado por el usuario esta dentro del rango permitidio (< a 120 y > a 20).
		Devuelve TRUE si el tiempo ingresado por el usuario no esta dentro del rango.
		Devuelve FALSE si el tiempo ingresado por el usuario cumple los requisitos.
*/
bool tiempo_no_valido(float tiempo_cosecha){
	if (tiempo_cosecha > MAX_TIEMPO || tiempo_cosecha < MIN_TIEMPO){
		return true;
	}
return false;
}


/*
PRE => Recibe la variable "puntaje_acumulado" valida ya inicializada.
POST => Imprime textos pidiendo al usuario responder la pregunta . Puede elegir entre 4 opciones de verdura (Lechuga, brocoli, zanahoria y tomate).
		Devuelve un valor numerico dependiendo de la verdura elegida (lechuga = 0; Brocoli = 5; Zanahoria = 10; Tomate = 15). 
		Este puntaje se va sumando en la variable "puntaje_acumulado" llamado por referencia.
*/
void preguntar_verdura_favorita(int* puntaje_acumulado){

	char verdura_preferida;
	printf("\nPrimera pregunta, ¿Que verdura preferis?\n(A)Lechuga\n(B)Brocoli\n(C)Zanahoria\n(D)Tomate\n");
	scanf(" %c", &verdura_preferida);

	while(verdura_no_valida(verdura_preferida)){

		printf("Esa no es una opcion valida, tenes que ingresar alguna de estas y en MAYUSCULAS:\n\nLechuga(A), Brocoli(B), Zanahoria(C) o Tomate(D)\n");
		scanf(" %c", &verdura_preferida);
	}

	if(verdura_preferida == LECHUGA){

		*puntaje_acumulado = VALOR_LECHUGA;
	}
		else if(verdura_preferida == BROCOLI){

			*puntaje_acumulado+= VALOR_BROCOLI;
		}
		else if (verdura_preferida == ZANAHORIA){

			*puntaje_acumulado+= VALOR_ZANAHORIA;
		}
		else{

			*puntaje_acumulado += VALOR_TOMATE;
		}
	
}

/*
PRE => Recibe la variable "puntaje_acumulado" valida ya inicializada.

POST => Se le pregunta al usuario que elija su estacion preferida entre Invierno y Verano. 
Si elige verano, se le suman 10 puntos a la variable "puntaje_acumulado".
Al elegir verano la proxima pregunta es que tanto le molestan los moquitos. Y dependiendo el valor (entre 0 y 5), se le restara ese numero a la variable "puntaje_acumulado".
Si elige invierno la dinamica es la misma solo que la pregunta es distinta.
*/
void preguntar_team_estacion(int* puntaje_acumulado){
	int nivel_enojo_mosquito = 0;
	int nivel_enojo_trabajar_bajo_lluvia = 0;
	char estacion_preferida = INVIERNO;

	printf("Buenisimo, la otra pregunta es controversial. ¿Team invierno (ingrese I) o team verano (ingrese V)?\n");
	scanf(" %c", &estacion_preferida);

	while(estacion_no_valida(estacion_preferida)){

			printf("Esa no es una opcion valida, tenes que ingresar alguna de estas y en MAYUSCULAS:\n\nInvierno(I) o Verano(V)\n");
			scanf(" %c", &estacion_preferida);
	}

	if(estacion_preferida == VERANO){

			*puntaje_acumulado += VALOR_VERANO;

			printf("banco el verano tambien pero del 0 al 5, ¿cuanto te enojan los mosquitos?\n");
			scanf(" %i", &nivel_enojo_mosquito);

			while(nivel_enojo_no_valido(nivel_enojo_mosquito, nivel_enojo_trabajar_bajo_lluvia)){
				printf("Del 0 al 5 podes elegir nomas capo.\n");
				scanf(" %i", &nivel_enojo_mosquito);
			}

			*puntaje_acumulado -= nivel_enojo_mosquito;
	}
	

	else if(estacion_preferida == INVIERNO){

			printf("Banco el invierno tambien pero del 0 al 5, ¿cuanto te enoja trabajar bajo la lluvia?\n");
			scanf(" %i", &nivel_enojo_trabajar_bajo_lluvia);

			while(nivel_enojo_no_valido(nivel_enojo_mosquito, nivel_enojo_trabajar_bajo_lluvia)){
				printf("Del 0 al 5 podes elegir nomas capo.\n");
				scanf(" %i", &nivel_enojo_trabajar_bajo_lluvia);
			}

			*puntaje_acumulado -= nivel_enojo_trabajar_bajo_lluvia;
	}

}

/*
PRE => 	Recibe la variable "puntaje_acumulado" valida ya inicializada.
POST => Pregunta al usuario cuanto tiempo tarda en cosechar un cultivo.
		La respuesta del usuario se la divide por 8 y ese resultado es lo que se le suma a la variable "puntaje_acumulado".
*/
void preguntar_tiempo_cosecha(int* puntaje_acumulado){
	
	float tiempo_cosecha = 0;

	printf("Vas muy bien, lo ultimo que necesito saber es:\n\n¿Cuantos minutos tardarias en cosechar un cultivo de 10 metros cuadrados?\n");
	printf("Podes responder entre 40 y 120 minutos inclusive.\nY podes especificar los segundos si es necesario. Por ejemplo 55 minutos y 30 segundos se escribe 55.5.Ya que 0.5 seria la mitad de un minuto)\n");
	scanf(" %f", &tiempo_cosecha);

	while(tiempo_no_valido(tiempo_cosecha)){

		printf("Es imposible ese tiempo, entre 40 y 120 minutos podes ingresar. Si tu tiempo no entra entre esos dos no sos enanito directamente.\n");
		scanf(" %f", &tiempo_cosecha);
	}

*puntaje_acumulado += (int) tiempo_cosecha/8;
}

/*
PRE => Recibe la variable "puntaje_acumulado" valida ya inicializada y no nula (con el valor correspondiente).

POST =>	Recibe el puntaje acumulado luego de obtener todas las respuestas del formulario. 
		Para luego decidir (dependiendo del numero) la inicial de la personalidad adecuada y guardarla en la variable pasada por referencia "inicial_enanito".
		Siendo GRUÑÓN cuando el puntaje_acumulado sea menor que 10
		DORMILON cuando este entre 10 y 19 inclusive.
		SABIO entre 20 y 29 inclusive 
		Y por ultimo FELIZ si esta arriba de 30 inclusive.
*/
char eleccion_tipo_enanito(int puntaje_acumulado, char* inicial_enanito){

	if(puntaje_acumulado < 10){
		*inicial_enanito = GRUÑÓN;
	}
	else if(puntaje_acumulado >= 10 && puntaje_acumulado < 20){
		*inicial_enanito = DORMILON;
	}
	else if(puntaje_acumulado >= 20 && puntaje_acumulado < 30 ){
		*inicial_enanito = SABIO;
	}
	else{
		*inicial_enanito = FELIZ;
	}

return *inicial_enanito;


}

void calcular_enanito(char* inicial_enanito){

	int puntaje_acumulado = 0;
	
	preguntar_verdura_favorita( &puntaje_acumulado);
	preguntar_team_estacion(&puntaje_acumulado);
	preguntar_tiempo_cosecha(&puntaje_acumulado);
	eleccion_tipo_enanito(puntaje_acumulado, inicial_enanito);
	

}