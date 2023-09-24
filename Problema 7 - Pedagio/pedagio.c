#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6

typedef struct {
    char placa[20];
    int dia;
    int hora;
    int sentido;        // 0 - entrar na rodovia 1 - sair da rodovia
    int km;
} Viagem;

Viagem registros[MAX];
int ordem[MAX];

void iniciaViagem (Viagem *v) {
    for (int i = 0; i < MAX; i++) {
        v[i].placa[0] = '\0';
        v[i].dia = -1;
        v[i].hora = -1;
        v[i].sentido = -1;
        v[i].km = -1;
    }
}

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

void exibeViagem (Viagem *v) {
    for (int i = 0; i < MAX; i++) {
        printf("Registro %d\n", i);
        printf("Placa: %s\n", v[i].placa);
        printf("Dia: %d\n", v[i].dia);
        printf("Hora: %d\n", v[i].hora);
        printf("Sentido: %d\n", v[i].sentido);
        printf("Km: %d\n", v[i].km);
        printf("\n");
    }
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

void iniciaOrdem (int *ordem) {
    for (int i = 0; i < MAX; i++) {
        ordem[i] = i;
    }
}

int ordenaPlaca(const void *a, const void *b) {
    int indice1 = *(int *)a;
    int indice2 = *(int *)b;
    int retorno;

    retorno = strcmp(registros[indice1].placa, registros[indice2].placa);
    if (retorno == 0) {     // Quer dizer que as placas são iguais, então devemos considerar outros critérios
        retorno = (registros[indice1].dia - registros[indice2].dia);
        if (retorno == 0) {     // Para os dis iguais, ordenaremos as horas
            retorno = (registros[indice1].hora - registros[indice2].hora);
        } 
    }
    
    return retorno;
}


void ordena (Viagem *v, int *ordem) {
    qsort(ordem, MAX, sizeof(int), ordenaPlaca);

    for (int i = 0; i < MAX; i++) {
        int indice = ordem[i]; // O índice ordenado

        printf("Registro %d\n", indice);
        printf("Placa: %s\n", v[indice].placa);
        printf("Dia: %d\n", v[indice].dia);
        printf("Hora: %d\n", v[indice].hora);
        printf("Sentido: %d\n", v[indice].sentido);
        printf("Km: %d\n", v[indice].km);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int entrada;
    int taxas[24];
    int mes, dia, hora, segundo, km;
    int contaEntrada, contaRegistro;
    char buffer[100];
    char sentido[6]; // Entrada ou saida
    char placa[21];

    scanf("%d", &entrada);
    getchar();
 
    iniciaViagem(registros);   
    iniciaOrdem(ordem); 

    contaEntrada = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int tam = removeQuebraLinha(buffer);

        if (buffer[0] == '\n') {
            contaEntrada++;
            contaRegistro = 0;      // Sempre que houver uma nova entrada o conta registro deve ser zerado

            if (contaEntrada > 1) {
                printf("\n"); 
                // exibeViagem(registros);     // Exibindo os registros da entrada anterior

                ordena(registros, ordem);
                // exibeViagem(registros);   

                iniciaViagem(registros);       // Reiniciando a struct para a nova entrada
                }
                    
            printf("Entrada %d\n", contaEntrada);
            /* Lendo as taxas */
            scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &taxas[0], &taxas[1], &taxas[2], &taxas[3], 
                &taxas[4], &taxas[5], &taxas[6], &taxas[7], &taxas[8], &taxas[9], &taxas[10], &taxas[11], &taxas[12], &taxas[13], &taxas[14],
                &taxas[15], &taxas[16], &taxas[17], &taxas[18], &taxas[19], &taxas[20], &taxas[21], &taxas[22], &taxas[23]);

            /* Exibindo as taxas */
            printf("Taxas: ");
            for (int i = 0; i < 24; i++) {
                printf("%d ", taxas[i]);
            }
            printf("\n");
            entrada--;
        } else {
            sscanf(buffer, "%s %d:%d:%d:%d %s %d", placa, &mes, &dia, &hora, &segundo, sentido, &km);
            cadastraViagem(&registros[contaRegistro], placa, dia, hora, (strcmp(sentido, "enter") == 0 ? 0 : 1), km, (contaRegistro));
            contaRegistro++;
        } 
    }
    ordena(registros, ordem);
    // exibeViagem(registros); 


    return 0;
}