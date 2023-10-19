#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Função do menu Atendimentos*/
int menuAtendimentos(void){
    int opAtendimentos;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU ATENDIMENTOS #####\n");
    printf("\t1. Agendar novo atendimento\n");
    printf("\t2. Tabela de atendimentos\n");
    printf("\t3. Minhas agendas\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAtendimentos);
    return opAtendimentos;      
}
void agendarProcedimento(){
    system("clear||cls");
    mostradorLogo();
    printf("#### AGENDAR PROCEDIMENTO ####\n");
    printf("Selecione a data: \n");
    printf("Selecione a hora: \n");   
}
void verProcedimentos(){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER PROCEDIMENTOS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}

void tabelaProcedimentos(){
    system("clear||cls");
    mostradorLogo();
    printf("#### TABELA DE PROCEDIMENTOS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}