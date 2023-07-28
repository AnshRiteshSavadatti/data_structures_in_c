#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 50

typedef struct queue{
    int front;
    int rare;
    int amt[MAX];
    int acount_no[MAX];
}Queue;

int isEmpty(Queue *q){
    if(q->rare == - 1)
        return 1;
    return 0;
}

int isFull(Queue *q){
    if(q->rare == MAX - 1)
        return 1;
    return 0;
}

void enque(Queue * q){
    if(!isFull(q)){
        if(q->front == q->rare == -1){
            q->rare++;     
        }
        else
            q->rare++;
            printf("Enter the account number\n");
            scanf("%d",&q->acount_no[q->rare]);
            printf("Enter the amount\n");
            scanf("%d",&q->amt[q->rare]);
    }
    else
        printf("queue overflow\n");
    return;
}

void enque1(Queue * q, int n){
    if(!isFull(q)){
        if(q->front == q->rare == -1){
            q->rare++;     
        }
        else
            q->rare++;
        q->acount_no[q->rare] = n;
    }
    else
        printf("queue overflow\n");
    return;
}

int dequeue(Queue *q){
    int x;
    if(!isEmpty(q)){
        q->front++;
        x = q->acount_no[q->front];
        return x;
    }
    else
        return INT_MIN;
}

void display(Queue *q, Queue* q1,Queue* q2){
    if(!isEmpty(q)){
        for(int i = q->front+1; i <= q->rare; i++){
            if(q->amt[i] > 5000){
                dequeue(q);
                enque1(q1,q->acount_no[i]);
            }
            else{
                dequeue(q);
                enque1(q2,q->acount_no[i]);
            }
        }
        for(int i = q1->front+1; i <= q1->rare; i++){
            printf("%d\t",q1->acount_no[i]);
        }
        printf("\n\n");
        for(int i = q2->front+1; i <= q2->rare; i++){
            printf("%d\t",q2->acount_no[i]);
        }
    }
    return;
}

int main(){
    int ch;
    Queue q,q1,q2;
    q.front = q.rare = q1.front = q1.rare = q2.front = q2.rare = -1;
    while(1){
        int ch;
        printf("Enter\n1 to enque\n2 to display and distribute queue\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               enque(&q);
               break;
            case 2 :
                display(&q,&q1,&q2);
                break;
            default :
                exit(0);

        }
    }
}