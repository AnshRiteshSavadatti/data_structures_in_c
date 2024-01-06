#include<stdio.h>
#include<string.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int nextPermutation(char s[]){
    int k = strlen(s) -1;
    for(; k > 0; k--){
        if(s[k] > s[k-1]){
            break;
        }
    }
    if(k == 0){
        return 0;
    }
    k--;
    int j = strlen(s);
    for( ; j > k; j--){
        if(s[k] < s[j]){
            break;
        }
    }
    swap(&s[k], &s[j]);
    k++;
    int l = strlen(s) -1;
    while(k < l){
        swap(&s[k], &s[l]);
        k++; l--;
    }
    printf("%s\n", s);
    return 1;
}

int main(){
    char s[] = "abcd";
    printf("%s\n",s);
    while (nextPermutation(s));
    return 0;
}
