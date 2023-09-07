/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 1                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   21/08/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2, cont, maior, verifica;

    while(scanf("%d %d", &num1, &num2) != EOF) {
        if (num1 > num2) {
            int temp;
            
            temp = num1;
            num1 = num2;
            num2 = temp;
            verifica = 1;
        } else {
            verifica = 0;
        }
        
        maior = 0;
        for (int num3 = num1; num3 <= num2; num3++) {
            // Divide o número por 2 se for par. Caso contrário, multiplica por 3 e soma 1
            cont = 1;
            for(int num4 = num3; num4 != 1; cont++) {
                if (num4 % 2 == 0) {
                    num4 = num4/2;
                } else {
                    num4 = num4 * 3 + 1;
                }
            }
            if (maior < cont) {
                maior = cont;
            }            
        }

        if (verifica == 1) {
            printf("%d %d %d\n", num2, num1, maior);  
        } else {
            printf("%d %d %d\n", num1, num2, maior);  
        }
    }
    return 0;
}