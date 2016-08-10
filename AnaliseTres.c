//
// Created by Evandson on 07/08/2016.
// Algoritmo O(log N)
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

void buscaBinaria (int x, int n, int v[]) {

    LARGE_INTEGER tempoInicial, tempoFinal, freq;
    double tempoTotal;
    QueryPerformanceCounter(&tempoInicial);

    int e, m, d;
    e = -1; d = n;
    while (e < d-1) {
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;

    QueryPerformanceCounter(&tempoFinal);
    QueryPerformanceFrequency(&freq);
    tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

    }
    printf("tempo decorrido: %f\n",tempoTotal);
}

int main() {
    int qtd = NULL, *matriz = NULL;
    int i, base = 2, expoente = 20;
    qtd = pow(base, expoente);

    matriz = (int *)malloc(qtd * sizeof(int));

    srand(time(NULL));
    for (i = 0; i < qtd; i++)
    {
        matriz[i] = rand() % qtd + 1;

        //printf("Valor  %i : %i" , i,  matriz[i]);
        //printf("\n");
    }

    buscaBinaria(524288, 20, matriz);
    return 0;


}
