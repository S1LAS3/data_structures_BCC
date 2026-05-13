#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//biblioteca para selecionar numeros aleatorios
#include <time.h>


int main(){
    int valor, num;
    No *lista;
    printf("diga um numero de 0 a 10: ");
    scanf("%d", &valor);

    //função para poder selecionar numeros aleatorios
    srand(time(NULL));
    for (int i = 0; i < 7; i++){
        incerir_no_inicio(&lista);
    }

    No *elemento;
    elemento = lst_busca(lista, valor);
    if (elemento != NULL){
        printf("=========================\n");
        printf("o numero %d esta na lista\n",valor);
        printf("=========================\n");

    }else{
        printf("=======================================\n");
        printf("o numero %d não foi encontrado na lista\n",valor);
        printf("=======================================\n");
    };

    //libera a lista
    libera(lista);


}