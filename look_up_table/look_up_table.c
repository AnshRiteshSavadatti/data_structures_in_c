#include <stdio.h>

#define MAX 500

int lookup[MAX][MAX];

struct Query {
    int L, R;
};

void preprocess(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (arr[lookup[i][j - 1]] < arr[j])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = j;
    }
}

void RMQ(int arr[], int n, struct Query q[], int m)
{
    preprocess(arr, n);
    for (int i = 0; i < m; i++)
    {
        int L = q[i].L, R = q[i].R;
        printf("Minimum of [%d, %d] is %d\n", L, R, arr[lookup[L][R]]);
    }
}
int main()
{
    int n, m;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n]; 

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of queries: ");
    scanf("%d", &m);

    struct Query q[m];

    printf("Enter the queries (L R):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &q[i].L, &q[i].R);
    }

    RMQ(a, n, q, m);

    return 0;
}


// space complexity 
// time
// advantages
// disadvantages
// applications 
