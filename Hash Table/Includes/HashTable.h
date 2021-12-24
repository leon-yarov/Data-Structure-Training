#include <conio.h>
#include <math.h>
#include "LinkedList.h"
#include <string.h>
#include <malloc.h>
typedef struct HashTableElement HashTableElement;

struct HashTableElement
{
    int key;
    LinkedList* chain;
};

typedef struct HashTable HashTable;

struct HashTable
{
    HashTableElement* hashTable;
    int hashFunction;
    int tableSize;
    int cellsTaken;
    int numOfElements;
};

int asciiStringHashFunction(char* str);
int accumulateStringHashFunction(char* str);
int improvedHashFunction(char* str);

int hash(char* str, HashTable* ht);
HashTable* initTable(int tableSize, int hashFunction);
int insert(HashTable* ht, char* str);
int deleteElement(HashTable* ht, char* str);
int search(HashTable* ht, char* str);
