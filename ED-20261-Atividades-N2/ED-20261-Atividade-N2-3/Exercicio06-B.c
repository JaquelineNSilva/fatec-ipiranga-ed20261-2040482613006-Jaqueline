//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 6 - B

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

int alturaNo(No *no) {
    if (no == NULL) return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    if (altEsq > altDir) return altEsq + 1;
    return altDir + 1;
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no) {
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado)
        return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

int imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    if (imprimirAncestral(raiz->esq, valor) ||
        imprimirAncestral(raiz->dir, valor)) {
        printf("%d ", raiz->dado);
        return 1;
    }
    return 0;
}

void percursoDescendentes(No *raiz) {
    if (raiz == NULL) return;
    percursoDescendentes(raiz->esq);
    printf("%d ", raiz->dado);
    percursoDescendentes(raiz->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    if (raiz == NULL) return;
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

int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    return 1 + contarDescendentes(no->esq) + contarDescendentes(no->dir);
}

void relatorioNo(No *raiz, int valor) {
    No *no = buscarNo(raiz, valor);

    if (no == NULL) {
        printf("Erro: valor %d nao encontrado na arvore.\n", valor);
        return;
    }

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-3d             |\n", valor);
    printf("+----------------------------------+\n");
    printf("| Profundidade : %-3d               |\n", profundidadeNo(raiz, valor, 0));
    printf("| Altura       : %-3d               |\n", alturaNo(no));
    printf("| Grau         : %-3d               |\n", grauNo(no));
    printf("| Ancestrais   : ");                
    imprimirAncestral(raiz, valor);
    printf("\n");
    printf("| Descendentes : ");
    imprimirDescendentes(raiz, valor);
    printf("\n");
    printf("| Qtd Descend. : %-3d               |\n", contarDescendentes(no) - 1);
    printf("+----------------------------------+\n\n");
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

    relatorioNo(raiz, 30);

    liberarArvore(raiz);
    return 0;
}