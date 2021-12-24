#include "WordSpellChecker.h"

//allocate string memory
//length - size of string
char *string(int length) {
    return (char *) malloc(sizeof(char) * length + 1);
}


//
int wordSpellingChecker(HashTable *dictionaryTable) {
    LinkedList *list = NULL;

    return 0;
}

//word in hashtable check
//word - word to check
//dictionaryTable - hashtable to check
//return 1 if word is in dictionaryTable, 0 if not
int isWordInDictionary(HashTable *dictionaryTable, char *word) {
    if (word == NULL || !search(dictionaryTable, word)) {
        return 0;
    }
    return 1;
}

//word space check [1]
//word - word to check
//dictionaryTable - hashtable to check
//returns list of suggested words
LinkedList *addSpaceCheck(HashTable *dictionaryTable, char *word) {

    LinkedList *list = NULL;
    char *first = string(strlen(word)), *second = string(strlen(word));
    for (int i = 1; i < strlen(word); i++) {
        strncpy(first, word, i); //get the first half of the word
        strncpy(second, word + i, strlen(word) - i); // get the second half of the word
        if (isWordInDictionary(dictionaryTable, first) && strcmp(first, word) != 0) {
            addToStart(list, first); //add the first half to the list if it is in the dictionary
        }
        if (isWordInDictionary(dictionaryTable, second) && strcmp(second, word) != 0) {
            addToStart(list, second); //add the second half to the list if it is in the dictionary
        }
    }
    free(first); //free mem
    free(second);
    return list;
}

//replace char check [2]
//word - word to check
//dictionaryTable - hashtable to check
//returns list of suggested words
LinkedList *replaceCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    char *temp = string(strlen(word));
    for (int i = 0; i < strlen(word); i++) { //for every letter
        strcpy(temp, word); //copy the word
        for (int j = 0; j < 26; ++j) { //for every letter in the alphabet
            char c = 'a' + j; //get the 'a' to 'z' letters
            temp[i] = c; //replace letter at index i
            if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
                addToStart(list, temp); //add the word to the list if it is in the dictionary
            }
        }
    }
    free(temp); //free mem
    return list;
}

//delete char check [3]
//word - word to check
//dictionaryTable - hashtable to check
//returns list of suggested words
LinkedList *deleteCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    for (int i = 0; i < strlen(word); i++) { //for every letter
        char *temp = string(strlen(word));
        strcpy(temp, word); //copy the word
        int idxToDel = i; //set the index to delete
        memmove(&temp[idxToDel], &temp[idxToDel + 1], strlen(temp) - idxToDel); //move the letters in mem
        if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
            addToStart(list, temp); //add the word to the list if it is in the dictionary
        }
        free(temp); //free mem
    }
    return list;
}

//add char check [1]
//word - word to check
//dictionaryTable - hashtable to check
//returns list of suggested words
LinkedList *addCharacterCheck(HashTable *dictionaryTable, char *word) {
    LinkedList *list = NULL;
    char *temp = string(strlen(word) + 1);
    for (int i = 1; i <= strlen(word); i++) { //for every letter but the first
        for (int j = 0; j < 26; ++j) { //for every letter in the alphabet
            strncpy(temp, word, i); //copy the word until the index i
            temp[i] = 'a' + j; //add the letter to the index i
            strcat(temp, word + i); //append the rest of the word
            if (isWordInDictionary(dictionaryTable, temp) && strcmp(temp, word) != 0) {
                addToStart(list, temp); //add the word to the list if it is in the dictionary
            }
        }
    }
    free(temp); //free mem
    return list;
}

