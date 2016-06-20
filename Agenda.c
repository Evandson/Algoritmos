//
// Created by Evandson Maranhão on 12/05/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *agenda;
    char nome[80], telefone[20];
    agenda = fopen("agenda.txt","w");
    fputs("*** Agenda de Contatos ***\n", agenda);
    do {
        printf("Nome: ");
        gets(nome);
        printf("telefone: ");
        gets(telefone);
        if (strcmp(nome, "fim") != 0){
            fprintf(agenda, "%s:%s\n", nome, telefone);
        }
    }while (strcmp(nome, "fim")!= 0);
        fclose(agenda);
    system("pause");
    return 0;
}

