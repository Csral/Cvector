#pragma once

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#include <math.h>

// ------------------------------------------------------- ERRORS ------------------------------------------------------------- //

jmp_buf env;

void err_handler(const char* msg) {

    printf("Error: %s\n", msg);

    longjmp(env,1);

};

// ------------------------------------------------------- VECTORS MAIN ------------------------------------------------------------- //

struct vector_base {

    long int size;
    long int limit;

};

typedef struct vector_base vectorBase;

typedef struct intvector intVector;
typedef struct floatvector floatVector;
typedef struct doublevector doubleVector;
typedef struct charvector charVector;
typedef struct stringvector stringVector;
typedef struct cintvector cintVector;
typedef struct cfloatvector cfloatVector;
typedef struct cdoublevector cdoubleVector;
typedef struct ccharvector ccharVector;
typedef struct cstringvector cstringVector;

// ------------------------------------------------------ NON CLASS ---------------------------------------------------------------- //

struct intvector {

    vectorBase base;
    int* data;

};

struct floatvector {

    vectorBase base;
    float* data;

};

struct doublevector {

    vectorBase base;
    double* data;

};

struct charvector {

    vectorBase base;
    char* data;

};

struct stringvector {

    vectorBase base;
    char** data;

};

// -------------------------------------------------------- CLASS ------------------------------------------------------------------ //

struct cintvector {

    intVector main;
    void (*push_back)(intVector* vec, int value);
    void (*pop_back)(intVector* vec);
    int (*at)(intVector* vec, long int pos);
    int (*front)(intVector* vec);
    int (*back)(intVector* vec);
    long int (*size)(intVector* vec);
    void (*insert)(intVector* vec, long int pos, int value);
    void (*erase)(intVector* vec, long int pos);
    void (*clear)(intVector* vec);
    long int (*count)(intVector* vec, int searcher);
    int* (*getData)(intVector* vec);
    void (*reverse)(intVector* vec);
    long int (*find)(intVector* vec, int finder);
    void (*shrink_to_fit)(intVector* vec, long int offset);
    void (*resize)(intVector* vec, long int offset, int init);
    void (*reserve)(intVector* vec, long int space);
    long int (*capacity)(intVector* vec);

};

struct cfloatvector {

    floatVector main;
    void (*push_back)(floatVector* vec, float value);
    void (*pop_back)(floatVector* vec);
    float (*at)(floatVector* vec, long int pos);
    float (*front)(floatVector* vec);
    float (*back)(floatVector* vec);
    long int (*size)(floatVector* vec);
    void (*insert)(floatVector* vec, long int pos, float value);
    void (*erase)(floatVector* vec, long int pos);
    void (*clear)(floatVector* vec);
    long int (*count)(floatVector* vec, float searcher);
    float* (*getData)(floatVector* vec);
    void (*reverse)(floatVector* vec);
    long int (*find)(floatVector* vec, float finder);
    void (*shrink_to_fit)(floatVector* vec, long int offset);
    void (*resize)(floatVector* vec, long int offset, float init);
    void (*reserve)(intVector* vec, long int space);
    long int (*capacity)(floatVector* vec);

};

struct cdoublevector {

    doubleVector main;
    void (*push_back)(doubleVector* vec, double value);
    void (*pop_back)(doubleVector* vec);
    double (*at)(doubleVector* vec, long int pos);
    double (*front)(doubleVector* vec);
    double (*back)(doubleVector* vec);
    long int (*size)(doubleVector* vec);
    void (*insert)(doubleVector* vec, long int pos, double value);
    void (*erase)(doubleVector* vec, long int pos);
    void (*clear)(doubleVector* vec);
    long int (*count)(doubleVector* vec, double searcher);
    double* (*getData)(doubleVector* vec);
    void (*reverse)(doubleVector* vec);
    long int (*find)(doubleVector* vec, double finder);
    void (*shrink_to_fit)(doubleVector* vec, long int offset);
    void (*resize)(doubleVector* vec, long int offset, double init);
    void (*reserve)(intVector* vec, long int space);
    long int (*capacity)(doubleVector* vec);

};

struct ccharvector {

    charVector main;
    void (*push_back)(charVector* vec, char value);
    void (*pop_back)(charVector* vec);
    char (*at)(charVector* vec, long int pos);
    char (*front)(charVector* vec);
    char (*back)(charVector* vec);
    long int (*size)(charVector* vec);
    void (*insert)(charVector* vec, long int pos, char value);
    void (*erase)(charVector* vec, long int pos);
    void (*clear)(charVector* vec);
    long int (*count)(charVector* vec, char searcher);
    char* (*getData)(charVector* vec);
    void (*reverse)(charVector* vec);
    long int (*find)(charVector* vec, char finder);
    void (*shrink_to_fit)(charVector* vec, long int offset);
    void (*resize)(charVector* vec, long int offset, char init);
    void (*reserve)(intVector* vec, long int space);
    long int (*capacity)(charVector* vec);

};

