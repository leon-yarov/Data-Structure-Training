#ifndef _LINKED_LIST
#define _LINKED_LIST

typedef struct Node list;
struct Node {
	int data;
	list* next;
};

//Build List with input values
list* BuildList();

//Prints the list
void PrintList(list*);

//Makes a new node with the input value
list* BuildNode(int);

//Add Node to the start of the list
list* addToHead(list*, int);

//Add Node to the end of the list
list* addToTail(list*, int);

//Add Node to List in index value
list* addToIndex(list*, int, int);

//Sort List with Selection Sort
void SelectionSort(list*);

//Delete list elements
list* FreeList(list*);

//Remove an element from the list
list* Delete(list*, int);

#endif
