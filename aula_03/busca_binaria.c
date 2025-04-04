#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

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

int main(int argc, char**argv)
{
	FILE *f;
	Endereco e;
	int qt;
	int inicio, meio, fim; 
	int c;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
	c = 0;
	printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
	f = fopen("/workspaces/Estudos-CEFET-Arquivos/arquivos_auxiliares/cep_ordenado.dat","rb");
	fseek(f, 0, SEEK_END);
	int tamArquivo = ftell(f);
	int qtdRegistros = tamArquivo / sizeof(Endereco);
	inicio = 0;
	fim = qtdRegistros;
	while(inicio <= fim){
		//SÓ SE USA OS REGISTROS PARA PERCORRER
		meio = (inicio + fim) / 2;
		fseek(f, meio*sizeof(Endereco), SEEK_SET);
		qt = fread(&e,sizeof(Endereco),1,f);
		if (strncmp(argv[1], e.cep, 8) == 0){
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",
				e.logradouro,
				e.bairro,
				e.cidade,
				e.uf,
				e.sigla,
				e.cep);
			break;
		} else if(strncmp(argv[1], e.cep, 8) > 0){
			c += 1;
			inicio = meio + 1;
		} else { // strncmp(argv[1], e.cep, 8) < 0
			c += 1;
			fim = meio - 1;
		}
	}
	printf("Quantidade de visualizações: %d\n", c);
	fclose(f);
}

