/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 2                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   25/08/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Peças pretas - minúsculo
// Peças brancas - MAIÚSCULO 

int posReiBranco[2];
int posReiPreto[2];
int check = 0;

/*-------------------------------------------------------------------------------------------------------
    Verifica se todos os elementos da matriz são '.' e retorna 1 se sim
-------------------------------------------------------------------------------------------------------*/
int verificaParada(char tabuleiro[10][10]) {
    int parada = 1;

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (tabuleiro[i][j] != '.') {
                parada = 0;
                break;
            }
        }
    }
    return parada;
}

/*-------------------------------------------------------------------------------------------------------
    Preenche a matriz com caracteres zeros
-------------------------------------------------------------------------------------------------------*/
void inicializaMatriz(char matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           matriz[i][j] = '0';
        }
    }
}

/*-------------------------------------------------------------------------------------------------------
    Exibe a matriz
-------------------------------------------------------------------------------------------------------*/
void exibeMatriz (int m, int n, char matriz[10][10]) {
    for (int i = 1; i < (m-1); i++) {
        for (int j = 1; j < (n-1); j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*-------------------------------------------------------------------------------------------------------
    Busca a posição do Rei Branco na matriz
-------------------------------------------------------------------------------------------------------*/
void posicaoReiBranco(char matriz[10][10]){
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (matriz[i][j] == 'K') {
                posReiBranco[0] = i;
                posReiBranco[1] = j;
                break;    
            }
        }
    }
}

/*-------------------------------------------------------------------------------------------------------
    Busca a posição do Rei Preto na Matriz
-------------------------------------------------------------------------------------------------------*/
void posicaoReiPreto(char matriz[10][10]){
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (matriz[i][j] == 'k') {
                posReiPreto[0] = i;
                posReiPreto[1] = j;  
                break;  
            }
        }
    }
}

/*-------------------------------------------------------------------------------------------------------
    Verifica se o Rei está em check pelo peão inimigo
-------------------------------------------------------------------------------------------------------*/
void verificaPeao (char tabuleiro[10][10], int posReiBranco[2], int posReiPreto[2]) {
    check = 0;

    if ((tabuleiro[posReiPreto[0] + 1][posReiPreto[1] - 1] == 'P' || tabuleiro[posReiPreto[0] + 1][posReiPreto[1] + 1] == 'P') && check == 0) {
        check = 1;
        printf("black king is in check.\n");
    } else if ((tabuleiro[posReiBranco[0] - 1][posReiBranco[1] + 1] == 'p' || tabuleiro[posReiBranco[0] - 1][posReiBranco[1] - 1] == 'p') && check == 0) {
        check = 1;
        printf("white king is in check.\n");
    } else {
        check = 0;
    }
}

