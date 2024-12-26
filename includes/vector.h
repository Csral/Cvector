#pragma once

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>

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

typedef struct intVector {

    vectorBase base;
    int* data;
    void (*push_back)(intVector* vec, int value);
    void (*pop_back)(intVector* vec);
    int (*at)(intVector* vec, long int pos);
    int (*front)(intVector* vec);
    int (*back)(intVector* vec);
    long int (*size)(intVector* vec);
    void (*insert)(intVector* vec, long int pos, int value);
    void (*erase)(intVector* vec, long int pos);

};

typedef struct floatVector {

    vectorBase base;
    float* data;
    void (*push_back)(floatVector* vec, float value);
    void (*pop_back)(floatVector* vec);
    float (*at)(floatVector* vec, long int pos);
    float (*front)(floatVector* vec);
    float (*back)(floatVector* vec);
    long int (*size)(floatVector* vec);
    void (*insert)(floatVector* vec, long int pos, float value);
    void (*erase)(floatVector* vec, long int pos);

};

typedef struct doubleVector {

    vectorBase base;
    double* data;
    void (*push_back)(doubleVector* vec, double value);
    void (*pop_back)(doubleVector* vec);
    double (*at)(doubleVector* vec, long int pos);
    double (*front)(doubleVector* vec);
    double (*back)(doubleVector* vec);
    long int (*size)(doubleVector* vec);
    void (*insert)(doubleVector* vec, long int pos, double value);
    void (*erase)(doubleVector* vec, long int pos);

};

typedef struct charVector {

    vectorBase base;
    char* data;
    void (*push_back)(charVector* vec, char value);
    void (*pop_back)(charVector* vec);
    char (*at)(charVector* vec, long int pos);
    char (*front)(charVector* vec);
    char (*back)(charVector* vec);
    long int (*size)(charVector* vec);
    void (*insert)(charVector* vec, long int pos, char value);
    void (*erase)(charVector* vec, long int pos);

};

typedef struct stringVector {

    vectorBase base;
    char** data;
    void (*push_back)(stringVector* vec, char* value);
    void (*pop_back)(stringVector* vec);
    char* (*at)(stringVector* vec, long int pos);
    char* (*front)(stringVector* vec);
    char* (*back)(stringVector* vec);
    long int (*size)(stringVector* vec);
    void (*insert)(stringVector* vec, long int pos, char* value);
    void (*erase)(stringVector* vec, long int pos);

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
        
        vec->base.limit *= 4;
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
        
        vec->base.limit *= 4;
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
        
        vec->base.limit *= 4;
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
        
        vec->base.limit *= 4;
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
        
        vec->base.limit *= 4;
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

    return vec->data[vec->base.size];

};

float float_back(floatVector* vec) {

    return vec->data[vec->base.size];

};

double double_back(doubleVector* vec) {

    return vec->data[vec->base.size];

};

char char_back(charVector* vec) {

    return vec->data[vec->base.size];

};

char* string_back(stringVector* vec) {

    return vec->data[vec->base.size];

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

            pos += v1->size(v1);

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

        if (pos > v1->size(v1)) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->size(v1); i > pos; i--) {
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

            pos += v1->size(v1);

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

        if (pos > v1->size(v1)) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->size(v1); i > pos; i--) {
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

            pos += v1->size(v1);

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

        if (pos > v1->size(v1)) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->size(v1); i > pos; i--) {
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

            pos += v1->size(v1);

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

        if (pos > v1->size(v1)) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->size(v1); i > pos; i--) {
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

            pos += v1->size(v1);

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

        if (pos > v1->size(v1)) {
            char msg[100];
            snprintf(msg, sizeof(msg), "Specified index %ld out of range to insert an element!\n", pos);
            err_handler(msg);
        } else {

            
            for (int i = v1->size(v1); i > pos; i--) {
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

// -------------------------------------------------------- SIZE -------------------------------------------------------------------- //

long int int_size(intVector* v1) {

    return (v1->base.size+1);

};

long int float_size(floatVector* v1) {

    return (v1->base.size+1);
    
};

long int double_size(doubleVector* v1) {

    return (v1->base.size+1);
    
};

long int char_size(charVector* v1) {

    return (v1->base.size+1);
    
};

long int string_size(stringVector* v1) {

    return (v1->base.size+1);
    
};

// -------------------------------------------------------- INIT -------------------------------------------------------------------- //

void* int_init(intVector* v1, long int limit) {

    if (limit <= 0) limit = 5;

    v1->base.size = 0;
    v1->base.limit = limit;

    v1->data = (int*)malloc(sizeof(int)*v1->base.limit);

    if (v1->data == NULL) {
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

    v1->push_back = &float_push_back;
    v1->pop_back = &float_pop_back;
    v1->at = &float_at;
    v1->front = &float_front;
    v1->back = &float_back;
    v1->size = &float_size;
    v1->insert = &float_insert;
    v1->erase = &float_erase;

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

    v1->push_back = &double_push_back;
    v1->pop_back = &double_pop_back;
    v1->at = &double_at;
    v1->front = &double_front;
    v1->back = &double_back;
    v1->size = &double_size;
    v1->insert = &double_insert;
    v1->erase = &double_erase;

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

    v1->push_back = &char_push_back;
    v1->pop_back = &char_pop_back;
    v1->at = &char_at;
    v1->front = &char_front;
    v1->back = &char_back;
    v1->size = &char_size;
    v1->insert = &char_insert;
    v1->erase = &char_erase;

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

    v1->push_back = &string_push_back;
    v1->pop_back = &string_pop_back;
    v1->at = &string_at;
    v1->front = &string_front;
    v1->back = &string_back;
    v1->size = &string_size;
    v1->insert = &string_insert;
    v1->erase = &string_erase;

};