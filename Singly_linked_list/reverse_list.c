#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node*  Node;

Node create(){
    Node newnode, temp;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated ");
        exit(0);
    }
    printf("Enter the data ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode,temp;
    newnode = create();
    if(head == NULL){
     head = newnode;
     return head;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next = newnode;
        return head;
    }

}

Node reverse_list(Node head){
    Node previousnode, currentnode, nextnode;
    previousnode = NULL;
    currentnode = nextnode = head;
    while(nextnode != NULL){
        nextnode = nextnode->next;
        currentnode->next = previousnode;
        previousnode = currentnode;
        currentnode = nextnode;
    }
    head = previousnode;
    return head;
}

void display(Node head){
    Node temp; 
    temp = head;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    Node head = NULL;
    int ch;
    while(1){
    printf("Enter 1 to insert at end\nEnter 2 to display list\n3 to reverse the list");
    printf("\nEnter 0 to exit \n");
    printf("Enter the number\n ");
    scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
            case 1:
            head = insert_at_end(head);
            break;
            case 2:
            display(head);
            break;
            case 3:
            head = reverse_list(head);
            break;
            default: 
            printf("Invalid Input ");
            exit(0);
            break;
        }
    }

}