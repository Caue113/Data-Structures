# Linked Lists
Notes about findings while playing around;

Linked lists uses pointers/references inside their nodes to know to where to go, either foward or backward (next/previous).

Opposed to Arrays, Linked Lists are used when needed memory for an objective is unknown, thus can't be statically defined. (Dynamic Arrays are an attempt to solve).

**All** linked lists **must have** at least a *head* reference of a given node. Other kind of references you can add as you wish for custom tailoring

The differences you can find about Linked Lists vary in the structure of the collection itself and his nodes. 

For the rest of the analysis, take the "default" definition of Linked List as the simplest one:
- It contains a node referece called *head*
- Nodes contain their own data(s) and a reference to next

# Quick Info Table

Linked List
- Insert - O(n) or O(1) with tail
- Insert begin - O(1)
- Insert after - O(n)
- Remove - O(n) or O(1) with tail
- Remove after - O(n)
- Remove at index - O(n) (index can be last)

# Unit of Data: Nodes
Nodes are custom made data. They can hold whatever is needed, but they **must** have a reference to *next* to be used in Linked Lists.

The following examples are valid:
```c
typedef struct node { 
    int value;
    node *next;
} node

typedef struct PersonNode { 
    int age;
    char *name;
    char *street;
    int housing_number;

    PersonNode *next;
} PersonNode
```

# Singly Linked Lists
Single linked lists are unidirectional, meaning only *next* within his nodes exist.

Example
```c
typedef struct node { 
    int value;
    node *next;
} node

typedef struct LinkedList { 
    node *head;
} LinkedList
```

# Double Linked Lists
Double Linked Lists are bidirectional. Each node inside them have a reference to a backward and a foward node.

By having another reference to go backwards full direction control is given and it's operations can be improved.

```c
typedef struct node { 
    int value;
    node *next;
    node *previous;
} node
typedef struct LinkedList { 
    node *head;
} LinkedList
```

# Singly Circular Linked Lists
In simple terms, a Circular Linked Lists revolves itself. Meaning, the *tail* will not point to NULL (or any unknown value), but back to *head*.

Singly Circular Linked Lists are unidirectional.

# Double Circular Linked Lists

Double Circular Linked Lists are bidirectional.

# Operations

## Insert
The insert appends a new node in the end. It takes a worst case of O(n) time to do it.

However, it can be improved if our Linked List uses a *tail* reference. 

A "sacrifice" of 8 bytes (4 Bytes in 32 bits systems) can make the insertion happen at O(1) time, since we always can know the end of the Linked List.

## Insert Begin
Insert a new node at Linked List's *head*

Since all Linked Lists require a *head*, this operation is O(1) for all cases;

## Insert After

Similar to insert in the end, the insert after needs to know an exact Node to append.

It could be done in two manners:

- Find node by a reference
  - Must know a node beforehand;
  - Uses unique reference;
  - Ensures proper order;
- Find node by a value
  - No need to know an exact node;
  - Possibility of duplicity of data;
  - Don't guarantee proper order;

At the momment, the (proved) way found is attached to a node data.

## Insert at index [Unneeded?]

This implementation resembles a lot an array operation, though arrays are better suited because of random access.

While indexes "are not a thing" in Linked Lists, this method enforces order as reference for insertion, as opposed to Linked List begin, end or a specific node in question.

## Remove

Remove works identically to Insert. 

O(n) for the simplest Linked List structure.

O(1) for Linked Lists with a *tail* reference.

## Remove After

Works identically to Insert After.

## Remove at index [Unneded?]

Works identically to Insert at index

# Applications

- Data structures
  - Queue
  - Stacks

# Observations

Generally Arrays are always preferable. Its simpler and has random access. 

Although of its contiguous nature imply that in insertion situations it may need an entire memory reallocation, for developing experiece it's worth it.

# To-do
- Application
- Operations
- Circular Linked List