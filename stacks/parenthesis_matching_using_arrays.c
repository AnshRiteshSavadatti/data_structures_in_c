#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
    char exp[MAX];
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

void push(Stack *p ,char num)
{
    if(isFull(p))
    {
        printf("Stack overflow\n");
        return;
    }
    p->top++;
    p->exp[p->top]=num;
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
{
    int temp;
    if(isEmpty(p))
    {
        printf("stack underflow\n");
        return -1;
    }
    temp=p->exp[p->top];
    p->top--;
    return temp;
}

int isBalance(Stack *p)
{   
    char exp[100];
    printf("Enter the string\n");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(p,'(');
        }
        else if(exp[i]==')')
        {
            if(isEmpty(p))
            {
                printf("parenthesis not matched1\n");
                return 0;
            }
                pop(p);
        }

    }

    if(!isEmpty(p))
    printf("parenthesis not matched\n");
    else
    printf("parenthesis matched\n");
}


int main()
{
    Stack S;
    S.top=-1;
    int ch,num;
     isBalance(&S);
    return 0;
}