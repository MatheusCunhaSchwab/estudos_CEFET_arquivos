#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HashSize 31
#define MAX 2048

int total_colisoes = 0;

typedef struct HashElement {
  int uf;
  float soma;
  int qt;
  struct HashElement *prox;
} HashElement;

void distribuicaoHash(HashElement tabela[]) {
  printf("\nDistribuicao da tabela hash:\n");
  for (int i = 0; i < HashSize; i++) {
    int contador = 0;
    HashElement* atual = &tabela[i];
    if (atual->uf != -1) {
      contador++;
      atual = atual->prox;
      while (atual != NULL) {
        contador++;
        atual = atual->prox;
      }
    }
    printf("Posicao %2d: %d elemento(s)\n", i, contador);
  }
}

void acumuladorHash(HashElement *tabela, int uf, float peso){
  int pos = uf % HashSize;
  HashElement *atual = &tabela[pos];

  if (atual->uf == -1) {
    atual->uf = uf;
    atual->soma = peso;
    atual->qt = 1;
    atual->prox = NULL;
    return;
  }

  while (atual != NULL) {
    if (atual->uf == uf) {
      atual->soma += peso;
      atual->qt += 1;
      return;
    }
    if (atual->prox == NULL) break;
    atual = atual->prox;
  }

  total_colisoes += 1;

  HashElement* novo = (HashElement*) malloc(sizeof(HashElement));
  novo->uf = uf;
  novo->soma = peso;
  novo->qt = 1;
  novo->prox = NULL;
  atual->prox = novo;
}


void imprimeMedias(HashElement tabela[]) {
  printf("----------------------------------\n");
  printf("| UF  |\tMedia de Peso (g)   |\n");
  printf("----------------------------------\n");

  for (int i = 0; i < HashSize; i++) {
  HashElement* atual = &tabela[i];
  while (atual != NULL && atual->uf != -1) {
    float media = atual->soma / atual->qt;
    printf("| %02d  |\t%.2f\n", atual->uf, media);
    atual = atual->prox;
  }
  }
}

void inicializadorHash(HashElement tabela[]) {
  for (int i = 0; i < HashSize; i++) {
  tabela[i].uf = -1;
  tabela[i].soma = 0;
  tabela[i].qt = 0;
  tabela[i].prox = NULL;
  }
}

void liberaHash(HashElement tabela[]) {
  for (int i = 0; i < HashSize; i++) {
  HashElement* atual = tabela[i].prox;
  while (atual != NULL) {
    HashElement* temp = atual;
    atual = atual->prox;
    free(temp);
  }
  }
}

int main() {
  FILE *f;
  f = fopen("../../arquivos_auxiliares/sinasc.csv", "r");
  if (f == NULL) {
  perror("Erro ao abrir o arquivo");
  return 1;
  }

  HashElement tabelaHash[HashSize];
  inicializadorHash(tabelaHash);

  char buffer[MAX];
  char *prox;
  char *linha[18];

  fgets(buffer, MAX, f);

  while (fgets(buffer, MAX, f)) {
  prox = NULL;
  linha[0] = strtok_r(buffer, ",\n", &prox);
  for (int i = 1; i < 18; i++) {
    linha[i] = strtok_r(NULL, ",\n", &prox);
    if (linha[i] == NULL) linha[i] = "";
  }

  int codmunres = atoi(linha[1]);
  int peso = atoi(linha[3]);

  if (codmunres > 0 && peso > 0) {
    int uf = codmunres / 10000;
    acumuladorHash(tabelaHash, uf, peso);
  }
  }

  fclose(f);

  imprimeMedias(tabelaHash);
  distribuicaoHash(tabelaHash);
  printf("\nTotal de colisoes na tabela hash: %d\n", total_colisoes);
  liberaHash(tabelaHash);
  return 0;
}
