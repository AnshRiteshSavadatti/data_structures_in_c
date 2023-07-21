#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

struct node{
    char name[20];
    int age;
    int coupon;
};

typedef struct queue{
    struct node n[MAX];
    int front;
    int rare;
}Queue;

int isEmpty(Queue *q){
    if(q->rare == -1)
        return 1;
    return 0;
}

int isFull(Queue *q){
    if(q->rare == MAX -1)
        return 1;
    return 0;
}

void enqueue(Queue *q){
    if(!isFull(q)){
        q->rare++;
        printf("Enter the name\n");
        scanf("%s",q->n[q->rare].name);
        printf("Enter the age\n");
        scanf("%d",&q->n[q->rare].age);
        printf("Enter the coupon\n");
        scanf("%d",&q->n[q->rare].coupon);
    }
    else
        printf("queue overflow\n");
    return;
}

void dequeue(Queue *q){
    if(!isEmpty(q)){
        q->front++;
         printf("%s\n",q->n[q->front].name);
         printf("%d\n",q->n[q->front].coupon);
    }
    else
        printf("Queue underflow\n");
    return;
}

void display(Queue *q){
    if(!isEmpty(q)){
        for(int i = q->front+1; i <= q->rare; i++){
            printf("%s\t",q->n[i].name);
            printf("%d\t",q->n[i].age);
            printf("%d\t\n",q->n[i].coupon);
        }
           
            printf("\n");
    }
    else
        printf("Queue is Empty\n");
}

void winners(Queue *q){
    for(int i = q->front+1; i <= q->rare; i++){
        if(q->n[i].coupon % 7 == 0){
            printf("The winners are \n");
            printf("%s\n",q->n[i].name);
            printf("%d\n",q->n[i].age);
            printf("%d\n",q->n[i].coupon); 
        }
    }
    return;
}

void count(Queue *q){
    if(!isEmpty(q)){
        int cnt = 0;
        for(int i = q->front+1; i <= q->rare; i++)
            cnt++;
        printf("Total coupons issused are %d\n",cnt);
    }
}

int main(){
    Queue q;
    q.front = q.rare = -1;
    while(1){
        printf("\nEnter\n1 to enque\n2 to deque\n3 to print queue\n4 to know about the winners\n5 to count number of coupons\n");
        printf("0 to exit\n");
        int ch;
        int n;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            winners(&q);
            break;
        case 5:
            count(&q);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}