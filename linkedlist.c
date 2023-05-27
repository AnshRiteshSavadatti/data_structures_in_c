// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct node{
//     int data;
//     struct node* link;
// };
// typedef struct node node;

// void create_node(node* head){
//  node * newnode ,*temp;
//  int choice = 1;
//     while(choice){
//         newnode = (struct node*)malloc(sizeof(struct node));
//         printf("Enter the value in newnode ");
//         scanf("%d",&newnode->data);
//         newnode->link = 0;
//         if(head == 0){
//             temp = head = newnode;
//         }
//         else{
//             temp->link = newnode;
//             temp = newnode;
//         }
//         printf("Do want to continue (0/1) ?");
//         scanf("%d",&choice);
//     }
//     temp = head;
//     while(temp != 0){
//         printf("%d\n",temp->data);
//         temp = temp->link;
//     }
// }

// void print(node* head){
//     node* temp;
//     temp = head;
//     while(temp != 0){
//         printf("%d\n",temp->data);
//         temp = temp->link;
//     }
//     while(temp != 0){
//         printf("%p\n",&temp->data);
//         temp = temp->link;
//     }
// }

// // node create(){
// //     node* temp, *newnode;
// //     newnode = (node*)malloc(sizeof(node));
// //     printf("Enter the data ");
// //     scanf("%d",&newnode->data);
// //     return *newnode;
// // }

// // void insertbeg(node* head){
// //     node* temp, *newnode;
// //     *newnode = create();
// //     if(head == NULL){
// //         printf("Memory not allocated ");
// //         exit(0);
// //     }
// //     newnode->link = head;
// //     newnode = head;
// // }

// int main(){
//     node* head;
//     head = 0;
//     create_node(head);
//     print(head);
//     //insertbeg(head);
//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// typedef struct node{
//     int data;
//     struct node* next;
// }nod;

// nod* create(){
//     nod* newnode;
//     newnode = (nod*)malloc(sizeof(nod));
//     printf("Enter the data in node ");
//     scanf("%d",&newnode->data);
//     newnode->next = NULL;
//     return newnode;
// }

// nod* insertlist(nod* head){
//     nod* newnode, *temp;
//     newnode =create();
//     if(head == NULL){
//         return newnode ;
//     }
//     else{
//         temp = head;
//         while(temp->next != NULL){
//             temp=temp->next;
//         }
//         temp->next = newnode;
//         return head;
//     }
// }
// void print(nod* head){
//     nod* temp;
//     if(head == NULL){
//         printf("List is empty \n");
//     }
//     else{
//         temp = head;
//         while(temp != NULL){
//         printf("%d\n",temp->data);
//         temp=temp->next;
//         }
//     }
// }

// int main(){
//     nod* head = NULL;
//     int ch;
//     while(1){
//     printf("enter 1 to insert node\nenter 2 to display the node\nenter 3 to exit\n");
//     scanf("%d",&ch);
//     switch (ch){
//         case(1):
//         insertlist(head);
//         break;
//         case(2): 
//         print(head);
//         break;
//         case(3):
//         exit(0);
//         default:
//         printf("Invalid choice ");
//         exit(0);

//     }
    
//     }
// }



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int data;
//     struct node* next;
// } nod;

// nod* create() {
//     nod* newnode;
//     newnode = (nod*)malloc(sizeof(nod));
//     if (newnode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     printf("Enter the data in node: ");
//     scanf("%d", &newnode->data);
//     newnode->next = NULL;
//     return newnode;
// }

// nod* insertlist(nod** head) {
//     nod* newnode, * temp;
//     newnode = create();
//     if (*head == NULL) {
//         *head = newnode;
//     } else {
//         temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newnode;
//     }
//     return *head;
// }

// void print(nod* head) {
//     nod* temp = head;
//     if (temp == NULL) {
//         printf("List is empty\n");
//     } else {
//         while (temp != NULL) {
//             printf("%d\n", temp->data);
//             temp = temp->next;
//         }
//     }
// }

// int main() {
//     nod* head = NULL;
//     int ch;
//     while (1) {
//         printf("Enter 1 to insert a node\nEnter 2 to display the nodes\nEnter 3 to exit\n");
//         scanf("%d", &ch);
//         switch (ch) {
//             case 1:
//                 head = insertlist(&head);
//                 break;
//             case 2:
//                 print(head);
//                 break;
//             case 3:
//                 exit(0);
//             default:
//                 printf("Invalid choice\n");
//                 exit(1);
//         }
//     }
//     return 0;
// }


//Insertion at any point

#include<Stdio.h>
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
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

Node Insert_at_end(Node head){
    Node newnode , temp;
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
 
int count(Node head){
    int count = 1;
    Node temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;

}
Node Insert_at_pos(Node head){
    Node temp1, temp2;
    Node newnode;
    newnode = create();
    temp1 = head;
    int position;
    printf("Enter the positon\n");
    scanf("%d",&position);
    int coount = count(head);
    if(position <=0 || position >= coount +1){
        printf("Invalid Position \n");
        exit(0);
    }
    int i = 1;
    while(i < position - 1){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = newnode;
    newnode->next = temp2;
    return head;
}

Node delete_beg(Node head){
    Node temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node delete_at_end( Node head){
    Node temp = head;
    Node temp1;
    while(temp->next != NULL){
        temp1 = temp;
        temp =temp->next;
    }
    temp1->next = NULL;
    free(temp);
    return head;
    
}

Node delete_at_pos(Node head){
    Node temp1, temp2;
    int position;
    printf("Enter the position\n");
    scanf("%d",&position);
    printf("The positon is: %d\n",position);
    int coount = count(head);
     
    if(position <=0 || position > coount){
        printf("Invalid Input\n");
        exit(0);
    }
    if(position == 1){
        head = delete_beg(head);
        
        return head;
    }
    if(position == coount){
        head = delete_at_end(head);
        return head;
    }
    else{
    int i = 1;
    temp1 = head;
    while(i < position - 1 ){
        temp1 = temp1->next;
        i++;
        printf("hi");
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = NULL;
    printf("Hi");
    free(temp2);
    return head;
    }
}


void display(Node head){
    Node temp;
    temp = head;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
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

int main(){
    Node head = NULL;
    int ch;
    while(1){
        printf("Enter\n1 to insert at end\n2 to insert at positon\n3 to print the list\n4 to delete from begning\n5 to delete at end\n6 to delete at position");
        printf("\n7 to insert before key ");
        printf("\nEnter 0 to exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            exit(0);
            break;
            case 1:
            head = Insert_at_end(head);
            break;
            case 2:
            head = Insert_at_pos(head);
            break;
            case 3:
            display(head);
            break;
            case 4:
            head = delete_beg(head);
            break;
            case 5:
            head = delete_at_end(head);
            break;
            case 6:
            head = delete_at_pos(head);
            break;
            case 7:
            head = insert_before_key(head);
            break;
            default:
            printf("Invalid Input \n");
            exit(0);
        }
    }
}
