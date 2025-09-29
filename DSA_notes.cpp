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
array combiinations??
why dynamic arrays a thing?
insert at end, start, middle???

Lecture 5

array is static memory allocation, linked list is dynamic memory allocation
array is continuous memory locations, linked list is scattered memory locations
array is fixed size, linked list is variable size
array is faster access, linked list is slower access
array is slower insertion and deletion, linked list is faster insertion and deletion
linked list uses pointer, array doesn't use pointer
we use built in mechanisms of array, linked list we have to build it ourselves
array memory is allocated at compile time , linked list memory is allocated at run time
array memory is allocated in stack, linked list memory is allocated in heap
linked list address of next index is stored in current index
linked list is memory efficient, array is memory inefficient
linked list can grow and shrink, array can't grow and shrink
performance is measured in two things:
-time
-space
basic unit of array is index
basic unit of linked list is node(index)
linked list node needs to be made manually, array index is done by itself  
we need to define node of a linked list
node is made using structures or classes
same node is used in trees, linked lists among other things
u need to keep two things in linked list index, value at that index and adress of next address
type of pointer must be type of class or structure
struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node n1,n2,n3;
    n1.data=5;
    n2.data=6;
    n3.data=7;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=nullptr;
}
ye sahi linked list nahi bani, because fixed and no addition or removal

Lecture 6

if node is already present, the the node present before it, it will input the adress of new node into old one
if none present, creeate node 

possibility 1: no node is present
possibility 2: one or more than one node is present
we can keep both head and tail or only one of them, but keeping both allow to insert from both ends
linkedlist item can be added from head or tail
step one create node
step two check if it is first node or one of many
step three where do you want to add it start or end
if keeping at tail, address of tail node needs to be realloted
step four add adress of new node in the next of last node/tail
step five next of new node will be made null
step six update tail pointer from last to new node because it is the new tail

Lecture 7

basic two types of linked list: single and double
singly linked list: node has data and next pointer (2)
doubly linked list: node has data, next pointer, previous pointer (3)
circular linked list: node has data and next pointer, last node points to first node
circular doubly linked list: node has data, next pointer, previous pointer, last node points to first node, first node previous points to last node
why doubly linked list?
because we can traverse in both directions
why circular linked list?
because we can traverse from any node to any node
why circular doubly linked list?
because we can traverse in both directions from any node to any node
advantages and disadvantages of each?
advantages of singly linked list: less memory, simple
disadvantages of singly linked list: can't traverse backwards, can't delete previous node
advantages of doubly linked list: can traverse backwards, can delete previous node
disadvantages of doubly linked list: more memory, complex
advantages of circular linked list: can traverse from any node to any node, no null pointer
disadvantages of circular linked list: complex, harder to implement
advantages of circular doubly linked list: can traverse in both directions from any node to any node
disadvantages of circular doubly linked list: more memory, complex, harder to implement
for double linkedlist, if adding inbetween, need to update 4 pointers
replace next of previous node to next of new node
replace previous of new node to previous node
for single linkedlist, if adding inbetween, need to update 2 pointers
replace next of new node with next of previous node
replace next of previous node with new node

Lecture 8

to create new node int * newnode = new node
circular behaviour allows us to double back esily to reach easier
for adding in tail in circular linked list
after allocating next of tail to next of new node
then allocating next of tail to new node
then updating tail to new node
for adding in head in circular linked list
after creating node
allocate next of new node with address of head which can be taken from head or next of tail
then allocate next of tail to new node
then update head to new node
last two steps can be interchanged, but there will be one difference
if next of tail is allocated to new node first, then head will be updated to new node
if head is updated to new node first, then next of tail will be allocated to new node or head

Lecture 9

code of singly linked list

Lecture 10

code of doubly linked list

for doubly linked list,
adding at head
allocate previos pointer of new node to null
allocate next pointer of new node to head
allocate previous of head to new node
if inserting first node it is tail and head, otherwise don't alter tail
if(tail==nullptr) tail=newNode;
else tail remains same's
update head to new node

Lecture 11

node can be deleted and inserted in three ways
at head
at tail
in between
deleting at head
make next of head head
delete old head
make previous of new head null
if next and previous of head are null, then it is the only node, so delete head and tail both
deleting at tail
opposite of deleteing at head

Lecture 12

linked list will have two types of sorting
- sorting values
- sorting nodes
sorting values is easy, just swap values
sorting nodes is hard, need to change pointers
for sorting nodes, need to change 4 pointers
if nodes are adjacent, then need to change 3 pointers
if nodes are not adjacent, then need to change 4 pointers
need to handle special cases
do sorting both ways

Lecture 13

circular linked list adding at head and tail is a bit different because of circular nature
for adding at head in circular linked list
create new node
if no node present
make next of new node point to itself
make head and tail point to new node
if one or more node present
make next of new node point to head
make next of tail point to new node
make head point to new node
for adding at tail in circular linked list
create new node
if no node present
make next of new node point to itself
make head and tail point to new node
if one or more node present
make next of new node point to head
make next of tail point to new node
make tail point to new node
for adding in between in circular linked list
same as simple double limked list
circular linked list was needed because we can traverse from any node to any node easily
and as in practical programming a pointer is set and it can't be changed so circular nature allows fast switching'

there are 3 disffernt ways to use stack in c++
- by using STL (built in stack)
- by using array implementation to create stack by ourselves (user defined stack)
- by using linked list implementation to create stack by ourselves (user defined stack)
stack works on last in first out mechanism
in abstract data type, physical implementaion is different but memory implementation is different
like stack using array, stack we can accesss only top element, but in array we can access any element
stack using linked list, stack we can accesss only top element, but in linked list we can access any element
hence stack is abstract data type
basic operations of stack
- push (insert element at top)
- pop (remove element from top)
- peek/top (get element at top without removing it)
- isEmpty (check if stack is empty)
- isFull (check if stack is full)
- size (get number of elements in stack)
fixing memory for stack is necessary because stack is static memory allocation and it has a limit so to stay true to that value
hence we define max size of stack