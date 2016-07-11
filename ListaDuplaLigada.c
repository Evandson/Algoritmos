//
// Created by Evandson on 10/07/2016.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *proximo, *anterior;
}No;

No *inicio = NULL;

void inserirInicio(No* *inicio, int numero){
    No *novo = malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = *inicio;
    novo->anterior = NULL;
    if (*inicio != NULL)
        (*inicio)->anterior = novo;
    *inicio = novo;
}

void inserirMeio(No* *inicio, int numero){
    No *aux, *atual = *inicio;
    No *novo = malloc(sizeof(No));
    novo->numero = numero;
    if(*inicio == NULL){
        novo->proximo = NULL;
        novo->anterior = NULL;
        *inicio = novo;
        printf("\n a lista estava vazia, inseriu no inicio! ");
    } else { //vai procurar onde inserir..
        while(atual != NULL && atual->numero < numero){
            aux = atual;
            atual = atual->proximo;
        }
        if(atual == *inicio){//insere no inicio
            novo->anterior = NULL;
            (*inicio)->anterior = novo;
            novo->proximo = *inicio;
            *inicio = novo;
            printf("\n Era igual ao primeiro elemento da lista, inseriu no inicio!\n ");
        } else {
            novo->proximo = aux->proximo;
            novo->anterior = aux;
            aux->proximo = novo;
            if(atual != NULL){
                atual->anterior = novo;
            }
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
        while (ultimo->proximo != NULL)
            ultimo = ultimo->proximo;
        ultimo->proximo = novo;
        novo->anterior = ultimo;
    }
}

void removeInicio(No* *inicio){
    No *velho;
    if (*inicio == NULL){
        printf("Lista vazia!");
    } else {
        velho = *inicio;
        *inicio = velho->proximo;
        if(velho->proximo != NULL)
            velho->proximo->anterior = NULL;
        free(velho);
    }
}

void removeMeio(No* *inicio, int numero){
    No *velho;
    if(*inicio == NULL)
        printf("\n lista vazia, não pode remover! \n");
    velho = *inicio;
    while(velho != NULL && velho->numero != numero){
        velho = velho->proximo;
    }
    if(velho == NULL)
        printf("Elemento inexistente!");
    if(velho->anterior == NULL)
        *inicio = velho->proximo;
    else
        velho->anterior->proximo = velho->proximo;
    if(velho->proximo != NULL)
        velho->proximo->anterior = velho->anterior;
    free(velho);
}

void removeFim(No* *inicio){
    No *velho;
    if(*inicio == NULL)
        printf("Lista vazia");
    velho = *inicio;
    while(velho->proximo != NULL)
        velho = velho->proximo;
    if(velho->anterior == NULL)
        *inicio = velho->proximo;
    else
        velho->anterior->proximo = NULL;
    free(velho);

}

void listar(No* inicio){
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
    listar(inicio);

    printf("\n");
    printf("7, 8, 9 e 10 INSERIDOS no FINAL: ");
    inserirFim(&inicio, 7);
    inserirFim(&inicio, 8);
    inserirFim(&inicio, 9);
    inserirFim(&inicio, 10);
    listar(inicio);
    printf("\n");

    printf("4 INSERIDO no MEIO: ");
    inserirMeio(&inicio, 4);
    listar(inicio);
    printf("\n");

    printf("\n");
    printf("1 foi REMOVIDO no INICIO: ");
    removeInicio(&inicio);
    listar(inicio);
    printf("\n");

    printf("10 foi REMOVIDO no FIM: ");
    removeFim(&inicio);
    listar(inicio);
    printf("\n");

    printf("5 foi REMOVIDO no MEIO: ");
    removeMeio(&inicio, 5);
    listar(inicio);

    return 0;
}