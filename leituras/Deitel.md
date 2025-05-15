## Introdução
-> O armazenamento de dados em array é temporário (perdidos quando um programa é encerrado), como soluçao, os ARQUIVOS sõa usados na conservação permanente dos dados.

## Hierarquia de dados
-> A menor item de dado que um computador pode armazenar é um __BIT__ (binary digit). <br>
-> Caracteres: dados em forma de digitos decimais, letras e símbolos especiais. <br>
-> A combinação de bits é chamada de __BYTE__, dos quias representarão caracteres e possuem 8 bits (0 a 255).<br>
-> Campo: conjunto de caracteres com significado. <br>
-> Registro: é uma estrutura de dados com vários campos (ou seja,o struct de C).
-> Arquivo: grupo de registros relacionados. <br>
-> Chave de registro: identifica e relaciona uma determinado registro a uma pessoa ou entidade. <br>
-> Arquivo sequencial: Organizado segundo a chave de registro. <br>
-> Banco de dados: combinação de arquivos para, por ex, administração de um sistema. <br>

## Arquivos e streams
-> Em C, todo arquivo termina com um 'marcador de fim de arquivo. <br>
-> Stream é  sequência de bytes usada para realizar operações de entrada (leitura) ou saída (gravação) de dados, associada a uma fonte (como um arquivo, teclado) ou destino (como a tela ou um arquivo). <br>
-> Existem três tipos de stream padrão em C: stdin, stderr e stdout. <br>
-> Quando um arquivo é aberto usando FILE*, se é colocado em um array de arquivos abertos. <br>
-> Existem funções de leitura/escrita de char em arquivos, sendo elass, respectivamente, fgetc e fputc. Mas existem outras também.
## Criação de um arquivo de acesso sequencial
-> C não impôe nenhuma estrutura de arquivos ou registros, portanto, cabe ao programador providenciar. Aqui vai um ex:
<pre>
    // Definição do registro
typedef struct {
    int matricula;
    char nome[MAX_NOME];
    float media;
} Aluno;

