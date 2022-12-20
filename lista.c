//
// Created by César de Souza on 18/12/22.
//

#include "lista.h"
void criaLista(Lista *lista){
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    lista->tamanho=0;
}
void inserirNoInicio(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor=valor;
        novo->proximo=lista->primeiro;
        lista->primeiro=novo;
        if(lista->ultimo==NULL){
            lista->ultimo=novo;
        }
        lista->ultimo->proximo = lista->primeiro;
        lista->tamanho++;
    } else{
        printf("\nErro ao alocar memoria\n");
    }
}
void inserirNoFim(Lista *lista, int valor){
    No *aux, *novo = malloc(sizeof (No));
    if(novo){
        novo->valor=valor;
        if(lista->primeiro==NULL){
            lista->primeiro=novo;
            lista->ultimo=novo;
            lista->ultimo->proximo=lista->primeiro;
        } else{
            aux=lista->primeiro;
            while (aux->proximo){
                aux=aux->proximo;
            }
            aux->proximo=novo;
        }
        lista->tamanho++;
    } else{
        printf("\nErro ao alocar memória\n");
    }
}
void inserirNoMeio(Lista *lista, int valor, int anterior){
    No *aux, *novo = malloc(sizeof (No));
    if(novo){
        novo->valor=valor;
        if(lista->primeiro==NULL){
            novo->proximo=NULL;
            lista->primeiro=novo;
        } else{
            aux=lista->primeiro;
            while (aux->valor!=anterior && aux->proximo){
                aux=aux->proximo;
            }
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }
    } else{
        printf("\nErro ao alocar memória\n");
    }
}
void inserirOrdenado(Lista *lista, int valor){
    No *aux, *novo = malloc(sizeof (No));

    if(novo){
        novo->valor=valor;
        if(lista->primeiro==NULL){
            novo->proximo=NULL;
            lista->primeiro=novo;
        } else if(novo->valor < lista->primeiro->valor){
            novo->proximo=lista->primeiro;
            lista->primeiro=novo;
        } else{
            aux=lista->primeiro;
            while (aux->proximo && novo->valor > aux->proximo->valor){
                aux=aux->proximo;
            }
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }
        lista->tamanho++;
    } else{
        printf("\nErro ao alocar memória!\n");
    }
}
No *remover(Lista *lista, int valor){
    No *aux, *aSerRemovido = NULL;
    if(lista->primeiro){
        if(lista->primeiro->valor==valor){
            aSerRemovido = lista->primeiro;
            lista->primeiro=aSerRemovido->proximo;
            lista->tamanho--;
        } else{
            aux = lista->primeiro;
            while (aux->proximo && aux->proximo->valor!=valor){
                aux = aux->proximo;
            }
            if(aux->proximo){
                aSerRemovido = aux->proximo;
                aux->proximo=aSerRemovido->proximo;
                lista->tamanho--;
            } else{
                printf("\nValor não encontrado\n");
            }
        }
    } else{
        printf("\nLista vazia\n");
    }
    return aSerRemovido;
}
No *buscar(Lista *lista, int valor){
    No *aux, *no = NULL;
    aux=lista->primeiro;
    while (aux && aux->valor!=valor){
        aux=aux->proximo;
    }
    if(aux){
        no = aux;
    }
    return no;
}
void imprimir(Lista lista){
    printf("\nLista\n");
    printf("\n------Tamanho: %i----------\n", lista.tamanho);
    No *aux = lista.primeiro;
    while (aux){
        printf(" %i", aux->valor);
        aux=aux->proximo;
    }
    printf("\n--------FimLista----------\n");
}

