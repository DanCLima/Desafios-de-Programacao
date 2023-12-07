/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 20                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   07/12/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int tabela[10][7] = {       // Setores [A, B, C, D, E, F, G]
    {1, 1, 1, 0, 1, 1, 1},  // Digito 0
    {0, 0, 1, 0, 0, 1, 0},  // Digito 1
    {1, 0, 1, 1, 1, 0, 1},  // Digito 2
    {1, 0, 1, 1, 0, 1, 1},  // Digito 3
    {0, 1, 1, 1, 0, 1, 0},  // Digito 4
    {1, 1, 0, 1, 0, 1, 1},  // Digito 5
    {1, 1, 0, 1, 1, 1, 1},  // Digito 6
    {1, 0, 1, 0, 0, 1, 0},  // Digito 7
    {1, 1, 1, 1, 1, 1, 1},  // Digito 8
    {1, 1, 1, 1, 0, 1, 1},  // Digito 9
};

void imprime_setor (int setor, int digito, int tam) {
    switch (setor) {
    case 0:
    case 3:
    case 6:
        if (tabela[digito][setor] == 1) {
            printf(" ");
            for (int i = 0; i < tam; i++) {
                printf("-");
            }
            printf("  ");
        } else {
            printf(" ");
            for (int i = 0; i < tam; i++) {
                printf(" ");
            }
            printf("  ");            
        }
        break;    
    case 1:
    case 4:
        if (tabela[digito][setor] == 1) {
            if (tabela[digito][setor+1] == 1) {
                printf("|");
                for (int i = 0; i < tam; i++) {
                    printf(" ");
                }
                printf("| ");
            } else {
                printf("|");
                for (int i = 0; i < tam; i++) {
                    printf(" ");
                }
                printf("  ");
            }
        } else {
            if (tabela[digito][setor+1] == 1) {
                printf(" ");
                for (int i = 0; i < tam; i++) {
                    printf(" ");
                }
                printf("| ");
            } else {
                printf(" ");
                for (int i = 0; i < tam; i++) {
                    printf(" ");
                }
                printf("  ");
            }
        }
        break;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    int tam;    
    char num[20];

    while (scanf("%d %s", &tam, num) != EOF) {
        if (tam == 0 && num[0] == '0') {
            break;
        } else {
            int tamanho_numero = strlen(num);
            for (int i = 0; i < 7; i++) {       // Loop que percorre todos os setores
                if (i == 1 || i == 4) {
                    int cont = 0;
                    while (cont < tam) {
                        for (int j = 0; j < tamanho_numero; j++) {      // Loop que percorre todos os dígitos
                            int digito = num[j] - '0';      // Transformando o digito caracter em um digito int       

                            imprime_setor(i, digito, tam);
                        }
                        printf("\n");
                        cont++;          
                    }
                } else if (i == 0 || i == 3 || i == 6) {
                    for (int j = 0; j < tamanho_numero; j++) {      // Loop que percorre todos os dígitos
                        int digito = num[j] - '0';      // Transformando o digito caracter em um digito int

                        imprime_setor(i, digito, tam);
                    }
                    printf("\n");
                }
            }
        }
    }
        
    return 0;
}
