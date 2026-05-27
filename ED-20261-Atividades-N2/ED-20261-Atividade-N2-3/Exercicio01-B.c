//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 1 - B


#include <stdio.h>

int main() {

    int v[] = {10, 20, 30, 40, 50};

    // ponteiro apontando para o primeiro elemento do vetor
    int *inicio = v;

    // ponteiro apontando para o ultimo elemento do vetor
    int *fim = v + 4;

    int soma = 0;

    printf("Numeros do vetor:\n\n");

    // ptr percorre o vetor usando aritmetica de ponteiros
    for (int *ptr = v; ptr <= v + 4; ptr++) {

        // *ptr acessa o valor armazenado no endereco atual
        printf("Valor: %d\n", *ptr);

        // ptr representa o endereco do elemento atual
        printf("Endereco: %p\n\n", ptr);

        // *ptr acessa o valor para somar
        soma += *ptr;
    }

    printf("Soma dos elementos: %d\n\n", soma);

    printf("---- Invertendo vetor ----\n\n");

    while (inicio < fim) {

        // *inicio acessa o valor do comeco do vetor
        // *fim acessa o valor do final do vetor
        int temp = *inicio;

        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }

    printf("Vetor invertido:\n\n");

    for (int *ptr = v; ptr <= v + 4; ptr++) {

        // *ptr acessa o valor do elemento atual
        printf("%d ", *ptr);
    }

    printf("\n");

    return 0;
}