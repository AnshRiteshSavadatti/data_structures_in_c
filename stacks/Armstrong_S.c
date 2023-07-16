#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
struct stack
{
    int a[MAX];
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


void push(Stack *p ,int num)
{
    if(isFull(&p))
    {
        printf("Stack overflow\n");
        return;
    }
    p->top++;
    p->a[p->top]=num;
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


int pop(Stack *p)
{   int x;
    if(isEmpty(&p))
    {
        printf("stack underflow\n");
        return -1;
    }
    x=p->a[p->top];
    p->top--;
    return x;
}
int armstrong(Stack *p,int n)
{   int sum=0;
int t;
    while(n>0)
    {
        int rem=n%10;
        push(p,rem);
        n=n/10;
    }
    while(p->top!=-1)
    {
        t=pop(p);
        sum=sum+(t*t*t);
    }
    return sum;
}
int main()
{   Stack S;
int sum;
   S.top=-1;
    int n;
    printf("Enter the no. that has to checked\n");
    scanf("%d",&n);
    sum=armstrong(&S,n);
    if(n==sum)
    {
        printf("It is an armstrong number\n");
    }
    else{
        printf("It is not an armstrong number\n");
    }
}