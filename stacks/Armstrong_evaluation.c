#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack{
    int data[MAX];
    int top;
}stack;

int isEmpty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int isFull(stack *s){
    if(s->top == MAX)
        return 1;
    return 0;
}

void push(stack *s, int n){
    if(!isFull(s)){
        s->top++;
        s->data[s->top] = n;
    }
    else
        printf("Stack overflow\n");
    return;
}

int pop(stack* s){
    int n = -1;
    if(!isEmpty(s)){
        n = s->data[s->top];
        s->top--;
    }
    else
        printf("Stack under flow\n");
    return n;
}

int isArmstrong(stack *s,int n){
    int m = n;
    while(m > 0){
        int rem = m % 10;
        push(s,rem);
        m /= 10;
    }
    int num;
    int sum = 0;
    while(!isEmpty(s)){
        num = pop(s);
        sum += num*num*num;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d",&n);
    stack s;
    s.top = -1;
    if(n<=0){
        printf("Invalid\n");
        exit(0);
    }
    int number =  isArmstrong(&s,n);
    if(number == n){
        printf("yes\n");
    }
    else
        printf("no\n");
    return 0;
}
