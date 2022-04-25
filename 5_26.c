#include<stdio.h>
#include<stdlib.h>
typedef struct OLNode
{
    int i, j, e;
    struct OLNode *right, *down; 
}OLNode, *OLink;
typedef struct
{
    OLink *rhead, *chead; 
    int mu, nu, tu;  
}CrossList;

CrossList CreateMatrix_OL(CrossList M)
{
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;

    //scanf("%d%d%d", &m, &n, &t);
    M.mu = 3;
    M.nu = 3;
    M.tu = 3;
    if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
    {
        exit(0);
    }
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }
    while(1) {
        printf("ÇëÊäÈëÔªËØ£º");
        scanf("%d %d %d", &i, &j, &e);
        if (i==0){break;};
        if (!(p = (OLNode*)malloc(sizeof(OLNode))))
        {
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;
        if (NULL == M.rhead[i] || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            q = M.rhead[i]; while((q->right) && q->right->j < j){
            
            q = q->right;}
            p->right = q->right;
            q->right = p;
        }
        if (NULL == M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            q = M.chead[j]; while((q->down) && q->down->j < j){
            
            q = q->down;}
            p->down = q->down;
            q->down = p;
        }
    }
    return M;
}
void display(CrossList M) {
    int i=0;
    while (i <= M.nu)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d %d %d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
        i++;
    }
    
}




int main()
{
    CrossList M;
    M = CreateMatrix_OL(M);
    display(M);
    return 0;
}





/*#include "stdio.h"
#include "stdlib.h"
#define elemtype int
typedef struct node
{
    int row;
    int col;
    elemtype e;
    struct node* down;
    struct node* right;
}node, *list;
typedef struct cross
{
 int m;
 int n;
 int tn;
 list * mlist;
 list * nlist;   
}cross;
typedef struct tuple
{
    elemtype e;
    int row;
    int col;
}tuple;

typedef struct tuplelist
{
    tuple *a[50];
    int arow;
    int acol;
}tuplelist;


cross *initcross(int p, int q){
    cross *a;
    a->m=p;
    a->n=q;
    a->tn=0;
    a->mlist=(list*)malloc((p+1)*sizeof(list));
    a->nlist=(list*)malloc((q+1)*sizeof(list));
    int k=0;
    while(k<=p){
    a->mlist[k]=(node*)malloc(sizeof(node));
    a->mlist[k]->col=-1;
    a->mlist[k]->row=-1;
    
    k++;}
    k=0;
    while(k<=q){
    a->nlist[k]=(node*)malloc(sizeof(node));
    a->nlist[k]->col=-1;
    a->nlist[k]->row=-1;
    
    k++;}
    return a;
}
node *initnode(elemtype r, int s,int t){
    node *a;
    a=(list)malloc(sizeof(node));
    a->down=(list)malloc(sizeof(node));
    a->right=(list)malloc(sizeof(node));
    a->down->col=-1;
    a->down->row=-1;
    a->right->col=-1;
    a->right->row=-1;



    a->e=r;
    a->row=s;
    a->col=t;
    return a;
}
cross *add(cross *a,node* b){
int i=b->row;
if (a->mlist[i]->col==-1||a->mlist[i]->col>b->col)

    {a->mlist[i]=b;
    b->right=a->mlist[i];}
else {
    list temp=a->mlist[i];

while (1)
{   
    if (temp->right->col==-1||temp->right->col>b->col)
    break;
    temp=temp->right;
}
list temp2=temp->right;
temp->right=b;
b->right=temp2;
}
int j=b->col;
if (a->nlist[j]->col==-1||a->nlist[j]->row>b->row)
    {a->nlist[j]=b;
    b->down=a->nlist[j];}
else {
    list temp3=a->nlist[j];

while (1)
{   
    if (temp3->down->row==-1||temp3->down->row>b->row)
    break;
    temp3=temp3->down;
}
list temp4=temp3->down;
temp3->down=b;
b->down=temp4;
}
a->tn++;
return a;
}
void getvalue(cross *a){
int i=0;
while(i<=a->m){
    list temp=a->mlist[i];
    while(temp){
        printf("%d %d %d\n",temp->row,temp->col,temp->e);
        temp=temp->right;
    }


    i++;
}
}


int main(){
    cross *a=initcross(4,4);
    list b=initnode(1,1,2);
    list c=initnode(2,2,3);
    a=add(a,b);
    a=add(a,c);
    getvalue(a);
    return 0;
}







/*
#include<stdio.h>
#include<stdlib.h>
typedef struct OLNode
{
    int i, j, e; //?????i??? j??? e?????????
    struct OLNode *right, *down; //??? ??? ???
}OLNode, *OLink;
typedef struct
{
    OLink *rhead, *chead; //????????
    int mu, nu, tu;  //?????,?????????
}CrossList;
CrossList CreateMatrix_OL(CrossList M);
void display(CrossList M);
int main()
{
    CrossList M;
    M.rhead = NULL;
    M.chead = NULL;
    M = CreateMatrix_OL(M);
    printf("????M:\n");
    display(M);
    return 0;
}
CrossList CreateMatrix_OL(CrossList M)
{
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;
    printf("????????????0?????");
    scanf("%d%d%d", &m, &n, &t);
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
    {
        printf("???????");
        exit(0);
    }
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }
    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e)) {
        if (!(p = (OLNode*)malloc(sizeof(OLNode))))
        {
            printf("????????");
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;
        //?????????
        if (NULL == M.rhead[i] || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        //?????????
        if (NULL == M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
    return M;
}
void display(CrossList M) {
    int i=1;
    while(i <= M.nu)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
        i++;
    }
}
*/