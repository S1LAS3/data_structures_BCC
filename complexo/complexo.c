#include <stdlib.h>
#include <stdio.h>
#include "complexo.h"

complexo* complexo_cria(){
    complexo* novo = (complexo*) malloc(sizeof(complexo));
    if (novo == NULL)
    {
        exit(1);
    }
    return novo;
}

complexo* complexo_soma(complexo* n1, complexo* n2){
    complexo* soma = complexo_cria();
    soma->real = n1->real + n2->real;
    soma->imaginaria = n1->imaginaria + n2->imaginaria;
    return soma;
}

complexo* complexo_subtracao(complexo* n1, complexo* n2){
    complexo* subtracao = complexo_cria();
    subtracao->real = n1->real - n2->real;
    subtracao->imaginaria = n1->imaginaria - n2->imaginaria;
    return subtracao;
}

complexo* complexo_imprime(complexo* x, int y){
    if(y=1){
        printf("soma : %.2f + %.2f j\n", x->real,x->imaginaria);
    }
    else if(y=2){
        printf("subtração : %.2f + %.2fj\n", x->real,x->imaginaria);
    }
    
}
