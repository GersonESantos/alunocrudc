#include <stdio.h>
#include <mysql.h>

// Definição da struct Aluno
typedef struct {
    char nome[255];
    int matricula;
    int anoIngresso;
    char curso[100];
} Aluno;

// Função para exibir o menu
void exibir_menu() {
    printf("\n---- Menu de Opções ----\n");
    printf("1. Inserir Aluno\n");
    printf("2. Atualizar Aluno\n");
    printf("3. Deletar Aluno\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para inserir aluno no banco de dados
void inserir_aluno(MYSQL *conexao) {
    Aluno aluno;
    char query[512];

    // Coleta de dados do aluno
    printf("Nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);
    printf("Matrícula: ");
    scanf("%d", &aluno.matricula);
    printf("Ano de ingresso: ");
    scanf("%d", &aluno.anoIngresso);
    printf("Curso: ");
    scanf(" %[^\n]", aluno.curso);

    // Montando a query SQL para inserir o aluno
    sprintf(query, "INSERT INTO Aluno (nome, matricula, anoIngresso, curso) VALUES ('%s', %d, %d, '%s')", 
            aluno.nome, aluno.matricula, aluno.anoIngresso, aluno.curso);

    // Executando a query no banco de dados
    if (mysql_query(conexao, query)) {
        printf("Erro ao inserir aluno: %s\n", mysql_error(conexao));
    } else {
        printf("Aluno inserido com sucesso!\n");
    }
}

// Função para atualizar um aluno no banco de dados
void atualizar_aluno(MYSQL *conexao) {
    int id;
    Aluno aluno;
    char query[512];

    // Coleta do ID do aluno que será atualizado
    printf("ID do aluno a ser atualizado: ");
    scanf("%d", &id);

    // Coleta dos novos dados do aluno
    printf("Novo nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);
    printf("Nova matrícula: ");
    scanf("%d", &aluno.matricula);
    printf("Novo ano de ingresso: ");
    scanf("%d", &aluno.anoIngresso);
    printf("Novo curso: ");
    scanf(" %[^\n]", aluno.curso);

    // Montando a query SQL para atualizar o aluno
    sprintf(query, "UPDATE Aluno SET nome='%s', matricula=%d, anoIngresso=%d, curso='%s' WHERE id=%d", 
            aluno.nome, aluno.matricula, aluno.anoIngresso, aluno.curso, id);

    // Executando a query no banco de dados
    if (mysql_query(conexao, query)) {
        printf("Erro ao atualizar aluno: %s\n", mysql_error(conexao));
    } else {
        printf("Aluno atualizado com sucesso!\n");
    }
}

int main() {
    MYSQL conexao;
    int opcao;

    // Inicializando conexão com o MySQL
    mysql_init(&conexao);

    // Tentando estabelecer conexão com o banco de dados
    if (mysql_real_connect(&conexao, "localhost", "root", "Gabibi89*", "alunodb", 3306, NULL, 0)) {
        printf("\nConexao ao banco realizada com sucesso!\n");
    } else {
        printf("Falha de conexao: %s\n", mysql_error(&conexao));
        return 1; // Saindo do programa em caso de falha na conexão
    }

    // Laço principal do programa, exibindo o menu até o usuário optar por sair
    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Inserir Aluno foi selecionado.\n");
                inserir_aluno(&conexao);  // Chama a função de inserir aluno
                break;

            case 2:
                printf("Atualizar Aluno foi selecionado.\n");
                atualizar_aluno(&conexao);  // Chama a função de atualizar aluno
                break;

            case 3:
                printf("Deletar Aluno foi selecionado.\n");
                // Chamar a função de deletar aluno (a ser implementada depois)
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);  // O programa continuará executando até o usuário escolher a opção "Sair"

    // Fechar a conexão com o banco de dados
    mysql_close(&conexao);

    return 0;
}

