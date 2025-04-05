#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
  FILE *entrada;
  char* palavra, BUFFER[8192];
  int c = 0;

  if(argc != 2)
  {
    fprintf(stderr, "Erro na chamada do comando. \n");
    return 1;
  }

  entrada = fopen("/workspaces/Estudos-CEFET-Arquivos/arquivos_auxiliares/letraBadRomance.txt", "rb"); // 'b' é importante no windows
  if(!entrada)
  {
    fprintf(stderr, "Arquivo %s não pode ser aberto para a leitura", entrada);
    return 1;
  }

  palavra = argv[2];
  printf("%s", palavra);

  while(c != EOF)
  {
    c = 
    while (c != ' '){
      //BUFFER += c;
    }
  }

  fclose(entrada);

  return 0;
}