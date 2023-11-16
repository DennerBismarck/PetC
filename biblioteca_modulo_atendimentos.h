typedef struct atendimento Atendimento;
struct atendimento{
    int id;
    char data[11];
    char hora[5];
    char cpfDoCliente[12];
    int idDoanimal;
    int idDoservico;

    bool status;
};

int menuAtendimentos(void);
Atendimento* agendarProcedimento();
void verAgendamentos();
void listarTodosAtendimentos();