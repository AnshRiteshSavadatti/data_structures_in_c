#include<stdio.h>
#include<stdlib.h>

int BIT[1000], a[1000], n;

void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int i;
    printf("Enter the array elements\n");
    for(i = 1; i <= n; i++)
    {
           scanf("%d", &a[i]);
           update(i, a[i]);
    }
    printf("sum of first %d elements is %d\n",n, query(n));
    printf("Enter the range\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("sum of all elements in range [%d, %d] is %d\n",a, b, query(a) - query(b));
    return 0;
}