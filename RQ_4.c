#include<stdio.h>
#include<stdlib.h>

struct node{
    int written_score;
    int technical_score;
    struct node* next;
};
typedef struct node* Node;

Node create(){
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the written score\n");
    scanf("%d",&)
}