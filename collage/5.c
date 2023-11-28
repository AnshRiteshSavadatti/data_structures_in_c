#include <stdio.h>
#include<time.h>

int main() {
    int n =0;
    while (n < 20)
    {
        printf("LEFT\n");
        sleep(1);
        for (int i = 0; i < 75; i++) {
            printf(" ");
        }
        printf("RIGHT\n");
        sleep(1);
        n++;
    }
    
}