struct cstringvector {

    stringVector main;
    void (*push_back)(stringVector* vec, char* value);
    void (*pop_back)(stringVector* vec);
    char* (*at)(stringVector* vec, long int pos);
    char* (*front)(stringVector* vec);
    char* (*back)(stringVector* vec);
    long int (*size)(stringVector* vec);
    void (*insert)(stringVector* vec, long int pos, char* value);
    void (*erase)(stringVector* vec, long int pos);
    void (*clear)(stringVector* vec);
    long int (*count)(stringVector* vec, char* searcher);
    char** (*getData)(stringVector* vec);
    void (*reverse)(stringVector* vec);
    long int (*find)(stringVector* vec, char* finder);
    void (*shrink_to_fit)(stringVector* vec, long int offset);
    void (*resize)(stringVector* vec, long int offset, char* init);
    void (*reserve)(intVector* vec, long int space);
    long int (*capacity)(stringVector* vec);

};

// ------------------------------------------------------- POP BACK ------------------------------------------------------------- //

void int_pop_back(intVector* vec) {

    if (vec->base.size == 0) return;

    vec->data[vec->base.size] = 0;
    vec->base.size -= 1; // ! Pop out

};

void float_pop_back(floatVector* vec) {

    if (vec->base.size == 0) return;

    vec->data[vec->base.size] = 0.00;
    vec->base.size -= 1; // ! Pop out

};

void double_pop_back(doubleVector* vec) {

    if (vec->base.size == 0) return;

    vec->data[vec->base.size] = 0.000;
    vec->base.size -= 1; // ! Pop out

};

void char_pop_back(charVector* vec) {

    if (vec->base.size == 0) return;

    vec->data[vec->base.size] = '\0';
    vec->base.size -= 1; // ! Pop out

};

void string_pop_back(stringVector* vec) {

    if (vec->base.size == 0) return;

    vec->data[vec->base.size] = "";
    vec->base.size -= 1; // ! Pop out

};

// ------------------------------------------------------- PUSH BACK ------------------------------------------------------------- //

void int_push_back(intVector* vec, int value) {

    if (vec->base.size == (vec->base.limit - 1) ) {
        
        vec->base.limit *= 2;
        vec->data = (int*)realloc(vec->data, vec->base.limit*sizeof(int));
        if (vec->data == NULL) {
            perror("Error expanding vector: ");
            exit(EXIT_FAILURE);
        };

    };

    vec->data[vec->base.size] = value;

    vec->base.size += 1;

};

void float_push_back(floatVector* vec, float value) {

    if (vec->base.size == (vec->base.limit - 1) ) {
        
        vec->base.limit *= 2;
        vec->data = (float*)realloc(vec->data, vec->base.limit*sizeof(float));
        if (vec->data == NULL) {
            perror("Error expanding vector: ");
            exit(EXIT_FAILURE);
        };

    };

    vec->data[vec->base.size] = value;

    vec->base.size += 1;

};

void char_push_back(charVector* vec, char value) {

    if (vec->base.size == (vec->base.limit - 1) ) {
        
        vec->base.limit *= 2;
        vec->data = (char*)realloc(vec->data, vec->base.limit*sizeof(char));
        if (vec->data == NULL) {
            perror("Error expanding vector: ");
            exit(EXIT_FAILURE);
        };

    };

    vec->data[vec->base.size] = value;

    vec->base.size += 1;

};

void double_push_back(doubleVector* vec, double value) {

    if (vec->base.size == (vec->base.limit - 1) ) {
        
        vec->base.limit *= 2;
        vec->data = (double*)realloc(vec->data, vec->base.limit*sizeof(double));
        if (vec->data == NULL) {
            perror("Error expanding vector: ");
            exit(EXIT_FAILURE);
        };

    };

    vec->data[vec->base.size] = value;

    vec->base.size += 1;

};

void string_push_back(stringVector* vec, char* value) {

    if (vec->base.size == (vec->base.limit - 1) ) {
        
        vec->base.limit *= 2;
        vec->data = (char**)realloc(vec->data, vec->base.limit*sizeof(char*));
        if (vec->data == NULL) {
            perror("Error expanding vector: ");
            exit(EXIT_FAILURE);
        };

    };

    vec->data[vec->base.size] = value;

    vec->base.size += 1;

};

// ------------------------------------------------------- VECTOR FRONT ------------------------------------------------------------- //

int int_front(intVector* vec) {

    return vec->data[0];

};

float float_front(floatVector* vec) {

    return vec->data[0];

};

double double_front(doubleVector* vec) {

    return vec->data[0];

};

char char_front(charVector* vec) {

    return vec->data[0];

};

char* string_front(stringVector* vec) {

    return vec->data[0];

};

// ------------------------------------------------------- VECTOR BACK ------------------------------------------------------------- //

