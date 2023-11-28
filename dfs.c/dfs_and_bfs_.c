#include<stdio.h>
#include<stdlib.h>

int visited[10] = {0};

void dfs(int m[10][10], int v, int source){
    visited[source] = 1;
    for(int i=0; i<v; i++){
        if(m[source][i] == 1 && visited[i] == 0){
            printf("%d\t",i);
            dfs(m, v, i);
        }
    }
    return;
}

void bfs(int m[10][10], int v, int source){
    int q[10];
    int f = 0, r = 0;
    q[r] = source;
    visited[source] = 1;

    while(f <= r){
        int u = q[f];
        printf("%d\t",u);
        f++;

        for(int i=0; i<v; i++){
            if(m[u][i] == 1 && visited[i] == 0){
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }

}

int main(){
    int v = 5;
    int m[10][10] = {{0,1,1,0,0}, {1,0,0,1,1},{1,0,0,0,1}, {0,1,0,0,0}, {0,1,1,0,0}};
    int source;
    printf("Enter the source\n");
    scanf("%d",&source);
    if(source < 0 || source > v ){
        printf("Invalid Input\n");
        return -1;
    }
    printf("Enter\n1 for dfs\n2 for bfs\n");
    int ch;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("The dfs travels is \n");
        printf("%d\t",source);
        dfs(m, v, source);
        break;
    case 2:
        printf("The bfs travel is \n");
        bfs(m, v, source);
        break;
    
    default:
        break;
    }
    
    return 0;
    
}