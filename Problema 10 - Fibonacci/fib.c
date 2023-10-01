/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 10                               |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   01/10/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#define MAX 100
#define MAX_FIB 477

typedef struct {
    char digits[MAX];
    int lastdigit;
} bignum;

int max(int a, int b) {
    return a > b ? a : b;
}

void init(bignum *a) {
    for (int i = 0; i < MAX; i++)
        a->digits[i] = 0;
    a->lastdigit = -1;
}

void add(bignum *a, bignum *b, bignum *c) {
    int carry = 0;
    init(c);
    c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
    for (int i = 0; i <= c->lastdigit; i++)
    {
        c->digits[i] = (char)(carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    while (c->digits[c->lastdigit] == 0)
        c->lastdigit--;
}

/* return -1, if a < b
   return 1, if a > b
   return 0, if a == b*/
int compare(bignum a, bignum b) {
    if (a.lastdigit > b.lastdigit) {
        return 1;
    } else if (a.lastdigit < b.lastdigit) {
        return -1;
    } else {
        /* A comparação deve ser feita do dígito mais significativo ao menos significatiov */
        for (int i = a.lastdigit; i >= 0; i--) {
            if (a.digits[i] > b.digits[i]) {
                return 1;
            } else if (a.digits[i] < b.digits[i]) {
                return -1;
            }
        }
        return 0; 
    }
}

void setnum(char *s, bignum *a) {
    int i, j;
    init(a);
    for (i = 0; s[i]; i++)
        ;
    for (j = 0, i--; i >= 0; i--, j++)
        a->digits[j] = s[i] - '0';
    a->lastdigit = j - 1;
}

void println(bignum a) {
    for (int i = a.lastdigit; i >= 0; i--)
        printf("%c", '0' + a.digits[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char a[150];
    char b[150];
    bignum num1;
    bignum num2;
    bignum fibonacci[MAX_FIB];

    init(&num1);
    init(&num2);

    for (int i = 0; i < MAX_FIB; i++) {
        init(&fibonacci[i]);
    }

    /* Dois primeiros valores da sequência de Fibonnaci */
    setnum("0", &fibonacci[0]);
    setnum("1", &fibonacci[1]);

    /* Sêquencia dos primeiros 477 números de Fibonacci */
    for (int i = 2; i < MAX_FIB; i++) {
        add(&fibonacci[i-2], &fibonacci[i-1], &fibonacci[i]);
    }

    while (scanf("%s %s", a, b) != EOF) {
        if (!((a[0] == '0') && (b[0] == '0'))) {
            setnum(a, &num1);
            setnum(b, &num2);

            int cont = 0;
            /* O loop iniciando em 2 vai anular o fib = 0 e a repetição do fib = 1 */
            for (int i = 2; i < MAX_FIB; i++) {
                if (compare(num2, fibonacci[i]) == 1 || compare(num2, fibonacci[i]) == 0) {
                    if (compare(fibonacci[i], num1) == 1 || compare(fibonacci[i], num1) == 0) {
                        cont++;
                    }
                } else {
                    break;
                }
            }
            printf("%d\n", cont);
        }
    }
    
    return 0;
}
