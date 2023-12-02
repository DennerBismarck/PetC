#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_animais.h"
#include "biblioteca_modulo_clientes.h"
#include "biblioteca_modulo_servicos.h"

int ultimoIDAtendimento;


typedef struct atendimento Atendimento;
struct atendimento{
    int id;
    char data[11];
    char hora[5];
    char cpfDoCliente[12];
    int idDoanimal;
    int idDoservico;

    bool status;
};

/*Verifica conflito de horários com um limiar de 30 minutos entre cada atendimento*/
bool verificaExistenciaAtendimento(char dataAgenda[9], char horaAgenda[5]){
    Atendimento atendimento;
    bool encontrado = false;

    FILE *file = fopen("atendimentos.dat", "rb");
    while (fread(&atendimento, sizeof(Atendimento), 1, file) == 1) {
        if(atendimento.status && strcmp(atendimento.data, dataAgenda) == 0){

            int horaAtual = atoi(atendimento.hora);
            int minutoAtual = atoi(atendimento.hora + 3);
            int horaNova = atoi(horaAgenda);
            int minutoNova = atoi(horaAgenda + 3);

            int minutosAtuais = horaAtual * 60 + minutoAtual;
            int minutosNovos = horaNova * 60 + minutoNova;

            if (abs(minutosAtuais - minutosNovos) < 30) {
                fclose(file);
                return false; // Conflito de horário
            }
        }
    }

    fclose(file);
    return true;
}


int retornaUltimoIDatendimento() {
    Atendimento atendimento;

    FILE *file = fopen("atendimentos.dat", "rb");

    int ultimoIDAtendimento = 0;

    if (file != NULL) {
        long pos = -1L;
        fseek(file, pos*sizeof(Atendimento), SEEK_END);
        

        if (fread(&atendimento, sizeof(Atendimento), 1, file) == 1) {
            ultimoIDAtendimento = atendimento.id;
            return ultimoIDAtendimento;
        }

        fclose(file);
    }

    return 0; 
}

