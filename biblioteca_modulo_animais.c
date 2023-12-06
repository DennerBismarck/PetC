#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_clientes.h"

int contadorIDAnimal;

typedef struct animal Animal;
struct animal{
    int id;
    char descricao[200];
    char cpfDoCliente[12];
    bool status;
};

bool checaAnimalID(const int* idAnimal){
    Animal animal;
    bool encontrado = false;

    FILE * file = fopen("animal.dat","rb");

    while(fread(&animal, sizeof(Animal), 1, file) == 1){
        if(animal.id == *idAnimal && animal.status == true){
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


int retornaUltimoIDAnimal() {
    Animal animal;

    FILE *file = fopen("animais.dat", "rb");

    int contadorIDAnimal = 0;

    if (file != NULL) {
        long pos = -1L;
        fseek(file, pos*sizeof(Animal), SEEK_END);

        if (fread(&animal, sizeof(Animal), 1, file) == 1) {
            contadorIDAnimal = animal.id;
            return contadorIDAnimal;
        }

        fclose(file);
    }

    return 0; 
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
    printf("\t5. Listar todos os animais\n");
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
                
                ani->id = retornaUltimoIDAnimal()+1;

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

void readAnimal(void) {
    Animal animal;
    Cliente cliente;

    bool encontrado = false;
    char cpfPesquisa[12];

    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR ANIMAIS DE UM CLIENTE ####\n");

    while (true) {
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja pesquisar: "), sizeof(cpfPesquisa));
        if (!verificaExistenciaCPF(cpfPesquisa)) {
            break;
        } else {
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }

    FILE *file = fopen("animais.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.");
        return;
    }

    while (fread(&animal, sizeof(Animal), 1, file) == 1) {
        if (strncmp(animal.cpfDoCliente, cpfPesquisa, sizeof(animal.cpfDoCliente)) == 0 && animal.status == true) {
            printf("==================================\n");
            printf("\tID do animal: %i\n", animal.id);
            printf("\tDescricao: %s\n", animal.descricao);
            printf("\tCPF do cliente: %s\n", animal.cpfDoCliente);
            printf("\tNome do cliente dono: %s\n", getCli(cpfPesquisa));
            printf("==================================\n");

            encontrado = true;
        }
    }

    if (encontrado == false) {
        printf("Nenhum animal encontrado! \n");
    }

    fclose(file);
    digiteEnter();
}


void  updateAnimal(){
    readAnimal();

    Animal animal;
    bool encontrado = false;
    int escolhaNumero;

    while (true){
        const char* escolha = input("Digite o id do animal que voce deseja editar: ");
        if(verificaNumero(*escolha)){
            escolhaNumero = atoi(escolha);
            break;
        }else{
            printf("Digite um id valido!\n");
        }
    }
    

    FILE * file = fopen("animais.dat","rb+");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&animal, sizeof(Animal), 1, file) == 1){
        if(animal.id == escolhaNumero && animal.status == true){
            printf("==================================\n");
            printf("\tID do animal: %i\n", animal.id);
            printf("\tCPF do cliente: %s\n", animal.cpfDoCliente);
            printf("\tDescricao: %s\n", animal.descricao);
            printf("==================================\n");
            encontrado = true;

            while (true){
                char *cpf = input("Digite o CPF do dono: ");
                if (validaCPF(cpf)){
                        strncpy(animal.cpfDoCliente, cpf, sizeof(animal.cpfDoCliente));
                        free(cpf);

                        char * desc = input("Digite a descricao do animal: ");
                        strncpy(animal.descricao, desc, sizeof(animal.descricao));
                        free(desc);

                        long pos = -1L;
                        fseek(file, pos*sizeof(Animal), SEEK_CUR);
                        fwrite(&animal, sizeof(Animal), 1, file);
                        break;

                }else{
                    printf("Digite um cpf valido!");
                }
            }
            break;
        }
    }
    if (encontrado == false){
        printf("Digite um id valido! \n");
    }
    fclose(file);
    digiteEnter();
}

void deleteAnimal(){
    readAnimal();

    Animal animal;
    bool encontrado = false;
    int escolhaNumero;

    while (true){
        const char* escolha = input("Digite o id do animal que voce deseja deletar: ");
        if(verificaNumero(*escolha)){
            escolhaNumero = atoi(escolha);
            break;
        }else{
            printf("Digite um id valido!\n");
        }
    }
    

    FILE * file = fopen("animais.dat","rb+");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&animal, sizeof(Animal), 1, file) == 1){
        if(animal.id == escolhaNumero){
            encontrado = true;

            animal.status = false;

            long pos = -1L;
            fseek(file, pos*sizeof(Animal), SEEK_CUR);
            fwrite(&animal, sizeof(Animal), 1, file);
            break;

        }
    }
    if (encontrado == false){
        printf("Digite um id valido! \n");
    }
    fclose(file);
    digiteEnter();    
}

void listarTodosAnimais(){

    Animal animal;

    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR TODOS OS ANIMAIS ####\n");
    
    FILE * file = fopen("animais.dat","rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&animal, sizeof(Animal), 1, file) == 1){
        if(animal.status == true){
            printf("==================================\n");
            printf("\tID do animal: %i\n", animal.id);
            printf("\tCPF do cliente: %s\n", animal.cpfDoCliente);
            printf("\tDescricao: %s\n", animal.descricao);
            printf("\tNome do cliente dono: %s\n", getCli(animal.cpfDoCliente));
            printf("==================================\n");
        }
    }
    
    fclose(file);
    digiteEnter();
}