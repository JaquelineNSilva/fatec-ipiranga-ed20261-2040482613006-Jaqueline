//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 3 - C


#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {

    // Caso base: apenas 1 disco, faz o movimento direto
    if (n == 1) {

        // Imprime espacos proporcionais ao nivel atual
        for (int i = 0; i < nivel * 2; i++) {
            printf(" ");
        }

        printf("Nivel %d -> mover disco 1 de %c para %c\n",
               nivel,
               origem,
               destino);

        movimentos++;

        return;
    }

    // Move os (n-1) discos superiores para o auxiliar
    // aprofunda mais um nivel na recursao
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    // Move o disco maior para o destino
    for (int i = 0; i < nivel * 2; i++) {
        printf(" ");
    }

    printf("Nivel %d -> mover disco %d de %c para %c\n",
           nivel,
           n,
           origem,
           destino);

    movimentos++;

    // Move os (n-1) discos do auxiliar para o destino
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {

    int testes[] = {1, 3, 4};
    int qtd = 3;

    for (int i = 0; i < qtd; i++) {

        int n = testes[i];

        movimentos = 0; // zera o contador antes de cada teste

        printf("\nHanoi com %d disco(s):\n\n", n);

        hanoi(n, 'A', 'C', 'B', 0);

        printf("\nTotal de movimentos: %d\n", movimentos);
        
        printf ("\n-------------------------------------");
        printf ("\n-------------------------------------");
    }

    return 0;
}