typedef struct atendimento Atendimento;
struct atendimento{
    int id;
    char data[11];
    char hora[5];
    char cpfDoCliente[12];
    int idDoanimal;
    int idDoservico;

    bool status;

    Atendimento *prox;
};

int menuAtendimentos(void);
Atendimento* agendarProcedimento();
void listarTodosAtendimentos();
void listarAgendamentosCliente();
void listagemDinamicaDataHora();
void listagemDinamicaFiltradaPorData();
