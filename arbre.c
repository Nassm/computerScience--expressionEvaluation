#include "arbre.h"


Tree * createTree()
{
    Tree * tree = malloc(sizeof(Tree));
    if(tree == NULL)
    {
        fprintf(stderr, "Error when allocating memory of tree. \n");
        exit(EXIT_FAILURE);
    }

    tree->current = malloc(sizeof(Node));
    if(tree->current == NULL)
    {
        fprintf(stderr, "Error when allocating memory of node. \n");
        exit(EXIT_FAILURE);
    }

    return tree;
}


void destroyTree(Node * node)
{
    if(node == NULL)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    free(node);
}


void printTree(Node * node)
{
    if(node == NULL)
    {
        return;
    }

    /* infixed route */

    printTree(node->left);

    if(node->op == 'c')
    {
        printf("%d ", node->value);

    } else
    {
        printf("%c ", node->op);
    }

    printTree(node->right);
}


void fillTree(Node * current, char * expr)
{
    if(current == NULL)
    {
        current = malloc(sizeof(Node));
    }

    int p;
    char * chaineGauche = "";
    char * chaineDroite = "";

    p = strlen(expr);
    while((p>0) && (expr[p] != '+') && (expr[p] != '-') && (expr[p] != '*') && (expr[p] != '/'))
    {
        --p; // decrement index of exp for reading form R -> L
    }

    if(p>0)
    {
        chaineGauche = getStringFrom(expr, 0, p-1);
        chaineDroite = getStringFrom(expr, p+1, strlen(expr)-1);

        current->op = expr[p];
        current->right = createNode(); /* creating right child */
        current->right->op = 'c';

        if(chaineDroite != "")
        {
            if((int)strtold(chaineDroite, NULL) == 0) // it's a variable
            {
                current->right->op = chaineDroite[0];
                current->right->value = 0;

            } else // it's an integer
            {
                current->right->value = (int)strtold(chaineDroite, NULL); // set integer
            }

        } else
        {
            current->right->value = 0;
        }

    } else // no more operator, so integer or variable
    {
        current->op = 'c';

        if(expr != "")
        {
            // assign here

            if((int)strtold(expr, NULL) == 0)
            {
                current->op = expr[0];
                current->value = 0;
            } else
            {
                current->value = (int)strtold(expr, NULL);
            }
        } else
        {
            current->value = 0;
        }
    }


    /* creating left child */

    if(chaineGauche != "")
    {
        p = strlen(expr);

        while((p>0) && (expr[p] != '+') && (expr[p] != '-') && (expr[p] != '*') && (expr[p] != '/'))
        {
            --p;
        }

        if(p > 0)
        {
            current->left = createNode();

            fillTree(current->left, chaineGauche); // récursive call

        } else // it's end
        {
            if((int)strtold(chaineGauche, NULL) == 0)
            {
                current->left->op = chaineGauche[0];
                current->left->value = 0;

            } else {
                current->left->op = 'c';
                current->left->value = (int)strtold(chaineGauche, NULL);
            }
        }

    } else // reinitialization
    {
        if(current->left != NULL)
        {
            if((int)strtold(expr, NULL) == 0)
            {
                current->left->op = expr[0];
                current->left->value = 0;

            } else {
                current->left->op = 'c';
                current->left->value = 0;
            }
        }
    }
}


int evalTree(Node * node)
{
    // TODO : ne marche pas :(
    int res;
    if(node == NULL){
        res = 0;
        return res ;
    }

    if (node->op == 'c')
    {
        res = node->value;

    } else {
        switch (node->op)
        {
            case '+' : res = evalTree(node->left) + evalTree(node->right);
            case '-' : res = evalTree(node->left) - evalTree(node->right);
            case '*' : res = evalTree(node->left) * evalTree(node->right);
            case '/' : res = evalTree(node->left) / evalTree(node->right);
            break;
        }
    }
    return res;
}


char * getStringFrom(char src[], int fromIndex, int toIndex){
    int counter = 0;
    char * dest = malloc(fromIndex+toIndex);
    for (int i = fromIndex; i < toIndex+1; ++i)
    {
        dest[counter] = src[i];
        ++counter;
    }
    return dest;
}
