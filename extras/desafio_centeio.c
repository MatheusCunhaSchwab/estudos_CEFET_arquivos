#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
  FILE *entrada;
  char* palavra, BUFFER[8192];
  int c = 0;

  if(argc != 3)
  {
    fprintf(stderr, "Erro na chamada do comando. \n");
    return 1;
  }

  entrada = fopen(argv[1], "rb"); // 'b' é importante no windows
  if(!entrada)
  {
    fprintf(stderr, "Arquivo %s não pode ser aberto para a leitura", argv[1]);
    return 1;
  }

  palavra = argv[2];
  printf("%s", palavra);

  while(c != EOF)
  {
    while (c != ' '){
      //BUFFER += c;
    }
  }

  fclose(entrada);

  return 0;
}