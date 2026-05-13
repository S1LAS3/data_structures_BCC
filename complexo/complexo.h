#ifndef COMPLEXO_H
#define COMPLEXO_H

struct numero{
    float real;
    float imaginaria;
};
typedef struct numero complexo;

complexo* complexo_cria();
complexo* complexo_soma(complexo* n1, complexo* n2);
complexo* complexo_subtracao(complexo* n1, complexo* n2);
complexo* complexo_imprime(complexo* x, int y);

#endif