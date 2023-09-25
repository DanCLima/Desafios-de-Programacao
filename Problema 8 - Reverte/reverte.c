/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 8                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   25/09/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

long long int reverte (long long int valor) {
    long long int noInvertido = 0, resultado = valor;
    // printf("Valor recebido: %lld\n", valor);

    for (long long int i = 0 ; resultado > 0; i++) {
        noInvertido = noInvertido * 10;
        noInvertido += (resultado % 10);
        resultado = resultado / 10;
    }
    // printf("No Invertido: %lld\n", noInvertido);
    return noInvertido;
}

int main(int argc, char const *argv[])
{
    long long int entrada, valor, qtdSoma, noInvertido;

    scanf("%lld", &entrada);
    getchar();

    while (scanf("%lld", &valor) != EOF) {
        getchar();
        noInvertido = reverte(valor);

        qtdSoma = 1;
        long long int encerra = 0;

        while (encerra != 1) {
            valor = valor + noInvertido;
            noInvertido = reverte(valor);
            if (valor == noInvertido) {
                printf("%lld %lld\n", qtdSoma, valor);
                encerra = 1;
            }
            qtdSoma++;            
        }
        entrada--;
    }
    
    return 0;
}