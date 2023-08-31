#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int vol = 7;
    int qtdComandos;
    char comandos[10];

    scanf("%d", &qtdComandos);
    getchar();      // Consome o '\n'

    for (int i = 0; i < qtdComandos; i++) {
        fgets(comandos, sizeof(comandos), stdin);       // Se a entrada for redirecionada de um arquivo, o caracter '\n' deve ser removido da string
        int tam = strlen(comandos);     

        // Verifica se o o último caracter lido é uma quebra de linha e o remove
        if (tam > 0 && comandos[tam-1] == '\n') {
            tam--;
            comandos[tam] = '\0';      
        }

        if (tam == 8 && vol < 10) {
            vol++;
        } else if (tam == 9 && vol > 0) {
            vol--;
        }
        comandos[0] = '\0';
    }
    printf("%d", vol);
    
    return 0;
}