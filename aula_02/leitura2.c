#include <stdio.h>

int main(int argc, char** argv){
  char c;
  FILE *entrada;
  int qt[256] = {0};

  if (argc != 2){
    fprintf(stderr, "Erro na chamada do comando. \n");
    return 1;
  }

  entrada = fopen(argv[1], "rb"); // 'b' é importante no windows
  if(!entrada)
  {
    fprintf(stderr, "Arquivo %s não pode ser aberto para a leitura", argv[1]);
    return 1;
  }

  c = getc(entrada);
  while(c != EOF){
    qt[c] += 1;
    c = getc(entrada);
  }

  for(int i = 0; i < 256; i++){
    if(qt[i])
      printf("codigo tabela asc: %d \t qtd ocorrencias: %d \n", i, qt[i]);
  }

  fclose(entrada);
  return 0;
}