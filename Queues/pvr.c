#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    struct node* next;
    int ticket_no;
    char gender;
    char name[20];
};

typedef struct node* Node;

Node create(){
    Node newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Queue underflow\n");
        return newnode;
    }
    newnode->next = NULL;
    printf("Enter the gender\n");
        fflush(stdin);
    scanf("%c",&newnode->gender);
    printf("Enter the name\n");
        fflush(stdin);
    scanf("%s",newnode->name);
    printf("enter the ticket number\n");
        fflush(stdin);
    scanf("%d",&newnode->ticket_no);
    fflush(stdin);
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode = create();
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

Node delete_from_beg(Node head){
    if(head == NULL)
        printf("Queue underflow\n");
    else{
        Node temp = head;
        head = head->next;
        printf("The ticket which is removed is %d\n",temp->ticket_no);
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
        printf("%d\t",temp->ticket_no);
        printf("%c\t",temp->gender);
        printf("%s\t\n",temp->name);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void count(Node head){
    int m = 0, f = 0;
    Node temp = head;
    while (temp != NULL)
    {
        if(temp->gender == 'm' || temp->gender == 'M')
            m++;
        if(temp->gender == 'f' || temp->gender == 'F')
            f++;
            temp = temp->next;
    }
    printf("The number of males are %d\n",m);
    printf("The number of females are %d\n",f);
    return;   
}

void tickets(Node head){
    Node temp = head;
    int c = 0;
    while(temp != NULL){
       c++;
        temp = temp->next;
    }
    printf("The number of tickets issued are %d\n",c);
    return;
}



int main(){
    Node head;
    head = NULL;
    while (1){
        int n;
        printf("Enter\n1 to enque from end\n2 to delete \n3 to display\n4 to count number of males and females\n5 to count number of tickets\n0 to exit\n");
        scanf("%d",&n);
        switch(n){
            case 1 :
                head = insert_at_end(head);
                break;
            case 2 : 
                head = delete_from_beg(head);
                break;
            case 3 :
                display(head);
                break;
            case 4 :
                count(head);
                break;
            case 5 :
                tickets(head);
                break;
            default :
                exit(0);
        }
        
    }
    return 0;
    
}
