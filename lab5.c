#include "stdio.h"
#include "stdlib.h"
#define elemtype int
typedef struct elem
{
    int i;
    int j;
    elemtype e;
} elem;
typedef struct tri
{
    int m;
    int n;
    int t;
    elem data[50];
} tri;

tri *init()
{
    tri *p = (tri *)malloc(sizeof(tri));
    printf("input m:");
     scanf("%d",&p->m);
    //p->m = 8;
    //p->n = 8;
    //p->t = 8;
    printf("input n:");
     scanf("%d",&p->n);
    printf("input t:");
     scanf("%d",&p->t);
    int count = 0;
    while (1)
    {
        printf("插入新元素\n");
        int r, s, t;
        scanf("%d", &r);
        scanf("%d", &s);
        scanf("%d", &t);
        // r=1;s=2;t=1;
        if (r == 0)
        {
            p->data[count].i = -1;
            break;
        }
        p->data[count].i = r;
        p->data[count].j = s;
        p->data[count].e = t;
        count++;
    }
    return p;
}
void print(tri *t)
{
    int count = 0;
    while (t->data[count].i != -1)
    {
        printf("%d %d %d\n", t->data[count].i, t->data[count].j, t->data[count].e);
        count++;
    }
}
tri *add(tri *a, tri *b)
{
    tri *t = (tri *)malloc(sizeof(tri));
    int tcount = 0, acount = 0, bcount = 0;
    while (1)
    {
        if (a->data[acount].i == -1)
        {
            while (b->data[bcount].i != -1)
            {
                t->data[tcount] = b->data[bcount];
                tcount++;
                bcount++;
            }
        }
        else if (b->data[bcount].i == -1)
        {
            while (a->data[acount].i != -1)
            {
                t->data[tcount] = a->data[acount];
                tcount++;
                acount++;
            }
        }
        else if ((a->data[acount].i < b->data[bcount].i) || ((a->data[acount].i == b->data[bcount].i) && (a->data[acount].j < b->data[bcount].j)))
        {
            t->data[tcount] = a->data[acount];
            tcount++;
            acount++;
        }
        else if ((a->data[acount].i == b->data[bcount].i) && (a->data[acount].j == b->data[bcount].j))
        {
            if ((a->data[acount].e + b->data[bcount].e) != 0)
            {
                t->data[tcount].i = a->data[acount].i;
                t->data[tcount].j = a->data[acount].j;
                t->data[tcount].e = a->data[acount].e + b->data[bcount].e;
                tcount++;
            }

            acount++;
            bcount++;
        }
        else
        {
            t->data[tcount] = b->data[bcount];
            tcount++;
            bcount++;
        }

        if ((a->data[acount].i == -1) && (b->data[bcount].i == -1))
        {
            t->data[tcount].i = -1;
            break;
        }
    }
    return t;
}

tri *sub(tri *a, tri *b)
{
    tri *t = (tri *)malloc(sizeof(tri));
    int tcount = 0, acount = 0, bcount = 0;
    while (1)
    {
        if (a->data[acount].i == -1)
        {
            while (b->data[bcount].i != -1)
            {
                t->data[tcount].i = b->data[bcount].i;
                t->data[tcount].j = b->data[bcount].j;
                t->data[tcount].e = -b->data[bcount].e;
                tcount++;
                bcount++;
            }
        }
        else if (b->data[bcount].i == -1)
        {
            while (a->data[acount].i != -1)
            {
                t->data[tcount] = a->data[acount];
                tcount++;
                acount++;
            }
        }
        else if ((a->data[acount].i < b->data[bcount].i) || ((a->data[acount].i == b->data[bcount].i) && (a->data[acount].j < b->data[bcount].j)))
        {
            t->data[tcount] = a->data[acount];
            tcount++;
            acount++;
        }
        else if ((a->data[acount].i == b->data[bcount].i) && (a->data[acount].j == b->data[bcount].j))
        {
            if ((a->data[acount].e - b->data[bcount].e) != 0)
            {
                t->data[tcount].i = a->data[acount].i;
                t->data[tcount].j = a->data[acount].j;
                t->data[tcount].e = a->data[acount].e - b->data[bcount].e;
                tcount++;
            }

            acount++;
            bcount++;
        }
        else
        {
            t->data[tcount] = b->data[bcount];
            t->data[tcount].i = b->data[bcount].i;
            t->data[tcount].j = b->data[bcount].j;
            t->data[tcount].e = -b->data[bcount].e;
            tcount++;
            bcount++;
        }

        if ((a->data[acount].i == -1) && (b->data[bcount].i == -1))
        {
            t->data[tcount].i = -1;
            break;
        }
    }
    return t;
}

