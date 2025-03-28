strncmp é usado quando uma das strings não é null terminated ,delimita a quantidade de comparações

MODOS DE CABEÇA DE LEITURA:

-> fseek(arquivo, o_que_você_está_movendo/deslocamento, tipo de whence)
->ftell(arquivo) sempre posição absoluta


whences:
-> absoluto (seek_set) -> onde o deslocamento manda ele ir (positivo ou negativo)
-> seek_end leva para depois do ultimo byte (se tentar ler da EOF, mas pode escrever, aumentando o arquivo)

OBS: Tamanho do arquivo:

fseek(f, 0, SEEK_END)
long tamArquivo = ftell(f);
long registros = tamArquivo / sizeof(Endereco)
fseek(f, 0, SEEK_SET) ou rewind(f)

busca binária de um arquivo:
fseek(f, 0, SEEK_END);
long tamArquivo = ftell(f);
long registros = tamArquivo / sizeof(Endereco)
long qtdRegistros = tamArquivos //  


T(n) = 1 + T(n/2)
T(n/2) = 1 + T(n/4)
T(n/4) = 1 + T(n/8)
...
T(n) = k + T(n/(2^k))

..