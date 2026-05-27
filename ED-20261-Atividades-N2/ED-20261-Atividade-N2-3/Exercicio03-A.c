//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 3 - A


#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar) {

    // caso base
    if (n == 1) {

        printf("Mover disco 1 de %c para %c\n",
               origem, destino);

        return;
    }

    // move os discos menores para auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    printf("Mover disco %d de %c para %c\n",
           n, origem, destino);

    // move os discos para destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {

    int n = 3;

    hanoi(n, 'A', 'C', 'B');

    return 0;
}