int int_back(intVector* vec) {

    return vec->data[vec->base.size-1];

};

float float_back(floatVector* vec) {

    return vec->data[vec->base.size-1];

};

double double_back(doubleVector* vec) {

    return vec->data[vec->base.size-1];

};

char char_back(charVector* vec) {

    return vec->data[vec->base.size-1];

};

char* string_back(stringVector* vec) {

    return vec->data[vec->base.size-1];

};

// ------------------------------------------------------- ACCESS AT ------------------------------------------------------------- //

int int_at(intVector* vec, long int pos) {

    //* Position starts at 0. Indexing at 0!!!

    if (setjmp(env) == 0) {

        if (pos > vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);

            err_handler(msg);
        };

        return vec->data[pos];

    } else {
        exit(EXIT_FAILURE);
    };

};

float float_at(floatVector* vec, long int pos) {

    //* Position starts at 0. Indexing at 0!!!

    if (setjmp(env) == 0) {

        if (pos > vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);

            err_handler(msg);
        };

        return vec->data[pos];

    } else {
        exit(EXIT_FAILURE);
    };

};

double double_at(doubleVector* vec, long int pos) {

    //* Position starts at 0. Indexing at 0!!!

    if (setjmp(env) == 0) {

        if (pos > vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);

            err_handler(msg);
        };

        return vec->data[pos];

    } else {
        exit(EXIT_FAILURE);
    };

};

char char_at(charVector* vec, long int pos) {

    //* Position starts at 0. Indexing at 0!!!

    if (setjmp(env) == 0) {

        if (pos > vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);

            err_handler(msg);
        };

        return vec->data[pos];

    } else {
        exit(EXIT_FAILURE);
    };

};

char* string_at(stringVector* vec, long int pos) {

    //* Position starts at 0. Indexing at 0!!!

    if (setjmp(env) == 0) {

        if (pos > vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);

            err_handler(msg);
        };

        return vec->data[pos];

    } else {
        exit(EXIT_FAILURE);
    };

};

// -------------------------------------------------------- INSERT ----------------------------------------------------------------- //

void int_insert(intVector* v1, long int pos, int value) {

    //* Pos should be relative to 0 indexing.

    if (setjmp(env) == 0) {

        if (pos < 0) {

            pos += v1->base.size;

        };

        // Ensure there is enough space for a new element
        if (v1->base.size >= v1->base.limit) {
            v1->base.limit *= 2;
            
            if (v1->base.limit < pos) {
                
                long int excess = pos - v1->base.limit;
                v1->base.limit = (long int) ( excess/sizeof(int) ) + sizeof(int);

            };

            v1->data = (int*)realloc(v1->data, v1->base.limit * sizeof(int));
            if (!v1->data) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        if (pos > v1->base.size) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->base.size; i > pos; i--) {
                v1->data[i] = v1->data[i-1];
            };

            v1->data[pos] = value; // * Replace value
            v1->base.size += 1;
        };

    } else {
        exit(EXIT_FAILURE);
    }

};

void float_insert(floatVector* v1, long int pos, float value) {

    //* Pos should be relative to 0 indexing.

    if (setjmp(env) == 0) {

        if (pos < 0) {

            pos += v1->base.size;

        };

        // Ensure there is enough space for a new element
        if (v1->base.size >= v1->base.limit) {
            v1->base.limit *= 2;
            
            if (v1->base.limit < pos) {
                
                long int excess = pos - v1->base.limit;
                v1->base.limit = (long int) ( excess/sizeof(float) ) + sizeof(float);

            };

            v1->data = (float*)realloc(v1->data, v1->base.limit * sizeof(float));
            if (!v1->data) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        if (pos > v1->base.size) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->base.size; i > pos; i--) {
                v1->data[i] = v1->data[i-1];
            };

            v1->data[pos] = value; // * Replace value
            v1->base.size += 1;
        };

    } else {
        exit(EXIT_FAILURE);
    }

};

void double_insert(doubleVector* v1, long int pos, double value) {

    //* Pos should be relative to 0 indexing.

    if (setjmp(env) == 0) {

        if (pos < 0) {

            pos += v1->base.size;

        };

        // Ensure there is enough space for a new element
        if (v1->base.size >= v1->base.limit) {
            v1->base.limit *= 2;
            
            if (v1->base.limit < pos) {
                
                long int excess = pos - v1->base.limit;
                v1->base.limit = (long int) ( excess/sizeof(double) ) + sizeof(double);

            };

            v1->data = (double*)realloc(v1->data, v1->base.limit * sizeof(double));
            if (!v1->data) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        if (pos > v1->base.size) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->base.size; i > pos; i--) {
                v1->data[i] = v1->data[i-1];
            };

            v1->data[pos] = value; // * Replace value
            v1->base.size += 1;
        };

    } else {
        exit(EXIT_FAILURE);
    }

};

