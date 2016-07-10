//
// Created by Evandson on 10/07/2016.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo, *anterior;
}No;

No* inicio = NULL;

void inserirInicio(No** inicio, int numero){
    No* novo = malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = *inicio;
    novo->anterior = NULL;
    if (*inicio != NULL)
        (*inicio)->anterior = novo;
    *inicio = novo;
}

void inserirMeio(No** inicio, int numero){
}

void inserirFim(No** inicio, int numero){
    No* ultimo;
    No* novo = malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = NULL;
    if(*inicio == NULL){
        *inicio = novo;
    } else {
        ultimo = *inicio;
        while (ultimo->proximo != NULL)
            ultimo = ultimo->proximo;
        ultimo->proximo = novo;
        novo->anterior = ultimo;
    }
}

void removeInicio(No** inicio){
}

void removeMeio(No** inicio){
}

void removeFim(No** inicio){
}

void listar(No* inicio){
    while(inicio){
        printf("%d ", inicio->numero);
        inicio = inicio->proximo;
    }
}

int main(){
    printf("\n");
    printf("200, 45, 2, 10 e 5 INSERIDOS no INICIO: ");
    inserirInicio(&inicio, 5);
    inserirInicio(&inicio, 10);
    inserirInicio(&inicio, 2);
    inserirInicio(&inicio, 45);
    inserirInicio(&inicio, 200);
    listar(inicio);

    printf("\n");
    printf("350, 100, 50 e 60 INSERIDOS no FINAL: ");
    inserirFim(&inicio, 60);
    inserirFim(&inicio, 50);
    inserirFim(&inicio, 100);
    inserirFim(&inicio, 350);
    listar(inicio);
    printf("\n");
    return 0;
}