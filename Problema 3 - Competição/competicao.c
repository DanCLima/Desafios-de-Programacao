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

void cadastraCompetidor(Desafios *competidor, int nProblema, int tempo, char nota) {
    competidor->problema[nProblema].tempo = tempo;
    competidor->problema[nProblema].nota = nota;
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
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {

        if (strcmp(buffer, "\n") == 0) {            //Por algum motivo tá lendo o raio de 2 '\n'
            nEntrada++;
            printf("Entrada %d: %s\n", nEntrada, buffer);
            // printf("Tam buffer eh: %d\n", strlen(buffer));
        } else {
            sscanf(buffer, "%d %d %d %c", &nCompetidor, &nProblema, &tempo, &nota);
            
            if (competidor[nCompetidor-1] == NULL) {      // Caso o competidor ainda não tenha sido cadastrado, ele será
                competidor[nCompetidor-1] = (Desafios *)malloc(sizeof(Desafios));

                iniciaVetor(competidor[nCompetidor-1]->problemasSumetidos, 8);
                competidor[nCompetidor-1]->problema->tempo = 0;
                competidor[nCompetidor-1]->problema->penalidade = 0;
                competidor[nCompetidor-1]->problema->nota = '\0';

                cadastraCompetidor(competidor[nCompetidor-1], nProblema-1, tempo, nota);        // Cadastra o competidor no primeiro registro. Então se ele já apresentou algum problema, nao
            } else {
                /* Lógica para sobrescrever os valores da struct */
            }
            

            // printf("Competidor %d problema %d tempo %d nota %c\n", nCompetidor, nProblema, competidor[nCompetidor-1]->problema[nProblema-1].tempo, competidor[nCompetidor-1]->problema[nProblema-1].nota);

        }
    }
    // printf("Competidor %d problema %d tempo %d nota %c\n", 1, 2, competidor[0]->problema[1].tempo, competidor[0]->problema[1].nota);
    // printf("Competidor %d problema %d tempo %d nota %c\n", 3, 1, competidor[2]->problema[0].tempo, competidor[2]->problema[nProblema-1].nota);
    // printf("Competidor %d problema %d penalidade %d\n", 3, 1, competidor[2]->problema[0].penalidade);

    for (int i = 0; i < 100; i++) {
        if (competidor[i] != NULL) {
            printf("Competidor %d problema %d tempo %d nota %c penalidade %d\n", i+1, 1, competidor[i]->problema[0].tempo, competidor[i]->problema[0].nota, competidor[i]->problema[0].penalidade);
        }
    }
    

    return 0;
}
