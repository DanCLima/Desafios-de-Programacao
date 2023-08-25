#include <stdio.h>
#include <stdlib.h>

int posReiBranco[2];
int posReiPreto[2];
// Preto - minúsculo
// Branco - maiúsculo

void inicializaMatriz(char matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           matriz[i][j] = '0';
        }
    }
}

void exibeMatriz (int m, int n, char matriz[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void posicaoReiBranco(char matriz[10][10]){
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (matriz[i][j] == 'K') {
                posReiBranco[0] = i;
                posReiBranco[1] = j;    
            }
        }
    }
}

void posicaoReiPreto(char matriz[10][10]){
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (matriz[i][j] == 'k') {
                posReiPreto[0] = i;
                posReiPreto[1] = j;    
            }
        }
    }
}

/* Certo! */
int verificaPeao (char tabuleiro[10][10], int posReiBranco[2], int posReiPreto[2]) {
    int check;

    if (tabuleiro[posReiPreto[0]+1][posReiPreto[1]-1] == 'P') {
        check = 1;
        printf("O Rei Preto esta em check!\n");
    } else if (tabuleiro[posReiPreto[0]+1][posReiPreto[1]+1] == 'P') {
        check = 1;
        printf("O Rei Preto esta em check!\n");
    }else if(tabuleiro[posReiBranco[0]-1][posReiBranco[1]+1] == 'p') {
        check = 1;
        printf("O Rei Branco esta em check!\n");
    } else if (tabuleiro[posReiBranco[0]-1][posReiBranco[1]-1] == 'p'){ // 
        check = 1;
        printf("O Rei Branco esta em check!\n");
    } else {
        check = 0;
    }
    return check;
}

int main () {
    char i, j;
    char tabuleiro[10][10];       //Criando um padding para eviter erro de acesso de memória na verificação do peão/rei

    inicializaMatriz(tabuleiro);
    printf("Matriz inicializada com zeros\n");
    exibeMatriz(10, 10, tabuleiro);
    printf("\n");


    /* Mudar para ler a quantidade que for passada de entrada */
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            scanf (" %c", &tabuleiro[i][j]);
        }
    }
    
    // exibeMatriz(10, 10, tabuleiro);
    posicaoReiPreto(tabuleiro);
    posicaoReiBranco(tabuleiro);
    printf("Posicao Rei Preto:  linha %d, coluna %d \n", posReiPreto[0], posReiPreto[1]);
    printf("Posicao Rei Branco:  linha %d, coluna %d \n", posReiBranco[0], posReiBranco[1]);
    
    int verifica = verificaPeao(tabuleiro, posReiBranco, posReiPreto);
    printf("\n");

    exibeMatriz(10, 10, tabuleiro);

}