// complete overlap 
// no overlap
// partial overlap
#include<bits/stdc++.h>

int maxi = 10000;

int cal_length(int n){
    int nearest =  pow(2, ceil(log2(n)));
    return (2*nearest) -1;
}

void init(int arr[]){
    for(int i=0; i<maxi; i++){
        arr[i] = INT_MIN;
    }
}

int right(int pos){
    return (pos*2)+1;
}

int left(int pos){
    return (pos*2)+2;
}

void create(int arr[], int low, int high, int pos, int segTree[]){
    if(low == high){
        segTree[pos] = arr[low];
    }
    int mid = (low + high)/2;
    create(arr,low,mid,(2*pos)+1,segTree);
    create(arr,low,mid+1,(2*pos)+2,segTree);
    segTree[pos] = max(segTree[left(pos)], segTree[right(pos)]);
}

int query_max(int segTree[], int low, int high, int qlow, int qhigh, int pos){
    if(low >= qlow && high <= qhigh){
        return segTree[pos];
    }
    // condition for no overlap
    if(high <= qlow && low > qhigh){
        return INT_MIN;
    }
    int mid = (low + high)/2;\
    return max(query_max)
}

