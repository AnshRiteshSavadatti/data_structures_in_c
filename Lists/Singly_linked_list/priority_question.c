// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// struct list{
//     char task[20];
//     char pri[20];
//     struct list *next;
// };
// typedef struct list *node;
// node createlist()
// {
//     node newnode;
//     newnode=(node)malloc(sizeof(struct list));
//     if(newnode==NULL)
//     {
//         printf("memory not allocated\n");
//         exit(0);
//     }
//     printf("enter the task to perform=\n");
//     scanf("%s",newnode->task);
//     printf("enter the priority\n");
//     scanf("%s",newnode->pri);
//     newnode->next=NULL;
//     return newnode;

// }
// node insertend(node start)
// {
//     node p;
//    node newnode=createlist();
//     if(start==NULL)
//     {
//         return newnode;
//     }
//     p=start;
//     while(p->next!=NULL)
//     {
//         p=p->next;
//     }
//     p->next=newnode;
//     return start;
// }

// node priority(node start)
// {
//      node p=start;
//      char pi[20];
//       printf("enter your priority=\n");
//     scanf("%s",pi);
//     while(p!=NULL)
//     {
//         if(strcmp(p->pri,pi)==0)
//         {

//             printf("%s\n",p->task);
//             insertend(start);

//         }
//         p=p->next;
//         return start;
//     }

// }
// node display(node start)
// {
//     node p=start;
//     while(p!=NULL)
//     {
//         printf("%s\n",p->task);
//         p=p->next;
//     }
// }

// int main()
// {
//     node start=NULL;
//     int ch;

//     while(1)
//     {
//         printf("0.exit\n 1.display\n 2.priority order\n3 to insert at end\n ");

//         printf("enter your choice=\n");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//         case 0:
//             exit(0);
//         case 1:
//             display(start);
//             break;
//         case 2:
//             start=priority(start);
//             break;
//         case 3:
//             start=insertend(start);
//             break;

//         default:
//             printf("invalid choice\n");
//             exit(0);
//         }
//     }
// }



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
char task[20];
int priority;
struct list* next;
};
typedef struct list* Node;
Node create()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct list));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("The task is:");
    scanf("%s",newnode->task);
    printf("The priority of the task is:");
    scanf("%d",&newnode->priority);
    newnode->next=newnode;
    return newnode;
}
Node insert_at_beg(Node head)
{
    Node temp2 = head,temp1;
    Node newnode;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp2->next!=head)
    {
        temp2=temp2->next;
    }
        temp2->next=newnode;
        newnode->next=head;
        head=newnode;
        return head;
}

Node priority_task(Node head)
{
    Node temp=head;
    int p;
    printf("The priority of which the task has to be deleted is:\n");
    scanf("%d",&p);
    while(temp->next!=head)
    {
        Node temp2;

    if(p==temp->priority)
        { printf("%s",temp->task);
          if(temp==head)
          {
              head=head->next;
              free(temp);
          }
          
          temp2->next=temp->next;
          free(temp);
          }
        temp2=temp;
        temp=temp->next;

 }
 return head;

 }

Node display_task(Node head)
{
    Node temp=head;
    if(head==NULL)
    {
        printf("The list is not created\n");
        exit(0);

    }
    while(temp->next!=head)
    {
        printf("%s\n",temp->task);
        printf("%d\n",temp->priority);
        temp=temp->next;
    }
     printf("%s\n",temp->task);
        printf("%d\n",temp->priority);

}
int main()
{
    Node head = NULL;
    int ch;
    while(1)
    {
        printf("1.for insertion at beginning\n2.for choosing the priority\n3.for displayin\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            head=insert_at_beg(head);
            break;
       case 2:
            head=priority_task(head);
            break;
        case 3:
            display_task(head);
            break;
        default:
            printf("Invalid choice entered \n");
            exit(0);
        }
    }

}