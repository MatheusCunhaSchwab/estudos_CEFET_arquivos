1. Suponha que o campo de busca de uma ´arvore B seja de tamanho V = 9bytes, o tamanho
do bloco de disco seja B = 512bytes, um ponteiro de registro (para o arquivo de dados)
seja Pr = 7bytes, e um ponteiro de bloco (para as outras p´aginas da ´arvore B) seja Pb = 6
bytes. Cada n´o da ´arvore B possui no m´aximo n ponteiros de ´arvore, n − 1 ponteiros de
dados e n − 1 valores de campos-chave de busca que devem caber em um ´unico bloco de
disco.
(a) Estime o valor de n.
(b) Quantas chaves cabem no m´aximo e no m´ınimo em um bloco n˜ao raiz?
(c) Suponha que em uma determinada ´arvore B, sabe-se que todos os n´os tˆem em m´edia
70% de ocupa¸c˜ao. Indique no terceiro n´ıvel da ´arvore a quantidade de chaves armazenadas.

Respostas:
    (a) n ponteiros, n-1 chaves, n-1 ponteiros para a tabela de dados
        N * Pb + (n-1) * V + (n-1) * Pr <= B
        6N + 9N - 9 + 7N - 7 <= 512
        22N - 16 <= 512
        N <= 528 / 22 -> N <= 24

    (b) max: grau - 1 -> 23
        min: max / 2 -> 11

    (c) 100 - 23 assim como 70 - x, logo, x = 16
        1° nivel - 1 chave
        2° nivel - 16 chaves
        3° nivel - 16^2 chaves

        Portanto, no total teremos 1 + 16 + 16^2 = 273