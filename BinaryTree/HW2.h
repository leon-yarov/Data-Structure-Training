#include "BinaryTree.h"

//Check if binary tree is empty
int isEmpty(node *root);

//Print binary tree leafs
void printLeaves(node *root);

//Check if binary tree contains key
int contains(node *root, int key);

//Count all the nodes in binary tree
int countNodes(node *root);

//Sum all internal nodes in binary tree
int sumOfInternalKeys(node *root);

//Level statistics of a binary tree
int levelStatistics(node *root, int level);

//Check if the binary tree is a full binary tree
int isFull(node *root);
