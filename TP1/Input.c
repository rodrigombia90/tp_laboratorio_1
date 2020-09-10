#include "input.h"

int reingresarA(int a)
{
    printf("Reingrese operando 1: ");
    scanf("%d",&a);
    return a;
}

int reingresarB(int b)
{
    printf("Reingrese operando 2: ");
    scanf("%d",&b);
    return b;
}

int sumarNumeros (int a, int b)
{
    int sumarNumeros;

    sumarNumeros=a+b;

    return sumarNumeros;
}

int restarNumeros (int a, int b)
{
    int restarNumeros;

    restarNumeros=a-b;

    return restarNumeros;
}

int multiplicarNumeros (int a, int b)
{
    int multiplicarNumeros;

    multiplicarNumeros=a*b;

    return multiplicarNumeros;
}

float dividirNumeros (int a, int b)
{
    float dividirNumeros;

    dividirNumeros=(float)a/(float)b;

    return dividirNumeros;
}

int factorialA(int a)
{
    int i;
    int factorialA=1;
    if(a<0)
    {
        printf("No calculo factorial de numeros negativos\n");
    }
    else
    {
        for(i = 1;i<=a;i++)
        {
           factorialA *= i;
        }
    }


    return factorialA;
}

int factorialB(int b)
{
    int i;
    int factorialB=1;

    if(b<0)
    {
        factorialB=printf("No calculo factorial de numeros negativos\n");
    }
    else
    {
        for(i = 1;i<=b;i++)
        {
           factorialB *= i;
        }
    }
    return factorialB;
}
