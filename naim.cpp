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
            printf("��ӳɹ�!\n");
        }
        i++;
     }
     in.close();
}












   
void findbook()
{
    int n;
    cout << "��������Ҫ��ѯ���ֶ���Ŀ" << endl;
    cin >> n;
    int k = 2;
    char name[LEN];
    cout << "��������Ҫ��ѯ���ֶ�" << endl;

    cin >> name;

    cout << "�������ѯ��������ѯһ��ֵ��1����ѯһ����Χ��2\n";
    int div;
    cin >> div;
    if (div == 2)
    {
        char valued[LEN], valueh[LEN];

        cout << "��������Ҫ��ѯ���½�" << endl;

        cin >> valued;
        cout << "��������Ҫ��ѯ���Ͻ�" << endl;
        cin >> valueh;
        sprintf(query, "select * from book where %s > %s and %s < %s", name, valued, name, valueh);
    }
    else
    {
        char value[LEN];

        cout << "��������Ҫ��ѯ��ֵ" << endl;
        cin >> value;
        sprintf(query, "select * from book where %s = %s", name, value);
    }
    while (k <= n)
    {
        char name1[LEN];
        char quer[LEN];
        cout << "��������Ҫ��ѯ���ֶ�" << endl;

        cin >> name1;

        cout << "�������ѯ��������ѯһ��ֵ��1����ѯһ����Χ��2\n";
        int div1;
        cin >> div1;
        if (div1 == 2)
        {
            char valued1[LEN], valueh1[LEN];

            cout << "��������Ҫ��ѯ���½�" << endl;

            cin >> valued1;
            cout << "��������Ҫ��ѯ���Ͻ�" << endl;
            cin >> valueh1;
            sprintf(quer, " and %s > %s and %s < %s", name1, valued1, name1, valueh1);
        }
        else
        {
            char value1[LEN];

            cout << "��������Ҫ��ѯ��ֵ" << endl;
            cin >> value1;

            sprintf(quer, " and %s = %s", name1, value1);
        }

        strcat(query, quer);
        k++;
    }
    char que[LEN] = "BookID", quer[LEN];
    cout << "��������Ҫ������ֶ�" << endl;
    cin >> que;
    sprintf(quer, " order by %s", que);
    strcat(query, quer);
    printf("��ѯ���:%s\n", query);
    int rc = mysql_query(conn, query);
    if (0 != rc)
    {
        printf("mysql_real_query(): %s\n", mysql_error(conn));
        exit(-1);
    }
    else
    {
        printf("��ѯ���:\n");
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
    cout << "�����뿨��" << endl;
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
        printf("δ����Ŀ   ����\n");
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
    cout<<"�����뿨��"<<endl;
    char cardid[LEN], bookname[LEN];
    cin>>cardid;
    cout<<"������Ҫ������"<<endl;
    cin>>bookname;
    char if_book_null[LEN];

    sprintf(if_book_null,"select * from book where bookid='%s' and storenumber>0",bookname);
    






    mysql_query(conn, if_book_null);
            res = mysql_use_result(conn);
            if ((mysql_fetch_row(res)) == NULL){
                cout<<"�����޿�棡"<<endl;
                mysql_free_result(res);
                char coming_date[LEN];
                cout<<"����黹ʱ��"<<endl;
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
                    printf("����ɹ�!\n");
                }
            }

    
}

void bookreturn(){
    cout<<"�����뿨��"<<endl;
    char cardid[LEN], bookname[LEN];
    cin>>cardid;
    cout<<"������Ҫ�������"<<endl;
    cin>>bookname;
    char no_return[LEN];
    sprintf(no_return,"select * from record where cardid=%s and BookID='%s' and intime is NULL",cardid,bookname);
            mysql_query(conn, no_return);
            res = mysql_use_result(conn);
            cout<<no_return<<endl;
            if ((mysql_fetch_row(res)) == NULL)
                cout<<"��������Ҳ�����Ϣ��"<<endl;
                
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
                    printf("����ɹ�!\n");
                }
            }
}

void addcard()
{
    cout << "������Ҫ��ӵĿ��ţ�" << endl;
    char card_number[LEN];
    cin >> card_number;
    cout << "������Ҫ��ӵ�ϵ��" << endl;
    char department[LEN];
    cin >> department;
    cout << "������Ҫ��ӵ����0����ʦ��1��ѧ��" << endl;
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
        printf("��ӳɹ�!\n");
    }
}

int main()
{
    cout << "ͼ��ݹ���ϵͳ" << endl;
    cout << "�����������" << endl;
    cin>>server;
    cout << "�������û���" << endl;
    cin>>user;
    cout << "����������" << endl;
    cin>>password;
    cout << "���������ݿ�" << endl;
    cin>>database;
    init();
    while(1){
    cout << "��������Ҫѡ�������" << endl;
    cout << "1�����룬2����ѯ��3�����飬4�����飬5������֤����6���˳�" << endl;
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
        cout << "���ӽ���֤��1��ɾ������֤��2" << endl;
        cin >> switch_num;
        if (switch_num == 1)
        {
            addcard();
        }
        else
        {
            cout << "������Ҫɾ���Ŀ��ţ�" << endl;
            char card_number[LEN];
            cin >> card_number;
            char prequery[LEN];
            sprintf(prequery, "select * from record where cardid= %s and intime is NULL\n", card_number);
            mysql_query(conn, prequery);
            res = mysql_use_result(conn);
            if ((mysql_fetch_row(res)) != NULL)
                cout << "�ÿ�����δ�黹����Ŀ�����޷�ע����\n"
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
                    printf("ɾ���ɹ�!\n");
                }
            }
        }
        break;
    }
    case 6: {
        printf("�˳�ͼ�����ϵͳ");
        exit(-1);
        break;
    }
    }}
    return 0;
}