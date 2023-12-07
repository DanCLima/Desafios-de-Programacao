#include <stdio.h>
#include <string.h>
#include <math.h>

int tabela[10][7] = {       // a, b, c, d, e, f, g
    {1, 1, 1, 0, 1, 1, 1},  //0
    {0, 0, 1, 0, 0, 1, 0},  //1
    {1, 0, 1, 1, 1, 0, 1},  // 2
    {1, 0, 1, 1, 0, 1, 1},  // 3
    {0, 1, 1, 1, 0, 1, 0},  // 4
    {1, 1, 0, 1, 0, 1, 1},  // 5
    {1, 1, 0, 1, 1, 1, 1},  // 6
    {1, 0, 1, 0, 0, 1, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
};

int extrai_digito(int *num) {
    int num_2 = *num;
    int i = 0;

    // printf("Num: %d\n", *num);
    if (*num >= 10) {
        for (i = 0; num_2 >= 10; i++) {
            num_2 = num_2/10;
        }
        *num = *num - num_2 * (pow(10, i));

        // printf("Digito extraido: %d\n", num_2);
        // printf("Num: %d\n", *num);
        // puts("");
    }
    
    return num_2;
}

void imprime_setor (int setor, int digito, int tam) {
    switch (setor) {
    case 0:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf("-");
        }
        printf(" \n");
        break;
    case 1:
        if (tabela[digito][2] == 1) {
            for (int i = 0; i < tam; i++) {
                printf("|");
                for (int j = 0; j < tam; j++) {
                    printf(" ");
                }
                printf("|\n");
            }
        } else {
            for (int i = 0; i < tam; i++) {
                printf("|\n");
            }
        }
        break;
    case 2:
        if (tabela[digito][1] == 0) {
            for (int i = 0; i < tam; i++) {
                printf(" ");
                for (int j = 0; j < tam; j++) {
                    printf(" ");
                }
                printf("|\n");
            }
        }
        break;
    case 3:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf("-");
        }
        printf(" \n");
        break;
    case 4:
        if (tabela[digito][5] == 1) {
            for (int i = 0; i < tam; i++) {
                printf("|");
                for (int j = 0; j < tam; j++) {
                    printf(" ");
                }
                printf("|\n");
            }
        } else {
            for (int i = 0; i < tam; i++) {
                printf("|\n");
            }
        }
        break;
    case 5:
        if (tabela[digito][4] == 0) {
            for (int i = 0; i < tam; i++) {
                printf(" ");
                for (int j = 0; j < tam; j++) {
                    printf(" ");
                }
                printf("|\n");
            }
        }
        break;
    case 6:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf("-");
        }
        printf(" \n");
        break;
    case 7:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf(" ");
        }
        printf(" \n");
        break;
    default:
        break;
    }
    
    
}

void imprime_digito(int digito, int tam) {
    for (int i = 0; i < 7; i++) {
        if ((i == 0 || i == 3 || i == 6) && tabela[digito][i] == 0) {
            imprime_setor(7, digito, tam);
        }
        
        if (tabela[digito][i] == 1) {
            imprime_setor(i, digito, tam);
        }
    }
}

int main(int argc, char const *argv[]) {
    int tam, num;

    while ((scanf("%d %d", &tam, &num)) != EOF) {
        if (tam == 0 && num == 0) {
            break;
        }
        
        printf("Num: %d tam: %d\n", num, tam);
        if (num > 9) {
            for (int i = 0; num > 9; i++) {
                int digito = extrai_digito(&num);
                imprime_digito(digito, tam);
            }
        }
        imprime_digito(num, tam);
    
    }

    return 0;
}
