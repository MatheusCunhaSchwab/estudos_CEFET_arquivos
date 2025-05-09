#### Pergunta: qual as diferenças entre fwrite e fprintf?

fwrite -> Escrita em arquivo binário <br>
fprintf -> Escrita formatada em arquivo <br>

endianess -> Em Little-endian, dados menos significativos são alocados em posições de menor significancia. Enquanto em Big-endian, dados de mais significativos são alocados en posições de menor significancia

## Aula de hoje: HASH
-> Dada uma função hash(chave), ele me dá a posição que corresponde <br>
-> Tem que ter um tamanho pré definido <br>
-> Uma boa função de hash <strong> ESPALHA BEM AS CHAVES </strong> <br>
-> Conceito importante para segurança da informação <br>
-> Uso para dar saltos em algoritmos de criptografia <br>
-> Ex: uso do digito verificador do cpf como hash
<pre>
    void funcaoHash(int cpf){
        int dv = cpf % 11;
        adicionarNaTabela(dv, cpf); //teria como acertar a colisão com o uso de listas encadeadas
    }

Em Python:
    def h(key): 
        return int(hashlib.sha1(key).hexdigest(),16) % hashsize
</pre>
-> Tem como problema a <strong>COLISÂO</strong> (ocorre quando dois "objetos" possuem a mesma chave) <br>
-> Se busca sempre <u>minimizar a colisão</u><br>