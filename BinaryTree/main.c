#include "HW2.h"

//print binary tree inside the console as a tree
void printBinaryTree(node *root)
{
}

int main(int argc, char const *argv[])
{
    srand(time(((void *)0)));
    node *t = randomTree();
    PrintLevelOrder(t);

    int item = 0;
    printf("\nEnter item to search: ");
    scanf("%d", &item);
    printf("Binary tree contains %d?: %d\n", item, contains(t, item));
    printf("Internal node count: %d\n", countNodes(t));
    printf("Sum of internal keys: %d\n", sumOfInternalKeys(t));

    printf("Enter level to see stastics: ");
    scanf("%d", &item);
    printf("Node count: %d\n", levelStatistics(t, item));
    printf("The tree is a full tree?: %d\n", isFull(t));
    return 0;
}
