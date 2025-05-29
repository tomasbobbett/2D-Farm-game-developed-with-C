# 2D-Farm-game-developed-with-C
This is a university project where i had to develop a simple 2D game for the CMD. To run and test the game read the PDF and download the game folder. Then follow the instructions in the README text file :)

<h2>INSTRUCTIONS</h2>
To run the game you should first compile the c files.<br>
  1. First open the CMD inside the "game" folder.<br>
  2. Enter the following command "gcc *.c -o juego -std=c99 -Wall -Wconversion -Werror -lm" to compile the required files.<br>
Now you are ready to play! just enter the line "./juego"<br>

<h2>GAME INFO</h2>
<p>Desde que llegó Blancanieves a vivir con los enanitos, les contagió el amor por cuidar las plantas y pasar tiempo
al aire libre. Y como ya no les alcanza el trabajo en la mina y les está costando llegar a fin de mes, decidieron invertir
en comprar unos lotes de campo para ponerse a cosechar verduras, para luego venderlas y así poder ahorrar unas
monedas.</p><br>
Debemos ayudar a Blancanieves a cultivar su huerta para llegar a su objetivo
de ahorro, que es juntar 1000 monedas. Si Blancanieves se queda sin monedas, pierde el juego.
El juego consiste en un terreno donde se tendrán 3 huertas de 3x3 con distintas verduras, donde se deben plantar
semillas, luego cosecharlas una vez que crecieron, y llevarlas al depósito para venderlas y así ganar monedas.
Plantar cada tipo de verdura cuesta un monto distinto, así como cada verdura tiene un precio distinto al venderla.
Se deberá esperar a que estén disponibles para cosechar para poder hacerlo.<br>

<h3>Huertas</h3>
Se tendrán 3 huertas de tamaño 3x3 (9 cultivos). Se podrá sembrar cualquier verdura en sus cultivos. Se deberá
posicionar de manera aleatoria en el terreno el cultivo del medio y a partir de ese cultivo, se generarán los de alrededor.
Si un cultivo excede límites del terreno, no deberá inicializarse.<br>

<h3>Obstaculos</h3>
Los obstáculos deben posicionarse aleatoriamente en el terreno. Cabe destacar que no puede posicionarse un
obstáculo en la misma posición que otro objeto.<br>

<h3>Plagas</h3>
Aparecen aleatoriamente sobre una posición del terreno cada 10 movimientos. Si aparecen arriba de alguna de las
3 huertas, tendrás 10 movimientos para salvarlas, sino se pudrirán y desaparecerán.<br>

<h3>Espinas</h3>
Se posicionan 5 espinas aleatoriamente en el terreno al iniciar el juego, cada vez que Blancanieves pasa por arriba
de una pierde 5 monedas.<br>

<h3>Herramientas</h3>
Habrá herramientas para ayudar a Blancanieves con su misión:

  <h4>Fertilizante</h4>
Aparece un fertilizante cada 15 movimientos de forma aleatoria en el terreno. Cabe aclarar que no puede estar
ubicado arriba de otro objeto o del personaje. Al activarlo sobre un cultivo de una huerta, hace que crezcan todas
las verduras de esa huerta. Se agarran de a uno.<br>

  <h4>Insecticidas</h4>
Al iniciar el juego, Blancanieves tiene 3 insecticidas disponibles para usar. Al activarse sobre un cultivo, curarán
toda esa huerta de la plaga.<br>

<h3>Depósito</h3>
Se debe inicializar en una posición aleatoria. No puede superponerse con ningún objeto. Blancanieves debe poner
ahí la cosecha para que le dé dinero. Una vez que está a distancia Manhattan 2 del depósito, se intercambian las
verduras que haya cosechado por monedas.<br>

<h3>Canasta</h3>
Para cosechar las verduras, Blancanieves deberá posicionarse sobre un cultivo donde la verdura esté lista para
cosechar y ésta se deberá agregar a la canasta de Blancanieves.
La canasta puede llevar como máximo 6 verduras. Al llevarlas al depósito, la canasta se vacía y se podrá volver
a cosechar más verduras.
Aclaración: Una vez cosechadas, las verduras no se pudren.<br>

