#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 200

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
    char *buffer = (char *)malloc(MAX_INPUT_LENGTH);

    if (buffer == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }

    printf("%s", entrada);

    if (fgets(buffer, MAX_INPUT_LENGTH, stdin) == NULL) {
        free(buffer);
        return NULL;
    }

    size_t tamanhoBuffer = strlen(buffer);

    if (tamanhoBuffer > 0 && buffer[tamanhoBuffer - 1] == '\n') {
        buffer[tamanhoBuffer - 1] = '\0';
    }
    return buffer;
}

void limpaBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void digiteEnter(void){
    printf("Digite Enter para continuar\n");
    limpaBuffer();
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

/*Função de receber datas - inspiração no código de Emerson da Silva Santos*/
void recebeData(){
    bool controle = true;
    while(controle == true){
        char *data = input("Digite sua data (DD/MM/AAAA): ");
        free(data);
        
        for (int i = 0; data[i] != '\0'; i++){
            if (!isdigit(data[i]) && data[i] != '/'){
            	printf("Data invalida, tente novamente\n");
                controle = true;
			}
        }
        controle = false;
    }
    
}

/*Função de verificar datas - inspiração no código de Emerson da Silva Santos - Sujeito a alterações, o código está muito feio*/
bool validaData(const char *data){
	int dia, mes, ano;
	char *token;
	char copiaData[11];
	strcpy(copiaData, data);

	if (strlen(copiaData) != 10){
		return false;
	}
	else{
		token = strtok(copiaData, "/");
		if (token == NULL){
			return false;
		}
		else{
			dia = atoi(token);
			token = strtok(NULL, "/");

			if (token == NULL){
				return false;
			}else{
				mes = atoi(token);
				token = strtok(NULL, "/");

				if (token == NULL){
					return false;
				}
				else{
					ano = atoi(token);
					if (ano < 0 || mes < 1 || mes > 12 || dia < 1 || dia > 31){
						return false;
					}else{
						if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
							return false;
						}else{
							if (mes == 2){
								bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
								if ((bissexto && dia > 29) || (!bissexto && dia > 28)){
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

/*Função validadora de quantias monetárias - Feita para o formato R$0.00*/
bool validaValor(const char *dinheiro) {
    int tamanhoChar = strlen(dinheiro);

    if (tamanhoChar < 3 || dinheiro[0] != 'R' || dinheiro[1] != '$') {
        return false;
    }

    bool controlePontoDecimal = false;
    for (int i = 2; i < tamanhoChar; i++) {
        if (!isdigit(dinheiro[i]) && dinheiro[i] != '.') {
            return false;
        }
        if (dinheiro[i] == '.') {
            if (controlePontoDecimal) {
                return false;
            }
            controlePontoDecimal = true;
        }
    }

    return true;
}
/*Feito com inspiração no Código de Gabriel Ygor Canuto*/
bool validaTelefone(char* fone){ 
  int tam;
  tam = strlen(fone);
  if (tam != 11){
    return false;
  }
  for (int i=0; i < tam; i++){
    if (!verificaNumero(fone[i])) {
      return false;
    }
  }
  return true;
}

/*Feito para o formato HH:MM*/
bool validaHora(const char horario[7]) {
    if (strlen(horario) != 5) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        if (!isdigit(horario[i])) {
            return false;
        }
    }

    if (horario[2] != ':') {
        return false;
    }
    for (int i = 3; i < 5; i++) {
        if (!isdigit(horario[i])) {
            return false;
        }
    }
    
    int hora = (horario[0] - '0') * 10 + (horario[1] - '0');
    int minutos = (horario[3] - '0') * 10 + (horario[4] - '0');

    if (hora < 0 || hora > 23 || minutos < 0 || minutos > 59) {
        return false;
    }

    return true;
}
