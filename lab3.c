#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30
typedef int Status;
typedef struct stack
{
  char *list;
  int stacknode;
} stack;
stack *create()
{
  stack *p;
  p = (stack *)malloc(sizeof(stack *));
  p->list = (char *)malloc(MAXSIZE * sizeof(char *));
  p->stacknode = -1;
  if (p == NULL)
  {
    exit(-1);
  }
  return p;
}
void instack(stack *s, char m)
{
  s->stacknode++;
  s->list[s->stacknode] = m;
  {
    if (isfull(*s) == 1)
    {
      printf("the stack is full!");
      exit(-1);
    }
  }
}
Status isfull(stack s)
{
  if (s.stacknode == (MAXSIZE - 1))
  {
    return 1;
  }
  else
    return 0;
}
Status isempty(stack s)
{
  if (s.stacknode == -1)
  {
    return 1;
  }
  else
    return 0;
}
char popstack(stack *s)
{
  if (isempty(*s) == 1)
  {
    printf("the stack is empty!");
    exit(-1);
  }
  char m;
  m = s->list[s->stacknode--];
  return m;
}
char gettop(stack *s)
{
  if (isempty(*s) == 1)
  {
    printf("the stack is empty!");
    exit(-1);
  }
  char m;
  m = s->list[s->stacknode];
  return m;
}
int cont_str(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }

  return i;
}

void middlelast(char *agrv, char *output)
{
  stack *s1;
  s1 = create();
  int poutput = 0;
  int len = cont_str(agrv);
  int j = 0;
  for (j = 0; j < len; j++)
  {
    char elem = agrv[j];
    if (elem == '[')
    {
      elem = '(';
    }
    if (elem == ']')
    {
      elem = ')';
    }
    if (elem >= '0' && elem <= '9')
    {
      output[poutput++] = elem;
    }
    else if (elem == '*' || elem == '/')
    {
      instack(s1, elem);
    }

    else if (elem == '(')
    {
      char temp;
      int count = 0;
      if (isempty(*s1) == 0)
      {
        temp = popstack(s1);
        count = 1;
      }
      while (s1->list[s1->stacknode] != '(' && isempty(*s1) == 0)
      {
        output[poutput++] = popstack(s1);
      }

      if (count == 1)
      {
        instack(s1, temp);
      }
      instack(s1, elem);
    }
    else if (elem == ')')
    {
      while (s1->list[s1->stacknode] != '(')
      {
        output[poutput++] = popstack(s1);
      }
      popstack(s1);
    }
    else if (elem == '+' || elem == '-')
    {
      if (isempty(*s1) || gettop(s1) != '*' || gettop(s1) != '/')
      {
        instack(s1, elem);
      }
      else
      {
        while (s1->list[s1->stacknode] != '(')
        {
          output[poutput++] = popstack(s1);
        }
        instack(s1, elem);
      }
    }
    else {printf("the sentense is wrong\n");
    exit(-1);}
  }
  int vou = s1->stacknode;
  for (vou = s1->stacknode; vou >= 0; vou--)
  {
    output[poutput++] = popstack(s1);
  }
}

int getvalue(char *agrv)
{
  stack *s1;
  s1 = create();
  int poutput = 0;
  int len = cont_str(agrv);
  int j = 0;
  int k = 0;
  for (j = 0; j < len; j++)
  {
    char elem = agrv[j];
    if (elem >= '0' && elem <= '9')
    {
      instack(s1, elem - '0');
    }
    else
    {
      int m, n;
      n = (popstack(s1));
      m = (popstack(s1));
      if (elem == '+')
        instack(s1, m + n);
      else if (elem == '-')
        instack(s1, m - n);
      else if (elem == '*')
        instack(s1, m * n);
      else { if (n==0){
          printf("error divided by zero");
      }
        instack(s1, m / n);}
    }
  }
  int result;
  result = popstack(s1);
  return result;
};

int main()
{
  char a[50] = "0";
  char b[50] = "0";
  printf("请输入一个表达式\n");
  char agrv[50];
  scanf("%s", agrv);
  middlelast(agrv, a);
  printf("后缀表达式为：\n");
  printf("%s", a);
  printf("\n");
  printf("表达式结果为\n");
  int retu = getvalue(a);
  printf("%d", retu);
  return 0;
}

