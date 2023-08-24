#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Declaração das funções*/
void mostradorLogo(void);
void menuAtendimentos(void);
void menuCliente(void);
void menuLoja(void);
void menuSobre(void);

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
void menuAtendimentos(void){
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU ATENDIMENTOS #####\n");
    printf("##### EM DESENVOLVIMENTO...\n");
}

/*Função do menu de clientes*/
void menuCliente(void){
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU CLIENTES #####\n");
    printf("##### EM DESENVOLVIMENTO...\n");
}

/*Função do menu Loja*/
void menuLoja(void){
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU LOJA #####\n");
    printf("##### EM DESENVOLVIMENTO...\n");
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
    int opMenuPrincipal = menuPrincipal();
    while (opMenuPrincipal != 0) { 
        if (opMenuPrincipal == 1){
            menuAtendimentos();
        } else if (opMenuPrincipal == 2){
            menuCliente();
        } else if (opMenuPrincipal == 3){
            menuLoja();          
        } else if (opMenuPrincipal == 4){
            menuSobre();
        } else{
            printf("\tDigite novamente!\n");
        }
        printf("Digite Enter para continuar");
        getchar();
        getchar();  
        opMenuPrincipal = menuPrincipal();
        printf("====================================\n");  
    }
    return 0;
}