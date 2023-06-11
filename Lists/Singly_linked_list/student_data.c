#include<stdio.h>
#include<stdlib.h>

struct  node{
    char name[20];
    int batch;
    int ID;
    float cgpa;
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
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter the batch\n");
    scanf("%d",&newnode->batch);
    printf("Enter the cgpa\n");
    scanf("%f",&newnode->cgpa);
    printf("Enter the ID\n");
    scanf("%d",&newnode->ID);
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

int lenght(Node head){
    int count = 1;
    Node temp = head;
   while(temp->next != head){
    temp = temp->next;
    count++;
   }
   return count;
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

Node delete_wrt_ID(Node head){
    Node temp = head;
    Node temp2;
    int id;
    printf("Enter the id\n");
    scanf("%d",&id);
    while(temp->ID != id){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = head->next;
        free(temp);
        return head;
    }
    else{
      temp2->next = temp->next;
      free(temp);
      return head;
    }
}
// Node delete_wrt_ID(Node head){
//     int l = lenght(head);
//     int id;
//     printf("Enter the id\n");
//     scanf("%d",&id);
//     Node temp = head;
//     int cnt = 0;
//     while(temp->ID != id){
//         temp = temp->next;
//         if(temp->ID == id){
//             break;
//         }
//         cnt++;
//     }
//     if(cnt == 0){
//         printf("Invalid ID\n");
//     }
//     else{
//         if(cnt == 1){
//             head = delete_beg(head);
//         }
//         else if(cnt == l){
//             head =delete_end(head);
//         }
//         else{
//             temp = head;
//             while(temp != NULL){
//                 temp = temp->next;
//                 Node temp2 = temp;
//                 temp = temp->next;
//                 if(temp->ID == id){
//                     temp2->next = temp->next;
//                     free(temp);
//                 }
//             }
//         }
//     }
//     return head;
// }

void display(Node head){
    Node temp = head;
    int b;
    printf("Enter the batch\n");
    scanf("%d",&b);
    while(temp != NULL){
        if(b == temp->batch){
        printf("%s\n%d\n%d\n%f\n",temp->name,temp->ID,temp->batch,temp->cgpa);
        }
        temp = temp->next;
        
    }    
    return;
}


int main(){
    int ch;
    Node head = NULL;
    while(1){
        printf("Enter\n1 to insert at end\n2 to delete wrt to ID\n3 to display wrt to batch\n");
        printf("0 to exit\n");
        scanf("%d",&ch);
        switch (ch){
        case 1:
            head = insert_end(head);
            break;
        case 2:
            head = delete_wrt_ID(head);
            break;
        case 3:
            display(head);
            break;
        default:
            exit(0);
            break;
        }
    }
}