void char_insert(charVector* v1, long int pos, char value) {

    //* Pos should be relative to 0 indexing.

    if (setjmp(env) == 0) {

        if (pos < 0) {

            pos += v1->base.size;

        };

        // Ensure there is enough space for a new element
        if (v1->base.size >= v1->base.limit) {
            v1->base.limit *= 2;
            
            if (v1->base.limit < pos) {
                
                long int excess = pos - v1->base.limit;
                v1->base.limit = (long int) ( excess/sizeof(char) ) + sizeof(char);

            };

            v1->data = (char*)realloc(v1->data, v1->base.limit * sizeof(char));
            if (!v1->data) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        if (pos > v1->base.size) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->base.size; i > pos; i--) {
                v1->data[i] = v1->data[i-1];
            };

            v1->data[pos] = value; // * Replace value
            v1->base.size += 1;
        };

    } else {
        exit(EXIT_FAILURE);
    }

};

void string_insert(stringVector* v1, long int pos, char* value) {

    //* Pos should be relative to 0 indexing.

    if (setjmp(env) == 0) {

        if (pos < 0) {

            pos += v1->base.size;

        };

        // Ensure there is enough space for a new element
        if (v1->base.size >= v1->base.limit) {
            v1->base.limit *= 2;
            
            if (v1->base.limit < pos) {
                
                long int excess = pos - v1->base.limit;
                v1->base.limit = (long int) ( excess/sizeof(char*) ) + sizeof(char*);

            };

            v1->data = (char**)realloc(v1->data, v1->base.limit * sizeof(char*));
            if (!v1->data) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        if (pos > v1->base.size) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->base.size; i > pos; i--) {
                v1->data[i] = v1->data[i-1];
            };

            v1->data[pos] = value; // * Replace value
            v1->base.size += 1;
        };

    } else {
        exit(EXIT_FAILURE);
    }

};

// -------------------------------------------------------- ERASE -------------------------------------------------------------------- //

void int_erase(intVector* vec, long int pos) {

    if (setjmp(env) == 0) {

        if (pos < 0 || pos >= vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);
            err_handler(msg);

        };

        for ( long int i = pos ; i < vec->base.size; i++) {
            vec->data[i] = vec->data[i+1];
        };

        vec->base.size -= 1;

    };

};

void float_erase(floatVector* vec, long int pos) {

    if (setjmp(env) == 0) {

        if (pos < 0 || pos >= vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);
            err_handler(msg);

        };

        for ( long int i = pos ; i < vec->base.size; i++) {
            vec->data[i] = vec->data[i+1];
        };

        vec->base.size -= 1;

    };

};

void double_erase(doubleVector* vec, long int pos) {

    if (setjmp(env) == 0) {

        if (pos < 0 || pos >= vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);
            err_handler(msg);

        };

        for ( long int i = pos ; i < vec->base.size; i++) {
            vec->data[i] = vec->data[i+1];
        };

        vec->base.size -= 1;

    };

};

void char_erase(charVector* vec, long int pos) {

    if (setjmp(env) == 0) {

        if (pos < 0 || pos >= vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);
            err_handler(msg);

        };

        for ( long int i = pos ; i < vec->base.size; i++) {
            vec->data[i] = vec->data[i+1];
        };

        vec->base.size -= 1;

    };

};

void string_erase(stringVector* vec, long int pos) {

    if (setjmp(env) == 0) {

        if (pos < 0 || pos >= vec->base.size) {

            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range!\n", pos);
            err_handler(msg);

        };

        for ( long int i = pos ; i < vec->base.size; i++) {
            vec->data[i] = vec->data[i+1];
        };

        vec->base.size -= 1;

    };

};

// -------------------------------------------------------- CLEAR -------------------------------------------------------------------- //

void int_clear(intVector* v1) {

    v1->base.size = 0;

};

void float_clear(floatVector* v1) {

    v1->base.size = 0;

};

void double_clear(doubleVector* v1) {

    v1->base.size = 0;

};

void char_clear(charVector* v1) {

    v1->base.size = 0;

};

void string_clear(stringVector* v1) {

    v1->base.size = 0;

};

// -------------------------------------------------------- COUNT  ----------------------------------------------------------------- //

long int int_count(intVector* v1, int searcher) {

    long int count = 0;

    for (long int i = 0; i < v1->base.size; i++) {

        if (searcher == v1->data[i]) count++;

    };

    return count;

};

long int float_count(floatVector* v1, float searcher) {

    long int count = 0;
    const float EPSILON = 1e-6;

    for (long int i = 0; i < v1->base.size; i++) {

        if (fabs(v1->data[i] - searcher) < EPSILON) count++;

    };

    return count;

};

long int double_count(doubleVector* v1, double searcher) {

    long int count = 0;
    const float EPSILON = 1e-10;

    for (long int i = 0; i < v1->base.size; i++) {

        if (fabs(v1->data[i] - searcher) < EPSILON) count++;

    };

    return count;

};

