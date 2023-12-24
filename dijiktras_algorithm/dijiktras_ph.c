#include<stdio.h>
#include<limits.h>

int distance[10];
int path[10];
int visited[10];

void dijkstras(int cost[10][10], int v, int src){
    int j;
    visited[src] = 1;
    for(j =0; j<v-1; j++){
        int min = INT_MAX;
        int u = 0;
        for(int i=0; i<v; i++){
            if(visited[i] == 0 && distance[i] < min){
                min = distance[i];
                u = i;
            }
        }
        visited[u] = 1;
        for(int i=0; i<v; i++){
            if(visited[i] == 0 && distance[i] > cost[u][i] + distance[u]){
                distance[i] = cost[u][i] + distance[u];
                path[i] = u;
            }
        }
    }
    return;
}

void print(int v){
    for(int i=0; i<v; i++){
        printf("%d ",distance[i]);
    }
    printf("\n");
    for(int i=0; i<v; i++){
        printf("%d ",path[i]);
    }
    printf("\n");
    return;
}

int main(){
    int v;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    int cost[10][10] = {{0,3,9999,7,9999},{3,0,4,2,9999},{9999,4,0,8,6 },{7,2,8,0,4},{9999,9999,6,4,0}};
    int src;
    printf("Enter the source \n");
    scanf("%d",&src);
    for(int i=0; i<v; i++){
        distance[i] = cost[src][i];
    }
    for(int i=0; i<v; i++){
        path[i] = src;
    }
    dijkstras(cost, v, src);
    print(v);
    return 0;
}