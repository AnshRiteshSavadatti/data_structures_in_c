#include<stdio.h>
#include<Stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* previous;
};

typedef struct node* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next = newnode;
    newnode->previous = newnode;
    return newnode;
}

Node insert_at_end(Node head){
    Node temp = head, previousnode;
    Node newnode = create();
    if(head == NULL){
        head = newnode;
    }
    else{
    temp = head->previous;
    newnode->previous = temp;
    newnode->next = head;
    temp->next = newnode;
    head->previous = newnode;
    }
    return head;
}
Node insert_at_beg(Node head){
    Node temp = head;
    Node newnode = create();
    newnode->next = head;
    temp = head->previous;
    temp->next = newnode;
    head->previous = newnode;
    newnode->previous = temp;
    head = newnode;
    return head;
}

Node delate_from_beg(Node head){
    Node temp1, temp2;
    temp1 = head->previous;
    temp2 = head;
}

void display(Node head){
    Node temp = head;
    while(temp->next != head){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at begning\n4 to display");
        printf("\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
            case 1:
            head = insert_at_end(head);
            break;
            case 2:
            head = insert_at_beg(head);
            break;
            case 4:
            display(head);
            break;
            default :
            exit(0);
            break;
        }
    }
}