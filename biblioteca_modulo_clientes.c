#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_animais.h"

/*Todas as funções de CRUD foram diretamente feitas com base nos Slides passados em aula*/

typedef struct cliente Cliente;
struct cliente {
    char nome[82];
    char cpf[12];
    char email[42];
    char telefone[12];
    bool status;

    Cliente *prox;//Parte de listagem dinâmica
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
    if(file == NULL){
        printf("Primeiro cliente cadastrado!\n");
        return true;
    }

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
void cabecalhoCliente(){
    printf("====================================\n");
    printf("| CPF | Nome | Email | Telefone | Qtd de Animais\n");
    printf("====================================\n");
}

void printaCliente(Cliente *cliente, int qtd){
    if (qtd>-1){
        printf("| %s | %s | %s | %s | %d |\n", cliente->cpf, cliente->nome, cliente->email, cliente->telefone, qtd);
    }else{
        printf("| %s | %s | %s | %s | :)Felicidade |\n", cliente->cpf, cliente->nome, cliente->email, cliente->telefone);
    }
    printf("====================================\n");
}

Cliente* cadastrarCliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    

    while (true){
        system("clear||cls");
        mostradorLogo();
        printf("#### CADASTRO ####\n");
        char *cpf = input("Digite o CPF do cliente: ");
        printf("CPF retornado: |%s|\n", cpf);
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
    printf("\t5. Listar clientes por ordem alfabetica\n");
    printf("\t6. Listar clientes por nome\n");
    printf("\t0. Voltar\n"); 

    printf("Digite sua opcao: ");
    scanf("%d", &opVerCliente);
    return opVerCliente;       
}

void listarCliente(void) {
    Cliente cliente;
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAGEM DE CLIENTES ####\n");

    FILE* file = fopen("clientes.dat", "rb");
    FILE* fileAni = fopen("animais.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.");
        return;
    }

    cabecalhoCliente();
    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        
        if (cliente.status == true) {

            int contadorAnimais = 0;
            if(fileAni != NULL){
                fseek(fileAni, 0, SEEK_SET);
            }

            Animal animal;
            
            if(fileAni != NULL){
                while (fread(&animal, sizeof(Animal), 1, fileAni) == 1) {
                    if (strcmp(animal.cpfDoCliente, cliente.cpf) == 0 && animal.status == true) {
                        contadorAnimais++;
                    }
                }
            }

            printaCliente(&cliente, contadorAnimais);
        }
    }

    fclose(file);
    if(fileAni != NULL){
        fclose(fileAni);
    }
    digiteEnter();
}

void pesquisarCliente(void){
    Cliente cliente;
    bool encontrado = false;
    char cpfPesquisa[12];

    FILE* fileAni = fopen("animais.dat", "rb");

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
            
            int contadorAnimais = 0;
            fseek(fileAni, 0, SEEK_SET);

            Animal animal;

            while (fread(&animal, sizeof(Animal), 1, fileAni) == 1){
                if(strcmp(animal.cpfDoCliente, cliente.cpf) == 0 && animal.status == true){
                    contadorAnimais++;
                }
            }            

            printf("==================================\n");
            printf("\tCPF: %s\n", cliente.cpf);
            printf("\tNome: %s\n", cliente.nome);
            printf("\tEmail: %s\n", cliente.email);
            printf("\tTelefone: %s\n", cliente.telefone);
            printf("\tQuantidade de animais cadastrados: %d\n", contadorAnimais);
            printf("==================================\n");
            encontrado = true;
            fclose(file);
            fclose(fileAni);
            break;
        }
    }

    if (encontrado == false){
        printf("Cliente nao encontrado! \n");
        fclose(file);
        fclose(fileAni);
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

            
                    long pos = -1L;

                    fseek(file, pos*sizeof(Cliente), SEEK_CUR);
                    fwrite(&cliente, sizeof(Cliente), 1, file);
                }    
            }
        }
    }
    fclose(file);
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
            limpaBuffer();
            
            cliente.status = false;
            long pos = -1L;
            fseek(file, pos*sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, file);

        }
    }
    fclose(file);
    digiteEnter();
}


