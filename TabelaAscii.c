//
// Aula 28/04/2016.
//
//
#include <stdio.h>
int main(){
    char c, dif = 'a' - 'A';
    scanf("%c",&c);

    if(c >= 'a' && c <= 'z'){
        c = c - dif;
        printf("Resultado da conversao: %c\n", c);
    } else {
        printf("Caractere digitado não é letra minuscula");
    }
    return 0;
}
