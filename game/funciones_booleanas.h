#ifndef __FUNCIONES_BOOLEANAS_H__
#define __FUNCIONES_BOOLEANAS_H__

#define GANADO 1
#define PERDIDO -1
#define SIGUE_JUGANDO 0
#define MAX_VERDURAS 6
#define MADURACION_TOMATE 20
#define MADURACION_ZANAHORIA 15
#define MADURACION_BROCOLI 10
#define MADURACION_LECHUGA 10
#define INTERVALO_PARA_GENERAR_FERTILIZANTES 15
#define INTERVALO_PARA_GENERAR_PLAGAS 10
#define FILA_SUPERIOR_HUERTA -1
#define FILA_INFERIOR_HUERTA 1
#define COLUMNA_IZQUIERDA_HUERTA -1
#define COLUMNA_DERECHA_HUERTA 1
#define CULTIVOS_POR_FILA 3
#define FILA_BORDE_SUP 0
#define FILA_BORDE_INF 19
#define COLUMNA_BORDE_DERECHO 19
#define COLUMNA_BORDE_IZQUIERDO 0
#define POSICION_CULTIVO_CENTRAL 0
#define CANT_INSECTICIDAS_INICIAL 3
#define CANT_ESPINAS 5
#define	MONEDAS_FELIZ 300
#define	MONEDAS_SABIO 250
#define MONEDAS_DORMILON 200
#define MONEDAS_GRUÑÓN 150
#define MONEDAS_PARA_GANAR 1000
#define GANADO 1
#define PERDIDO -1
#define SIGUE_JUGANDO 0
#define VALOR_CAE_ESPINA 5
#define FILAS 20
#define COLUMNAS 20

#define VALOR_TOMATE 5
#define VALOR_ZANAHORIA 10
#define VALOR_BROCOLI 15
#define VALOR_LECHUGA 20
#define VALOR_VENTA_TOMATE 30
#define VALOR_VENTA_ZANAHORIA 50
#define VALOR_VENTA_BROCOLI 70
#define VALOR_VENTA_LECHUGA 80
#define MAX_VERDURAS_COSECHADAS 6
#define DISTANCIA_MANHATTAN_2 2
#define MOVIMIENTOS_MATA_LA_PLAGA 10
#define VIDA_TOMATE 30
#define VIDA_ZANAHORIA 25
#define VIDA_BROCOLI 20
#define VIDA_LECHUGA 15

#define BLANCANIEVES 'S'
#define GRUÑÓN 'G'
#define DORMILON 'D'
#define SABIO 'S'
#define FELIZ 'F'
#define CULTIVO  'C'
#define PLAGA  'P'
#define ESPINA  'E'
#define FERTILIZANTE  'F'
#define INSECTICIDA 'I'
#define ARRIBA  'W'
#define ABAJO  'S'
#define IZQUIERDA  'A'
#define DERECHA  'D'
#define DEPOSITO  'D'
#define TOMATE  'T'
#define ZANAHORIA  'Z'
#define BROCOLI  'B'
#define LECHUGA  'L'
/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST Devuelve TRUE si la plaga se pudre. De lo contrario devuelve false.
*/
bool se_pudre_plaga(juego_t juego, int numero_de_huerta);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si la accion ingresada por el usuairo es valida.
*/
bool accion_valida(char accion);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si cae una plaga sobre una huerta.
*/
bool cae_plaga_sobre_huerta(juego_t juego, int numero_de_huerta, int numero_de_cultivo, int ubicacion_plaga);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST:cheque si el jugador se para sobre un fertilizante.
*/
bool esta_jugador_sobre_fertilizante(juego_t juego, int posicion_fertilizante);

