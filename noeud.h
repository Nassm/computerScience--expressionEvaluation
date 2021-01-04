#ifndef NOEUD_H
#define NOEUD_H
#include <stdio.h>
#include <stdlib.h>

/* Tree structure */
typedef struct Node
{
    char op;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

/* new node */
Node * createNode();

/* destroy recursivly OK*/
void destroyNode(Node * node);

#endif // TREE_H
