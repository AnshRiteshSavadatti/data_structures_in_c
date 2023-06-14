#include<stdio.h>
#include<stdlib.h>

struct royal_furniture
{
    char ID[20];
    struct royal_furniture* next;
};

typedef struct royal_furniture * Node;

Node create()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct royal_furniture));
    if(newnode == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    printf("Enter the Id of furniture\n");
    scanf("%s",newnode->ID);
    newnode->next = NULL;
    return newnode;
}

Node insert_end(Node head)
{
    Node temp,newnode;
    newnode=create();
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
}

Node delete_end (Node head)
{
    Node currentnode,previousnode;
    currentnode = head;
    while(currentnode->next != NULL)
    {
        previousnode=currentnode;
        currentnode=currentnode->next;
    }
    previousnode->next = NULL;
    free(currentnode);
    return head;
}
void display( Node head)
{
    Node temp;
    if(head == NULL)
    {
        printf("list is empty\n");

    }
    temp=head;
    while(temp!= NULL)
    {
        printf("%s",temp->ID);
        printf("\n");
        temp=temp->next;
    }
}
int main()
{
    int ch;
    Node head=NULL;
 while(1)
 {
     printf("Enter \n 1 to insert at end \n 2 to delete at end \n 3 to display ");
     printf("\n 0 to exit");
     printf("\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
              head=insert_end(head);
        break;
        case 2:
               head=delete_end(head);
        break;
        case 3:
              display(head);
        break;
        case 0:
            exit(0);
            break;


     }
 }
 return 0;
}