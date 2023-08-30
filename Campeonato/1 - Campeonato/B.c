#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int vol = 7;
    int qtdComandos;
    char comandos[10];

    scanf("%d", &qtdComandos);
    // printf("qtd comandos eh: %d\n", qtdComandos);

    
    for (int i = 0; i < qtdComandos; i++) {
        scanf_s(" %s", &comandos);
        int tam = strlen(comandos);
        printf("\n tam eh %d\n", tam);

        
        if (comandos[4] == 'u'&& vol >= 0 && vol < 10) {
            vol++;
        } else if (comandos[4] == 'd'&& vol > 0 && vol <= 10) {
            vol--;
        }
        comandos[0] = '\0';
        printf("%d\n", i);

    }

    printf("%d", vol);

    
    return 0;
}
