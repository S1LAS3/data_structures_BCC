#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"
//biblioteca para selecionar numeros aleatorios
#include <time.h>

int main(){
    int num, x;
    No *head = NULL;

    for (int i = 0; i < 11; i++){
        head = inserir_no_inicio(head,i);
    }
    printf("\n\nlista inicial alocada\n");


    int c = 0;
    while ( c != 8){
        printf("\n");
        printf("==========================================\n");
        printf("= o que vc deseja fazer ?                =\n");
        printf("=                                        =\n");
        printf("= 1-listar a lista                       =\n");
        printf("= 2-apagar elemento da lista             =\n");
        printf("= 3-procurar um elemento da lista        =\n");
        printf("= 4-inserir um novo elemento da lista    =\n");
        printf("= 5-apagar todos os elementos da lista   =\n");
        printf("= 6-gerar uma nova lista desorganizada   =\n");
        printf("= 7-organizar a lista                    =\n");
        printf("= 8-sair                                 =\n");
        printf("==========================================\n");
        printf("\n");

        scanf("%d", &c);
            printf("\n");

        switch (c){
            case 1:

                printf("\033[H\033[J");

                printf("\n");
                escreve(head);
                printf("\n");

                
                break;

            case 2:
                //retirar da lista                
                printf("qual numero você quer retirar ?\n");
                scanf("%d",&x);
                printf("\n");

                printf("\033[H\033[J");

                head = lst_retira(head, x); 
                break;

            case 3:
                //procurar elemento nas lista
                printf("qual numero você quer procurar ?\n");
                scanf("%d",&x);
                printf("\n");

                No *elemento;
                elemento = lst_busca(head, x);

                printf("\033[H\033[J");

                if (elemento->valor == x){
                printf("--> o numero %d esta na lista\n",x);

                }else{
                    printf("--> o numero %d não foi encontrado na lista\n",x);
                };
                break;

            case 4:
                printf("qual numero você quer colonar na lista?\n");
                scanf("%d",&x);

                printf("\033[H\033[J");

                head = inserir_no_inicio(head,x);
                break;

            case 5:

                printf("\033[H\033[J");
                head = libera(head);
                break;

            case 6:
                //lipar a lista antes
                head = libera(head);
                srand(time(NULL));

                printf("quantos numeros você quer colocar na lista? no maximo 30: ");
                int x;
                scanf("%d",&x);
                
                printf("\033[H\033[J");

                if (x <= 30 && x > 0){
                    for (int i = 0; i < x; i++){
                        int num = rand() % x+1;
                        head = inserir_no_inicio(head,num);
                    }
                }else{
                    printf("esse numero não da certo\n");
                }
                
                break;

            case 7:

                printf("\033[H\033[J");

                head = ordenar(head);

                break;

            case 8:
                break;

            default:

                printf("\033[H\033[J");

                printf("houve um erro, digite sua escolha novamente\n");
                break;
        }
    }
    libera(head);
    
}