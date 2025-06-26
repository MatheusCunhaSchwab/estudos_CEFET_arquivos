2. Responda objetivamente:
(a) Em uma tabela de hash onde h(chave) = chave%11, ao inserir as chaves 10, 33, 85,
43, 27, 63, 95, 88 e 32, quantas colis˜oes ocorrem?
(b) Quantas chaves precisam ser inseridas (no m´ınimo) em uma ´arvore B de grau 3 para
atingir altura 3?

Resposta:
    (a) 10 na 10
        33 na 0 
        85 na 8 
        43 na 10    COLISÃO
        27 na 5
        63 na 8     COLISÃO
        95 na 7
        88 na 0     COLISÃO
        32 na 10    COLISÃO

        Ou seja, temos 4 colições
    
    (b) 