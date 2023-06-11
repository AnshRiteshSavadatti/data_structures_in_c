#include<Stdio.h>
#include<Stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stack is Full\n");
    }
    else{
        printf("Enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
    }
    return newnode;
}

Node push(Node top){
    Node newnode = create();
    if(top == NULL){
        return newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
        return top;
    }
}

Node pop(Node top){
    if(top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        Node temp = top;
        top = top->next;
        printf("%d\n",temp->data);
        free(temp);
    }
    return top;
}

void display(Node top){
    Node temp = top;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    Node top = NULL;
    int ch;
    while(1){
        printf("Enter\n1 to push\n2 to display\n3 to pop\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                top = push(top);
                break;
            case 2:
                display(top);
                break;
            case 3:
                top = pop(top);
                break;
            default:
                exit(0);
                break;
        }
    }
}
