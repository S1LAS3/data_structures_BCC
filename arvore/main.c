#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int main(){

    arv *minha_arv = malloc(sizeof(arv));

    minha_arv->raiz == NULL;
    
    int x = 1,num;

    while (x!=4){
        printf("\n\n 1 para incerir\n 2 para retirar\n 3 para listar (em ordem)\n 4 para sair \n digite man: ");
        scanf("%d",&x);
        printf("\033[H\033[J");

        switch (x){
        case 1:
            scanf("%d",&num);
            minha_arv->raiz = incerir(minha_arv->raiz, num);
            printf("numero %d inserido\n",num);
            break;
        case 2:
            printf("\033[H\033[J");
            scanf("%d",&num);
            minha_arv->raiz = remover(minha_arv->raiz, num);
            printf("numero %d removido\n",num);
            break;
        case 3:
            printf("\033[H\033[J");
            imprimir(minha_arv->raiz);
            printf("\valores em ordem crescente\n");
            break;

        case 4:
            printf("\033[H\033[J");
            break;

        default:
            printf("\033[H\033[J");
            printf("ocorreu um erro digite novamente\n");
            break;
        }

    }
    

}