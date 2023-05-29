#include<Stdio.h>
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
        printf("Memory not allocaated\n");
        exit(0);
    }
    printf("Enter thte data\n");
    scanf("%d",&newnode->data);
    newnode->next = newnode->previous = NULL;
    return newnode;
}

Node insert_at_end(Node head){
    Node temp, newnode;
    newnode = create();
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->previous = temp;
    }
    return head;
}

Node reverse(Node head){
    Node previousnode, nextnode, currentnode;
    previousnode = NULL;
    nextnode = currentnode = head;
    while(nextnode != NULL){
    nextnode = nextnode->next;
    currentnode->next = previousnode;
    currentnode->previous = nextnode;
    previousnode = currentnode;
    currentnode = nextnode;
    }
    head = previousnode;
    return head;
}

void display(Node head){
    Node temp = head;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
return;
}

int main(){
    Node head = NULL;
    int ch;
    while(1){
        printf("Enter\n1 to insert at end\n2 to reverse the list\n3 to display the list\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
            case 1:
            printf("hi");
            head = insert_at_end(head);
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

