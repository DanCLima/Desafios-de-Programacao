#include <stdio.h>

int main(int argc, char const *argv[])
{
    int qtdEntrada;
    int base;
    int cont = 1;

    scanf("%d", &qtdEntrada);
    int vetor[qtdEntrada];

    for (int i = 0; i < qtdEntrada; i++) {
        scanf("%d", &vetor[i]);
    }

    base = vetor[0];

    for (int i = 1; i < qtdEntrada; i++) {
        if (base < vetor[i]) {
            cont++;
        }
        base = vetor[i];

    }
    printf("%d", cont);
    
    return 0;
}