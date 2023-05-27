#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated");
        exit(0);
    }
        printf("Enter the value of data \n");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        return newnode;
}

Node insert_at_end(Node head){
    Node newnode, temp;
    newnode = create();
    if(head == NULL){
        head = newnode;
        return head;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
}

void display_list(Node head){
    Node temp = head;
    if(head == NULL){
        printf("\nList is Empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}
Node link_list(Node head, Node head2){
    Node temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head;
}

int main(){
    int ch;
    Node head = NULL;
    Node head2 = NULL;
    while(1){
        printf("Enter\n1 to insert in list 1\n2 to insert in list 2\n3 to display list 1\n4 to display list 2\n5 to link the two lists\n");
        printf("Enter 0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            head = insert_at_end(head);
            break;
            case 2:
            head2 = insert_at_end(head2);
            break;
            case 3:
            display_list(head);
            break;
            case 4:
            display_list(head2);
            break;
            case 5:
            head = link_list(head, head2);
            break;
            case 0:
            exit(0);
            break;
            default:
            exit(0);
            break;
        }
    }
}