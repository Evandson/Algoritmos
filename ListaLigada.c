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

void inserirMeio(No** inicio, int numero){ //metodo não funciona
    No* anterior = NULL;
    No* percorre = *inicio;
    No* novo = malloc(sizeof(No));
    novo->numero = numero;
    while (percorre != NULL && percorre->numero < numero){
        anterior = percorre;
        percorre = percorre->proximo;
    }
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
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

void removeMeio(No** inicio){ //metodo não funciona
    No* anterior;
    No* verifica;
    anterior = NULL;
    verifica = *inicio;
    while(verifica != NULL){
        anterior = verifica;
        verifica = verifica->proximo;
    }
    anterior->proximo = verifica->proximo;
    free(verifica);
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

void buscaElemento(No** inicio, int numero){
    No* atual;
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
    No* inicio = NULL;

    printf("\n");
    printf("200, 45, 2, 10 e 5 INSERIDOS no INICIO: ");
    inserirInicio(&inicio, 5);
    inserirInicio(&inicio, 10);
    inserirInicio(&inicio, 2);
    inserirInicio(&inicio, 45);
    inserirInicio(&inicio, 200);
    imprimir(inicio);

    printf("\n");
    printf("350, 100, 50 e 60 INSERIDOS no FINAL: ");
    inserirFim(&inicio, 60);
    inserirFim(&inicio, 50);
    inserirFim(&inicio, 100);
    inserirFim(&inicio, 350);
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

    printf("\n");
    printf("BUSCANDO elemento 5: ");
    buscaElemento(&inicio, 5);

    printf("\n");
    printf("77 INSERIDO no MEIO: ");
    inserirMeio(&inicio, 77);
    imprimir(inicio);

    //removeMeio(&inicio);
    //imprimir(inicio);
    return 0;
}