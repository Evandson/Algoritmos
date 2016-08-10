//
// Created by Evandson on 07/08/2016.
// Algoritmo O(N)
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

typedef struct No {
    int numero;
    struct No *proximo;
}No;

No* inicio = NULL;

void inserirFim(No* *inicio, int numero){

    LARGE_INTEGER tempoInicial, tempoFinal, freq;
    double tempoTotal;
    QueryPerformanceCounter(&tempoInicial);

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

    QueryPerformanceCounter(&tempoFinal);
    QueryPerformanceFrequency(&freq);
    tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

    printf("tempo decorrido: %f\n",tempoTotal);
}

void imprimir(No* inicio){
    while(inicio){
        printf("%d ", inicio->numero);
        inicio = inicio->proximo;
    }
}

int main(){
    int i, base = 2, expoente = 20;
    int qtd = pow(base, expoente);

    srand( (unsigned)time(NULL) );
    for(i = 1; i <= qtd; i++)
        listaAdd(&inicio, rand());

    //Chamando a questão e inserindo outro elemento na lista diferente de NULL
    inserirFim(&inicio, 24);
    //imprimir(inicio);
    return 0;
}

//função para adicionar elementos na lista
void listaAdd(No* *inicio, int numero){
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
