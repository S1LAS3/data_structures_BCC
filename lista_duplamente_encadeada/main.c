#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

int main(){
    int x, num;
    No *lista;
    lista = NULL;
    
    for (int i = 0; i < 11; i++){
        incerir_no_inicio(&lista, i);
    }

    int c = 0;
    while ( c != 4){
        printf("==========================\n");
        printf("o que vc deseja fazer ?\n");
        printf("1-listar a lista \n");
        printf("2-apagar elemento da lista\n");
        printf("3-procurar elemento da lista\n");
        printf("4-sair \n");
        printf("==========================\n");

        scanf("%d", &c);

        switch (c){
            case 1:
                escreve(lista);
                printf("\n");

                break;

            case 2:
                printf("qual numero você quer retirar ?\n");
                scanf("%d",&x);
                lista = lst_retira(lista, x);  
                break;

            case 3:
                printf("qual numero você quer procurar ?\n");
                scanf("%d",&x);
                No *elemento;
                elemento = lst_busca(lista, x);
                if (elemento != NULL){
                    printf("--> o numero %d esta na lista\n",x);

                }else{
                    printf("--> o numero %d não foi encontrado na lista\n",x);
                };

                break;

            default:
                break;
        }

    }

 libera(lista);
    
}
