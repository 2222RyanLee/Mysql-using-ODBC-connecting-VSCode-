#ifndef DAtACONNECTION_H_
#define DAtACONNECTION_H_
#include <bits/stdc++.h>
#include <WinSock.h>  
#include "mysql.h"
#include <string>

const int cmdSize = 10000000;
class DataConnection
{

private:
    MYSQL_RES *res = NULL;
    MYSQL_ROW column = NULL;
    char query[5000];
    MYSQL mysql;

public:
    bool connectDataBase();
};

#endif