<h3>Plantas</h3>
Todas las plantas tienen un precio a la hora de plantarse, y crecen después de una determinada cantidad de
movimientos. Si alguna no se cosecha a tiempo desaparece y el cultivo queda disponible para plantar una nueva
verdura:<br>

  <h4>Tomate</h4>
Sembrar semillas de tomates cuesta 5 monedas. Cada cosecha de tomate (cada cultivo) te da 30 monedas. Vive
durante 30 movimientos, pasados los 20 ya crece y se puede cosechar, pero pasados 10 movimientos después de los
primeros 20, se pudre. Es decir, si planto un tomate y camino 20 movimientos, el tomate ya está maduro y lo puedo
ir a buscar, a partir de este momento si tardo más de 10 movimientos ya no lo puedo cosechar y desaparece.<br>

  <h4>Zanahoria</h4>
Sembrar semillas de zanahoria cuesta 10 monedas. Cada cosecha de zanahoria (cada cultivo) te da 50 monedas.
Vive durante 25 movimientos, pasados los 15 ya crece y se puede cosechar, pero pasados 10 movimientos después de
los primeros 15, se pudre.<br>

  <h4>Brócoli</h4>
Sembrar semillas de Brócoli cuesta 15 monedas. Cada cosecha de Brócoli (cada cultivo) sale 70 monedas. Vive
durante 20 movimientos, pasados los 10 ya crece y se puede cosechar, pero pasados 15 movimientos después de los
primeros 10, se pudre.<br>

  <h4>Lechuga</h4>
Sembrar semillas de Lechuga cuesta 20 monedas. Cada cosecha de Lechuga (cada cultivo) sale 80 monedas. Vive
durante 15 movimientos, pasados los 10 ya crece y se puede cosechar, pero pasados 5 movimientos después de los
primeros 10, se pudre.<br>

<h2>Game Controls</h2>
El personaje se podrá mover en 4 direcciones:<br>
Arriba: <b>W</b><br>
Abajo: <b>S</b><br>
Derecha: <b>D</b><br>
Izquierda:<b>A</b><br>
El personaje <b>no</b> podrá salir del terreno, osea que si Blancanieves se encuentra en la primera fila y trata de moverse
para arriba no moverá y tampoco contará como movimiento.<br>

Para sembrar, <b>Blancanieves</b> debe estar sobre un cultivo de una huerta y se usará la letra Z para sembrar zanahoria,
T para sembrar tomate, L para sembrar lechuga, y B para sembrar brócoli.<br>

Para usar el <b>insecticida</b>, Blancanieves debe estar sobre un cultivo de una huerta atacada por una plaga y se
usará la letra I para activarlo sobre toda la huerta.<br>

Para usar el <b>fertilizante</b>, Blancanieves debe estar sobre un cultivo de una huerta y se usará la letra F para
activarlo sobre toda la huerta.<br>

Para cosechar lo sembrado, se podrá hacer posicionándose sobre los cultivos cuando crezcan las plantas y cuando
no haya pasado el tiempo límite para hacerlo. Si se posiciona sobre un cultivo que aún no está listo, no debe suceder
nada. No se podrán cosechar verduras que tengan plaga.<br>

<h2>Game Goal</h2>
Para ganar el juego, Blancanieves tiene que ganar un total de 1000 monedas. La cantidad de monedas inicial
dependerá del enanito resultante del TP1:<br>
   Gruñón: 150 monedas<br>
   Dormilón: 200 monedas<br>
   Sabio: 250 monedas<br>
   Feliz: 300 monedas<br>

<h2>Characters Letters</h2>
<ul>
  <li>Blancanieves: S.</li>
  <li>Cultivo vacío: C.</li>
  <li>Depósito: D.</li>
  <li>Espinas: E.</li>
  <li>Plagas: P.</li>
  <li>Fertilizantes: F</li>
  <li>Lechuga: L.</li>
  <li>Tomate: T.</li>
  <li>Zanahoria: Z.</li>
  <li>Brócoli: B.</li>
</ul>

<h2>Hope you like it! made by Tomás Bobbett in 2023</h2>
