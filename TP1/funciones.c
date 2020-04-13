#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int sumar (int a, int b)
{
    return a + b;
}

int restar (int a, int b)
{
    return a - b;
}

int dividir (int a, int b)
{
    return (float)a/b;
}

int multiplicar (int a, int b)
{
    return a*b;
}

int factorial (int a)
{
    int fact;

    if(a==1)
    {
        fact=1;
    }
    else
    {
        fact= a*factorial(a-1);
    }
    return fact;
}
