#include<stdio.h>
#include<string.h>

typedef struct _Endereco Endereco;

#define N 80

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
	FILE* f;
	FILE* g;
	Endereco e;
	int c = 0;
	f = fopen("/workspaces/Estudos-CEFET-Arquivos/arquivos_auxiliares/cep.dat","rb");
	fseek(f, 0, SEEK_END);
	int tamArquivo = ftell(f);
	int qtdRegistros = tamArquivo / sizeof(Endereco);
	g = fopen("/workspaces/Estudos-CEFET-Arquivos/arquivos_auxiliares/cep_reduzido.dat", "wb");
	while(c < N){
		fseek(f, c*sizeof(Endereco), SEEK_SET);
		fread(&e, sizeof(Endereco), 1, f);
		fwrite(&e, sizeof(Endereco), 1, g);
		c +=1;
	}
	return 0;
}