#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/vector.h"

int main() {
    charVector v1;

    // Initialize the vector with a limit of 10
    char_init(&v1, 10);
    assert(v1.base.size == 0);
    assert(v1.base.limit == 10);
    printf("Initialization passed.\n");

    // Push back some characters
    char_push_back(&v1, 'A');
    char_push_back(&v1, 'B');
    char_push_back(&v1, 'C');
    assert(v1.base.size == 3);
    assert(v1.data[0] == 'A' && v1.data[1] == 'B' && v1.data[2] == 'C');
    printf("Push back passed.\n");

    // Access elements using `at`
    assert(char_at(&v1, 0) == 'A');
    assert(char_at(&v1, 2) == 'C');
    printf("Access via 'at' passed.\n");

    // Clear the vector
    char_clear(&v1);
    assert(v1.base.size == 0);
    printf("Clear passed.\n");

    // Cleanup memory
    free(v1.data);
    printf("Memory cleanup passed.\n");

    printf("All tests passed for non-class charVector.\n");
    return 0;
}