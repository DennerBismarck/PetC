typedef struct servico Servico;
struct servico {
    int id;
    char nome[81];
    char valor[20];

    bool status;
};
int menuRequisicoes(void);
void requisicoesClientes(void);
void requisicoesAgendamentos(void);
void cadastrarFuncionario(void);
void cadastrarServico(void);
