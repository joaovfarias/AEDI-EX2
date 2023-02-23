/*
Faça um programa que armazena nomes.
O programa deve armazenar todos os nomes na mesma string.
O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos. 
Não pode ter desperdício de memória.
Faça o seguinte menu:
1) Adicionar nome
2) Remover nome
3) Listar
4) Sair
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AdicionarNome(char **listaNomes);

int main(){

    char *lista = NULL;
    AdicionarNome(&lista);
    AdicionarNome(&lista);
    printf("%s", lista);
    
}

void AdicionarNome(char **listaNomes){

    char nome[100] = "joao";
    int tam;

    if (*listaNomes == NULL){
        tam = strlen(nome);
        *listaNomes = malloc(sizeof(char) * tam);
        strcpy(*listaNomes, nome);
    }
    else{
        tam = strlen(*listaNomes) + strlen(nome);
        *listaNomes = realloc(*listaNomes, (sizeof(char) * tam));
        strcat(*listaNomes, nome);
    }
}

