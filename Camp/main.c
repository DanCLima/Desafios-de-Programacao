#include <stdio.h>
#include <string.h>

int remover_quebra_linha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

int main(int argc, char const *argv[])
{
    int lin, col;

    scanf("%d %d", &lin, &col);
    getchar();

    int tabuleiro[lin+2][col+2];
    char buffer[col];

    for (int i = 0; i < lin+2; i++) {
        for (int j = 0; j < col+2; j++) {
            if (i == 0 || i == lin+1 || j == 0 || j == col+1) {
                tabuleiro[i][j] = 0;
            } else {
                tabuleiro[i][j] = 1;
            }
        }
    }
    
    int linInicial = 1;
    int colInicial = 1;
    int encontrou = 0;
    int movimentos = 0;
    int saiu = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int tam = remover_quebra_linha(buffer);

        for (int i = 0; i < tam; i++) {
            if (buffer[i] == 'N') {
                linInicial--;
                movimentos++;

                if (tabuleiro[linInicial][colInicial] == 0) {
                    printf("Out\n");
                    saiu = 1;
                    break;
                }
                
            } else if (buffer[i] == 'S') {
                linInicial++;
                movimentos++;

                if (tabuleiro[linInicial][colInicial] == 0) {
                    printf("Out\n");
                    saiu = 1;
                    break;
                }                

            } else if (buffer[i] == 'W') {
                colInicial--;
                movimentos++;

                if (tabuleiro[linInicial][colInicial] == 0) {
                    printf("Out\n");
                    saiu = 1;
                    break;
                }

            } else if (buffer[i] == 'E') {
                colInicial++;
                movimentos++;

                if (tabuleiro[linInicial][colInicial] == 0) {
                    printf("Out\n");
                    saiu = 1;
                    break;
                }

            } else if (buffer[i] == 'T') {
                encontrou = 1;
            }
        }

        if (saiu == 1) {
            break;
        }
        
    }

    if (saiu != 1) {
        if (encontrou == 0) {
            printf("Lost\n");
        } else {
            printf("%d\n", movimentos);
        }
    }
    
    return 0;
}
