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
    char senha[100];

    bool status;
};

/*Subfunções do menu clientes*/
Cliente* cadastrarCliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    while (true){
        system("clear||cls");
        mostradorLogo();
        printf("#### CADASTRO ####\n");
        cli->cpf == input("Digite seu CPF: ");
        if (validaCPF(cli->cpf)){
            cli->nome == input("Digite seu nome: ");
            cli->email == input("Digite seu email: ");
            cli->senha == input("Digite sua senha: ");
            cli->status = true;
            break;
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