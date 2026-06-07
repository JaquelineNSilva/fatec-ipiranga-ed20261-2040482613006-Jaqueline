#include <stdio.h>
#include "minhabib.h"

static No* buscar_no(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar_no(raiz->esq, valor);

    return buscar_no(raiz->dir, valor);
}

static void mostrar_nivel(No* raiz, int nivelDesejado, int nivelAtual) {
    if (raiz == NULL)
        return;

    if (nivelAtual == nivelDesejado)
        printf("%d ", raiz->valor);

    mostrar_nivel(raiz->esq, nivelDesejado, nivelAtual + 1);
    mostrar_nivel(raiz->dir, nivelDesejado, nivelAtual + 1);
}

static void imprimir_subarvore(No* raiz, int espaco) {
    if (raiz == NULL)
        return;

    espaco += 5;

    imprimir_subarvore(raiz->dir, espaco);

    printf("\n");

    for (int i = 5; i < espaco; i++)
        printf(" ");

    printf("%d\n", raiz->valor);

    imprimir_subarvore(raiz->esq, espaco);
}

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

int calcular_altura(No* no) {
    if (no == NULL)
        return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    return (esq > dir ? esq : dir) + 1;
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL)
        return -1;

    if (raiz->valor == valor)
        return profundidade_atual;

    if (valor < raiz->valor)
        return calcular_profundidade(
            raiz->esq,
            valor,
            profundidade_atual + 1
        );

    return calcular_profundidade(
        raiz->dir,
        valor,
        profundidade_atual + 1
    );
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL)
        return;

    if (raiz->valor == valor)
        return;

    if (valor < raiz->valor)
        imprimir_ancestrais(raiz->esq, valor);
    else
        imprimir_ancestrais(raiz->dir, valor);

    printf("%d ", raiz->valor);
}

void imprimir_descendentes(No* no) {
    if (no == NULL)
        return;

    if (no->esq != NULL) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if (no->dir != NULL) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    int altura = calcular_altura(raiz);

    (void)nivel_atual;

    for (int i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        mostrar_nivel(raiz, i, 0);
        printf("\n");
    }
}

void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    printf("Raiz da arvore: %d\n", raiz->valor);

    printf("\nNos internos: ");
    imprimir_nos_internos(raiz);

    printf("\nNos folhas: ");
    imprimir_folhas(raiz);

    printf("\n\nExibicao por niveis:\n");
    imprimir_niveis(raiz, 0);

    No* encontrado = buscar_no(raiz, valorBusca);

    if (encontrado == NULL) {
        printf("\nValor nao encontrado.\n");
        return;
    }

    printf("\nNo buscado: %d\n", encontrado->valor);

    int grau = 0;

    if (encontrado->esq != NULL)
        grau++;

    if (encontrado->dir != NULL)
        grau++;

    printf("Grau do no: %d\n", grau);

    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);

    printf("\nDescendentes: ");
    imprimir_descendentes(encontrado);

    printf("\nAltura: %d\n", calcular_altura(encontrado));

    printf("Profundidade: %d\n",
           calcular_profundidade(raiz, valorBusca, 0));

    printf("\nSubArvore:\n");
    imprimir_subarvore(encontrado, 0);
}
