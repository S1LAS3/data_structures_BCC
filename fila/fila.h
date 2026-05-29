#ifndef FILA_H
#define FILA_H

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
}No;

typedef struct fila{
    No *primeiro;
    No *ultimo;
}fila;

fila* incerir(fila *minha_fila, int num);
fila* retirada(fila *minha_fila);
int escreve(fila *minha_fila);

#endif