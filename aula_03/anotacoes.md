COMO USAR O FSEEK:
  fseek(arquivo, deslocamento em relação ao troço, troço)
  variações de troço:
  -> SEEK_END: Em relação ao começo do arquivo 
  -> SEEK_SET: Em relação ao começo do arquivo 
  -> SEEK_CUR: Em relação a posição atual da cabeça de leitura

Como organizar um arquivo/ORDENAÇÃO:
  OBS: o quick sorte funciona melhor que o merge sort pelo menor quanidade de cópias da memória
  o melhor método é quando o arquivo cabe em memória, se coloca todo na memória e organiza-o
  o melhor método é quando o arquivo não cabe em memória se chama EXTERNAL MERGE SORT

Ex quickSort:
  void quick(int V[], int inicio, int fim){
    if(inicio < fim){
      int p = particiona(V, inicio, fim); [complexidade O(n)]
      quick(V, inicio, p-1); [complexidade O(n/2)]
      quick(V, p+1, fim); [complexidade O(n/2)]
    }
  }

int compara(const void *e1, const void *e2){
  return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep, 8);
}

dentro da função qsort, o ultimo parametro é um ponteiro de uma função, que será o critério de ordenação


CALLBACKS:
f será uma variável do tipo ponteiro para funçao que recebe dois inteiros e retorna inteiro
EX:
int (*f) (int, int);
f = soma;
printf("%d\n", f(3, 4));

