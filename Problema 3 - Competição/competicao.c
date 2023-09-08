#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int tempo;
    int penalidade;
    char nota;
} Problema;

typedef struct {
    Problema problema[8];   // Criando um vetor com 9 problemas
    int problemasSumetidos[8];
} Desafios;

void cadastraCompetidor(Desafios *competidor, int nProblema, int tempo, char nota, int penalidade) {
    competidor->problema[nProblema].tempo = tempo;
    competidor->problema[nProblema].nota = nota;
    competidor->problema[nProblema].penalidade += penalidade;
    competidor->problemasSumetidos[nProblema] = 1;      //  Indica que o competidor submeteu o problema x | x = posição do vetor
}

/* Inicia o vetor competidor */
void iniciaCompetidores(Desafios *competidor[]) {
    for (int i = 0; i < 100; i++) {
        competidor[i] = NULL;
    }
}

void iniciaVetor (int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = 0;
    }

    // for (int i = 0; i < tam; i++) {
    //     printf("%d ", vetor[i]);
    // }
}

void liberaMemoria(Desafios *competidor[]) {
    for (int i = 0; i < 100; i++) {
        free(competidor[i]);
    }
}

/*----------------------------------------------------+
|    Critérios de pontuação e desempate:              |
|                                                     |
|    1 - número de problemas resolvidos               |
|    2 - menor quantidade de tempo e de penalidade    |
|    3 - ordem crescente do número de equipes         |
+----------------------------------------------------*/ 
int main(int argc, char const *argv[])
{   
    Desafios *competidor[100];

    int entrada, nCompetidor, nProblema, tempo, nota, nEntrada;
    char buffer[100];

    scanf("%d", &entrada);
    getchar();

    iniciaCompetidores(competidor);

    nEntrada = -1;
    int novaEntrada = 1;
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {

        if (strcmp(buffer, "\n") == 0) {            //Por algum motivo tá lendo o raio de 2 '\n'

            if (nEntrada >= 0) {     // Limpando a memória para cada entrada diferente
                printf("Entrada %d:\n", nEntrada+1);
                for (int i = 0; i < 100; i++) {
                    if (competidor[i] != NULL) {
                        for (int j = 0; j < 9; j++) {
                            if (competidor[i]->problemasSumetidos[j] == 1){
                                printf("Competidor %d problema %d tempo %d nota %c penalidade %d\n", i+1, j+1, competidor[i]->problema[j].tempo, competidor[i]->problema[j].nota, competidor[i]->problema[j].penalidade);
                            }  
                        }
                    }  
                }
                iniciaCompetidores(competidor);     // É preciso reiniciar a estrutura de dados a cada entrada
            }
            
            nEntrada++;

        
        } else {
            sscanf(buffer, "%d %d %d %c", &nCompetidor, &nProblema, &tempo, &nota);
            
            if (competidor[nCompetidor-1] == NULL) {      // Caso o competidor ainda não tenha sido cadastrado, ele será
                competidor[nCompetidor-1] = (Desafios *)malloc(sizeof(Desafios));

                iniciaVetor(competidor[nCompetidor-1]->problemasSumetidos, 8);

                /* Todos os problemas devem ser iniciados! */
                for (int i = 0; i < 9; i++) {
                    competidor[nCompetidor-1]->problema[i].tempo = 0;
                    competidor[nCompetidor-1]->problema[i].penalidade = 0;
                    competidor[nCompetidor-1]->problema[i].nota = '\0';
                }
            }  

            /* Lógica para sobrescrever os valores da struct */
            if (competidor[nCompetidor-1]->problema[nProblema-1].nota != 'C') {
                if (competidor[nCompetidor-1]->problema[nProblema-1].nota == 'I') {
                    cadastraCompetidor(competidor[nCompetidor-1], nProblema-1, tempo, nota, 1);
                } else {
                    cadastraCompetidor(competidor[nCompetidor-1], nProblema-1, tempo, nota, 0);
                }
            } else {
                cadastraCompetidor(competidor[nCompetidor-1], nProblema-1, tempo, nota, 0);
            }
        }        
    }


    printf("Entrada %d:\n", nEntrada+1);
    for (int i = 0; i < 100; i++) {
        if (competidor[i] != NULL) {
            for (int j = 0; j < 9; j++) {
                if (competidor[i]->problemasSumetidos[j] == 1){
                    printf("Competidor %d problema %d tempo %d nota %c penalidade %d\n", i+1, j+1, competidor[i]->problema[j].tempo, competidor[i]->problema[j].nota, competidor[i]->problema[j].penalidade);
                }  
            }
        }  
    }

    liberaMemoria(competidor);

    return 0;
}
