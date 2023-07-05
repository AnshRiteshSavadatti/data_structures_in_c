#include<Stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int size;
    int id;
    char file_name[20];
    struct node* next;
    struct node* prev;
};

typedef struct node* Node;

Node create(){
    Node newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the size\n");
    scanf("%d",&newnode->size);
    printf("Enter the id\n");
    scanf("%d",&newnode->id);
    printf("Enter the file name\n");
    scanf("%s",newnode->file_name);
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode = create();
    if(head == NULL){
        return newnode;
    }
    Node temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;
    return head;
}

Node moveToNextImage(Node head, Node pos){
    if(pos == NULL){
        pos = head;
    }
    pos = pos->next;
    printf("%d\n%d\n%s\n",pos->size,pos->id,pos->file_name);
    return pos;
}

Node moveToPreviousImage(Node head, Node pos){
    if(pos == NULL){
        pos = head;
    }
    pos = pos->prev;
    printf("%d\n%d\n%s\n",pos->size,pos->id,pos->file_name);
    return pos;
}

Node position(Node head){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    Node temp = head;
    int i = 1;
    while(i < pos){
        temp = temp->next;
        i++;
    }
    return temp;
}

void displayCurrentImage(Node head, Node pos){
    printf("%d\n%d\n%s\n",pos->size,pos->id,pos->file_name);
    return;
}

Node delete_max(Node head){
    int max = 0;
    Node temp = head;
    Node p;
    while(temp->next != head){
        if(temp->size > max){
            p = temp;
        }
        temp = temp->next;
    }
    if(temp->size > max){
            p = temp;
        }
    if(p == head){
        Node temp1 = head;
        while (temp1 ->next != head){
            temp1 = temp1->next;
        }
        temp1->next = head->next;
        head = head->next;
        free(p);
    }
    else if(p->next == head){
        p->prev->next = head;
        head->prev = p->prev;
        free(p);
    }
    else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    return head;
}

void display1(Node head){
    Node temp = head;
    while(temp->next != head){
        printf("%d\n%d\n%s\n",temp->size,temp->id,temp->file_name);
        temp = temp->next;
    }
    printf("%d\n%d\n%s\n",temp->size,temp->id,temp->file_name);
    return;
}

int main(){
    int ch;
    Node head = NULL, pos = NULL;
    while(1){
        printf("\nEnter\n 1 to insert at end\n2 to move to next image\n3 to move to previous image\n4 display current image\n5 to delete maximum size\n");
        printf("6 Display list\n0 to exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
           exit(0);
            break;
        case 1:
           head = insert_at_end(head);
            break;
        case 2:
           if(pos == NULL){
            pos = position(head);
           }
            pos = moveToNextImage(head,pos);
            break;
        case 3:
           if(pos == NULL){
            pos = position(head);
           }
            pos = moveToPreviousImage(head,pos);
            break;
        case 4:
            displayCurrentImage(head,pos);
            break;
        case 5:
            head = delete_max(head);
            break;
        case 6:
            display1(head);
            break;
        default:
            printf("Invalid Input");
            exit(0);
            break;
        }
    }
}

