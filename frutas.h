struct Fruta {
  int codigo;
  char nome[50];
  int quantidade;
  float preco;
  struct Fruta *prox;
} typedef Fruta;

Fruta *inicializarFruta();
Fruta *criarFruta(Fruta *f);
Fruta *listarFruta(Fruta *f);
Fruta *buscaFruta(Fruta *f);
Fruta *alteraFruta(Fruta *f);
Fruta *excluirFruta(Fruta *f);
Fruta *venderFruta(Fruta *f);