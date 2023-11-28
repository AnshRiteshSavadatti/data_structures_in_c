#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 50

struct node{
    int amt;
    int acc_no;
    char mode;
};

typedef struct queue{
    int front;
    int rare;
    struct node n[MAX];
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
            scanf("%d",&q->n[q->rare].acc_no);
            printf("Enter the amount\n");
            scanf("%d",&q->n[q->rare].amt);
            printf("Enter the mode of checque[c] or cash[h]\n");
            fflush(stdin);
            scanf("%c",&q->n[q->rare].mode);
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
        q->n[q->rare].acc_no = n;
    }
    else
        printf("queue overflow\n");
    return;
}

struct node dequeue(Queue *q){
    struct node x;
    if(!isEmpty(q)){
        q->front++;
        x = q->n[q->front];
        return x;
    }
}

void display(Queue *q, Queue *q1){
    int cnt = 0;
    if(!isEmpty(q)){
        for(int i = q->front+1; i <= q->rare; i++){
            if(q->n[i].mode == 'c' || q->n[i].mode == 'C' ){
                dequeue(q);
                enque1(q1,q->n[i].acc_no);
            }
            else{
                printf("For person of account number %d We request to collect you the amount afer two days\n",q->n[i].acc_no);
                dequeue(q);
                cnt++;
            }
        }
        printf("The accout of peoples with cash mode will be displayed\n");
        for(int i = q1->front+1; i <= q1->rare; i++){
            printf("%d\t",q1->n[i].acc_no);
        }
    }
    printf("\nThe number of peoples not served are %d\n",cnt);
    return;
}

int main(){
    int ch;
    Queue q,q1;
    q.front = q.rare = q1.front = q1.rare = -1;
    while(1){
        int ch;
        printf("Enter\n1 to enque\n2 to display, distribute queue and find the people which wont be served\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               enque(&q);
               break;
            case 2 :
                display(&q,&q1);
                break;
            default :
                exit(0);

        }
    }
}