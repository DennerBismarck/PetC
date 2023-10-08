#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*função do menu principal*/

int menuPrincipal(void){
    int opMenuPrincipal;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU PRINCIPAL #####\n");
    printf("\t1. Atendimentos\n");
    printf("\t2. Sobre\n");
    printf("\t3. Login ou Cadastro\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuPrincipal);
    return opMenuPrincipal;   

}

int menuAutenticacao(void){
    int opMenuCadastroLogin;
    
    system("clear||cls");
    mostradorLogo();

    printf("##### MENU AUTENTICACAO #####\n");
    printf("\t1. Login\n");
    printf("\t2. Cadastro\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuCadastroLogin);
    return opMenuCadastroLogin;   

}

void logar(){

    char cpf[15];
    char senha[100];

    system("clear||cls");
    mostradorLogo();

    printf("##### LOGAR #####\n");
    printf("Digite seu cpf: ");
    scanf("%14s",cpf);
    printf("Digite sua senha: ");
    scanf("%99s", senha);
}
