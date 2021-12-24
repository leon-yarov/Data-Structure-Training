#include "LinkedList.h"


LinkedList *BuildNode(char *data) {
    LinkedList *temp = (LinkedList *) malloc(sizeof(LinkedList));
    if (temp == NULL) {
        printf("Memory allocation failed");
        exit(1); //Memory allocation failed
    }
    temp->data = (char *) malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(temp->data, data);
    return temp;
}

LinkedList *addToStart(LinkedList *n, char *s) {
    LinkedList *t = BuildNode(s);
    t->next = n;
    return t;
}

LinkedList *FreeList(LinkedList *l) {
    LinkedList *temp = l;
    while (temp != NULL) {
        LinkedList *next = temp->next;
        free(temp);
        temp = next;
    }
}

LinkedList *DeleteElement(LinkedList *ls, char *str) {
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
    return NULL;
}

int isInList(LinkedList *ls, char *str) {
    LinkedList *temp = ls;
    while (temp != NULL) {
        if (strcmp(temp->data, str) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void PrintList(LinkedList *ls) {
    LinkedList *temp = ls;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}
