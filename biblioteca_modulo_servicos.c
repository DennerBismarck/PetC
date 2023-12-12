#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_atendimentos.h"

int ultimoID;

/*Struck de servicos*/
typedef struct servico Servico;

struct servico {
    int id;
    char nome[81];
    char valor[20];

    bool status;

    Servico *prox;
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
    printf("\t6. Listar servicos com um valor\n");
    printf("\t7. Listar servicos por ordem decescente de preco\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opMenuServicos);
    return opMenuServicos;   

}

int retornaUltimoIDServico() {
    Servico servico;

    FILE *file = fopen("servicos.dat", "rb");

    int ultimoID = 0;

    if (file != NULL) {
        long pos = -1L;
        fseek(file, pos*sizeof(Servico), SEEK_END);

        if (fread(&servico, sizeof(Servico), 1, file) == 1) {
            ultimoID = servico.id;
            return ultimoID;
        }

        fclose(file);
    }

    return 0; 
}

bool checaServicoID(const int* idServico) {
    Servico servico;
    bool encontrado = false;

    FILE * file = fopen("servicos.dat", "rb");

    if (file == NULL){
        return false;
    }

    while (fread(&servico, sizeof(Servico), 1, file) == 1) {
        if (servico.id == *idServico && servico.status == true) {
            encontrado = true;
            break;
        }
    }

    fclose(file); 

    return encontrado;  
}

void cabecalhoServico(){
    printf("====================================\n");
    printf("| ID | Nome | Preço | Qtd Agendamentos |\n");
    printf("====================================\n");
}

void printaServico(Servico *servico, int qtd){
    if(qtd>-1){
        printf("| %d | %s | %s | %d |\n", servico->id, servico->nome, servico->valor, qtd);
    }else{
        printf("| %d | %s | %s | ( ͡° ͜ʖ ͡°) |\n", servico->id, servico->nome, servico->valor);
    }

    printf("====================================\n");
}

bool checaExistenciaServico(const char* nomeVerificado){
    Servico servico;
    bool encontrado = false;

    FILE * file = fopen("servicos.dat","rb");

    if (file == NULL){
        printf("Primeiro servico cadastrado! \n");
        return true;
    }

    while(fread(&servico, sizeof(Servico), 1, file) == 1){
        if(strcmp(servico.nome, nomeVerificado) == 0 && servico.status == true){
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

Servico* cadastrarServico(){
    system("clear||cls");
    mostradorLogo();
    Servico *ser;
    ser = (Servico*)malloc(sizeof(Servico));

    printf("#### CADASTRAR SERVICO ####\n");

    while (true){
        char *nome = input("Digite o nome do servicoo: ");
        if (checaExistenciaServico(nome)){
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

                    ser->id = retornaUltimoIDServico()+1;                    

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
            break;
        } else{
            printf("Ja existe um servico cadastrado com este nome!\n");
        }

        digiteEnter();
    }
}

void listarServicos() {
    Servico servico;

    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAGEM DE SERVICOS ####\n");

    FILE* file = fopen("servicos.dat", "rb");
    FILE* fileAte = fopen("atendimentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.");
        return;
    }

    cabecalhoServico();
    while (fread(&servico, sizeof(Servico), 1, file) == 1) {
        if (servico.status == true) {

            int contadorServico = 0;

            if (fileAte != NULL){
                fseek(fileAte, 0, SEEK_SET);
                Atendimento atendimento;
                while (fread(&atendimento, sizeof(Atendimento), 1, fileAte) == 1) {
                    if (atendimento.idDoservico == servico.id && atendimento.status == true) {
                        contadorServico++;
                    }
                }
            }

        printaServico(&servico, contadorServico);
            
        }
    }

    fclose(file);
    if(fileAte != NULL){
        fclose(fileAte);
    }
    digiteEnter();
}


void pesquisarServico() {
    Servico servico;
    Atendimento atendimento;
    bool encontrado = false;
    char nomePesquisa[82];

    system("clear || cls");
    mostradorLogo();
    printf("#### PESQUISAR SERVICO ####\n");

    strncpy(nomePesquisa, input("\nDigite o nome do servico que voce deseja pesquisar: "), sizeof(nomePesquisa));

    FILE *fileServico = fopen("servicos.dat", "rb");
    FILE *fileAtendimento = fopen("atendimentos.dat", "rb");

    if (fileServico == NULL || fileAtendimento == NULL) {
        printf("Erro ao abrir arquivos.");
        return;
    }

    
    int contadorAgendado = 0;

    while (fread(&servico, sizeof(Servico), 1, fileServico) == 1) {
        
        if (servico.status == true && strcasecmp(servico.nome, nomePesquisa) == 0) {
            
            contadorAgendado = 0;

            
            while (fread(&atendimento, sizeof(Atendimento), 1, fileAtendimento) == 1) {
                if (atendimento.idDoservico == servico.id) {
                    contadorAgendado++;
                }
            }

            
            printf("==================================\n");
            printf("\tID: %i\n", servico.id);
            printf("\tNome: %s\n", servico.nome);
            printf("\tValor: %s\n", servico.valor);
            printf("\tQuantidade de vezes agendado: %d\n", contadorAgendado);
            printf("==================================\n");

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Servico nao encontrado! \n");
    }

    fclose(fileServico);
    fclose(fileAtendimento);
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
                    
                    long pos = -1L;

                    fseek(file, pos*sizeof(Servico), SEEK_CUR);
                    fwrite(&servico, sizeof(Servico), 1, file);
                    break;
                }
            }     
        }
    }
    fclose(file);
}

