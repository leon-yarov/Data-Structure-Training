#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main()
{
	srand(time(NULL));
	node *root;
	int H, num, NumToSearch;
	root = randomTree();
	H = height(root);
	printf("\n\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);
	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);
	deleteTree(root);
	printf("\nTree deleted\n");
	return 0;
}