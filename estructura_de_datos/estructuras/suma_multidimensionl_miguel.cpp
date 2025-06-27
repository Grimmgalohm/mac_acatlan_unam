//Suma Multidimensional
#include <stdio.h>

void primeraSuma(int *suma1, int x[2][4][3][5][2][5]) {
    for (int i = 0; i <= 2; i++) {
        *suma1 += i;
        x[i][0][0][0][0][0] = *suma1; // Almacenar suma1
    }
}

void segundaSuma(int suma1, int *suma2, int x[2][4][3][5][2][5]) {
    int sumaPar1 = 0;
    for (int j = 0; j <= 4; j++) {
        sumaPar1 += j;
        *suma2 = suma1 + sumaPar1;
        x[0][j][0][0][0][0] = *suma2; // Almacenar suma2
    }
}

void terceraSuma(int suma2, int *suma3, int x[2][4][3][5][2][5]) {
    int sumaPar2 = 0;
    for (int k = 0; k <= 3; k++) {
        sumaPar2 += k;
        *suma3 = suma2 + sumaPar2;
        x[0][0][k][0][0][0] = *suma3; // Almacenar suma3
    }
}

void cuartaSuma(int suma3, int *suma4, int x[2][4][3][5][2][5]) {
    int sumaPar3 = 0;
    for (int l = 0; l <= 5; l++) {
        sumaPar3 += l;
        *suma4 = suma3 + sumaPar3;
        x[0][0][0][l][0][0] = *suma4; // Almacenar suma4
    }
}

void quintaSuma(int suma4, int *suma5, int x[2][4][3][5][2][5]) {
    int sumaPar4 = 0;
    for (int m = 0; m <= 2; m++) {
        sumaPar4 += m;
        *suma5 = suma4 + sumaPar4;
        x[0][0][0][0][m][0] = *suma5; // Almacenar suma5
    }
}

void finalSuma(int suma5, int *sumaFinal, int x[2][4][3][5][2][5]) {
    int sumaPar5 = 0;
    for (int n = 0; n <= 5; n++) {
        sumaPar5 += n;
        *sumaFinal = suma5 + sumaPar5;
        x[0][0][0][0][0][n] = *sumaFinal; // Almacenar sumaFinal
    }
}

int main() {
    int x[2][4][3][5][2][5] = {0}; // Inicializar el arreglo a cero
    int suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0, suma5 = 0, sumaFinal = 0;

    primeraSuma(&suma1, x);
    segundaSuma(suma1, &suma2, x);
    terceraSuma(suma2, &suma3, x);
    cuartaSuma(suma3, &suma4, x);
    quintaSuma(suma4, &suma5, x);
    finalSuma(suma5, &sumaFinal, x);

    // Imprimir resultados finales
    printf("Suma1: %d\n", suma1);
    printf("Suma2: %d\n", suma2);
    printf("Suma3: %d\n", suma3);
    printf("Suma4: %d\n", suma4);
    printf("Suma5: %d\n", suma5);
    printf("SumaFinal: %d", sumaFinal);

    return 0;
}
