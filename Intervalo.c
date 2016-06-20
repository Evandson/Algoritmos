//
// Created by Evandson Maranhão on 23/05/2016.
//
#include <stdio.h>
int main(){
    int n1, n2,x;

    scanf("%d %d",&n1,&n2);
    intervalo(n1, n2);
}

int intervalo(n1, n2){
    x = n2;
    if (x == n1){
        printf("%d",&x);
        return x;
    } else{
        printf("%d",&x);
        return 0;
    }
}

