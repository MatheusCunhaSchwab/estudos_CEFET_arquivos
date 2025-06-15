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
  struct HashElement *next;
} HashElement;

void HashDistribution(HashElement table[]) {
  printf("\nDistribuição da tabela hash:\n");
  for (int i = 0; i < HashSize; i++) {
    int contador = 0;
    HashElement* atual = &table[i];
    if (atual->uf != -1) {
      contador++;
      atual = atual->next;
      while (atual != NULL) {
        contador++;
        atual = atual->next;
      }
    }
    printf("Posicao %2d: %d elemento(s)\n", i, contador);
  }
}

void HashAccumulator(HashElement *tabela, int uf, float peso){
  int pos = uf % HashSize;
  HashElement *atual = &tabela[pos];

  if (atual->uf == -1) {
    atual->uf = uf;
    atual->soma = peso;
    atual->qt = 1;
    atual->next = NULL;
    return;
  }

  while (atual != NULL) {
    if (atual->uf == uf) {
      atual->soma += peso;
      atual->qt += 1;
      return;
    }
    if (atual->next == NULL) break;
    atual = atual->next;
  }

  total_colisoes += 1;

  HashElement* novo = (HashElement*) malloc(sizeof(HashElement));
  novo->uf = uf;
  novo->soma = peso;
  novo->qt = 1;
  novo->next = NULL;
  atual->next = novo;
}


void printMediumWeight(HashElement table[]) {
  printf("----------------------------------\n");
  printf("| UF  |\tMedia de Peso (g)   |\n");
  printf("----------------------------------\n");

  for (int i = 0; i < HashSize; i++) {
  HashElement* atual = &table[i];
  while (atual != NULL && atual->uf != -1) {
    float media = atual->soma / atual->qt;
    printf("| %02d  |\t%.2f\n", atual->uf, media);
    atual = atual->next;
  }
  }
}

void HashTableInicializer(HashElement table[]) {
  for (int i = 0; i < HashSize; i++) {
  table[i].uf = -1;
  table[i].soma = 0;
  table[i].qt = 0;
  table[i].next = NULL;
  }
}

void FreeTable(HashElement table[]) {
  for (int i = 0; i < HashSize; i++) {
  HashElement* atual = table[i].next;
  while (atual != NULL) {
    HashElement* temp = atual;
    atual = atual->next;
    free(temp);
  }
  }
}

int main() {
  FILE *f = fopen("../arquivos_auxiliares/sinasc.csv", "r");
  if (f == NULL) {
  perror("Erro ao abrir o arquivo");
  return 1;
  }

  HashElement HashTable[HashSize];
  HashTableInicializer(HashTable);

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
    HashAccumulator(HashTable, uf, peso);
  }
  }

  fclose(f);

  printMediumWeight(HashTable);
  HashDistribution(HashTable);
  printf("\nTotal de colisões na tabela hash: %d\n", total_colisoes);
  FreeTable(HashTable);
  return 0;
}
