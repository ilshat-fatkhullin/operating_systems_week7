#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

size_t min(size_t a, size_t b)
{
    if (a < b)
        return a;
    return b;
}

void *new_realloc(void *ptr, size_t original_size, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    void* new_array = malloc(new_size);
    memcpy(new_array, ptr, min(original_size, new_size));
    free(ptr);
    return new_array;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

int main() {
    int n1;
    printf("Enter size of array:\n");
    scanf("%d", &n1);

    int *array = malloc(n1 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        array[i] = i;
    }

    printf("Array:\n");
    print_array(array, n1);

    int n2;
    printf("Enter new size of array:\n");
    scanf("%d", &n2);

    array = new_realloc(array, n1 * sizeof(int), n2 * sizeof(int));

    if (array == NULL) {
        printf("Reallocated array is empty\n");
    } else {
        printf("Reallocated array:\n");
        print_array(array, n2);
    }

    return 0;
}