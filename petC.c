#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_Funcoes_auxiliares.h"
#include "biblioteca_modulo_inicio.h"
#include "biblioteca_modulo_clientes.h"
#include "biblioteca_modulo_servicos.h"

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
    int opmenuAutenticacao;

    do{
        opMenuPrincipal = menuPrincipal();
        switch (opMenuPrincipal){
            
            case 1:
                    do{
                        opmenuAtendimentos = menuAtendimentos();
                        switch(opmenuAtendimentos){
                            case 1:
                                do{
                                    opmenuProcedimentos = menuProcedimentos();
                                    switch (opmenuProcedimentos){
                                        case 1:
                                            agendarProcedimento();
                                            break;
                                        case 2:
                                            verProcedimentos();
                                            break;
                                        case 0:
                                            printf("================================\n");
                                            break;    
                                        default:
                                            printf("Digite novamente!");
                                            break;                                         
                                    } 
                                } while (opmenuProcedimentos != 0);
                                printf("Digite Enter para continuar");
                                getchar();
                                getchar();  
                                printf("====================================\n");    
                                break;
                            case 0:
                                printf("================================\n");
                                break;    
                           
                            default:
                                printf("Digite novamente!");
                                break;

                            printf("Digite Enter para continuar");
                            getchar();
                            getchar();  
                            printf("====================================\n");                                            
                        }
                    }while (opmenuAtendimentos!=0);            
                break;

            case 2:
                menuSobre();   
                break;
            case 3:
                do{
                    opmenuAutenticacao = menuAutenticacao();
                    switch (opmenuAutenticacao){
                    case 1:
                        printf("Abuble");
                        break;
                    case 2:
                        cadastrarCliente();
                        break;
                    case 0:
                        printf("================================\n");
                        break;
                    default:
                        printf("Digite novamente!");
                        break;
                    }
                } while (opmenuAutenticacao!=0);

                printf("Digite Enter para continuar");
                getchar();
                getchar();  
                printf("====================================\n");                   
                break;    

            case 0:
                printf("================================\n");
                break;         
            default:
                printf("Digite novamente!");
                break;
            printf("Digite Enter para continuar");
            getchar();
            getchar();  
            printf("====================================\n");        
        }
    } while (opMenuPrincipal != 0);
    return 0;
}