long int char_count(charVector* v1, char searcher) {

    long int count = 0;

    for (long int i = 0; i < v1->base.size; i++) {

        if (searcher == v1->data[i]) count++;

    };

    return count;

};

long int string_count(stringVector* v1, char* searcher) {

    long int count = 0;

    for (long int i = 0; i < v1->base.size; i++) {

        if (strcmp(v1->data[i], searcher) == 0) count++;

    };

    return count;

};

// -------------------------------------------------------- SIZE -------------------------------------------------------------------- //

long int int_size(intVector* v1) {

    return (v1->base.size);

};

long int float_size(floatVector* v1) {

    return (v1->base.size);
    
};

long int double_size(doubleVector* v1) {

    return (v1->base.size);
    
};

long int char_size(charVector* v1) {

    return (v1->base.size);
    
};

long int string_size(stringVector* v1) {

    return (v1->base.size);
    
};

// -------------------------------------------------------- FIND -------------------------------------------------------------------- //

long int int_find(intVector* v1, int finder) {

    for (long int i = 0; i < v1->base.size; i++ ) if (v1->data[i] == finder) return i;

    return -1; //* Not found;

};

long int float_find(floatVector* v1, float finder) {
    
    const float EPSILON = 1e-6;

    for (long int i = 0; i < v1->base.size; i++ ) if (fabs(v1->data[i] - finder) < EPSILON) return i;

    return -1; //* Not found;

};

long int double_find(doubleVector* v1, double finder) {

    const float EPSILON = 1e-10;

    for (long int i = 0; i < v1->base.size; i++ ) if (fabs(v1->data[i] - finder) < EPSILON) return i;

    return -1; //* Not found;

};

long int char_find(charVector* v1, char finder) {

    for (long int i = 0; i < v1->base.size; i++ ) if (v1->data[i] == finder) return i;

    return -1; //* Not found;

};

long int string_find(stringVector* v1, char* finder) {

    for (long int i = 0; i < v1->base.size; i++ ) if (strcmp(v1->data[i], finder) == 0) return i;

    return -1; //* Not found;

};

// -------------------------------------------------------- SWAP -------------------------------------------------------------------- //

void int_swap(intVector* v1, intVector* v2) {

    // todo -> Make a reallocator so that we can ensure both v1 and v2 are max size.
    // todo -> Make a fix allocator which will set limit a bit closer to the size.

    long int maxSize = 10;

    if (v1->base.size > v2->base.size) maxSize = v1->base.size;
    else maxSize = v2->base.size;

    vectorBase tempBase = v1->base;
    int* tempData = v1->data;

    v1->base = v2->base;
    v1->data = v2->data;

    v2->base = tempBase;
    v2->data = tempData;

};

void float_swap(floatVector* v1, floatVector* v2) {

    // todo -> Make a reallocator so that we can ensure both v1 and v2 are max size.
    // todo -> Make a fix allocator which will set limit a bit closer to the size.

    long int maxSize = 10;

    if (v1->base.size > v2->base.size) maxSize = v1->base.size;
    else maxSize = v2->base.size;

    vectorBase tempBase = v1->base;
    float* tempData = v1->data;

    v1->base = v2->base;
    v1->data = v2->data;

    v2->base = tempBase;
    v2->data = tempData;

};

void double_swap(doubleVector* v1, doubleVector* v2) {

    // todo -> Make a reallocator so that we can ensure both v1 and v2 are max size.
    // todo -> Make a fix allocator which will set limit a bit closer to the size.

    long int maxSize = 10;

    if (v1->base.size > v2->base.size) maxSize = v1->base.size;
    else maxSize = v2->base.size;

    vectorBase tempBase = v1->base;
    double* tempData = v1->data;

    v1->base = v2->base;
    v1->data = v2->data;

    v2->base = tempBase;
    v2->data = tempData;

};

void char_swap(charVector* v1, charVector* v2) {

    // todo -> Make a reallocator so that we can ensure both v1 and v2 are max size.
    // todo -> Make a fix allocator which will set limit a bit closer to the size.

    long int maxSize = 10;

    if (v1->base.size > v2->base.size) maxSize = v1->base.size;
    else maxSize = v2->base.size;

    vectorBase tempBase = v1->base;
    char* tempData = v1->data;

    v1->base = v2->base;
    v1->data = v2->data;

    v2->base = tempBase;
    v2->data = tempData;

};

void string_swap(stringVector* v1, stringVector* v2) {

    // todo -> Make a reallocator so that we can ensure both v1 and v2 are max size.
    // todo -> Make a fix allocator which will set limit a bit closer to the size.

    long int maxSize = 10;

    if (v1->base.size > v2->base.size) maxSize = v1->base.size;
    else maxSize = v2->base.size;

    vectorBase tempBase = v1->base;
    char** tempData = v1->data;

    v1->base = v2->base;
    v1->data = v2->data;

    v2->base = tempBase;
    v2->data = tempData;

};

