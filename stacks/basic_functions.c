#include<Stdio.h>
#include<Stdlib.h>

struct stack{
    int top;
    int *s;
    int size;
};

void create(struct stack *st){
    printf("Enter the size of stack\n");
    scanf("%d",&st->size);
    st->top = -1;
    st->s = (int*)malloc(st->size * sizeof(struct stack));
}

void display(struct stack st){
    for(int i=st.top; i>=0; i--){
        printf("%d\n",st.s[i]);
    }
}

void push(struct stack* st, int n){
    if(st->top == st->size-1){
        printf("stack overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = n;
    }
}

int pop(struct stack *st){
    int n = -1;
    if(st->top == -1){
        printf("stack underflow\n");
    }
    else{
        n = st->s[st->top];
        st->top--;
    }
    return n;
}

int peek(struct stack st, int index){
    int x = -1;
    if(st.top - index +1 < 0){
        printf("Invalid Index\n");
    }
    else{
        x = st.s[st.top - index + 1];
    }
    return x;
}

int isEmpty(struct stack st){
    int x;
    if(st.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack st){
    if(st.top == st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stackTop(struct stack st){
    if(!isEmpty(st)){
        return st.s[st.top];
    }
    else{
        return -1;
    }
}

int main(){
    struct stack st;
    create(&st);
push(&st,10);
 push(&st,20);
 push(&st,30);
 push(&st,40);
 
 printf("%d\n\n",peek(st,2));
 display(st);
}
