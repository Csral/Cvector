#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../includes/vector.h"

int main() {
    stringVector v1;

    // Initialize the vector with a limit of 10
    string_init(&v1, 10);
    assert(v1.base.size == 0);
    assert(v1.base.limit == 10);
    printf("Initialization passed.\n");

    // Push back some strings
    string_push_back(&v1, "Hello");
    string_push_back(&v1, "World");
    string_push_back(&v1, "Vector");
    assert(v1.base.size == 3);
    assert(strcmp(v1.data[0], "Hello") == 0);
    assert(strcmp(v1.data[1], "World") == 0);
    assert(strcmp(v1.data[2], "Vector") == 0);
    printf("Push back passed.\n");

    // Access elements using `at`
    assert(strcmp(string_at(&v1, 0), "Hello") == 0);
    assert(strcmp(string_at(&v1, 2), "Vector") == 0);
    printf("Access via 'at' passed.\n");

    // Clear the vector
    string_clear(&v1);
    assert(v1.base.size == 0);
    printf("Clear passed.\n");

    // Cleanup memory
    for (size_t i = 0; i < v1.base.size; i++) {
        free(v1.data[i]);
    }
    free(v1.data);
    printf("Memory cleanup passed.\n");

    printf("All tests passed for non-class stringVector.\n");
    return 0;
}