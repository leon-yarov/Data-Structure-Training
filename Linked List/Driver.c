//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
#include "206817181.h"

int main()
{
	list* head = NULL;
	int num, index;
	head = BuildList();

	PrintList(head);
	/*
	printf("\nEnter a number for new head node: ");
	scanf("%d", &num);
	head = addToHead(head, num);
	PrintList(head);
	*/
	list* test = BuildNode(10);
	PrintList(head);

	//test function from file 206817181.c
	SearchValueInList(head, 10);
	CheckListAscendingOrder(head);
	AddItemToAscendingList(&head, 5);
	PrintList(head);
	GetMaxValueInList(head);
	SumOddValuesInList(head);
	MostFrequentValueInList(head);

	/*
	printf("\nEnter a number for new tail node: ");
	scanf("%d", &num);
	head = addToTail(head, num);
	PrintList(head);

	printf("\nEnter a number and an index for new node: ");
	scanf("%d%d", &num, &index);
	head = addToIndex(head, num, index);
	PrintList(head);

	printf("\nSorted List: ");
	SelectionSort(head);
	PrintList(head);

	printf("\nEnter a value for delete: ");
	scanf("%d", &num);
	head = Delete(head, num);
	PrintList(head);
	*/
	head = FreeList(head);

	return 0;
}