#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <WinSock.h>
#include <windows.h>
#include <mysql.h>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;
using std::string;
#define COUNTBOOK 2
#define LEN 50

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
char server[LEN]; 
char user[LEN];
char password[LEN];
char database[LEN];
char query[LEN];

struct book
{
    string booknumber;
    string type;
    string name;
    string pub;
    int year;
    string author;
    double price;
    int number;
};

void init()
{
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0))
    {
        printf("Error connecting to database:%s\n", mysql_error(conn));
        cout << user << endl;
        cout << password << endl;
    }
    else
    {
        printf("Connected...\n");
    }
    if (!mysql_set_character_set(conn, "gbk"))
    {
        //printf("New client character set: %s\n",
               //mysql_character_set_name(conn));
    }
}







void writefile()
{

    int i = 0;
    book s1[COUNTBOOK];
     ifstream in( "stud.txt" , ios::in);
     if (!in.is_open())
     {
         cout <<  "Error: opening file fail"  << endl;
         exit (1);
     }
     while (!in.eof() && i < COUNTBOOK)
     {
         in >> s1[i].booknumber>> s1[i].type>>s1[i].name>>s1[i].pub>>s1[i].year>>s1[i].author>> s1[i].price>>s1[i].number;
     int f1=s1[i].number;
sprintf(query, "insert into book values('%s','%s','%s','%s','%d','%s','%f','%d','%d')", s1[i].booknumber.c_str(), s1[i].type.c_str(),
                s1[i].name.c_str(), s1[i].pub.c_str(), s1[i].year, s1[i].author.c_str(), s1[i].price, f1, f1);
        printf("%s\n", query);

        int rc =
            mysql_query(conn, query);
        if (rc != 0)
        {
            printf("mysql_real_query(): %s\n", mysql_error(conn));

            exit(-1);
        }
        else
        {
            printf("添加成功!\n");
        }
        i++;
     }
     in.close();
}












   
void findbook()
{
    int n;
    cout << "请输入需要查询的字段数目" << endl;
    cin >> n;
    int k = 2;
    char name[LEN];
    cout << "请输入需要查询的字段" << endl;

    cin >> name;

    cout << "请输入查询方法，查询一个值：1，查询一个范围：2\n";
    int div;
    cin >> div;
    if (div == 2)
    {
        char valued[LEN], valueh[LEN];

        cout << "请输入需要查询的下界" << endl;

        cin >> valued;
        cout << "请输入需要查询的上界" << endl;
        cin >> valueh;
        sprintf(query, "select * from book where %s > %s and %s < %s", name, valued, name, valueh);
    }
    else
    {
        char value[LEN];

        cout << "请输入需要查询的值" << endl;
        cin >> value;
        sprintf(query, "select * from book where %s = %s", name, value);
    }
    while (k <= n)
    {
        char name1[LEN];
        char quer[LEN];
        cout << "请输入需要查询的字段" << endl;

        cin >> name1;

        cout << "请输入查询方法，查询一个值：1，查询一个范围：2\n";
        int div1;
        cin >> div1;
        if (div1 == 2)
        {
            char valued1[LEN], valueh1[LEN];

            cout << "请输入需要查询的下界" << endl;

            cin >> valued1;
            cout << "请输入需要查询的上界" << endl;
            cin >> valueh1;
            sprintf(quer, " and %s > %s and %s < %s", name1, valued1, name1, valueh1);
        }
        else
        {
            char value1[LEN];

            cout << "请输入需要查询的值" << endl;
            cin >> value1;

            sprintf(quer, " and %s = %s", name1, value1);
        }

        strcat(query, quer);
        k++;
    }
    char que[LEN] = "BookID", quer[LEN];
    cout << "请输入需要排序的字段" << endl;
    cin >> que;
    sprintf(quer, " order by %s", que);
    strcat(query, quer);
    printf("查询语句:%s\n", query);
    int rc = mysql_query(conn, query);
    if (0 != rc)
    {
        printf("mysql_real_query(): %s\n", mysql_error(conn));
        exit(-1);
    }
    else
    {
        printf("查询结果:\n");
        res = mysql_use_result(conn);
        if ((row = mysql_fetch_row(res)) == NULL)
            cout << "none" << endl;

        if (res)
        {
            while ((row = mysql_fetch_row(res)) != NULL)
            {

                for (int t = 0; t < mysql_num_fields(res); t++)
                    printf("%8s ", row[t]);
                printf("\n");
            }
        }

        mysql_free_result(res);
    }
}

void showcard()
{
    cout << "请输入卡号" << endl;
    char cardnumber[LEN];
    cin >> cardnumber;
    sprintf(query, "select BookID, outtime from Record where CardID= %s and InTime is NULL", cardnumber);
    printf("%s\n", query);
    int rc =
        mysql_query(conn, query);
    if (rc != 0)
    {
        printf("mysql_real_query(): %s\n", mysql_error(conn));
        exit(-1);
    }
    else
    {
        printf("未还书目   借期\n");
        res = mysql_use_result(conn);
        if (res)
        {
            while ((row = mysql_fetch_row(res)) != NULL)
            {

                int t;
                for (t = 0; t < mysql_num_fields(res); t++)
                    printf("%8s ", row[t]);
                printf("\n");
            }
        }
    }
}

