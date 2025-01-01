# CVector

CVector is a header-only implementation of std::vector from C++ in C.
Vectors are quite convenient to use. They reduce the necessity of declaring
the array size which is something commonly found in high level programming
languages.

Thus, CVector allows an array of non-fixed size to exist using dynamic
memory management. However, note that not all functions would work in the
same way as C++'s vectors. One change is that you must always pass the vector
itself as an argument and each function is unique for specific datatype.

If you wish to use function calling directly from vectors as in C++,
consider using class vectors from the header in which the first
argument should be `vector.main` which is the vector instance in a stimulated
class. This is because C doesn't support [Object Oriented Programming](https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/) and so structs were used along with
function pointers to stimulate a class like experience. However, each function pointer
consumes 4 bytes of memory on 32-bit systems and 8 bytes of memory on 64-bit systems
and hence each stimulated class consumes 60-120 bytes of data by default for functions alone.
so consider using them only if needed or in cases where memory efficiency can be ignored.

Modification and understanding of source code requires the following:
* Knowledge on C programming language
* Understanding of pointers
* Basic pointer arithmetic

To start, download and include the header file in your source code.

## Docs

It is strongly recommended to read the documentation to understand the operations
and usage of CVector. As pre-mentioned, CVector is quite different from std::vector
due to absence of classes in C. However, the dot notations are provided using
pointers and structures.

Thus, to ensure proper usage and to reduce the confusion in usage please refer to
the documentation [here](CVector/Getting_Started).