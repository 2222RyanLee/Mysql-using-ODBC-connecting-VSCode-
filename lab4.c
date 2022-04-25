#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct string
{
    char *a;
    int length;
} string;
typedef struct contain
{
    string *str;
    struct contain *next;
} contain;
string *init()
{

    string *s;
    s = (string *)malloc(sizeof(string));

    s->a = (char *)malloc(100 * sizeof(char));
    return s;
}

void in(string *s)
{
    printf("ÇëÊäÈë\n");
    gets(s->a);
    s->length = strlen(s->a);
}

int compare(string *p, string *q)
{
    if (p->length != q->length)
        return 0;
    else
    {
        int i = 0;
        int count = 0;
        while (i < p->length)
        {
            if (p->a[i] != q->a[i])
            {
                count = 1;
                break;
            }

            i++;
        }
        if (count == 1)
            return 0;
        else
            return 1;
    }
}

int substring(string *s, string *r, int m)
{
    int i = 0;
    int count = 0;
    while (i < r->length)
    {
        if (s->a[i + m] != r->a[i])
        {
            count = 1;
            break;
        }

        i++;
    }
    if (count == 1)
        return 0;
    else
        return 1;
}

void print(string *s)
{
    int i = 0;
    while (i < s->length)
    {
        printf("%c", s->a[i]);
        i++;
    }
}

void unit(string *s, string *r)
{

    int i = 0;
    while (i < r->length)
    {
        s->a[s->length + i] = r->a[i];
        i++;
    }
    s->length = s->length + r->length;
}

string *dif(string *s, int m, int n)
{
    string *temp = init();
    strncpy(temp->a, s->a + m, n - m - 1);
    temp->a[n - m - 1] = '\0';
    temp->length = n - m;
    return temp;
}

string *replace(string *s, string *t, string *v)
{
    int i = 0;
    int j = 0;
    string *temp = init();
    temp->length = 0;
    while (i < (s->length - t->length + 1))
    {
        if (substring(s, t, i))
        {
            unit(temp, v);
            i += t->length;
            j += v->length;
        }
        else
        {
            temp->a[j] = s->a[i];
            temp->length++;
            i++;
            j++;
        }
    }
    while (i < s->length)
    {
        temp->a[j] = s->a[i];
        temp->length++;
        i++;
        j++;
    }

    return temp;
}

contain *cinit()
{
    contain *s = (contain *)malloc(sizeof(contain));
    s->next = NULL;
    return s;
}

char *output(contain *c, int n)
{
    int i = 1;
    contain *temp = c;
    while (i < n)
    {
        temp = temp->next;
    }
    char *s = temp->str->a;
    return s;
}

string *lab4(string *s, string *strin)
{
    contain *temp = cinit();
    contain *c = temp;
    int len = strlen(strin->a);
    char *token;
    char update[100];
    strcpy(update, strin->a);
    const char s1[2] = ",";
    token = strtok(update, s1);

    while (token != NULL)
    {
        c->str = init();
        c->next = NULL;
        c->str->a = token;
        c->str->length = strlen(token);
         //c->str=dif(c->str,2,c->str->length);
        //printf("%s\n", c->str->a);
        c->next = cinit();
        c = c->next;
        token = strtok(NULL, s1);
    }
    c = NULL;

    int i = 0;
    while (temp->next)
    {
        string *v = init();
        v->a = temp->str->a;
        v->length = strlen(v->a);
        string *t = init();
        char quer[100];
        sprintf(quer, "{%d}", i);
        strcpy(t->a, quer);
        t->length = strlen(t->a);
        s = replace(s, t, v);
        temp = temp->next;
        i++;
    }

    return s;
}

int main()
{
    printf("\n");

    string *s = init();
    string *r = init();
    in(s);
    in(r);
    //s->a = " {1} {0} of {1} course is {3}.";
    //s->a="the {0} of the {1} is {2}";
    s->length = strlen(s->a);
    //r->a = "subject,the,course,data structure";
    //r->a="subject,course,data structure";
    r->length = strlen(r->a);
    string *c = init();
    printf("the string is\n");
    print(s);
    printf("\n");
    printf("\n");
    printf("the find string is\n");
    print(r);
    printf("\n");
    printf("\n");
    printf("the replace string is\n");
    s = lab4(s, r);
    print(s);
    printf("\n");
    printf("\n");
    return 0;
}
