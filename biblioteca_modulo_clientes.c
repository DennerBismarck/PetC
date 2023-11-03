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

int menuClientes(void){
    
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
            
            char *nome = input("Digite o nome do cliente: ");
            strncpy(cli->nome, nome, sizeof(cli->nome));

            char *telefone = input("Digite o telefone do cliente: ");
            if(validaTelefone(telefone)){
                strncpy(cli->telefone, telefone, sizeof(cli->telefone));

                char *email = input("Digite o email do cliente: ");
                strncpy(cli->email, email, sizeof(cli->email));

                cli->status = true;
                break;
            } else{
                printf("Digite um telefone valido.");
            }
        }else{
            printf("Digite um cpf valido.");
        }    
    }
}
void verCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CLIENTE ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}