tri *treverse(tri *a)
{
    tri *t = (tri *)malloc(sizeof(tri));
    int row = 1;
    int cow = 1;
    int tcount = 0;
    while (cow <= a->n)
    {
        int count = 0;
        while (a->data[count].i != -1)
        {
            if (a->data[count].j == cow)
            {
                t->data[tcount].i = a->data[count].j;
                t->data[tcount].j = a->data[count].i;
                t->data[tcount].e = a->data[count].e;
                tcount++;
            }
            count++;
        }
        cow++;
    }
    t->data[tcount].i = -1;
    return t;
}

tri *mult(tri *a, tri *b)
{
    if (a->n != b->m)
    {
        printf("wrong row!=cow");
        exit(-1);
    }
    tri *t = (tri *)malloc(sizeof(tri));
    int tcount = 0;
    int acount = 0;
    int arow = 1;
    while (arow <= a->m)
    {   //printf("%d\n",arow);
        int contain[50];
        int ccount = 0;

        while (a->data[acount].i != -1)
        {
            if (a->data[acount].i == arow)
            {
                contain[ccount] = a->data[acount].j;
                ccount++;
            }
            acount++;
        }
        int pc=0;
        //while (pc<ccount){
        //    printf("%d",contain[pc]);
        //    pc++;
        //}
        int bcol = 1;
        while (bcol <= b->n)
        {   
            int sum = 0;
            int bcount = 0;
            int count_count = 0;
            int ifmatch=0;
            while(ifmatch==0){
            while (b->data[bcount].i != -1)
            {
                if (count_count == ccount)
                    break;
                
                if ((b->data[bcount].j == bcol) && (b->data[bcount].i == contain[count_count]))
                {   //printf("%d",b->data[bcount].i);
                    //printf("%d",b->data[bcount].j);
                    //printf("\n");
                    acount=0;
                    //printf("now%d%d\n",a->data[acount].i,a->data[acount].j);
                    //printf("%d\n",contain[count_count]);
                    while (1){
                        if ((a->data[acount].i==arow)&&(a->data[acount].j==contain[count_count])) break;
                        acount++;
                        //printf("ow%d%d\n",a->data[acount].i,a->data[acount].j);
                        
                        
                    }
                    //printf("%d",a->data[acount].i);
                    //printf("%d",a->data[acount].j);
                    //printf("\n");
                    
                    if ((a->data[acount].i==arow)&&(a->data[acount].j==contain[count_count])){
                    sum += a->data[acount].e * b->data[bcount].e;
                    ifmatch=1;
                    bcount=-1;
                    }
                    count_count++;
                    //printf("count%d\n",count_count);
                }
                bcount++;
                
            }
            if (ifmatch==0){
            count_count++;
            bcount=0;
            //printf("%dco\n",contain[count_count]);
            }
            if (count_count==ccount) break;
            }
            if (sum != 0)
            {
                t->data[tcount].i = arow;
                t->data[tcount].j = bcol;
                t->data[tcount].e = sum;
                tcount++;
            }
            bcol++;
        }
        arow++;
    }
    t->data[tcount].i = -1;
    return t;
}

int main()
{
    tri *a = init();
    tri *b = init();
    printf("矩阵a\n");
    print(a);
    printf("矩阵b\n");
    print(b);
    printf("加法结果为：\n");
    tri *t = add(a, b);
    print(t);
    printf("\n");
    printf("减法结果为：\n");
    t = sub(a, b);
    print(t);
    printf("\n");
    printf("转置结果为:\n");
    t = treverse(a);
    print(t);
    printf("\n");
    printf("相乘结果为：\n");
    t = mult(a, b);
    print(t);
    return 0;
}