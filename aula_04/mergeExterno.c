#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int compara(const void *e1, const void *e2)
{
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

void ordenaIntercala(char* f1, char* f2, char* arqSaida)
{
	FILE *a, *b, *saida;
	Endereco ea, eb;
  
	a = fopen(f1,"rb");
	b = fopen(f2,"rb");
	saida = fopen(arqSaida,"wb");

	fread(&ea,sizeof(Endereco),1,a);
	fread(&eb,sizeof(Endereco),1,b);

	// eof -> End Of File
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

void divide()
{
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
}
  void ordena(char* f1)
  {
    FILE *f, *saida;
    Endereco *e;
    long posicao, qtd, metade;
  
    f = fopen(f1,"rb");
    fseek(f,0,SEEK_END);
    posicao = ftell(f);
    qtd = posicao/sizeof(Endereco);
    metade = qtd/2;
    e = (Endereco*) malloc(metade*sizeof(Endereco));
    rewind(f);
    if(fread(e,sizeof(Endereco),metade,f) == metade)
    {
      printf("Lido = OK\n");
    }
    qsort(e,metade,sizeof(Endereco),compara);
    printf("Ordenado = OK\n");
    saida = fopen("cep_a.dat","wb");
    fwrite(e,sizeof(Endereco),metade,saida);
    fclose(saida);
    printf("Escrito = OK\n");
    free(e);
  
    e = (Endereco*) malloc((qtd-metade)*sizeof(Endereco));
    if(fread(e,sizeof(Endereco),qtd-metade,f) == qtd-metade)
    {
      printf("Lido = OK\n");
    }
    qsort(e,qtd-metade,sizeof(Endereco),compara);
    printf("Ordenado = OK\n");
    saida = fopen("cep_b.dat","wb");
    fwrite(e,sizeof(Endereco),qtd-metade,saida);
    fclose(saida);
    printf("Escrito = OK\n");
    free(e);
  
    fclose(f);
  }

int main(){
  
}