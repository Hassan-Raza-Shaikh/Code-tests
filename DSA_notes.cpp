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
if another p = new int;  written without delete p; then memory leak
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
advantages and disadvantages of recursion

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
if none present, create node 

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

there are 3 differnt ways to use stack in c++
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

Lecture 14

stack is kept size even though it can be limitless because of isFull function, therefore a size is specified, also because by defination it must be fixed
STL is standard template library, it is a collection of classes and functions for data structures and algorithms, that we use often
- stack
- queue
- vector
- list
- map
- set

top function in STL replaces the last elment or shows the top one depending on how it is used in STL
we use top=-1 because array index starts from zero, hence if top=0 then one element is present, if top=-1 then no element is present
pop returns value and removes it in STL, but in user defined stack it just removes it

Lecture 15

to sort a stack without violating stack rules, instead of sorted, create a stack in a way that it i pre sorted
two criteria for stack sorting
- sorting an unsorted already created stack
- creating a stack in a way that values automatically get sorted after each insertion

queue is also an abstract data type
queue works on first in first out mechanism
its logic is opposite of stack, instead of insert and delete at head, we insert at head and delete at tail
there are 3 differnt ways to use queue in c++.
- STL
- linked list
- array
basic operations of queue
- enqueue (insert element at rear)
- dequeue (remove element from front)
- front (get element at front without removing it)
- rear (get element at rear without removing it)
- isEmpty (check if queue is empty)
- isFull (check if queue is full)
- size (get number of elements in queue)

potential applications of stack and queue in solving computer problems?
stack
Expression evaluation and syntax parsing
Function call management
Undo/Redo feature
Backtracking algorithms
queue
CPU and I/O scheduling
Data buffering
Breadth-First Search (BFS)
Printing and Task Queues
applications ofstack and queue in schedualing of tasks and jobs while ram and processor are interacting with each oher?
queue
Process Scheduling (Ready Queue)
I/O Queue
stack 
Function call stack during process execution
Interrupt handling
example application of stack and queue in development of different mobile and web apps in real world scenerios?
stack
Navigation (Back button functionality)
Form Input Management (Undo/Redo)
queue
Message Queues in Chat or Notification Systems
Task queues in backend servers
Music or Video Playlist in Apps

Lecture 16

in queue and stack using array, vallue is not deleted, index is just moved back
in dequeue, value is also returned when deleting/moving pointer back
two indicators will be used, front and rear
rear will move forward when inserting
front will move forward when deleting

Lecture 17

if u fill queue and then while dequeuing, if u want to insert others values in place that you removed without first emptying whole queue
so we move rear to start if there is space in start
this is called circular queue
in circular queue, when rear or front reaches end, it will move to start if there is space
to check if queue is full in circular queue
if((rear+1)%maxSize==front)
to check if queue is empty in circular queue
if(front==-1)
in circular queue, when inserting first element, front and rear both will be 0
in circular queue, when deleting last element, front and rear both will be -1
in circular queue, when inserting element, rear will be moved forward in circular manner
rear=(rear+1)%maxSize;

Lecture 18

bubble sort
compare two adjacent elements
if first is greater than second, swap them
repeat for all elements
repeat for n-1 times
insertion sort
 
Lecture 19

for measurment of efficiency we take two things into account(measurements)
-time complexity
-space complexity
time complexity is measured in terms of number of comparisons and number of swaps
space complexity is measured in terms of number of variables used
we easure it by the time compiler took to run the code
we measure it by the memory used by the code
but these are not accurate because they depend on many factors
a computer is never in the same state twice
it doesn't give exact idea of efficiency because its size can't be infinite on a practical device
worst case scenario big O notation
average case scenario big theta notation
best case scenario big omega notation
we make table to represent O Omega and theta of different algorithms
remember graph for time complexities og big O

Lecture 20

same as discrete maths??!
k is value when g(x) overtakes f(x) on graph
c is the multiple on which value does that
see log(n), n, log(log(n)), n^2, etc
for log of log, we need power of power
for multiple doublings or divisions, we need log whole power to the amount of loops
recursion growing factor is function call, 

