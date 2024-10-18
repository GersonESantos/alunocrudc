#include <stdio.h>
#include <mysql.h>

MYSQL* conectar_banco() {
    MYSQL *conexao = mysql_init(NULL);
    
    // mysql_real_connect estabelece uma conexão com o servidor MySQL
    if (mysql_real_connect(conexao, "localhost", "root", "Gabibi89*", "alunodb", 3306, NULL, 0)) {
        printf("\nConexão ao banco realizada com sucesso!\n");
    } else {
        printf("Falha de conexão: %s\n", mysql_error(conexao));
        return NULL;
    }
    
    return conexao;
}
