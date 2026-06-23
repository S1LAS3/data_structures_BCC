#ifndef ARVORE_H
#define ARVORE_H

typedef struct No{
    int valor;
    struct No *direita;
    struct No *esquerda;
    short altura;
}No;

typedef struct {
    No *raiz;
}arv;

No* incerir(No *raiz, int num);
void imprimir(No* Node);
No* remover(No* raiz, int valor);

#endif