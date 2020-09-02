#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    float b;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMulti;
    float resultadoDiv;
    float factorialDeA;
    float factorialDeB;

    printf("***Bienvenido a la calculadora***\n");
    printf("A continuacion ingrese los dos operandos\n");
    printf("Operando 1: ");
    scanf("%f", &a);
    printf("Operando 2: ");
    scanf("%f", &b);

    resultadoSuma=a+b;
    resultadoResta=a-b;
    resultadoMulti=a*b;
    resultadoDiv=a/b;
    factorialDeA;
    factorialDeB;

    printf("El resultado de %.2f + %.2f es: %.2f\n",a,b,resultadoSuma);
    printf("El resultado de %.2f - %.2f es: %.2f\n",a,b,resultadoResta);
    printf("El resultado de %.2f * %.2f es: %.2f\n",a,b,resultadoMulti);
    printf("El resultado de %.2f / %.2f es: %.2f\n",a,b,resultadoDiv);
    printf("El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f",a,factorialDeA,b,factorialDeB);



    return 0;
}
