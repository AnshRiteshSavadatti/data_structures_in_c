
#include<Stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 15

typedef struct stack{
    int data[MAX];
    int top;
}stack;

int isEmpty(stack *s){
    if(s->top == - 1)
    return 1;
    return 0;
}

int isFull(stack *s){
    if(s->top == MAX-1)
    return 1;
    return 0;
}

void push(stack *s,int x){
    // int x;
    if(!isFull(s)){
    // printf("Enter the data which is to be inserted\n");
    // scanf("%d",&x);
    s->top++;
    s->data[s->top] = x;
    }
    else{
        printf("stack overflow\n");
    }
}

int pop(stack *s){
    char x;
    if(!isEmpty(s)){
        x = s->data[s->top];
        s->top--;
        return x;
    }
    else{
        printf("Stack underflow\n");
        return '\0';
    }
}

void display(stack s){
    if(!isEmpty(&s)){
        for(int i = s.top; i>=0; i--){
            printf("%d\n",s.data[i]);
        }
    }
}


int isOpreant(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
    return 1;
}

int result(int m, int n, char ch){
    switch(ch){
        case '+':
            return m+n;
        case '-':
            return m-n;
        case '*':
            return m*n;
        case '/':
            return m/n;
    }
}

void calculate(stack * s, char ptr[MAX]){
    int r;
    for(int i=0;  i<strlen(ptr); i++){    //  || i<strlen(ptr);  --> as condition
        if(isdigit(ptr[i]))
        push(s,ptr[i]-'0');
        else{
            int m = pop(s);
            int n = pop(s);
            r = result(m,n,ptr[i]);
            push(s,r);
        }
    }
    printf("%d : is the answer\n",s->data[s->top]);
}


int main(){
    stack s;
    s.top = -1;
    int ch;
    char infix[15];
    while(1){
        int exp;
        printf("Enter\n1 to calculate\n2 to exit\n");
        scanf("%d",&exp);
        switch (exp)
        {
        case 1:
            printf("Enter the expression\n");
            scanf("%s",infix);  
            calculate(&s ,infix);          
            break;
        default:
            exit(0);
            break;
        }
        
    }
    return 0;
}