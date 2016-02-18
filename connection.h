MYSQL *connection() {
        /* Attempt to connect to the server */
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
                perror(mysql_error(conn));
                return 0;
        } else {
                return conn;
        }
}
