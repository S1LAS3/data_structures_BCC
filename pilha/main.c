#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(){

    pilha *minha_pilha = malloc(sizeof(pilha));

    minha_pilha->de_baixo = NULL;
    minha_pilha->de_cima = NULL;
    
    int x = 1,num;

    while (x!=4){

        printf("\n\n 1 para incerir\n 2 para retirar\n 3 para listar\n 4 para sair \n digite man: ");
        scanf("%d",&x);
        printf("\033[H\033[J");

        switch (x){
        case 1:
            printf("digite: ");
            scanf("%d",&num);
            printf("\033[H\033[J");
            minha_pilha = push(minha_pilha, num);
            break;
        case 2:
            pop(minha_pilha);
            break;
        case 3:
            imprimir(minha_pilha);
            break;
        default:
            break;
        }

    }
    

}