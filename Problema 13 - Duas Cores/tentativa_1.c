#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 10

typedef struct  {
    int matriz_adj[MAX_VERTICES][MAX_VERTICES];
    int n_vertices;
    int n_arestas;
} grafo;

void inicia_grafo (grafo *g) {
    g->n_arestas = 0;
    g->n_vertices = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->matriz_adj[i][j] = 0;
        }
    }
}

void printar_grafo (grafo *g) {
    for (int i = 0; i < g->n_vertices; i++) {
        for (int j = 0; j < g->n_vertices; j++) {
            // if (i > j) {
            //     printf("- ");
            // } else {
                printf("%d ", g->matriz_adj[i][j]);
            // }
        }
        puts("");
    } 
    puts("");
}

int verificar_bicoloracao (grafo *g) {
    int eh_bicolor = 1;
    int cor[MAX_VERTICES];

    for (int i = 0; i < MAX_VERTICES; i++) {
        cor[i] = -1;
    }
    
    for (int i = 0; i < g->n_vertices; i++) {
        if (cor[i] == -1) {     // Atribui a cor inicial ao primeiro vétice
            cor[i] = 0;

            for (int j = 0; j < g->n_vertices; j++) {
                if (g->matriz_adj[i][j] == 1) {    
                    if (cor[j] == -1) {
                        cor[j] = 1 - cor[i];        // Atribuindo a outra cor ao vértice adjacente
                    } else if (cor[j] == cor[i]) {      // Se os vertices adjacentes possuírem a mesma cor, não pode ser colorido com duas cores
                        eh_bicolor = 0;
                        return eh_bicolor;
                    }
                }
            } 
        } 
    }
    return eh_bicolor;
}

void le_grafo (grafo *g, int n_vertices, int n_arestas) {
    inicia_grafo(g);

    g->n_arestas = n_arestas;
    g->n_vertices = n_vertices;

    for (int i = 0, x, y; i < n_arestas; i++) {
        scanf("%d %d", &x, &y);
        g->matriz_adj[x][y] = 1;
        g->matriz_adj[y][x] = 1;
    }
}

int main(int argc, char const *argv[])
{
    int vertices, qtd_arestas, x, y;
    grafo duas_cores;

    while (scanf("%d", &vertices) != EOF) {

        if (vertices == 0){
            break;
        }

        scanf("%d", &qtd_arestas);  
          
        le_grafo(&duas_cores, vertices, qtd_arestas);

        int verifica = verificar_bicoloracao(&duas_cores);
        if (verifica == 1) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }
        printar_grafo(&duas_cores);

    }

    return 0;
}
