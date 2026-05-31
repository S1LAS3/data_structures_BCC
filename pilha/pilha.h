#ifndef PILHA_H
#define PILHA_H

typedef struct No{
    int valor;
    struct No *anterior;
}No;

typedef struct pilha{
    No *de_baixo;
    No *de_cima;
}pilha;

pilha* push(pilha *minha_fila, int num);
void pop(pilha *minha_fila);
int imprimir(pilha *minha_fila);

#endif