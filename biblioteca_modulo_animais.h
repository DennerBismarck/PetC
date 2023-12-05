int menuAnimal(void);
typedef struct animal Animal;
struct animal{
    int id;
    char descricao[200];
    char cpfDoCliente[12];

    bool status;
};

Animal* createAnimal();
void readAnimal();
void updateAnimal();
void deleteAnimal();
bool checaAnimalID(const int* idAnimal);
void listarTodosAnimais();