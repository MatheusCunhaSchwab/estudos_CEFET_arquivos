#### formas de se ler um arquivo csv:
-> fputs
-> fgets / fscanf / fprintf
-> strtok

#### strtko(buffer, delimitador constante!!)
Uso:
buffer = "abc,def,ghij\n"
char * s = strtok(buffer, ",\n")
printf("%s", &s); -> 'abc'
s = strtok(NULL, ",\n");
printf("%s", &s); -> 'dce'

#### O problema dessa função é ela é não reentrante
Ou seja, não é possível manipular dados de dois arquivos diferentes
#### Isso é corrijido por strtok_r
que recebe o ponteiro do arquivo que deseja manipular
Uso: 
buffer = "abc,def,ghij\n"
char *x;
char *s = strtok_r(buffer, ",\n", &x)
printf("%s", &s); -> 'abc'
#### Seu usa AUTOMATOS para processar arquivos textos de forma mais refinada
Olhe 'awk', pois é bem interessante
#### O arquivo binário é mais interessante por ser mais direto