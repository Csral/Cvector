#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/vector.h"

int main() {
    doubleVector v1;

    // Initialize the vector with a limit of 10
    double_init(&v1, 10);
    assert(v1.base.size == 0);
    assert(v1.base.limit == 10);
    printf("Initialization passed.\n");

    // Push back some elements
    double_push_back(&v1, 1.111);
    double_push_back(&v1, 2.222);
    double_push_back(&v1, 3.333);
    assert(v1.base.size == 3);
    assert(v1.data[0] == 1.111 && v1.data[1] == 2.222 && v1.data[2] == 3.333);
    printf("Push back passed.\n");

    // Access elements using `at`
    assert(double_at(&v1, 0) == 1.111);
    assert(double_at(&v1, 2) == 3.333);
    printf("Access via 'at' passed.\n");

    // Clear the vector
    double_clear(&v1);
    assert(v1.base.size == 0);
    printf("Clear passed.\n");

    // Cleanup memory
    free(v1.data);
    printf("Memory cleanup passed.\n");

    printf("All tests passed for non-class doubleVector.\n");
    return 0;
}