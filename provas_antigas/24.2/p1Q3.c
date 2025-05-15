#include <stdio.h>

typedef struct{
  int matricula;
}StructS;

int compara(const void *a, const void *b){
  const S *s1 = (const S*)a;
  const S *s2 = (const S*)b;
  return (s1->matricula - s2->matricula); 
}

int main(int argc, char ** argv){
  if(argc != 3){
    fprintf(stderr, "Uso incorreto de chamada da função");
    return 1;
  }
  
  FILE *f, *g, *h;
  StructS *s1, *s2;

  f = fopen(argv[1], "rb");
  if(f == NULL){
    fprintf(stderr, "erro na abertura do arquivo %s", argv[1]);
    return 1;
  }
  
  g = fopen(argv[2], "rb");
  if(g == NULL){
    fprintf(stderr, "erro na abertura do arquivo %s", argv[2]);
    return 1;  
  }

  h = fopen("Resultado.dat", "wb");
  if(h == NULL){
    fprintf(stderr, "erro na criação do arquivo de saida");
    return 1;
  }

  StructS comecoArq2, fimArq2;
  fread(&comecoArq2, sizeof(S), 1, g);
  fseek(g, -sizeof(S), SEEK_END);
  fread(&fimArq2, sizeof(S), 1, g);
  rewind(g);

  StructS R1, R2;
  while (fread(&R1, sizeof(S), 1, f) == 1) {
      if (R1.matricula < comecoArq2.matricula || 
          R1.matricula > fimArq2.matricula) {
          fwrite(&R1, sizeof(S), 1, h);
          continue;
      }
      
      int inicio = 0;
      fseek(g, 0, SEEK_END);
      int fim = (ftell(g) / sizeof(S)) - 1;
      int encontrado = 0;

      while (inicio <= fim) {
          int meio = (inicio + fim) / 2;
          fseek(g, meio * sizeof(S), SEEK_SET);
          fread(&R2, sizeof(S), 1, g);

          if (R1.matricula == R2.matricula) {
              encontrado = 1;
              break;
          } else if (R1.matricula > R2.matricula) {
              inicio = meio + 1;
          } else {
              fim = meio - 1;
          }
      }

      if (!encontrado) {
          fwrite(&R1, sizeof(S), 1, h);
      }
  }

  fclose(f);
  fclose(g);
  fclose(h);
  return 0;
}