void deleteServico(){
    Servico servico;
    bool encontrado = false;
    char nomePesquisa[81];

    system("clear || cls");
    mostradorLogo();
    printf("#### DELETAR SERVICO ####\n");

    strncpy(nomePesquisa, input("\nDigite o nome do servico que voce deseja deletar: "), sizeof(nomePesquisa));

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
            servico.status = false;

            long pos = -1L;

            fseek(file, pos*sizeof(Servico), SEEK_CUR);
            fwrite(&servico, sizeof(Servico), 1, file);
            break;
        }
    }
    fclose(file);
    digiteEnter();    
}

void listarServicoValor(){
    Servico servico;
    bool encontrado = false;
    char *valorPesquisa;

    system("clear || cls");
    mostradorLogo();
    printf("#### PESQUISAR SERVICO ####\n");

    while (true){
        valorPesquisa =  input("\nDigite o valor que voce deseja filtrar (R$X.XX): ");
        if(validaValor(valorPesquisa)){
            break;
        }else{
            printf("Digite um valor valido!\n");
        }
    }

    
    FILE * file = fopen("servicos.dat","rb");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    cabecalhoServico();
    while(fread(&servico, sizeof(Servico), 1, file) == 1){
        if(strcmp(servico.valor, valorPesquisa) == 0){
            printaServico(&servico, -1);
            encontrado = true;
        }
    }

    if (encontrado == false){
        printf("Nenhum servico encontrado! \n");
    }
    fclose(file);
    digiteEnter();
}

void listagemServicoPrecos() {
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR SERVICOS POR ORDEM DE PRECO ####\n");

    FILE *file = fopen("servicos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    Servico *servico;
    Servico *lista;

    lista = NULL;
    servico = (Servico *)malloc(sizeof(Servico));

    if (servico == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    
    while (fread(servico, sizeof(Servico), 1, file) == 1) {
        servico->prox = NULL;

        if ((lista == NULL) || (atof(servico->valor + 2) > atof(lista->valor + 2))) {
            servico->prox = lista;
            lista = servico;
        } else {
            Servico *anterior = lista;
            Servico *atual = lista->prox;
            while ((atual != NULL) && (atof(servico->valor + 2) < atof(atual->valor + 2))) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = servico;
            servico->prox = atual;
        }

        servico = (Servico *)malloc(sizeof(Servico));
        if (servico == NULL) {
            printf("Erro de alocacao de memoria\n");
            break;
        }
    }

    fclose(file);

    servico = lista;

    cabecalhoServico();
    while (servico != NULL) {
        printaServico(servico, -1);
        digiteEnter();
        servico = servico->prox;
    }

    servico = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(servico);
        servico = lista;
    }
}
