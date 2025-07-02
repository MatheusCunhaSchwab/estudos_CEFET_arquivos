#include <stdio.h>
#include <string.h>

#define QtdPartes 4

int main(){
    FILE *f = fopen("../../arquivos_auxiliares/dados_dos_famosos.csv", "r");
    char buffer[64];
    int aux = 0;
    fgets(buffer, 64, f);
    while (!feof(f))
    {
        char *x;
        char *t = strtok_r(buffer, ",\n", &x);
        while(t && aux < QtdPartes){
            printf("%-20s|", t);
            t = strtok_r(NULL, ",\n", &x);
            aux += 1;
        }
        printf("\n");
        aux = 0;
        fgets(buffer, 64, f);
    }
    fclose(f);
    return 0;
}