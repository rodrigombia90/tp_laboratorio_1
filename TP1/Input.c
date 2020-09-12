#include "input.h"
float mostrarCalculos (float a, float b, float banderaCalculos)
{
     if(banderaCalculos==1)
            {
                printf("El resultado de la suma es: %.1f\n\n",sumarNumeros(a,b));
                printf("El resultado de la resta es: %.1f\n\n",restarNumeros(a,b));
                printf("El resultado de la multiplicacion es: %.1f\n\n",multiplicarNumeros(a,b));
                if(b==0)
                {
                    printf("No se puede dividir entre cero\n\n");
                }
                else
                {
                    printf("El resultado de la division es: %.2f\n\n",dividirNumeros(a,b));
                }
                if(a<0)
                {
                    printf("No calculo factorial de numeros negativos\n\n");
                }
                else
                {
                    printf("El factorial de %.1f es: %ld\n\n",a,factorial(a));
                }
                if(b<0)
                {
                    printf("No calculo factorial de numeros negativos\n\n");
                }
                else
                {
                    printf("El factorial de %.1f es: %ld\n\n",b,factorial(b));
                }
            }
            else
            {
                printf("Primero tengo que calcular");
            }

            return 0;
}
float hacerCalculos (float a, float b)
{
    printf("Ya hice los calculos...\n");

    sumarNumeros(a,b);
    restarNumeros(a,b);
    multiplicarNumeros(a,b);
    dividirNumeros(a,b);
    factorial(a);
    factorial(b);

        return 0;
}
float reingresarA(float a)
{
    printf("Reingrese operando 1: ");
    scanf("%f",&a);
    return a;
}

float reingresarB(float b)
{
    printf("Reingrese operando 2: ");
    scanf("%f",&b);
    return b;
}

float sumarNumeros (float a, float b)
{
    float sumarNumeros;

    sumarNumeros=a+b;

    return sumarNumeros;
}

float restarNumeros (float a, float b)
{
    float restarNumeros;

    restarNumeros=a-b;

    return restarNumeros;
}

float multiplicarNumeros (float a, float b)
{
    float multiplicarNumeros;

    multiplicarNumeros=a*b;

    return multiplicarNumeros;
}

float dividirNumeros (float a, float b)
{
    float dividirNumeros;

    dividirNumeros=(float)a/b;

    return dividirNumeros;
}

long long int factorial(int num)
{
    int i;
    int factorial=1;
         for(i = 1;i<=num;i++)
        {
           factorial *= i;
        }
    return factorial;
}
