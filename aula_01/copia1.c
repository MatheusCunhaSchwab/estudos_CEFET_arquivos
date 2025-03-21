#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
  FILE *entrada, *saida;
  int c;

  if(argc != 3)
  {
    fprintf(stderr, "Erro na chamada do comando. \n");
    fprintf(stderr, "Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
    return 1;
  }

  entrada = fopen(argv[1], "rb"); // 'b' é importante no windows
  if(!entrada)
  {
    fprintf(stderr, "Arquivo %s não pode ser aberto para a leitura", argv[1]);
    return 1;
  }
  
  saida = fopen(argv[2], "wb");
  if(!saida)
  {
    fclose(entrada);
    fprintf(stderr, "Arquivo %s não pode ser aberto para a escrita", argv[2]);
    return 1;
  }

  c = fgetc(entrada);
  while(c != EOF)
  {
    fputc(c, saida);
    c = fgetc(entrada);
  }

  fclose(entrada);
  fclose(saida);

  return 0;
}