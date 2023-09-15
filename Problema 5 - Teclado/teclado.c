/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 5                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   15/09/2023                               |
+----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

/* Remove a quebra de linha da linha de entrada e retorna o tamanho da string */
int removeQuebraLinha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

int procuraCaracter (char *alfabeto, char caracter) {
    int tam = strlen(alfabeto);
    int pos = 0;

    for (int i = 0; i < tam; i++) {
        if (caracter == alfabeto[i]) {
            return i;
        }
    }
}

int main(int argc, char const *argv[])
{

char entrada[250];
char alfabeto[44] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-[;,. ";    //esq
   char novoA[44] = "SNVFRGHJOKL;,MP[WTDYIBECUX1234567890-=]'./ ";     //dir

int tam;
    while (fgets(entrada, sizeof(entrada),stdin) != NULL) {
        tam = removeQuebraLinha(entrada);    
        int pos;

        for (int i = 0; i < tam; i++) {
            pos = procuraCaracter(novoA, entrada[i]);
            printf("%c", alfabeto[pos]);
        }
        printf("\n");
    }
    
    return 0;
}
