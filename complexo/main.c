#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main(){
    //criando variaveis
    complexo* n1 = complexo_cria();
    complexo* n2 = complexo_cria();

    //leitura de variaveis
    printf("\nvamos fazer a leitura das variaveis\n");
    printf("\n====================================\n");
   
    printf("parte real de n1: ");
    scanf("%f",&n1->real);
    printf("parte imaginaria de n1: ");
    scanf("%f",&n1->imaginaria);

    printf("\n====================================\n");

    printf("parte real de n2: ");
    scanf("%f",&n2->real);
    printf("parte imaginaria de n2: ");
    scanf("%f",&n2->imaginaria);

   printf("\n====================================\n");
    int opção = 0;
    printf("Qual operação vc deseja fazer com os numeros ?:\n1 para soma\n2 para subtração\n ");
    scanf("%d",&opção);

    //operações e funções

    switch (opção){
        case 1:
            complexo* soma;
            soma = complexo_soma(n1, n2);
            complexo_imprime(soma, opção);
            free(soma);
            break;

        case 2:
            complexo* subtracao;
            subtracao = complexo_subtracao(n1, n2);
            complexo_imprime(subtracao, opção);
            free(subtracao);
            break;
        
        default:
        printf("erro de entrada, reinicie o programa\n ");
            break;
    }

    free(n1);
    free(n2);  
}