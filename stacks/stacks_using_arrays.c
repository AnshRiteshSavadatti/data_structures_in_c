#include<Stdio.h>
#include<Stdlib.h>
# define MAX 5
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
    if(s->top == MAX - 1)
    return 1;
    return 0;
}

void push(stack *s){
    if(!isFull(s)){
        int n;
        printf("Enter the data\n");
        scanf("%d",&n);
        s->top++;
        s->data[s->top] = n;
    }
    else
    printf("stack over flow\n");
    return;
}

int pop(stack *s){
    int x;
    if(!isEmpty(s)){
    x = s->data[s->top];
    s->top--;
    }
    else 
    printf("stack under flow\n");
    return x;
}

void display(stack s){
    if(!isEmpty(&s)){
        for(int i = s.top; i >= 0; i--){
            printf("%d\n",s.data[i]);
        }
    }
    else
    printf("Stack is empty\n");
    return;
}

int main(){
    stack s;
    s.top  = -1;
    int ch;
    int x;
    while(1){
    printf("Enter\n1 to push\n2 to pop\n3 to display\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        push(&s);
        break;
    case 2:
        pop(&s);
        printf("The data which is removed is %d\n",x);
        break;
    case 3:
        display(s);
        break;
    default:
        exit(0);
        break;
    }
    }
}
