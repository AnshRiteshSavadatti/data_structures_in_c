
// Functions in linked list
// node insertion and deletion
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node* Node;
Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated ");
        exit(0);
    }
    printf("Enter the value in node ");
    scanf("%d",&newnode->data);
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
            temp= temp->next;
        }
        temp->next = newnode;
        return head;
    }
}

Node insert_beg(Node head){
    Node temp, newnode;
    temp = head;
    newnode = create();
    newnode->next = temp;
    head = newnode;
    return head;
    
}

Node insert_at_pos(Node head){
    Node temp , newnode;
  temp = head;
  int count = 1;
  int position;
 
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
   printf("Enter the position where the node is the be inserted");
  scanf("%d",&position);
  if(position == 1){
    head = insert_beg(head);
    return head;
  }
  if(count == position){
   head = insert_end(head);
   return head;
  }
  if(position > count || position <= 0 ){
    printf("Invalid Input ");
    exit(0);
  }
  
    temp = head;
    int i = 1;
   while(i < position-1){
    temp = temp->next;
    printf("%d",temp->data);
    i++;
   }
   newnode = create();
   newnode->next = temp->next;
   temp-> next = newnode;
   return head;
  
}
Node delete_beg(Node head){
    Node temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node delete_end(Node head){
    Node temp1 , temp2;
    temp1 = head;
    while(temp1->next != NULL){
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    return head;

}

Node delete_position(Node head){
    Node temp1, temp2;
    // Here temp 1 id going till position -1 and temp2 is at positon
    temp1 = head;
    printf("Enter the position ");
    int position;
    scanf("%d",&position);
    if(position == 1){
        head = delete_beg(head);
        return head;
    }
    Node temp3 = head;
    int count = 1;
    while(temp3 != NULL){
    temp3 = temp3->next;
    count++;
    }
    if(position == count){
        head = delete_end(head);
        return head;
    }
    if(position <= 0 || position > count){
        printf("Invalid Input ");
        exit(0);
    }
    int i = 1;
    while(i < position - 1){
        temp1 = temp1->next;
        i++;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = NULL;
    free(temp2);
    return head;
}

// key and insert
Node insert_before_key(Node head){
    Node temp, newnode;
    newnode = create();
    int data;
    printf("Enter the date before which node must be inserted ");
    scanf("%d",&data);
    temp = head;
    Node previous;
    while(data != temp->data){
        previous = temp;
        temp = temp->next;
    }
    previous->next = newnode;
    newnode->next = temp;
    return head;
}

Node insert_after_key(Node head){
    Node temp, nextnode, newnode;
    newnode = create();
    int data;
    printf("Enter the data after which node must be inserted ");
    scanf("%d",&data);
    temp = head;
    while(data != temp->data){
        temp = temp->next;
    }
    nextnode = temp->next;
    temp->next = newnode;
    newnode->next = nextnode;
    return head;
}

int count(Node head){
    int count = 1;
    Node temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;

}

// sorting the list
Node sort(Node head){
    Node temp1, temp2, prenode;
    int coount = count(head);
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            temp1 = head;
            temp2 = temp1->next;
            if(temp1->data > temp2->data){
                temp1->next = temp2->next;
                temp2->next = temp1;
                prenode->next = temp2;
            }
            
        }
    }
}



void display(Node head){
    Node temp;
    temp = head ;
    if(head == NULL){
        printf("The list is empty \n");
    }
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp= temp->next;
    }
}


int main(){
    Node head = NULL;
    int ch;
    while(1){
        printf("Enter\n1 for inserting a node\n2 for diaplaying the node\n3 to insert in begning\n4 for inserting a node at given position\n5 pfr inserting at end\n6 for deleting from begning\n");
        printf("7 for deleting the node from end\n8 to delete from any position\n9 to insert before key\n10 to insert after key");
        printf("\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
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
            head = insert_at_pos(head);
            break;
            case 5 :
            head = insert_end(head);
            case 6:
            head = delete_beg(head);
            break; 
            case 7:
            head = delete_end(head);
            break;
            case 8:
            head = delete_position(head);
            break;
            case 9:
            head = insert_before_key(head);
            break;
            case 10:
            head = insert_after_key(head);
            break;
            default:
            printf("Invalid input ");
            exit(0);
            break;
        }
    }
}

