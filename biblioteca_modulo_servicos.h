typedef struct servico Servico;

struct servico {
    int id;
    char nome[81];
    char valor[20];

    bool status;
};
int menuServicos(void);
Servico* cadastrarServico();
void listarServicos();
void pesquisarServico();
void updateServico();
void deleteServico();
void checaExistenciaServico(const char* nomeVerificado);
bool checaServicoID(const int* idServico);
void listarServicoValor();