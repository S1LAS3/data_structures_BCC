#include <stdlib.h>
#include <stdio.h>
#include "lista_circular.h"

//função para criar e inserir um elemento no inicio da lista
No* inserir_no_inicio(No *head, int num){
    No *novo = malloc(sizeof(No));
    novo->valor = num;

    //quando não existe nem um elemento na lista ele aloca o primeiro elemeto
    if (head == NULL){
        novo->proximo = novo;
        novo->anterior = novo;
        printf("%d; ",novo->valor);
    }
    //aloca os demais elementos
    else if (novo != NULL){
        No* tail = head->anterior;

        novo->proximo = head;
        novo->anterior = tail;
        head->anterior = novo;
        tail->proximo = novo;

        printf("%d; ",novo->valor);
    }else{
        printf("houve um erro na alocação \n");
    }


    return novo;
}


// função buscar um elemento da lista
No* lst_busca(No *head, int num){
    No *p;
    p = head;
    do{
        if (p->valor == num){
            return p;
        }
        
        p = p->proximo;
    }while (p != head);
}


//função para escrever a lista
int escreve(No *head){
    if (head == NULL){
        printf("--> A lista esta vazia!\n");
        return 0;
    }

    No *p = head->anterior;

    do{
        printf("%d; ",p->valor);
        p = p->anterior;
    }while (p != head->anterior);
}




//função para retirar um elemento da lista
No* lst_retira(No *head, int num){

    No *p;
    p = head;

    //repetição de busca
    do{
        if (p->valor == num){
            break; 
        }
        
        p = p->proximo;
    }while (p != head);
    
    if (p == NULL){
        printf("--> o elemento não existe\n");
        return head;
    }

    //controle de ponteiros
    else if (p->proximo == p && p->anterior == p){
        head = NULL;
    }
    else if (p == head){
        p->proximo->anterior = p->anterior;
        p->anterior->proximo = p->proximo;
        head = p->proximo;
    }
    else if (p->proximo == head){
        p->proximo->anterior = p->anterior;
        p->anterior->proximo = p->proximo;
    }
    else{
        p->proximo->anterior = p->anterior;
        p->anterior->proximo = p->proximo;
    }

    //verificação de valores
    if (p->valor == num){
        printf("--> elemento %d retirado\n",num);
    }else{
        printf("--> elemento %d não esta na lista\n",num);

    }

    free(p);
    return head;   
}

//função para liberar a lista
No* libera(No *head){
    //verificação inicial pra ver se a lista tem alguma coisa
    if (head == NULL){
        printf("--> A lista ja esta vazia!\n");
        return NULL;
    }

    No *p = head->proximo;
    No *aux;

    do{
        aux = p->proximo;
        free(p);
        p = aux;
    }while (p != head);
    printf("--> lista apagada\n");
    return NULL;

}



//função de organização quick sort que não deu bom :(

/*
//particionamento
No* particiona (No *head, No *tail){
    int pivo = tail->valor;

    No *indo;
    No *voltando;

    indo = head;
    voltando = tail;
    while (indo != voltando && indo->anterior != voltando){

        while(indo != voltando && indo->valor <= pivo){
            indo = indo->proximo;
        }

        while (indo != voltando && voltando->valor > pivo){
            voltando = voltando->anterior;
        }

        if (indo != voltando && indo->anterior != voltando){
            int aux = indo->valor;
            indo->valor = voltando->valor;
            voltando->valor = aux;

            indo = indo->proximo;
            voltando = voltando->anterior;      
        }
        

    }
    
    return indo;
}

void quick_sort(No* head, No* tail){
    if (tail != NULL && head != tail && head != tail->proximo){
        No* divisor;
        divisor = particiona (head,tail);
        quick_sort(head,divisor->anterior);
        quick_sort(divisor, tail);
    }  
}
*/


//função de organização merge sort
No* coelho_tartaruga(No* head, No* tail){
    No* x; No* y;

    x = head; y = head;

    while(x != tail && x->proximo != tail && x->proximo != NULL){
        x = x->proximo->proximo;
        y = y->proximo;
    }
    return y;
}

No* merge(No* l1, No* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    No* head;
    //define o primeiro elemento da lista (head)
    if (l1->valor < l2->valor){
        head = l1;
        l1 = l1->proximo;
    }else{
        head = l2;
        l2 = l2->proximo;
    }

    //formando a lista apartir das outras listas
    No* tail;
    tail = head;
    while (l1 && l2){
        if (l1->valor < l2->valor){
            tail->proximo = l1;
            l1->anterior = tail;
            l1 = l1->proximo;
        }else{
            tail->proximo = l2;
            l2->anterior = tail;
            l2 = l2->proximo;
        }
        
        tail = tail->proximo;
    }

    if (l1){
        tail->proximo = l1;
        l1->anterior = tail;
    }else{
        tail->proximo = l2;
        l2->anterior = tail;
    }
    return head;
}

No* merge_sort(No* head, No* tail){
    if ( !head || head == tail){
        return head;
    }else{
        //descobrindo o meio da lista
        No* meio = coelho_tartaruga(head,tail);

        //quebrando a lista em duas partes
        No* segunda = meio->proximo;
        meio->proximo = NULL;
        if (segunda) segunda->anterior = NULL;

        //chamando a função de forma recursiva
        No* esquerda = merge_sort(head,meio);
        No* direita = merge_sort(segunda,tail);

        return merge(esquerda, direita);
    }
}

No* ordenar(No* head){
    if (head == NULL || head->proximo == head){
        printf("--> a lista não pode ser ordenada\n");
        return head;
    }
    //quebrando a lista circular em uma lista linear
    No* tail = head->anterior;
    head->anterior = NULL;
    tail->proximo = NULL;

    //organizando a lista
    head = merge_sort(head, NULL);

    //devolver a circularidade da lista
    No* novo_tail = head;
    while(novo_tail->proximo != NULL){
        novo_tail = novo_tail->proximo;
    }

    novo_tail->proximo = head;
    head->anterior = novo_tail;

    printf("--> lista ordenada\n");

    return head;
}
