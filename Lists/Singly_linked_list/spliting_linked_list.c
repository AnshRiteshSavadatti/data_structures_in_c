#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int a;
    struct node*next;
};
typedef struct node *Node;
Node create()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("The value of a is:\n");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    return newnode;
}
Node insert_at_end(Node head)
{
    Node newnode;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    Node temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
Node split(Node head,Node head2)
{
    Node temp=head;
     int x;
     printf("No.of nodes in the first list:\n");
     scanf("%d",&x);
    printf("The list 1 is:\n");

        for(int i=0;i<(x-1);i++)
        {
             printf("%d\n",temp->a);
            temp=temp->next;
        }
        printf("%d\n",temp->a);

        head2=temp->next;
        temp->next=NULL;


    return head2;
}
Node display(Node head)
{
    Node temp=head;
    printf("list 2 is:\n");
    while(temp!=NULL)
    {
        printf(" %d\n",temp->a);


        temp=temp->next;

    }
    return head;
}
int main()
{  Node head=NULL;
Node head2=NULL;

    int n;
    printf("Total no. of nodes is:\n");
    scanf("%d",&n);
    while(n--)
    {
        head=insert_at_end(head);
    }
    head2=split(head,head2);

    head2=display(head2);
}