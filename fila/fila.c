#include <stdlib.h>
#include <stdio.h>
#include "fila.h"



No* criar(){
    No *novo = malloc(sizeof(No));
    novo->anterior = NULL;
    return novo;
}

fila* push(fila *minha_fila,int num){

    No* novo = criar();

    if (novo != NULL){

        novo->valor = num;
        printf("numero %d alocado\n",novo->valor);

        if (minha_fila->comeco == NULL){
            minha_fila->comeco = novo;
            minha_fila->fim = novo;
        }else{
            minha_fila->fim->anterior = novo;
            minha_fila->fim = novo;
        }
        
    }
    else{
        printf("houve um erro na alocação \n");
    }
    return minha_fila;
}

void pop(fila *minha_fila){

    if (minha_fila->comeco != NULL){
        No* apagando = minha_fila->comeco;
        minha_fila->comeco = minha_fila->comeco->anterior;
        free(apagando);
    }else{
        printf("a lista esta vazia\n");
    } 
}


int imprimir(fila *minha_fila){
    if (minha_fila->comeco != NULL){
        No *p;
        p = minha_fila->comeco;
        while (p != NULL){
            printf("%d; ",p->valor);
            p = p->anterior;
        }
    }else{
        printf("a lista esta vazia\n");
    }

}
