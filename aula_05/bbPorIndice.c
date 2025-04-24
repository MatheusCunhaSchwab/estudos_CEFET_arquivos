//Antes de rodar este programa, se roda o indices.c

#include <stdio.h>
#include <string.h>

typedef struct {
	char logradouro[72],bairro[72],cidade[72], uf[72], sigla[2], cep[8], lixo[2]; 
} Endereco;

typedef struct {
    char cep[8];
    long posicao;
} IndiceCep;

int main(int argc, char**argv)
{
	FILE *f, *g;
	Endereco e;
    IndiceCep ic;
	int qt;
	int inicio, meio, fim; 
	int qtdrodagens = 0;
    long aux;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	f = fopen("indices.dat","rb");
	fseek(f, 0, SEEK_END);
	int tamArquivo = ftell(f);
	int qtdRegistros = tamArquivo / sizeof(IndiceCep);

	inicio = 0;
	fim = qtdRegistros;

	while(inicio <= fim){
		//SÓ SE USA OS REGISTROS PARA PERCORRER
		meio = (inicio + fim) / 2;
		fseek(f, meio*sizeof(IndiceCep), SEEK_SET);
		qt = fread(&ic,sizeof(IndiceCep),1,f);
		if (strncmp(argv[1], ic.cep, 8) == 0){
			printf("O seu cep %.8s foi encontrado com indice %ld\n",
				ic.cep,
                ic.posicao);
                aux = ic.posicao;
			break;
		} else if(strncmp(argv[1], ic.cep, 8) > 0){
			qtdrodagens += 1;
			inicio = meio + 1;
		} else { // strncmp(argv[1], e.cep, 8) < 0
			qtdrodagens += 1;
			fim = meio - 1;
		}
	}
    g = fopen("../arquivos_auxiliares/cep.dat", "rb");
    fseek(g, aux*sizeof(Endereco), SEEK_SET);
    fread(&e, sizeof(Endereco), 1, g);
    printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
	printf("Quantidade de visualizações: %d\n", qtdrodagens);
	fclose(f);
}

