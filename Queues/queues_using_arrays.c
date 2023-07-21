#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 50

typedef struct queue{
    int front;
    int rare;
    int arr[MAX];
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

void enque(Queue * q, int n){
    if(!isFull(q)){
        if(q->front == q->rare == -1){
            q->rare++;     
        }
        else
            q->rare++;
        q->arr[q->rare] = n;
    }
    else
        printf("queue overflow\n");
    return;
}

int dequeue(Queue *q){
    int x;
    if(!isEmpty(q)){
        q->front++;
        x = q->arr[q->front];
        return x;
    }
    else
        return INT_MIN;
}

void display(Queue *q){
    if(!isEmpty(q)){
        for(int i = q->front+1; i <= q->rare; i++)
            printf("%d\t",q->arr[i]);
            printf("\n");
    }
    else
        printf("Queue is Empty\n");
}

int main(){
    Queue q;
    q.front = q.rare = -1;
    while(1){
        printf("\nEnter\n1 to enque\n2 to deque\n3 to print queue\n");
        printf("0 to exit\n");
        int ch;
        int n;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element which is to be inserted\n");
            scanf("%d",&n);
            enque(&q,n);
            break;
        case 2:
            n = dequeue(&q);
            printf("The element which is removed is %d\n",n);
            break;
        case 3:
            display(&q);
            break;
        
        default:
            exit(0);
            break;
        }
    }
    return 0;
}