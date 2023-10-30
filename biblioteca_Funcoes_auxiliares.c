#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*Função da logo principal*/
void mostradorLogo(void){
    printf("       /^-^\\         /^-----^\"\n");
    printf("      / o o \\        V  o o  V\n");
    printf("     /   Y   \\        |  Y  |\n");
    printf("     V \\ v / V         \\ Q /\n");
    printf("       / - \\           / - \"\n");
    printf("      /    |           |    \"\n");
    printf("(    /     |           |     \\     )\n");
    printf(" ===/___) ||           || (___\\====\n");
    printf("\n");
    printf("##### PETC: ONDE SEU PET EH MAIS QUE UMA GARRAFA! #####\n");
    printf("\n");
}

void digiteEnter(void){
    printf("Digite Enter para continuar\n");
    getchar();
    getchar();  
    printf("====================================\n");
}

/*Função que verifíca se uma variavel de char é um número*/
bool verificaNumero(char teste){
    return isdigit(teste);  
}



/*Função validadora de cpf (Houve inspiração em uma versão criada pelo chatGPT)*/
bool validaCPF(const char *cpf){
    /*Verificador de tamanho*/
    if (strlen(cpf) != 11) {
            return false;
    }
    /*Verificador de digitos numéricos*/
    for (int i = 0; i < 11; i++) {
        if (!verificaNumero(cpf[i])) {
            return false;
        }
    }
    /*Digito verificador 1*/
    int total = 0;
    for (int i = 0; i < 9; i++) {
        total += (cpf[i] - '0') * (10 - i);
    }
    int digito1 = 11 - (total % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    /*Digito verificador 2*/
    total = 0;
    for (int i = 0; i < 10; i++) {
        total += (cpf[i] - '0') * (11 - i);
    }
    int digito2 = 11 - (total % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }

    /*Verificando se as contas deram certo*/
    return (digito1 == (cpf[9] - '0')) && (digito2 == (cpf[10] - '0'));

}

/*Função de verificação de nomes próprios - Checa se contém números ou caracteres especiais que não são letras acentuadas*/
bool verificaNome(const char *nome){

    int tam = sizeof(nome);

    for (int i = 0; i < tam; i++){
        if(!isalpha(nome[i]) && !isspace(nome[i])){
            return true;   
        }
    }
    return false;
}

/*Função de verificação da datas*/
bool verificaData(char *data){
    const char subDatas[3] = "//";
    
    if (strstr(data, subDatas) != NULL){
        return false;
    }
}