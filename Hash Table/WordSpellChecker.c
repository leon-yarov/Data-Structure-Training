#include "WordSpellChecker.h"

char *string(int length) {
    return (char *) malloc(sizeof(char) * length + 1);
}


int wordSpellingChecker(HashTable *dictionaryTable) {
    LinkedList *list = NULL;

    return 0;
}

int isWordInDictionary(HashTable *dictionaryTable, char *word) {
    if (word == NULL || !search(dictionaryTable, word)) {
        return 0;
    }
    return 1;
}

LinkedList *addSpaceCheck(HashTable *dictionaryTable, char *word) {

    LinkedList *list = NULL;
    char *first = string(strlen(word)), *second = string(strlen(word));
    for (int i = 1; i < strlen(word); ++i) {
        strncpy(first, word, i);
        strncpy(second, word + i, strlen(word) - i); //might be i - 1
        if (isWordInDictionary(dictionaryTable, first) && strcmp(first, word) != 0) {
            addToStart(list, first);
        }
        if (isWordInDictionary(dictionaryTable, second) && strcmp(second, word) != 0) {
            addToStart(list, second);
        }
    }
    free(first);
    free(second);
    return list;
}

LinkedList *replaceCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    char *temp = string(strlen(word));
    for (int i = 0; i < strlen(word); ++i) {
        strcpy(temp, word);
        for (int j = 0; j < 26; ++j) {
            char c = 'a' + j; //get the 'a' to 'z' letters
            temp[i] = c;
            if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
                addToStart(list, temp);
            }
        }
    }
    free(temp);
    return list;
}

LinkedList *deleteCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    for (int i = 0; i < strlen(word); ++i) {
        char *temp = string(strlen(word));
        strcpy(temp, word);
        int idxToDel = i;
        memmove(&temp[idxToDel], &temp[idxToDel + 1], strlen(temp) - idxToDel);
        if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
            addToStart(list, temp);
        }
        free(temp);
    }
    return list;
}

LinkedList *addCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    char *temp = string(strlen(word) + 1);
    for (int i = 1; i <= strlen(word); ++i) {
        for (int j = 0; j < 26; ++j) {
            strncpy(temp, word, i);
            temp[i] = 'a' + j;
            strncpy(temp, word + i, strlen(word) - i); //might be i - 1
            if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
                addToStart(list, temp);
            }
        }
    }
    free(temp);
    return list;
}


