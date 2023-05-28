#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
char cname[20];
float sal;
int year;
struct student *next;
};

typedef struct student* node;

node createlist()
{
    node newnode;
    newnode=(node)malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("enter company name=\n");
    scanf("%s",newnode->cname);
    printf("enter salary=\n");
    scanf("%f",&newnode->sal);
    printf("enter year=\n");
    scanf("%d",&newnode->year);

    newnode->next=NULL;
    return newnode;
}

node display(node start)
{
    node p=start;
    if(start==NULL)
    {
        printf("list is empty\n");
        exit(0);
    }
    while(p != NULL)
    {
        printf("%s\n",p->cname);
        printf("%f\n",p->sal);
        printf("%d\n",p->year);
        p = p->next;
    }
}

node insertend(node start)
{
    node newnode,p=start;
    newnode=createlist();
    if(start == NULL)
    {
        return newnode;
    }
    
    
         while(p->next!=NULL)
        {
          p=p->next;
         }
        p->next=newnode;
    return start;

}

// search with respect to year ie int
node searchyear(node start)
{
    node newnode,p;
    int y=2020;
    p=start;
    while(p!=NULL)
    {
        if(y==p->year)
        {
            printf("placed in 2020\n");
            printf("%s\n",p->cname);
            printf("%f\n",p->sal);
            printf("%d\n",p->year);


        }
        p=p->next;
    }

    return start;
}


// Finding highest value in int or float
void searchsal(node start)
{
    node p=start;
    node p1;
    int high = p->sal;
    while(p!=NULL)
    {

        if(high < p->sal)
        {
            high=p->sal;
            p1 = p;
        }   
        p=p->next;
    }
    printf("%s\n",p1->cname);
    printf("%f\n",p1->sal);
    printf("%d\n",p1->year);
}

int main()
{
    node start=NULL;
    int ch;
    while(1)
    {
        printf("\n 0. exit\n 1.insert end\n 2.search for 2020 year\n 3.search for highest salary\n 4.display\n");
        printf("enter your choice=\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            start=insertend(start);
            break;
        case 2:
            start=searchyear(start);
            break;
        case 3:
            searchsal(start);
            break;
        case 4:
            display(start);
            break;
        default:
            printf("invalid\n");
            exit(0);
        }

    }
}