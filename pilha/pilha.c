#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"



No* criar(int num){
    No *novo = malloc(sizeof(No));
    novo->anterior = NULL;
    novo->valor = num;
    return novo;
}

pilha* push(pilha *minha_pilha,int num){

    No* novo = criar(num);

    if (novo != NULL){

        printf("--> numero %d alocado\n",novo->valor);

        if (minha_pilha->de_cima == NULL){
            minha_pilha->de_cima = novo;
            minha_pilha->de_baixo = novo;
        }else{
            novo->anterior = minha_pilha->de_cima;
            minha_pilha->de_cima = novo;
        }  
    }
    else{
        printf("--> houve um erro na alocação \n");
    }
    return minha_pilha;
}

void pop(pilha *minha_pilha){
    if (minha_pilha->de_cima != NULL){

        No* apagando = minha_pilha->de_cima;
        minha_pilha->de_cima = minha_pilha->de_cima->anterior;

        printf("--> numero %d apagado\n",apagando->valor);

        free(apagando);

        if (minha_pilha->de_cima == NULL){
            minha_pilha->de_baixo = NULL;
        }
        }else{
        printf("--> a lista esta vazia\n");
    } 
}


int imprimir(pilha *minha_pilha){
    if (minha_pilha->de_cima != NULL){
        No *p;
        p = minha_pilha->de_cima;
        printf("topo --> ");
        while (p != NULL){
            printf("%d; ",p->valor);
            p = p->anterior;
        }
        printf("<-- base \n");

    }else{
        printf("--> a lista esta vazia\n");
    }

}
