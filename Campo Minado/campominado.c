#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
*   Aloca espaço para uma matriz de acordo com os parâmetros  
*------------------------------------------------------------------------*/
int** geraMatriz (int m, int n) {
    int** matriz = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    return matriz;
}

/*------------------------------------------------------------------------
*   Libera o espaço alocado para a matriz  
*------------------------------------------------------------------------*/
void liberaMatriz(int m, int** matriz) {
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/*------------------------------------------------------------------------
*   Exibe a matriz com os valores como char 
*------------------------------------------------------------------------*/
void printaMatriz(int m, int n, int **matriz) {
    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*------------------------------------------------------------------------
*   Percorre os elementos da matriz atribuindo 42 às minas e 0 aos demais 
*------------------------------------------------------------------------*/
void binarizaMatriz(int m, int n, int** matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (matriz[i][j] == 42) ?  42 : 0;
        }
    }
} 

/*------------------------------------------------------------------------
*   Percorre a matriz incrementando os 8 valores adjacentes das minas  
*------------------------------------------------------------------------*/
void adjacencia(int m, int n, int** matriz) {
    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if(matriz[i][j] == 42) {
                matriz[i][j-1] = (matriz[i][j-1] == 42) ? 42 : matriz[i][j-1] + 1;
                matriz[i-1][j-1] = (matriz[i-1][j-1] == 42) ? 42 : matriz[i-1][j-1] + 1;
                matriz[i-1][j] = (matriz[i-1][j] == 42) ? 42 : matriz[i-1][j]++;
                matriz[i-1][j+1] = (matriz[i-1][j+1] == 42) ? 42 : matriz[i-1][j+1] + 1;
                matriz[i][j+1] = (matriz[i][j+1] == 42) ? 42 : matriz[i][j+1] + 1;
                matriz[i+1][j+1] = (matriz[i+1][j+1] == 42) ? 42 : matriz[i+1][j+1] + 1;
                matriz[i+1][j] = (matriz[i+1][j] == 42) ? 42 : matriz[i+1][j] + 1;
                matriz[i+1][j-1] = (matriz[i+1][j-1] == 42) ? 42 : matriz[i+1][j-1] + 1;
            }
        }  
    }
}

/*------------------------------------------------------------------------
*   Converte os valores, que não são minas, de int para char  
*------------------------------------------------------------------------*/
void ajustaMatriz(int m, int n, int** matriz) {
    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (matriz[i][j] != 42) {
                matriz[i][j] = matriz[i][j] + '0';
            }
        }
    }
} 

int main () {
    int p, q, game = 1;
    char campo;

    while (scanf ("%d %d", &p, &q) != EOF) {
        // Criando um padding para não acessar espaço fora da memória
        p += 2;
        q +=2;

        int** matriz = geraMatriz(p, q);

        for (int i = 1; i < p-1; i++) {
            for (int j = 1; j < q-1; j++) {
                scanf(" %c", &campo);
                matriz[i][j] = campo;
            }
        }

        binarizaMatriz(p, q, matriz);
        adjacencia(p, q, matriz);
        ajustaMatriz(p, q, matriz);
        if (p-2 > 0 && q-2 > 0) {
            printf("Campo #%d:\n", game);
            printaMatriz(p, q, matriz);
        }

        liberaMatriz(p, matriz);
        game++;
   }
}