//Função feita originalmente por Gabriel Canuto (Deus abençoe esse gordinho)
char *getCli(const char *cpf) {
    Cliente cliente;
    FILE *file = fopen("clientes.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            // CPF encontrado, aloca memória para o nome
            char *result = (char *)malloc(strlen(cliente.nome) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memoria.\n");
                fclose(file);
                return NULL;
            }

            // Copia o nome para o resultado e o retorna
            strcpy(result, cliente.nome);
            fclose(file);
            return result;
        }
    }

    // Se o CPF não for encontrado, retorna NULL
    fclose(file);
    return NULL;
}

//Feito com base nos slides de Flavius Gorgônio e no código de Gabriel Canuto
void ListagemDinamicaAlfabetica(){
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR CLIENTES EM ORDEM ALFABETICA ####\n");

    FILE *file = fopen("clientes.dat", "rb");

    if (file == NULL) { 
        printf("Erro ao abrir arquivo.\n");
        return;
    } 

    Cliente* cliente; 
    Cliente* lista;  

    lista = NULL;
    cliente = (Cliente*)malloc(sizeof(Cliente));

    if (cliente == NULL) {
        printf("Erro de alocacao de memoria\n");
    }

    while (fread(cliente, sizeof(Cliente), 1, file) == 1) {
        cliente->prox = NULL;

        if ((lista == NULL) || (strcmp(cliente->nome, lista->nome) < 0)) {
            cliente->prox = lista; 
            lista = cliente;  
        } else {  
            Cliente* anterior = lista;  
            Cliente* atual = lista->prox;   
            while ((atual != NULL) && strcmp(atual->nome, cliente->nome) < 0) { 
                anterior = atual;  
                atual = atual->prox; 
            }
            anterior->prox = cliente;
            cliente->prox = atual;
        }

        cliente = (Cliente*)malloc(sizeof(Cliente));
        if (cliente == NULL) {
            printf("Erro de alocacao de memoria\n");
        }
    }

    fclose(file);

    cliente = lista;

    cabecalhoCliente();
    while (cliente != NULL) { 
        if(cliente->status == true){
            printaCliente(cliente, -1);
            digiteEnter();
            cliente = cliente->prox; 
        }
    }

    cliente = lista; 
    while (lista != NULL) {
        lista = lista->prox; 
        free(cliente); 
        cliente = lista; 
    }
    digiteEnter();
}


void pesquisaClientePorNome() {
    system("clear || cls");
    mostradorLogo();
    printf("#### PESQUISAR CLIENTE POR NOME ####\n");

    char *nomePesquisa = input("Digite o nome que deseja pesquisar: ");

    FILE *file = fopen("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    Cliente *cliente;
    Cliente *lista;

    lista = NULL;
    cliente = (Cliente *)malloc(sizeof(Cliente));

    if (cliente == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }

    while (fread(cliente, sizeof(Cliente), 1, file) == 1) {
        cliente->prox = NULL;

        if ((lista == NULL) || (strcmp(cliente->nome, lista->nome) < 0)) {
            cliente->prox = lista;
            lista = cliente;
        } else {
            Cliente *anterior = lista;
            Cliente *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, cliente->nome) < 0) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = cliente;
            cliente->prox = atual;
        }

        cliente = (Cliente *)malloc(sizeof(Cliente));
        if (cliente == NULL) {
            printf("Erro de alocacao de memoria\n");
            break;
        }
    }

    fclose(file);

    // Pesquisar cliente por nome
    cliente = lista;
    bool encontrado = false;

    cabecalhoCliente();
    while (cliente != NULL) {
        if (strcmp(cliente->nome, nomePesquisa) == 0) {
            printaCliente(cliente, -1);
            encontrado = true;
        }
        cliente = cliente->prox;
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    // Libera a memória alocada para a lista
    cliente = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(cliente);
        cliente = lista;
    }

    digiteEnter();
}