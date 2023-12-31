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
    char hora[7];
    char cpfDoCliente[12];
    int idDoanimal;
    int idDoservico;

    bool status;

    Atendimento *prox;
};

void cabecalhoAtendimento(){
    printf("====================================\n");
    printf("| ID | Data | Hora | CPF do Cliente | Nome do cliente | ID do animal | Serviço |\n");
    printf("====================================\n");
}

void printaAtendimento(Atendimento *atendimento, char *nomecli, char *servico, char *valor){

    printf("| %d | %s | %s | %s | %s | %d | %s | %s |\n", atendimento->id, atendimento -> data, atendimento -> hora, atendimento ->cpfDoCliente, nomecli, atendimento->idDoanimal, servico, valor);
    printf("====================================\n");
}

//Get data - feita com inspiração na getNome de Gabriel Canuto
bool getData (const char *data){
    Atendimento atendimento;

    FILE *file = fopen("atendimentos.dat", "rb"); 

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&atendimento, sizeof(Atendimento), 1, file) == 1) {
        if (strcmp(atendimento.data, data) == 0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

//POR ENQUANTO ESSA DESGRAÇA NÃO FUNCIONA
bool verificaExistenciaAtendimento(char dataAgenda[10], char horaAgenda[6]) {
    Atendimento atendimento;
    FILE *file = fopen("atendimentos.dat", "rb");

    if (file == NULL) {
        printf("Parabens, voce eh o primeiro agendamento! \n");
        return true;
    }

    char horaAgendaCortada[6];  // Para armazenar os 5 primeiros dígitos
    strncpy(horaAgendaCortada, horaAgenda, 5);
    horaAgendaCortada[5] = '\0';  // Adiciona o caractere nulo ao final

    int horaNova, minutoNova;
    sscanf(horaAgendaCortada, "%d:%d", &horaNova, &minutoNova);
    int minutosNovo = horaNova * 60 + minutoNova;

    while (fread(&atendimento, sizeof(Atendimento), 1, file) == 1) {
        if (atendimento.status == true && getData(dataAgenda)) {
            int horaAtual, minutoAtual;
            digiteEnter();
            sscanf(atendimento.hora, "%d:%d", &horaAtual, &minutoAtual);
            int minutosAtual = horaAtual * 60 + minutoAtual;
            // Verifica se há sobreposição de horário
            if (minutosNovo <= minutosAtual + 30 && minutosNovo >= minutosAtual - 30) {
                fclose(file);
                return false; // Conflito de horário
            }
        }
    }

    fclose(file);
    return true; // Não há conflito de horário
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
    printf("\t4. Listar por data e hora\n");
    printf("\t5. Listar agendamentos de um dia\n");
    printf("\t0. Sair\n");
    printf("##########################\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opAtendimentos);
    return opAtendimentos;      
}

Atendimento* agendarProcedimento() {
    system("clear||cls");
    mostradorLogo();
    Atendimento *ate = (Atendimento*)malloc(sizeof(Atendimento));

    if (ate == NULL) {
        printf("Erro ao alocar memória para atendimento.\n");
        return NULL;
    }

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
                scanf("%i", &ser);limpaBuffer();

                if (checaServicoID(&ser)) {
                    ate->idDoservico = ser;

                    while (!agendamentoConcluido) {
                        readAnimal();
                        int ani;
                        printf("Digite o id do animal que sera atendido: ");
                        scanf("%i", &ani);limpaBuffer();

                        if (checaAnimalID(&ani)) {
                            ate->idDoanimal = ani;

                            while (!agendamentoConcluido) {
                                char *data = input("Digite a data do atendimento (DD/MM/AAAA): ");
                                if (validaData(data)) {

                                    while (!agendamentoConcluido) {
                                        char *hora = input("Digite a hora do atendimento (HH:MM): ");
                                        if (validaHora(hora)) {
                                            if (verificaExistenciaAtendimento(data, hora) == true) {
                                                strncpy(ate->data, data, sizeof(ate->data));
                                                free(data);

                                                strncpy(ate->hora, hora, sizeof(ate->hora));
                                                free(hora);

                                                ate->id = retornaUltimoIDatendimento() + 1;
                                                ate->status = true;

                                                FILE *file = fopen("atendimentos.dat", "ab");

                                                if (file == NULL) {
                                                    printf("Erro ao abrir arquivo de atendimentos.\n");
                                                } else {
                                                    fwrite(ate, sizeof(Atendimento), 1, file);
                                                    fclose(file);
                                                    agendamentoConcluido = true;
                                                }

                                                
                                                free(ate);
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
                limpaBuffer();

                if (checaServicoID(&ser)) {
                    ate.idDoservico = ser;

                    readAnimal();
                    int ani;
                    printf("Digite o id do animal que sera atendido: ");
                    scanf("%i", &ani);
                    limpaBuffer();

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
        scanf("%i", &opSelecionaAtendimento);limpaBuffer();
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

    cabecalhoAtendimento();
    while (fread(&atendimento, sizeof(Atendimento), 1, fileAte) == 1) {
        if (atendimento.status == true) {  

            fseek(fileAni, (atendimento.idDoanimal - 1) * sizeof(Animal), SEEK_SET);
            fread(&animal, sizeof(Animal), 1, fileAni);
            
            fseek(fileSer, (atendimento.idDoservico - 1) * sizeof(Servico), SEEK_SET);
            fread(&servico, sizeof(Servico), 1, fileSer);

            printaAtendimento(&atendimento, getCli(atendimento.cpfDoCliente), servico.nome, servico.valor);
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

    cabecalhoAtendimento();
    while (fread(&atendimento, sizeof(Atendimento), 1, fileAte) == 1) {
        if (atendimento.status == true && strcmp(atendimento.cpfDoCliente, cpfPesquisa) == 0) {
            encontrado = true;

            fseek(fileAni, (atendimento.idDoanimal - 1) * sizeof(Animal), SEEK_SET);
            fread(&animal, sizeof(Animal), 1, fileAni);
            
            fseek(fileSer, (atendimento.idDoservico - 1) * sizeof(Servico), SEEK_SET);
            fread(&servico, sizeof(Servico), 1, fileSer);

            printaAtendimento(&atendimento, getCli(atendimento.cpfDoCliente), servico.nome, servico.valor);
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

void listagemDinamicaDataHora() {
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR ATENDIMENTOS POR ORDEM DE DATA E HORA ####\n");

    FILE *file = fopen("atendimentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    Atendimento *atendimento;
    Atendimento *lista;
    Servico servico;
    Animal animal;

    lista = NULL;
    atendimento = (Atendimento *)malloc(sizeof(Atendimento));

    FILE* fileAni = fopen("animais.dat", "rb");
    FILE* fileSer = fopen("servicos.dat", "rb");

    if (atendimento == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }

    while (fread(atendimento, sizeof(Atendimento), 1, file) == 1) {
        atendimento->prox = NULL;

        if ((lista == NULL) || (strcmp(atendimento->data, lista->data) > 0) ||
            ((strcmp(atendimento->data, lista->data) == 0) && (strcmp(atendimento->hora, lista->hora) > 0))) {
            atendimento->prox = lista;
            lista = atendimento;
        } else {
            Atendimento *anterior = lista;
            Atendimento *atual = lista->prox;
            while ((atual != NULL) && ((strcmp(atendimento->data, atual->data) < 0) ||
                   ((strcmp(atendimento->data, atual->data) == 0) && (strcmp(atendimento->hora, atual->hora) < 0)))) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = atendimento;
            atendimento->prox = atual;
        }

        atendimento = (Atendimento *)malloc(sizeof(Atendimento));
        if (atendimento == NULL) {
            printf("Erro de alocacao de memoria\n");
            break;
        }
    }

    fclose(file);

    atendimento = lista;

    cabecalhoAtendimento();
    while (atendimento != NULL) {

        fseek(fileAni, (atendimento->idDoanimal - 1) * sizeof(Animal), SEEK_SET);
        fread(&animal, sizeof(Animal), 1, fileAni);
        
        fseek(fileSer, (atendimento->idDoservico - 1) * sizeof(Servico), SEEK_SET);
        fread(&servico, sizeof(Servico), 1, fileSer);

        printaAtendimento(atendimento, getCli(atendimento->cpfDoCliente), servico.nome, servico.valor);
        digiteEnter();
        atendimento = atendimento->prox;
    }

    atendimento = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(atendimento);
        atendimento = lista;
    }
}




void listagemDinamicaFiltradaPorData() {
    system("clear || cls");
    mostradorLogo();
    printf("#### LISTAR ATENDIMENTOS POR FILTRO DE DATA ####\n");

    char *dataFiltro[11];

    while (true) {
        *dataFiltro = input("Digite a data para pesquisa (DD/MM/AAAA): ");

        if (validaData(*dataFiltro)) {
            break; 
        } else {
            printf("Data invalida. Por favor, tente novamente.\n");
        }
    }

    FILE *file = fopen("atendimentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    Atendimento *atendimento;
    Atendimento *lista;
    Servico servico;
    Animal animal;

    lista = NULL;
    atendimento = (Atendimento *)malloc(sizeof(Atendimento));

    FILE *fileAni = fopen("animais.dat", "rb");
    FILE *fileSer = fopen("servicos.dat", "rb");

    if (atendimento == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }

while (fread(atendimento, sizeof(Atendimento), 1, file) == 1) {
    if (strcmp(atendimento->data, *dataFiltro) == 0) {
        Atendimento *novoAtendimento = (Atendimento *)malloc(sizeof(Atendimento));

        if (novoAtendimento == NULL) {
            printf("Erro de alocacao de memoria\n");
            break;
        }

        
        memcpy(novoAtendimento, atendimento, sizeof(Atendimento));
        novoAtendimento->prox = NULL;

        
        if ((lista == NULL) || (strcmp(novoAtendimento->hora, lista->hora) > 0) ||
            ((strcmp(novoAtendimento->hora, lista->hora) == 0) && (strcmp(novoAtendimento->data, lista->data) > 0))) {
            novoAtendimento->prox = lista;
            lista = novoAtendimento;
        } else {
            Atendimento *anterior = NULL;
            Atendimento *atual = lista;

            
            while ((atual != NULL) &&
                   ((strcmp(novoAtendimento->hora, atual->hora) < 0) ||
                    ((strcmp(novoAtendimento->hora, atual->hora) == 0) &&
                     (strcmp(novoAtendimento->data, atual->data) < 0)))) {
                anterior = atual;
                atual = atual->prox;
            }

            anterior->prox = novoAtendimento;
            novoAtendimento->prox = atual;
        }
    }

    atendimento = (Atendimento *)malloc(sizeof(Atendimento));
    if (atendimento == NULL) {
        printf("Erro de alocacao de memoria\n");
        break;
    }
}


    fclose(file);

    if (lista == NULL) {
        printf("Nenhum agendamento encontrado para a data %s.\n", *dataFiltro);
        digiteEnter();
        return;
    }

    atendimento = lista;

    cabecalhoAtendimento();
    while (atendimento != NULL) {

        fseek(fileAni, (atendimento->idDoanimal - 1) * sizeof(Animal), SEEK_SET);
        fread(&animal, sizeof(Animal), 1, fileAni);
        
        fseek(fileSer, (atendimento->idDoservico - 1) * sizeof(Servico), SEEK_SET);
        fread(&servico, sizeof(Servico), 1, fileSer);

        printaAtendimento(atendimento, getCli(atendimento->cpfDoCliente), servico.nome, servico.valor);
        digiteEnter();
        atendimento = atendimento->prox;
    }

    atendimento = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(atendimento);
        atendimento = lista;
    }
}
