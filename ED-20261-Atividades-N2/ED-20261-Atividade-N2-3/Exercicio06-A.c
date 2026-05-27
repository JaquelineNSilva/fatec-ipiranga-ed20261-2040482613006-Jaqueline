//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 6 - A

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

// Busca um no na arvore
No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor)
        return raiz;

    if (valor < raiz->dado)
        return buscarNo(raiz->esq, valor);

    return buscarNo(raiz->dir, valor);
}

// Imprime os ancestrais do no com 'valor', do pai ate a raiz.
// Funciona de forma recursiva: se encontrar o valor em alguma
// subarvore, imprime o no atual ao retornar (do pai para a raiz).
int imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL)
        return 0;
    if (raiz->dado == valor)
        return 1;

    if (imprimirAncestral(raiz->esq, valor) ||
        imprimirAncestral(raiz->dir, valor)) {
        printf("%d ", raiz->dado);
        return 1;
    }
    return 0;
}

// Imprime todos os descendentes do no com 'valor'
// usando percurso em ordem, excluindo o proprio no.
void percursoDescendentes(No *raiz) {
    if (raiz == NULL) return;
    percursoDescendentes(raiz->esq);
    printf("%d ", raiz->dado);
    percursoDescendentes(raiz->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("Valor nao encontrado na arvore.\n");
        return;
    }
    if (raiz->dado == valor) {
        percursoDescendentes(raiz->esq);
        percursoDescendentes(raiz->dir);
        return;
    }
    if (valor < raiz->dado)
        imprimirDescendentes(raiz->esq, valor);
    else
        imprimirDescendentes(raiz->dir, valor);
}

// Conta quantos descendentes o no possui
int contarDescendentes(No *no) {
    if (no == NULL)
        return 0;
    return 1 + contarDescendentes(no->esq) + contarDescendentes(no->dir);
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

    printf("Ancestrais de 45: ");
    imprimirAncestral(raiz, 45);
    printf("\n");

    printf("Descendentes de 30: ");
    imprimirDescendentes(raiz, 30);
    printf("\n");

    No *no30 = buscarNo(raiz, 30);

    printf("Quantidade de descendentes de 30: %d\n",
           contarDescendentes(no30) - 1);

    liberarArvore(raiz);
    return 0;
}