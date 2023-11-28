#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char ch;
    struct node* next;
};
typedef struct node* Node;

int isEmpty(Node head){
    if(head == NULL)
        return 1;
    return 0;
}

Node create(){
    Node newnode = (Node)malloc(sizeof(struct node));
    newnode->next = NULL;
    return newnode;
} 

Node push(Node head, char ch){
    Node newnode = create();
    newnode->ch = ch;
    if(head == NULL){
        return newnode;
    }
    newnode->next = head;
    head = newnode;
    return head;
}

Node pop(Node* head){
    if(*head == NULL)
        return NULL;
    else{
        Node temp = *head;
        *head = (*head)->next ;
        return temp;
    }
}

void print(Node head){
    Node temp = head;
    while(temp != NULL){
        printf("%c",temp->ch);
        temp = temp->next;
    }
    return;
}

void solve(char str[], int n){
    Node head1 = NULL;
    Node head2 = NULL;
    int i = n;

    while(str[i] != '\0'){
        
    }

    return;
}


int main(){
    char s[20];
    printf("Enter the string which you want to enter\n");
    printf("denote starting and ending wall by /\n");
    scanf("%s",s);
    int cnt = 0;
    while (s[cnt])
    {
        cnt++;
    }
    
    solve(s,cnt);
    return 0;
}