// ------------------------------------------------------- DATA ---------------------------------------------------------------- //

int* int_data(intVector* v1) {

    return v1->data;
    
};

float* float_data(floatVector* v1) {

    return v1->data;
    
};

double* double_data(doubleVector* v1) {

    return v1->data;
    
};

char* char_data(charVector* v1) {

    return v1->data;
    
};

char** string_data(stringVector* v1) {

    return v1->data;
    
};

// ------------------------------------------------------- REVERSE ---------------------------------------------------------------- //

void int_reverse(intVector* v1) {

    long int size = v1->base.size;

    for (int i = 0; i < size / 2; i++) {

        int temp = v1->data[i];
        v1->data[i] = v1->data[v1->base.size-1-i];
        v1->data[v1->base.size-1-i] = temp;

    };

}

void float_reverse(floatVector* v1) {

    long int size = v1->base.size;

    for (int i = 0; i < size / 2; i++) {

        float temp = v1->data[i];
        v1->data[i] = v1->data[v1->base.size-1-i];
        v1->data[v1->base.size-1-i] = temp;

    };

}

void double_reverse(doubleVector* v1) {

    long int size = v1->base.size;

    for (int i = 0; i < size / 2; i++) {

        double temp = v1->data[i];
        v1->data[i] = v1->data[v1->base.size-1-i];
        v1->data[v1->base.size-1-i] = temp;

    };

}

void char_reverse(charVector* v1) {

    long int size = v1->base.size;

    for (int i = 0; i < size / 2; i++) {

        char temp = v1->data[i];
        v1->data[i] = v1->data[v1->base.size-1-i];
        v1->data[v1->base.size-1-i] = temp;

    };

}

void string_reverse(stringVector* v1) {

    long int size = v1->base.size;

    for (int i = 0; i < size / 2; i++) {

        char* temp = v1->data[i];
        v1->data[i] = v1->data[v1->base.size-1-i];
        v1->data[v1->base.size-1-i] = temp;

    };

}

// --------------------------------------------------- SHRINK TO FIT ------------------------------------------------------------ //

void* int_shrink_to_fit(intVector* vec, long int offset) {

    if (!offset) offset = 2;

    vec->data = (int*)realloc(vec->data, (vec->base.size + offset) * sizeof(int) );

    if (vec->data == NULL) {
        perror("Failed to shrink to size: ");
        exit(EXIT_FAILURE);
    };
    
    vec->base.limit = vec->base.size + offset;

}

void* float_shrink_to_fit(floatVector* vec, long int offset) {

    if (!offset) offset = 2;

    vec->data = (float*)realloc(vec->data, (vec->base.size + offset) * sizeof(float) );
    
    if (vec->data == NULL) {
        perror("Failed to shrink to size: ");
        exit(EXIT_FAILURE);
    };
    
    vec->base.limit = vec->base.size + offset;

}

void* double_shrink_to_fit(doubleVector* vec, long int offset) {

    if (!offset) offset = 2;

    vec->data = (double*)realloc(vec->data, (vec->base.size + offset) * sizeof(double) );
    
    if (vec->data == NULL) {
        perror("Failed to shrink to size: ");
        exit(EXIT_FAILURE);
    };
    
    vec->base.limit = vec->base.size + offset;

}

void* char_shrink_to_fit(charVector* vec, long int offset) {

    if (!offset) offset = 2;

    vec->data = (char*)realloc(vec->data, (vec->base.size + offset) * sizeof(char) );
    
    if (vec->data == NULL) {
        perror("Failed to shrink to size: ");
        exit(EXIT_FAILURE);
    };
    
    vec->base.limit = vec->base.size + offset;

}

void* string_shrink_to_fit(stringVector* vec, long int offset) {

    if (!offset) offset = 2;

    vec->data = (char**)realloc(vec->data, (vec->base.size + offset) * sizeof(char**) );
    
    if (vec->data == NULL) {
        perror("Failed to shrink to size: ");
        exit(EXIT_FAILURE);
    };
    
    vec->base.limit = vec->base.size + offset;

}

// -------------------------------------------------------- RESERVE ----------------------------------------------------------------- //

void int_reserve(intVector* vec, long int space) {

    if (vec->base.limit < space) {

        vec->data = (int*) realloc(vec->data, space * sizeof(int) );

        if (vec->data == NULL) {
            perror("Failed to reserve space: ");
            exit(EXIT_FAILURE);
        };

        vec->base.limit = space;

    };

};

void float_reserve(floatVector* vec, long int space) {

    if (vec->base.limit < space) {

        vec->data = (float*) realloc(vec->data, space * sizeof(float) );

        if (vec->data == NULL) {
            perror("Failed to reserve space: ");
            exit(EXIT_FAILURE);
        };

        vec->base.limit = space;

    };

};

