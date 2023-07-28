#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
typedef struct node * Node;

Node create(){
    Node newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next = newnode;
    return newnode;
}

Node insert_beg(Node head){
    Node newnode = create();
    if(head == NULL)
        return newnode;
    else{
        Node temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return head;
}

Node reverse(Node head){
    Node prv = head, nextnode = head, current = head;
    while(prv->next != head)
        prv = prv->next;
    while(nextnode->next != head){
        nextnode = nextnode->next;
        current->next = prv;
        prv = current;
        current = nextnode;
    }
        nextnode = nextnode->next;
        current->next = prv;
        prv = current;
        current = nextnode;
    head = prv;
    return head;
}

void display(Node head){
    Node temp = head;
    while(temp->next != head){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d\t",temp->data);
    return;
}

int main(){
    Node head = NULL;
    int ch;
    while(1){
        printf("enter\n1 to insert at end\n 2 to reverse\n 3 to display\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = insert_beg(head);
            break;
        case 2:
            head = reverse(head);
            break;
        case 3:
            display(head);
            break;
        default:
        exit(0);
            break;
        }
    }
}