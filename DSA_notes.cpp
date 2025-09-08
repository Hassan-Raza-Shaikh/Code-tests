Hello


Lecture 1

introduction
zahid haleem slides
some algorithms revise exactly 
others logic and ratta
don't watch youtube
if instructions given, no doubt
books and outline uploaded
operations on data structures (algorithms)
search
insert
remove
traverse
sort
2-3 pre req this course
revise pointers and refrences, arrays, struct and classes, functtion and recursion, STL (no compromise except STL)'

Lecture 2

pointer has 2 parts but it doen't store both, it stores address of variable and points to that address and doesn't store both
int* p = new int; // reserves address in pointer of an empty int
*p = 10; // assigns value to that address
delete p; // frees the memory, and pointer address reset
p = new int; // reassigns pointer to new address
p = nullptr; // makes pointer null
static memory is last in first out
dynamic memory is in heap, manually managed
if another P = new int;  written without delete p; then memory leak
dangling pointer is pointer pointing to freed memory (address of a variable that doesn't exist's)
why do we make different pointers for different types if pointer just stores address?
because of pointer arithmetic
p++ means increment address by size of type
pointer to pointer
can we create a dynamic pointer?
yes, pointer to pointer
int** p = new int*;
*p = new int;
**p = 10;
delete *p;
delete p;
p = nullptr;
can you make a dynamic refrence?
no, because refrence must be initialized when declared
refrence is alias, pointer is variable
refrence can't be null, pointer can be null
refrence can't be reassigned, pointer can be reassigned
refrence must be initialized when declared, pointer can be initialized later
refrence is safer, pointer is more powerful
refrence is easier to use, pointer is harder to use
refrence is implemented using pointer
refrence is used for operator overloading, pointer is used for dynamic memory allocation
refrence is used for function arguments, pointer is used for dynamic data structures
refrence is used for function return type, pointer is used for dynamic arrays
refrence is used for function chaining, pointer is used for linked list
refrence is used for function overloading, pointer is used for tree
refrence is used for function templates, pointer is used for graph
refrence is used for function specialization, pointer is used for hash table
refrence is used for function instantiation, pointer is used for trie
refrence is used for function recursion, pointer is used for heap
refrence is used for function lambda, pointer is used for segment tree
what is difference between refrence and derefrence?

Lecture 3

fragment is scattered, defragmentation is unscattering it and making it continuous
loop excecutes code beforehand, whereas recussion goes till end then updates all the waiting values
recursion advantages and disadvantages?

Lecture 4

Data structures relates to data storage in RAM
Data base relates to data storage in secondary memory
Data warehouse relates to data storage in external memory
Abstract data structures: function not defined, only declared, details hidden
Concrete data structures: function defined, details visible
oop parts: abstraction, encapsulation, inheritance, polymorphism
decleration, defination
stack is abstract data structure because we don't know how it is implemented, we just see it as LIFO but actually it is stored differently '
array is concrete data structure because we know how it is implemented, we see it as continuous memory locations
abstract data types: stack, queue, list, tree, graph
concrete data types: array, struct, class, linked list
linear data structures: array, linked list, stack, queue
non linear data structures: tree, graph
see abstract classes, and general classes?