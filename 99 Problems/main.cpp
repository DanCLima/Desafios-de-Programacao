/*---------------------------------------------------------------+
|            UNIFAL - Universidade Federal de Alfenas            |
|              BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO              |
|       Trabalho....:   99 Problems                              |
|       Disciplina..:   Desafios de Programação                  |
|       Professor...:   Luiz Eduardo da Silva                    |
|       Aluno.......:   Daniel da Costa Lima                     |
|       Data........:   16/11/2023                               |
+----------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>

using namespace std;

int encontrar_menor(int num) {
    int i = 0, j = 1;
    
    if (num < 1000) {
        for (; num >= 10;) {
            num = num/10;
            i = i * 10;
            i += 9;
            j *= 10;
        }
    } else {
        for (; num >= 100;) {
            num = num/10;
            i = i * 10;
            i += 9;
            j *= 10;
        }
    }
    
    // Se o resto da div for 1, é preciso retornar a seq de 9
    if (num == 1) {
        return i;
    } else {        // Caso contrário, retornar o 1 + seq de 9
        return j * (num-1) + i;
    }
    
}

void depurar (int valor, int menor_valor, int num) {
    cout << "Valor: " << num << endl;
    cout << "Limite inferior: ["<< menor_valor << "] distância: " << abs(menor_valor - num) << endl;
    cout << "Limite superior: [" << valor << "] distância: " << abs(valor - num) << endl;
    cout << "Resultado: ";
}

int main(int argc, char const *argv[])
{
    int num, resto, valor;

    while (cin >> num) {
        if (num < 100 ) {
            cout << "99" << endl;
        } else {
            resto = num % 100;
            valor = 99 - resto;
            valor += num;

            // Sempre será menor do que o "valor"
            int menor_valor = encontrar_menor(num);

            depurar(valor, menor_valor, num);

            if (abs(menor_valor - num) < abs(valor-num)) {
                cout << menor_valor << endl;
            } else {
                cout << valor << endl;
            }    

        }
    }
    
    return 0;
}