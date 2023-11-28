#include<Stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MAX 10
struct node{
    int amt;
    int freq;
    char mode;
    int customer_id;
};

typedef struct queue{
    int front;
    int rare;
    struct node n[MAX];
}Queue;

int isEmpty(Queue *s){
    if(s->rare == s->front)
        return 1;
    return 0;
}

int isFull(Queue *s){
    if(s->front == (s->rare + 1) % MAX)
        return 1;
    return 0;
}

void enuqeue(Queue *s, int amt, int customer_id, char mode ){
    if(!isFull(s)){
        s->rare = (s->rare + 1) % MAX;
        s->n[s->rare].amt = amt;
        s->n[s->rare].customer_id = customer_id;
        s->n[s->rare].mode = mode;
    }
    else
        printf("Queue overflow\n");
    return;
}

void enuqeue2(Queue *s, int amt, int customer_id, char mode,int freq ){
    if(!isFull(s)){
        s->rare = (s->rare + 1) % MAX;
        s->n[s->rare].amt = amt;
        s->n[s->rare].customer_id = customer_id;
        s->n[s->rare].mode = mode;
        s->n[s->rare].freq = freq;
    }
    else
        printf("Queue overflow\n");
    return;
}

struct node dequeue(Queue *s){
    if(!isEmpty(s)){
        s->front = (s->front + 1) % MAX;
        return s->n[s->front];
    }
    else
        printf("Queue is empty\n");
}

void check(Queue *q){
    int cnt = 0;

    while(!isEmpty(q)){
        struct node a = dequeue(q);
        if(a.amt <= 2000 && a.freq == 1){
            printf("\nbill paid by customer id  %d\n",a.customer_id);
            printf("The number of times the customer appeared is %d\n",a.freq);
        }
        else if(a.amt <= 2000 && a.freq >1){
            a.amt -= 2000;
            printf("\nbill paid by customer id  %d\n",a.customer_id);
            printf("The number of times the customer appeared is %d\n",a.freq);
            cnt++;
        }
        else if(isEmpty(q)){
            printf("\nbill paid by customer id  %d\n",a.customer_id);
            printf("The number of times the customer appeared is %d\n",a.freq);
            cnt++;
        }
        else{
            a.amt -= 2000;
            a.freq++;
            enuqeue2(q,a.amt,a.customer_id,a.mode, a.freq);
        }
    }
    printf("\nThe persons who were in line more than once is %d\n\n",cnt);
    return;
}

int main(){
    int n;
    Queue q;
    q.front = q.rare = 0;
    printf("Enter the number of customers\n");
    scanf("%d",&n);
    for(int i=0; i<=n; i++){
        q.n[i].freq = 1;
    }
    while(n--){
        int amt, customer_id;
        char mode;
        printf("Enter the amount\n");
        scanf("%d",&amt); 
        printf("Enter the customer id\n");
        scanf("%d",&customer_id);
        printf("Enter the mode of payment card[c] or cash [h]\n");
        fflush(stdin);
        scanf("%c",&mode);
        enuqeue(&q,amt,customer_id,mode);
    }
    check(&q);
    return 0;
}