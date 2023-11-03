#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Struck de servicos*/
typedef struct servico Servico;

struct servico {
    int id;
    char nome[81];
    char valor[20];

    bool status;
};

void cadastrarServico(){
    system("clear||cls");
    mostradorLogo();
    Servico *ser;
    ser = (Servico*)malloc(sizeof(Servico));

    printf("#### CADASTRAR SERVICO ####\n");
    ser->id = sizeof(Servico)+1;
    ser->nome == input("Digite o nome do servico: ");
    while (true){
        ser->valor == input("Digite o valor do servico (Formato R$X.XX)");
        if(!validaValor(ser->valor)){
            printf("Digite um valor valido.");
        }else{
            break;
        }
    }
}