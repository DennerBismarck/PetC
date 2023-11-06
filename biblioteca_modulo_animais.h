int menuAnimal(void);
typedef struct animal Animal;
struct animal{
    char descricao[200];
    char cpfDoCliente[11];
};

Animal* createAnimal();
void readAnimal();
void updateAnimal();
void deleteAnimal();