#include "LinkedList.h"

//Build a linked list node
//data: the data to be stored in the node
//return: the node
LinkedList *BuildNode(char *data) {
    LinkedList *temp = (LinkedList *) malloc(sizeof(LinkedList));
    if (temp == NULL) {
        printf("Memory allocation failed");
        exit(1); //Memory allocation failed
    }
    temp->data = (char *) malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(temp->data, data);
    temp->next = NULL;
    return temp;
}

//Insert a node at the end of the linked list
//n: the head of the linked list
//s: the data to be stored in the node
//return: the head of the linked list
LinkedList *addToEnd(LinkedList *n, char *s) {
    if (n == NULL) {
        return BuildNode(s);
    }
    LinkedList *temp = n;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = BuildNode(s);
    return n;
}

//Free the linked list memory
//l: the head of the linked list
LinkedList *FreeList(LinkedList *l) {
    if (l == NULL) { return NULL; }
    printf("Freeing the list that starts with '%s'\n", l->data);
    LinkedList *temp = l;
    while (temp != NULL) {
        LinkedList *next = temp->next;
        free(temp);
        temp = next;
    }
    return NULL;
}

//Delete a node from the linked list
//ls: the head of the linked list
//str: the data of the node to be deleted
//return: the head of the linked list
LinkedList *DeleteElement(LinkedList *ls, char *str) {
    printf("Deleting '%s' from the list\n", str);
    if (strcmp(ls->data, str) == 0)
        return ls;
    if (ls == NULL || str == NULL)
        return NULL;
    LinkedList *temp = ls;
    LinkedList *prev = NULL;
    while (temp->next != NULL) {
        if (strcmp(temp->data, str) == 0) {
            prev->next = temp->next;
            return temp;
        }
        prev = temp;
        temp = temp->next;
    }
    return ls;
}

//Check if the item in list
//ls: the head of the linked list
//str: the data to be checked
//return: 1 if the item is in the list, 0 otherwise
int isInList(LinkedList *ls, char *str) {
    if (ls == NULL)
        return 0;
    LinkedList *temp = ls;
    while (temp != NULL) {
        if (strcmp(temp->data, str) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//Merge lists without duplicates
//l1: the head of the first list
//l2: the head of the second list
//return: the head of the merged list
LinkedList *MergeLists(LinkedList *ls1, LinkedList *ls2) {
    if (ls1 == NULL)
        return ls2;
    LinkedList *temp = ls1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (ls2 != NULL) {
        if (!isInList(ls1, ls2->data)) {
            temp->next = ls2;
            temp = temp->next;
        }
        ls2 = ls2->next;
    }
    return ls1;
}

//Print the linked list
//l: the head of the linked list
void PrintList(LinkedList *ls) {
    LinkedList *temp = ls;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}



