void deletar_aluno(MYSQL *conexao, int id) {
    char query[256];
    
    // Criando a query SQL para deletar o aluno
    sprintf(query, "DELETE FROM Aluno WHERE id=%d", id);
    
    // Executando a query
    if (mysql_query(conexao, query)) {
        printf("Erro ao deletar aluno: %s\n", mysql_error(conexao));
    } else {
        printf("Aluno deletado com sucesso!\n");
    }
}
