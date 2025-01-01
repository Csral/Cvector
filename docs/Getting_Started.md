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
    int_init(&vec);

    printf("Size of the vector: %d\n", int_size(&vec)); // 0

    int_push_back(&vec, 102);

    printf("Element at 0th position: %d\n", int_at(&vec,0)); // 102

    return 0;

}

```