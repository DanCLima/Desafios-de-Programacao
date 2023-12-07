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

void imprime_setor (int setor, int digito, int tam) {
    switch (setor) {
    case 0:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf("-");
        }
        printf(" ");
        
        break;    
    case 7:
        printf(" ");
        for (int i = 0; i < tam; i++) {
            printf(" ");
        }
        printf(" ");
        break;
    
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    int tam;    
    char num[20];

    scanf("%d %s", &tam, num);

    int tamanho_numero = strlen(num);
    printf("Tam %d num %s tam_num %d\n", tam, num, tamanho_numero);

    for (int i = 0; i < 7; i++) {       // Loop que percorre todos os setores
        for (int j = 0; j < tamanho_numero; j++) {      // Loop que percorre todos os dígitos
            int digito = num[j] - '0';      // Transformando o digito caracter em um digito int
            
            if ((i == 0 || i == 3 || i == 6) && tabela[digito][i] == 0) {
                imprime_setor(7, digito, tam);
                // if (i == 6) {
                //     printf(" \n");
                // } else {
                //     printf(" ");
                // }
                
            }

            if (tabela[digito][i] == 1) {
                imprime_setor(i, digito, tam);
            }
            
            
            imprime_setor(i, digito, tam);
        }
    }
    
    return 0;
}
