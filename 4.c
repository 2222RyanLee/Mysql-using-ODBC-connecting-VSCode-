#include "stdio.h"
#include "stdlib.h"
typedef struct string
{
    char *a;
    int length;
} string;

string *init()
{
    //
    string *s;
    s = (string *)malloc(sizeof(string));

    s->a = (char *)malloc(100 * sizeof(char));
    return s;
}

void in(string *s)
{
    int i = 0;
    scanf("%d", &s->length);
    while (i < s->length)
    {
        scanf("%s", &s->a[i]);
        i++;
    }
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
    int i = m;
    while (i < n)
    {
        temp->a[i] = s->a[i];
        i++;
    }
    temp->length = n = m;
    return temp;
}

string *replace(string *s, string *t, string *v)
{
    int i = 0;
    int j = 0;
    string *temp = init();
    temp->length = 0;
    while (i < (s->length - t->length))
    {
        if (substring(s, t, i))
        {
            unit(temp, v);
            i += t->length;
            j += v->length;
            s->length = s->length + v->length - t->length;
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

int main()
{
    string *s = init();
    string *r = init();
    in(s);
    in(r);
    string *c = init();
    in(c);
    printf("the string is\n");

    print(s);
    printf("\n");
    printf("the find string is\n");

    print(r);
    printf("\n");
    printf("the replace string is\n");

    print(c);
    printf("\n");
    c = replace(s, r, c);
    printf("the result is\n");
    print(c);
    return 0;
}