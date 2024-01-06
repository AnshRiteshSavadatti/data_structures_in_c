#include<stdio.h> 
#include<stdbool.h>

int arr[10000001];
int N = 10000000;

void createSieve(){
    for(int i = 2; i <= N; i++){
        arr[i] = 1;
    }
    for(int i = 2; i*i <= N; i++){
        if(arr[i]){
            for(int j = i*i; j <= N; j += i){
                arr[j] = 0;
            }
        }
    }
    return;
}

int main(){
    createSieve();
    for(int i=0; i<100; i++){
        if(arr[i])
            printf("%d ",i);
    }
    return 0;
}