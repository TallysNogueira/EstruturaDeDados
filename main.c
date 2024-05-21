#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frutas.h"


int main() {
  Fruta *f;
  int op;
  f = inicializarFruta(f);

  do {
    printf("====MERCADINHO DE FRUTAS====\n");
    printf("1 - CRIAR FRUTA(S)\n2 - LISTAR FRUTA(S)\n3 - BUSCAR FRUTA\n4 - "
           "ALTERAR FRUTA\n5 - EXCLUIR FRUTA\n6 - VENDER FRUTA\n7 - SAIR\n\n ");
    printf("Escolha uma opção:");

    scanf("%d", &op);

    switch (op) {
    case 1:
      f = criarFruta(f);
      break;
    case 2:
      f = listarFruta(f);
      break;

    case 3:
      f = buscaFruta(f);
      break;

    case 4:
      f = alteraFruta(f);
      break;

    case 5:
      f = excluirFruta(f);
      break;

    case 6:
      f = venderFruta(f);
      break;

    case 7:
      printf("\nTCHAU...");
      
    }
  } while (op != 7);

  return 0;
}
