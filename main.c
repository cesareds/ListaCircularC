#include "lista.h"
int main() {
    int opcao, valor, anterior;
    Lista lista;
    criaLista(&lista);
    No *removido;

    do{
        printf("\n0-sair\n1-inserirNoInicio\n2-inserirNoFim\n3-inserirNoMeio\n4-inserirOrdenado\n5-remover\n6-buscar\n7-imprimir\n");
        scanf(" %i", &opcao);
        switch (opcao) {
            case 0:
                printf("\nencerrando...\n");
                break;
            case 1:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                inserirNoFim(&lista, valor);
                break;
            case 3:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                printf("\nanterior:\t");
                scanf(" %i", &anterior);
                inserirNoMeio(&lista, valor, anterior);
                break;
            case 4:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                inserirOrdenado(&lista, valor);
                break;
            case 5:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                removido = remover(&lista, valor);
                printf("\nRemovido:\t%i\n", removido->valor);
                removido->valor=-1;
                break;
            case 6:
                printf("\nvalor:\t");
                scanf(" %i", &valor);
                removido = buscar(&lista, valor);
                printf("\nEncontrado:\t%i\n", removido->valor);
                removido->valor=-1;
                break;
            case 7:
                imprimir(lista);
                break;
            default:
                printf("\nopcao inválida\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}
