#include "HashTable.h"

//String hash function
//Str - string
//Return - ASCII of the first letter
//If all the given words start with the same letter the runtime will be O(n)
int asciiStringHashFunction(char *str) {
    return (int) (str[0]);
}

//Sum all the letters
//str - string
//Return ASCII sum of all letters
int accumulateStringHashFunction(char *str) {
    if (strlen(str) == 0) return 0;
    return (int) (str[0]) + accumulateStringHashFunction(str + 1);
}

//TODO: figure out what to do with the return value
int improvedHashFunction(char *str) {
    int sum = 0, n = strlen(str);
    for (int i = 0; i < n; i++) {
        sum += str[i] * pow(31, n - 1 - i);
    }
    return sum;
}


HashTable *initTable(int tableSize, int hashFunction) {
    HashTable *table = malloc(sizeof(HashTable));
    if (table == NULL) exit(1);
    table->tableSize = tableSize;
    table->hashFunction = hashFunction;
    table->hashTable = (HashTableElement *) malloc(sizeof(HashTableElement) * tableSize);
    if (table->hashTable == NULL) exit(1);
    for (int i = 0; i < tableSize; i++) {
        table->hashTable[i].key = -1;
        table->hashTable[i].chain = NULL;
    }
    return table;
}

//Get hash table element
//table - hash table
//str - string
//Return - hash table index
int hash(char *str, HashTable *ht) {
    switch (ht->hashFunction) {
        case 1:
            return abs(asciiStringHashFunction(str)) % ht->tableSize;
        case 2:
            return abs(accumulateStringHashFunction(str)) % ht->tableSize;
        case 3:
            return abs(improvedHashFunction(str)) % ht->tableSize;
        default:
            return 0;
    }
}

//Insert a new element into the hash table
//ht - hash table
//str - string to insert
//return - 1 if successful, 0 if not
int insert(HashTable *ht, char *str) {
    if (str == NULL || search(ht, str)) return 0;
    HashTableElement *t = &(ht->hashTable[hash(str, ht)]);  //Get the hash table element
    t->chain = addToStart(t->chain, str); //add the string to the chain
    if (t->key == -1) t->key = hash(str, ht); //if key is not defined, set it to the hash value
    return 1;
}


//Delete element from the table
//ht - hash table
//str - string to delete
//Return 1 if the element was deleted, 0 if it wasn't
int deleteElement(HashTable *ht, char *str) {
    if (str == NULL || !search(ht, str)) return 0;
    HashTableElement *t = &(ht->hashTable[hash(str, ht)]); //Get the element
    free(DeleteElement(t->chain, str)); //Delete the element in the chain
    return 1;
}

//Search for a string in the hash table
//ht - hash table
//str - string to search for
//Return 1 if found, 0 if not
int search(HashTable *ht, char *str) {
    if (str == NULL) return 0;
    HashTableElement *t = &(ht->hashTable[hash(str, ht)]); //get HashTable entry
    return isInList(t->chain, str);
}

















