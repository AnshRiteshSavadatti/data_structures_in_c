#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char singer[20];
    int year;
    char movie[20];
    float duration;
    struct node* next;
};

typedef struct node* Node;

Node create(){
 Node newnode = (Node)malloc(sizeof(struct node));
 if(newnode == NULL){
    printf("Memory not allocated\n");
    exit(0);
 }   
 printf("Enter the year\n");
 scanf("%d",&newnode->year);
 printf("Enter the singer name\n");
 fflush(stdin);
 gets(newnode->singer);
 printf("Enter the movie of song\n");
 scanf("%s",newnode->movie);
 printf("Enter the duration\n");
 scanf("%f",&newnode->duration);
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
    }
    return head;
}

void displat_arjit(Node head){
    int cnt = 0;
    char name[20] = "Arjit_sing";
    Node temp = head;
    while(temp->next != head){
        // int k = strcmp(name, temp->singer);
        // printf("%d",k);
        if(!(strcmp(name, temp->singer))){
        printf("%d\n",temp->year);
        printf("%s\n",temp->singer);
        printf("%s\n",temp->movie);
        printf("%f\n",temp->duration);  
        cnt++;
        }
        temp = temp->next;
    }
    if(!(strcmp(name, temp->singer))){
        printf("%d\n",temp->year);
        printf("%s\n",temp->singer);
        printf("%s\n",temp->movie);
        printf("%f\n",temp->duration);  
        cnt++;
        }
    printf("The total songs by arjit singh is %d\n",cnt++);

}

Node delete_at_front(Node head){
    Node temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    Node temp3 = head;
    head = head->next;
    free(temp);
    return head;
}


Node delete(Node head){
    int y;
    printf("Enter the year\n");
    scanf("%d",&y);
    Node temp = head;
    Node temp1 = NULL;
    while (temp->next != head)
    {   if(y == temp->year){
          if(temp == head){
                head = delete_at_front(head);
                return head;
            }
            else{
                temp1->next = temp->next;
                free(temp);
                return head;
            }
        }
        temp1 = temp;
        temp = temp->next;
    
    }
    
    return head;
}

int length(Node head){
    Node temp = head;
    int cnt = 1;
    while(temp->next != head){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
Node insert_at_pos(Node head){
    int l = length(head);
    int pos;
    printf("Enter the positoin\n");
    scanf("%d",&pos);
    Node newnode = create();
    if(pos<0 || pos>l){
        printf("Invalid Input\n");
        return head;
    }
    else if(pos == 1){
        Node temp = head;
        newnode->next = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        head = newnode;

    }
    else if(pos == l){
        head = insert_at_end(head);
    }
    else{
        int i=1;
        Node temp = head, temp2;
        while(i < pos){
            temp2 = temp;
            temp = temp->next;
            i++;
        }
        temp2->next = newnode->next;
        newnode->next = temp; 
    }
    return head;
}

void display(Node head){
    Node temp = head;
    while (temp->next != head)
    {
        /* code */
        printf("%d\n",temp->year);
        printf("%s\n",temp->singer);
        printf("%s\n",temp->movie);
        printf("%f\n",temp->duration); 
        temp = temp->next; 
    }
        printf("%d\n",temp->year);
        printf("%s\n",temp->singer);
        printf("%s\n",temp->movie);
        printf("%f\n",temp->duration); 
    
}

int main(){
    Node head = NULL;
    int ch;
    while ((1))
    {
        printf("Enter\n1 to insert at end\n2 to display songs by arjit singh\n3 to delete the songs of particular year\n4 to add the song at pos\n5 to display songs\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = insert_at_end(head);
            break;
        case 2 :
            displat_arjit(head);
            break;
        case 3:
            head = delete(head);
            break;
        case 4 :
            head = insert_at_pos(head);
            break;
        case 5:
            display(head);
            break;
        default :
            exit(0);        
            break;
        }
    }
    
}