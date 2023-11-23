/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 16                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   23/11/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#define DIREITA 0
#define BAIXO 1
#define ESQUERDA 2
#define CIMA 3

int main(int argc, char const *argv[])
{
    int segundo;

    while (scanf("%d", &segundo) != EOF) {
        if (segundo == 0) {
            break;
        } else if (segundo == 1) {
            printf("1 1\n");
        } else {
            int x, y, tam, qtd_passos, direcao;

            x = 1;
            y = 2;
            tam = 2;
            qtd_passos = 0;
            direcao = DIREITA;

            for (int i = 2; i < segundo; i++) {
                if (qtd_passos == tam-1) {
                    if (direcao == DIREITA) {
                        direcao = BAIXO;
                        qtd_passos = 0;
                    } else if (direcao == BAIXO) {
                        x++;
                        direcao = CIMA;
                        qtd_passos = 0;
			            tam++;
                        continue;
                    } else if (direcao == CIMA) {
                        direcao = ESQUERDA;
                        qtd_passos = 0;
                    } else if (direcao == ESQUERDA) {
                        y++;
                        direcao = DIREITA;
                        qtd_passos = 0;
			            tam++;
                        continue;
                    }
                }

                switch (direcao) {
                    case DIREITA:
                    x++;
                    break;

                    case BAIXO:
                    y--;
                    break;

                    case ESQUERDA:
                    x--;
                    break;

                    case CIMA:
                    y++;
                    break;
                }

                qtd_passos++;
            }
            printf("%d %d\n", x, y);
        }
    }

    return 0;
}
