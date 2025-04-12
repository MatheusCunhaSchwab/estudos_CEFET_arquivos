#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    
    if (f1 == NULL || f2 == NULL) {
        if (f1 == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo: %s\n", file1);
        }
        if (f2 == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo: %s\n", file2);
        }
        return -1; // Erro ao abrir arquivos
    }
    
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int result = 0; // 0 = arquivos iguais
    
    while (1) {
        size_t bytes_read1 = fread(buffer1, 1, BUFFER_SIZE, f1);
        size_t bytes_read2 = fread(buffer2, 1, BUFFER_SIZE, f2);
        
        // Verifica se a quantidade de bytes lidos é diferente
        if (bytes_read1 != bytes_read2) {
            result = 1; // Arquivos diferentes
            break;
        }
        
        // Se nenhum byte foi lido, chegamos ao final dos arquivos
        if (bytes_read1 == 0) {
            break;
        }
        
        // Compara os buffers
        if (memcmp(buffer1, buffer2, bytes_read1) != 0) {
            result = 1; // Arquivos diferentes
            break;
        }
    }
    
    fclose(f1);
    fclose(f2);
    
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <arquivo1> <arquivo2>\n", argv[0]);
        return 1;
    }
    
    int result = compare_files(argv[1], argv[2]);
    
    if (result == -1) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }
    
    if (result == 0) {
        printf("Os arquivos sao iguais.\n");
    } else {
        printf("Os arquivos sao diferentes.\n");
    }
    
    return 0;
}