#include<stdio.h>
#include<string.h>

typedef struct _Endereco Endereco;

#define N 8

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char* argv){
	FILE *f, *g;
	Endereco e;
	int c = 0, i = 0;
  char nomearq[10];
	f = fopen("/workspaces/Estudos-CEFET-Arquivos/arquivos_auxiliares/cep_reduzido.dat","rb");
	fseek(f, 0, SEEK_END);
  int tamArquivo = ftell(f);
  rewind(f);
	int qtdRegistros = tamArquivo / sizeof(Endereco);
  while(c < qtdRegistros){
    sprintf(nomearq, "a%d.dat", i);
    g = fopen(nomearq, "wb");
		fseek(f, c*sizeof(Endereco), SEEK_SET);
    for(int j = 0; j <= 9; j += 1){
      fread(&e, sizeof(Endereco), 1, f);
      fwrite(&e, sizeof(Endereco), 1, g);
    }
    fclose(g);
		c += (qtdRegistros/N);
    i += 1;
	}
	return 0;
}