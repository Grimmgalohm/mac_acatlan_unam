# Tercer ejercicio

Programar en lenguaje C una aplicación denominada “Adivina el número
mágico”, que consiste en generar un número pseudoaleatorio entre 0 y 100, no visible para
el usuario, referido como “número mágico”. El usuario tendrá que adivinarlo, cada vez que el
usuario ingrese un valor, el sistema debe indicarle si es mayor o menor que el número
mágico, debe contabilizar el número de intentos, en caso de que sea adivinado se le
notificara lo adivinó después de N intentos. También debe considerar la postura de no
continuar y que sea revelado el número mágico, en este último caso se le notificará “Reto no
alcanzado”. El programa debe terminar solo hasta que el usuario lo desee en caso contrario
continuar generando números mágicos. Indicar hora de entrada, hora de salida, contabilizar
el tiempo de permanencia en el sistema, utilizar funciones.

## Requisitos

- El usuario tendrá que adivinarlo, cada vez que el usuario ingrese un valor
- El sistema debe indicarle si es mayor o menor que el número mágico.
- Debe contabilizar el número de intentos
- En caso de que sea adivinado se le notificara lo adivinó después de N intentos. 
- También debe considerar la postura de no continuar y que sea revelado el número mágico, en este último caso se le notificará “Reto no alcanzado”. 
- El programa debe terminar solo hasta que el usuario lo desee en caso contrario continuar generando números mágicos. 
- Indicar hora de entrada, hora de salida, contabilizar el tiempo de permanencia en el sistema, utilizar funciones.

## Datos

- Un numero random. Usaremos ``rand()`` de la libreria ``stdlib``