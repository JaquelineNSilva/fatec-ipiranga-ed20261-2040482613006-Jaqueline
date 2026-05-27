//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 3 - B

#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {

    // caso base
    if (n == 1) {

        printf("Mover disco 1 de %c para %c\n",
               origem, destino);

        movimentos++;

        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);

    printf("Mover disco %d de %c para %c\n",
           n, origem, destino);

    movimentos++;

    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {

    for (int n = 1; n <= 6; n++) {

        movimentos = 0;

        printf("\nTeste com n = %d\n\n", n);

        hanoi(n, 'A', 'C', 'B');

        printf("\nMovimentos contados: %d\n",
               movimentos);

        printf("Valor esperado: %d\n",
               (1 << n) - 1);

        printf("---------------------------------------\n");
        printf("---------------------------------------\n");
    }

    /*
        Tabela de complexidade

        n = 1 -> 1 movimento
        n = 2 -> 3 movimentos
        n = 3 -> 7 movimentos
        n = 4 -> 15 movimentos
        n = 5 -> 31 movimentos
        n = 6 -> 63 movimentos

        Foi observado que a quantidade
        de movimentos segue a formula:

        2^n - 1
    */

    return 0;
}