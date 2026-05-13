#include <stdlib.h>
#include <stdio.h>
#include "lista_dupla.h"

//função para alocar e inserir um novo elemento na lista
void incerir_no_inicio(No **head, int num){
    No *novo = malloc(sizeof(No));

    if (novo != NULL){
        novo->valor = num;
        printf("numero %d alocado\n",novo->valor);

        novo->proximo = *head;
        novo->anterior = NULL;

        if (*head != NULL){
            (*head)->anterior = novo;
        }
        
        *head = novo;
    }
    else{
        printf("houve um erro na alocação \n");
    }
}

//função para buscar na lista
No* lst_busca(No *head, int num){
    No *p;
    p = head;
    while (p != NULL && p->valor != num){
        p = p->proximo;
    }
    return p;
}



//função para apagar a lista
void libera(No *head){
    No *p;
    p = head;
    while(head != NULL){
        p = head->proximo;

        int x = head->valor;
        
        free(head);
        head=p;
    }
    printf("lista apagada\n");
}


//função para escrever a lista
int escreve(No *head){
    No *p;
    p = head;
    while (p != NULL){

        printf("%d; ",p->valor);
        p = p->proximo;
    }
}

//função para retirar um elemento da lista
No* lst_retira(No *head, int num){
    No *p;
    p = head;
    while (p != NULL && p->valor != num){
        p = p->proximo;
    }


    if (p == NULL){
        printf("o elemento não existe\n");
        return head;
    }
    else if (p->proximo == NULL && p->anterior == NULL){
        head = NULL;
    }
    else if (p->anterior == NULL){
        p->proximo->anterior = NULL;
        head = p->proximo;
    }
    else if (p->proximo == NULL){
        p->anterior->proximo = NULL;
    }
    else{
        p->proximo->anterior = p->anterior;
        p->anterior->proximo = p->proximo;
    }

    printf("elemento %d retirado\n",num);
    free(p);
    return head;
}


