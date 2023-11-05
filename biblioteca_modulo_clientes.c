#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Todas as funções de CRUD foram diretamente feitas com base nos Slides passados em aula*/

typedef struct cliente Cliente;
struct cliente {
    char nome[82];
    char cpf[12];
    char email[42];
    char telefone[12];
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
bool verificaExistenciaCPF(const char* CPFVerificado){
    Cliente cliente;
    bool encontrado = false;

    FILE * file = fopen("clientes.dat","rb");

    while(fread(&cliente, sizeof(Cliente), 1, file) == 1){
        if(strcmp(cliente.cpf, CPFVerificado) == 0 && cliente.status == true){
            encontrado = true;
            fclose(file);
            break;
            return false;
        }
    }
    if(encontrado == false){
        return true;
    }
}


Cliente* cadastrarCliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    

    while (true){
        system("clear||cls");
        mostradorLogo();
        printf("#### CADASTRO ####\n");
        char *cpf = input("Digite o CPF do cliente: ");
        if (validaCPF(cpf) && verificaExistenciaCPF(cpf)){
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
                    printf("Erro ao abrir arquivo.\n");
                }
                fwrite(cli, sizeof(Cliente), 1, file); 
                
                free(cli);

                fclose(file);

                break;

            } else{
                printf("Digite um telefone valido.\n");
                digiteEnter();
            }
        }else{
            printf("CPF invalido ou ja existente\n");
            digiteEnter();
        }    
    }
}
int verCliente(void){
    int opVerCliente;
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CLIENTE ####\n");
    printf("\t1. Listar todos os clientes\n");
    printf("\t2. Pesquisar diretamente por cliente\n");
    printf("\t3. Editar cliente\n"); 
    printf("\t4. Deletar cliente\n");
    printf("\t0. Voltar\n"); 

    printf("Digite sua opcao: ");
    scanf("%d", &opVerCliente);
    return opVerCliente;       
}

void listarCliente(void){
    Cliente cliente;
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAGEM DE CLIENTES ####\n");

    FILE* file = fopen("clientes.dat", "rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }


    while(fread(&cliente, sizeof(Cliente), 1, file) == 1){
        if(cliente.status == true){
            printf("==================================\n");
            printf("\tCPF: %s\n", cliente.cpf);
            printf("\tNome: %s\n", cliente.nome);
            printf("\tEmail: %s\n", cliente.email);
            printf("\tTelefone: %s\n", cliente.telefone);
            printf("==================================\n");
        }
    }
    digiteEnter();
    fclose(file);
}

void pesquisarCliente(void){
    Cliente cliente;
    bool encontrado = false;
    char cpfPesquisa[12];

    system("clear || cls");
    mostradorLogo();
    printf("#### PESQUISAR CLIENTE ####\n");
    while(true){
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja pesquisar: "), sizeof(cpfPesquisa));
        if (validaCPF(cpfPesquisa)){
            break;
        } else{
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }
    
    FILE * file = fopen("clientes.dat","rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&cliente, sizeof(Cliente), 1, file) == 1){
        if(strcmp(cliente.cpf, cpfPesquisa) == 0){
            printf("==================================\n");
            printf("\tCPF: %s\n", cliente.cpf);
            printf("\tNome: %s\n", cliente.nome);
            printf("\tEmail: %s\n", cliente.email);
            printf("\tTelefone: %s\n", cliente.telefone);
            printf("==================================\n");
            encontrado = true;
            fclose(file);
            break;
        }
    }

    if (encontrado == false){
        printf("Cliente nao encontrado! \n");
        fclose(file);
    }
    digiteEnter();
}


void updateCliente(){
    Cliente cliente;
    bool encontrado = false;
    char cpfPesquisa[12];

    system("clear || cls");
    mostradorLogo();
    printf("#### EDITAR CLIENTE ####\n");

    while(true){
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja editar: "), sizeof(cpfPesquisa));
        if (validaCPF(cpfPesquisa)){
            break;
        } else{
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }
    FILE* file = fopen("clientes.dat", "rb+");

    if (file == NULL) { 
        printf("Erro ao abrir arquivo.\n");
        return;
    }   
    while(fread(&cliente, sizeof(Cliente), 1, file) == 1){
        if (strcmp(cliente.cpf, cpfPesquisa) == 0){
            printf("==================================\n");
            printf("\tCPF: %s\n", cliente.cpf);
            printf("\tNome: %s\n", cliente.nome);
            printf("\tEmail: %s\n", cliente.email);
            printf("\tTelefone: %s\n", cliente.telefone);
            printf("==================================\n");
            printf("DIGITE AS NOVAS INFORMACOES\n");
            char *cpf = input("Digite o CPF do cliente: ");
            if (validaCPF(cpf)){
                strncpy(cliente.cpf, cpf, sizeof(cliente.cpf));
                free(cpf);

                char *nome = input("Digite o nome do cliente: ");
                strncpy(cliente.nome, nome, sizeof(cliente.nome));
                free(nome);

                char *telefone = input("Digite o telefone do cliente: ");
                if(validaTelefone(telefone)){
                    strncpy(cliente.telefone, telefone, sizeof(cliente.telefone));
                    free(telefone);

                    char *email = input("Digite o email do cliente: ");
                    strncpy(cliente.email, email, sizeof(cliente.email));
                    free(email);

                   //GAMBIARRA PRA ESSA DESGRAÇA RODAR
                    long pos = -1L;

                    fseek(file, pos*sizeof(Cliente), SEEK_CUR);
                    fwrite(&cliente, sizeof(Cliente), 1, file);
                    fclose(file);
                }    
            }
        }
    }
}

/*Exclusão do tipo lógica*/
void deleteCliente(){
    Cliente cliente;
    bool encontrado = false;
    char cpfPesquisa[12];

    system("clear || cls");
    mostradorLogo();
    printf("#### DELETAR CLIENTE ####\n");

    while(true){
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja deletar: "), sizeof(cpfPesquisa));
        if (validaCPF(cpfPesquisa)){
            break;
        } else{
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }
    FILE* file = fopen("clientes.dat", "rb+");

    if (file == NULL) { 
        printf("Erro ao abrir arquivo.\n");
        return;
    }   
    while(fread(&cliente, sizeof(Cliente), 1, file) == 1){
        if (strcmp(cliente.cpf, cpfPesquisa) == 0){
            printf("==================================\n");
            printf("\tCPF: %s\n", cliente.cpf);
            printf("\tNome: %s\n", cliente.nome);
            printf("\tEmail: %s\n", cliente.email);
            printf("\tTelefone: %s\n", cliente.telefone);
            printf("==================================\n");
            fflush(stdin);

            cliente.status = false;
            long pos = -1L;
            fseek(file, pos*sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, file);
            fclose(file);

        
        }
    }
    digiteEnter();
}
