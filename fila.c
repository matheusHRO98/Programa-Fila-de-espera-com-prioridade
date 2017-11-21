#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h" //inclui os Protótipos
#define APAGAR system("clear");


Fila *criarFila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));

    if (fila ==  NULL)
        return NULL;

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void destruirFila(Fila *fila) {
    Elemento *e;

    if (fila == NULL)
        return;

    if(fila->inicio == NULL){
      free(fila);
      fila = NULL;
      return;
    }
    e = fila->inicio;
    printf("\nEliminado - \tNome:%s \t- Prioridade: %d\n", e->dados.nome,e->dados.prio);
    fila->inicio = e->proximo;
    free(e);
    e = NULL;
    destruirFila(fila);

}


int inserirFila(Fila *fila, char *nome,int prioridade){
  Elemento *novoElemento;
  if (fila == NULL)
      return 0;

  novoElemento = (Elemento *) malloc(sizeof(Elemento));
  if (novoElemento == NULL)
      return 0;

  strcpy(novoElemento->dados.nome, nome);
  novoElemento->dados.prio = prioridade;
  novoElemento->proximo = NULL;

  if (fila->inicio == NULL) {
      fila->inicio = novoElemento;
  }else {
      Elemento *anterior, *atual = fila->inicio;
      while (atual != NULL &&  atual->dados.prio >= prioridade  ) {
          anterior = atual;
          atual = atual->proximo;
      }
      if (fila->inicio == atual){
          novoElemento->proximo = fila->inicio;
          fila->inicio = novoElemento;
      } else {
          novoElemento->proximo = anterior->proximo;
          anterior->proximo = novoElemento;
      }
  }
    return 1;
}

int removerFila(Fila *fila,int prioridade) {
    Elemento *e;

    if (fila == NULL)
        return 0; // fila nao existe

    if (fila->inicio == NULL)
        return 0; // fila vazia

    Elemento *anterior, *atual = fila->inicio;
    if (prioridade == 1) {
      while (atual != NULL &&  atual->dados.prio > 1  ) {
        anterior = atual;
        atual = atual->proximo;
      }

      if (fila->inicio == atual){
        e = fila->inicio;
        fila->inicio = e->proximo;
      } else {
        e = atual;
        anterior->proximo = atual->proximo;
      }
    }
    else if (prioridade == 2) {
      while (atual != NULL &&  atual->dados.prio == 1  ) {
        anterior = atual;
        atual = atual->proximo;
      }

      if (fila->inicio == atual){
        e = fila->inicio;
        fila->inicio = e->proximo;
      } else {
        e = atual;
        anterior->proximo = atual->proximo;
      }
    }

    if (fila->inicio == NULL)
        fila->fim = NULL;
    printf("\nEliminado - \tNome:%s \t- Prioridade: %d\n", e->dados.nome,e->dados.prio);
    free(e);
    e = NULL;
    return 1;
}


void imprimirFila(Fila *fila) {
  if(fila != NULL){
    imprimirFilaRecursiva(fila->inicio);
    printf("====     fim        ====\n");
  }
}

void imprimirFilaRecursiva(Elemento *e){
  if (e != NULL){
    printf("Nome:%s \t- Prioridade: %d\n", e->dados.nome,e->dados.prio);
    imprimirFilaRecursiva(e->proximo);
  }
}

struct paciente retornaProximo(Fila *fila) {
    return fila->inicio->dados;
}

int filaVazia(Fila *fila) {
    if (fila == NULL)
        return -1; // erro

    if (fila->inicio == NULL)
        return 1; // verdadeiro

    return 0;

}

void sair () {
  int a;
  printf("\nDIGITE QUALQUER NUMERO PARA SAIR!!\n ->");
  scanf("%d", &a);
  APAGAR;
}
