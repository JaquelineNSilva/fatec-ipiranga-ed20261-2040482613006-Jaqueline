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

    int altura = 1 + maior(alturaEsq, alturaDir);

    printf(
        "No %d: 1 + max(H_esq:%d, H_dir:%d) = Altura %d\n",
        n->valor,
        alturaEsq,
        alturaDir,
        altura
    );

    return altura;
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

    printf("\nCalculo das alturas dos nos:\n\n");

    int fbRaiz = obterFB(raiz);

    printf("\nResultado final no no 20 (Raiz):\n");

    printf("Fator de Balanceamento: %d\n", fbRaiz);

    if (fbRaiz > 1 || fbRaiz < -1) {
        printf("Status: DESBALANCEADA\n");
    } else {
        printf("Status: BALANCEADA\n");
    }

    return 0;
}