//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de Dados
//RA: 1111111111111 - Nome do Aluno
//Atividade Final N2-3 - Exercício 5 - B

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
    if (no == NULL)
        return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    if (altEsq > altDir)
        return altEsq + 1;
    else
        return altDir + 1;
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL)
        return -1;
    if (raiz->dado == valor)
        return prof;
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

// Busca um no pelo valor e retorna o ponteiro para ele
No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado)
        return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

// Percurso em ordem imprimindo grau de cada no
void grauEmOrdem(No *raiz) {
    if (raiz == NULL) return;
    grauEmOrdem(raiz->esq);
    printf("  No %2d -> grau %d\n", raiz->dado, grauNo(raiz));
    grauEmOrdem(raiz->dir);
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

    // a) Altura dos nos: 50, 30, 70, 20, 10
    printf("\n  Altura de alguns nos da arvore:\n");
    int nosAltura[] = {50, 30, 70, 20, 10};
    for (int i = 0; i < 5; i++) {
        No *no = buscarNo(raiz, nosAltura[i]);
        printf("  alturaNo(%d) = %d\n", nosAltura[i], alturaNo(no));
    }
    
        printf("-----------------------------------\n");

    // b) Profundidade dos nos: 50, 30, 70, 45, 10
    printf("  Profundidade dos nos:\n");
    int nosProf[] = {50, 30, 70, 45, 10};
    for (int i = 0; i < 5; i++) {
        printf("  profundidade(%d) = %d\n", nosProf[i],
               profundidadeNo(raiz, nosProf[i], 0));
    }

       printf("-----------------------------------\n");
       
    // c) Grau de cada no (percurso em ordem)
    printf("  Grau de cada no (em ordem):\n");
    grauEmOrdem(raiz);
    printf("----------------------------------\n");

    // d) Altura total da arvore
    printf("  Altura total da arvore:\n");
    printf("  Altura: %d\n", alturaNo(raiz));

    liberarArvore(raiz);
    return 0;
}