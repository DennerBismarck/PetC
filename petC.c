#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_inicio.h"
#include "biblioteca_modulo_clientes.h"
#include "biblioteca_modulo_servicos.h"
#include "biblioteca_modulo_atendimentos.h"
#include "biblioteca_modulo_animais.h"

/*Função do menu Sobre*/
void menuSobre(void){
    system("clear||cls");
    mostradorLogo();
    printf("##### MENU SOBRE #####\n");
    printf("\tUNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE \n");
    printf("\tCENTRO DE ENSINO SUPERIOR DO SERIDO\n");
    printf("\tDEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA\n");
    printf("\tDISCIPLINA DCT1106: PROGRAMAÇÃO\n");
    printf("\tPROJETO DE UM SOFTWARE PARA GESTÃO DE PETSHOP\n");
    printf("\tDESENVOLVIDO POR DENNER BISMARCK DE LUCENA FRANÇA\n");
}


/*Função main do código*/
int main(){
    int opMenuPrincipal;
    int opmenuAtendimentos;
    int opmenuConsultas;
    int opmenuProcedimentos;
    int opmenuClientes;
    int opmenuVerCliente;
    int opmenuServicos;
    int opmenuAnimais;

    do{
        opMenuPrincipal = menuPrincipal();
        switch (opMenuPrincipal){
            
            case 1:
                    do{
                        opmenuAtendimentos = menuAtendimentos();
                        switch(opmenuAtendimentos){
                            case 1:
                                limpaBuffer();
                                agendarProcedimento();
                                break;
                            case 2:
                                limpaBuffer();
                                listarAgendamentosCliente();
                                break;
                            case 3:
                                limpaBuffer();
                                listarTodosAtendimentos();
                                break;
                            case 4:
                                limpaBuffer();
                                listagemDinamicaDataHora(); 
                                break;
                            case 5:
                                limpaBuffer();
                                listagemDinamicaFiltradaPorData();
                                break;
                            case 0:
                                limpaBuffer();
                                printf("====================================\n");    
                                break;                           
                            default:
                                limpaBuffer();
                                printf("Digite novamente!");
                                break;                                         
                        }
                    }while (opmenuAtendimentos!=0);            
                    break;

            case 2:
                menuSobre();   
                digiteEnter();
                break;
            case 3:
                do{
                    opmenuClientes = menuCliente();
                    switch (opmenuClientes){
                    case 1:
                        limpaBuffer();
                        cadastrarCliente(); 
                        break;
                    case 2:
                        do{
                            opmenuVerCliente = verCliente();
                            switch (opmenuVerCliente){
                            case 1:
                                limpaBuffer();
                                listarCliente();
                                break;
                            case 2:
                                limpaBuffer();
                                pesquisarCliente();
                                break;
                            case 3:
                                limpaBuffer();
                                updateCliente();
                                break;
                            case 4:
                                limpaBuffer();
                                deleteCliente();
                                break;
                            case 5:
                                limpaBuffer();
                                ListagemDinamicaAlfabetica();
                                break;
                            case 6:
                                limpaBuffer();
                                pesquisaClientePorNome();
                                break;
                            case 0:
                                printf("==============================\n");
                                break;
                            default:
                                limpaBuffer();
                                printf("Digite novamente!\n");
                                break;
                            }
                        }while(opmenuVerCliente!=0);
                        break;
                    case 0:
                        limpaBuffer();
                        printf("================================\n");
                        break;  
                    default:
                        limpaBuffer();
                        printf("Digite novamente!\n");
                        break;
                    }
                } while (opmenuClientes!=0);                  
                break; 
            case 4:
                do{
                    opmenuServicos = menuServicos();
                    switch (opmenuServicos){
                        case 1:
                            limpaBuffer();
                            cadastrarServico();
                            break;  
                        case 2:
                            limpaBuffer();
                            listarServicos();
                            break;
                        case 3:
                            limpaBuffer();
                            pesquisarServico();
                            break;
                        case 4:
                            limpaBuffer();
                            updateServico();
                            break;
                        case 5:
                            limpaBuffer();
                            deleteServico();
                            break;
                        case 6:
                            limpaBuffer();
                            listarServicoValor();
                            break;
                        case 7:
                            limpaBuffer();
                            listagemServicoPrecos();
                            break;
                        case 0:
                            limpaBuffer();
                            printf("======================================\n");
                            break;
                        default:
                            limpaBuffer();
                            printf("Digite novamente!\n");
                            break;
                    }
                }while (opmenuServicos != 0);  
                break; 
            case 5:
                do{
                    opmenuAnimais = menuAnimal();
                    switch (opmenuAnimais){
                        case 1:
                            limpaBuffer();
                            createAnimal();
                            break;
                        case 2:
                            limpaBuffer();
                            readAnimal();
                            break;
                        case 3:
                            limpaBuffer();
                            updateAnimal();
                            break;
                        case 4:
                            limpaBuffer();
                            deleteAnimal();
                            break;
                        case 5:
                            limpaBuffer();
                            listarTodosAnimais();
                        case 0:
                            limpaBuffer();
                            printf("======================================\n");
                            break;                            
                        default:
                            printf("Digite novamente!\n");
                            break;
                        }                      
                }while(opmenuAnimais != 0);
                break;
            case 6:
            limpaBuffer();
                printf("================================\n");
                break;
            default:
                limpaBuffer();
                printf("Digite novamente!\n");
                printf("====================================\n"); 
                break;
                digiteEnter();
            digiteEnter();       
        }
        digiteEnter();
    } while (opMenuPrincipal != 6);
    return 0;
}