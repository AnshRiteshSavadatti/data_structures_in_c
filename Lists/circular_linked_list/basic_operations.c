#include<stdio.h>
#include<stdlib.h>

struct  node{
    int data;
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
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
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
        printf("%d\n",temp->data);
        temp = temp->next;
    }    
    printf("%d\n",temp->data);
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

Node delete_front(Node head){
    Node temp;
    temp = head;
    head = head->next;
    Node temp2 = head;
    while(temp2->next != temp){
        temp2 = temp2->next;
    }
    temp2->next = head;
    free(temp);
    return head;
}

Node delete_from_end(Node head){
    Node temp,  temp2;
    temp = head;
    if(head->next == head){
        free(head);
    }
    while(temp->next != head){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = head;
    free(temp);
    return head;
}

Node delete_at_pos(Node head){
    int l = lenght(head);
    int position;
    printf("Enter the position\n");
    scanf("%d",&position);
    if(position > l || position < 0){
        printf("Invalid Input\n");
    }
    else{
        if(position == 1){
            head = delete_front(head);
        }
        else if(position == l){
            head =delete_from_end(head);
        }
        else{
            Node temp = head;
            int i = 1;
            while(i < position - 1){
                temp = temp->next;
                i++;
            }
            Node temp2 = temp->next; // temp2 is at position
            temp->next = temp2->next;
            free(temp2);
        }
    }
    return head;
}

void search(Node head){
    int data;
    int cnt = 0;
    printf("Enter the data\n");
    scanf("%d",&data);
    Node temp = head;
    while(temp ->next != head){
        if(data == temp->data){
            printf("Found\n");
            cnt++;
        }
        temp = temp->next;
    }
    if(cnt == 0){
        printf("Not found\n");
    }
  return ;
}

Node reverse(Node head)
{
    Node prevnode,currentnode,nextnode;
    currentnode=nextnode=head;
    prevnode=NULL;
    if(head==NULL)
    {
        printf("The list is empty");
        exit(0);
    }
   
    while(nextnode->next != head)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;
    head=prevnode;
    nextnode->next = head;
    return head;
}

int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at begning\n3 to insert at position\n4 to reverse\n5 to delete from front\n6 to delete form end\n7 to display\n");
        printf("8 to delete at position\n9 to search\n");
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
            head = reverse(head);
            break;
        case 5:
            head = delete_front(head);
            break;
        case 6:
            head = delete_from_end(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            head = delete_at_pos(head);
            break;
        case 9:
            search(head);
            break;
        default:
            exit(0);
            break;
        }
    }
}