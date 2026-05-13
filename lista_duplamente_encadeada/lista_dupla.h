
#ifndef lISTA_DUPLA_H
#define lISTA_DUPLA_H

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

No* lst_busca(No *head, int num);
No* lst_retira(No *head, int num);
void incerir_no_inicio(No **head, int num);
int escreve(No *head);
void libera(No *head);


#endif