//
// Created by Evandson on 16/06/2016.
//
#include <stdio.h>
int fibonacci(int n, int x, int y){
    if (n == 0)
        return 0;
    if (n > 1)
        return y + fibonacci(n - 1, y, x + y);
    else
        return 1;
}

int main(){
    int n = 0;
    printf("Posicao: ");
    scanf("%d",&n);
    printf("O numero da Posicao %d dos numeros fibonacci eh %d\n", n, fibonacci(n, 1, 0));
}