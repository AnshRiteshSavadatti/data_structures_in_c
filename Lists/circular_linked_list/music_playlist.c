#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[20];
    int no_songs;
    char language[20];
    int year;
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
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter the number of songs \n");
    scanf("%d",&newnode->no_songs);
    printf("Enter the language\n");
    scanf("%s",newnode->language);
    printf("Enter the year\n");
    scanf("%d",&newnode->year);
    newnode->next = newnode;
    return newnode;
}

Node insert_at_end(Node head){
    Node newnode = create();
    if(head == NULL){
        return newnode;
    }
    else{
        Node temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        return head;
    }
}

Node insert_at_beg(Node head){
    Node newnode = create();
    if(head == NULL){
        return newnode;
    }
    else{
        Node temp = head;
        newnode->next = head;
        head = newnode;
        while(temp->next != newnode->next){
            temp = temp->next;
        }
        temp->next = head;
        return head;
    }
}

int lenght(Node head){
    int l = 1;
    Node temp = head;
    while(temp->next != head){
        temp = temp->next;
        l++;
    }
    return l;
}

Node insert_at_pos(Node head){
    int l = lenght(head);
    int pos;
    Node newnode = create();
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(pos < 0|| pos > l){
        printf("Invalid Input\n");
    }
    else if(pos == 1){
        head = insert_at_beg(head);
    }
    else if(pos == l){
        head = insert_at_end(head);
    }
    else{
        int i=1;
        Node temp = head;
        while(i < pos -1){
            temp = temp->next;
            i++;
        }
        Node temp2 = temp->next; // temp2 is at position temp is behind temp2
        temp->next = newnode;
        newnode->next = temp2;
    }
    return head;
}

Node delete_front(Node head){
    Node temp = head;
    if(head == NULL){
        printf("List is Empty\n");
    }
    else{
        Node temp2 = head;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        head = head->next;
        temp2->next = head;
        free(temp);
    }
    return head;
}

Node delete_end(Node head){
    Node temp = head;
    Node temp2;
     if(head == NULL){
        printf("List is Empty\n");
    }
    else{
        while(temp->next != head){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = head;
        free(temp);
    }
    return head;
}

Node delete_at_pos(Node head){
    int l = lenght(head);
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(pos < 0 || pos> l){
        printf("Inlvaid Input\n");
    }
    else if(pos == 1)
    head = delete_front(head);
    else if(pos == l)
    head = delete_end(head);
    else{
        Node previousnode = head, currentnode;
        int i=1;
        while(i < pos-1){
            previousnode = previousnode->next;
            i++;
        }
        currentnode = previousnode->next;
        previousnode->next = currentnode->next;
        free(currentnode);
    }   
    return head;
}

void search_name(Node head){
    char namee[20];
    printf("Enter the name which is to be searched\n");
    scanf("%s",namee);
    Node temp = head;
    int cnt = 0;
    while(temp->next != head){
        int k = strcmp(namee,temp->name);
        if(k == 0){
            printf("Singer found\n");
            cnt++;
            break;
        }
        temp = temp->next;
    }
    if(cnt == 0){
        printf("Singer not found\n");
    }
}

void display(Node head){
    Node temp = head;
    while(temp->next != head){
        printf("%s\n",temp->name);
        printf("%s\n",temp->language);
        printf("%d\n",temp->no_songs);
        printf("%d\n",temp->year);
        temp = temp->next;
    }
        printf("%s\n",temp->name);
        printf("%s\n",temp->language);
        printf("%d\n",temp->no_songs);
        printf("%d\n",temp->year);
}

int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at begining\n3 to insert at position\n4 to delete at front\n5 to delete at end\n6 to delete at position\n");
        printf("7 to display the list\n8 to search name\n");
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
                head = insert_at_beg(head);
                break;
            case 3:
                head = insert_at_pos(head);
                break;
            case 4:
                head = delete_front(head);
                break;
            case 5:
                head = delete_end(head);
                break;
            case 6:
                head = delete_at_pos(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                search_name(head);
                break;
            default:
                exit(0);
                break;
       }
    }
}