#include <stdio.h>

struct Aluno{
    char nome[80];
    float nota1;
    float nota2;
    float media;
  };

struct Aluno lerAluno(){
  struct Aluno a;

  printf("Digite o nome do aluno aqui: ");
  fgets(a.nome, 80, stdin);
  a.nome[strcspn(a.nome, "\n")] = '\0'; //REMOVER O \n DO FINAL DA STRING. 

  printf("Digite a nota da P1: ");
  scanf("%f", &a.nota1);

  printf("Digite a nota da P2: ");
  scanf("%f", &a.nota2);

      getchar();

  a.media = (a.nota1 + a.nota2) / 2;

    return a;
};

void lerTurma(struct Aluno turma[], int tamanho){
  for(int i = 0; i < tamanho; i++){
   printf("\n--- Aluno %d ---\n", i + 1);
   turma[i] = lerAluno();
  }
}

void mostrarResultado(struct Aluno turma[], int tamanho){
      printf("\n===== RESULTADO FINAL =====\n");

      for(int i = 0; i < tamanho; i++){
        printf("\nAluno: %s\n", turma[i].nome);
        printf("Nota P1: %.2f\n", turma[i].nota1);
        printf("Nota P2: %.2f\n", turma[i].nota2);
        printf("Média: %.2f\n", turma[i].media);
  
        if (turma[i].media >= 6.0) {
            printf("Status: APROVADO\n");
        } else {
            printf("Status: REPROVADO\n");
        }
    }

}

int main (){
  struct Aluno turma[5]; 

  lerTurma(turma, 5);
  mostrarResultado(turma, 5);

  return 0;
}