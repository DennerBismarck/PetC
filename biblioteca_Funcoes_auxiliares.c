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

/*Inspirado no LeLinha de Flavius Gorgônio*/
char *input(const char *entrada) {
    char *buffer = NULL;
    size_t tamanhoBuffer = 0;
    printf("%s", entrada);

    size_t caracteres = getline(&buffer, &tamanhoBuffer, stdin);

    if (caracteres > 0 && buffer[caracteres - 1] == '\n') {
        buffer[caracteres - 1] = '\0';
    }

    return buffer;
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

    if (strlen(cpf) != 11) {
            return false;
    }

    for (int i = 0; i < 11; i++) {
        if (!verificaNumero(cpf[i])) {
            return false;
        }
    }
    int total = 0;
    for (int i = 0; i < 9; i++) {
        total += (cpf[i] - '0') * (10 - i);
    }
    int digito1 = 11 - (total % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    total = 0;
    for (int i = 0; i < 10; i++) {
        total += (cpf[i] - '0') * (11 - i);
    }
    int digito2 = 11 - (total % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }
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

/*Função de receber datas - inspiração no código de Emerson da Silva Santos
void recebeData(){
    char data[11];
    
    while(true){
        printf("Digite sua data (DD/MM/AAAA): \n");
        

    }
    
}

bool verificaData(char *data){
    const char subDatas[3] = "//";
    
    if (strstr(data, subDatas) != NULL){
        return false;
    }
}*/