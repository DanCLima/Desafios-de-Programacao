#include <stdio.h>

long long int encontrar_maior(long long int *vetor, int tam) {
    long long int maior = -1;

    for (int i = 0; i < tam; i++) {
        if (maior < vetor[i]) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    long long int lin, vol, l, w, h;

    scanf("%lld %lld", &lin, &vol);

    long long int vetor[lin];

    for (int i = 0; i < lin; i++) {
        scanf("%lld %lld %lld", &l, &w, &h);
        vetor[i] = (long long int) l * w * h;
    }

    for (int i = 0; i < lin; i++) {
        printf("%lld ", vetor[i]);
    }
    printf("\n");

    long long int maior = encontrar_maior(vetor, lin);
    printf("%lld\n", maior - vol);

    return 0;
}
