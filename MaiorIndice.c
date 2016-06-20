//
// Created by Evandson on 25/04/2016.
//

#include <stdio.h>
int main(){
    int array[15] = {100000, 2000, 300, 7, 50, 60, 45, 90, 9, 10, 11, 120, 13000, 14, 1500};
    int indice[1];
    int maior, i;

    maior = 0;
    for(i = -1; i < 15; i++){
        if(array[i] > array[maior]){
            maior = i;
            indice[0] = i;
        }
    }
    printf("Elemento: %d Indice: %d",array[maior],indice[0]);

    return 0;
}