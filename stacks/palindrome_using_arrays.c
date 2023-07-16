#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

struct stack
{
    char a[MAX];
    int top;
};

typedef struct stack Stack;

int isFull(Stack *p)
{
    if(p->top==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(Stack *p,char c)
{
    if(isFull(p))
    {
        printf("Stack is full\n");
        return;
    }
    p->top++;
    p->a[p->top]=c;
}

int isEmpty(Stack *p)
{
    if(p->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

char pop(Stack *p)
{  char t = '\0';
    if(isEmpty(p))
    {
        printf("Stack is empty\n");
        return t;
    }
   t= p->a[p->top];
   p->top--;
   return t;

}

void palindrome(Stack *p)
{   
    int mid,i;
    char e;
    char exp[20];
    printf("Enter the expression\n");
    scanf("%s",exp);
    int lenght=strlen(exp);
     mid=lenght/2;
     for( i=0;i<mid;i++)
     {
         push(p,exp[i]);
     }
      if(lenght % 2 != 0)
         {
             i++;
         }
     while(exp[i]!='\0')
     {
          e=pop(p);
         if(e != exp[i])
         {
             printf("It is not a palindrome ");
             return;
         }
         i++;
     }
         printf("Its a palindrome\n");
}
int main()
{
    Stack S;
    S.top=-1;
    palindrome(&S);
    return 0;
}