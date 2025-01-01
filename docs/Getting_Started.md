# Quick Start

Welcome to CVectors documentation! In this page you will learn to include
this header and the general uses of vectors. To begin with, download the header file
[vector.h](https://github.com/Csral/Cvector/blob/master/includes/vector.h) and place it
in your project folder where you wish to use this header. Once the file is available, just include it.

Alternatively change directory (cd) into the directory (folder) where you want
to place the header and execute the following command:

`curl -L https://raw.githubusercontent.com/Csral/Cvector/master/includes/vector.h -o vector.h`

To include it in your .c file add the following statement:
`#include "./relative/path/to/vector.h"`

There are no special flags or options for compilation using gcc. However, for clang use -lm flag
to link the math library.

*Example project directory:*

```

/   Project                   # Root of the project
├── includes/                 # Header files
│   └── vector.h              # vector header file
├── src/                      # Source files
│   └── main.c                # Main C file
└── Other files/folders       # Optional, if you want a build 


```
*Example main.c*

```

//main.c

#include "../includes/vector.h"
#include <stdio.h>

int main(void) {

    intVector vec;
    int_init(&vec,10);

    printf("Size of the vector: %d\n", int_size(&vec)); // 0

    int_push_back(&vec, 102);

    printf("Element at 0th position: %d\n", int_at(&vec,0)); // 102

    return 0;

}

```

By the end of this page you will learn the following:
* Difference between class and non-class vectors
* Initializing Vectors
* Pushing elements to vectors
* Popping elements to vectors
* Accessing elements from vectors

## Difference Between Class and Non-Class vectors

Class and Non-class vectors are just namesakes as C doesn't really have classes in it.
The only difference or advantage in class variants of vectors is dot notation provided
by the class variants (As in methods) but the first argument in either type of vectors
functions is the vector itself. In a class variant of vector it is the `vector.main` 
instead of vector itself. Class variants make it easier to call function and are
easier to relate to `std::vector`.

For instance, this is how they work:

**Non-Class**: `datatype_function_name(&vectorName, Extra_Args);`

**Class**: `vectorName.function_name(&vectorName.main, Extra_Args)`

However, there is one disadvantage of using the class based approach. In class based approach,
the structs reserve 60 bytes (on 32-bit based systems) or 120 bytes (in 64-bit based systems)
to store the base address of functions. Thus, a better use case is if vectors are going to store
data much larger than function pointers themselves. For optimized memory consumptions avoid regular
usage of class based approach.

## Initializing Vectors

### Class Vectors

For class vectors use c<datatype>Vector as the datatype where datatype of the elements stored
in the vector without the angular brackets (<>). For example a class based vector storing integers
would be initialized as `cintVector myClassVector;`.

### Non-class vector

For non class vectors use <datatype>Vector as the datatype where datatype of the elements stored
in the vector without the angular brackets (<>). For example a class based vector storing integers
would be initialized as `intVector myVector;`.

### Initializing

However, structs do not store default values and so they must be initialized. There is a init() function
for each datatype for both class and non-class based vectors making a total of 10 different init() functions.

For class based vectors the init function is defined as `class_datatype_init(cdatatypeVector* vec, long int limit)`
and should be used as follows:
`class_datatype_init(&vec, 10)`

For non-class based vectors the init function is defined as `datatype_init(datatypeVector* vec, long int limit)`
and should be used as follows:
`datatype_init(&vec,10)`

Here limit is the maximum amount of elements this vector can store. No worries, if the size of vector reaches limit
then the vector's size is increased to fit more elements. If limit is passed as 0 or a negative value, the limit will
be taken to 5 by default.