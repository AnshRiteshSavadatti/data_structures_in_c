#include<stdio.h>
#include<string.h>

int nextBitString(char s[]){
    int i = strlen(s) -1;
    for(; i>=0; i--){
        if(s[i] == '1'){
            s[i] = '0';
        }else{
            s[i] = '1';
            break;
        }
    }
    if(i < 0){
        return 0;
    }
    printf("%s\n",s);
    return 1;
}

int main(){
    char ch[] = "100";
    while(nextBitString(ch));
    return 0;
}