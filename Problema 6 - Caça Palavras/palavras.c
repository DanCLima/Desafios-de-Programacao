/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 6                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   18/09/2023                               |
+----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  

/* Remove a quebra de linha da entrada e retorna o tamanho da string */
int removeQuebraLinha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

/* Recebe uma string e converte todos os caracteres para minúsculo */
char* palavraMinuscula (char *palavra) {
    int tam = strlen(palavra);

    for (int i = 0; i < tam; i++) {
        palavra[i] = tolower(palavra[i]);
    }
    return palavra;
}

int main(int argc, char const *argv[])
{
    int entrada;
    scanf("%d", &entrada);
    getchar();  

    while(entrada > 0) {
        int m, n, cont, qtdPalavras;
        char buffer[100];

        scanf("%d %d", &m, &n);
        getchar();
        
        char tabuleiro[m+2][n+2];       // Criando um padding para a matriz para evitar acessar endereço de memória errado

        /* Iniciando o tabuleiro */
        for (int i = 0; i < m+2; i++) {
            for (int j = 0; j < n+2; j++) {
                tabuleiro[i][j] = '.';
            }
        }
        
        cont = 1;       // Corresponde a linha do tabuleiro
        while (cont <= m) {
            fgets(buffer, sizeof(buffer), stdin);
            int tam = removeQuebraLinha(buffer);

            for (int i = 1, j = 0; i <= n; i++, j++) {
                tabuleiro[cont][i] = tolower(buffer[j]);
            }
            cont++;
        }
      
        scanf("%d", &qtdPalavras);
        getchar();

        int encontradas = 0;        // Contador de palavras encontradas

        /* Guardando as palavras */
        while (encontradas < qtdPalavras) {
            fgets(buffer, sizeof(buffer), stdin);
            int tam = removeQuebraLinha(buffer);
            strcpy(buffer, palavraMinuscula(buffer));       // Convertendo em minúsculo
            int encontrou = 0; 

            /* Vamos caçar as palavras */
            for (int i = 1; i <= m && !encontrou; i++) {
                for (int j = 1; j <= n && !encontrou; j++) {
                    if (tabuleiro[i][j] == buffer[0]) {
                        /* Olhando os vizinhos */
                        for (int dx = -1; dx <= 1 && !encontrou; dx++) {
                            for (int dy = -1; dy <= 1 && !encontrou; dy++) {
                                if (dx == 0 && dy == 0) {
                                    continue;       // Ignorar a posição atual
                                }
                                int x = i;
                                int y = j;
                                int pos;
                                for (pos = 1; pos < tam; pos++) {
                                    x += dx;
                                    y += dy;
                                    if (x < 1 || x > m || y < 1 || y > n || tabuleiro[x][y] != buffer[pos]) {
                                        break;      // Não coincide
                                    }
                                }
                                if (pos == tam) {
                                    encontrou = 1;      // Palavra encontrada 
                                    printf("%d %d\n", i, j);
                                    encontradas++;      
                                    break;      // Sainod do loop de direções
                                }
                            }
                        }
                    }
                }
            }
        }
        
        /* Para depuração */
        // for (int i = 0; i < m+2; i++) {
        //     for (int j = 0; j < n+2; j++) {
        //         printf("%c ", tabuleiro[i][j]);
        //     }
        //     printf("\n");
        // }        

        entrada--;
        if (entrada > 0) {      // Tratamento necessário para não ter diff  saída esperada
            printf("\n");
        }
    }

    return 0;
}
