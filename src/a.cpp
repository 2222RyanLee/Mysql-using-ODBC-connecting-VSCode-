#include "C:\Coding\Projects\DSExercise\include\a.hpp"
bool DataConnection::connectDataBase()
{
    mysql_init(&mysql);
    const char host[] = "127.0.0.1";
    const char user[] = "root";
    const char passwd[] = "root";
    const char db[] = "managework";
    unsigned int port = 3306;
    const char *unix_socket = NULL;
    unsigned long client_flag = 0;

    if (mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag))
    {
        mysql_query(&mysql, "set names gbk");
        return true;
    }
    else
    {
        return false;
    }
}
