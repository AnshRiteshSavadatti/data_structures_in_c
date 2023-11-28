#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

struct node{
    char name[20];
    int runs;
    int numbers;
};

struct stack{
    int top;
    struct node n[MAX];
};

typedef struct stack Stack;

int isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int isFull(Stack *s){
    if(s->top == MAX -1)
        return 1;
    return 0;
}

void push(Stack *s){
    if(!isFull(s)){
        s->top++;
        printf("Enter the name\n");
        scanf("%s",s->n[s->top].name);
        printf("Enter the runs\n");
        scanf("%d",&s->n[s->top].runs);
        printf("Enter the jearsey number\n");
        scanf("%d",&s->n[s->top].numbers);
    }
    else
        printf("Stack overflow\n");
    return;
}

int pop(Stack *s){
    int x = -1;
    if(!isEmpty(s)){
        x = s->n[s->top].numbers;
        s->top--;
    }
    else
        printf("Stack underflow\n");
    return x;
}

struct node peek(Stack* s){
    if(!isEmpty(s))
        return s->n[s->top];
}

void check(Stack *s){
    char str[20];
    printf("Enter the name\n");
    scanf("%s",str);
    while(!isEmpty(s)){
        struct node a = peek(s);
        if(!strcmp(str,a.name)){
            pop(s);
        }
        else{
            printf("%s\t",a.name);
            pop(s);
        }
    }
    return;
}

int main(){
    Stack s;
    s.top = -1;
    int n;
    printf("Entere the number of players\n");
    scanf("%d",&n);
    while(n--){
        push(&s);
    }
    check(&s);
    return 0;
}
