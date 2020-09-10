#include <stdio.h>
#include <stdlib.h>
#include "input.h"
// agregar tambien la salida de datos por funcion

int main()
{
    int a;
    int b;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMulti;
    int eleccion;
    float resultadoDiv;
    unsigned long long int  factorialDeA=1;
    unsigned long long int factorialDeB=1;

        system("cls");
        printf("***Bienvenido a la calculadora***\n");
        printf("A continuacion ingrese los dos operandos\n");
        printf("Operando 1: ");
        scanf("%d", &a);
        printf("Operando 2: ");
        scanf("%d", &b);
        system("cls");

    do
    {
        system("cls");
        printf("El operando 1 es: %d y el operando 2 es: %d\n",a,b);
        printf("A continuacion elija una opcion\n");
        printf("1.Reingresar Operando 1\n");
        printf("2.Reingresar Operando 2\n");
        printf("3.Resultado de Suma\n");
        printf("4.Resultado de Resta\n");
        printf("5.Resultado de Multiplicacion\n");
        printf("6.Resultado de Division\n");
        printf("7.Resultado de los factoriales\n");
        printf("8.Todos los resultados\n");
        printf("9.Salir\n\n");
        printf("Su eleccion: ");
        scanf("%d",&eleccion);


        switch(eleccion)
        {
        case 1:
            a = reingresarA(a);
            printf("Reingreso de a: %d",a);
            break;
        case 2:
            b = reingresarB(b);
            printf("Reingreso de b: %d",b);
            break;
        case 3:
            resultadoSuma=sumarNumeros(a,b);
            printf("El resultado de la suma es: %d\n\n",resultadoSuma);
            system("pause");
            break;
        case 4:
            resultadoResta=restarNumeros(a,b);
            printf("El resultado de la resta es: %d\n\n",resultadoResta);
            system("pause");
            break;
        case 5:
            resultadoMulti=multiplicarNumeros(a,b);
            printf("El resultado de la multiplicacion es: %d\n\n",resultadoMulti);
            system("pause");
            break;
        case 6:
            resultadoDiv=dividirNumeros(a,b);
            printf("El resultado de la division es: %.2f\n\n",resultadoDiv);
            system("pause");
            break;
        case 7:
            factorialDeA=factorialA(a);
            printf("El factorial de %d es: %d\n\n",a,factorialDeA);
            factorialDeB=factorialB(b);
            printf("El factorial de %d es: %d\n\n",b,factorialDeB);
            system("pause");
            break;
        case 8:
            resultadoSuma=sumarNumeros(a,b);
            resultadoResta=restarNumeros(a,b);
            resultadoMulti=multiplicarNumeros(a,b);
            resultadoDiv=dividirNumeros(a,b);
            factorialDeA=factorialA(a);
            factorialDeB=factorialB(b);

            printf("El resultado de la suma es: %.d\n\n",resultadoSuma);
            printf("El resultado de la resta es: %.d\n\n",resultadoResta);
            printf("El resultado de la multiplicacion es: %.d\n\n",resultadoMulti);
            printf("El resultado de la division es: %.2f\n\n",resultadoDiv);
            printf("El factorial de %d es: %d\n\n",a,factorialDeA);
            printf("El factorial de %d es: %d\n\n",b,factorialDeB);
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("Error, ingrese un numero valido\n");
            system("pause");
            break;
            system("cls");
        }
    }
    while(eleccion!=9);

    return 0;
}
