#include <mysql.h>
#include <stdio.h>

void menu() {
    printf("\n---- Menu ----\n");
    printf("1. Inserir Aluno\n");
    printf("2. Atualizar Aluno\n");
    printf("3. Deletar Aluno\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
 //   MYSQL *conexao = conectar_banco();
   // if (conexao == NULL) return 1;
    
   // int opcao, id;
  // Aluno aluno;
    
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Nome do aluno: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Matrícula: ");
                scanf("%d", &aluno.matricula);
                printf("Ano de ingresso: ");
                scanf("%d", &aluno.anoIngresso);
                printf("Curso: ");
                scanf(" %[^\n]", aluno.curso);
                inserir_aluno(conexao, aluno);
                break;
            
            case 2:
                printf("ID do aluno a ser atualizado: ");
                scanf("%d", &id);
                printf("Novo nome do aluno: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Nova matrícula: ");
                scanf("%d", &aluno.matricula);
                printf("Novo ano de ingresso: ");
                scanf("%d", &aluno.anoIngresso);
                printf("Novo curso: ");
                scanf(" %[^\n]", aluno.curso);
                atualizar_aluno(conexao, id, aluno);
                break;
                
            case 3:
                printf("ID do aluno a ser deletado: ");
                scanf("%d", &id);
                deletar_aluno(conexao, id);
                break;
            
            case 4:
                printf("Saindo...\n");
                break;
            
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
    
    mysql_close(conexao);
    return 0;
}
