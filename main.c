#include<stdio.h>
#include <stdlib.h>
#include "fila.h"
#define APAGAR system("clear");

int main() {
  Fila *fp = criarFila ();
  int op,prioridade;
  char nome[40];

  inserirFila(fp, "Alex", 1);
  inserirFila(fp, "Silvano", 1);
  inserirFila(fp, "Douglas", 1);
  inserirFila(fp, "Fredson", 3);
  inserirFila(fp, "Janio", 1);
  inserirFila(fp, "Yzaac", 2);

  printf("\n=================================================\n");

  do {
    APAGAR;
    printf("\n\n\t ----- SET - Sistema de Espera de Transplante ----- \n\n");
    printf("\n\t1 - Inserir Paciente\n");
    printf("\t2 - Remover Paciente\n");
    printf("\t3 - Imprimir Fila de Espera\n");
    printf("\t4 - Destruir Fila\n");
    printf("\t0 - Sair\n\t-> ");
    scanf("%d", &op);
    switch (op) {
      case 1:
        do {
          printf("\nPaciente com que criterio de atendimento?\n");
          printf("1- Normal. \t 2- Idoso. \t 3- Crianca de colo. \t 4- PVE. \t 5- Universitário.\n ->");
          scanf("%d", &prioridade);
          printf("\n");
        } while(prioridade < 1 && prioridade > 5);
        printf("Paciente de prioridade: %d\n ==== \n", prioridade);
        printf("Nome: ");
        scanf("%s", nome);
        if (inserirFila(fp, nome, prioridade) == 1) {
          printf("\nPaciente inserido na fila!!\n");
        } else {
          printf("\nErro!!\n");
        }
        sair();
      break;
      case 2:
        do {
          printf("Qual o criterio do paciente a ser removido do atendimento?\n");
          printf("1- Normal. \t 2- Com criterio\n ->");
          scanf("%d", &prioridade);
          printf("\n");
        } while(prioridade < 1 && prioridade > 2);
        if (removerFila(fp,prioridade) == 1) {
          printf("\nPaciente removido da fila!!\n");
        } else {
          printf("\nErro!!\n");
        }
        sair();
      break;
      case 3:
        printf("\n==== Fila completa ====\n");
        imprimirFila(fp);
        printf("====               ====\n");
        sair();
      break;
      case 4:
        destruirFila(fp);
        sair();
      break;
     }
     if (op == 0) {
       break;
     }
} while(op > 0 || op < 4);

  return 0;
}
