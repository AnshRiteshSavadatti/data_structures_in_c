#include<stdio.h>

typedef struct node{
    int u;
    int v;
    int w;
}NODE;

NODE edges[30];

void input(NODE edges[], int n){
    for(int i=0; i<n; i++){
        scanf("%d%d%d",&edges[i].u, &edges[i].v, &edges[i].w);
    }
    return;
}

void sort(NODE edges[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(edges[j].w > edges[j+1].w){
                NODE t = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = t;
            }
        }
    }
    return;
}

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

int kruskals(NODE edges[], int n, int arr[]){
    int sum = 0;
    for(int i=0; i<n; i++){
        if(!find(arr, edges[i].u, edges[i].v)){
            union_(arr, 10, edges[i].u, edges[i].v);
            sum += edges[i].w;
            printf("%d %d\n",edges[i].u, edges[i].v);
        }
    }
    printf("\n");
    return sum;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    return;
}


int main(){
    int n;
    printf("Enter the number of edges\n");
    scanf("%d",&n);
    input(edges, n);
    sort(edges, n);
    int arr[8];
    for(int i=0; i<8; i++){
        arr[i] = i;
    }
    printf("The edges are\n");
    int ans = kruskals(edges, n, arr);
    // print(arr, 8);
    printf("\nThe total weight is %d",ans);
    return 0;
}


// THE INPUT IS 
// 14
// 6 7 2
// 2 8 4
// 5 6 4
// 0 1 8
// 2 3 8 
// 6 8 17
// 2 3 14
// 7 8 14
// 0 7 16 
// 1 2 16
// 3 4 18
// 4 5 20
// 1 7 22
// 3 5 28 
