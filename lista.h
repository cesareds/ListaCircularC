//
// Created by César de Souza on 18/12/22.
//

#ifndef ESTUDANDO_P_EXAME_LISTA_H
#define ESTUDANDO_P_EXAME_LISTA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   struct no *proximo;
   int valor;
}No;
typedef struct {
    No *primeiro;
    No *ultimo;
    int tamanho;
}Lista;


void criaLista(Lista *lista);
void inserirNoInicio(Lista *lista, int valor);
void inserirNoFim(Lista *lista, int valor);
void inserirNoMeio(Lista *lista, int valor, int anterior);
void inserirOrdenado(Lista *lista, int valor);
No *remover(Lista *lista, int valor);
No *buscar(Lista *lista, int valor);
void imprimir(Lista lista);

#endif //ESTUDANDO_P_EXAME_LISTA_H
