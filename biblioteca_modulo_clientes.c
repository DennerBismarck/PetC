#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

typedef struct cliente Cliente;
struct cliente {
    char nome[81];
    char cpf[11];
    char email[41];
    char telefone[11];
    bool status;
};

int menuCliente(void){
    int opMenuCliente;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU CLIENTES #####\n");
    printf("\t1. Cadastrar novo cliente\n");
    printf("\t2. Ver clientes\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuCliente);
    return opMenuCliente;      
}
/*Subfunções do menu clientes*/
Cliente* cadastrarCliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    

    while (true){
        system("clear||cls");
        mostradorLogo();
        printf("#### CADASTRO ####\n");
        char *cpf = input("Digite o CPF do cliente: ");
        if (validaCPF(cpf)){
            strncpy(cli->cpf, cpf, sizeof(cli->cpf));
            free(cpf);
            
            char *nome = input("Digite o nome do cliente: ");
            strncpy(cli->nome, nome, sizeof(cli->nome));
            free(nome);

            char *telefone = input("Digite o telefone do cliente: ");
            if(validaTelefone(telefone)){
                strncpy(cli->telefone, telefone, sizeof(cli->telefone));
                free(telefone);

                char *email = input("Digite o email do cliente: ");
                strncpy(cli->email, email, sizeof(cli->email));
                free(email);

                cli->status = true;

                /*Trecho que salvará em arquivo*/
                FILE* file = fopen("clientes.dat", "ab");

                if (file == NULL){
                    printf("Erro ao abrir arquivo.");
                }
                fwrite(cli, sizeof(Cliente), 1, file); 

                break;

            } else{
                printf("Digite um telefone valido.\n");
                digiteEnter();
            }
        }else{
            printf("Digite um cpf valido.\n");
            digiteEnter();
        }    
    }
}
void verCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CLIENTE ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}
