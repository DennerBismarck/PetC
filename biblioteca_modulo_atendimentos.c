#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_animais.h"
#include "biblioteca_modulo_clientes.h"
#include "biblioteca_modulo_servicos.h"

int contadorIDAtendimento = 1;


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

/*Função do menu Atendimentos*/
int menuAtendimentos(void){
    int opAtendimentos;
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU ATENDIMENTOS #####\n");
    printf("\t1. Agendar novo atendimento\n");
    printf("\t2. Tabela de atendimentos\n");
    printf("\t3. Minhas agendas\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAtendimentos);
    return opAtendimentos;      
}
Atendimento* agendarProcedimento(){
    system("clear||cls");
    mostradorLogo();
    Atendimento *ate;
    ate = (Atendimento*)malloc(sizeof(Atendimento));

    printf("#### AGENDAR ATENDIMENTO ####\n");

    while (1) {
        char *cpf = input("Digite o cpf do cliente que esta agendando: ");
        if (!verificaExistenciaCPF(cpf)) {
            strncpy(ate->cpfDoCliente, cpf, sizeof(ate->cpfDoCliente));
            free(cpf);

            while (1) {
                listarServicos();
                printf("Digite o id do servico que voce deseja agendar: ");

                int ser;
                scanf("%i", &ser);
                fflush(stdin);

                if (!checaServicoID(&ser)) {
                    ate->idDoservico = ser;

                    while (1) {
                        readAnimal();
                        int ani;
                        printf("Digite o id do animal que sera atendido: ");
                        scanf("%i", &ani);
                        fflush(stdin);
                        
                        if (checaAnimalID(&ani)) {
                            ate->idDoanimal = ani;

                            while (1) {
                                char *data = input("Digite a data do atendimento (DD/MM/AAAA): ");
                                if (validaData(data)) {

                                    while (1) {
                                        char *hora = input("Digite a hora do atendimento (HH:MM): ");
                                        if (validaHora(hora)) {
                                            if (verificaExistenciaAtendimento(data, hora)) {
                                                strncpy(ate->data, data, sizeof(ate->data));
                                                free(data);

                                                strncpy(ate->hora, hora, sizeof(ate->hora));
                                                free(hora);

                                                ate->id = contadorIDAtendimento;
                                                contadorIDAtendimento = contadorIDAtendimento + 1;

                                                FILE* file = fopen("atendimentos.dat", "ab");

                                                if (file == NULL) {
                                                    printf("Erro ao abrir arquivo.");
                                                }

                                                fwrite(ate, sizeof(Atendimento), 1, file);
                                                fclose(file);
                                                free(ate);
                                                break;

                                            } else {
                                                printf("Conflito na agenda!\n");
                                            }
                                        } else {
                                            printf("Hora invalida!\n");
                                        }
                                    }
                                    break;
                                } else {
                                    printf("Data invalida!\n");
                                }
                            }break;
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
       break;
    }
    digiteEnter();
}


void verAgendamentos(){
    system("clear||cls");
    mostradorLogo();
    printf("#### VER PROCEDIMENTOS ####\n");
    printf("#### EM DESENVOLVIMENTO ####\n");
}

void listarAgendamentos(){
    printf ("aaaaa");
}