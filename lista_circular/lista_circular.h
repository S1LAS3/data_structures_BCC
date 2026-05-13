#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No; 


No* inserir_no_inicio(No *head, int num);
No* lst_busca(No *head, int num);
No* lst_retira(No *head, int num);
int escreve(No *head);
No* libera(No *head);
No* ordenar(No* head);



#endif