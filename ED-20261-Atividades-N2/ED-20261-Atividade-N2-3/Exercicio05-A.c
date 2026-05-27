//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 5 - A


#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);
    if (valor < raiz->dado)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Retorna -1 se o no for nulo, 0 se for folha,
// ou o maior caminho ate uma folha descendente
int alturaNo(No *no) {
    if (no == NULL)
        return -1;

    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);

    if (altEsq > altDir)
        return altEsq + 1;
    else
        return altDir + 1;
}

// Busca o valor na arvore e retorna a profundidade dele.
// Retorna -1 se o valor nao existir.
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL)
        return -1;
    if (raiz->dado == valor)
        return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Numero de filhos diretos do no (0, 1 ou 2)
int grauNo(No *no) {
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++)
        raiz = inserir(raiz, valores[i]);

    printf("Arvore montada com sucesso.\n");
    printf("Altura da arvore: %d\n", alturaNo(raiz));

    liberarArvore(raiz);
    return 0;
}