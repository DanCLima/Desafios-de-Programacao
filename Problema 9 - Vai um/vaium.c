/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 9                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   29/09/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int valor1, valor2;

    while (scanf("%d %d", &valor1, &valor2) != EOF) {
        if (valor1 == valor2 && valor1 == 0) {
            return 0;
        }
        
        int vaiUm = 0;
        int contaOperacoes = 0;

        while (valor1 > 0 || valor2 > 0) {
            int digito1 = valor1 % 10;
            int digito2 = valor2 % 10;

            int umAnterior = vaiUm;
            int soma = digito1 + digito2 + umAnterior;

            vaiUm = soma / 10;

            if (vaiUm > 0) {
                contaOperacoes++;
            }
            
            valor1 = valor1 / 10;
            valor2 = valor2 / 10;
        }
        
        if (contaOperacoes == 0) {
            printf("No carry operation.\n");
        } else if (contaOperacoes == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", contaOperacoes);
        }
    }
    
    return 0;
}

