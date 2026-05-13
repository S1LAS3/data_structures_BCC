#ifndef LISTA_H
#define lISTA_H

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No* lst_busca(No *head, int num);
void incerir_no_inicio(No **head);
int escreve(No *head);
void libera(No *head);

#endif