#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

struct recommendation_data
{
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
};

typedef struct recommendation_data RD;
RD search_list[200];
int global_count = 0;

typedef struct mydata{
    char recommendation_name[30];
    int viewers;
}md;

md o[100];

typedef struct most_viewed
{
    char movie_name1[30];
    int viewers;
}MV;

MV arr[10];

/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/ 
// strupy

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


// here p is the user input and t is movie
int BruteForceStringMatch(char t[], char p[], int n, int m){
    for(int i = 0; i <= n-m; i++){
        int j = 0;
        while(j < m && p[j] == t[i+j]){
            j++;   
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}


int StringSize(char arr[]){
    return strlen(arr);
}

void convertToLowerCase(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int recommend(){
    char s[20];
    printf("Enter the movie to be suggested\n");
    scanf("%[^\n]s",&s);
    int i = 0;
    while (s[i] != '\0') {
        s[i] = tolower(s[i]);
        i++;
    }
    for(int i=0; i<strlen(s); i++){
        if(s[i] == ' '){
            s[i] = '-';
        }
    }

    int c = 0;
    for(int i=0; i<global_count; i++){
        int s1 = strlen(s);
        int s2 = strlen(search_list[i].movie_name);
        if(BruteForceStringMatch(search_list[i].movie_name, s, s2, s1) >= 0){
            strcpy(o[c].recommendation_name, search_list[i].recommendation_name);
            o[c].viewers = search_list[i].viewers;
            c++;
        }
    }
    return c;
}


void merge(MV arr[], int n, MV arr1[], int s1, MV arr2[], int s2) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < s1 && j < s2) {
        if (arr1[i].viewers >= arr2[j].viewers) { 
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < s2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return;
}


void MergeSort(MV arr[], int n) {
    if (n <= 1) {
        return;
    }

    int s1 = n/2;
    int s2 = n - s1;

    MV arr1[s1];
    MV arr2[s2];
    for(int i=0; i<s1; i++){
        arr1[i] = arr[i];
    }
    for(int i=0; i<s2; i++){
        arr2[i] = arr[i + s1];
    }

        MergeSort(arr1, s1);
        MergeSort(arr2, s2);


    return merge(arr, n, arr1, s1, arr2, s2);
}

void convertToUpperCase(char str[]) {
    char * str1 = str;
    while (*str1) {
        if(*str1 == '-'){
            *str1 = ' ';
        }
        *str1 = toupper(*str1);
        str1++;
    }
    printf("%s\n",str);
    return;
}

void fiter(int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if (strcmp(o[i].recommendation_name, o[j].recommendation_name) == 0 && o[j].viewers > 0){
                o[j].viewers = 0;
            }
        }
    }
    return;
}

void display(int c){
    for(int i=0; i<80 ; i++)
        printf("*");
    printf("\n");
    printf("The recommended movies are \n");
    for(int i=0; i<c; i++){
        convertToUpperCase(o[i].recommendation_name);
    }
    return;
}
void merge_descending(RD arr[], int n, RD arr1[], int s1, RD arr2[], int s2) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < s1 && j < s2) {
        if (arr1[i].viewers >= arr2[j].viewers) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < s2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort_descending(RD arr[], int n) {
    if (n <= 1) {
        return;
    }

    int s1 = n / 2;
    int s2 = n - s1;

    RD arr1[s1];
    RD arr2[s2];

    for (int i = 0; i < s1; i++) {
        arr1[i] = arr[i];
    }

    for (int i = 0; i < s2; i++) {
        arr2[i] = arr[i + s1];
    }


    mergeSort_descending(arr1, s1);
    mergeSort_descending(arr2, s2);

    return merge_descending(arr, n, arr1, s1, arr2, s2);
}

void insert_in_MV() {
    int c = 0;
    for(int i = 0; i < 3; i++){
        arr[c].viewers = search_list[i].viewers;
        strcpy(arr[c++].movie_name1, search_list[i].movie_name);
        arr[c].viewers = search_list[i].viewers;
        strcpy(arr[c++].movie_name1, search_list[i].recommendation_name);
    }
    return;
}

void display_trending(){
    for(int i=0; i<80 ; i++)
        printf("*");
    printf("\n");
    printf("The Most Watched movies are \n\n");
    for(int i=0; i<6 && arr[i].viewers > 0; i++){
        convertToUpperCase(arr[i].movie_name1);
    }
    return;
}

void filter_MV(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if ((strcmp(arr[i].movie_name1, arr[j].movie_name1) == 0   ) && arr[j].viewers > 0){
                arr[j].viewers = 0;
            }
        }
    }
    return;
}


int main()
{
    
    welcome();
    load_from_file();
    mergeSort_descending(search_list, global_count);
    insert_in_MV();
    filter_MV(6);
    display_trending();
    printf("\n");
    int n = recommend();
    MergeSort(arr, n);
    if(n == 0){
        printf("\nThere no such movie avaliable\n");
        printf("Please check the spelling\n");
        printf("Thank-You");
    }
    else
        display(n);

    // TODO

    return 0;
}


// MODIFICATIONS 
// Case-Insensitive Comparison:
// Make the string comparison case-insensitive for more robust search 
// results. Converting both strings to lowercase before comparing
// Added a mostwatched feature
