//
// Created by Evandson on 05/07/2016.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo;
}No;

void inserirInicio(No** inicio, int numero){
    No* novo = malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = *inicio;
    *inicio = novo;
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
        while(ultimo->proximo != NULL)
            ultimo = ultimo->proximo;
        ultimo->proximo = novo;
        }
    }

void removeInicio(No** inicio){
    No* velho;
    velho = *inicio;
    if (velho == NULL){
        printf("Lista Vazia");
    } else {
        *inicio = velho->proximo;
        free(velho);
    }
}

void removeFim(No** inicio){
    No* penultimo;
    No* ultimo;
    penultimo = *inicio;
    if (penultimo == NULL){
        printf("Lista Vazia");
    } else {
        ultimo = penultimo->proximo;
        while(ultimo->proximo != NULL){
            penultimo = ultimo;
            ultimo = ultimo->proximo;
        }
        penultimo->proximo = NULL;
        free(ultimo);
    }
}

void imprimir(No* inicio){
    while(inicio){
        printf("%d ", inicio->numero);
        inicio = inicio->proximo;
    }
}

int main(){
    No* inicio = NULL;

    printf("\n");
    printf("200, 45, 2, 10 e 5 INSERIDOS no INICIO: ");
    inserirInicio(&inicio,5);
    inserirInicio(&inicio,10);
    inserirInicio(&inicio,2);
    inserirInicio(&inicio,45);
    inserirInicio(&inicio,200);
    imprimir(inicio);

    printf("\n");
    printf("350, 100, 50 e 60 INSERIDOS no FINAL: ");
    inserirFim(&inicio,60);
    inserirFim(&inicio,50);
    inserirFim(&inicio,100);
    inserirFim(&inicio,350);
    imprimir(inicio);
    printf("\n");

    printf("\n");
    printf("200 foi REMOVIDO no INICIO: ");
    removeInicio(&inicio);
    imprimir(inicio);

    printf("\n");
    printf("350 foi REMOVIDO no FIM: ");
    removeFim(&inicio);
    imprimir(inicio);
    printf("\n");
    return 0;
}