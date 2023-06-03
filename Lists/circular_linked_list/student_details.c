#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  node{
    char name[20];
    int roll;
    struct node* next;
};

typedef struct node* Node;

Node create(){
    Node newnode, temp;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the roll no\n");
    scanf("%d",&newnode->roll);
    printf("Enter the name");
    scanf("%s",newnode->name);
    newnode->next = newnode;
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode, temp;
    newnode = create();
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return head;
}

void display(Node head){
    Node temp = head;
    while(temp->next != head){
        printf("%s\n",temp->name);
        printf("%d\n",temp->roll);
        temp = temp->next;
    }
        printf("%s\n",temp->name);
        printf("%d\n",temp->roll);    
    
    return;
}

Node insert_at_beg(Node head){
    Node temp = head, newnode;
    newnode = create();
    newnode->next = head;
    head = newnode;
    while(temp->next != newnode->next){
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

int lenght(Node head){
    int count = 1;
    Node temp = head;
   while(temp->next != head){
    temp = temp->next;
    count++;
   }
   return count;
}

Node insert_at_pos(Node head){
    Node currentnode, previousnode, newnode;
    int position;
    printf("Enter the position\n");
    scanf("%d",&position);
    newnode = create();
    int count = lenght(head);
    if(position == 1){
        head = insert_at_beg(head);
    }
    if(position == count){
        head = insert_at_end(head);
    }
    if(position > count || position < 1){
        printf("Invalid Input\n");
    }
    else{
        previousnode = head;
        int i = 1;
        while(i < position-1){
            previousnode = previousnode->next;
        }
        currentnode = previousnode->next;
        newnode->next = currentnode;
        previousnode->next = newnode;
    }
    return head;
}

 void search_roll(Node head){
    int n;
    printf("\nEnter the roll no\n");
    scanf("%d",&n);
    Node temp = head;
    while(temp->next != head){
        if(temp->roll == n){
            printf("%s\n",temp->name);
        }
        temp = temp->next;
    }
  return;
}

void search_name(Node head){
    char name[20];
    Node temp = head;
    printf("Enter the name which is to be searched\n");
    scanf("%s",name);
    while(temp->next != head){
        int k = strcmp(name, temp->name);
        if(k == 0){
        printf("%s\n",temp->name);
        printf("%d\n",temp->roll);    
        }
    }
}


int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at begning\n3 to insert at position\n4 to search roll no\n5 to search name\n7 to display\n");
        printf("0 to exit\n");
        scanf("%d",&ch);
        switch (ch){
        case 1:
            head = insert_at_end(head);
            break;
        case 2:
            head = insert_at_beg(head);
            break;
        case 3:
            head = insert_at_pos(head);
            break;
        case 4:
            search_roll(head);
            break;
        case 5:
            search_name(head);
            break;
        case 7:
            display(head);
            break;
        default:
            exit(0);
            break;
        }
    }
}