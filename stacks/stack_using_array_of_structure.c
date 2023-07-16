#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

 struct node{
    float price;
    char str[20];
};

typedef struct stack{
    struct node s[MAX];
    int top;
}stack;

int isEmpty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int isFull(stack *s){
    if(s->top == MAX-1)
    return 1;
    return 0;
}

void push(stack *s,float x,char arr[20]){
    
    if(!isFull(s)){
    s->top++;
    s->s[s->top].price = x;
    strcmp(arr,s->s[s->top].str);
    }
    else{
        printf("stack overflow\n");
    }
}

void cost(stack *s){
    int c = 0;
    for(int i=0; i<MAX; i++){
        c += s->s[i].price;
    }
    printf("%d is the total cost\n");
}

void print(stack *s){
    for(int i = s->top; i>0; i--){
        printf("%d\t%s",s->s[i].price,s->s[i].str);
    }
}

void cnt(stack *s, int arr[20]){
    int count = 0;
    for(int i = 0; i<=s->top; i++){
        if(!strcmp(arr,s->s[i].str))
            count++;
    }
    printf("%s book she won is %d\n",arr,count);
}

int main(){
    stack s;
    s.top = -1;
    int n;
    printf("Enter the number of books\n");
    scanf("%d",&n);
    while(n--){
        float x;
        printf("Enter the price\n");
        scanf("%f",&x);
        char arr[20];
        printf("Enter the book name\n");
        scanf("%s",&arr);
        push(&s,x,arr);
    }
    print(&s);
    char brr[20];
    printf("Enter the book which is to be searched\n");
    scanf("%s",brr);
    cnt(&s,brr);
    return 0;
}

