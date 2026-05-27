//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 1 - A


#include <stdio.h>

void trocar(int *a, int *b) {

    // *a acessa o valor armazenado no endereco apontado por a
    *a = *a + *b;

    // *b acessa o valor armazenado no endereco apontado por b
    *b = *a - *b;

    // *a acessa novamente o valor no endereco apontado por a
    *a = *a - *b;
}

int main() {

    int num1 = 10;
    int num2 = 20;

    printf("Antes da troca:\n\n");

    // &num1 retorna o endereco de memoria da variavel num1
    printf("Endereco de num1: %p\n", &num1);

    // &num2 retorna o endereco de memoria da variavel num2
    printf("Endereco de num2: %p\n", &num2);

    printf("Valor de num1: %d\n", num1);
    printf("Valor de num2: %d\n\n", num2);

    // &num1 envia o endereco de memoria de num1
    // &num2 envia o endereco de memoria de num2
    trocar(&num1, &num2);

    printf("Depois da troca:\n\n");

    // &num1 retorna o endereco de memoria da variavel num1
    printf("Endereco de num1: %p\n", &num1);

    // &num2 retorna o endereco de memoria da variavel num2
    printf("Endereco de num2: %p\n", &num2);

    printf("Valor de num1: %d\n", num1);
    printf("Valor de num2: %d\n", num2);

    return 0;
}