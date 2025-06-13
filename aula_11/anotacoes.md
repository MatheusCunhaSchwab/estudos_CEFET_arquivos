compactações possuem duas categorias:
-> As que reduzem a qualidade de imagem
-> As que não reduzem qualidade de imagem

.zip é um compactador e "juntador" de arquivos, facilitando o envio 

Ex:
<pre>
aaaabbcadaabbcbdccaaaabbbaae
13 a, 7 b, 4 c, 2 d, 1 e

Algoritmo guloso: o que sempre quer mais ou o maior (existe a variação para o que busca o menor)

Primeiro, coloca-se no min heap os caracteres e ocorrências
(os elementos do heap são subárvores de Ruff)

vai se colocando e refazendo as subárvores até sobrar 1 item na heap
                    28
                 <0>/ \<1>
                   15  A 13         
               <0>/  \<1>
                 7    B 8
             <0>/ \<1> 
               3    C 4
           <0>/ \<1>
            D 2  E 1


A 1
B 01
C 001
D 0000
E 0001

Assim, compactado vira:
11110101001100001101010010100000010011111010101110001
dividindo em bytes, temos algo 8 vezes menor que isso (passa junto a tabela de representação)
</pre>

Para a arvore de Ruffman ser "boa", precisa ter um número de ocorrencias desiguais dos simbolos

Todos as extensões de arquivos da Microsoft são tipos de compactações

Todo arquivo pertencente a um .zip, o file header, tem um começo mágico, para .zip, 50 4B 03 04

O formato zip não é só para compressão, mas tambem para reunir arquivos, organizando-os

Na prova (choro) não será cobrado detalhes, mas sim sua implementação