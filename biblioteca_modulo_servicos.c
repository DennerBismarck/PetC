#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Struck de servicos*/
typedef struct servico Servico;

struct servico {
    int id;
    char nome[81];
    char valor[20];

    bool status;
};

int menuServicos(){
    int opMenuServicos;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU SERVICOS #####\n");
    printf("\t1. Cadastrar novo servico\n");
    printf("\t2. Ver Servicos\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuServicos);
    return opMenuServicos;   

}

void cadastrarServico(){
    system("clear||cls");
    mostradorLogo();
    Servico *ser;
    ser = (Servico*)malloc(sizeof(Servico));

    printf("#### CADASTRAR SERVICO ####\n");
    ser->id = sizeof(Servico)+1;

    char *nome = input("Digite o nome do servicoo: ");
    strncpy(ser->nome, nome, sizeof(ser->nome));;
    free(nome);

    while (true){
        char *valor = input("Digite o valor do servico (Formato R$X.XX)");
        if(!validaValor(ser->valor)){
            printf("Digite um valor valido.");
        }else{
            strncpy(ser->valor, valor, sizeof(ser->valor));
            free(valor);

            ser->status = true;

            break;
        }
    }
}