Lecture 21

bubble sorting, one iteration is called pass

Lecture 22

selection sort
best complexity: O(n^2)
average complexity: O(n^2)
worst complexity: O(n^2)

bubble sort
best complexity: O(n)
average complexity: O(n^2)
worst complexity: O(n^2)

insertion sort
best complexity: O(n)
average complexity: O(n^2)
worst complexity: O(n^2)

merge sort
best complexity: O(n log n)
average complexity: O(n log n)
worst complexity: O(n log n)

quick sort
best complexity: O(n log n)
average complexity: O(n log n)
worst complexity: O(n^2)

heap sort
best complexity: O(n log n)
average complexity: O(n log n)
worst complexity: O(n log n)

merge sort and quick sort are divide and conquer algorithms
merge sort divides array into two halves, sorts them recursively, and then merges them
merge sort keeps splitting until single element, then merges back in the same order and groups as were broken from
merge sort 2d array
merge sort takes start and end index, and then when left index is equal to right it reaches a single elment and stops halving

Lecture 23

didn't happen'

Lecture 24

merge sort again

Lecture 25

paper discussion
. and -> are different

Lecture 26

Trees
at any point, the larger value from it is on right and if it is smaller it is on its left
there are differet types of trees
- simple trees
- binary trees
binary tree further has 3 types
- self balancing tree
- binary search tree
- AVL tree
main node is called root node
ending nodes are called leaf nodes
binary tree is a tree in which each node has two nodes
binary search tree is a tree in which greater node then it is on right and smaller node is on right
each node of a BST is a subtree of the ones following it
each node has a left and right

Lecture 27

Traversal in BST
each node has two nodes
smaller on left and larger on right
strict binary search tree is one in which each node strictly has two nodes after each node
this is only possible for odd numbers
there are 4 methods of traversal
- in order traversal
- pre order traversal
- post order traversal
- level order traversal
height of the tree is the no. of links between the further most leaf node and the root node
pre order means top most is first - order dene wala phele ata hai
in order means top most is in middle - order dene wala dono sides pe braber main aye ga
post order means top most is last - order dene wala akhir main
level order means the first item is at level 1 or 0 and next order is 1 or 2 and so on etc, so those on same level are siblings, so print in order
in general we always traverse from left side first no matter what type we use
pre and post are basically the opposite of each other

Lecture 28

there are 3 cases for deletion,
- current node is the leaf node
- current node has only 1 child node
- current node has 2 child nodes
in the 2 child case, we don't delete the current node but we delete the node whose value is to be replaced in that node'
successor: node next to any node in traversal
predecessor: node prev to any node in traversal
for deleting node with no child, just reach and delete
for deleting node with one child, reach and link parent to child, then delete
for deleting node with two children, find inorder successor (leftmost of right subtree),or predecessor(rightmost of left subtree) copy its value to current node, then delete successor node which will have at most one child
write in order values and next value to node or previos is to be replaced, this or min max is the same thing
simple searching is done  in preorder way

Lecture 29

AVL trees
AVL tree is a self balancing binary search tree
in AVL tree, the difference between heights of left and right subtrees cannot be more than one
if it becomes more than one, then we need to perform rotations to balance the tree
BF=LHS-RHS
if BF=-1,0,1 then tree is balanced
if BF>1 then left heavy
if BF<-1 then right heavy
we find height, then balancing factor, then we balance tree if required
for same values, different trees are possible depending on insertion order
so for certain tree formation we can make it so that the height becomes half or almost half of Linkedlist
- worst time complexity of AVL: log(n)
- worst time complexity of BST: n
AVL tree will insure that minimum possible height is maintained
there are two possibiliteies:
- a BST already exists and convert it to AVL
- create an AVL tree foom scratch
there are 4 rotation cases
- left left case
- right right case
- left right case
- right left case
left left case: right rotation
right right case: left rotation
left right case: left rotation on left child, then right rotation on root
right left case: right rotation on right child, then left rotation on root
rotation is opposite of what is causing imbalance
left left and right right case are single step corrections
left right and right left case are double step corrections
we write left right from root in order of which they are placed towards left or right, then rotation is same order 
if it is a left right case, first we rotate the bottom node to left and  its root to right, then whole tree towrards right
height is found using edges, nodes one not preferred
basically for building an AVL tree from scratch, there can never be more than these two cases

