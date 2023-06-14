#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct  music{
char lsong[20];
int number;
char singer[20];
char language[20];
struct music*next;

};

typedef struct music* Node;

Node create()//creating the node
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct music));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Most liked Song is:\n");
    scanf("%s",newnode->lsong);
    printf("Number of songs are:\n");
    scanf("%d",&newnode->number);
    printf("Singer is:\n");
    scanf("%s",newnode->singer);
    printf("Language of the song is:\n");
    scanf("%s",newnode->language);
    newnode->next=newnode;
    return newnode;
}

Node insert_at_beg( Node head)//inserting at the beginning
{
    Node newnode;
    Node temp1=head;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp1->next!=head)
    {
        temp1=temp1->next;
    }
    newnode->next = head;
    head=newnode;
    temp1->next = newnode;
    
    return head;

}

Node insert_at_end(Node head)//inserting at the end
{
    Node newnode;
    Node temp=head;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;


}
Node insert_singer(Node head)//inserting at the pos when a singer is found
{
    Node newnode;
    Node temp=head;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    char sin[20];
    printf("Enter the singer who has to be searched\n");
    scanf("%s",&sin);
    while(temp->next!=head)
    {
        if(strcmp(temp->singer,sin)==0)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;


}
Node delete_at_beg(Node head)//deleting at the beginning
{
    Node temp1,temp2=head;
    if(head==NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }
    while(temp2->next!=head)
    {
        temp2=temp2->next;
    }
    temp1 = head;
    head = head->next;
    temp2->next=head;
    free(temp1);
    return head;
}
Node delete_at_end(Node head)//deleting at th end
{
    Node temp,prev;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    while(temp->next!=head)
    {   prev =temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
    return head;

}
Node delete_at_pos(Node head)//deleting at the position
{
    Node temp=head;
    Node nextnode;
    int pos,count = 1;
    printf("Enter the position\n");
    scanf("%d",&pos);
     if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    if(pos<1 || pos>count+1)
    {
        printf("Invalid position entered\n");
        exit(0);
    }
    if(pos==1)
    {
        head=delete_at_beg(head);
        return head;
    }
    if(pos==count+1)
    {
        head=delete_at_end(head);
        return head;
    }
    int i = 1;
    temp=head;
    while(i<(pos-1))
    {
        temp=temp->next;
        i++;
    }
    temp->next = nextnode->next;
    free(nextnode);
    return head;

}
Node display_song(Node head)//displaying when a song is found
{
    Node temp;
     if(head==NULL)
    {
        printf("List not created\n");
        exit(0);
    }
    char son[20];
    printf("The song that has to be searched is:\n");
    scanf("%s",&son);
    temp = head;
    while(temp->next!=head)
    {
        if(strcmp(temp->lsong,son)==0)
        {
            printf("%s",temp->lsong);
            printf("%s",temp->singer);
            printf("%d",temp->number);
            printf("%s",temp->language);

        }
    }
    return head;


}
Node display(Node head)//displaying
{
    Node temp = head;
    if(head==NULL)
    {
        printf("List not created\n");
        exit(0);
    }
    while(temp->next!=head)
    {
        printf("%s\n",temp->lsong);
        temp=temp->next;
    }
    printf("%s\n",temp->lsong);
}
int main()
{
    Node head=NULL;
    int ch;
    while(1)
    {
        printf("1.for insertion at beginning\n2.for insertion at the end\n3.for insertion based on singer\n4.for deletion at beginning\n5.fordeletion at end\n6.for deletion at pos\n7.for displaying based on key song\n8.for display");
        printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        head=insert_at_beg(head);
        break;
    case 2:
        head=insert_at_end(head);
        break;
    case 3:
        head=insert_singer(head);
        break;
    case 4:
        head=delete_at_beg(head);
        break;
    case 5:
        head=delete_at_end(head);
        break;
    case 6:
        head=delete_at_pos(head);
        break;
    case 7:
        head=display_song(head);
        break;
    case 8:
        head=display(head);
        break;
    default:
        printf("Invalid choice entered\n");
        exit(0);
    }
    }
}