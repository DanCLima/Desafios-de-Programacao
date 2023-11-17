/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   Problema 15                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   12/11/2023                               |
+----------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int contar_subsequencias(char X[], char Z[]) {
    int m = strlen(X);
    int k = strlen(Z);
    int dp[m + 1][k + 1];

    for (int i = 0; i <= m; i++) { 
        dp[i][0] = 1;
    }

    for (int i = 1; i <= k; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (X[i - 1] == Z[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][k];
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char X[10001], Z[101];
        scanf("%s %s", X, Z);
        printf("%d\n", contar_subsequencias(X, Z));
    }

    return 0;
}
