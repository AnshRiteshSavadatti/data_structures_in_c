//  REVIEW QUESTIONS
// RQ 1
#include<stdio.h>
#include<stdlib.h>

struct student_details{
    char name[15];
    char usn[12];
    float dob;
    int sem;
    char div;
    float sgpa;
    struct student_details* next;
};

typedef struct student_details* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct student_details));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter the usn\n");
    scanf("%s",newnode->usn);
    printf("Enter the date of birth\n");
    scanf("%f",&newnode->dob);
    printf("Enter the sem\n");
    scanf("%d",&newnode->sem);
    fflush(stdin);
    printf("Enter the division\n");
    scanf("%c",&newnode->div);
    printf("Enter the sgpa\n");
    scanf("%f",&newnode->sgpa);
    newnode->next = NULL;
    return newnode;
}

Node insert_end(Node head){
    Node temp, newnode;
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

Node insert_beg(Node head){
    Node newnode;
    newnode = create();
    if(head == NULL){
        head = newnode;
        return head;
    }
    else{
        newnode->next = head;
        head = newnode;
        return head;
    }
}

Node delete_end(Node head){
    Node currentnode, previousnode;
    currentnode = head;
    while(currentnode->next != NULL){
        previousnode = currentnode;
        currentnode = currentnode->next;
    }
    previousnode->next = NULL;
    free(currentnode);
    return head;
}

Node delete_at_beg(Node head){
    Node temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

int count(Node head){
    int count = 1;
    Node temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node delete_at_pos(Node head){
    int position;
    int coount = count(head);
    printf("Enter the position");
    scanf("%d",&position);
    if(position <= 0 || position >= count + 1){
        printf("\nInvalid postion\n");
        exit(0);
    }
    if(position == 1){
        delete_at_beg(head);
        return head;
    }
    if(position == coount){
        delete_end(head);
        return head;
    }
    Node previous, current;
    current = head;
    int i = 1;
    while(i < position -1){
        previous = previous->next;
        i++;
    } 
    current = previous->next;
    current->next = previous->next;
    free(current);
}


void display(Node head){
    Node temp;
    if(head == NULL){
        printf("\nlist is empty\n");
    }
    temp = head;
    while(temp != NULL){
    printf("%s\n",temp->name);
    printf("%s\n",temp->usn);
    printf("%f\n",temp->dob);
    printf("%d\n",temp->sem);
    printf("%c\n",temp->div);
    printf("%f\n",temp->sgpa);  
    printf("\n");
    temp = temp->next;
    }
}

int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to display list\n3 to insert at beg\n4 to delete at position\n6 to delete at beg");
        printf("\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            head = insert_end(head);
            break;
            case 2:
            display(head);
            break;
            case 3:
            head = insert_beg(head);
            break;
            case 4:
            head = delete_at_pos(head);
            break;
            case 5:
            head = delete_at_beg(head);
            case 0:
            exit(0);
            break;
        }
    }
    return 0;
}