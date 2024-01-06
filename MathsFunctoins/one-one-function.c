#include<stdio.h>

void check(int output[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=(i+1);j<n;j++)
        {
            if(output[i]==output[j])
            {
                 printf("The given function is not one one\n");
                 break;
            }
        }
    }
}
int main()
{
    // check if the function f(x)=x+3 is one one or no for x in the range [1,5]
    int output[100];
    //take the input of all the values of f(x) like 4 5 6 7 8
    for(int i=0;i<5;i++)
    {
        scanf("%d",&output[i]);
    }
    check(output,5);
}