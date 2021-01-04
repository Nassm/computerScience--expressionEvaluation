#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"

/* Structure de l'arbre */
typedef struct Tree
{
    struct Node * current;
} Tree;


/* Fonction de création d'un arbre */
Tree * createTree ();

/* Fonction de libération de la mémoire recursif OK */
void destroyTree(Node * node);

/* Fonction de libération de la mémoire recursif OK */
void printTree(Node * noeud);

/* Fonction de remplissage d'un arbre */
void fillTree(Node * courant, char * expr);

/* Fonction d'évaluation OK */
int evalTree(Node * node);

/* Fonction de construction d'un chaine par index*/
char * getStringFrom(char src[], int fromIndex, int toIndex);

#endif // ARBRE_H