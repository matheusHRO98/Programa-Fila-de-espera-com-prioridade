struct paciente{
  char nome[30];
  int prio;
};

typedef struct ELEMENTOFILA {
    struct paciente dados;
    struct ELEMENTOFILA *proximo;
} Elemento;

typedef struct FILA {
    Elemento *inicio;
    Elemento *fim;
} Fila;



Fila *criarFila();
void destruirFila(Fila *fila);
int inserirFila(Fila *fila, char *nome,int prioridade);
int removerFila(Fila *fila,int prioridade);
struct paciente retornaProximo(Fila *fila);
int filaVazia(Fila *fila);
void imprimirFila(Fila *fila);
void imprimirFilaRecursiva(Elemento *e);
void sair ();
