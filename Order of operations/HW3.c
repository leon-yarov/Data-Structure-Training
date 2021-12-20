#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<malloc.h>

//node structure
typedef struct node{
    char data[50];
    struct node *left, *right;
}node;

//stack structure
typedef struct stack{
    node *data;
    struct stack* next;
}stack;

//if stack is empty return 1
int isEmpty(stack *top){
    return top == NULL;
}

//pop the top element from stack
//base - stack pointer
//return - popped element
node* pop(stack** base){
    if (isEmpty(*base)){
        printf("Stack is empty or invalid expression\n");
        exit(1);
    }
    node* temp = (*base)->data;
    stack* temp2 = *base;
    *base = (*base)->next;
    free(temp2); //free mem
    return temp; //return the data from stack's node
}

//Free binary tree memory
//node - tree root
void freeTree(node* root){
    if(root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//push the node to stack
//base - stack base pointer
///node - node to be pushed
void push(stack** base, node* data){
    stack* temp = (stack*)malloc(sizeof(stack));
    if (temp == NULL){
        printf("\nMemory allocation failed");
        exit(1); //exit if memory allocation failed
    }
    temp->data = data;
    temp->next = *base;
    *base = temp;
}

//print in post order using the root
//rootNode - root of the tree
void postOrder(node *treeNode)
{
    if (treeNode == NULL)return;
    postOrder(treeNode->left);
    postOrder(treeNode->right);
    printf("%s ", treeNode->data);
}

//initialize the stack
//data - the data to be pushed to stack
//returns - the stack
stack* createStack(node* data){
    stack* base = (stack*)malloc(sizeof(stack));
    if (base == NULL){
        printf("Stack is empty");
        exit(1); //Memory allocation failed
    }
    base->data = data;
    base->next = NULL;
    return base;
}

//make a new tree node
//data - the data to be pushed to stack
//returns - tree node
node* makeNode(char* data){
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL){
        printf("Memory allocation failed");
        exit(1); //Memory allocation failed
    }
    strcpy(temp->data, data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//print all stack elements
//base - stack base pointer
void printStack(stack* head){
    printf("\nStack: [");
    stack* temp = head;
    while (temp != NULL){
        printf("%s ", temp->data->data);
        temp = temp->next;
    }
    printf("]\n");
}

//check if the char is an operator
//c - the char to be checked
//returns - 1 if it is an operator, 0 otherwise
int isOperator(char *c){
    if (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0 || strcmp(c,"^") == 0)
        return 1;
    return 0;
}
int isOperand(char * c){
    if (strcmp(c, "0") == 0) return 0;
    int num = atoi(c);
    if (num == 0) return INT_MIN;
    return num;
}

//evaluate expression to a binary tree
//postfix - the postfix expression
//returns - the root of the tree
node* create_expr_tree(char *postfix)
{
    char *token = strtok(postfix, " ");  //get the first token in the string
    stack* head = createStack(makeNode(token)); //create the stack
    while (token != NULL)
    {
        token = strtok(NULL, " "); //next token
        if (token == NULL) break; //end of expression
        if (isOperand(token) != INT_MIN){ //while a token is a number
            node* temp = makeNode(token);
            push(&head, temp); //add number to stack
        }
        else if (isOperator(token))
        { //if the token is an operator
            node* temp = makeNode(token); //make an operator node
            temp->right= pop(&head);
            temp->left = pop(&head);
            push(&head, temp);
        }
    }
    return head->data;
}

//print in-order with parenthesis
//treeNode - the root of the tree
void inOrder(node *treeNode)
{
    if (treeNode == NULL)
        return;
    if (isOperator(treeNode->data))
        printf("(");
    inOrder(treeNode->left);
    printf(" %s ", treeNode->data);
    inOrder(treeNode->right);
    if (isOperator(treeNode->data))
        printf(")");

}

//print pre order
//treeNode - the root of the tree
void preOrder(node *treeNode)
{
    if (treeNode == NULL)
        return;
    printf("%s ", treeNode->data);
    preOrder(treeNode->left);
    preOrder(treeNode->right);
}

//do simple calculations (INT_MIN -> error)
//n, m - the numbers to calculate on
//op - the operator
int doMath(int n, int m, char op){
    switch (op){
    case '+': return n + m;
    case '-': return n - m;
    case '*': return n * m;
    case '/': return m == 0 ? INT_MIN : n / m;
    case '^': break; //calculate power down below
    default: return INT_MIN; //if op failed return min
    }
    //power calculation
    int result = 1;
    for (int i = 0; i < m; i++) result *= n;
    return result;
}

//translate binary tree to final output
//treeNode - the root of the tree
int evaluateExpression(node *treeNode)
{
    if (isOperator(treeNode->data)){
        int n = evaluateExpression(treeNode->left);
        int m = evaluateExpression(treeNode->right);
        int calc = doMath(n, m, *treeNode->data);
        if (calc == INT_MIN) {
            printf("Error: division by zero or invalid operator\n");
            exit(1);
        }
        return calc;
    }
    else
        return atoi(treeNode->data);
}

//main function
int main()
{
	char ex[][50] = { { "2 8 + 7 3 ^ *" }, { "98 2 * 8 +" }, { "2 5 * 6 4 / ^ 2 3 + +" },
	{ "1 2 3 4 + + +" }, { "12 32 + 3 + 4 +" } };
	for (int i = 0; i < 5; i++){
		node* treeRoot = create_expr_tree(ex[i]);
        if (treeRoot == NULL) {
            printf("Error: invalid expression\n");
            exit(1);
        }
		//Traversal Operation on expression tree
		printf("\nIn-Order Traversal :   ");
		inOrder(treeRoot);
		printf("\nPre-Order Traversal :   ");
		preOrder(treeRoot);
		printf("\nPost-Order Traversal :   ");
		postOrder(treeRoot);
		//evaluate expression from the expression tree:
		printf("\nEvaluate the expression from the tree: %d\n", evaluateExpression(treeRoot));
        freeTree(treeRoot); //free tree memory
	}

	return 0;
}