#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"

/*Struck de servicos*/
typedef struct servico Servico;

struct servico {
    char nome[81];
    char valor[20];

    bool status;
};

int menuServicos(){
    int opMenuServicos;

    system("clear||cls");
    mostradorLogo();

    printf("##### MENU SERVICOS #####\n");
    printf("\t1. Cadastrar novo servico\n");
    printf("\t2. Listar todos os servicos\n");
    printf("\t3. Procurar por servico especifico\n");
    printf("\t4. Atualizar servico\n");
    printf("\t5. Deletar servico\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuServicos);
    return opMenuServicos;   

}

Servico* cadastrarServico(){
    system("clear||cls");
    mostradorLogo();
    Servico *ser;
    ser = (Servico*)malloc(sizeof(Servico));

    printf("#### CADASTRAR SERVICO ####\n");

    char *nome = input("Digite o nome do servicoo: ");
    strncpy(ser->nome, nome, sizeof(ser->nome));;
    free(nome);

    while (true){
        char *valor = input("Digite o valor do servico (Formato R$X.XX)");
        if(validaValor(valor) == false){
            printf("Digite um valor valido.\n");
        }else{
            strncpy(ser->valor, valor, sizeof(ser->valor));
            free(valor);

            ser->status = true;

            /*Trecho que salvará em arquivo*/
            FILE* file = fopen("servicos.dat", "ab");

            if (file == NULL){
                printf("Erro ao abrir arquivo.");
            }
            fwrite(ser, sizeof(Servico), 1, file); 

            free(ser);
            fclose(file);
            break;
            
        }
    }
}

void listarServicos(){
    Servico servico;
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAGEM DE SERVICOS ####\n");

    FILE* file = fopen("servicos.dat", "rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }


    while(fread(&servico, sizeof(Servico), 1, file) == 1){
        if(servico.status == true){
            printf("==================================\n");
            printf("\tNome: %s\n", servico.nome);
            printf("\tValor: %s\n", servico.valor);
            printf("==================================\n");
        }
    }
    digiteEnter();
    fclose(file);
}

void pesquisarServico(){
    Servico servico;
    bool encontrado = false;
    char nomePesquisa[81];

    system("clear || cls");
    mostradorLogo();
    printf("#### PESQUISAR SERVICO ####\n");

    strncpy(nomePesquisa, input("\nDigite o nome do servico que voce deseja pesquisar: "), sizeof(nomePesquisa));
    
    FILE * file = fopen("servicos.dat","rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&servico, sizeof(Servico), 1, file) == 1){
        if(strcmp(servico.nome, nomePesquisa) == 0){
            printf("==================================\n");
            printf("\tNome: %s\n", servico.nome);
            printf("\tValor: %s\n", servico.valor);
            printf("==================================\n");
            encontrado = true;
            fclose(file);
            break;
        }
    }

    if (encontrado == false){
        printf("Servico nao encontrado! \n");
        fclose(file);
    }
    digiteEnter();
}

void updateServico(){
    Servico servico;
    bool encontrado = false;
    char nomePesquisa[81];

    system("clear || cls");
    mostradorLogo();
    printf("#### EDITAR SERVICO ####\n");

    strncpy(nomePesquisa, input("\nDigite o nome do servico que voce deseja editar: "), sizeof(nomePesquisa));

    FILE* file = fopen("servicos.dat", "rb+");

    if (file == NULL) { 
        printf("Erro ao abrir arquivo.\n");
        return;
    }   
    while(fread(&servico, sizeof(Servico), 1, file) == 1){
        if (strcmp(servico.nome, nomePesquisa) == 0){
            printf("==================================\n");
            printf("\tNome: %s\n", servico.nome);
            printf("\tValor: %s\n", servico.valor);
            printf("==================================\n");
            printf("DIGITE AS NOVAS INFORMACOES\n");
            char *nome = input("Digite o nome do servicoo: ");
            strncpy(servico.nome, nome, sizeof(servico.nome));;
            free(nome);

            while (true){
                char *valor = input("Digite o valor do servico (Formato R$X.XX)");
                if(validaValor(valor) == false){
                    printf("Digite um valor valido.\n");
                    
                }else{
                    strncpy(servico.valor, valor, sizeof(servico.valor));
                    free(valor);
                    //GAMBIARRA PRA ESSA DESGRAÇA RODAR
                    long pos = -1L;

                    fseek(file, pos*sizeof(Servico), SEEK_CUR);
                    fwrite(&servico, sizeof(Servico), 1, file);
                    fclose(file);
                    break;
                }
            }     
        }
    }
}