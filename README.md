# Mines
Buscaminas
Proyecto de Programación 3

## Objetivos:

- Desarrollar un juego completo de Buscaminas con la opción de seleccionar diferentes niveles.
- Implementar algoritmos de orden y búsqueda en arreglos.
-  Desarrollar una interfaz cómoda e intuitiva en consola.
-  Registrar los puntajes de los usuarios de acuerdo al tiempo de juego.

## Librerías y/o componentes que se requieran:
### Librería Estándar C++ :

En C++, la biblioteca estándar es una colección de clases y funciones, escritas en el núcleo del lenguaje. La biblioteca estándar proporciona varios contenedores genéricos, funciones para utilizar y manipular esos contenedores, funciones objeto, cadenas y flujos genéricos (incluyendo E/S interactiva y de archivos) y soporte para la mayoría de las características del lenguaje. 
 
## Resumen del juego 
Buscaminas es un videojuego de 1989 creado por Curt Johnson y Robert Donner. Este consiste de un tablero compuesto por casillas en las que el jugador deberá despejar todas las casillas, sin detonar las minas que están ocultas dentro de estas de manera aleatoria. Algunas de las casillas sin minas tienen un número, el cuál indica el número de minas que hay alrededor. Es decir, si se selecciona una casilla sin mina el cual muestra el número 1, esto quiere decir que hay una mina alrededor de esa casilla seleccionada.

También se pueden colocar banderas donde uno crea que se encuentren minas como una ayuda visual para descubrir las demás que estén cerca
## Resumen del programa

Nuestro programa consta de un menú principal con 6 opciones donde se tienen 3 para acceder a los niveles principales (Nivel 1, Nivel 2 y Nivel 3)
La cuarta opción permite mostrar un submenú con dos niveles adicionales (Nivel Cruz y Nivel Diamante) y un nivel personalizable por el mismo jugador donde puede elegir el número de filas, columnas y minas que contenga el tablero.
La quinta opción muestra los mejores puntajes obtenidos a partir de un archivo de texto movimientos.txt, mientras que la última opción permite salir del juego.
Dentro del juego, se crea un objeto de la clase del nivel de juego, la cuál hereda los atributos y métodos de una clase Tablero y los define. Dentro de esta clase, se hace uso de dos matrices, una en la que se tienen las casillas sin minas (representadas con ceros) y las que tienen minas (representadas con asterisco), y otra que se usa para imprimir a partir de lo que se indique en la otra matriz.
El jugador podrá seleccionar cualquier casilla dentro del tablero y también tendrá la opción de colocar alguna bandera. Si la casilla no tiene mina, el programa evaluará las posiciones que rodean a esa casilla (si son posiciones válidas o no) y asignará el número de minas que encuentre en las posiciones circundantes.
Si el jugador descubre todas las casillas sin mina (que se da en el caso en que la primera matriz ya no contenga ceros), gana la partida y se procederá a registrar su puntaje en movimientos.txt. Después, se registrará su nombre, el cuál sería preguntado antes de iniciar el juego, y su victoria dentro de otro archivo llamado scores.txt el cuál, si encuentra el nombre del jugador previamente, actualizará el contador de victorias de ese jugador.

## Resumen del programa
[VIDEO RESUMEN]

## Indicaciones
- Al momento de correr el programa, el jugador tendra 5 opciones a digitar en consola: Nivel1, Nivel2, Nivel3, Perzonalizados y Ver Puntajes.
- Dependiendo 
- Inicialmente el programa tendra el archivo de movimientos.txt con un solo 0, para que si por primera vez el jugador solicite ver los Puntajes, le imprimira en consola 5 numeros 0.
- De acuerdo al nivel que escoja el usuario, se imprimira un tablero con cada posición(fila, columna) marcada con un "#".
- El jugador primera tendrá que eligir si desea o no colocar un banderín en alguna posición. Si elige que sí tendra que digitar la fila y columna, y esta la casilla se pintara con el simbolo "P". Si elige que no colocar el banderin, tendrá que elegir la posición a desmarcar en el tablero.
- Al estilo del juego buscaminas, si la posición no contiene una mina, se desmarcarán las casillas alrededor. Si la casilla que se elige tiene una mina cerca, se desmarcará la casilla y se pintara con el número de minas a su alredor. Si la casilla contiene una mina, se imprimira la frase de "Perdiste".
- El juego finaliza en 2 posibles escenarios. El primero es cuando la casilla elegida por el jugador contiene una mina, y el segundo, cuando el numero de casillas restantes, es igual al número de minas, lo que significa que haz ganado.
- Una vez acaba el juego, el tiempo que haya durado la partida se registrará en el archivo "movimientos.txt", y podra consultarlo al correr nuevamente el programa y darle a la opción 5. 

## Code insights
<img src="/Imagenes/Diagrama.png" alt="Logo"/>
