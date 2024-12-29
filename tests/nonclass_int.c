#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/vector.h"

int main() {
    intVector v1;

    // Initialize the vector with a limit of 10
    int_init(&v1, 10);
    assert(v1.base.size == 0);
    assert(v1.base.limit == 10);
    printf("Initialization passed.\n");

    // Push back some elements
    int_push_back(&v1, 5);
    int_push_back(&v1, 10);
    int_push_back(&v1, 15);
    assert(v1.base.size == 3);
    assert(v1.data[0] == 5 && v1.data[1] == 10 && v1.data[2] == 15);
    printf("Push back passed.\n");

    // Access elements using `at`
    assert(int_at(&v1, 0) == 5);
    assert(int_at(&v1, 2) == 15);
    printf("Access via 'at' passed.\n");

    // Check front and back
    assert(int_front(&v1) == 5);
    assert(int_back(&v1) == 15);
    printf("Front and back passed.\n");

    // Insert an element at position 1
    int_insert(&v1, 1, 7);
    assert(v1.data[1] == 7);
    assert(v1.base.size == 4);
    printf("Insertion passed.\n");

    // Erase an element at position 2
    int_erase(&v1, 2);
    assert(v1.data[2] == 15);
    assert(v1.base.size == 3);
    printf("Erase passed.\n");

    // Reverse the vector
    int_reverse(&v1);
    assert(v1.data[0] == 15 && v1.data[1] == 7 && v1.data[2] == 5);
    printf("Reverse passed.\n");

    // Find an element
    int index = int_find(&v1, 7);
    assert(index == 1);
    printf("Find passed.\n");

    // Clear the vector
    int_clear(&v1);
    assert(v1.base.size == 0);
    printf("Clear passed.\n");

    // Cleanup memory
    free(v1.data);
    printf("Memory cleanup passed.\n");

    printf("All tests passed for non-class intVector.\n");
    return 0;
}