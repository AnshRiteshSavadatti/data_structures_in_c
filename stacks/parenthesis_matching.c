// with parenthesis in order ie this --> ' ( ' first then this --> ' ) '

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char ch;
    struct node* next;
};

typedef struct node* Node;
Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stack is full\n");
        exit(0);
    }
    newnode->next = NULL;
    return newnode;
}

Node push(Node head, char ch){
    Node newnode = create();
    if(newnode == NULL){
        printf("Stack is full\n");
    }
    else{
        newnode->ch = ch;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

Node pop(Node head){
    Node temp = head;
    if(head == NULL){
        printf("Stack is empty\n");
    }
    else{
        head = head->next;
        free(temp);
    }
    return head;
}

void is_balanced(Node head, char arr[15]){
    for(int i=0; arr[i] != '\0'; i++){
        if(arr[i] == '('){
           head =  push(head, '(');
        }
        else if(arr[i] == ')'){
            if(head == NULL){
            printf("parenthesis not matched");
            return;
            }
            head = pop(head);

        }
    }
    if(head == NULL)
    printf("parenthesis matched");
    else
    printf("parenthesis not matched");
    return ;
}

int main(){
    char str[20];
    printf("Enter the parenthesis\n");
    scanf("%s",str);
    Node head = NULL;
    is_balanced(head,str);
    return 0;
}