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
            lista->ultimo->proximo=novo;
            lista->ultimo=novo;
            lista->ultimo->proximo=lista->primeiro;
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
            inserirNoInicio(lista, valor);
        } else if(novo->valor < lista->primeiro->valor){
            inserirNoInicio(lista, valor);
        } else{
            aux=lista->primeiro;
            while (aux->proximo != lista->primeiro && novo->valor > aux->proximo->valor){
                aux=aux->proximo;
            }
            if(aux->proximo==lista->primeiro){
                inserirNoFim(lista, valor);
            } else{
                novo->proximo=aux->proximo;
                aux->proximo=novo;
                lista->tamanho++;
            }
        }
    } else{
        printf("\nErro ao alocar memória!\n");
    }
}
No *remover(Lista *lista, int valor){
    No *aux, *aSerRemovido = NULL;
    if(lista->primeiro){
        if(lista->primeiro==lista->ultimo && lista->primeiro->valor==valor){
            aSerRemovido = lista->primeiro;
            lista->primeiro=NULL;
            lista->ultimo=NULL;
            lista->tamanho--;
        }else if(lista->primeiro->valor==valor){
            aSerRemovido = lista->primeiro;
            lista->primeiro=aSerRemovido->proximo;
            lista->ultimo->proximo=lista->primeiro;
            lista->tamanho--;
        } else{
            aux = lista->primeiro;
            while (aux->proximo != lista->primeiro && aux->proximo->valor!=valor){
                aux = aux->proximo;
            }
            if(aux->proximo->valor==valor){
                if(lista->ultimo==aux->proximo){
                    aSerRemovido = aux->proximo;
                    aux->proximo = aSerRemovido->proximo;
                    lista->ultimo=aux;
                } else{
                    aSerRemovido = aux->proximo;
                    aux->proximo = aSerRemovido->proximo;
                }
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
    No *aux = lista->primeiro;
    if(aux){
        do{
            if(aux->valor==valor){
                return aux;
            }
            aux=aux->proximo;
        } while (aux!=lista->primeiro);
    }
    return NULL;
}
void imprimir(Lista lista){
    printf("\nLista\n");
    printf("\n------Tamanho: %i----------\n", lista.tamanho);
    No *aux = lista.primeiro;
    if(aux){
        do{
            printf("%i\t", aux->valor);
            aux=aux->proximo;
        } while (aux!=lista.primeiro);
        printf("\ninício:\t%i", aux->valor);
    }
    printf("\n--------FimLista----------\n");
}