int main() {
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Leitura e exibição dos registros
    while (fscanf(arquivo, "%d %s %f", &aluno.matricula, aluno.nome, &aluno.media) == 3) {
        printf("Matrícula: %d | Nome: %s | Média: %.2f\n", aluno.matricula, aluno.nome, aluno.media);
    }

    fclose(arquivo);
</pre>
-> o ponteiro File apontará para o arquivo alunos.txt, que aí sim poderá modifica-lo (caso a configuração permita). <br>
-> Formas de abrir um arquivo: para criar um arquivo ou sobrescrever, use "w"; para ler um arquivo existente, use "r". para acrescentar registros ao final do arquivo existente, use "a"."r+" e "a+" abre um arquivo para leitura e escrita, porém o segundo escreverá no final do arquivo. "w+" cria um arquivo para leitura e gravação (se o arquivo existir, seu conteudo é descartado) OBS: no windows se coloca o b no final, ex: rb (legível no windows). <br>
-> É uma boa prática se fechar um arquivo ao final de seu uso, mesmo que o SO faça isso quando o programa finaliza. <br>
-> Cada arquivo usado em um programa precisa ter um nome exclusivo, e terá um ponteiro retornado por fopen. <br>
#### Modos de Abertura de Arquivo em C

| Modo  | Descrição                                                                 |
|-------|---------------------------------------------------------------------------|
| `r`   | Abre um arquivo existente para leitura.                                   |
| `w`   | Cria um arquivo para gravação. Se o arquivo já existe, descarta o conteúdo atual. |
| `a`   | Acréscimo; abre ou cria um arquivo para gravação no final do arquivo.     |
| `r+`  | Abre um arquivo existente para atualização (leitura e gravação).          |
| `w+`  | Cria um arquivo para atualização. Se o arquivo já existe, descarta o conteúdo atual. |
| `a+`  | Acréscimo; abre ou cria um arquivo para atualização; a gravação é feita no final do arquivo. |
| `rb`  | Abre um arquivo existente para leitura no modo binário.                   |
| `wb`  | Cria um arquivo para gravação no modo binário. Se o arquivo já existe, descarta o conteúdo atual. |
| `ab`  | Acréscimo; abre ou cria um arquivo para gravação no final do arquivo no modo binário. |
| `rb+` | Abre um arquivo existente para atualização (leitura e gravação) no modo binário. |
| `wb+` | Cria um arquivo para atualização no modo binário. Se o arquivo já existe, descarta o conteúdo atual. |
| `ab+` | Acréscimo; abre ou cria um arquivo para atualização no modo binário; a gravação é feita no final do arquivo. |

## Leitura de dados em um arquivo sequencial
-> fscanf recebe como argumento um ponteiro de arquivo do qual os dados foram lidos <br>
-> feof retorna verdade de o que está sendo lido é um "end of file". <br>
-> "rewind ([ponteiro])" faz o ponteiro em questão voltar ao início do ponteiro. <br>

## Arquivos de acesso aleatório
-> Se considerarmos um arquivo de acesso aleatório com tamanhos fixos, são vantajosos pois podem ser acessados de forma direta (ou seja, mais rapidamente.<br>
-> Como todos os registros em um arquivo normalmente tem o mesmo tamanho, o local exato de um registro em relação ao início do arquivo pode ser calculado como uma função da __chave de registro__.<br>
-> Registros de tamanho fixo permitem que os dados sejam inseridos em um arquivo de acesso aleatório sem destruir outros dados do arquivo. Os dados armazenados anteriormente também podem ser atualizados ou excluidos sem que seja necessário regravar o arquivo inteiro.

## Criação de um arquivo de acesso aleatório 
-> A função __fwrite__ transfere para um arquivo um numero especificado de bytes a partir de um local especicficado na memória:
<pre>fwrite(&variavel_que_será_escrita, tamanho_do_item, quantidade, arquivo_escrito)</pre>
-> A função __fread__ transfere um número especificado de bytes do local no arquivo especificado pelo ponteiro de posição do arquivo para uma área na memória que começa como endereço especificado:
<pre>fread(&variavel_que_será_escrita, tamanho_do_item, quantidade, arquivo_lido)</pre> 
-> Exemplo de uso para gravar um inteiro:
<pre>
    De: fprintf(fPtr, "%d",  number);
    Para: fwrite(&number, sizeof(int), 1, fPtr);
</pre>
->  As funções fwrite e fresd são capazes de ler e gravar arrays de dados, do disco e para o disco. O terceiro elemento de fread e fwrite são o número de elementos no array que devem ser lidos ou gravados no disco. <br>
-> É uma boa prática se gravar/ler somente 1 struct por vez. <br>

## Escrita aleatória de dados em um arquivo de acesso aleatório
-> Outra forma de percorrer arquivos é com fseek.
<pre>fseek(arquivo, deslocamento, tipo)
  variações de tipo:
  -> SEEK_END: Em relação ao final do arquivo 
  -> SEEK_SET: Em relação ao começo do arquivo 
  -> SEEK_CUR: Em relação a posição atual da cabeça de leitura</pre>
-> Ele pode ser usado junto com fwrite para escrever em qualquer posição do arquivo. <br>
-> offset ou deslocamento: Calculo usado para acessar um local específico do arquivo. Ex: quero acessar a conta qualquer , aqui como se faz:
<pre>
 fseek(cfPtr, (Client.accNum - 1) * sizeof(struct ClientData), SEEK_SET);
</pre>
 Neste exemplo, o offset é __(Client.accNum - 1) * sizeof(struct ClientData)__. <br>
-> fscanf retorna o número de itens lidos ou EOF<br>
-> fseek retorna 0 se der certo a busca e qqr valor diferente caso a operação de busca não puder ser realizada. <br>
-> fwrite retorna o número de foram escritos com sucesso. OBS: se o retorno for menor que o 3° argumento, houve um erro na gravação da função.

## Leitura de dados de um arquivo de acesso aleatório
-> a função freaf lê um número especificado de bytes a partir de um arquivo para a memória:
<pre>fread(&client, sizeof(Struct ClientData), 1, cfPtr)</pre>
Lê o número de bytes determinados por sizeof(struct ClientData) do arquivo referenciado por cfPtr, e armazena os dados na estrutura Client. <br>
-> A função fread pode ser usada para ler vários elementos do array de tamanho fixo, oferecendo um ponteiro ao array em que os elementos serão armazenados e indicanso o número de elementos a serem lidos <br>

# OLHAR O CÓDIGO EM 11.10, POIS TEM NA PRÁTICA COMO FUNCIONA TODAS AS TECNICAS ABORDADAS NESTE MÓDULO