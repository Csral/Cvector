#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/vector.h"

int main() {
    floatVector v1;

    // Initialize the vector with a limit of 10
    float_init(&v1, 10);
    assert(v1.base.size == 0);
    assert(v1.base.limit == 10);
    printf("Initialization passed.\n");

    // Push back some elements
    float_push_back(&v1, 1.1f);
    float_push_back(&v1, 2.2f);
    float_push_back(&v1, 3.3f);
    assert(v1.base.size == 3);
    assert(v1.data[0] == 1.1f && v1.data[1] == 2.2f && v1.data[2] == 3.3f);
    printf("Push back passed.\n");

    // Access elements using `at`
    assert(float_at(&v1, 0) == 1.1f);
    assert(float_at(&v1, 2) == 3.3f);
    printf("Access via 'at' passed.\n");

    // Clear the vector
    float_clear(&v1);
    assert(v1.base.size == 0);
    printf("Clear passed.\n");

    // Cleanup memory
    free(v1.data);
    printf("Memory cleanup passed.\n");

    printf("All tests passed for non-class floatVector.\n");
    return 0;
}