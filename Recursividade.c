//
// Created by Evandson Maranhão on 23/05/2016.
// função recursiva fatorial
#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);
    printf("%d",fatorial(n));
}

int fatorial(int n){
    if(n == 0){
        return 1;
    } else {
        return (n * fatorial(n - 1));
    }
}

