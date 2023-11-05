#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_clientes.h"

typedef struct animal Animal;
struct animal{
    char descricao[200];
    char cpfDoCliente[12];

    bool status;
};

bool checaExistenciaAnimal(const char *animalVerificado, const char *cpfVerificado) {
    Animal animal;
    bool encontrado = false;

    FILE *file = fopen("animais.dat", "rb");

    if (file == NULL) {
        return false;
    }

    while (fread(&animal, sizeof(Animal), 1, file) == 1) {
        if (strcmp(animal.descricao, animalVerificado) == 0 && strcmp(animal.cpfDoCliente, cpfVerificado) == 0 && animal.status == true) {
            encontrado = true;
            break;  
        }
    }

    fclose(file); 

    return encontrado;
}


int menuAnimal(void){
    int opAnimal;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU ANIMAIS #####\n");
    printf("\t1. Cadastrar animal\n");
    printf("\t2. Listar animais de um cliente\n");
    printf("\t3. Editar animal\n");
    printf("\t4. Deletar animal\n");
    printf("\t0. Sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAnimal);
    return opAnimal;  
}

Animal* createAnimal(void){
    system("clear||cls");
    mostradorLogo();
    Animal *ani;
    ani = (Animal*)malloc(sizeof(Animal));

    printf("#### CADASTRAR ANIMAL ####\n");

    while (true){
        char *cpf = input("Digite o cpf do cliente dono deste animal: ");
        if (!verificaExistenciaCPF(cpf)){
            char *desc = input("Digite a descricao do animal: ");
            if (checaExistenciaAnimal(desc, cpf) == false){
                strncpy(ani->cpfDoCliente, cpf, sizeof(ani->cpfDoCliente));
                free(cpf);

                strncpy(ani->descricao, desc,sizeof(ani->descricao));
                free(desc);

                ani->status = true;

                /*Trecho que salvará em arquivo*/
                FILE* file = fopen("animais.dat", "ab");

                if (file == NULL){
                    printf("Erro ao abrir arquivo.");
                }
                fwrite(ani, sizeof(Animal), 1, file); 

                free(ani);
                fclose(file);
                break;
            }else{
                printf("Ja existe um animal com esse cadastro!\n");
            }
        }
    }
    digiteEnter();
}

void readAnimal(void){
    Animal animal;
    bool encontrado = false;
    char cpfPesquisa[12];

    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR ANIMAIS DE UM CLIENTE ####\n");
    while(true){
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja pesquisar: "), sizeof(cpfPesquisa));
        if (!verificaExistenciaCPF(cpfPesquisa)){
            break;
        } else{
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }
    
    FILE * file = fopen("animais.dat","rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&animal, sizeof(Animal), 1, file) == 1){
        if(strcmp(animal.cpfDoCliente, cpfPesquisa) == 0){
            printf("==================================\n");
            printf("\tCPF do cliente: %s\n", animal.cpfDoCliente);
            printf("\tDescricao: %s\n", animal.descricao);
            printf("==================================\n");
            encontrado = true;
        }else{
            printf("%s %s", animal.cpfDoCliente, cpfPesquisa);
        }
    }
    if (encontrado == false){
        printf("Nenhum animal encontrado! \n");
    }
    fclose(file);
    digiteEnter();
}