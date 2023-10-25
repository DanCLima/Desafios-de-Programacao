/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 13                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   25/10/2023                               |
+----------------------------------------------------------------*/
#include <stdio.h>

#define MAX_VERTICES 200

typedef struct {
    int visitado;
    int cor;
    int vizinhos[MAX_VERTICES];
} Node;

/* Inicia a struct Node */
void iniciar_node (Node *n) {
    n->cor = -1 ;
    n->visitado = 0;
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        n->vizinhos[i] = 0;
    }
}

/* Exibe o grafo */
void printar_grafo (Node *n, int n_vertices) {
    for (int i = 0; i < n_vertices; i++) {
        printf("Node: %d\n", i);
        printf("Visitado: %d\n", n[i].visitado);
        printf("Cor: %d\n", n[i].cor);
        printf("Vizinhos: ");

        for (int j = 0; j < n_vertices; j++) {
            if (n[i].vizinhos[j] == 1){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    puts("");
}

/* Realiza a leitura de cada aresta no grafo e armazena na struct */
void ler_node (Node *n, int n_vertices, int n_arestas) {
    for (int i = 0; i < n_vertices; i++) {
        iniciar_node(&n[i]);
    }
    
    for (int i = 0, x, y; i < n_arestas; i++) {
        scanf("%d %d", &x, &y);

        n[x].vizinhos[y] = 1;
        n[y].vizinhos[x] = 1;
    }
}

/* Realiza uma busca em largura colorindo os vértices. O vértice inicial recebe a "cor" 0, e os seus vizinhos recebem a "cor" 1, 
desde que ainda não tenham sido visitados. Se em algum momento um vértice possuir a mesma cor que seus vizinhos, isso indica que 
o grafo não é bicolorível.*/
void verificar_bicoloracao (Node *n, int n_vertices) {
    for (int i = 0; i < n_vertices; i++) {
        if (n[i].visitado == 0) {       // Verificação para os vértices que não foram visitados
            n[i].cor = 0;
            n[i].visitado = 1;

            for (int j = 0; j < n_vertices; j++) {
                if (n[i].vizinhos[j] == 1) {        //  Identificando os vizinhos (vetor armazena 1 para o indíce correspondente aos vértices adjacentes)
                    if (n[j].visitado == 0) {
                        n[j].cor = 1 - n[i].cor;
                        n[j].visitado = 1;
                    } else {
                        if (n[i].cor == n[j].cor) {
                            printf("NOT BICOLORABLE.\n");
                            return;
                        }
                    }
                }
            }
        } else {        // Verificação para os vértices já foram visitados
            for (int j = 0; j < n_vertices; j++) {
                if (n[i].vizinhos[j] == 1) {
                    if (n[j].visitado == 0) {
                        n[j].cor = 1 - n[i].cor;
                        n[j].visitado = 1;
                    } else {
                        if (n[i].cor == n[j].cor) {
                            printf("NOT BICOLORABLE.\n");
                            return;
                        }
                    }
                }
            }
        }
    }
    
    printf("BICOLORABLE.\n");
}

int main(int argc, char const *argv[])
{
    Node grafo[MAX_VERTICES];
    int n_vertices, n_arestas, x, y;

    while (scanf("%d", &n_vertices) != EOF) {

        if (n_vertices == 0){
            break;
        }

        scanf("%d", &n_arestas);  
        
        ler_node(grafo, n_vertices, n_arestas);
        verificar_bicoloracao(grafo, n_vertices);

        // printar_grafo(grafo, n_vertices);
    }

    return 0;
}