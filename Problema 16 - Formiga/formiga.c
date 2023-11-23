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
        }

        printf("%d\n", segundo);

        int x, y, tam, qtd_passos, direcao;

        x = 1;
        y = 1;
        tam = 1;
        qtd_passos = 1;
        direcao = BAIXO;

        for (int i = 2; i < segundo; i++) {
            if (qtd_passos == tam) {
                if (direcao == DIREITA) {
                    direcao = BAIXO;
                } else if (direcao == BAIXO) {
                    x++;
                    direcao = CIMA;
                } else if (direcao == CIMA) {
                    direcao = ESQUERDA;
                } else if (direcao == ESQUERDA) {
                    y++;
                    direcao = DIREITA;
                }
            }

            if (x == 1 || y == 1) {
                tam++;
                qtd_passos = 0;
            }

            qtd_passos++;
        }

        printf("x: %d y: %d\n", x, y);
    }
    



    return 0;
}
