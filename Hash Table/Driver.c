#define _CRT_SECURE_NO_WARNINGS

#include "WordSpellChecker.h"

int parseWordsToTable(char *path, HashTable *ht);

void printSpellingSuggestions(SpellingSuggestion *suggestions);

SpellingSuggestion *spellingCheck(char *text);

#define  MAX_WORD_LENGTH  30

int main() {
    char *text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
    SpellingSuggestion *spellingSuggestions = spellingCheck(text);
    printSpellingSuggestions(spellingSuggestions);
    return 0;
}


SpellingSuggestion *spellingCheck(char *text) {
    HashTable *ht = initTable(6000, 1); //create a table with 6000 entries
    if (parseWordsToTable("I:\\CLion Projects\\Data-Structure-Training\\Hash Table\\dictionary.txt", ht) == 0) {
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
        printf("Working on: %s\n", word);
        used = addToStart(used, word); //add the word to the used list
        SpellingSuggestion *suggestion = (SpellingSuggestion *) malloc(sizeof(SpellingSuggestion));
        suggestion->originalWord = word; //save original word
        suggestion->suggestions = getWordSuggestions(ht, word); //get the suggestions for the word
        suggestion->next = suggestions;
        suggestions = suggestion;
        word = strtok(NULL, " "); //get the next word
    }
    free(sentence); //free the copied text
    return suggestions;
}

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

void printSpellingSuggestions(SpellingSuggestion *suggestions) {
    if (suggestions == NULL) return;
    printf("The word [%s] was misspelled. ", suggestions->originalWord);
    if (suggestions->suggestions == NULL) {
        printf("No suggestions found\n");
    } else {
        printf("Did you mean: \n");
        PrintList(suggestions->suggestions);
    }
    printf("\n");
    printSpellingSuggestions(suggestions->next);
}
