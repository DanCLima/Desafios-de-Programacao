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
            direcao = BAIXO;

            for (int i = 2; i <= segundo; i++, qtd_passos++) {
                if (qtd_passos == tam-1) {
                    if (direcao == DIREITA) {
                        direcao = BAIXO;
                    } else if (direcao == BAIXO) {
                        x++;
                        direcao = CIMA;
                        qtd_passos = 0;
                    } else if (direcao == CIMA) {
                        direcao = ESQUERDA;
                    } else if (direcao == ESQUERDA) {
                        y++;
                        direcao = DIREITA;
                        qtd_passos == 0;
                    }
                }

                switch (direcao) {
                    case DIREITA:
                    printf("Direcao direita!\n");
                    x++;
                    break;

                    case BAIXO:
                    printf("Direcao baixo!\n");
                    y++;
                    break;

                    case ESQUERDA:
                    printf("Direcao esquerda!\n");
                    x--;
                    break;

                    case CIMA:
                    printf("Direcao cima!\n");
                    y--;
                    break;
                }

                if (x == 1 || y == 1) {
                    tam++;
                    qtd_passos = 0;
                }
            }

            printf("Qtd passos %d\n", qtd_passos);
            printf("x: %d y: %d\n", x, y);
            puts("");

        }
    }

    printf("%d\n", segundo);

    return 0;
}
