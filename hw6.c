#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#define elemtype char

typedef struct btree
{
    elemtype item;
    struct btree * lchild;
    struct btree * rchild;
}btree;
btree* tinit(){
    btree *t=(btree*)malloc(sizeof(btree));
    t->lchild=NULL;
    t->rchild=NULL;
    return t;
}
btree * inputvalue(btree *t){

        char a;
        t=(btree*)malloc(sizeof(btree));
        scanf("%c",&a);
        if (a!='0'){
            t->item=a;
            t->lchild=inputvalue(t->lchild);
            t->rchild=inputvalue(t->rchild);
            }
        else {
        t=NULL;}
    return t;
}
void printtree(btree*t){
    if (t!=NULL){
        printf("%c",t->item);
        printtree(t->lchild);
        printtree(t->rchild);
    }
    else printf("N");

}
void delete(btree *t,char x){
    if (t){
    if (t->item==x){
        free (t->lchild);
        free (t->rchild);
        t->lchild=NULL;
        t->rchild=NULL;

    }
    else{
        delete(t->lchild,x);
        delete(t->rchild,x);

    }
    }
}

void printlink(btree *t,char i){
    t=t->lchild;
    while (1){
        if (t==NULL) break;
        char j=t->item;
        printf("%c %c\n",i,j);
        printlink(t,j);
        t=t->rchild;
    }
}



int main(){
    
    printf("input the form of a bother-children tree\n");
    btree* t=inputvalue(t);
    printf("\n");
    char i=t->item;
    printf("the link is :\n");
    printlink(t,i);
    return 0;
}