Lecture 30

on each step find balancing factor
going from bottom, first point where problem arises is where we fix it
we go from depth to up wherever balancing factor is greater than 1 or less than -1 we fix it at that point
which ever sides rotation, the maximum most dept value on that side

Lecture 31

code of AVL tree

Lecture 32

deletion of AVL tree has exactly same casses as BST
only difference is that after deletion, we need to check balancing factor and perform rotations if required
we check from point of error which side is heavy and which side of that side is heavy
then perform rotations accordingly
rotation is opposite of what is causing imbalance

graphs are non linear data structures
graph is a collection of nodes and edges
nodes are also called vertices
edges are also called arcs
graphs can be directed or undirected
in directed graphs, edges have direction
in undirected graphs, edges don't have direction
graphs can be weighted or unweighted
in weighted graphs, edges have weights
in unweighted graphs, edges don't have weights
if in a tree we combine two leaf nodes with an edge, it becomes a graph
there are more than one way to reach from one node to another in graph
graps keep record of connections between nodes
graphs can be represented in two ways
- adjacency matrix
- adjacency list
adjacency matrix is a 2D array where rows and columns represent nodes and values represent edges
if there is an edge between node i and node j, then matrix[i][j]=1
else matrix[i][j]=0
for weighted graphs, matrix[i][j]=weight of edge
if no edge, matrix[i][j]=infinity or some large value
adjacency list is an array of lists where each index represents a node and the list at that index represents its adjacent nodes
for weighted graphs, each element in the list is a pair of adjacent node and weight of edge
adjacency list is more space efficient for sparse graphs
adjacency matrix is more space efficient for dense graphs

Lecture 33

in tree there is only one path between two nodes
in graph there can be multiple paths between two nodes
degree of a node is the number of edges connected to it
in directed graphs, we have in-degree and out-degree
recommended implementation of trees is using pointers and classes
but for graphs, adjacency matrix and adjacency list are preferred (vectors and lists)
in graphs we don't keep addresses of connections in that node, we keep record of connections in a separate structure so it's not an actual tree like structure, that is just drawn like that for understanding
ontology: is a graph formed by multiple connections of nodes representing knowledge basis 
adjacency matrix shows presence or absence of edge directly
it shows weights directly
adjacency list shows only connected nodes directly
first is the node out of which all connections are made in one step, all the ones following it are the ones the first node can go to
pyhton type of for loop is an iterator type loop
this means the itterator is the value at the first index, otherwise loops are index based
for(auto x: adjList[i])
auto means the type is automatically detected
x is the value at that index
adjList[i] is the list at index i
BFS: breath first search
DFS: depth first search
BFS prints adjacent nodes first, then goes deeper
also no repetition of nodes
DFS goes deeper first, then prints adjacent nodes
also no repetition of nodes
both can be implemented using recursion or using stack/queue

Lecture 34

BFS in grapgh using queue
DFS in graph using stack or recursion
notation is using arrows which doesn't mean we go from one to the next, but from first to all those mentioned after arrows'
we will create a bool array to keep track of visited nodes
in BFS we use queue to keep track of vertices to be visited wrt to current vertice
in DFS we use stack or recursion to keep track of nodes to be visited
BFS:
place a number in queue, then pop it to show it
then we place all its adjacent nodes in queue
then we pop next number from queue, show it, and place all its adjacent nodes in queue
repeat until queue is empty
as we place vertices in queue, we mark them as visited
whose vertices we are seeing next, we remove that from queue
then we add all its adjacent vertices to queue if not visited
then we repeat
we make a tree like structure for traversal without repetition, and more than one type of tree can be made depending on which node is chosen first

