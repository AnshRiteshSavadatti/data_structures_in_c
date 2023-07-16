#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10
typedef struct stack {
    char data[MAX];
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

void push(stack *s,char data){
    if(!isFull(s)){
        s->top++;
        s->data[s->top] = data;
    }
    else
       printf("Stack overflow\n"); 
    return;
}
       
char pop(stack *s){
   char n;
    if(!isEmpty(s)){
       n =  s->top[s->data];
        s->top--;
    }
    else{
        printf("stack underflow\n");
        return '\0';
    }
    return n;
}

int ispalindrome(stack *s, char n[20]){
    
    int l = strlen(n);
    int i;
    for(i=0; i<l/2; i++){
        push(s,n[i]);
    }
    if(l % 2 != 0)
        i++;
    while(n[i] != '\0'){
        if(pop(s) != n[i])
           return 0;
        i++;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        exit(0);
    }
    stack s;
    s.top = -1;
    char ch[20];
    sprintf(ch,"%d",n);
    int r = ispalindrome(&s,ch);
    if(r == 1){
        printf("%d is a palindrome number",n);
    }
    else
        printf("%d is not a palindrome number",n);
    return 0;
}
