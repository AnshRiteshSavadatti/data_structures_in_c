#include<stdio.h>
#include<stdlib.h>

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
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->previous = NULL;
    return newnode;
}

Node insert_at_end(Node head){
    Node temp = head;
    Node newnode = create();
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
        newnode->previous = temp;
        return head;
    }
}

Node insert_at_beg(Node head){
    Node temp = head;
    Node newnode = create();
    newnode->next = head;
    head->previous = newnode;
    head = newnode;
    return head;
}

int lenght(Node head){
    Node temp = head;
    int count  = 1;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node insert_at_pos(Node head){
Node prev = head,current;
Node newnode = create();
int count;
count = lenght(head);
int position;
printf("Enter the position\n");
scanf("%d",&position);
if(position <= 0 || position > count){
    printf("Invalid position");
    return head;
}
if(position == 1){
    head = insert_at_beg(head);
    return head;
}
if(position == count){
    head = insert_at_end(head);
    return head;
}
else{
    int i = 1;
    while(i < position - 1){
        prev = prev->next;
    }
    current = prev->next;
    prev->next = newnode;
    newnode->previous = prev;
    newnode->next = current;
    current->previous = newnode;
    return head;
}
}

Node delete_from_beg(Node head){
    Node temp = head;
    head = head->next;
    head->previous = NULL;
    free(temp);
    return head;
}

Node delete_from_end(Node head){
    Node temp = head;
    Node temp2;
    // here temp will be at last node and temp2 at last second node
    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
    return head;
}

Node delete_at_pos(Node head){
int count;
count = lenght(head);
int position;
printf("\nThe count is %d\n",count);
printf("Enter the position\n");
scanf("%d",&position);
if(position <= 0 || position > count){
    printf("Invalid position\n");
    return head;
}
if(position == 1){
    head = delete_from_beg(head);
    return head;
}
if(position == count-1){
    head = delete_from_end(head);
    return head;
}
else{
Node temp, previousnode = head, nextnode;
int i=1; 
while(i < position - 1){
    previousnode = previousnode->next;
}
temp = previousnode->next;
nextnode = temp->next;
previousnode->next = nextnode;
nextnode->previous = previousnode;
free(temp);
return head;
}
}

Node search_delete(Node head){
    Node temp = head;
    int key;
    printf("Enter the key which is to be deleated\n");
    scanf("%d",&key);
    printf("hi\n");
    Node temp2;
    while(temp->next != NULL){
        Node temp3 = temp;
        if(key == temp->data){
            if(head == temp){
                head = delete_from_beg(head);
            }
            else if(temp->next == NULL){
                head = delete_from_end(head);
            }
            else{
                printf("hi2\n");
                temp2->next = temp->next;
                free(temp);
                printf("hi3\n");
            }

        }
        temp = temp3;
        temp2 = temp;
        temp = temp->next;
    }
    return head;
}

void display(Node head){
    Node temp = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void display_reverese(Node head){
    Node temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->previous;
    }
}

int main(void){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at positon\n3 to insert at first\n4 to display\n5 to display the list in reverse order\n");
        printf("6 to delete from begning\n7 to delete from end\n8 to delete from any position\n9 to search and delete\n");
        printf("0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
            case 1:
            head = insert_at_end(head);
            break;
            case 2:
            head = insert_at_pos(head);
            break;
            case 3:
            head = insert_at_beg(head);
            break;
            case 4:
            display(head);
            break;
            case 5:
            display_reverese(head);
            break;
            case 6:
            head = delete_from_beg(head);
            break;
            case 7:
            head = delete_from_end(head);
            break;
            case 8:
            head = delete_at_pos(head);
            break;
            case 9:
            head = search_delete(head);
            break;
            default:
            exit(0);
            break;

        }
    }
}