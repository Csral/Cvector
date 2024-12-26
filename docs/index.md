# CVector

CVector is a header-only implementation of std::vector from C++ in C.
Vectors are quite convenient to use. They reduce the necessity of declaring
the array size which is something commonly found in high level programming
languages.

Thus, CVector allows an array of non-fixed size to exist using dynamic
memory management. However, note that not all functions would work in the
same way as C++'s vectors. C doesn't have (Object-Oriented Programming)[https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/] capabilities and hence structures
were used to emulate an object-oriented feel in this project.

Modification and understanding of source code requires the following:
* Knowledge on C programming language
* Understanding of pointers
* Basic pointer athematic

To start, download and include the header file in your source code.

## Docs

It is strongly recommended to read the documentation to understand the operations
and usage of CVector. As pre-mentioned, CVector is quite different from std::vector
due to absence of classes in C. However, the dot notations were maintained using
pointers and structures.

Thus, to ensure proper usage and to reduce the confusion in usage please refer to
the documentation here.