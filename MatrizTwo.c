//
// Created by Evandson on 09/06/2016.
//
#include <stdio.h>

int main(){
    int i,j,cont,y;
    int m[3][3];
    cont = 1;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            m[i][j] = cont++;
            y = m[i][j];
            printf("Indice: %d\n",y);
        }
    }

    return 0;
}
