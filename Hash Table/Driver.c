#define _CRT_SECURE_NO_WARNINGS

#include "WordSpellChecker.h"

int parseWordsToTable(char *path, HashTable *ht);

SpellingSuggestion *spellingCheck(char *text);

#define  MAX_WORD_LENGTH  30

int main() {
    char *text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
    SpellingSuggestion *spellingSuggestions = spellingCheck(text);
    printSpellingSuggestions(spellingSuggestions);
    return 0;
}

int parseWordsToTable(char *path, HashTable *ht) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
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
