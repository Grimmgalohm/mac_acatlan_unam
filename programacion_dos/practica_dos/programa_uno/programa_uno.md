# Programa A (o programa uno)

Generar una matriz triangular superior con números (pseudo) aleatorios entre  el 0 y el 99.

## Background

Una matriz triangular superior es una matriz cuadrada "que tiene todos los elementos nulos por debajo de la diagonal principal"(**Ojo con esta condición**) ([Universo Formulas](https://www.universoformulas.com/matematicas/algebra/matriz-triangular-superior/#:~:text=Una%20matriz%20triangular%20superior%20es,(inicial%20del%20ingl%C3%A9s%20upper)., s.f.).
Siendo más exactos, siendo "A" la matriz, y sus elementos a<sub>ij</sub>, entonces a<sub>ij</sub>=0 para todo i>j.

$$
A = \begin{bmatrix}
2 & 1 & 3 \\
0 & 4 & 5 \\
0 & 0 & 6
\end{bmatrix}
$$

## Previo
Para generar matrices de nxn (cuadradas) se usarán for anidados. En estructura de datos estos arreglos se llaman también tensores y puede haber de 3+ dimensiones. En este caso en específico, por características del requerimiento, usaremos arreglos cuadrados (nxn). Supongamos que tenemos un arreglo cualquiera:
```c
// fig 2
for(i; i<n; i++){
  printf("%d", arreglo[i]);
}
// Este for imprimirá los elementos de un arreglo unidimensional. Que visualmente podría verse así:
[1, 2, 3, 4, 5, ... , n]

// fig 2.1
for(i; i<n; i++){
  for(j; j<n; j++){
    printf("%d", col[j]);
  }
}
//Este es la forma que buscamos implementar. En este caso (a veces puede ser diferente) i (filas) y j (columnas) tienen el mismo "largo" (por ser una matriz nxn).
// El segundo for se encarga de imprimir los elementos por columna y el primer for de recorrer las filas. De suerte que podemos tener algo asi:
// fig 2.2
// | 1  1  1 |
// | 1  1  1 |
// | 1  1  1 |
```
Ahora, adicional a esto, buscamos imprimir una matriz triangular superior, por lo que tendremos que recurrir a la definción anterior `a<sub>ij</sub>=0 para todo i>j`. Por tanto, solo los elementos fila (i) si son mayores que la columna (j) en cuestión de el número de su posición (ahora lo aclaro) serán diferentes de 0. Es decir, los que vamos a rellenar con elementos aleatorios.
```
// Con posición, me refiero al numero de columna, fila, correspondiente ij de la matriz.
// fig 2.3
A = | 2  1  3 |
    | 0  4  5 |
    | 0  0  6 |
// De forma que si busco la posición 2,3 (note que no estoy hablando de una coordenada cartesiana) nos referimos a la fila 2, columna 4. De forma que el elemento que buscamos es el 5 (de la matriz A que muestro en la fig 2.3)
// Si revisamos la condición, la fila 2 (i) !> (j) la columna 3 por tanto, el espacio puede no ser nulo.
// De igual forma, la posición 3,1 (si la revisamos con la condición dada) 3>1 por tanto es 0.
// Pero ¿y la fila 2,2? o [1,1] o la [3,3] estríctamente hablando, 3 no es mayor que 3... es igual.
// Bueno, para eso, en la definición nos dicen que (recordando) "tiene todos los elementos nulos **por debajo de la diagonal principal**
// ¿Y cuál es la diagonal principal? Son "*los elementos de la matriz cuadrada que tienen el mismo número de fila que de columna forman la diagonal principal. [Cómo Calcular](https://comocalcular.online/propiedades-de-las-matrices/diagonal-principal-de-una-matriz/)* (s.f.)"

//Por tanto, para facilitar la programación podemos argumentar que se van a llenar todos los espacios ij con i>=j.
```
## Plip!
plop!

## Referencias
- Universo Formulas. (s.f.). Matriz triangular superior. Recuperado el 18 de julio de 2025, de https://www.universoformulas.com/matematicas/algebra/matriz-triangular-superior/
- Cómo Calcular. (s.f.). *Diagonal principal de una matriz*. Recuperado de https://comocalcular.online/propiedades-de-las-matrices/diagonal-principal-de-una-matriz/