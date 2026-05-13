#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

int maior(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int calcularAltura(struct No* n) {

    if (n == NULL) {
        return -1;
    }

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    return 1 + maior(alturaEsq, alturaDir);
}

int obterFB(struct No* n) {

    if (n == NULL) {
        return 0;
    }

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    return alturaEsq - alturaDir;
}

struct No* criarNo(int valor) {

    struct No* novo = (struct No*) malloc(sizeof(struct No));

    novo->valor = valor;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int main() {

    struct No* raiz = criarNo(20);

    raiz->esq = criarNo(10);

    raiz->esq->esq = criarNo(5);

    raiz->esq->esq->esq = criarNo(2);

    printf("\nEstrutura criada:\n");
    printf("(20) -> (10) -> (5) -> (2)\n\n");

    int alturaRaiz = calcularAltura(raiz);

    int fbRaiz = obterFB(raiz);

    printf("Altura da raiz: %d\n", alturaRaiz);

    printf("Fator de balanceamento da raiz: %d\n", fbRaiz);

    if (fbRaiz > 1 || fbRaiz < -1) {
        printf("A arvore esta desbalanceada.\n");
    } else {
        printf("A arvore esta balanceada.\n");
    }

    return 0;
}