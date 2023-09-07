/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 4                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   07/09/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char alfabeto[26];       // Guarda o caracter codificado na posição correta do alfabeto. Ex: t -> a, g -> c ... alfabeto[26] = "tg ..."
int verificaLetras[26];     // Verifica se todas as letras do alfabeto foram usadas para a codificação
char dados[100][80];        // Armazena os dados que estão sendo lidos
char fraseMagica[100][80];      // Contém a frase mágica de cada entrada ou "No solution."
int indices[] = {36, 10, 7, 40, 2, 16, 42, 1, 6, 20, 8, 35, 22, 14, 12, 23, 4, 11, 24, 0, 5, 27, 13, 18, 38, 37};

/* Remove a quebra de linha da linha de entrada e retorna o tamanho da string */
int removeQuebraLinha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

/* Inicia o vetor (que verifica o uso de todas as letras do alfabeto) com 0 */
void iniciaVerificaLetras(int *ehAlfabeto) {
    for (int i = 0; i < 26; i++) {
        ehAlfabeto[i] = 0;
    }
}

/* Verifica se a string recebida é uma frase mágica */
int verificaFraseMagica(char *buffer, int tam) {
    if (tam == 43) {  
        // Os espaços têm posição fixa na frase
        if (buffer[3] == ' ' && buffer[9] == ' ' && buffer[15] == ' ' && buffer[19] == ' ' && buffer[25] == ' ' && buffer[30] == ' ' && buffer[34] == ' ' && buffer[39] == ' ') {
            iniciaVerificaLetras(verificaLetras);
            for (int i = 0; i < tam; i++) {     
                if (buffer[i] >= 'a' && buffer[i] <= 'z'){
                    verificaLetras[buffer[i] - 'a'] = 1;
                }
            }
            
            // Verifica se todas as letras do alfabeto foram usadas, através do vetor de zeros
            for (int i = 0; i < 26; i++) {    
                if (verificaLetras[i] == 0) {
                    return 0;
                }   
            }
            return 1;
        }
    }
    return 0;
}

/* Usado para debugar */
void exibeFrasesMagicas (int entrada) {
    for (int i = 0; i < entrada; i++) {
        printf("Frase %d: %s\n", i, fraseMagica[i]);
    }
}

/* Encontra a posição do caracter passado como parâmetro no vetor alfabeto */
int posCaracter (char caracter) {
    for (int i = 0; i < 26; i++) {
        if (alfabeto[i] == caracter) {
            return i;
        }    
    }
    return -1;
}

/* Decodifica a linha enviada passada parâmetro */
void decodifica (int linha) {
    int tam = strlen(dados[linha]);

    for (int i = 0; i < tam; i++) {
        if (dados[linha][i] >= 'a' && dados[linha][i] <= 'z') {
            int pos = posCaracter(dados[linha][i]);

            if (pos != -1) {
                dados[linha][i] = 'a' + pos;
            }
        }
    }
}

/* Preeche o vetor alfabeto com o alfabeto na ordem correta, porém ainda codificado */
void preencheaAlfabeto (int linha) {
    int tam = strlen(fraseMagica[linha]);

    for (int i = 0; i < 26; i++) {
        alfabeto[i] = fraseMagica[linha][indices[i]];
    }
}

/* Usado para debugar */
void exibeDados (int tam) {
    for (int i = 0; i < tam; i++){
        printf("%s\n", dados[i]);
    }
}

int main(int argc, char const *argv[])
{
    /* 
        A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z 
        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25      

        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
        t h e   q u i c k   b  r  o  w  n     f  o  x     j  u  m  p  s     o  v  e  r     t  h  e     l  a  z  y     d  o  g
        x n m   c e u o b   l  r  t  z  v     i  t  a     h  e  g  f  d     t  s  m  r     x  n  m     y  p  w  q     k  t  j
    */

    int entrada;
    char buffer[100];
    int tam;
    int linha;
    int contEntrada;
    int fraseEncontrada = 0;
    int totalLinhas = 0;

    scanf("%d", &entrada);
    getchar();  
        
    linha = 0;  
    for (int i = 0; i < entrada; i++) {
        contEntrada = 0;       
        int maxQbrLin = 0;

        while (fgets(buffer, sizeof(buffer), stdin) != NULL){
            tam = removeQuebraLinha(buffer);                

            strcpy(dados[linha], buffer);  

            /* Como a lógica alterna as entradas de acordo com o caracter '\n', 
            esse if trata a possibilidade de obter uma quebra de linhas como 
            entrada */
            if (linha > 0 && dados[linha][0] == '\n') {    
                if (dados[linha-1][0] == '\n' && maxQbrLin == 0) {
                    maxQbrLin = 1;
                } else {
                    maxQbrLin = 0;
                }
                
                if (maxQbrLin == 0) {
                    contEntrada++;      // Se uma entrada for '\n' não pode incrementar o contador de quebra linha que alterna entre entradas
                    fraseEncontrada = 0;
                }
            }

            int semSol = 0;
            if (verificaFraseMagica(buffer, tam) == 1 && fraseEncontrada == 0) {
                strcpy(fraseMagica[contEntrada], buffer);
                fraseEncontrada = 1;

            } else if (verificaFraseMagica(buffer, tam) != 1 && fraseEncontrada == 0 && semSol == 0) {
                strcpy(fraseMagica[contEntrada], "No solution.");
                semSol = 1;
            }
            linha++;
        }
    }

    int maxQbrLin = 0;
    contEntrada = 0;
    for (int i = 0, lim = 0; i < linha; i++) {
        if (i > 0 && dados[i][0] == '\n') {    
            if (dados[i-1][0] == '\n' && maxQbrLin == 0) {
                maxQbrLin = 1;
            } else {
                maxQbrLin = 0;
            }
            
            if (maxQbrLin == 0) {
                contEntrada++;    
                lim = 0;
                printf("\n");   
            }
        }

        if (strcmp(fraseMagica[contEntrada], "No solution.") == 0 && lim == 0) {
            printf("%s\n", fraseMagica[contEntrada]);           
            lim = 1;
        } else if (strcmp(fraseMagica[contEntrada], "No solution.") != 0 && dados[i][0] != '\n') {
            preencheaAlfabeto(contEntrada);
            decodifica(i);
            printf("%s\n", dados[i]);             
        }
    }
    return 0;
}