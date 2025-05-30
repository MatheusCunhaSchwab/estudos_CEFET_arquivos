### Leitura obrigatória: 
    -> paper sobre árvore (rudolf Bayer); 
    -> Bons livros de BD (Navathe 7° edição está curtida no meu perfil)

### O que é uma árvore B:
    -> É a principal estrutura de dados usada por bancos de dados. 
    -> É uma estrutura que cada nó pode possuir um N ponteiros para outros nós

### Definição formal de uma árvore B:
    Uma árvore B é uma árvore de busca balanceada com as seguintes propriedades:

    1) Cada nó tem um certo número de chaves e filhos.
    2) Todas as folhas estão no mesmo nível (mesma profundidade).
    3) Um nó interno com k chaves tem k+1 filhos.
    4) Todas as chaves dentro de um nó são armazenadas em ordem crescente.
    5) Para cada chave X em um nó interno e seu filho Pi, todas as chaves no subárvore de Pi são menores que X se Pi é o filho à esquerda de X, e maiores que X se Pi é o filho à direita de X. (Isso é uma generalização da propriedade de uma árvore binária de busca).
    6) Existe um limite inferior e superior para o número de chaves que um nó pode conter (exceto a raiz). Esse limite é determinado pela ordem (ou grau mínimo) da árvore B. Se a ordem mínima é m, então cada nó (exceto a raiz) deve ter pelo menos m−1 chaves e no máximo 2m−1 chaves. A raiz pode ter entre 1 e 2m−1 chaves

### Definição Simples de uma árvore B:
    Imagine uma árvore onde cada "galho" (nó) pode ter muitos "frutos" (chaves) e muitos "galhos menores" (filhos). A Árvore B é especial porque:

    -> É organizada: Os frutos dentro de cada galho estão sempre em ordem, e os galhos menores são organizados de forma que é fácil saber onde procurar um fruto específico.
    -> É "baixinha" e "larga": Em vez de ser alta e fina como algumas árvores, ela é mais baixa e larga, o que significa que você não precisa descer muitos níveis para encontrar o que procura. Isso é ótimo para quando os dados estão em um disco rígido, pois acessar o disco é lento.
    -> Se auto-arruma: Quando você adiciona ou remove frutos, a árvore se ajusta automaticamente para continuar organizada e "baixinha", garantindo sempre um bom desempenho.

### O Metodo de inserção é o Split!!

### Definição formal do split:
    Como o Split Funciona
    -> Nó Cheio: Um nó já tem o número máximo de chaves e uma nova chave precisa ser inserida nele.
    -> Chave Mediana: A chave do meio (mediana) desse nó cheio é selecionada.
    -> Criação de Novos Nós: O nó original é dividido em dois novos nós. O novo nó à esquerda conterá as chaves menores que a mediana, e o novo nó à direita conterá as chaves maiores que a mediana.
    -> Promoção da Mediana: A chave mediana é então "promovida" para o nó pai (o nó acima na árvore). Ela se torna uma chave de separação no nó pai, indicando que os dados menores estão em um subárvore e os maiores em outro.
    -> Reajuste do Pai: O nó pai, ao receber a chave mediana, pode também atingir sua capacidade máxima e, se isso acontecer, ele próprio precisará passar por um split, e assim por diante. Esse processo pode se propagar até a raiz da árvore. Se a raiz for dividida, uma nova raiz é criada, e a altura da árvore aumenta.

### O que é?
    -> Quando ocorre um "estouro", o item do meio sobe e se cria um novo nó
    -> Quando a raiz tem estouro, umanova raiz é criada seguinfo o mesmo conceito

### Link para vizualização
    https://www.cs.usfca.edu/~galles/visualization/BTree.html


