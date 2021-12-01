#include "HW2.h"
#define NULL ((void *)0)

int isEmpty(node *root)
{
    return root == NULL;
}

void printLeaves(node *root)
{
    if (isEmpty(root))
        return;
    if (Left(root) == NULL && Right(root) == NULL)
        printf("%d ", root->data);
    printLeaves(Left(root));
    printLeaves(Right(root));
}

int contains(node *root, int key)
{
    if (isEmpty(root))
        return 0;
    if (root->data == key)
        return 1;
    if (contains(Left(root), key) || contains(Right(root), key))
        return 1;
    return 0;
}

int countNodes(node *root)
{
    if (isEmpty(root) || (Left(root) == NULL && Right(root) == NULL))
        return 0;
    return 1 + countNodes(Left(root)) + countNodes(Right(root));
}

int sumOfInternalKeys(node *root)
{
    if (isEmpty(root) || (Left(root) == NULL && Right(root) == NULL))
        return 0;
    return sumOfInternalKeys(Left(root)) + sumOfInternalKeys(Right(root)) + root->data;
}

// count the number of nodes in that level
int levelStatistics(node *root, int level)
{
    if (level < 0)
    {
        printf("Invalid level\n");
        return 0;
    }
    if (isEmpty(root))
        return 0;
    if (level == 0)
    {
        printf("%d ", root->data);
        return 1;
    }
    return levelStatistics(Left(root), level - 1) + levelStatistics(Right(root), level - 1);
}

int isFull(node *root)
{
    if (isEmpty(root))
        return 1;
    if (Left(root) == NULL && Right(root) == NULL)
        return 1;
    if (Left(root) == NULL || Right(root) == NULL)
        return 0;
    return isFull(Left(root)) && isFull(Right(root));
}