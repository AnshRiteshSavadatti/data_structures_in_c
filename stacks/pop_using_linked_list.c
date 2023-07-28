#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
    
};
typedef struct Node *node;
node createlist()
{
    node newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("enter data=\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
   
    return newnode;
}
node insertend(node start)
{
    node newnode=createlist();
    node p=start;
    if(start==NULL)
    {
        return newnode;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=newnode;
        
        return start;
        
    }
}
node display(node start)
{
    node p=start;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
       
    }
}

node max(node start,node head)
{
    int max=0;
    node p=start;

    while(p!=NULL)
    {   
        if(max<p->data)
        {
            max=p->data;
        }
        node temp = head, temp2;
    if(p->next = start){
        while(temp->next != p)
            temp = temp->next;
        temp->next = NULL;
        if(head == NULL){
            p->next = NULL;
            head = p;
        }
        else{
            node n = head;
            while(n->next != NULL)
                n = n->next;
            n->next = p;
            p->next = NULL;
        }
    }

    else if (p == start)
    {
        start = start->next;
        if(head == NULL){
            p->next = NULL;
            head = p;
        }
        else{
            node n = head;
            while(n->next != NULL)
                n = n->next;
            n->next = p;
            p->next = NULL;
        }
    }
    else{
        while(temp->next != p)
            temp = temp->next;
            temp->next = p->next;
            if(head == NULL){
            p->next = NULL;
            head = p;
            }
        else{
            node n = head;
            while(n->next != NULL)
                n = n->next;
            n->next = p;
            p->next = NULL;
        }
    }
    }
    printf("maximum element is %d\n",max);
}

void min(node start)
{
    int min=10000;
    node p=start;
    while(p!=NULL)
    {
        if(min >  p->data)
        {
            min = p->data;
        }
        p=p->next;
    }
    printf("maximum element is %d\n",min);

}
int main()
{
    node start=NULL;
    node head = NULL;
    int ch;
    while(1)
    {
        printf("0.exit\n 1.insertend\n 2.display\n 3.max value\n 4.min value\n");
        printf("enter your choice=\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            case 1:
            start=insertend(start);
            break;
            case 2:
            display(start);
            break;
            case 3:
            head = max(start,head);
            break;
            case 4:
            min(start);
            break;
            default:
            printf("invalid choice\n");
            exit(0);
        }
    }
    return 0;
}