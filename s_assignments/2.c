#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node* Node;

Node create(){
    Node newnode = (Node) malloc(sizeof(struct Node));
    if(newnode == NULL){
        return NULL;
    }
    newnode->next = NULL;
    return newnode;
}

Node insert_at_end(Node head, int data){
    Node newnode = create();
    newnode->data = data;
    if(head == NULL)
        head = newnode;
    else{
        Node temp = head;
        while(temp->next != NULL){
            temp = temp ->next;
        }
        temp->next = newnode;
    }
    return head;
}

Node delete(Node head, Node curr, Node prv){
    if(head == curr){
        head = head->next;
        free(curr);
        return head;
    }
    prv->next = curr->next;
    free(curr);
    return head;
}

Node delete_end(Node head){
    Node temp = head;
    Node prv = NULL;
    while(temp->next != NULL){
        prv = temp;
        temp = temp ->next;
    }
    prv->next = NULL;
    free(temp);
    return head;
}

Node remove_friend(Node head, int K, int N){
   Node prv = NULL;
   Node temp = head;
   int c = 0;
   while (temp->next != NULL && c < K){
        if(temp->next != NULL && temp->data < temp->next->data  ){
            Node t = temp;
            head = delete(head,temp,prv);
            temp = t;
            ++c;
        }
        if(c == K){
            printf("yo\n");
            return head;
        
        }

        prv = temp;
        temp = temp->next;
   }
   if(c < K){
    while(c < K){
        head = delete_end(head);
        c++;
    }
   }
   return head;
}

void prin(Node head){
    Node temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}


int main()
{   
    int T;
    printf("The no. of test cases are:\n");
    fflush(stdin);
    scanf("%d",&T);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    // Clear the input buffer
    }  
    
    while(T--){
        Node head = NULL;
        int N;
        int data;
        printf("The no. of friends in her list are:\n");
        fflush(stdin);
        scanf("%d",&N);

        int K;
        printf("The no of friends she decides to delete are:\n");
        fflush(stdin);
        scanf("%d",&K);

        printf("Enter the popularity of each friend\n");
        for(int i=0;i<N;i++){   
            scanf("%d",&data);
            head = insert_at_end(head, data);
        }
        prin(head);
        head = remove_friend(head,K,N);
        printf("\n");
        prin(head);
    }
    return 0;
    
}