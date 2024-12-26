#include <stdio.h>
#include <stdlib.h>
#include "../includes/vector.h"

// Test function for intVector
void test_int_vector() {
    printf("Testing intVector:\n");
    
    intVector v1;
    int_init(&v1, 5);

    v1.push_back(&v1, 10);
    v1.push_back(&v1, 20);
    v1.push_back(&v1, 30);
    v1.push_back(&v1, 40);

    printf("Size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("Front: %d\n", v1.front(&v1)); // Expected: 10
    printf("Back: %d\n", v1.back(&v1));  // Expected: 40
    printf("At(1): %d\n", v1.at(&v1, 1)); // Expected: 20

    v1.reverse(&v1);
    printf("After reverse, front: %d\n", v1.front(&v1)); // Expected: 40
    printf("After reverse, back: %d\n", v1.back(&v1));  // Expected: 10

    // Testing insert
    v1.insert(&v1, 2, 25);  // Insert 25 at position 2
    printf("After insert at position 2, size: %ld\n", v1.size(&v1)); // Expected: 5
    printf("At(2): %d\n", v1.at(&v1, 2)); // Expected: 25

    // Testing erase
    v1.erase(&v1, 1);  // Erase element at position 1
    printf("After erase at position 1, size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("At(1): %d\n", v1.at(&v1, 1)); // Expected: 25

    // Testing count
    printf("Count of 25: %d\n", v1.count(&v1, 25)); // Expected: 1

    // Testing find
    printf("Position of 30: %ld\n", v1.find(&v1, 30)); // Expected: position of 30
    printf("Position of 50: %ld\n", v1.find(&v1, 50)); // Expected: -1 (not found)

    v1.clear(&v1);
    printf("After clear, size: %ld\n", v1.size(&v1)); // Expected: 0
}

void test_char_vector() {
    printf("Testing char Vector:\n");
    
    charVector v1;
    char_init(&v1, 5);

    v1.push_back(&v1, 'a');
    v1.push_back(&v1, 'b');
    v1.push_back(&v1, 'c');
    v1.push_back(&v1, 'd');

    printf("Size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("Front: %c\n", v1.front(&v1)); // Expected: a
    printf("Back: %c\n", v1.back(&v1));  // Expected: d
    printf("At(1): %c\n", v1.at(&v1, 1)); // Expected: b

    v1.reverse(&v1);
    printf("After reverse, front: %c\n", v1.front(&v1)); // Expected: d
    printf("After reverse, back: %c\n", v1.back(&v1));  // Expected: a

    // Testing insert
    v1.insert(&v1, 2, 'e');  // Insert e at position 2
    printf("After insert at position 2, size: %ld\n", v1.size(&v1)); // Expected: 5
    printf("At(2): %c\n", v1.at(&v1, 2)); // Expected: e

    // Testing erase
    v1.erase(&v1, 1);  // Erase element at position 1
    printf("After erase at position 1, size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("At(1): %c\n", v1.at(&v1, 1)); // Expected: e

    // Testing count
    printf("Count of c: %d\n", v1.count(&v1, 'c')); // Expected: 0

    // Testing find
    printf("Position of a: %ld\n", v1.find(&v1, 'a')); // Expected: position of a (3)
    printf("Position of f: %ld\n", v1.find(&v1, 'f')); // Expected: -1 (not found)

    v1.clear(&v1);
    printf("After clear, size: %ld\n", v1.size(&v1)); // Expected: 0
}

void test_string_vector() {
    printf("Testing string Vector:\n");
    
    stringVector v1;
    string_init(&v1, 5);

    v1.push_back(&v1, "Hello");
    v1.push_back(&v1, "From");
    v1.push_back(&v1, "Testing");
    v1.push_back(&v1, "Program");

    printf("Size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("Front: %s\n", v1.front(&v1)); // Expected: Hello
    printf("Back: %s\n", v1.back(&v1));  // Expected: Program
    printf("At(1): %s\n", v1.at(&v1, 1)); // Expected: From

    v1.reverse(&v1);
    printf("After reverse, front: %s\n", v1.front(&v1)); // Expected: Program
    printf("After reverse, back: %s\n", v1.back(&v1));  // Expected: Hello

    // Testing insert
    v1.insert(&v1, 2, "The");  // Insert The at position 2
    printf("After insert at position 2, size: %ld\n", v1.size(&v1)); // Expected: 5
    printf("At(2): %s\n", v1.at(&v1, 2)); // Expected: The

    // Testing erase
    v1.erase(&v1, 1);  // Erase element at position 1
    printf("After erase at position 1, size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("At(1): %s\n", v1.at(&v1, 1)); // Expected: The

    // Testing count
    printf("Count of Hello: %d\n", v1.count(&v1, "Hello")); // Expected: 1

    // Testing find
    printf("Position of From: %ld\n", v1.find(&v1, "From")); // Expected: position of From
    printf("Position of To: %ld\n", v1.find(&v1, "To")); // Expected: -1 (not found)

    v1.clear(&v1);
    printf("After clear, size: %ld\n", v1.size(&v1)); // Expected: 0
}

// Test function for floatVector
void test_float_vector() {
    printf("\nTesting floatVector:\n");

    floatVector v1;
    float_init(&v1, 5);

    v1.push_back(&v1, 10.5f);
    v1.push_back(&v1, 20.5f);
    v1.push_back(&v1, 30.5f);

    printf("Size: %ld\n", v1.size(&v1)); // Expected: 3
    printf("Front: %.2f\n", v1.front(&v1)); // Expected: 10.5
    printf("Back: %.2f\n", v1.back(&v1));  // Expected: 30.5
    printf("At(1): %.2f\n", v1.at(&v1, 1)); // Expected: 20.5

    v1.reverse(&v1);
    printf("After reverse, front: %.2f\n", v1.front(&v1)); // Expected: 30.5
    printf("After reverse, back: %.2f\n", v1.back(&v1));  // Expected: 10.5

    // Testing insert
    v1.insert(&v1, 1, 25.5f);  // Insert 25.5 at position 1
    printf("After insert at position 1, size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("At(1): %.2f\n", v1.at(&v1, 1)); // Expected: 25.5

    // Testing erase
    v1.erase(&v1, 0);  // Erase element at position 0
    printf("After erase at position 0, size: %ld\n", v1.size(&v1)); // Expected: 3
    printf("At(0): %.2f\n", v1.at(&v1, 0)); // Expected: 25.5

    // Testing count
    printf("Count of 25.5: %d\n", v1.count(&v1, 25.5f)); // Expected: 1

    // Testing find
    printf("Position of 30.5: %ld\n", v1.find(&v1, 30.5f)); // Expected: position of 30.5
    printf("Position of 40.5: %ld\n", v1.find(&v1, 40.5f)); // Expected: -1 (not found)

    v1.clear(&v1);
    printf("After clear, size: %ld\n", v1.size(&v1)); // Expected: 0
}

// Test function for doubleVector
void test_double_vector() {
    printf("\nTesting doubleVector:\n");

    doubleVector v1;
    double_init(&v1, 5);

    v1.push_back(&v1, 10.75);
    v1.push_back(&v1, 20.75);
    v1.push_back(&v1, 30.75);

    printf("Size: %ld\n", v1.size(&v1)); // Expected: 3
    printf("Front: %.2f\n", v1.front(&v1)); // Expected: 10.75
    printf("Back: %.2f\n", v1.back(&v1));  // Expected: 30.75
    printf("At(1): %.2f\n", v1.at(&v1, 1)); // Expected: 20.75

    v1.reverse(&v1);
    printf("After reverse, front: %s\n", v1.front(&v1)); // Expected: 30.75
    printf("After reverse, back: %s\n", v1.back(&v1));  // Expected: 10.75

    // Testing insert
    v1.insert(&v1, 2, 25.75);  // Insert 25.75 at position 2
    printf("After insert at position 2, size: %ld\n", v1.size(&v1)); // Expected: 4
    printf("At(2): %.2f\n", v1.at(&v1, 2)); // Expected: 25.75

    // Testing erase
    v1.erase(&v1, 1);  // Erase element at position 1
    printf("After erase at position 1, size: %ld\n", v1.size(&v1)); // Expected: 3
    printf("At(1): %.2f\n", v1.at(&v1, 1)); // Expected: 25.75

    // Testing count
    printf("Count of 25.75: %d\n", v1.count(&v1, 25.75)); // Expected: 1

    // Testing find
    printf("Position of 30.75: %ld\n", v1.find(&v1, 30.75)); // Expected: position of 30.75
    printf("Position of 50.75: %ld\n", v1.find(&v1, 50.75)); // Expected: -1 (not found)

    v1.clear(&v1);
    printf("After clear, size: %ld\n", v1.size(&v1)); // Expected: 0
}

int main() {
    test_int_vector();
    test_float_vector();
    test_double_vector();
    test_char_vector();
    test_string_vector();

    return 0;
}