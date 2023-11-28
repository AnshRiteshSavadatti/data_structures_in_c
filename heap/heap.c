#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void heapfy(int h[], int n){
    for(int i=n/2; i>=1; i--){
        int k = i;
        int v = h[k];
        bool flag = false;
        while(!flag && 2*k <= n){
            int j = 2*k;
            if(j < n){
                if(h[j] < h[j+1])
                    j = j+1;
            }
                if(v >= h[j])
                    flag = true;
                else{
                    h[k] = h[j];
                    k=j;
                }
        }
        h[k] = v;
        fflush(stdin);
    }
    return;
}

void print(int arr[], int n){
    for(int i=1; i<=n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}

int insert(int n, int data, int arr[]){
    if(n < 1000){
        n++;
        arr[n] = data;
        fflush(stdin);
        heapfy(arr, n);
        fflush(stdin);
        return n;
    }
    printf("Heap is full\n");
    return n;
}

int delete(int arr[], int n){
    if(n <= 0){
        printf("Heap is empty\n");
        return -1;
    }
    else{
        printf("The value which is deleted is %d",arr[1]);
        arr[1] = arr[n];
        n--;
        fflush(stdin);
        heapfy(arr, n);
        fflush(stdin);
        return n;
    }
}

int main(){
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    int h[1000];
    printf("Enter the heap elements\n");
    for(int i=1; i<=n; i++){
        fflush(stdin);
        scanf("%d",&h[i]);
    }
    heapfy(h, n);
    int ch;
    int data;
    while(1){
        printf("Enter\n1 to insert number into heap\n");
        printf("2 to delete a number in heap\n");
        printf("3 to print the heap");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter the number which is to be inserted\n");
                scanf("%d",&data);
                insert(n,data,h);
                break;
            case 2:
                n = delete(h,n);
                break;
            case 3:
                print(h, n);
                break;
            default :
                exit(0);
        }
    }
    
    return 0;
}