#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char ch;
    struct node* next;
};

typedef struct node* Node;

Node create(){
    Node newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stack is full\n");
        exit(0);
    }
    newnode->next = NULL;
    return newnode;
}

Node push(Node top, char ch){
    Node newnode = create();
    newnode->ch = ch;
    if(top == NULL){
        return newnode;
    }
    newnode->next = top;
    top = newnode;
    return top;
}

Node pop(Node top){
    Node temp = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        top = top->next;
        free(temp);
    }
    return top;
}

void isbalanced(Node top, char str[20]){
    for(int i=0 ; str[i] !='\0'; i++){
    if(str[i] == '('){
        top = push(top,'(');
    }
    else if( str[i] == '{' ){
        top = push(top,'{');
    }
    else if( str[i] == '['){
        top = push(top,'[');
    }
    else{
        if(top == NULL && (str[i] == ')'|| str[i] == '}' || str[i] == ']')){
             printf("parenthesis not matched\n");
            return;
            }
        else if(str[i] == ')' && top->ch == '('){
            top = pop(top);
        }
        else if(str[i] == '}' && top->ch == '{'){
            top = pop(top);
        }
        else if(str[i] == ']' && top->ch == '['){
            top = pop(top);
        }
    }
    }

    if(top == NULL)
    printf("parenthesis matched\n");
    else
    printf("parenthesis not matched\n");
}

int main(void){
    Node top = NULL;
    char str[20];
    printf("Enter the string\n");
    scanf("%s",str);
    isbalanced(top, str);
    return 0;
}
