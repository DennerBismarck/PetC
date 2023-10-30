#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Função do menu de clientes*/
int menuCliente(void){
    int opClientes;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU CLIENTES #####\n");
    printf("\t1. Cadastrar Cliente\n");
    printf("\t2. Ver Clientes\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opClientes);
    return opClientes;   
}
/*Subfunções do menu clientes*/
void cadastrarCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### CADASTRAR CLIENTE ####\n");
    printf("Nome\n");
    printf("CPF\n");
    printf("Email\n");
    printf("Senha\n");   
}
void verCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CLIENTE ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}