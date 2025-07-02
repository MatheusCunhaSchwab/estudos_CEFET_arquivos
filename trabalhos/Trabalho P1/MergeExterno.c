#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numero_partes 8

typedef struct{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
} Endereco;

int compara(const void *e1, const void *e2){
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

void intercala(char* f1, char* f2, char* fSaida){
	FILE *a, *b, *saida;
	Endereco ea, eb;

	a = fopen(f1,"rb");
	b = fopen(f2,"rb");
	saida = fopen(fSaida,"wb");

	fread(&ea,sizeof(Endereco),1,a);
	fread(&eb,sizeof(Endereco),1,b);

	while(!feof(a) && !feof(b))
	{
		if(compara(&ea,&eb)<0) // ea < eb
		{
			fwrite(&ea,sizeof(Endereco),1,saida);
			fread(&ea,sizeof(Endereco),1,a);
		}
		else // ea >= eb
		{
			fwrite(&eb,sizeof(Endereco),1,saida);
			fread(&eb,sizeof(Endereco),1,b);
		}
	}

	while(!feof(a))
	{
		fwrite(&ea,sizeof(Endereco),1,saida);
		fread(&ea,sizeof(Endereco),1,a);		
	}
	
	while(!feof(b))
	{
		fwrite(&eb,sizeof(Endereco),1,saida);
		fread(&eb,sizeof(Endereco),1,b);		
	}

	fclose(a);
	fclose(b);
  remove(f1);
  remove(f2);
	fclose(saida);
}

void separa_ordena(FILE* f, FILE* saida){
  char nomearq[15];
  long qtdEnderecos, enderecosPorParte, sobra, posicao;
  Endereco *e;

	fseek(f, 0, SEEK_END);
	posicao = ftell(f);
	qtdEnderecos = posicao / sizeof(Endereco);
	enderecosPorParte = qtdEnderecos / numero_partes;
	sobra = qtdEnderecos % numero_partes;
	rewind(f);

  for (int i = 0; i < numero_partes; i++) {
		if (i == (numero_partes - 1)) {
			enderecosPorParte += sobra; //Extra no ultimo arquivo
		}

		e = (Endereco*) malloc(enderecosPorParte * sizeof(Endereco));

		fread(e, sizeof(Endereco), enderecosPorParte, f);

		qsort(e, enderecosPorParte, sizeof(Endereco), compara);
    
		sprintf(nomearq, "cep_%d.dat", i);
		saida = fopen(nomearq, "wb");
		fwrite(e, sizeof(Endereco), enderecosPorParte, saida);

		fclose(saida);
		free(e);
	}
}

int main(int agrc, char* argv[]){
  FILE* f = fopen("../../arquivos_auxiliares/cep.dat", "rb");
  FILE* saida;
  int qtdPartes = numero_partes, prox = 0;
	char fName0[20], fName1[20], fName2[20];
  
  separa_ordena(f, saida);

  sprintf(fName0, "cep_%d.dat", prox);
	sprintf(fName1, "cep_%d.dat", prox + 1);
	sprintf(fName2, "cep_%d.dat", qtdPartes);

	while (qtdPartes <= (numero_partes * 2) - 2) {
		intercala(fName0, fName1, fName2);

		qtdPartes += 1;
		prox += 2;

		sprintf(fName0, "cep_%d.dat", prox);
		sprintf(fName1, "cep_%d.dat", prox + 1);
		sprintf(fName2, "cep_%d.dat", qtdPartes);

	}
  
  rename(fName0, "Cep_ordenado.dat");
  fclose(f);
  
  return 0;
}