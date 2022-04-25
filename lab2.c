

#include "stdio.h"
#include "stdlib.h"
#define elemtype int
typedef struct link
{
    elemtype chdata;
    struct link *succ;
    struct link *next;
} link, linklist;
linklist *newnode(elemtype x)
{
    linklist *new;
    new = (linklist *)malloc(sizeof(linklist));
    new->chdata = x;
    new->succ = NULL;
    new->next = NULL;
    return new;
};
linklist *addnode(linklist *L, elemtype x)
{
    linklist *ptc = L->succ, *ptf = L, *new;
    new = (linklist *)malloc(sizeof(linklist));
    new->chdata = x;

    if (!ptc)
    {
        L->succ = new;
        new->next = L;
        new->succ = NULL;
    }
    while (ptc)
    {
        ptf = ptf->succ;
        ptc = ptc->succ;
        if (!ptc)
        {
            ptf->succ = new;
            new->next = ptf;
            new->succ = NULL;
        }
    }

    return L;
};

void print1(linklist *L)
{
    linklist *p = L;
    int m, n;
    while (1)
    {
        m = p->next->chdata;

        printf("%d", m);

        p = p->succ;
        if (!p)
            break;
    }
}
void print(linklist *L)
{
    linklist *p = L;
    int m, n;
    while (1)
    {
        m = p->chdata;

        printf("%d", m);

        p = p->succ;
        if (!p)
            break;
    }
}

linklist *kmp(linklist *L)
{
    linklist *ptf = L, *new, *ptc;
    new = (linklist *)malloc(sizeof(linklist));
    new->succ = ptf;
    new->next = new;
    int add = 0;
    new->chdata = add;
    ptf->next = new;
    ptc = new;
    while (ptf->succ)
    {

        if (ptc == new || ptf->chdata == ptc->chdata)
        {
            ptf = ptf->succ;
            ptc = ptc->succ;
            ptf->next = ptc;
        }
        else
        {
            ptc = ptc->next;
        }
    }

    return new;
}

int main()
{
    linklist *s;
    s = newnode(8);
    s = addnode(s, 7);
    s = addnode(s, 8);
    s = addnode(s, 7);
    s = addnode(s, 8);
    s = addnode(s, 9);

    linklist *mode;
    mode = newnode(7);
    mode = addnode(mode, 8);
    mode = addnode(mode, 7);
    mode = addnode(mode, 9);
    printf("字符串为\n");
    printf("0");
    print(mode);
    printf("\n");
    mode = kmp(mode);
    printf("kmp算法在何处返回\n");
    print1(mode);
    printf("\n");

    printf("字符串为\n");
    printf("0");
    print(s);
    printf("\n");
    s = kmp(s);
    printf("kmp算法在何处返回\n");
    print1(s);
    return 0;
}