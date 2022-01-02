#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList LinkedList;

struct LinkedList {
    char *data;
    LinkedList *next;
};

void PrintList(LinkedList *);

LinkedList *BuildNode(char *);

LinkedList *addToEnd(LinkedList *n, char *s);

LinkedList *FreeList(LinkedList *);

LinkedList *DeleteElement(LinkedList *, char *);

int isInList(LinkedList *, char *);


//Custom Functions
LinkedList *MergeLists(LinkedList *, LinkedList *);
