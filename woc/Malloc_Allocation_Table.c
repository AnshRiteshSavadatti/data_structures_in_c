#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 500 * 1024 * 1024 // 500MB

typedef struct MAT_Entry {
    void* address;
    size_t size;
    int is_allocated;
} MAT_Entry;

MAT_Entry* mat_table;
void* heap_start;
size_t heap_remaining;

void initialize_mat() {
    mat_table = (MAT_Entry*)malloc(sizeof(MAT_Entry) * HEAP_SIZE);
    heap_start = malloc(HEAP_SIZE);
    heap_remaining = HEAP_SIZE;

    for (int i = 0; i < HEAP_SIZE; i++) {
        mat_table[i].address = heap_start + i;
        mat_table[i].size = 1;
        mat_table[i].is_allocated = 0;
    }
}

void* my_malloc(size_t size) {
    for (int i = 0; i < HEAP_SIZE; i++) {
        if (!mat_table[i].is_allocated && mat_table[i].size >= size) {
            mat_table[i].is_allocated = 1;
            return mat_table[i].address;
        }
    }
    return NULL; // Memory allocation failed
}

void my_free(void* address) {
    for (int i = 0; i < HEAP_SIZE; i++) {
        if (mat_table[i].address == address) {
            mat_table[i].is_allocated = 0;
            return;
        }
    }
}

void view_mat() {
    printf("MAT Table:\n");
    for (int i = 0; i < HEAP_SIZE; i++) {
        printf("Address: %p, Size: %zu, Allocated: %d\n", mat_table[i].address, mat_table[i].size, mat_table[i].is_allocated);
    }
}

int main() {
    initialize_mat();

    void* ptr1 = my_malloc(100);
    void* ptr2 = my_malloc(200);

    view_mat();

    my_free(ptr1);

    view_mat();

    free(heap_start);
    free(mat_table);

    return 0;
}
