#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct engine_data
{
    int priority;
    char search_feed[150];
};
struct search_engine
{
    int priority1;
    char search_feed1[150];
};
typedef struct engine_data ED;
typedef struct search_engine ED1;
ED search_list[300];
ED1 sort_list[300];
int global_count = 0;
int iter=0;

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

    printf("\n\n\t\t\t\tIII SEARCH ENGINE\n\n\n");

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n");

}

/**
Function Name: load_from_file
Input Params: NILL
Return Type: void
Description: loads all the data available with search engine into appropriate data structure
**/

void load_from_file()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("SearchIndex.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        //take all the inputs from the user untill the user clicks on enter
        fscanf(fp,"%d\t%[^\n]s", &search_list[global_count].priority, search_list[global_count].search_feed);
        printf("%d\t%s\n", search_list[global_count].priority, search_list[global_count].search_feed);
        global_count++;
    }

    fclose(fp);
}
int brute_force_string_match(char T[],int n,char P[],int m)
{

         for(int i=0;i<n-m;i++)
         {
             int j=0;
             while(j<m && P[j]==T[i+j])
             {
                 j=j+1;
             }
             if(j==m)
             {

                 return i;
             }
         }

     return -1;
}
int count_words(char P[],int m) {
    int wordCount = 0;
    int Word=0;

    for (int i = 0; P[i] != '\0'; i++) {
        if (P[i] == ' ' || P[i] == '\t' || P[i] == '\n') {
            Word = 0;
        }
        else if (!Word) {
            Word = 1;
            wordCount++;
        }
    }

    return wordCount;
}
void display()
{

    for(int i=0;i<iter;i++)
    {
        printf("%d\n",sort_list[i].priority1);
        printf("%s\n",sort_list[i].search_feed1);
    }
}

int bubble_sort()
{
    ED1 temp;
    for(int i=0;i<(iter-2);i++)
    {
        for(int j=0;j<(iter-1-i);j++)
        {
            if(sort_list[j+1].priority1<sort_list[j].priority1)
            {

                temp = sort_list[j+1];
                sort_list[j+1] = sort_list[j];
                sort_list[j] = temp;

            }
        }
    }
    printf("sorted array is=\n");
    display();
}

void pattern_processing(char P[],int m)
{

    int k,output,word_count;
    word_count=count_words(P,m);

    if(word_count>2)
    {
        printf("please enter 1 or 2 words\n");
    }
    for(k=0;k<global_count;k++)
    {

         output=brute_force_string_match(search_list[k].search_feed,strlen(search_list[k].search_feed),P,strlen(P));

         if(output!=-1)
         {
              strcpy(sort_list[iter].search_feed1,search_list[k].search_feed);
              sort_list[iter].priority1=search_list[k].priority;
              iter++;
          }
    }

    printf("\n");
}
int main()
{
    welcome();
    load_from_file();
    char P[100];
    char choice;
    printf("enter the pattern to be matched with the text=\n");
    scanf("%s",P);
    pattern_processing(P,strlen(P));
    while(1)
    {

        printf("Y.Do u want to enter next pattern to match with text[YES]\n");
        printf("N.do not want to enter next pattern[NO]\n");
        printf("enter your choice=\n");
          scanf("%s",&choice);
        switch(choice)
        {
         case 'Y':
            printf("enter the pattern to be matched with the text=\n");
            scanf("%s",P);
            pattern_processing(P,strlen(P));
            break;


         case 'N':
             printf("Not interested to search for any other string\n");
             bubble_sort();
             exit(0);
             break;

         default:
            printf("invalid choice\n");
            exit(0);

        }

    }
    return 0;
}