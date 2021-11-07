#ifndef _LINKED_LIST
#define _LINKED_LIST
typedef struct Node list;
struct Node {
	int data;
	list* next;
};

list* BuildList();
void PrintList(list*);
list* BuildNode(int);
list* addToHead(list*, int);
list* addToTail(list*, int);
list* addToIndex(list*, int, int);
void SelectionSort(list*);
list* FreeList(list*);
list* Delete(list*, int);
#endif
