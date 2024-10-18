void atualizar_aluno(MYSQL *conexao, int id, Aluno aluno) {
    char query[512];
    
    // Criando a query SQL para atualizar os dados do aluno
    sprintf(query, "UPDATE Aluno SET nome='%s', matricula=%d, anoIngresso=%d, curso='%s' WHERE id=%d", 
            aluno.nome, aluno.matricula, aluno.anoIngresso, aluno.curso, id);
    
    // Executando a query
    if (mysql_query(conexao, query)) {
        printf("Erro ao atualizar aluno: %s\n", mysql_error(conexao));
    } else {
        printf("Dados do aluno atualizados com sucesso!\n");
    }
}
