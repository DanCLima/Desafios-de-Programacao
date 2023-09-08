#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int tempo;
    char nota;
} Problema;

typedef struct {
    Problema problema[8];
} Desafios;

void cadastraCompetidor(Desafios *competidor, int nProblema, int tempo, char nota) {
    competidor->problema[nProblema].tempo = tempo;
    competidor->problema[nProblema].nota = nota;
}

int main(int argc, char const *argv[]) {   
    Desafios *competidor[100];

    int entrada, nCompetidor, nProblema, tempo, nota, nEntrada;

    // Aloque memória para os competidores
    for (int i = 0; i < 2; i++) {
        competidor[i] = (Desafios *)malloc(sizeof(Desafios));
    }

    cadastraCompetidor(competidor[0], 0, 10, 'C');
    cadastraCompetidor(competidor[1], 0, 15, 'I');
    printf("Competidor %d problema %d tempo %d nota %c\n", 0, 0, competidor[0]->problema[0].tempo, competidor[0]->problema[0].nota);
    printf("Competidor %d problema %d tempo %d nota %c\n", 0, 0, competidor[1]->problema[0].tempo, competidor[1]->problema[0].nota);
    printf("Competidor 2 eh NULL? %s", competidor[3] == NULL ? "Sim" : "Nao");

    // // Libere a memória alocada para os competidores
    // for (int i = 0; i < 100; i++) {
    //     free(competidor[i]);
    // }
    
    return 0;
}
