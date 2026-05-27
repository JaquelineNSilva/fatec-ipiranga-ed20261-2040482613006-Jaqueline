//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 2 


#include <stdio.h>

/* Calcula e retorna a media aritmetica */
float calcularMedia(float *vet, int n) {

    float soma = 0;

    for (float *ptr = vet; ptr < vet + n; ptr++) {

        soma += *ptr;
    }

    return soma / n;
}

/* Encontra o maior e o menor valor */
void encontrarExtremos(float *vet, int n, float *maior, float *menor) {

    *maior = *vet;
    *menor = *vet;

    for (float *ptr = vet; ptr < vet + n; ptr++) {

        if (*ptr > *maior) {

            *maior = *ptr;
        }

        if (*ptr < *menor) {

            *menor = *ptr;
        }
    }
}

/* Normaliza o vetor: cada elemento eh dividido pelo valor do maximo */
void normalizar(float *vet, int n) {

    float maior = *vet;

    for (float *ptr = vet; ptr < vet + n; ptr++) {

        if (*ptr > maior) {

            maior = *ptr;
        }
    }

    for (float *ptr = vet; ptr < vet + n; ptr++) {

        *ptr = *ptr / maior;
    }
}

/* Imprime o vetor */
void imprimirVetor(float *vet, int n, const char *titulo) {

    printf("%s\n\n", titulo);

    for (float *ptr = vet; ptr < vet + n; ptr++) {

        printf("%.2f ", *ptr);
    }

    printf("\n\n");
}

int main() {

    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    int tamanho = sizeof(notas) / sizeof(notas[0]);

    float media;
    float maior;
    float menor;

    imprimirVetor(notas, tamanho, "Valores antes da normalizacao:");

    media = calcularMedia(notas, tamanho);

    encontrarExtremos(notas, tamanho, &maior, &menor);

    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n\n", menor);

    normalizar(notas, tamanho);

    imprimirVetor(notas, tamanho, "Valores apos normalizacao (dividir pela maior media):");

    /*
       A funcao normalizar altera o vetor original porque
       foi passado o endereco de memoria do vetor para a funcao.
       Dessa forma, qualquer alteracao feita usando ponteiros
       modifica diretamente os valores originais.
    */

    return 0;
}