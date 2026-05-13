#include <stdlib.h>
#include <stdio.h>
//biblioteca para selecionar numeros aleatorios
#include <time.h>
#include "lista.h"

//função para inserir um novo elemento na lista
void incerir_no_inicio(No **head){
    No *novo = malloc(sizeof(No));

    if (novo != NULL){
        //função para selecionar numeros aleatorios
        int num = rand() % 11;
        novo->valor = num;
        printf("numero %d alocado\n",novo->valor);

        novo->proximo = *head;
        *head = novo;
    }
    else{
        printf("houve um erro na alocação \n");
    }
}

//função que busca um elemento e retorna ele
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

        printf("numero %d apagado\n",x);
        head=p;
    }
}

