#include <stdio.h>
#include <string.h>

typedef struct {
  int id, idade;
  char nome[30], especie[20];
  float peso;
} Paciente;

void buscarRegistro(FILE *arquivo, int targetId) {
  Paciente paciente;
  int tamArquivo, qtdPacientes, inicio, fim, meio;

  fseek(arquivo, 0, SEEK_END);
  tamArquivo = ftell(arquivo);
  qtdPacientes = tamArquivo / sizeof(Paciente);
  inicio = 0;
  fim = qtdPacientes - 1;

  while (inicio <= fim) {
      meio = (inicio + fim) / 2;
      fseek(arquivo, sizeof(Paciente) * meio, SEEK_SET);

      if (fread(&paciente, sizeof(Paciente), 1, arquivo) != 1) {
          printf("Erro ao ler o arquivo.\n");
          return;
      }

      if (targetId == paciente.id) {
          printf("Paciente encontrado:\n");
          printf("ID: %d\n", paciente.id);
          printf("Nome: %s\n", paciente.nome);
          printf("Espécie: %s\n", paciente.especie);
          printf("Idade: %d\n", paciente.idade);
          printf("Peso: %.2f\n", paciente.peso);
          return;
      } else if (targetId > paciente.id) {
          inicio = meio + 1;
      } else {
          fim = meio - 1;
      }
  }

  printf("Paciente com ID %d não encontrado.\n", targetId);
}

void adicionarInformacoes(FILE *arquivo) {
  Paciente paciente, aux;
  int tamArquivo, qtdPacientes, inicio, fim, meio;

  scanf("%d", &paciente.id);
  getchar(); // consome \n

  // Verifica se o ID já existe
  rewind(arquivo);
  fseek(arquivo, 0, SEEK_END);
  tamArquivo = ftell(arquivo);
  qtdPacientes = tamArquivo / sizeof(Paciente);
  inicio = 0;
  fim = qtdPacientes - 1;

  while (inicio <= fim) {
      meio = (inicio + fim) / 2;
      fseek(arquivo, sizeof(Paciente) * meio, SEEK_SET);
      fread(&aux, sizeof(Paciente), 1, arquivo);

      if (paciente.id == aux.id) {
          printf("ID já existe.\n");
          return;
      } else if (paciente.id > aux.id) {
          inicio = meio + 1;
      } else {
          fim = meio - 1;
      }
  }

  // Leitura dos dados
  printf("Nome: ");
  fgets(paciente.nome, sizeof(paciente.nome), stdin);
  paciente.nome[strcspn(paciente.nome, "\n")] = '\0';

  printf("Espécie: ");
  fgets(paciente.especie, sizeof(paciente.especie), stdin);
  paciente.especie[strcspn(paciente.especie, "\n")] = '\0';

  printf("Idade: ");
  scanf("%d", &paciente.idade);
  printf("Peso: ");
  scanf("%f", &paciente.peso);

  // Adiciona ao final
  fseek(arquivo, 0, SEEK_END);
  fwrite(&paciente, sizeof(Paciente), 1, arquivo);
  printf("Paciente adicionado com sucesso.\n");
}

void substituirInformacoes(FILE* arquivo, int targetId) {
  Paciente paciente;
  int tamArquivo, qtdPacientes, inicio, fim, meio, achou = 0;

  rewind(arquivo);
  fseek(arquivo, 0, SEEK_END);
  tamArquivo = ftell(arquivo);
  qtdPacientes = tamArquivo / sizeof(Paciente);
  inicio = 0;
  fim = qtdPacientes - 1;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    fseek(arquivo, sizeof(Paciente) * meio, SEEK_SET);
    fread(&paciente, sizeof(Paciente), 1, arquivo);

    if (targetId == paciente.id) {
      achou = 1;
      break;
    } else if (targetId > paciente.id) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }

  if (!achou) {
    printf("Paciente não encontrado.\n");
    return;
  }

  // Substituição de dados
  printf("Nova idade e peso: ");
  scanf("%d %f", &paciente.idade, &paciente.peso);
  getchar(); // consome \n

  printf("Nova espécie: ");
  fgets(paciente.especie, sizeof(paciente.especie), stdin);
  paciente.especie[strcspn(paciente.especie, "\n")] = '\0';

  printf("Novo nome: ");
  fgets(paciente.nome, sizeof(paciente.nome), stdin);
  paciente.nome[strcspn(paciente.nome, "\n")] = '\0';

  fseek(arquivo, sizeof(Paciente) * meio, SEEK_SET);
  fwrite(&paciente, sizeof(Paciente), 1, arquivo);
  printf("Informações atualizadas com sucesso.\n");
}


int main(int argc, char ** argv){

  if(argc != 2){
    printf("Chamada incorreta de funcao");
    return 1;
  }
  FILE *arquivo = fopen(argv[1], "rb+");
}