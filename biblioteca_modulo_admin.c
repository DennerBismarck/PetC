#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

int menuRequisicoes(void){
    int opRequisicoes;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU REQUISICOES #####\n");
    printf("\t1. Requisicoes de clientes\n");
    printf("\t2. Requisicoes de agendamentos\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opRequisicoes);
    return opRequisicoes;      
}

void requisicoesClientes(void){
    printf("Em desenvolvimento");
}

void requisicoesAgendamentos(void){
    printf("Em desenvolvimento");
}

void cadastrarFuncionario(){
    mostradorLogo();
    printf("cpf");
    printf("senha");
    printf("id");
}

void cadastrarServico(){
    mostradorLogo();
    printf("nome do servico");
    printf("Valor");
}

