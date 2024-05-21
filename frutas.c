#include "frutas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fruta *inicializarFruta() { return NULL; }

// Inserção da fruta no início da lista
Fruta *criarFruta(Fruta *f) {
  Fruta *novo = (Fruta *)malloc(sizeof(Fruta));

  printf("\nDigite o código da fruta:");
  scanf("%d", &novo->codigo);

  Fruta *p;
  for (p = f; p != NULL; p = p->prox) {
    if (p->codigo == novo->codigo) {
      printf("CÓDIGO REPETIDO\n");
      return f;
    }
  }
  printf("Digite o nome da fruta:");
  scanf("%s", novo->nome);
  strcpy(novo->nome, novo->nome);

  printf("Digite a quantidade da fruta:");
  scanf("%d", &novo->quantidade);

  printf("Digite o preço da fruta:");
  scanf("%f", &novo->preco);
  printf("--------------------------------------------\n");
  novo->prox = f;

  return novo;
}
Fruta *listarFruta(Fruta *f) {
  Fruta *p;
  for (p = f; p != NULL; p = p->prox) {
    printf("\nCódigo: %d\n", p->codigo);
    printf("Nome: %s\n", p->nome);
    printf("Quantidade: %d\n", p->quantidade);
    printf("Preço: %.2f\n", p->preco);
    printf("-----------------------------------------\n\n");
  }
  return f;
}

Fruta *buscaFruta(Fruta *f) {
  Fruta *p;
  int v;

  if (f == NULL) {
    printf("\nA Lista não foi inicializada\n\n");
    return f;
  }

  printf("\nDigite o código da fruta que deseja buscar:\n");
  scanf("%d", &v);
  for (p = f; p != NULL; p = p->prox) {
    if (p->codigo == v) {
      printf(">>>>1 FRUTA ENCONTRADA<<<<\n");
      printf("Código: %d\n", p->codigo);
      printf("Nome: %s\n", p->nome);
      printf("Quantidade: %d\n", p->quantidade);
      printf("Preço: %.2f\n", p->preco);
      printf("-----------------------------------------\n\n");
      return f;
    } else {
      printf("FRUTA NÃO ENCONTRADA\n");
      return f;
    }
  }
  return f;
}

Fruta *excluirFruta(Fruta *f) {
  int cod;
  printf("\nDigite o código da fruta que deseja exluir:");
  scanf("%d", &cod);
  Fruta *p = f;
  Fruta *ant = NULL;

  while (p != NULL && p->codigo != cod) {
    ant = p;
    p = p->prox;
  }
  if (p == NULL) {
    return f;
  }
  if (ant == NULL) {
    f = p->prox;
  } else {
    ant->prox = p->prox;
  }
  free(p);
  return f;
}
Fruta *alteraFruta(Fruta *f) {
  int cod;
  Fruta *ant = NULL;
  Fruta *p = f;
  printf("\nDigite o código da fruta que deseja alterar:\n");
  scanf("%d", &cod);
  while (p != NULL && p->codigo != cod) {
    ant = p;
    p = p->prox;
  }
  if (f == NULL) {
    printf("\nLista não inicializada\n\n");
  }

  if (p == NULL) {
    printf("Código não encontrado\n");
    return f;
  }

  Fruta *nf = (Fruta *)malloc(sizeof(Fruta));

  printf("\nDigite o novo código da fruta:");
  scanf("%d", &nf->codigo);

  for (Fruta *i = f; i != NULL; i = i->prox) {
    if (i->codigo == nf->codigo) {
      printf("CÓDIGO REPETIDO\n");
      free(nf);
      return f;
    }
  }

  printf("Digite o novo nome da fruta:");
  scanf("%s", nf->nome);
  strcpy(nf->nome, nf->nome);

  printf("Digite a nova quantidade da fruta:");
  scanf("%d", &nf->quantidade);

  printf("Digite o novo preço da fruta:");
  scanf("%f", &nf->preco);
  printf("\n--------------------------------------------\n");

  nf->prox = p->prox;
  if (ant == NULL) { // A Alteração será na primeira fruta da lista
    f = nf;
  } else { // A Alteração será na fruta que está no meio da lista
    ant->prox = nf;
  }

  free(p);
  return f;
}
Fruta *venderFruta(Fruta *f) {
  Fruta *p;
  int v;
  printf("\nDigite o código da fruta que será vendida:\n");
  scanf("%d", &v);
  for (p = f; p != NULL; p = p->prox) {
    if (p->codigo == v) {
      int q;
      printf("Quantas frutas serão vendidas?\n");
      scanf("%d", &q);
      if (q > p->quantidade) {
        printf("Quantidade superior ao que está no estoque\n\n");
      } else {
        FILE *arq = fopen("vendas.txt", "a");
        if (arq) {
          fprintf(arq, "Código: %d\n", p->codigo);
          fprintf(arq, "Nome: %s\n", p->nome);
          fprintf(arq, "Quantidade de frutas vendidas: %d\n", q);
          p->quantidade -= q;
          fprintf(arq, "Valor da compra: %.2f\n\n", p->preco * q);
        } else {
          printf("ERRO AO ABRIR O ARQUIVO");
        }
        fclose(arq);
      }
      break;
    }
    if (p->prox == NULL && p->codigo != v) {
      printf("CÓDIGO NÃO ENCONTRADO\n\n");
    }
  }
  return f;
}
