#include<stdio.h>

int find(int arr[], int u, int v){
    if(arr[u] == arr[v])
        return 1;
    return 0;
}

void union_(int arr[], int n, int u, int v){
    int temp = arr[u];
    for(int i=0; i<n; i++){
        if(arr[i] == temp)
            arr[i] = arr[v];
    }
    return;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    return;
}   

int main(){
    int arr[10];
    for(int i=0; i<10; i++){
        arr[i] = i;
    }
    
    if(!find(arr,2,3)){
        union_(arr, 10, 2, 3);
    }
    if(!find(arr,3,2)){
        union_(arr, 10, 3, 2);
    }
    if(!find(arr,6,7)){
        union_(arr, 10, 6, 7);
    }
    if(!find(arr,2,0)){
        union_(arr, 10, 2, 0);
    }
    print(arr, 10);

    return 0;
}