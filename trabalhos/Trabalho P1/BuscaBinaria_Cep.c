#include <stdio.h>
#include <string.h>

typedef struct{
	char logradouro[72], bairro[72], cidade[72], uf[72], sigla[2], cep[8], lixo[2];
}Endereco;

int main(int argc, char**argv){
	FILE *f;
	Endereco e;
	int inicio, meio, fim; 
	int QtdRodagens = 0;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	f = fopen("../../arquivos_auxiliares/cep_ordenado.dat","rb");
	fseek(f, 0, SEEK_END);

	int tamArquivo = ftell(f);
  int qtdRegistros = tamArquivo / sizeof(Endereco);
	
	inicio = 0;
	fim = qtdRegistros;
	
  while(inicio <= fim){
		//SÓ SE USA OS REGISTROS PARA PERCORRER

		meio = (inicio + fim) / 2;
		fseek(f, meio * sizeof(Endereco), SEEK_SET);
		fread(&e,sizeof(Endereco),1,f);

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
			QtdRodagens += 1;
			inicio = meio + 1;
		} else { // strncmp(argv[1], e.cep, 8) < 0
			QtdRodagens += 1;
			fim = meio - 1;
		}

	}
	printf("Quantidade de visualizacoes: %d\n", QtdRodagens);
	fclose(f);
}