void double_reserve(doubleVector* vec, long int space) {

    if (vec->base.limit < space) {

        vec->data = (double*) realloc(vec->data, space * sizeof(double) );

        if (vec->data == NULL) {
            perror("Failed to reserve space: ");
            exit(EXIT_FAILURE);
        };

        vec->base.limit = space;

    };

};

void char_reserve(charVector* vec, long int space) {

    if (vec->base.limit < space) {

        vec->data = (char*) realloc(vec->data, space * sizeof(char) );

        if (vec->data == NULL) {
            perror("Failed to reserve space: ");
            exit(EXIT_FAILURE);
        };

        vec->base.limit = space;

    };

};

void string_reserve(stringVector* vec, long int space) {

    if (vec->base.limit < space) {

        vec->data = (char**) realloc(vec->data, space * sizeof(char*) );

        if (vec->data == NULL) {
            perror("Failed to reserve space: ");
            exit(EXIT_FAILURE);
        };

        vec->base.limit = space;

    };

};

// -------------------------------------------------------- RESIZE ----------------------------------------------------------------- //

void int_resize(intVector* vec, long int newSize, int init) {

    if (!init) init = 0;

    while (newSize > vec->base.size) {
        if (vec->base.size == (vec->base.limit - 1) ) {
            
            vec->base.limit *= 2;
            vec->data = (int*)realloc(vec->data, vec->base.limit*sizeof(int));

            if (vec->data == NULL) {
                perror("Error expanding vector to resize: ");
                exit(EXIT_FAILURE);
            };

        };

        vec->data[vec->base.size] = init;

        vec->base.size += 1;
    };

    vec->base.size = newSize;
    
    if (newSize > vec->base.limit) vec->base.limit = newSize;

};

void float_resize(floatVector* vec, long int newSize, float init) {

    if (!init) init = 0;

    while (newSize > vec->base.size) {
        if (vec->base.size == (vec->base.limit - 1) ) {
            
            vec->base.limit *= 2;
            vec->data = (float*)realloc(vec->data, vec->base.limit*sizeof(float));

            if (vec->data == NULL) {
                perror("Error expanding vector to resize: ");
                exit(EXIT_FAILURE);
            };

        };

        vec->data[vec->base.size] = init;

        vec->base.size += 1;
    };

    vec->base.size = newSize;
    
    if (newSize > vec->base.limit) vec->base.limit = newSize;

};

void double_resize(doubleVector* vec, long int newSize, double init) {

    if (!init) init = 0;

    while (newSize > vec->base.size) {
        if (vec->base.size == (vec->base.limit - 1) ) {
            
            vec->base.limit *= 2;
            vec->data = (double*)realloc(vec->data, vec->base.limit*sizeof(double));

            if (vec->data == NULL) {
                perror("Error expanding vector to resize: ");
                exit(EXIT_FAILURE);
            };

        };

        vec->data[vec->base.size] = init;

        vec->base.size += 1;
    };

    vec->base.size = newSize;
    
    if (newSize > vec->base.limit) vec->base.limit = newSize;

};

void char_resize(charVector* vec, long int newSize, char init) {

    if (!init) init = 0;

    while (newSize > vec->base.size) {
        if (vec->base.size == (vec->base.limit - 1) ) {
            
            vec->base.limit *= 2;
            vec->data = (char*)realloc(vec->data, vec->base.limit*sizeof(char));

            if (vec->data == NULL) {
                perror("Error expanding vector to resize: ");
                exit(EXIT_FAILURE);
            };

        };

        vec->data[vec->base.size] = init;

        vec->base.size += 1;
    };

    vec->base.size = newSize;
    
    if (newSize > vec->base.limit) vec->base.limit = newSize;

};

void string_resize(stringVector* vec, long int newSize, char* init) {

    if (!init) init = 0;

    while (newSize > vec->base.size) {
        if (vec->base.size == (vec->base.limit - 1) ) {
            
            vec->base.limit *= 2;
            vec->data = (char**)realloc(vec->data, vec->base.limit*sizeof(char*));

            if (vec->data == NULL) {
                perror("Error expanding vector to resize: ");
                exit(EXIT_FAILURE);
            };

        };

        vec->data[vec->base.size] = init;

        vec->base.size += 1;
    };

    vec->base.size = newSize;
    
    if (newSize > vec->base.limit) vec->base.limit = newSize;

};

// --------------------------------------------------------- CAPACITY --------------------------------------------------------------- //

long int int_capacity(intVector* v1) {

    return v1->base.limit;

};

long int float_capacity(floatVector* v1) {

    return v1->base.limit;

};

long int double_capacity(doubleVector* v1) {

    return v1->base.limit;

};

long int char_capacity(charVector* v1) {

    return v1->base.limit;

};

long int string_capacity(stringVector* v1) {

    return v1->base.limit;

};

// -------------------------------------------------------- INIT ------------------------------------------------------------------ //

