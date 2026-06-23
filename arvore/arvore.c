#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

short maior(short a, short b){
    return (a>b)? a: b;
}
short altura_no(No* no){
    if (no == NULL){
        return -1;
    }else{
        return no->altura;
    }
    
}
short fator_balanceamento(No* no){
    if (no){
        return (altura_no(no->esquerda) - altura_no(no->direita));
    }else return 0;
    
}

void atualizarAltura(No* no) {
    if (no != NULL) {
        no->altura = 1 + maior(altura_no(no->esquerda), altura_no(no->direita));
    }
}




No* incerir(No* raiz, int num){
    if (raiz == NULL){
        No* novo = malloc(sizeof(No));
        novo->valor = num; 
        novo->direita = NULL;
        novo->esquerda = NULL;  
        novo->altura = 0;
        return novo;

    }else{
        if(num < raiz->valor || num == raiz->valor){
            raiz->esquerda = incerir(raiz->esquerda, num);
        }else if (num > raiz->valor){
            raiz->direita = incerir(raiz->direita, num); 
        }
        atualizarAltura(raiz);
        return raiz;
    }
    
};

void imprimir(No* Node){
    if (Node != NULL){
        imprimir(Node->esquerda);
        printf("%d;", Node->valor);
        imprimir(Node->direita);
    }
}

No* remover(No* raiz, int valor){
    //se a raiz é nula ou não
    if (raiz == NULL){
        printf("ocorreu um erro :(");
        return NULL;
    }else{
        //se a raiz é o valor ou não
        if (raiz->valor == valor){
            //se a raiz é um no folha ou não
            if (raiz->direita == NULL && raiz->esquerda == NULL){
                free(raiz);
                return NULL;
            }else{
                //se o no tem dois filhos ou um
                if (raiz->direita != NULL && raiz->esquerda != NULL){
                    //essa parte aqui eu achei bacana, ele troca um no com dois filhos com um no folha que não fique muito fora do lugar
                    No* aux = raiz->esquerda;
                    while (aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerda = remover(raiz->esquerda,valor);
                    return raiz;
                    
                }else{
                    No* aux;
                    if (raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    }else{
                        aux = raiz->direita;
                    }
                    free(raiz);
                    return aux;  
                }  
            } 
        }else{
            //se se o valor da raiz esta na direita ou na esquerda    
            if (valor < raiz->valor){
                raiz->esquerda = remover(raiz->esquerda, valor);
            }else{
                raiz->direita = remover(raiz->direita, valor);
            }
            
            return raiz;
        }
    }
    
}