void borrow(){
    cout<<"请输入卡号"<<endl;
    char cardid[LEN], bookname[LEN];
    cin>>cardid;
    cout<<"请输入要借的书号"<<endl;
    cin>>bookname;
    char if_book_null[LEN];

    sprintf(if_book_null,"select * from book where bookid='%s' and storenumber>0",bookname);
    






    mysql_query(conn, if_book_null);
            res = mysql_use_result(conn);
            if ((mysql_fetch_row(res)) == NULL){
                cout<<"该书无库存！"<<endl;
                mysql_free_result(res);
                char coming_date[LEN];
                cout<<"最近归还时间"<<endl;
    sprintf(coming_date,"select date_add(outtime, interval 90 day) from record where bookid='%s' order by outtime desc limit 1",bookname);
mysql_query(conn, coming_date);

res = mysql_use_result(conn);
if (res)
        {
            while ((row = mysql_fetch_row(res)) != NULL)
            {

                for (int t = 0; t < mysql_num_fields(res); t++)
                    printf("%8s ", row[t]);
                printf("\n");
            }
        }

        mysql_free_result(res);
mysql_free_result(res);
            }
            else
            {   mysql_free_result(res);
mysql_free_result(res);
                char rebook[LEN];
                sprintf(rebook, "update book set storenumber=storenumber-1 where bookid= '%s' ", bookname);
                
                int i =
                    mysql_query(conn, rebook);
                if (i != 0)
                {
                    printf("mysql_real_query(): %s\n", mysql_error(conn));

                    exit(-1);
                }
                res = mysql_use_result(conn);
                mysql_free_result(res);
                char update_record[LEN];
                sprintf(update_record, "insert into record values('%s',curdate(),NULL,'001','%s')", bookname,cardid);
                cout<<update_record<<endl;
                int j =
                    mysql_query(conn, update_record);
                if (j != 0)
                {
                    printf("mysql_real_query(): %s\n", mysql_error(conn));

                    exit(-1);
                }
                else
                {
                    printf("借书成功!\n");
                }
            }

    
}

void bookreturn(){
    cout<<"请输入卡号"<<endl;
    char cardid[LEN], bookname[LEN];
    cin>>cardid;
    cout<<"请输入要还的书号"<<endl;
    cin>>bookname;
    char no_return[LEN];
    sprintf(no_return,"select * from record where cardid=%s and BookID='%s' and intime is NULL",cardid,bookname);
            mysql_query(conn, no_return);
            res = mysql_use_result(conn);
            cout<<no_return<<endl;
            if ((mysql_fetch_row(res)) == NULL)
                cout<<"还书错误，找不到信息！"<<endl;
                
            else
            {   mysql_free_result(res);
                char rebook[LEN];
                sprintf(rebook, "update book set storenumber=storenumber+1 where bookid= '%s' ", bookname);
                
                int i =
                    mysql_query(conn, rebook);
                if (i != 0)
                {
                    printf("mysql_real_query(): %s\n", mysql_error(conn));

                    exit(-1);
                }
                res = mysql_use_result(conn);
                mysql_free_result(res);
                char update_record[LEN];
                sprintf(update_record, "update record set intime=curdate() where bookid= '%s' and intime is NULL and cardid=%s", bookname,cardid);
                cout<<update_record<<endl;
                int j =
                    mysql_query(conn, update_record);
                if (j != 0)
                {
                    printf("mysql_real_query(): %s\n", mysql_error(conn));

                    exit(-1);
                }
                else
                {
                    printf("还书成功!\n");
                }
            }
}

void addcard()
{
    cout << "请输入要添加的卡号：" << endl;
    char card_number[LEN];
    cin >> card_number;
    cout << "请输入要添加的系：" << endl;
    char department[LEN];
    cin >> department;
    cout << "请输入要添加的类别：0：教师，1：学生" << endl;
    char catagory[LEN];
    cin >> catagory;
    sprintf(query, "insert into card values('%s','ryan','%s',%s)", card_number, department, catagory);
    printf("%s\n", query);
    int rc =
        mysql_query(conn, query);
    if (rc != 0)
    {
        printf("mysql_real_query(): %s\n", mysql_error(conn));

        exit(-1);
    }
    else
    {
        printf("添加成功!\n");
    }
}

int main()
{
    cout << "图书馆管理系统" << endl;
    cout << "请输入服务器" << endl;
    cin>>server;
    cout << "请输入用户名" << endl;
    cin>>user;
    cout << "请输入密码" << endl;
    cin>>password;
    cout << "请输入数据库" << endl;
    cin>>database;
    init();
    while(1){
    cout << "请输入需要选择的命令" << endl;
    cout << "1：插入，2：查询，3：借书，4：还书，5：借书证管理，6：退出" << endl;
    int n;
    cin >> n;

    switch (n)
    {
    case 1:
    {
        writefile();
        break;
    }
    case 2:
    {
        findbook();
        break;
    }
    case 3:
    {

        showcard();
        borrow();
        break;
    }
    case 4:
    {
        showcard();
        bookreturn();
        break;
    }
    case 5:
    {
        int switch_num;
        cout << "增加借书证：1，删除借书证：2" << endl;
        cin >> switch_num;
        if (switch_num == 1)
        {
            addcard();
        }
        else
        {
            cout << "请输入要删除的卡号：" << endl;
            char card_number[LEN];
            cin >> card_number;
            char prequery[LEN];
            sprintf(prequery, "select * from record where cardid= %s and intime is NULL\n", card_number);
            mysql_query(conn, prequery);
            res = mysql_use_result(conn);
            if ((mysql_fetch_row(res)) != NULL)
                cout << "该卡还有未归还的书目，故无法注销！\n"
                     << endl;
            else
            {
                char requery[LEN];
                sprintf(requery, "delete from card where cardid= %s ", card_number);
                cout << requery << endl;
                int rc =
                    mysql_query(conn, requery);
                if (rc != 0)
                {
                    printf("mysql_real_query(): %s\n", mysql_error(conn));

                    exit(-1);
                }
                else
                {
                    printf("删除成功!\n");
                }
            }
        }
        break;
    }
    case 6: {
        printf("退出图书管理系统");
        exit(-1);
        break;
    }
    }}
    return 0;
}