#include<Stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int age;
    int songs;
    char name[15];
    struct node* next;
};

typedef struct node* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the age");
    scanf("%d",&newnode->age);
    printf("Enter the number of songs ");
    scanf("%d",&newnode->songs);
    printf("Enter the name");
    scanf("%s",newnode->name);
    newnode->next = newnode;
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode = create();
    
    if(head == NULL){
        head = newnode;
    }
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

Node create_different_list(Node head, Node head2){
    char namee[15];
    printf("Enter the name which is to be inserted\n");
    scanf("%s",namee);
    Node temp = head;
    while (temp->next != head){
    int k = strcmp(namee, temp->name);
    if(k == 0){
        Node newnode = create();
        if(head2 == NULL){
            head2 = newnode;
            newnode->age = temp->age;
            strcpy(newnode->name, temp->name);
            newnode->songs = temp->songs;
        }
        else{
            Node temp = head2;
            while(temp->next != head){
                temp = temp->next;
                newnode->age = temp->age;
                strcpy(newnode->name, temp->name);
                newnode->songs = temp->songs;
            }
             
            temp->next = newnode;
            newnode->next = head2;
        }
    }
    }
    return head2;
}

void display(Node head){
    Node temp = head;
    while (temp->next != head){
        printf("%d\n",temp->age);
        printf("%d\n",temp->songs);
        printf("%s\n\n",temp->name);
    }
        printf("%d\n",temp->age);
        printf("%d\n",temp->songs);
        printf("%s\n\n",temp->name);
    return;
}

void display2(Node head2){
    Node temp = head2;
    while (temp->next != head2){
        printf("%d\n",temp->age);
        printf("%d\n",temp->songs);
        printf("%s\n\n",temp->name);
    }
        printf("%d\n",temp->age);
        printf("%d\n",temp->songs);
        printf("%s\n\n",temp->name);
    return;
}

int main(){
    Node head = NULL;
    Node head2 = NULL;
    int ch;
    while(1){
        printf("Enter \n1 to insert at end\n2 to create different list\n3 to display first list\n4 to display created list\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = insert_at_end(head);
            break;
        case 2:
            head2 = create_different_list(head, head2);
            break;
        case 3:
            display(head);
            break;
        case 4:
            display(head2);
            break;
        default:
            exit(0);
            break;
        }

    }
}