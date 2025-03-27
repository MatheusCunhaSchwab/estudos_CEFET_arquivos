#include <stdio.h>

int main(int argc, char** argv){
    char c;
    int qtd = 0;
    FILE *entrada;
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

    do{
        c = getc(entrada);
        if (c == '\n' || c == EOF){
            qtd += 1;
        }
    }while(c != EOF);

    printf("Quantidade de linhas: %d\n", qtd);
    fclose(entrada); //nao esquecer
    return 0;
}