### Propriedades da Árvore B
    Uma Árvore B é uma estrutura de dados de árvore auto-balanceável otimizada para armazenamento e recuperação eficiente de grandes volumes de dados, como os encontrados em bancos de dados e sistemas de arquivos. Suas propriedades fundamentais garantem que ela seja sempre balanceada e eficiente nas operações de busca, inserção e exclusão.

    Considerando uma Árvore B de ordem m (ou grau mínimo m), as seguintes propriedades se aplicam:

    1. Todas as Folhas Estão no Mesmo Nível (Mesma Profundidade)
    -> Esta é a propriedade mais crucial para o balanceamento. Significa que, não importa o caminho que você siga da raiz até qualquer folha, a quantidade de "degraus" (níveis) será sempre a mesma. Isso assegura que o tempo para encontrar qualquer dado seja consistentemente rápido, pois o número de acessos é sempre o mesmo, evitando cenários onde alguns dados estariam muito "profundos" na árvore.

    2. Cada Nó, Exceto a Raiz, Tem Pelo Menos m−1 Chaves
    -> Para evitar que a árvore fique muito esparsa e ineficiente, cada nó (exceto a raiz) deve conter um número mínimo de chaves (dados). Se um nó tiver menos de m−1 chaves, ele precisará "pegar emprestado" de um irmão ou se fundir com um.

    -> Exceção da Raiz: A raiz é o único nó que pode ter menos de m−1 chaves (pode ter apenas 1 chave, por exemplo), pois ela é o ponto de partida da árvore e seu tamanho não afeta diretamente o balanceamento de forma negativa.
    
    3. Cada Nó Tem no Máximo 2m−1 Chaves
    -> Esta propriedade define a capacidade máxima de um nó. Quando um nó atinge esse limite e uma nova chave precisa ser adicionada, ele passa por um processo chamado split (divisão). O nó é dividido em dois, e a chave mediana é promovida para o nó pai, garantindo que a árvore continue organizada e sem nós superlotados.

    4. Cada Nó Interno com k Chaves Tem k+1 Filhos
    -> Em um nó interno (que não é folha), o número de ponteiros para filhos é sempre uma unidade a mais do que o número de chaves. Por exemplo, se um nó tem 3 chaves, ele terá 4 ponteiros para seus filhos. Cada chave serve como um "divisor" que orienta a busca para o próximo nível da árvore.

    5. Todas as Chaves Dentro de um Nó São Armazenadas em Ordem Crescente
    -> Dentro de cada nó, as chaves são mantidas estritamente em ordem crescente. Isso facilita a busca linear dentro do próprio nó e a identificação rápida de qual ponteiro de filho seguir para continuar a busca pela chave desejada.

    6. As Chaves em um Nó Atuam como Valores de Separação para os Filhos
    -> Esta propriedade é crucial para a navegação na árvore:

        Se um nó tem chaves C1,C2,…,Ck e filhos P0,P1,…,Pk:
            Todas as chaves na subárvore apontada por P0 são menores que C1.
            Todas as chaves na subárvore apontada por Pi (para 0<i<k) estão entre Ci e Ci+1.
            Todas as chaves na subárvore apontada por Pk são maiores que Ck.
        Isso permite que o algoritmo de busca descarte rapidamente grandes porções da árvore, direcionando-se sempre para o subárvore que, potencialmente, contém a chave procurada.

#### O split preemptivo ocorre SOMENTE em arvores que contem um número par de elementos

### Implementação e C
    sruct no{
        T chave chaves[N];
        T pont filhos [N+1];
        T pont dados[N];
    }

### Como calcular o melhor N
    EX:
    
    T pont tem 4 bytes
    T chave tem 8 bytes

    n = (sizeof(T chave) * 8 + sizeof(T pont) * 4 + sizeof(T pont) * 4 < 8192)


    h   n           chaves
    1   300         301
    2   300*301     301^2



### Arvore B+
    -> criada pq a arvore B possui um problema de nulidade em alguns nós da arvore B
    -> junta o ponteiro de filhos e conteudo, forçando sempre a descida até as folhas