Lecture 35

the difference between tree and graph is:
is that there is no closed loop in tree, whereas in graph there can be closed loops
in tree there is only one path between two nodes, whereas in graph there can be multiple paths
in tree there is a root node, whereas in graph there is no root node
in tree there are no cycles, whereas in graph there can be cycles
in simple tree, we keep an array of pointers in each node to point to its children, so that we can keep more than 2 nodes
in binary tree, we keep two pointers in each node to point to its left and right children

Lecture 36

DFS:
we use stack or recursion
we place a number in stack, then pop it to show it
then we place all its adjacent nodes in stack
then we pop next number from stack, show it, and place all its adjacent nodes in stack
repeat until stack is empty
as we place vertices in stack, we mark them as visited
whose vertices we are seeing next, we remove that from stack
then we add all its adjacent vertices to stack if not visited
then we repeat
in DFS, we go deeper first, then print adjacent nodes
in BFS, we print adjacent nodes first, then go deeper
both can be implemented using recursion or using stack/queue
a vector of vectors is used to create adjacency list
vector<vector<int>> adjList;
each index of adjList represents a node
adjList[i] is a vector containing all adjacent nodes of node i
matrix contais record of which nodes we can not go to from which nodes

Lecture 37


There are two techniques for DFS
- running stack technique
- suspension stack technique
in running stack technique, we use a recursion to keep track of nodes to be visited
in suspension stack technique, we use stack to keep track of nodes to be visited
in running stack technique, we call DFS recursively for adjacent nodes
in suspension stack technique, we push adjacent nodes onto stack 

all the nodes we are visiting will be kept in recursion and we will go deeper until no unvisited adjacent nodes are left
then we backtrack using stack or recursion
we keep track of visited nodes using a bool array
this is in running stack

all the nodes we are visiting, we will pop it before going deeper
then we push all its unvisited adjacent nodes onto stack
then we pop next node from stack and repeat
this is in suspension stack

Recursive DFS pops (finishes) node before exploring the next adjacency list.
Iterative DFS pushes all neighbors, then pops from the stack later.

Lecture 38

hash is used when we need fast insertion, deletion or searching
BST is used when we need sorted data, and AVL if sorted and fast searching
Linked list for 
graph is used for finding shortest path among multiple paths

any graph when traversing BFS or DFS converts into a spanning tree (tree not BST), because no node/vertex is visited twice
graphs decide the style or alignment of tree
possible spanning combinations of a tree of graph are n^(n-2) wrt 

Lecture 39 (in lab)

hashing is used when we wanr lowest time complexity o(1) for insertion, removal and deletion
but it is the worst for sorting
limitation is the amount of data that we can store
we create a hash function
it takes a key, and against it returns a value which we call hash value
key is the thing we want to store, value is the place/index of array we are going to store it
hash function converts that key into its index/hash value
then that is known as hash table, where we store keys
we have to make a hash function that takes key and converts it into its hash and vice versa so we have to devise its formula/method
size of hash depends on type of data structure that we use
if we have to chnage size of hash, we have to change size of hash function too
most general hash function is taking mod of key with 10 and using remainder as index
everything happens in constant time
but the problem with this is that collision can occur if two values have the same hash value
then to resolve this we resolve by open chaining or close chaining
for close chaining
linear prob, we search and insert in nearest free slot
linear prob is not good because clustering can occur
quadratic prob, we search and insert in nearest free slot in quadratic manner, every second slot is checked
the more higher jump we make, the worse the complexity gets
in open chaining
we make a linked list at each index of hash table
then if collision occurs, we insert that value in linked list
in this case best case is o(1) and worst case is o(n)
worst case complexity for this depends on what data structures are used in hash for further value insertion
for quadratic probing, index is changed in quadratic manner wrt original key
for linear probing, index is changed in linear manner wrt index after each