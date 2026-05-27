//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 5 - C


/*
    Estrutura da ABB apos inserir: 50 30 70 20 40 60 80 10 25 45 65

                        50
                       /  \
                     30    70
                    /  \   / \
                  20   40 60  80
                  / \    \   /
                10  25   45 65

    Verificacao manual de tres nos:

    No 50 (raiz):
      - altura esperada  : 3  (caminho 50->30->20->10)
      - profundidade     : 0  (eh a raiz)
      - grau             : 2  (tem filho esquerdo 30 e direito 70)

    No 30:
      - altura esperada  : 2  (caminho 30->20->10)
      - profundidade     : 1  (50->30)
      - grau             : 2  (tem filho esquerdo 20 e direito 40)

    No 10 (folha):
      - altura esperada  : 0  (nao tem filhos)
      - profundidade     : 3  (50->30->20->10)
      - grau             : 0  (folha)
*/

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

No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado)
        return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
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

    // Verificacao dos tres nos descritos no ASCII art acima
    int verificar[] = {50, 30, 10};
    int qtd = 3;

    for (int i = 0; i < qtd; i++) {
        int v = verificar[i];
        No *no = buscarNo(raiz, v);
        printf("\n No %d:\n Altura = %d\n Profundidade = %d\n Grau = %d\n", v, alturaNo(no), 
        profundidadeNo(raiz, v, 0), grauNo(no));
        printf("\n---------------------\n");
    }

    liberarArvore(raiz);
    return 0;
}