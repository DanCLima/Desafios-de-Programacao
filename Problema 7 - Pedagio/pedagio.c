/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 7                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   25/09/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000

typedef struct {
    char placa[21];
    int dia;
    int hora;
    int sentido;        // 0 - entrar na rodovia (enter)        1 - sair da rodovia (exit)
    int km;
    int contabilizado;      // 0 - não foi usado na soma geral      1 - foi usado na soma geral
    float valor;      
} Viagem;

Viagem registros[MAX];

/* Inicia a struct */
void iniciaViagem (Viagem *v) {
    for (int i = 0; i < MAX; i++) {
        v[i].placa[0] = '\0';
        v[i].dia = -1;
        v[i].hora = -1;
        v[i].sentido = -1;
        v[i].km = -1;
        v[i].contabilizado = 0;
        v[i].valor = 0.0;
    }
}

/* Insere um registro na struct */
void cadastraViagem (Viagem *v, char *placa, int dia, int hora, int sentido, int km, int indice) {
    if (indice >= MAX) {
        printf("Limite de viagens atingido!\n");
        return;
    }
    
    strcpy(v->placa, placa);
    v->dia = dia;
    v->hora = hora;
    v->sentido = sentido;
    v->km = km;
}

/* Remove a quebra de linha da entrada e retorna o tamanho da string */
int removeQuebraLinha (char *buffer) {
    int tam = strlen(buffer);

    if (buffer[tam-1] == '\n' && tam > 1) {
        buffer[tam-1] = '\0';
        tam--;
    }
    return tam;
}

/* Inicia o vetor ordem */
void iniciaOrdem (int *ordem, int qtdRegistro) {
    for (int i = 0; i < qtdRegistro; i++) {
        ordem[i] = i;
    }
}

/* 
    Realiza a ordenação do vetor que contém os índices das structs de acordo com alguns critérios:
        1 - Placa
        2 - Dia
        3 - Hora
 */
int ordenaPlaca(const void *a, const void *b) {
    int indice1 = *(int *)a;
    int indice2 = *(int *)b;
    int retorno;

    retorno = strcmp(registros[indice1].placa, registros[indice2].placa);
    if (retorno == 0) {     // Se as placas são iguais, então devemos considerar outros critérios
        retorno = (registros[indice1].dia - registros[indice2].dia);
        if (retorno == 0) {     // Se os dias são iguais, consideraremos as horas
            retorno = (registros[indice1].hora - registros[indice2].hora);
        } 
    }
    
    return retorno;
}

/* Utiliza o quick-sort para ordenador o vetor de índices */
void ordena (Viagem *v, int *ordem, int qtdRegistro) {
    qsort(ordem, qtdRegistro, sizeof(int), ordenaPlaca);
}

/* DEPURAÇÃO - exibe a struct */
void exibeViagem (Viagem *v, int *ordem, int qtdRegistros) {
        printf("\n");

    for (int i = 0; i < qtdRegistros; i++) {
        int indice = ordem[i]; // O índice ordenado

        printf("Registro %d\n", indice);
        printf("Placa: %s\n", v[indice].placa);
        printf("Dia: %d\n", v[indice].dia);
        printf("Hora: %d\n", v[indice].hora);
        printf("Sentido: %d\n", v[indice].sentido);
        printf("Km: %d\n", v[indice].km);
        printf("Valor: %.3f\n", v[indice].valor);
        printf("\n");
    }
}

