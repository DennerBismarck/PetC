#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*função do menu principal*/

int menuPrincipal(void){
    int opMenuPrincipal;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU PRINCIPAL #####\n");
    printf("\t1. Atendimentos\n");
    printf("\t2. Sobre\n");
    printf("\t3. Clientes\n");
    printf("\t4. Servicos\n");
    printf("\t5. Animais\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuPrincipal); fflush(stdin);
    return opMenuPrincipal;   

}
