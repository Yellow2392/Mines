# Mines
Buscaminas
Proyecto de Programación 3

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
