#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 500 * 1024 * 1024

static void* heap_start;

void initialize_heap() {
    heap_start = malloc(HEAP_SIZE);
    if (!heap_start) exit(1);
}

void* my_malloc(size_t size) {
    void* ptr = heap_start;
    while (*(int*)ptr && *(size_t*)((char*)ptr + 4) < size) ptr = (char*)ptr + 12 + *(size_t*)((char*)ptr + 8);
    if (!*(int*)ptr) {
        *(int*)ptr = 1;
        *(size_t*)((char*)ptr + 4) = size;
        return (char*)ptr + 8;
    }
    return NULL;
}

void my_free(void* ptr) {
    if (!ptr) return;
    ptr = (char*)ptr - 8;
    if (*(int*)ptr == 1) {
        *(int*)ptr = 0;
        *(size_t*)((char*)ptr + 4) = 0;
    }
}

int main() {
    initialize_heap();

    int choice;
    size_t size;
    void* ptr;

    while (1) {
        printf("1. my_malloc\n2. my_free\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size to allocate: ");
                scanf("%zu", &size);
                ptr = my_malloc(size);
                if (ptr) printf("Memory allocated at address: %p\n", ptr);
                else printf("Allocation failed. No suitable block found.\n");
                break;
            case 2:
                printf("Enter the address to free: ");
                scanf("%p", &ptr);
                my_free(ptr);
                printf("Memory freed at address: %p\n", ptr);
                break;
            case 3:
                free(heap_start);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
