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
                                fflush(stdin);
                                agendarProcedimento();
                                break;
                              case 2:
                                fflush(stdin);
                                verAgendamentos();
                                break;
                            case 3:
                                fflush(stdin);
                                listarAgendamentos();
                                break;         
                            case 0:
                                fflush(stdin);
                                printf("====================================\n");    
                                break;                           
                            default:
                                fflush(stdin);
                                printf("Digite novamente!");
                                break;                                         
                        }
                        digiteEnter(); 
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
                        fflush(stdin);
                        cadastrarCliente(); 
                        break;
                    case 2:
                        do{
                            opmenuVerCliente = verCliente();
                            switch (opmenuVerCliente){
                            case 1:
                                fflush(stdin);
                                listarCliente();
                                break;
                            case 2:
                                fflush(stdin);
                                pesquisarCliente();
                                break;
                            case 3:
                                fflush(stdin);
                                updateCliente();
                                break;
                            case 4:
                                fflush(stdin);
                                deleteCliente();
                                break;
                            case 0:
                                printf("==============================\n");
                                break;
                            default:
                                fflush(stdin);
                                printf("Digite novamente!\n");
                                break;
                            }
                        }while(opmenuVerCliente!=0);
                        break;
                    case 0:
                        fflush(stdin);
                        printf("================================\n");
                        break;  
                    default:
                        fflush(stdin);
                        printf("Digite novamente!\n");
                        break;
                    }
                    digiteEnter();
                } while (opmenuClientes!=0);                  
                break; 
            case 4:
                do{
                    opmenuServicos = menuServicos();
                    switch (opmenuServicos){
                        case 1:
                            fflush(stdin);
                            cadastrarServico();
                            break;  
                        case 2:
                            fflush(stdin);
                            listarServicos();
                            break;
                        case 3:
                            fflush(stdin);
                            pesquisarServico();
                            break;
                        case 4:
                            fflush(stdin);
                            updateServico();
                            break;
                        case 5:
                            fflush(stdin);
                            deleteServico();
                            break;
                        case 0:
                            fflush(stdin);
                            printf("======================================\n");
                            break;
                        default:
                            fflush(stdin);
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
                            fflush(stdin);
                            createAnimal();
                            break;
                        case 2:
                            fflush(stdin);
                            readAnimal();
                            break;
                        case 3:
                            fflush(stdin);
                            updateAnimal();
                            break;
                        case 4:
                            fflush(stdin);
                            deleteAnimal();
                            break;
                        case 0:
                            fflush(stdin);
                            printf("======================================\n");
                            break;                            
                        default:
                            printf("Digite novamente!\n");
                            break;
                        }                        
                }while(opmenuAnimais != 0);
                break;
            case 0:
                printf("================================\n");
                break;
            default:
                printf("Digite novamente!");
                printf("====================================\n"); 
                break;
            digiteEnter();       
        }
    } while (opMenuPrincipal != 0);
    return 0;
}