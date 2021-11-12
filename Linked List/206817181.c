#include <stdio.h>
#include "206817181.h"

void SearchValueInList(list* head, int value){
    list* current = head;
    while(current != NULL){
        if(current->data == value){
            printf("%d is in the list\n", value);
            return;
        }
        current = current->next;
    }
    printf("%d is not in the list\n", value);
}

void CheckListAscendingOrder(list* head){
    list* current = head;
    while(current != NULL){
        if(current->next != NULL && current->data < current->next->data){
            printf("List is not in ascending order\n");
            return;
        }
        current = current->next;
    }
    printf("List is in ascending order\n");
}

void AddItemToAscendingList(list** head, int value){
    list* current = *head;
    list* newNode = BuildNode(value);
    if(current == NULL){
        *head = newNode;
        return;
    }
    while(current->next != NULL){
        if (current->next->data > value){
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    current->next = newNode;
}

int GetMaxValueInList(list* head){
    list* current = head;
    int max = current->data;
    while(current != NULL){
        if(current->data > max) max = current->data;
        current = current->next;
    }
    printf("Max value in list is %d\n", max);
    return max;
}

int SumOddValuesInList(list* head){
    list* current = head;
    int sum = 0;
    while (current != NULL)
    {
        if (current->data % 2 == 1) sum += current->data;
        current = current->next;
    }
    return sum;
}

int MostFrequentValueInList(list* head){
    list* current = head;
    int max = 0;
    int maxValue = 0;
    while(current != NULL){
        int count = 0;
        list* temp = head;
        while(temp != NULL){
            if(temp->data == current->data) count++;
            temp = temp->next;
        }
        if(count > max){
            max = count;
            maxValue = current->data;
        }
        current = current->next;
    }
    printf("Most frequent value in list is %d\n", maxValue);
    return maxValue;
}
