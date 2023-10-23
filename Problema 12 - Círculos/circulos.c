#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void printar_vetor (float *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%.3f ", vetor[i]);
    }
    printf("\n");
}

/* 
    a² + b² = c² , então
    a = sqrt(|c²-b²|)
*/
float calcular_distancia (float *raios, int tam) {
    float a, b, c;

    a = raios[0] + raios[tam-1];

    for (int i = 0; i < tam-1; i++) {
        b = fabs(raios[i] - raios[i+1]);
        c = raios[i] + raios[i+1];        
        a += sqrt(c*c-b*b);
    }
    // printf("A dist eh: %.3f\n", a);

    return a;
}

void permuta (float *raios, int inicio, int fim, float *menor_distancia) {
    if (inicio == fim-1) {
        float distancia = calcular_distancia(raios, fim);
        if (distancia < *menor_distancia) {
            *menor_distancia = distancia;
        }
    } else {
        for (int i = inicio; i < fim; i++) {
            float tmp = raios[i];
            raios[i] = raios[inicio];
            raios[inicio] = tmp;
            permuta(raios, inicio+1, fim, menor_distancia);
            raios[inicio] = raios[i];
            raios[i] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int entrada;

    scanf("%d", &entrada);
    getchar();

    while (entrada--) {
        int qtd_circulos;
        float raios[8];

        scanf("%d", &qtd_circulos);
        getchar();

        for (int i = 0; i < qtd_circulos; i++) {
            scanf("%f", &raios[i]);
        }
        
        // printar_vetor(raios, qtd_circulos);
        float menor_distancia = calcular_distancia(raios, qtd_circulos);

        permuta(raios, 0, qtd_circulos, &menor_distancia);

        printf("%.3f\n", menor_distancia);

    }
    
    return 0;
}