/* Calcula o valor do pedágio de acordo com a lógica do problema */
void calculaPedagio (Viagem *v, int *ordem, int *taxas, int qtdRegistro) {
    for (int i = 0; i < qtdRegistro-1; i++) {
        float taxaAtual = 0.0;
        int indice1 = ordem[i];
        int indice2 = ordem[i+1];

        if (strcmp(v[indice1].placa, v[indice2].placa) == 0 && v[indice1].sentido != v[indice2].sentido) {
            /* Calcula o pedágio e armazena sempre na struct com o sentido enter (0)*/
            if (v[indice1].sentido == 0) {
                taxaAtual = (taxas[v[indice1].hora])/100.00;       // A taxa muda de acordo com o horário. O horário corresponde aos índices do vetor taxas
                v[indice1].valor += taxaAtual * abs(v[indice1].km - v[indice2].km);     // Realiza o cálculo do pedágio
            }
        }
    }

    /* O objetivo dessa repetição é passar por todas as viagens válidas e armazenar a soma dos valores no primeiro registro da placa */
    for (int i = 0; i < qtdRegistro-1; i++) {
        int indice1 = ordem[i];     // Ajusta o índice, porque seguimos o vetor que ordenou os registros
        float contaViagens = 1.0;

        /* Verifica se a primeira estrutura está no sentido enter (0) */
        if (v[indice1].contabilizado == 0 && v[indice1].sentido == 0 && v[indice1].valor != 0) {

            for (int j = i+1; j < qtdRegistro; j++) {
                int indice2 = ordem[j];
                
                /* O segundo registro deve possuir um valor válido sentido enter - 0 */
                if (strcmp(v[indice1].placa, v[indice2].placa) == 0 && v[indice2].contabilizado == 0 && v[indice2].sentido == 0) {

                    if (v[indice2].valor != 0) {
                        v[indice1].valor += v[indice2].valor;  
                        v[indice2].valor = 0.0;       // Assim que o valor for somado ao primeiro registro, os outros devem ser zerados
                        contaViagens++;  
                    }
                    
                    v[indice2].contabilizado = 1;       // O valor da struct já foi somado à primeira struct com a mesma placa
                    
                }
            }
            v[indice1].valor += contaViagens + 2;       // Cada viagem custa 1 dolar e cada conta tem uma taxa de 2 dolares
            v[indice1].contabilizado = 1;
        }
    }
}

/* Exibe a saída de acordo com o proposto pelo exercício */
void saidaEsperada (Viagem *v, int *ordem, int qtdRegistro) {
    for (int i = 0; i < qtdRegistro; i++) {
        int indice = ordem[i];

        if (v[indice].valor != 0) {
            printf("%s $%.2f\n", v[indice].placa, v[indice].valor);
        }
    }
}

int main(int argc, char const *argv[])
{
    int entrada;
    int taxas[24];
    int mes, dia, hora, segundo, km;
    int contaEntrada, contaRegistro;
    char buffer[100];
    char sentido[6]; // Entrada - 0     saida - 1
    char placa[21];
    int *ordem;     // Vetor que irá guardar a ordenação das structs

    scanf("%d", &entrada);
    getchar();
 
    iniciaViagem(registros);   

    contaEntrada = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int tam = removeQuebraLinha(buffer);

        if (buffer[0] == '\n') {
            contaEntrada++;

            if (contaEntrada > 1) {
                if (contaEntrada > 2) {
                    printf("\n"); 
                }

                /* O vetor ordem é alocado de acordo com a quantidade de registros */
                ordem = (int*)malloc(sizeof(int) * contaRegistro); 
                iniciaOrdem(ordem, contaRegistro); 
                ordena(registros, ordem, contaRegistro);
                calculaPedagio(registros, ordem, taxas, contaRegistro);
                // exibeViagem(registros, ordem, contaRegistro);
                saidaEsperada(registros, ordem, contaRegistro);
                free(ordem);

                /* Reinicia a struct para a nova entrada */
                iniciaViagem(registros);       
            }
            contaRegistro = 0;      // Sempre que houver uma nova entrada, o conta registro deve ser zerado
    
            /* Lendo as taxas */
            scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &taxas[0], &taxas[1], &taxas[2], &taxas[3], 
                &taxas[4], &taxas[5], &taxas[6], &taxas[7], &taxas[8], &taxas[9], &taxas[10], &taxas[11], &taxas[12], &taxas[13], &taxas[14],
                &taxas[15], &taxas[16], &taxas[17], &taxas[18], &taxas[19], &taxas[20], &taxas[21], &taxas[22], &taxas[23]);

            /* Exibindo as taxas */
            // printf("Taxas: ");
            // for (int i = 0; i < 24; i++) {
            //     printf("%d ", taxas[i]);
            // }
            // printf("\n");
            entrada--;
        } else {
            sscanf(buffer, "%s %d:%d:%d:%d %s %d", placa, &mes, &dia, &hora, &segundo, sentido, &km);
            cadastraViagem(&registros[contaRegistro], placa, dia, hora, (strcmp(sentido, "enter") == 0 ? 0 : 1), km, (contaRegistro));
            contaRegistro++;
        } 
    }
    printf("\n"); 

    ordem = (int*)malloc(sizeof(int) * contaRegistro); 
    iniciaOrdem(ordem, contaRegistro); 
    ordena(registros, ordem, contaRegistro);
    calculaPedagio(registros, ordem, taxas, contaRegistro);
    // exibeViagem(registros, ordem, contaRegistro);
    saidaEsperada(registros, ordem, contaRegistro);
    free(ordem);

    return 0;
}