# Linked List in C
A linked list is a linear data structure in which elements are linked together using pointers. Each node of the list consists of two items :
1. Value of the current element
2. Reference to the next element

The last node of the *Linked List* has a reference to NULL. The start of the *Linked List* is actually not a node but a reference to the first node of the *Linked List* and is called head. If the *Linked List* is empty, the head is a null reference.

![Linked List](LinkedList.png)

### Advantages of Linked List
1. It does not require any initial size as it is a dynamic data structure and it can grow and shrink at runtime by allocating and deallocating memory.
2. The cost of *Inserting* or *Deleting* elements inside linked list is very low as we do not have to shift all the elements present in the list. 

### Disadvantages of Linked list
1. It takes a lot of memory space as the reference to the next element has to be stored.
2. Direct access to elements inside the list is not possible. We have to transverse the list to reach a specific index which increases the time complexity.

