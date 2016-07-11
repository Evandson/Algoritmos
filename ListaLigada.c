//
// Created by Evandson on 05/07/2016.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo;
}No;

No* inicio = NULL;

void inserirInicio(No* *inicio, int numero){
    No *novo = malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = *inicio;
    *inicio = novo;
}

void inserirMeio(No* *inicio, int numero){
    No *aux, *atual = *inicio;
    No *novo = malloc(sizeof(No));
    novo->numero = numero;
    if(*inicio == NULL) {//insere no inicio
        novo->proximo = *inicio;
        *inicio = novo;
    } else {
        while(atual != NULL && atual->numero < numero){
            aux = atual;
            atual = atual->proximo;
        }
        if(atual == *inicio){
            novo->proximo = *inicio;
            *inicio = novo;
        } else {
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void inserirFim(No* *inicio, int numero){
    No *ultimo;
    No *novo = malloc(sizeof(No));
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

void removeInicio(No* *inicio){
    No *velho;
    velho = *inicio;
    if (velho == NULL){
        printf("Lista Vazia");
    } else {
        *inicio = velho->proximo;
        free(velho);
    }
}

void removeMeio(No* *inicio, int numero){
    if(*inicio == NULL)
        printf("Lista vazia! ");
    No *anterior, *velho = *inicio;
    while (velho != NULL && velho->numero != numero){
        anterior = velho;
        velho = velho->proximo;
    }
    if(velho == NULL)
        printf("Elemento inexistente! ");
    if(velho == *inicio)
        *inicio = velho->proximo;
    else
        anterior->proximo = velho->proximo;
    free(velho);
}

void removeFim(No* *inicio){
    No *penultimo;
    No *ultimo;
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

void buscaElemento(No* *inicio, int numero){
    No *atual;
    atual = *inicio;
    while (atual != NULL){
        if (atual->numero == numero){
            printf("Elemento encontrado!");
            break;
        }
        atual = atual->proximo;
    }
}

void imprimir(No* inicio){
    while(inicio){
        printf("%d ", inicio->numero);
        inicio = inicio->proximo;
    }
}

int main(){
    printf("\n");
    printf("1, 2, 3, 5 e 6 INSERIDOS no INICIO: ");
    inserirInicio(&inicio, 6);
    inserirInicio(&inicio, 5);
    inserirInicio(&inicio, 3);
    inserirInicio(&inicio, 2);
    inserirInicio(&inicio, 1);
    imprimir(inicio);

    printf("\n");
    printf("7, 8, 9 e 10 INSERIDOS no FINAL: ");
    inserirFim(&inicio, 7);
    inserirFim(&inicio, 8);
    inserirFim(&inicio, 9);
    inserirFim(&inicio, 10);
    imprimir(inicio);
    printf("\n");

    printf("4 INSERIDO no MEIO: ");
    inserirMeio(&inicio, 4);
    imprimir(inicio);
    printf("\n");

    printf("\n");
    printf("1 foi REMOVIDO no INICIO: ");
    removeInicio(&inicio);
    imprimir(inicio);
    printf("\n");

    printf("10 foi REMOVIDO no FIM: ");
    removeFim(&inicio);
    imprimir(inicio);
    printf("\n");

    printf("5 foi REMOVIDO no MEIO: ");
    removeMeio(&inicio, 5);
    imprimir(inicio);

    return 0;
}