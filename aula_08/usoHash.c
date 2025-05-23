#include <stdio.h>

typedef struct{
  int uf;
  float soma;
  int qt;
  HashElement *next;
}HashElement;

void acumula(HashElement *tabela, int uf, float peso){
  int pos = uf % 31;
  HashElement * atual = &tabela[pos];

  while(atual){
    if(atual->uf == uf){
      atual->soma += peso;
      atual->qt += 1;
      return;
    }
    atual = atual->next;
  }

  if(tabela[pos].uf == 0){
    tabela[pos].soma = peso;
    tabela[pos].qt = 1;
    tabela[pos].uf = uf;
  }else{
    atual = (HashElement*)malloc(sizeof(HashElement));
    atual->uf = uf;
    atual->soma = peso;
    atual->qt = 1;
    atual->next = tabela[pos].next;
    tabela[pos].next = atual;
  }

}