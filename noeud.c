#include "noeud.h"

Node *createNode()
{
    Node * node = malloc(sizeof (Node));

    if(node == NULL)
    {
        fprintf(stderr, "Error when allocating memory of node. \n");
        exit(EXIT_FAILURE);
    }

    return node;
}

void destroyNode(Node * node)
{
    if(node == NULL)
    {
        return;
    }

    destroyNode(node->left);
    destroyNode(node->right);
    free(node);
}