void* int_init(intVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (int*)malloc(sizeof(int)*v1->base.limit);

    if (v1->data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

};

void* float_init(floatVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (float*)malloc(sizeof(float)*v1->base.limit);

    if (v1->data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

};

void* double_init(doubleVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (double*)malloc(sizeof(double)*v1->base.limit);

    if (v1->data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

};

void* char_init(charVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (char*)malloc(sizeof(char)*v1->base.limit);

    if (v1->data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

};

void* string_init(stringVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (char**)malloc(sizeof(char*)*v1->base.limit);

    if (v1->data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

};

// -------------------------------------------------------- INIT ------------------------------------------------------------------ //

void* class_int_init(cintVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->main.base.size = 0;
    v1->main.base.limit = limit;

    v1->main.data = (int*)malloc(sizeof(int)*v1->main.base.limit);

    if (v1->main.data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

    v1->push_back = &int_push_back;
    v1->pop_back = &int_pop_back;
    v1->at = &int_at;
    v1->front = &int_front;
    v1->back = &int_back;
    v1->size = &int_size;
    v1->insert = &int_insert;
    v1->erase = &int_erase;
    v1->clear = &int_clear;
    v1->count = &int_count;
    v1->getData = &int_data;
    v1->reverse = &int_reverse;
    v1->find = &int_find;
    v1->shrink_to_fit = &int_shrink_to_fit;
    v1->resize = &int_resize;
    v1->reserve = &int_reserve;
    v1->capacity = &int_capacity;

};

void* class_float_init(cfloatVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->main.base.size = 0;
    v1->main.base.limit = limit;

    v1->main.data = (float*)malloc(sizeof(float)*v1->main.base.limit);

    if (v1->main.data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

    v1->push_back = &float_push_back;
    v1->pop_back = &float_pop_back;
    v1->at = &float_at;
    v1->front = &float_front;
    v1->back = &float_back;
    v1->size = &float_size;
    v1->insert = &float_insert;
    v1->erase = &float_erase;
    v1->clear = &float_clear;
    v1->count = &float_count;
    v1->getData = &float_data;
    v1->reverse = &float_reverse;
    v1->find = &float_find;
    v1->shrink_to_fit = &float_shrink_to_fit;
    v1->resize = &float_resize;
    v1->reserve = &float_reserve;
    v1->capacity = &float_capacity;

};

void* class_double_init(cdoubleVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->main.base.size = 0;
    v1->main.base.limit = limit;

    v1->main.data = (double*)malloc(sizeof(double)*v1->main.base.limit);

    if (v1->main.data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

    v1->push_back = &double_push_back;
    v1->pop_back = &double_pop_back;
    v1->at = &double_at;
    v1->front = &double_front;
    v1->back = &double_back;
    v1->size = &double_size;
    v1->insert = &double_insert;
    v1->erase = &double_erase;
    v1->clear = &double_clear;
    v1->count = &double_count;
    v1->getData = &double_data;
    v1->reverse = &double_reverse;
    v1->find = &double_find;
    v1->shrink_to_fit = &double_shrink_to_fit;
    v1->resize = &double_resize;
    v1->reserve = &double_reserve;
    v1->capacity = &double_capacity;

};

void* class_char_init(ccharVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->main.base.size = 0;
    v1->main.base.limit = limit;

    v1->main.data = (char*)malloc(sizeof(char)*v1->main.base.limit);

    if (v1->main.data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

    v1->push_back = &char_push_back;
    v1->pop_back = &char_pop_back;
    v1->at = &char_at;
    v1->front = &char_front;
    v1->back = &char_back;
    v1->size = &char_size;
    v1->insert = &char_insert;
    v1->erase = &char_erase;
    v1->clear = &char_clear;
    v1->count = &char_count;
    v1->getData = &char_data;
    v1->reverse = &char_reverse;
    v1->find = &char_find;
    v1->shrink_to_fit = &char_shrink_to_fit;
    v1->resize = &char_resize;
    v1->reserve = &char_reserve;
    v1->capacity = &char_capacity;

};

void* class_string_init(cstringVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->main.base.size = 0;
    v1->main.base.limit = limit;

    v1->main.data = (char**)malloc(sizeof(char*)*v1->main.base.limit);

    if (v1->main.data == NULL) {
        perror("Error allocating memory for vector: ");
        exit(EXIT_FAILURE);
    };

    v1->push_back = &string_push_back;
    v1->pop_back = &string_pop_back;
    v1->at = &string_at;
    v1->front = &string_front;
    v1->back = &string_back;
    v1->size = &string_size;
    v1->insert = &string_insert;
    v1->erase = &string_erase;
    v1->clear = &string_clear;
    v1->count = &string_count;
    v1->getData = &string_data;
    v1->reverse = &string_reverse;
    v1->find = &string_find;
    v1->shrink_to_fit = &string_shrink_to_fit;
    v1->resize = &string_resize;
    v1->reserve = &string_reserve;
    v1->capacity = &string_capacity;

};