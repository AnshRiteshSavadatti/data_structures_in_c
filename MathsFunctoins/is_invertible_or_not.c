#include <stdio.h>
#include <stdbool.h>

// Function to check if the given function is one-to-one (injective)
bool isOneToOne(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                return false;  // Found two different inputs mapping to the same output
            }
        }
    }
    return true;  // No two different inputs map to the same output
}

// Function to check if the given function is onto (surjective)
bool isOnto(int arr[], int size, int codomainSize) {
    bool mapped[codomainSize];
    for (int i = 0; i < codomainSize; ++i) {
        mapped[i] = false;
    }

    for (int i = 0; i < size; ++i) {
        int mappedElement = arr[i];

        if (mappedElement < 0 || mappedElement >= codomainSize) {
            printf("Invalid mapping detected.\n");
            return false;
        }

        mapped[mappedElement] = true;
    }

    for (int i = 0; i < codomainSize; ++i) {
        if (!mapped[i]) {
            return false;
        }
    }

    return true;
}

// Function to check if the given function is invertible
bool isInverse(int arr[], int size, int codomainSize) {
    return isOneToOne(arr, size) && isOnto(arr, size, codomainSize);
}

int main() {
    int codomainSize, size;

    // Get the size of the codomain and the size of the function from the user
    printf("Enter the size of the codomain: ");
    scanf("%d", &codomainSize);

    printf("Enter the size of the function: ");
    scanf("%d", &size);

    // Declare an array to represent the function
    int functionArray[size];

    // Get the mapping from the user
    printf("Enter the mapping from domain to codomain:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &functionArray[i]);
    }

    // Check if the function has an inverse and display the result
    if (isInverse(functionArray, size, codomainSize)) {
        printf("The function has an inverse.\n");
    } else {
        printf("The function does not have an inverse.\n");
    }

    return 0;
}