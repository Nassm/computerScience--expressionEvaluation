#include "interval.h"


double getMin(double b[4]){
    double res = 100; // we consider our interval value are shorter than 100

    for(int i = 0; i < 4; ++i)
    {
        if (i < res){
            res = b[i];
        }
    }
    return res;
}

double getMax(double b[4]){
    double res = 0; // we consider our interval value are under of 0

    for(int i = 0; i < 4; ++i)
    {
        if (i > res){
            res = b[i];
        }
    }
    return res;
}

interval getSum(interval alpha, interval beta)
{
    interval i;
    i.min = alpha.min + beta.min;
    i.max = alpha.max + beta.max;
    return i;
}

interval getDiff(interval alpha, interval beta)
{
    interval i;
    i.min = alpha.min - beta.max;
    i.max = alpha.max - beta.min;
    return i;
}

interval getMul(interval x, interval y)
{
    interval i ;
    double tab[4] = {};
    tab[0] = (x.min * y.min);
    tab[1] = (x.min *y.max);
    tab[2] = (x.max * y.min);
    tab[3] = (x.max * y.max);

    i.min = getMin(tab);
    i.max = getMax(tab);

   return i;
}

interval evaTreeWith(interval X, interval Y)
{
    interval i;
    interval trois = {2.5, 3.5};
    interval deux = {1.5, 2.5};
    interval un = {.5, 1.5};
    interval a = getMul(getMul(trois,X),Y);
    interval b = getSum(getMul(deux,Y),un);
    interval c = getSum(a,b);
    i.min = c.min;
    i.max = c.max;
    return i;
}

void printinterval(interval X)
{
    printf("\n Valeur de l'évaluation = %f \n", ((X.min + X.max)/2));;
}