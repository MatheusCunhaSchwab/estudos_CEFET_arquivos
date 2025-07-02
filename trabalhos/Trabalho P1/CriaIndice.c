/*Este código deve ser capaz de criar um arquivo onde conterá os índices de um determinado cep*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Endereco Endereco;
typedef struct _indiceCep indiceCep;

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

struct _indiceCep{
    char cep[8];
    long posicao;
};

int compara(const void *e1, const void *e2){
	return strncmp(((indiceCep*)e1)->cep,((indiceCep*)e2)->cep,8);
}


int main()
{
    FILE *f, *g;
    Endereco e;
	indiceCep *ic;
    long tamanho, qtdEnderecos, i = 0;
    

	f = fopen("../../arquivos_auxiliares/cep.dat","rb");
    fseek(f, 0, SEEK_END);
	tamanho = ftell(f);
    rewind(f);
	qtdEnderecos = tamanho / sizeof(Endereco);
    ic = (indiceCep*) malloc(qtdEnderecos * sizeof(indiceCep));
    for(i; i < qtdEnderecos; i+=1){
        fread(&e,sizeof(Endereco),1,f);
        ic[i].posicao = i;
        strncpy(ic[i].cep, e.cep, 8);
    }
    

    /*while(!feof(f)){
        fread(&e,sizeof(Endereco),1,f);
        strncpy(ic[i].cep, e.cep, 8);
        ic[i].posicao = i;
        i += 1;
    }*/

   qsort(ic, qtdEnderecos, sizeof(indiceCep), compara);
	
    g = fopen("indices.dat", "wb");
    fwrite(ic, sizeof(indiceCep), qtdEnderecos, g);

	fclose(f);
    fclose(g);

}

