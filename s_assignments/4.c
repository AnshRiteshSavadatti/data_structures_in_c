#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node*next;
    struct node*prev;

};
typedef struct node*Node;

Node create()
{

    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
    printf("Enter the data in the newnode:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;

}

Node insert_at_end(Node head)
{   Node newnode=create();
    if(head==NULL)
    {
        return newnode;
    }
    Node temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

Node search(Node head)
{
    Node A=head;
    Node B=head;
    while(B->next!=NULL)
    {
        B=B->next;
    }
    while(B != A->prev && B!= head)
    {
        if(A->data > B->data)
        {
            printf("1 ");
            B = B->prev;
        }
        else if(A->data < B->data)
        {
            printf("2 ");
            A = A->next;
        }
        else{
            printf("0 ");
            A = A->next;
            B = B->next;
        }
    }
}
int main()
{
    Node head=NULL;
    int n;
    printf("Enter the no. of elements in the list:\n");
    scanf("%d",&n);
    if(n <= 0){
        printf("Invalid input\n");
        return 0;
    }
    if(n == 1){
        printf("0 ");
        return 1;
    }
    while(n--)
    {
        head=insert_at_end(head);
    }
    head=search(head);
    return 0;
}