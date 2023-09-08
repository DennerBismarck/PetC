#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Declaração das funções principais*/
void mostradorLogo(void);
int menuAtendimentos(void);
int menuCliente(void);
int menuLoja(void);
void menuSobre(void);
int menuPrincipal(void);

/*Declaração das subfunções de cada módulo*/
int menuConsultas(void);
void createConsulta(void);
void verConsultas(void);

int menuProcedimentos(void);
void agendarProcedimento(void);
void verProcedimentos(void);

void cadastrarCliente(void);
void verCliente(void);

int menuProdutos(void);
void cadastrarProduto(void);
void verProduto(void);

int menuVendas(void);
void cadastrarVenda(void);
void verVenda(void);

/*Função da logo principal*/
void mostradorLogo(void){
    printf("       /^-^\\         /^-----^\"\n");
    printf("      / o o \\        V  o o  V\n");
    printf("     /   Y   \\        |  Y  |\n");
    printf("     V \\ v / V         \\ Q /\n");
    printf("       / - \\           / - \"\n");
    printf("      /    |           |    \"\n");
    printf("(    /     |           |     \\     )\n");
    printf(" ===/___) ||           || (___\\====\n");
    printf("\n");
    printf("##### PETC: ONDE SEU PET EH MAIS QUE UMA GARRAFA! #####\n");
    printf("\n");
}

/*Função do menu Atendimentos*/
int menuAtendimentos(void){
    int opAtendimentos;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU ATENDIMENTOS #####\n");
    printf("\t1. Consultas\n");
    printf("\t2. Procedimentos esteticos\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAtendimentos);
    return opAtendimentos;      
}

/*SubFunções de Atendimentos*/
int menuConsultas(void){
    int opConsultas;
    system("clear||cls");
    mostradorLogo();
    printf("#### MENU CONSULTAS ####\n");
    printf("\t1. Agendar nova consulta\n");
    printf("\t2. Ver consultas\n");
}
/*Subfunções do menu consultas*/
void createConsulta(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### AGENDAR CONSULTA ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}
void verConsultas(void){
    int opConsultas;
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CONSULTAS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}

int menuProcedimentos(){
    int opProcedimentos;
    system("clear||cls");
    mostradorLogo();
    printf("#### MENU PROCEDIMENTOS #### \n");
    printf("\t1. Agendar procedimento");
    printf("\t2. Ver procedimentos");
}
void agendarProcedimento(){
    system("clear||cls");
    mostradorLogo();
    printf("#### AGENDAR PROCEDIMENTO ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");   
}
void verProcedimentos(){
    int opProcedimentos;
    system("clear||cls");
    mostradorLogo();
    printf("#### VER PROCEDIMENTOS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}


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
    printf("#### EM DESENVOLVIMENTO ####\n");   
}
void verCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER CLIENTE ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}


/*Função do menu Loja*/
int menuLoja(void){
    int opLoja;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU LOJA #####\n");
    printf("\t1. Produtos\n");
    printf("\t2. Vendas\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opLoja);
    return opLoja; 
}

/*Subfunções do menu Loja*/
int menuProdutos(void){
    int opProdutos;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU PRODUTOS #####\n");
    printf("\t1. Cadastrar produto\n");
    printf("\t2. Ver produto\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opProdutos);
    return opProdutos;     
}

void cadastrarProduto(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### CADASTRAR PRODUTO ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");   
}

void verProduto(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER PRODUTO ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}

int menuVendas(void){
    int opVendas;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU PRODUTOS #####\n");
    printf("\t1. Realizar venda\n");
    printf("\t2. Relatorio de vendas\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opVendas);
    return opVendas;         
}

void cadastrarVenda(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### VENDA ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");       
}

void verVenda(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### RELATORIO DE VENDAS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");         
}

/*Função do menu Sobre*/
void menuSobre(void){
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU SOBRE #####\n");
    printf("\tUNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE \n");
    printf("\tCENTRO DE ENSINO SUPERIOR DO SERIDO\n");
    printf("\tDEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA\n");
    printf("\tDISCIPLINA DCT1106: PROGRAMAÇÃO\n");
    printf("\tPROJETO DE UM SOFTWARE PARA GESTÃO DE PETSHOP\n");
    printf("\tDESENVOLVIDO POR DENNER BISMARCK DE LUCENA FRANÇA\n");
}


/* Função do menu principal */
int menuPrincipal(void){
    int opMenuPrincipal;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU PRINCIPAL #####\n");
    printf("\t1. Atendimentos\n");
    printf("\t2. Clientes\n");
    printf("\t3. Loja\n");
    printf("\t4. Sobre\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuPrincipal);
    return opMenuPrincipal;   

}
/*Função main do código*/
int main(){
    int opMenuPrincipal;
    do{
        opMenuPrincipal = menuPrincipal();
        switch (opMenuPrincipal){
        case 1:
            menuAtendimentos();
            break;
        case 2:
            menuCliente();
            break;
        case 3:
            menuLoja();
            break;
        case 4:
            menuSobre();   
            break;
        case 0:
            printf("================================\n");
            break;         
        default:
            printf("Digite novamente!");
            break;
        printf("Digite Enter para continuar");
        getchar();
        getchar();  
        printf("====================================\n");        
        }
    } while (opMenuPrincipal != 0);
    return 0;
}