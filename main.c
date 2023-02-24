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

char *AdicionarNome(char *ListaP);
char *RemoverNome(char *ListaP, char *nome);

int main(){
    
    int esc;
    char *lista = NULL;
    char nome[100];

   while (1){
        do{
            printf("\n");
            printf("1- Adicionar nome\n");
            printf("2- Remover nome\n");
            printf("3- Listar nomes\n");
            printf("4- Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &esc);
            printf("\n");
            switch (esc){
                case 1:
                    lista = AdicionarNome(lista);
                    break;
                case 2:
                    printf("Digite o nome: ");
                    scanf("%s", nome);
                    lista = RemoverNome(lista, nome);
                    break;
                case 3:
                    printf("%s\n", lista);
                    break;
                case 4:
                    return 0;
                    break;
            }
        } while (esc < 1 || esc > 4);
    }
}

char *AdicionarNome(char *ListaP){

    char nome[100];
    int tam;
    printf("Digite o nome: ");
    scanf("%s", nome);
    int idx = strlen(nome);
    nome[idx] = '-';
    nome[idx+1] = '\0';

    if (ListaP == NULL){
        tam = strlen(nome) + 2; 
        ListaP = malloc(sizeof(char) * tam);
        strcpy(ListaP, nome);
        return ListaP;
    }
    else{
        tam = strlen(ListaP) + strlen(nome) + 2;
        ListaP = realloc(ListaP, sizeof(char) * tam);
        strcat(ListaP, nome);
        return ListaP;
    }
}

char *RemoverNome(char *ListaP, char *nome){

    if (ListaP == NULL){
        printf("Não e possivel remover um nome");
        return ListaP;
    }

    char sep[2] = "-";
    char *nomes;
    char *listaCopia;
    int indexInicio = 0;
    int indexFinal;
    int len = strlen(ListaP);

    listaCopia = malloc(sizeof(char) * len);
    strcpy(listaCopia, ListaP);

    nomes = strtok(listaCopia, sep);

    while (nomes != NULL){
        if (strcmp(nomes, nome) == 0){
            indexFinal = indexInicio + strlen(nomes);
            memmove(&ListaP[indexInicio], &ListaP[indexFinal+1], len - indexFinal);
            ListaP = realloc(ListaP, sizeof(char) * (len - strlen(nome)) );
            return ListaP;
        }
        else{
            indexInicio += strlen(nomes) + 1;
        }
        nomes = strtok(NULL, sep);
    }

    printf("Nome nao encontrado");
    return ListaP;
}