/*-------------------------------------------------------------------------------------------------------
    Verifica se o Rei está em check por alguma torre e/ou rainha pela horizontal e/ou vertical
-------------------------------------------------------------------------------------------------------*/
void verificaAtaqueOrtogonal(char tabuleiro[10][10], int posReiBranco[2], int posReiPreto[2]) {
    check = 0;

    /* Alternando os 2 reis. 0 Para o preto e 1 para o Branco */
    for (int rei = 0, linha, coluna; rei < 2 && check == 0; rei++) {
        if (rei == 0) {
            linha = posReiPreto[0];
            coluna = posReiPreto[1];
        } else {
            linha = posReiBranco[0];
            coluna = posReiBranco[1];     
        }

        //Verificando ataques acima do Rei
        for (int i = linha; i > 0 && check == 0; i--) {
            if (tabuleiro[i-1][coluna] != '.') {
                if (rei == 0 && tabuleiro[i-1][coluna] == 'R' || rei == 0 && tabuleiro[i-1][coluna] == 'Q' ||
                rei == 1 && tabuleiro[i-1][coluna] == 'r' || rei == 1 && tabuleiro[i-1][coluna] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }

        //Verificando ataques abaixo do Rei
        for (int i = linha; i < 9 && check == 0; i++) {
            if (tabuleiro[i+1][coluna] != '.') {
                if (rei == 0 && tabuleiro[i+1][coluna] == 'R' || rei == 0 && tabuleiro[i+1][coluna] == 'Q' ||
                rei == 1 && tabuleiro[i+1][coluna] == 'r' || rei == 1 && tabuleiro[i+1][coluna] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }

        //Verificando ataques à esquerda do Rei
        for (int i = coluna; i > 0 && check == 0; i--) {
            if (tabuleiro[linha][i-1] != '.') {
                if (rei == 0 && tabuleiro[linha][i-1] == 'R' || rei == 0 && tabuleiro[linha][i-1] == 'Q' ||
                rei == 1 && tabuleiro[linha][i-1] == 'r' || rei == 1 && tabuleiro[linha][i-1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }

        //Verificando ataques à direita do Rei
        for (int i = coluna; i < 9 && check == 0; i++) {
            if (tabuleiro[linha][i+1] != '.') {
                if (rei == 0 && tabuleiro[linha][i+1] == 'R' || rei == 0 && tabuleiro[linha][i+1] == 'Q' ||
                rei == 1 && tabuleiro[linha][i+1] == 'r' || rei == 1 && tabuleiro[linha][i+1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }
    } 
}

/*-------------------------------------------------------------------------------------------------------
    Verifica se o Rei está em check por algum bispo e/ou rainha pelas diagonais
-------------------------------------------------------------------------------------------------------*/
void verificaAtaqueDiagonal(char tabuleiro[10][10], int posReiBranco[2], int posReiPreto[2]) {
    check = 0;

    /* Alternando os 2 reis. 0 Para o preto e 1 para o Branco */
    for (int rei = 0, linha, coluna; rei < 2 && check == 0; rei++) {
        if (rei == 0) {
            linha = posReiPreto[0];
            coluna = posReiPreto[1];
        } else {
            linha = posReiBranco[0];
            coluna = posReiBranco[1];     
        }

        //Verificando ataques à diagonal superior esquerda do Rei
        for (int i = linha, j = coluna; i > 0 && j > 0 && check == 0; i--, j--) {
            if (tabuleiro[i-1][j-1] != '.') {
                if (rei == 0 && tabuleiro[i-1][j-1] == 'B' || rei == 0 && tabuleiro[i-1][j-1] == 'Q' ||
                rei == 1 && tabuleiro[i-1][j-1] == 'b' || rei == 1 && tabuleiro[i-1][j-1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }

        //Verificando ataques à diagonal superior direita do Rei
        for (int i = linha, j = coluna; i > 0 && j < 9 && check == 0; i--, j++) {
            if (tabuleiro[i-1][j+1] != '.') {
                if (rei == 0 && tabuleiro[i-1][j+1] == 'B' || rei == 0 && tabuleiro[i-1][j+1] == 'Q' ||
                rei == 1 && tabuleiro[i-1][j+1] == 'b' || rei == 1 && tabuleiro[i-1][j+1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                } else
                break; // Peça irá bloquear o ataque
            } 
        }        

        //Verificando ataques à diagonal inferior esquerda do Rei
        for (int i = linha, j = coluna; i < 9 && j > 0 && check == 0; i++, j--) {
            if (tabuleiro[i+1][j-1] != '.') {
                if (rei == 0 && tabuleiro[i+1][j-1] == 'B' || rei == 0 && tabuleiro[i+1][j-1] == 'Q' ||
                rei == 1 && tabuleiro[i+1][j-1] == 'b' || rei == 1 && tabuleiro[i+1][j-1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
                break; // Peça irá bloquear o ataque
            } 
        }

        //Verificando ataques à diagonal inferior direita do Rei
        for (int i = linha, j = coluna; i < 9 && j < 9 && check == 0; i++, j++) {
            if (tabuleiro[i+1][j+1] != '.') {
                if (rei == 0 && tabuleiro[i+1][j+1] == 'B' || rei == 0 && tabuleiro[i+1][j+1] == 'Q' ||
                rei == 1 && tabuleiro[i+1][j+1] == 'b' || rei == 1 && tabuleiro[i+1][j+1] == 'q') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }               
                break; // Peça irá bloquear o ataque
            } 
        } 
    }
}

/*-------------------------------------------------------------------------------------------------------
    Verifica se o Rei está em check pelo Cavalo inimigo
-------------------------------------------------------------------------------------------------------*/
void verificaCavalo(char tabuleiro[10][10], int posReiBranco[2], int posReiPreto[2]) {
    check = 0;

    /* Alternando os 2 reis. 0 Para o preto e 1 para o Branco */
    for (int rei = 0, linha, coluna; rei < 2 && check == 0; rei++) {
        if (rei == 0) {
            linha = posReiPreto[0];
            coluna = posReiPreto[1];
        } else {
            linha = posReiBranco[0];
            coluna = posReiBranco[1];     
        }

        // Todos os 8 movimentos possíveis do cavalo
        int movimentos[8][2] = {
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
        };
        
        for (int i = 0; i < 8 && check == 0; i++) {
            int novaLinha = linha + movimentos[i][0];
            int novaColuna = coluna + movimentos[i][1];

            if (novaLinha > 0 && novaLinha < 9 && novaColuna > 0 && novaColuna < 9 && check == 0) {
                if (rei == 0 && tabuleiro[novaLinha][novaColuna] == 'N' || rei == 1 && tabuleiro[novaLinha][novaColuna] == 'n') {
                    check = 1;
                    printf("%s king is in check.\n", (rei == 0)? "black" : "white");
                }
            }
        }
    }
}

int main () {
    char i, j;
    char tabuleiro[10][10];       //Criando um padding para eviter erro de acesso de memória
    int parada = 0;
    int game = 1;

    while (parada == 0)
    {
        inicializaMatriz(tabuleiro);

        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                scanf (" %c", &tabuleiro[i][j]);
            }
        }
        
        parada = verificaParada(tabuleiro);
        posicaoReiPreto(tabuleiro);
        posicaoReiBranco(tabuleiro);
        
        if (parada != 1) {
            printf("Game #%d: ", game);
            verificaPeao(tabuleiro, posReiBranco, posReiPreto);
            if (check == 0) {
                verificaAtaqueOrtogonal(tabuleiro, posReiBranco, posReiPreto);
                if (check == 0) {
                    verificaAtaqueDiagonal(tabuleiro, posReiBranco, posReiPreto);
                    if (check == 0) {
                        verificaCavalo(tabuleiro, posReiBranco, posReiPreto);
                        if (check == 0){
                            printf("no king is in check.\n");
                        }
                    } 
                } 
            }            
        }
        game++;
    }
    printf("\n");
}