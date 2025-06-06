### Arvore b+
    as chaves ficam replicadas

### Problema árvore B
    -> ALTA NULIDADE
    -> A arvore b+ resolve esse problema dividindo a estrutura das folhas e dos nós intermediários


### Estruturas usadas em b+

    struct PagBPlusLeaf
    {
        int q;
        Tchave chaves[N];
        Tpont registros[N];
        Tpont prox;
    }

    struct PagBPluss
    {
        int q;
        Tchave chaves[N];
        Tpont filhos[N+1];
    }
