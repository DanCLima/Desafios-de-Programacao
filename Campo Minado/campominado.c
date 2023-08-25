#include <stdio.h>
#include <stdlib.h>

int** geraMatriz (int m, int n) {
    int** matriz = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    return matriz;
}

void liberaMatriz(int m, int** matriz) {
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void printaMatriz(int m, int n, int **matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void binarizaMatriz(int m, int n, int** matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (matriz[i][j] == 42) ?  1 : 0;
        }
    }
}

void adjacencia(int m, int n, int** matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(matriz[i][j] == 1) {

                if (i == 0) {
                    if (j == 0 && n != 0) {
                        matriz[i][j+1]++;
                        matriz[i+1][j]++;
                        matriz[i+1][j+1]++;
                    } else if (j == 0 && n == 0) {
                        matriz[i+1][j]++;
                    } else if (j == n) {
                        matriz[i][j-1]++;
                        matriz[i+1][j-1]++;
                        matriz[i+1][j]++;
                    } else {
                        matriz[i][j-1]++;
                        matriz[i+1][j-1]++;
                        matriz[i+1][j]++;
                        matriz[i+1][j+1]++;
                        matriz[i][j+1]++;
                    }
                }  

            }
        }  
    }
}

int main () {
    int p, q;
    char campo;

    while (scanf ("%d %d", &p, &q) != EOF) {
        int** matriz = geraMatriz(p, q);

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                scanf(" %c", &campo);
                matriz[i][j] = campo;
            }
        }
        binarizaMatriz(p, q, matriz);
        printaMatriz(p, q, matriz);

        adjacencia(p, q, matriz);
        printf("\n");
        printaMatriz(p, q, matriz);

        

        liberaMatriz(p, matriz);
        printf("\n");
   }
}