/*Função do menu Atendimentos*/
int menuAtendimentos(void){
    int opAtendimentos;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU ATENDIMENTOS #####\n");
    printf("\t1. Agendar novo atendimento\n");
    printf("\t2. Listar atendimentos de um cliente\n");
    printf("\t3. Listar todos os agendamentos\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAtendimentos);
    return opAtendimentos;      
}

Atendimento* agendarProcedimento() {
    system("clear||cls");
    mostradorLogo();
    Atendimento *ate;
    ate = (Atendimento*)malloc(sizeof(Atendimento));

    printf("#### AGENDAR ATENDIMENTO ####\n");

    bool agendamentoConcluido = false;

    while (!agendamentoConcluido) {
        char *cpf = input("Digite o cpf do cliente que esta agendando: ");
        if (!verificaExistenciaCPF(cpf)) {
            strncpy(ate->cpfDoCliente, cpf, sizeof(ate->cpfDoCliente));
            free(cpf);

            while (!agendamentoConcluido) {
                listarServicos();
                printf("Digite o id do servico que voce deseja agendar: ");

                int ser;
                scanf("%i", &ser);
                fflush(stdin);

                if (checaServicoID(&ser)) {
                    ate->idDoservico = ser;

                    while (!agendamentoConcluido) {
                        readAnimal();
                        int ani;
                        printf("Digite o id do animal que sera atendido: ");
                        scanf("%i", &ani);
                        fflush(stdin);

                        if (checaAnimalID(&ani)) {
                            ate->idDoanimal = ani;

                            while (!agendamentoConcluido) {
                                char *data = input("Digite a data do atendimento (DD/MM/AAAA): ");
                                if (validaData(data)) {

                                    while (!agendamentoConcluido) {
                                        char *hora = input("Digite a hora do atendimento (HH:MM): ");
                                        if (validaHora(hora)) {
                                            if (verificaExistenciaAtendimento(data, hora)) {
                                                strncpy(ate->data, data, sizeof(ate->data));
                                                free(data);

                                                strncpy(ate->hora, hora, sizeof(ate->hora));
                                                free(hora);

                                                ate->id = retornaUltimoIDatendimento()+1;

                                                ate->status = true;

                                                FILE* file = fopen("atendimentos.dat", "ab");

                                                if (file == NULL) {
                                                    printf("Erro ao abrir arquivo.");
                                                }

                                                fwrite(ate, sizeof(Atendimento), 1, file);
                                                fclose(file);
                                                free(ate);

                                                agendamentoConcluido = true; 
                                            } else {
                                                printf("Conflito na agenda!\n");
                                            }
                                        } else {
                                            printf("Hora invalida!\n");
                                        }
                                    }
                                } else {
                                    printf("Data invalida!\n");
                                }
                            }
                        } else {
                            printf("ID do animal invalido!\n");
                        }
                    }
                } else {
                    printf("ID do servico invalido!\n");
                }
            }
        } else {
            printf("CPF nao cadastrado!\n");
        }
    }

    digiteEnter();
}

void updateAtendimento() {
    system("clear||cls");
    mostradorLogo();
    Atendimento ate;

    int escolhaNumero;

    printf("#### EDITAR ATENDIMENTO ####\n");

    while (true) {
        const char *escolha = input("Digite o id do agendamento que voce deseja editar: ");
        if (verificaNumero(*escolha)) {
            escolhaNumero = atoi(escolha);
            break;
        } else {
            printf("Digite um id valido!\n");
        }
    }

    FILE *file = fopen("atendimentos.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    bool agendamentoConcluido = false;

    while (fread(&ate, sizeof(Atendimento), 1, file) == 1) {
        if (ate.id == escolhaNumero) {
            char *cpf = input("Digite o cpf do cliente que esta agendando: ");
            if (!verificaExistenciaCPF(cpf)) {
                strncpy(ate.cpfDoCliente, cpf, sizeof(ate.cpfDoCliente));
                free(cpf);

                listarServicos();
                printf("Digite o id do servico que voce deseja agendar: ");

                int ser;
                scanf("%i", &ser);
                fflush(stdin);

                if (checaServicoID(&ser)) {
                    ate.idDoservico = ser;

                    readAnimal();
                    int ani;
                    printf("Digite o id do animal que sera atendido: ");
                    scanf("%i", &ani);
                    fflush(stdin);

                    if (checaAnimalID(&ani)) {
                        ate.idDoanimal = ani;

                        char *data = input("Digite a data do atendimento (DD/MM/AAAA): ");
                        if (validaData(data)) {

                            char *hora = input("Digite a hora do atendimento (HH:MM): ");
                            if (validaHora(hora)) {
                                if (verificaExistenciaAtendimento(data, hora)) {
                                    strncpy(ate.data, data, sizeof(ate.data));
                                    free(data);

                                    strncpy(ate.hora, hora, sizeof(ate.hora));
                                    free(hora);

                                    long pos = -1L;
                                    fseek(file, pos * sizeof(Atendimento), SEEK_CUR);
                                    fwrite(&ate, sizeof(Atendimento), 1, file);

                                    agendamentoConcluido = true;
                                    break;
                                } else {
                                    printf("Conflito na agenda!\n");
                                }
                            } else {
                                printf("Hora invalida!\n");
                            }
                        } else {
                            printf("Data invalida!\n");
                        }
                    } else {
                        printf("ID do animal invalido!\n");
                    }
                } else {
                    printf("ID do servico invalido!\n");
                }
            } else {
                printf("CPF nao cadastrado!\n");
            }
        }
    }

    fclose(file);
    digiteEnter();
}

void deleteAtendimento(){
    
    Atendimento ate;

    bool encontrado = false;

    int escolhaNumero;

    printf("#### DELETAR ATENDIMENTO ####\n");

    while (true) {
        const char *escolha = input("Digite o id do agendamento que voce deseja deletar: ");
        if (verificaNumero(*escolha)) {
            escolhaNumero = atoi(escolha);
            break;
        } else {
            printf("Digite um id valido!\n");
        }
    }
    

    FILE * file = fopen("atendimentos.dat","rb+");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
    }

    while(fread(&ate, sizeof(Atendimento), 1, file) == 1){
        if(ate.id == escolhaNumero){
            encontrado = true;

            ate.status = false;

            long pos = -1L;
            fseek(file, pos*sizeof(Atendimento), SEEK_CUR);
            fwrite(&ate, sizeof(Atendimento), 1, file);
            break;

        }
    }
    if (encontrado == false){
        printf("Digite um id valido! \n");
    }
    fclose(file);
    digiteEnter(); 
}

void selecionaAtendimento(){
    int opSelecionaAtendimento;

    do{
        printf("Digite 1 para editar um dos atendimentos, 2 para deletar ou 0 para continuar: ");
        scanf("%i", &opSelecionaAtendimento);fflush(stdin);
        switch (opSelecionaAtendimento){
            case 1:
                updateAtendimento();
                break;
            case 2:
                deleteAtendimento();
                break;    
            case 0:
                printf("=====================\n");
                break;
            default:
                printf("Selecione uma opcao valida!\n");
                break;
        }
    }while (opSelecionaAtendimento != 0);
}

void listarTodosAtendimentos() {
    system("clear||cls");
    mostradorLogo();

    Atendimento atendimento;
    Servico servico;
    Animal animal;

    printf("#### LISTAGEM DE TODOS OS AGENDAMENTOS ####\n");

    FILE* fileAte = fopen("atendimentos.dat", "rb");
    FILE* fileAni = fopen("animais.dat", "rb");
    FILE* fileSer = fopen("servicos.dat", "rb");

    if (fileAte == NULL || fileSer == NULL || fileAni == NULL) {
        printf("Erro ao ler arquivos.\n");
        return;
    }

    while (fread(&atendimento, sizeof(Atendimento), 1, fileAte) == 1) {
        if (atendimento.status == true) {
            printf("==================================\n");

            printf("\tID do atendimento: %i\n", atendimento.id);
            printf("\tCPF do cliente: %s\n", atendimento.cpfDoCliente);

            printf("\tData: %s\n", atendimento.data);
            printf("\tHora: %.5s\n", atendimento.hora);

            
            fseek(fileAni, (atendimento.idDoanimal - 1) * sizeof(Animal), SEEK_SET);
            fread(&animal, sizeof(Animal), 1, fileAni);

            printf("\tId do animal atendido: %d\n", atendimento.idDoanimal);
            printf("\tDescricao do animal atendido: %s\n", &animal.descricao);

            
            fseek(fileSer, (atendimento.idDoservico - 1) * sizeof(Servico), SEEK_SET);
            fread(&servico, sizeof(Servico), 1, fileSer);

            printf("\tServico prestado: %s \n", servico.nome);
            printf("\tValor: %s \n", servico.valor);

            printf("==================================\n");
        }
    }
    selecionaAtendimento();

    fclose(fileAte);
    fclose(fileAni);
    fclose(fileSer);

    digiteEnter();
}

void listarAgendamentosCliente(){
    system("clear||cls");
    mostradorLogo();

    Atendimento atendimento;
    Servico servico;
    Animal animal;

    bool encontrado = false;
    char cpfPesquisa[12];

    printf("#### LISTAGEM DE AGENDAMENTOS DE UM CLIENTE ####\n");

    FILE* fileAte = fopen("atendimentos.dat", "rb");
    FILE* fileAni = fopen("animais.dat", "rb");
    FILE* fileSer = fopen("servicos.dat", "rb");

    if (fileAte == NULL || fileSer == NULL || fileAni == NULL) {
        printf("Erro ao ler arquivos.\n");
        return;
    }

    while(true){
        strncpy(cpfPesquisa, input("\nDigite o cpf do cliente que voce deseja pesquisar: "), sizeof(cpfPesquisa));
        if (!verificaExistenciaCPF(cpfPesquisa)){
            break;
        } else{
            printf("Digite um cpf valido!\n");
            digiteEnter();
        }
    }

    while (fread(&atendimento, sizeof(Atendimento), 1, fileAte) == 1) {
        if (atendimento.status == true && strcmp(atendimento.cpfDoCliente, cpfPesquisa) == 0) {
            encontrado = true;

            printf("==================================\n");

            printf("\tID do atendimento: %i\n", atendimento.id);
            printf("\tCPF do cliente: %s\n", atendimento.cpfDoCliente);

            printf("\tData: %s\n", atendimento.data);
            printf("\tHora: %.5s\n", atendimento.hora);

            
            fseek(fileAni, (atendimento.idDoanimal - 1) * sizeof(Animal), SEEK_SET);
            fread(&animal, sizeof(Animal), 1, fileAni);

            printf("\tId do animal atendido: %d\n", atendimento.idDoanimal);
            printf("\tDescricao do animal atendido: %s\n", &animal.descricao);

            
            fseek(fileSer, (atendimento.idDoservico - 1) * sizeof(Servico), SEEK_SET);
            fread(&servico, sizeof(Servico), 1, fileSer);

            printf("\tServico prestado: %s \n", servico.nome);
            printf("\tValor: %s \n", servico.valor);

            printf("==================================\n");

        }
    }
    if (encontrado == false){
        printf("Nenhum atendimento encontrado! \n");
    }else{
        selecionaAtendimento();
    }

    fclose(fileAte);
    fclose(fileAni);
    fclose(fileSer);

    digiteEnter();    
}

