#include <stdlib.h>
#include <stdio.h>
#include "fila.h"


No* criar_elemento(No *head){
    No *novo = malloc(sizeof(No));
    novo->proximo = NULL; 
    novo->anterior = NULL;

    return novo;
}

fila* incerir(fila *minha_fila, int num){

    No *novo = criar_elemento(minha_fila->primeiro);

    if (novo != NULL){
        novo->valor = num;
        printf("numero %d alocado\n",num);
        if(minha_fila->primeiro != NULL){
            novo->proximo = minha_fila->ultimo;
            novo->anterior = minha_fila->primeiro;
            minha_fila->ultimo->anterior = novo;
            minha_fila->primeiro->proximo = novo;
            minha_fila->ultimo = novo;

        }else if (minha_fila->primeiro == NULL){
            minha_fila->primeiro = novo;
            minha_fila->ultimo= novo;
            novo->anterior = novo;
            novo->proximo = novo;
        }else{
            printf("houve um erro de alocação");

        }
        
    }
    return minha_fila;
    
}   

fila* retirada(fila *minha_fila){
    No* apagando = minha_fila->primeiro; 
    minha_fila->primeiro = apagando->anterior;
    minha_fila->ultimo->anterior = apagando->anterior;
    free(apagando);
    return minha_fila;
}

int escreve(fila *minha_fila){
    if (minha_fila->primeiro == NULL){
        printf("--> A lista esta vazia!\n");
        return 0;
    }

    No *p = minha_fila->ultimo;

    do{
        printf("%d; ",p->valor);
        p = p->proximo;
    }while (p != minha_fila->ultimo);
}