/*
PRE: Recibe la accion correcta y valida
POST: La funcion booleana devuelve true si es que se cumplen las conduciopnes para usar el fertilizante.
*/
bool condiciones_usar_fertilizante(juego_t* juego, char accion);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si el personaje esdta a distancia manhattan 2.
*/
bool esta_jugador_a_distancia_manhattan_2(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si estan las condiciones necesarias como para cosechar una verdura.
*/
bool condiciones_para_cosechar(juego_t juego, int numero_de_huerta, int numero_de_cultivo);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si el personaje esta parado sobre alguno de los tres cultivos.
*/
bool esta_jugador_en_cultivo(juego_t juego, int numero_de_huerta, int numero_de_cultivo);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si las condiciones son aptas como para plantar alguna verdura.
*/
bool condiciones_para_plantar(juego_t juego, int numero_de_huerta, int numero_de_cultivo);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si blancanieves pisa alguna de las 5 espinas que hay por el mapa.
*/
bool blancanieves_se_posiciona_en_espina(juego_t juego, int numero_de_espina);

/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si la huerta se choca con otra huerta.
*/
bool se_choca_con_huerta(juego_t juego, int i);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si una huerta se va fuera del terreno.
*/
bool huerta_fuera_de_terreno(juego_t juego, int fila, int columna, int *j, int i);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si la espina cae sobre una huerta.
*/
bool se_choca_espinas_huertas(juego_t juego, int i);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si la espina cae sobre otra espina
*/
bool se_choca_espinas_espinas(juego_t juego, int i);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si la espina se choca con algo en general.
*/
bool se_choca_espina(juego_t juego, int numero_plaga);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si el personaje cae en alguna huerta.
*/
bool se_choca_personaje_huerta(juego_t juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende de si el personaje cae sobre alguna espina
*/
bool se_choca_personaje_espinas(juego_t juego);

/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si el personaje se choca con alguna de posicion de cualquier cosa en general.
*/
bool se_choca_personaje(juego_t juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende del estado de di el deposito cae sobre alguna huerta.
*/
bool se_choca_deposito_huertas(juego_t juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende del estado de si el deposito cae sobne alguina espina.
*/
bool se_choca_deposito_espinas(juego_t juego);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas.
POST: Devuelve true o false depende del estado de si el deposito cae sobre el personaje (blancanieves).
*/
bool se_choca_deposito_blancanieves(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si la posicion del deposito se choca con algo en general.
*/
bool se_choca_deposito(juego_t juego);

/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea que al ubicar el fertlizante no caiga sobre el deposito.
*/
bool se_choca_fertilizante_deposito(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: chequea que al ubicar el fertlizante no caiga sobre el jugador.
*/
bool se_choca_fertilizante_blancanieves(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: hequea que al ubicar el fertlizante no caiga sobre algun objeto en general.
*/
bool se_choca_fertilizante_con_objeto(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: hequea que al ubicar el fertlizante no caiga sobre alguna de las tres huertas.
*/
bool se_choca_fertilizante_con_huerta(juego_t juego);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si la posicion del fertilizante se choca copn algo en general.
*/
bool se_choca_fertilizante(juego_t juego);

	
/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea q al ubicar la plaga no se pise con ningun objeto en gral.
*/
bool se_choca_plaga_objeto(juego_t juego, int posicion_plaga_en_vector);


/*
PRE: Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Devuelve true o false depende del estado de si alguna plaga cae sobre el personaje (blancanieves)
*/
bool se_choca_plaga_blancanieves(juego_t juego, int posicion_plaga_en_vector);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST:  Chequea q al ubicar la plaga no se pise con el deposito.
*/
bool se_choca_plaga_deposito(juego_t juego, int posicion_plaga_en_vector);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea que la posicion de la plaga no se pise con nada que este en el terreno.
*/
bool se_choca_plaga(juego_t juego, int posicion_vector_plaga);


/*
PRE:Recibe los datos correctos de la estructura juego
	 Recibe los datos de las bibliotecas incluidas en el codigo
	 Todas las constantes tienen los valores correctos asignados en el .h de las funciones booleanas
POST: Chequea si ya hay una plaga inicializada en el vector de objetos.
*/
bool hay_plaga_en_el_vector(juego_t juego);


#endif /*__FUNCIONES_BOOLEANAS_H__*/