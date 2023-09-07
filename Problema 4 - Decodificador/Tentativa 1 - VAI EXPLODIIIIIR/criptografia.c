#include <stdio.h>
#include <string.h>

char alfabeto[26];
int somaAlfabeto[26] = {0};
char buffer[80];

/* Remove a quebra de linha das frases de entrada e retorna o tamanho da string corrigido*/
int removeQuebraLinha (char *frase) {
    int tam = strlen(frase);

    if (frase[tam-1] == '\n') {
        frase[tam-1] = '\0';
        tam--;
    }
    return tam;
}

/* Verifica se a frase é a decriptadora verificando os espaços em posições específicas da string passadacomo parâmetro*/
int verificaFraseDecriptadora(char *frase, int tam) {
    for (int i = 0, j = 8; i < tam && j > 0 && tam == 43; i++, j--) {
        if (i == 3 || i == 9 || i == 15 || i == 19 || i == 25 || i == 30 || i == 34 || i == 39) {
            if (frase[i] != ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int posCaracter (char caracter) {
    for (int i = 0; i < 26; i++) {
        if (alfabeto[i] == caracter) {
            return i;
        }    
    }

    return -1;
}

char* decodifica (char *frase) {
    int tam = strlen(frase);

    for (int i = 0; i < tam; i++) {
        int pos = posCaracter(frase[i]);

        if (pos != -1) {
            frase[i] = 'a' + pos;
        }
    }
    
    return frase;
}

void inicializaMatriz(char dados[][80]) {
    for (int i = 0; i < 100; i++) {
        strcpy(dados[i], ""); // Copia uma string vazia para cada elemento da matriz
    }
}

void inicializaAlfabeto(char caracter) {

    for (int i = 0; i < 26; i++) {
        alfabeto[i] = caracter;
    }
}

int verificaTodoAlfabeto(char *frase) {
    for (int i = 0; i < 43; i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            somaAlfabeto[frase[i] - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (somaAlfabeto[i] == 0) {
            return 0;
        }  
    }
    
    return 1;
}

void zeraVetor(int *vetor) {
    for (int i = 0; i < 26; i++) {
        vetor[i] = 0;
    }
    
}

int main () {   
    
    /* 
        A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z 
        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
        t h e   q u i c k   b  r  o  w  n     f  o  x     j  u  m  p  s     o  v  e  r     t  h  e     l  a  z  y     d  o  g
        x n m   c e u o b   l  r  t  z  v     i  t  a     h  e  g  f  d     t  s  m  r     x  n  m     y  p  w  q     k  t  j
    */
    int entrada;
    int verificaFraseDec = 0;
    int indices[] = {36, 10, 7, 40, 2, 16, 42, 1, 6, 20, 8, 35, 22, 14, 12, 23, 4, 11, 24, 0, 5, 27, 13, 18, 38, 37};
    char dados[100][80];
    int linha;
    int odio = 0;

    scanf (" %d", &entrada);
    getchar();

    while (entrada > 0) {   
        zeraVetor(somaAlfabeto);
        inicializaMatriz(dados);
        inicializaAlfabeto('.');

        linha = 0;
        verificaFraseDec = 0;

        while (1) {
            if (fgets(buffer, 80, stdin) == NULL || buffer[0] == '\n') {
                // Verifica se a linha é vazia (fim da entrada)
                if (!verificaFraseDec) {
                    printf("\n\nOdio eh: %d\n", odio);
                    printf("No solution.\n");
                }
                break; // Sai do loop interno e passa para a próxima entrada
            }

            int tam = removeQuebraLinha(buffer);
            strcpy(dados[linha], buffer); // salvando os arquivos já lidos

            if (verificaFraseDec == 0) {
                if (tam == 43 && verificaFraseDecriptadora(buffer, tam) == 1 && verificaTodoAlfabeto(buffer) == 1) {
                    for (int i = 0; i < 26; i++) {
                        if (alfabeto[i] != '.') {
                            verificaFraseDec = 0;
                            break;
                        } else {
                            alfabeto[i] = buffer[indices[i]];
                        }
                        verificaFraseDec = 1;
                    }
                }
            }
            linha++;
        }

    if (verificaFraseDec == 1) {
        int linha2 = 0;
        printf("\n\nOdio eh: %d\n", odio);

        while (linha2 < linha) {
            strcpy(dados[linha2], decodifica(dados[linha2]));
            printf("%s\n", dados[linha2]);
            linha2++;
        }
    }

    entrada--;
    odio++;
}
    // printf("Odio eh: %d", odio);
}