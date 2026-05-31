#ifndef FILA_H
#define FILA_H

typedef struct No{
    int valor;
    struct No *anterior;
}No;

typedef struct fila{
    No *fim;
    No *comeco;
}fila;

fila* push(fila *minha_fila, int num);
void pop(fila *minha_fila);
int imprimir(fila *minha_fila);

#endif