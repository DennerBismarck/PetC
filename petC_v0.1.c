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
void menuPrincipal(void){
    system("clear||cls");

    mostradorLogo();
    
    char opMenuPrincipal[1];

    printf("##### MENU PRINCIPAL #####\n");
    printf("\t1. Atendimentos\n");
    printf("\t2. Clientes\n");
    printf("\t3. Loja\n");
    printf("\t4. Sobre\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%s", opMenuPrincipal);   

    while (strcmp(opMenuPrincipal, "0") != 0){     
        if (strcmp(opMenuPrincipal, "1") == 0){
            menuAtendimentos();
        }else if (strcmp(opMenuPrincipal, "2") == 0){
            printf("uiui");
        } else if(strcmp(opMenuPrincipal, "3") == 0){
            printf("uiui");
        }else if (strcmp(opMenuPrincipal, "4") == 0){
            printf("uiui");
        }
        else{
            printf("\tDigite uma opcao valida!");
        }
        printf("\tPRESSIONE ENTER PARA CONTINUAR");
        getchar();
        printf("Digite sua opcao: ");
        scanf("%s", opMenuPrincipal);  
    }
}
/*Função main do código*/
int main(){
    menuPrincipal();

    return 0;
}
