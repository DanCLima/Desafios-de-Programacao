/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 11                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   09/10/2023                               |
+----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Remove a quebra de linha no final do buffer e retorna o tamanho da string alterada */
int remover_quebra_linha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

/* Realiza a soma dos algarismos da string passada como parâmetro */
int somar_algarismos2 (char *string, int tam) {
    int soma = 0;

    for (int i = 0; i < tam; i++) {
        int num = string[i] - '0';
        soma += num;
    }

    return soma;
}

/* Realiza a soma dos algarismos do número passado como parâmetro */
int somar_algarismos (int num) {
    int soma = 0;

    for (int i = 0; num >= 10; i++) {
        soma += num % 10;
        num = num / 10;
    }
    soma += num;

    return soma;
}

/* Realiza a fatoração do número passado como parâmetro e retorna a soma de todos os ALGARISMOS da fatoração. 
    Ex: 
        Fatoração:              4937775 = 3 * 5 * 5 * 65837 
        Soma dos algarismos:    3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42                                          */
long int somar_algarismos_fatorados (long int num) {
    long int i;
    long int c;
    long int soma = 0;

    c = num;

    while ((c % 2 == 0)) {
        // printf("%d\n", 2);
        c = c/2;
        soma += 2;
    }

    i = 3;
    while (i <= (sqrt(c) + 1)) {
        if ((c % i) == 0) {
            // printf("%ld\n", i);
            c = c/i;

            if (i >= 10) {
                long int temp = i;

                while (temp >= 10) {
                    soma += (temp % 10);
                    temp = temp/10;
                }
                soma += temp;
            } else {
                soma += i;
            }

        } else {
            i = i + 2;
        }        
    }  

    if (c > 1) {
        // printf("%ld\n", c);
        if (c >=10) {
            long int temp = c;

            while (temp >= 10) {
                soma += (temp % 10);
                temp = temp/10;
            }
            soma += temp;
        } else {
            soma += c;
        }
    }

    return soma;
}

/* Verifica se o número passado como parâmetro é primo. Retorna 1 para sim e 0 para não. */
int verificar_numero_primo (long int num) {
    int e_primo = 1;

    for (int i = 2; i <= sqrt(num); i +=2 ) {
        if (num % i == 0) {
            e_primo = 0;
            break;
        }
        
        /* Verificar os números 2 3 5 7 ...*/
        if (i == 2) {
            i--;
        }
    }
    return e_primo;
}

int main(int argc, char const *argv[])
{
    int entrada;
    int numero;
    char buffer[100];

    scanf("%d", &entrada);
    getchar();

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int tam = remover_quebra_linha(buffer);
        int soma_algarismos, soma_algarismos_fatorados, e_primo;
        int numero_int = atoi(buffer);

        while (1) {
            soma_algarismos = somar_algarismos(numero_int);
            soma_algarismos_fatorados = somar_algarismos_fatorados(numero_int);
            e_primo = verificar_numero_primo(numero_int);
            
            /* O número de Smith não pode ser um número primo! */
            if (soma_algarismos == soma_algarismos_fatorados && e_primo != 1) {
                break;
            }
            
            numero_int++;
        }
        printf("%d\n", numero_int);
        
        entrada--;
    }
    
    return 0;
}
