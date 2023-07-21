#include<stdio.h>
#include<Stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node * Node;

Node create(int n){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Queue over flow\n");
        exit(0);
    }
    newnode->next = NULL;
    newnode->data = n;
    return newnode;
}

Node insert_at_end(Node head,int n){
    Node newnode = create(n);
    if(head == NULL){
        return newnode;
    }
    else{
        Node temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        return head;
    }
}

Node insert_at_beg(Node head,int n){
    Node newnode = create(n);
    if(head == NULL){
        return newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
        return head;
    }
}

Node delete_from_beg(Node head){
    if(head == NULL)
        printf("Queue underflow\n");
    else{
        Node temp = head;
        head = head->next;
        printf("The data which is removed is %d\n",temp->data);
        free(temp);
        return head;
    }
}

Node delete_from_end(Node head){
    if(head == NULL)
        printf("Queue underflow\n");
    else{
        Node temp = head;
        Node temp2;
        while (temp->next != NULL){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        printf("The data which is removed is %d\n",temp->data);
        free(temp);
        return head;
    }
}

void display(Node head){
    if(head == NULL){
        printf("Queue is empty\n");
        return;
    }
    Node temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    Node head;
    head = NULL;
    while (1){
        int n;
        printf("Enter\n1 to enque from end\n2 to enque from beg\n3 to delete from beg\n4 to delete from end\n5 to display\n0 to exit\n");
        scanf("%d",&n);
        int x;
        switch(n){
            case 1 :
                printf("Enter the data which is to be enqued\n");
                scanf("%d",&x);
                head = insert_at_end(head,x);
                break;
            case 2 : 
                printf("Enter the data which is to be enqued\n");
                scanf("%d",&x);
                head = insert_at_beg(head,x);
                break;
            case 3 :
                head = delete_from_beg(head);
                break;
            case 4 :
                head = delete_from_end(head);
                break;
            case 5 :
                display(head);
                break;
            default :
                exit(0);
        }
        
    }
    return 0;
    
}