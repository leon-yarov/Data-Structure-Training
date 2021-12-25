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
//    printf("Adding '%s' to the start of the list\n", s);
    LinkedList *t = BuildNode(s);
    t->next = n;
    return t;
}

LinkedList *FreeList(LinkedList *l) {
    printf("Freeing the list that starts with '%s'\n", l->data);
    LinkedList *temp = l;
    while (temp != NULL) {
        LinkedList *next = temp->next;
        free(temp);
        temp = next;
    }
}

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
    return NULL;
}

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

//TODO: This function is not working properly, skips some elements
LinkedList *MergeLists(LinkedList *ls1, LinkedList *ls2) {
    LinkedList *temp = ls1;
    if (ls1 == NULL)
        return ls2;
    else if (ls2 == NULL)
        return ls1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (ls2->next) {
        if (isInList(ls1, ls2->data)) {
            ls2 = ls2->next;
            continue;
        }
        temp->next = ls2;
        temp = temp->next;
        ls2 = ls2->next;
    }
    return ls1;
}

void PrintList(LinkedList *ls) {
    LinkedList *temp = ls;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}



