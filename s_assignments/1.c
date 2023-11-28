#include<stdio.h>
#include<stdlib.h>


struct stack{
    int top;
    int data[100];
};
typedef struct stack Stack;

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node* Node;

Node create(){
    Node newnode = (Node) malloc(sizeof(struct Node));
    if(newnode == NULL){
        return NULL;
    }
    newnode->next = NULL;
    return newnode;
}

Node insert_at_end(Node head, int data){
    Node newnode = create();
    newnode->data = data;
    if(head == NULL)
        head = newnode;
    else{
        Node temp = head;
        while(temp->next != NULL){
            temp = temp ->next;
        }
        temp->next = newnode;
    }
    return head;
}

Node reverse(Node head){
    Node temp = head;
    Node head1 = NULL;
    Stack s;
    s.top = -1;
    while(temp != NULL){
        if(temp->data % 2 == 0){
            s.data[++s.top] = temp->data;
        }
        else{
            while(s.top != -1){
                head1 = insert_at_end(head1,s.top);
                printf("%d ",s.data[s.top--]);
            }
            head1 = insert_at_end(head1,temp->data);
        }
        temp = temp->next;
    }
    return head1;
}

void print(Node head){
    Node temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    Node head = NULL;
    int n;
    int data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    while(n--){
        printf("Enter data\n");
        scanf("%d",&data);
        head = insert_at_end(head,data);
    }
    printf("The numbers which are recersed are \n");
    head = reverse(head);
    printf("\n\n");
    print(head);
    return 0;
}


