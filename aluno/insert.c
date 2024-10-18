void inserir_aluno(MYSQL *conexao, Aluno aluno) {
    char query[512];
    
    // Criando a query SQL para inserir o aluno
    sprintf(query, "INSERT INTO Aluno (nome, matricula, anoIngresso, curso) VALUES ('%s', %d, %d, '%s')", 
            aluno.nome, aluno.matricula, aluno.anoIngresso, aluno.curso);
    
    // Executando a query
    if (mysql_query(conexao, query)) {
        printf("Erro ao inserir aluno: %s\n", mysql_error(conexao));
    } else {
        printf("Aluno inserido com sucesso!\n");
    }
}
