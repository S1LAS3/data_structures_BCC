#include <stdio.h>
//função usada para descobri o meio de uma lista duplamente encadeada
typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No; 

No* Tortoise_and_Hare(No* head, No* tail){
    No* Tortoise;
    No* Hare;
    Tortoise = head;
    Hare = head;
    while (Hare != tail && Hare->proximo != tail){
        Hare = Hare->proximo->proximo;
        Tortoise = Tortoise->proximo;
    }
    return Tortoise;
}



No* merge(No* l1, No* l2){

    if (!l1) return l2;
    if (!l2) return l1;

    No* head;

    if (l1->valor < l2->valor){
        head = l1;
        l1 = l1->proximo; 
    }else{
        head = l2;
        l2 = l2->proximo;
    }

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
        No* meio = Tortoise_and_Hare(head, tail);

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
