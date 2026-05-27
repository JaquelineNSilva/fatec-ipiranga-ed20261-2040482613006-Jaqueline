//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 4 - A


#include <stdio.h>

int chamadas = 0;

//Retorna o indice do elemento se encontrado, ou -1 caso contrario.

int buscaBinaria(int *vet, int inicio, int fim, int alvo) {

    chamadas++;

    // caso base: elemento nao encontrado
    if (inicio > fim) {

        return -1;
    }

    int meio = (inicio + fim) / 2;

    // caso base: elemento encontrado
    if (vet[meio] == alvo) {

        return meio;
    }

    // busca na metade esquerda
    if (alvo < vet[meio]) {

        return buscaBinaria(vet, inicio, meio - 1, alvo);
    }

    // busca na metade direita
    return buscaBinaria(vet, meio + 1, fim, alvo);
}

int main() {

    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};

    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int valores[] = {23, 50, 2};

    for (int i = 0; i < 3; i++) {

        chamadas = 0;

        int resultado = buscaBinaria(dados, 0, tamanho - 1,valores[i]);

        printf("\nValor buscado: %d\n", valores[i]);

        if (resultado != -1) {

            printf("Indice encontrado: %d\n", resultado);

        } else {

            printf("Indice: nao encontrado (-1)\n");
        }

        printf("Chamadas recursivas: %d\n\n", chamadas);
        printf("---------------------------\n");
    }

    return 0;
}