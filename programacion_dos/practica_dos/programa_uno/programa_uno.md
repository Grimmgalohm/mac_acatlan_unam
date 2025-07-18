# Programa A (o programa uno)

Generar una matriz triangular superior con números (pseudo) aleatorios entre  el 0 y el 99.

## Background

Una matriz triangular superior es una matriz cuadrada "que tiene todos los elementos nulos por debajo de la diagonal principal" ([Universo Formulas](https://www.universoformulas.com/matematicas/algebra/matriz-triangular-superior/#:~:text=Una%20matriz%20triangular%20superior%20es,(inicial%20del%20ingl%C3%A9s%20upper)., s.f.).
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
// De forma que si busco la posición 2,2 (note que no estoy hablando de una coordenada cartesiana) nos referimos a la fila 2, columna 2. De forma que el elemento que buscamos es el 4 (de la matriz A que muestro en la fig 2.3)
// Y emm... eso. Si aplicamos la regla de discriminación para la matriz triangular, la fila 3 (i) > columna 1 (j) por tanto es igual a 0.
```
## Plip!
plop!

## Referencias
Universo Formulas. (s.f.). Matriz triangular superior. Recuperado el 18 de julio de 2025, de https://www.universoformulas.com/matematicas/algebra/matriz-triangular-superior/