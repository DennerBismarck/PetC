typedef struct cliente Cliente;
struct cliente {
    char 
    nome[81];
    char cpf[11];
    char email[41];
    char senha[100];

    bool status;

    Cliente *prox;
};

int menuCliente(void);
Cliente* cadastrarCliente(void);
int verCliente(void);
void listarCliente(void);
void pesquisarCliente(void);
void updateCliente();
void deleteCliente();
bool verificaExistenciaCPF(const char* CPFVerificado);
char *getCli(const char *cpf);
void ListagemDinamicaAlfabetica();