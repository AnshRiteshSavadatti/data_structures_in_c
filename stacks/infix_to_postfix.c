// (a + ( b * c )) == abc*+  -- > postfix
// (a + ( b * c )) == +a*bc  -- > prefix

// a + b + (c * d) ==  ++ab*cd -- > prefix
// a + b + (c * d) ==  ab+cd*+ -- > prefix


#include<Stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15
typedef struct stack{
    char data[MAX];
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

void push(stack *s,char x){
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

char pop(stack *s){
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

int precedence(char x){
    if(x == '+' || x == '-')
    return 1;
    else if(x == '*' || x == '/')
    return 2;
    else 
    return 3;
}

int isOpreant(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
    return 1;
}

void postfix(char ptr[MAX], stack *s){
    // char postfix = new char[strlen(MAX)+1];
    char postfix[MAX+1];
    int i = 0, j = 0;
    while(ptr[i] != '\0'){
        if(isOpreant(ptr[i])){
            postfix[j++] = ptr[i++];
        }
        else{
            if(isEmpty(s) || precedence(ptr[i]) > precedence(s->data[i]))
                push(s,ptr[i++]);
            else{
                postfix[j++] = pop(s);
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j++] = pop(s);
     }
     postfix[j] = '\0';
     printf("%s\n",postfix);
     printf("hi");
}

int main(){
    stack s;
    s.top = -1;
    int ch;
    char infix[15];
    printf("Enter the expression\n");
    scanf("%s",infix);
    postfix(infix,&s);
    return 0;
}