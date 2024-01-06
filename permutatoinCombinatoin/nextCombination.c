// #include <stdio.h>

// void printCombination(int arr[], int n, int r) {
//     for (int i = 0; i < r; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int nextCombination(int arr[], int n, int r) {
//     for (int i = r - 1; i >= 0; i--) {
//         if (arr[i] < n - r + i + 1) {
//             arr[i]++;
//             for (int j = i + 1; j < r; j++) {
//                 arr[j] = arr[j - 1] + 1;
//             }
//             return 1;  // Next combination found
//         }
//     }
//     return 0;  // No more combinations
// }

// int main() {
//     int n = 5; // Change n to the size of your set
//     int r = 3; // Change r to the size of combinations you want

//     int combination[r];
//     for (int i = 0; i < r; i++) {
//         combination[i] = i + 1; // Initialize the first combination (1, 2, ..., r)
//     }

//     do {
//         printCombination(combination, n, r);
//     } while (nextCombination(combination, n, r));

//     return 0;
// }


#include<stdio.h>

void generate(int a[], int r, int n) {
    int i = r - 1;
    while (i >= 0 && a[i] == (n - r + (i + 1))) {
        i--;
    }

    if (i >= 0) {
        a[i] = a[i] + 1;
        for (int j = i + 1; j < r; j++) {
            a[j] = a[i] + j - i;
        }
    }
}

int main() {
    int n;
    printf("The size of the set is:\n");
    scanf("%d", &n);
    
    int set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int r;
    printf("The sequence size is:\n");
    scanf("%d", &r);
    
    int a[r];
    for (int i = 0; i < r; i++) {
        scanf("%d", &a[i]);
    }

    generate(a, r, n);

    printf("Next lexicographically greater combination: ");
    for (int i = 0; i < r; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}