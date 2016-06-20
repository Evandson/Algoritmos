#include <stdio.h>
int main(){
    int n, i, maior, turma=1, codigo[500], nota[500];

    scanf("%d", &n);
    while (n > 0) {
        for (i = 0; i < n; i++){
            scanf("%d %d", &codigo[i], &nota[i]);
        }
        maior = 0;
        for (i = 1; i < n; i++){
            if (nota[i] > nota[maior]){
                maior = i;
            }
        }
        printf("Turma %d\n%d\n\n", turma++, codigo[maior]);
        scanf("%d", &n);
    }
    return 0;
}
