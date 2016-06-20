//
// Created by Evandson on 09/06/2016.
//
#include <stdio.h>
int main(){

    int i,j,soma,x;
    int m[2][2];
    m[0][0] = 3;
    m[0][1] = 6;
    m[1][0] = 5;
    m[1][1] = 4;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            x = m[i][j];
            if (x % 2 == 1) {
                soma += m[i][j];
            }
        }
    }
    printf("Resultado: %d",soma);
    return 0;

}



