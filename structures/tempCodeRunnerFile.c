
// class test problem
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct information{
    int age;
    int salary;
    float exp;
    char name[20];
    char employee_ID[20];
}inf;

void read(inf *ptr, int n){
    for(int i=0; i<n; i++){
    printf("Enter the age ");
    scanf("%d",&ptr->age);
    printf("Enter the salary");
    scanf("%d",&ptr->salary);
    printf("Enter the experiance");
    scanf("%f",&ptr->exp);
    printf("Enter the name");
    scanf("%s",ptr->name);
    printf("Enter the employee_id");
    scanf("%s",ptr->employee_ID);
    ptr++;
    }
}

void display(inf * ptr, int n){
    for(int i=0; i<n; i++){
    printf("%d\n",ptr->age);
    printf("%d\n",ptr->salary);
    printf("%f\n",ptr->exp);
    printf("%s\n",ptr->name);
    printf("%s\n",ptr->employee_ID);
    printf("\n");
    ptr++;
    }
}

void sort(inf * ptr, int n){
   for (int i = 0; i < n-1; i++)
   {
    for (int j = 0; j < n-1-i; j++)
    {
        if((ptr+j)->exp > (ptr+j+1)->exp){
            inf temp = *(ptr+j);
            *(ptr+j) = *(ptr+j+1);
            *(ptr+j+1) = temp;
        }
    }
    
   }
   
}

void bonus(inf* ptr ,int n){
    for(int i=0; i<n; i++){
        if(ptr->exp >= 10){
            ptr->salary += (0.1*ptr->salary);
        }
        ptr++;
    }
}

int main(){
    int n; 
    printf("Enter the value of n");
    scanf("%d",&n);
    inf *ptr;
    ptr = (inf*)malloc(n*sizeof(inf));
    read(ptr, n);
    display(ptr,n);
    sort(ptr, n);
    display(ptr,n);
    bonus(ptr,n);
    display(ptr,n);
    return 0;
}




