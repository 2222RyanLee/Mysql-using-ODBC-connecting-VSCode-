#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define MAXSIZE 50
typedef struct seq
{
  int *list[MAXSIZE];
  int front;
  int rear;
} seq;
seq *init(int k)
{
  seq *p;
  p = (seq *)malloc(sizeof(seq *));
  p->list[MAXSIZE] = (int *)malloc(MAXSIZE * sizeof(int));
  p->front = k-1;
  p->rear = k-2;
  if (p == NULL)
  {
    exit(-1);
  }
  int count=0;
  while (count<k-1){
    p->list[count]=0;
    count++;
  }
  p->list[k-1]=1;
  return p;

}
int  getelem(seq *a,int k){
  int count=0;
  int sum=0;
  while (count<k){
  int adds=a->list[count];
  sum+=adds;
  count++;
  }
return sum;
}

void getf(seq* a, int n,int k){
  int c=k;
    while (c<n+1){
      
      int temp=getelem(a,k);
      if (a->front==k-1)a->front=0;
      else a->front++;
      if (a->rear==k-1)a->rear=0;
      else a->rear++;
      a->list[a->front]=temp;
      c++;
    }
}

int main()
{
  int k,n;
  printf("请输入k:\n");
  scanf("%d", &k);
  printf("n:\n");
  scanf("%d",&n);

  seq *a;
  a=init(k);
  getf(a,n,k);
  printf("后%d项为\n",k);
  int count=0;
  while (count<k){
   if (a->front==k-1)a->front=0;
      else a->front++;
    int print=a->list[a->front];

    printf("%d",print);
    printf("\n");
    count++;
  }
  return 0;
}

