#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Uso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo");
    return 1;
  }
  
  int pilha = 0;
  char c;
  while((c = getc(f)) != EOF){
    if(c == '{'){
      pilha += 1;
    } else if( c == '}'){
      pilha -= 1;
    }
    if(pilha < 0){
      break;
    }
  }

  if(pilha != 0){
    printf("Esta desbalanceado");
  } else{
    printf("Esta balanceado");
  }

  fclose(f);
  return 0;
}
