//
// Created by Evandson on 16/06/2016.
//função MDC Recursiva
#include <stdio.h>

int mdc(int a, int b){
    if(b == 0)
        return a;
    else
        return mdc(b,a%b);
    }

int main(){
    printf("%d", mdc(25, 20));
}

