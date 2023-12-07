#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct recommendation_data
{
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
};

struct data
{
    char movie_name[30];
    int viewers;
};
typedef struct data D;
D o[200];
typedef struct recommendation_data RD;
RD search_list[200];
int global_count = 0;

/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/
void welcome()
{
    int  i = 0;
    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n\t\t\t\tRECOMMENDATION ENGINE\n\n\n");

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n");

}

/**
Function Name: load_from_file
Input Params: NILL
Return Type: void
Description: loads all the data available with recommendation engine into appropriate data structure
**/
void load_from_file()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("MovieIndex.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d", search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                &search_list[global_count].viewers);
        printf("%s %s %d\n",search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                search_list[global_count].viewers);
        global_count++;
    }

    fclose(fp);
}

int BruteForceStringMatch(char t[],char p[],int n,int m)
{
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j < m && p[j]== t[i+j]){
            j++;
        }
        if(j==m)
            return i;
    }
    return -1;
}

int input(){
    printf("Enter search:\n");
    char p[50];
    scanf("%[^\n]s",&p);
    int k=0;
    for(int i=0;i<global_count;i++){
        int n=strlen(search_list[i].movie_name);
        int m=strlen(p);
        if(BruteForceStringMatch(search_list[i].movie_name,p,n,m)!=-1)
        {
            strcpy(o[k].movie_name, search_list[i].recommendation_name);
            o[k].viewers = search_list[i].viewers;
            k++;
        }
    }
    return k;
}

void display(int n){
    printf("The movie recommendations are:\n");
    for(int i=0;i<n;i++){
        printf("%s\n",o[i].movie_name);
    }
}

// void sort(int n)
// {
//     int temp;
//     for(int i=0; i<n-2;i++){
//         for(int j=0;j<n-2-1;j++){
//             if(o[j+1].viewers<o[j].viewers){
//                 temp=o[j+1].viewers;
//                 o[j+1]=o[j].viewers;
//                 o[j].viewers=temp;
//             }
//         }
//     }
// }

int main()
{

    welcome();
    load_from_file();
    int n= input();
    // sort(n);
    display(n);


    // TODO

    return 0;
}