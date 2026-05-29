#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(){

    fila *minha_fila = malloc(sizeof(fila));
    minha_fila->primeiro = NULL;
    minha_fila->ultimo = NULL;
    
    int x = 1,num;

    while (x!=4){
        printf("\n\n1 para incerir\n 2 para retirar\n 3 para listar\n 4 para sair \n digite man: ");
        scanf("%d",&x);
        printf("\n");
        switch (x){
        case 1:

            scanf("%d",&num);
            minha_fila = incerir(minha_fila, num);
            break;
        case 2:
            minha_fila = retirada(minha_fila);
            break;
        case 3:
            escreve(minha_fila);
            break;
        default:
            break;
        }

    }
    

}