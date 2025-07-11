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

- Cada vez que el usuario ingrese un valor el sistema debe indicarle si es mayor o menor que el número mágico.
- Debe contabilizar el número de intentos.
- En caso de que sea adivinado se le notificara que lo adivinó después de N intentos. 
- También debe considerar la postura de no continuar (se revela el número mágico).
- Se notificará “Reto no alcanzado” si el usuario se rinde.
- El programa debe terminar solo hasta que el usuario lo desee en caso contrario continuar generando números mágicos.
- Indicar hora de entrada.
- Indicar hora de salida.
- Contabilizar el tiempo de permanencia en el sistema.

## Datos de entrada

- Número entero del usuario
- Respuesta (Numérica o alfabética) para reintento
- Respuesta (numérica o alfabética) para rendirse

## Datos generados

- Número aleatorio (se usara la funcion `srand()` de la libreria `<stdlib.h>`)

## Diagrama de flujos (no aún)
```bash

  Program Inits
	|
	v
  Menú de inicio
	|
	v
      Play?
	|
	v					       
    n <-----> y -----> make random number ----> (scanf) input ----> input > magic number? ----> n ----> input < magic_number ----> input = magic_number?
    | 	      	       	      ^	   	  	       ^      	    	    	|    	  	  	        |	     	   	 |
    |			      |			       |			v		   	        v			 v 
    |	    		      |			       |			y		       	        y			 y
    |			      |			       |			|				|			 |
    |			      |			       |		input is greater		  input is minor	      You Win!
    |			      |			       |			|				|  		     Try Again? ----> n
    |			      |			       |		    	|    				|		         |	      |
    |			      |			       |------------------------|-------------------------------|			 y	      |
    |	                      |----------------------------------------------------------------------------------------------------------|	      |
    |----> Program ends <-----------------------------------------------------------------------------------------------------------------------------|
    
```
No vuelvo a hacer diagramas de flujo en txt