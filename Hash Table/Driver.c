#define _CRT_SECURE_NO_WARNINGS

#include "WordSpellChecker.h"

int parseWordsToTable(char *path, HashTable *ht);

void printSpellingSuggestions(SpellingSuggestion *suggestions);

SpellingSuggestion *spellingCheck(char *text);

void FreeSpelling(SpellingSuggestion*);
#define  MAX_WORD_LENGTH  30

int main() {
    char *text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
    SpellingSuggestion *spellingSuggestions = spellingCheck(text);
    printSpellingSuggestions(spellingSuggestions);
//    FreeSpelling(spellingSuggestions);
    return 0;
}

// Spell-check words from the given input
// text: input text
// Return a list of suggestions for each word
SpellingSuggestion *spellingCheck(char *text) {
    HashTable *ht = initTable(6000, 1); //create a table with 6000 entries
    if (parseWordsToTable("C:\\Users\\dori6\\CLionProjects\\Data-Structure-Training\\Hash Table\\dictionary.txt", ht) == 0) {
        printf("Error: File not found\n");
        return NULL;
    }
    SpellingSuggestion *suggestions = NULL; //Suggestion list
    LinkedList *used = NULL; //Used words list (to avoid duplicates)
    char *sentence = (char *) malloc(sizeof(char) * strlen(text) + 1); //copy of the sample text
    strcpy(sentence, text); //copy the text to the sentence
    char *word = strtok(sentence, " "); //get the first word
    while (word != NULL) { //loop all words
        if (isInList(used, word) || search(ht, word)) { //if the word is already in the used list or dictionary
            word = strtok(NULL, " ");
            continue;
        }
        char* copy = (char*)malloc(strlen(word) + 1); //copy the word
        strcpy(copy, word);
        printf("Working on: %s\n", copy);
        used = addToEnd(used, word); //add the word to the used list
        SpellingSuggestion *suggestion = (SpellingSuggestion *) malloc(sizeof(SpellingSuggestion));
        suggestion->originalWord = copy; //save original word
        suggestion->suggestions = getWordSuggestions(ht, copy); //get the suggestions for the word
        suggestion->next = suggestions;
        suggestions = suggestion;
        word = strtok(NULL, " "); //get the next word
    }
    free(ht->hashTable);
    free(ht);
    free(sentence); //free the copied text
    return suggestions;
}

//Convert the file to a hash table
//path: path to the file
//ht: the hash table
//Return 0 if the file is not found
int parseWordsToTable(char *path, HashTable *ht) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    printf("File opened successfully\n");
    char *word = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
    while (fscanf(fp, "%s", word) != EOF) {
        int res = insert(ht, word);
        if (res == 0) {
            printf("Error inserting word\n");
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

//Print the suggestions for a word
//suggestions: the suggestions for the word
void printSpellingSuggestions(SpellingSuggestion *suggestions) {
    if (suggestions == NULL) return;
    printSpellingSuggestions(suggestions->next);
    printf("The word [%s] was misspelled. ", suggestions->originalWord);
    if (suggestions->suggestions == NULL) {
        printf("No suggestions found\n");
    } else {
        printf("Did you mean: \n");
        PrintList(suggestions->suggestions);
    }
    printf("\n");
}

//Free all memory allocated for the suggestions
void FreeSpelling(SpellingSuggestion* s){
    if(s==NULL) return;
    FreeSpelling(s->next);
    free(s->originalWord);
    FreeList(s->suggestions);
    free(s);
}
