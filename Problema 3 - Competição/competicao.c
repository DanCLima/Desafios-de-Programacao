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
    int tempoTotal;
    int problemasResolvidos;
    int ranking;
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

void classificacao(Desafios *competidor[]) {
    for (int i = 0; i < 100; i++) {
        if (competidor[i] != NULL) {
            for (int j = 0; j < 9; j++) {
                if (competidor[i]->problema[j].nota == 'C'){
                    competidor[i]->problemasResolvidos += 1;
                    competidor[i]->tempoTotal += competidor[i]->problema[j].tempo;

                    if (competidor[i]->problema[j].penalidade == 1) {
                        competidor[i]->tempoTotal += 20;
                    }
                }     
            }
        }  
    }
}

void classificarCompetidores(Desafios *competidor[], int totalCompetidores) {
    // Criar um vetor temporário para armazenar índices dos competidores
    int indices[totalCompetidores];

    // printf("Total de competidores: %d\n", totalCompetidores);
    // printf("Indices: ");
    for (int i = 0; i < totalCompetidores; i++) {
        indices[i] = i;
        // printf("%d ", indices[i]);
    }
    // printf("\n");

    // Ranqueando todos os competidores de acordo com o seu cadastro
    for (int i = 0, j = 0; i < 100 && j < totalCompetidores; i++) {
        if (competidor[i] != NULL) {
            competidor[i]->ranking = j;
            j++;
        }  
    }    

    // Ranquear os participantes com base nos critérios
    for (int i = 0; i < totalCompetidores; i++) {
        if (competidor[i] != NULL) {
            for (int j = i + 1; j < totalCompetidores; j++) {
                if (competidor[j] != NULL) {
                    if (competidor[i]->problemasResolvidos < competidor[j]->problemasResolvidos ||
                        (competidor[i]->problemasResolvidos == competidor[j]->problemasResolvidos &&
                        competidor[i]->tempoTotal > competidor[j]->tempoTotal) ||
                        (competidor[i]->problemasResolvidos == competidor[j]->problemasResolvidos &&
                        competidor[i]->tempoTotal == competidor[j]->tempoTotal && i > j)) {                 

                        int temp = competidor[i]->ranking;
                        competidor[i]->ranking = competidor[j]->ranking;
                        competidor[j]->ranking = temp;
                    }
                }
            }
        }
    }
}

void exibeClassificacaoTabular(Desafios *competidor[]) {
    printf("+------------------------------------------------------------+\n");
    printf("| Competidor | Problemas Resolvidos | Tempo total |  Ranking |\n");
    printf("+------------+----------------------+-------------+----------+\n");

    for (int i = 0; i < 100; i++) {
        if (competidor[i] != NULL) {
            printf("|%6d      |%11d           |%7d      |%5d     |\n", i+1, competidor[i]->problemasResolvidos, competidor[i]->tempoTotal, competidor[i]->ranking);
        }  
    }    
    printf("+------------------------------------------------------------+\n");
}

void exibeClassificacao(Desafios *competidor[], int totalCompetidores) {
    for (int i = 0; i < totalCompetidores; i++) {
        for (int j = 0; j < 100; j++) {
            if (competidor[j] != NULL && competidor[j]->ranking == i) {
                // printf("O ranking eh %d\n", competidor[j]->ranking);
                printf("%d %d %d RANKING: %d\n", j+1, competidor[j]->problemasResolvidos, competidor[j]->tempoTotal, competidor[j]->ranking);
                break;
            }  
        }  
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
    int totalCompetidores = 0;
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {

        if (strcmp(buffer, "\n") == 0) {            //Por algum motivo tá lendo o raio de 2 '\n'

            if (nEntrada >= 0) {     // Limpando a memória para cada entrada diferente
                classificacao(competidor);
                classificarCompetidores(competidor, totalCompetidores);      // TEM ERRO AQUI

                // exibeClassificacaoTabular(competidor);
                exibeClassificacao(competidor, totalCompetidores);

                iniciaCompetidores(competidor);     // É preciso reiniciar a estrutura de dados a cada entrada
            }
            nEntrada++;
            printf("\n");
            totalCompetidores = 0;
        
        } else {
            sscanf(buffer, "%d %d %d %c", &nCompetidor, &nProblema, &tempo, &nota);
            
            if (competidor[nCompetidor-1] == NULL) {      // Caso o competidor ainda não tenha sido cadastrado, ele será
                competidor[nCompetidor-1] = (Desafios *)malloc(sizeof(Desafios));

                iniciaVetor(competidor[nCompetidor-1]->problemasSumetidos, 8);
                competidor[nCompetidor-1]->ranking = -1;
                competidor[nCompetidor-1]->tempoTotal = 0;
                competidor[nCompetidor-1]->problemasResolvidos = 0;

                /* Todos os problemas devem ser iniciados! */
                for (int i = 0; i < 9; i++) {
                    competidor[nCompetidor-1]->problema[i].tempo = 0;
                    competidor[nCompetidor-1]->problema[i].penalidade = 0;
                    competidor[nCompetidor-1]->problema[i].nota = 'Z';
                }
                totalCompetidores++;
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

    classificacao(competidor);
    classificarCompetidores(competidor, totalCompetidores);

    // exibeClassificacaoTabular(competidor);
    exibeClassificacao(competidor, totalCompetidores);

    liberaMemoria(competidor);

    return 0;
}
