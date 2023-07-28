#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    char name[20];
    int age;
    char gender;
    struct Node *next;
};

typedef struct Node *node;
node createqueue()
{
    node newnode;
    newnode=(node)malloc(sizeof(struct Node));
    if (newnode==NULL)
    {
        printf("Queue underflow\n");
    }
    printf("enter the name of person\n");
    scanf("%s",newnode->name);
    printf("enter age of person\n");
    scanf("%d",&newnode->age);
    printf("enter gender of person=\n");
        fflush(stdin);
    scanf("%c",&newnode->gender);
    newnode->next=NULL;
    return newnode;
}
node insertend(node rear,node* front)
{
    node newnode=createqueue();
   
    if(rear==NULL)
    {
        *front = newnode;
        return newnode;
    }
    rear->next=newnode;
    rear = newnode;
    return rear;
}

node delfront(node front)
{
    node temp=front;
    front = front->next;
    free(temp);
    return front;
    
}

void display(node rear,node front)
{
    node temp=front;
    while(temp!=NULL)
    {
        printf("%s\n",temp->name);
        printf("%d\n",temp->age);
        printf("%c\n",temp->gender);
        temp=temp->next;
    }
}
void gen(node rear,node front)
{
    int mcount=0,fcount=0;
    if(rear==NULL || front==NULL)
    {
        printf("queue is empty\n");
    }
    node temp=front;
    while(temp!=NULL)
    {
        if(temp->gender=='M'||temp->gender=='m')
        {
               mcount++;
        }
        else if(temp->gender=='F'||temp->gender=='f')
        {
            fcount++;
        }
        temp=temp->next;
    }
    printf("male count=%d\n",mcount);
    printf("female count=%d\n",fcount);

}
void total(node rear,node front)
{
    node temp=front;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("total count=%d\n",count);

}

int main()
{
    node rear=NULL,front=NULL;
    int ch;
    while(1)
    {
        printf("0.exit\n 1.insertend\n 2.delfront\n 3.display\n 4.count number of males and females in queue\n 5.total number of tickets issues\n");
        printf("enter your choice=\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            exit(0);
            case 1:
             rear=insertend(rear,&front);
             break;
            case 2:
              front=delfront(front);
              break;
            case 3:
                display(rear,front);
                break;
            case 4:
                gen(rear,front);
                break;
            case 5:
                total(rear,front);
                break;
            default:
                 printf("invalid choice\n");
                 exit(0);
        }
    }
return 0;

}