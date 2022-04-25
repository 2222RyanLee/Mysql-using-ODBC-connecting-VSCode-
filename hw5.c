#include<stdio.h>
#include<stdlib.h>
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










#define elemtype int
typedef struct link
{   int tag;
    struct link * next;
    union{
        elemtype atom;
        struct link* p;
    };
}link;
link * linit(){
    link *a=(link*)malloc(sizeof(link));
    a->next=NULL;
    a->tag=1;
    a->p==NULL;
    return a;
}
link *addintolist(link *c,string * sub,int count){
    int n=sub->length;
    sub=dif(sub,1,n);

    int len = strlen(sub->a);
    char *token;
    char update[100];
    strcpy(update, sub->a);
    const char s1[2] = ",";
    int i=0,j=0;
    string * substr=init();
    while(update[i]!=','&&i<strlen(sub->a)){
        i++;
    }
    substr=dif(sub,0,i+1);
    link* ptlink=c;
    link *pt;
    while (strlen(substr->a)!=0)
    {   
        if(strlen(substr->a)==1){
            ptlink->tag=0;
            ptlink->atom=atoi(substr->a);
            printf("the elem is %d and the layer is %d\n",ptlink->atom,count);}
            else {
                ptlink->tag=1;
                string *str=init();
                str=substr;
                ptlink->p=linit();
                ptlink->p=addintolist(ptlink->p,str,count+1);
            }
            ptlink->next=(link*)malloc(sizeof(link));
            ptlink=ptlink->next;
            
    j=i;
    i++;
    if(update[i]=='('){
    while(update[i]!=')'&&i<strlen(sub->a)){
        i++;
    }    
    }
    else{
    while(update[i]!=','&&i<strlen(sub->a)){
        i++;
    }}

    substr=dif(sub,j+1,i+1);
    }


    return c;
}
int main(){
    string *a=init();
    in(a);
    printf("\n");
    link *l=linit();
    int count=0;
    l=addintolist(l,a,count);
    return 0;
}

