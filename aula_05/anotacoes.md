### O que é um indice?
É um "semiendereço" de algo que mostra onde está algo, ou ainda, uma <strong>chave</strong> que te leva para algum conteúdo <br>

### Problema da Busca binária
-> O arquivo deve estra ordenado <br>
-> O arquivo é ordenado por somente um parâmetro

#### Para se acertar isso, se usa índices

### O que existe em um arquivo de índices?
-> Chaves e uma informação de onde algo desejado está <br>
-> EX: 
<pre>
struct IndiceCep
{
    char cep[8];
    long posicao; (imagine como um ponteiro de memória em disco)
}
</pre>

### O problema de utilizar muitos indeces são:
-> Espaço ocupado (por menor que seja) <br>
-> Atualização do arquivo original (por conta da atualização de índices)