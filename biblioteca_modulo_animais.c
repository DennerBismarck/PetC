#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_clientes.h"

typedef struct animal Animal;
struct animal{
    int id;
    char descricao[200];
};


int menuAnimal(void){
    int opAnimal;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU ANIMAIS #####\n");
    printf("\t1. Cadastrar animal\n");
    printf("\t2. Meus animais\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAnimal);
    return opAnimal;  
}

void createAnimal(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### CADASTRAR ANIMAL ####\n");
    printf("Descricao\n");
}

void meusAnimais(void){
    system("clear||cls");
    mostradorLogo();
    printf("#### MEUS ANIMAIS ####\n");
    printf("Listagem de animais\n");
    printf("Selecione seu animal: \n");
}
