#include "stdio.h"
#include "arbre.h"
#include "interval.h"


interval X = {2.0, 5.0};
interval Y = {-.5, +.5};
const int expSize = 100;


int main(void)
{
    //char * expression = "3*x+y";


    
    char expression[expSize];
    char confirm[expSize];


    /* User procedure */
    printf("Veuillez saisir une expression (sans parenthèses, ni espaces) : ");

    gets(expression);

    printf("Vous avez saisi : %s \n", expression);

    printf("\n Confirmez ? (oui | non) : ");

    gets(confirm);

    if(confirm[0] == 'n' || confirm[0] == 'N')
    {
        printf("Ok. Veuillez relancer le programme \n");
        return 0;
    }


    /* creating tree */
    Tree * tree = createTree();

    /* filling tree*/
    fillTree(tree->current, expression);

    /* printing tree*/
    printf("\n Afficher l'arbre d'expression ? (oui | non) : ");

    gets(confirm);

    if(confirm[0] == 'n' || confirm[0] == 'N')
    {
        printf("Ok. Veuillez relancer le programme \n");
        return 0;
    }

    printf("\n");

    printTree(tree->current);

    printf("\n");

    /* evaluating tree*/

    printf("\n Procéder à l'évaluation de l'expression ? (oui | non) : ");

    gets(confirm);

    if(confirm[0] == 'n' || confirm[0] == 'N')
    {
        printf("Ok. Veuillez relancer le programme \n");
        return 0;
    }

    interval X = {2.0, 5.0};
    interval Y = {-.5, +.5};
    interval a = evaTreeWith(X,Y);
    printinterval(a);


    /* liberating memory*/
    destroyTree(tree->current);

    return 0;
}
