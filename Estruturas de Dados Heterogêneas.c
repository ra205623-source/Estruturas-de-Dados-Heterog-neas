#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 30
#define TAM_NOME 60

// Definição da Estrutura Heterogênea (Registro)
typedef struct {
    int matricula;
    char nome[TAM_NOME];
    float p1;
    float p2;
    float dac;
    float media_final;
} Aluno;

// Função auxiliar para calcular a média
float calcular_media(float p1, float p2, float dac) {
    float p_especifica = (p1 + p2) / 2.0f;
    return (0.2f * dac) + (0.8f * p_especifica);
}

int main() {
    Aluno turma[MAX_ALUNOS];
    int total_alunos;

    printf("=== SISTEMA DE GESTÃO DE TURMA (STRUCTS) ===\n\n");
    printf("Quantos alunos deseja cadastrar (máx %d)? ", MAX_ALUNOS);
    scanf("%d", &total_alunos);

    if (total_alunos > MAX_ALUNOS) {
        total_alunos = MAX_ALUNOS;
    }

    // Leitura dos dados e armazenamento no vetor de structs
    for (int i = 0; i < total_alunos; i++) {
        printf("\n--- Cadastro do Aluno %d ---\n", i + 1);
        
        printf("Matrícula: ");
        scanf("%d", &turma[i].matricula);
        
        // Limpa o buffer do teclado antes de ler string
        getchar();
        
        printf("Nome completo: ");
        fgets(turma[i].nome, TAM_NOME, stdin);
        // Remove a quebra de linha tratada pelo fgets
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';

        printf("Nota P1: ");
        scanf("%f", &turma[i].p1);
        
        printf("Nota P2: ");
        scanf("%f", &turma[i].p2);

        printf("Nota DAC: ");
        scanf("%f", &turma[i].dac);

        // Processamento dos campos da struct
        turma[i].media_final = calcular_media(turma[i].p1, turma[i].p2, turma[i].dac);
    }

    // Exibição do relatório geral
    printf("\n=========================================================\n");
    printf("%-10s %-25s %-8s %-10s\n", "MATRÍCULA", "NOME", "MÉDIA", "SITUAÇÃO");
    printf("=========================================================\n");

    for (int i = 0; i < total_alunos; i++) {
        char situacao[15];
        if (turma[i].media_final >= 7.0f) {
            strcpy(situacao, "Aprovado");
        } else if (turma[i].media_final < 4.0f) {
            strcpy(situacao, "Reprovado");
        } else {
            strcpy(situacao, "Exame Final");
        }

        printf("%-10d %-25s %-8.1f %-10s\n", 
               turma[i].matricula, 
               turma[i].nome, 
               turma[i].media_final, 
               situacao);
    }
    printf("=========================================================\n");

    return 0;
}