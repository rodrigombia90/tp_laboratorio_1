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
        printf("Desea ver todos los resultados o alguno en especifico?\n");
        printf("1.Resultado de Suma\n");
        printf("2.Resultado de Resta\n");
        printf("3.Resultado de Multiplicacion\n");
        printf("4.Resultado de Division\n");
        printf("5.Resultado de los factoriales\n");
        printf("6.Todos los resultados\n\n");
        printf("7.Salir");
        printf("Su eleccion: ");
        scanf("%d",&eleccion);


        switch(eleccion)
        {
        case 1:
            resultadoSuma=sumarNumeros(a,b);
            printf("El resultado de la suma es: %d\n\n",resultadoSuma);
            system("pause");
            break;
        case 2:
            resultadoResta=restarNumeros(a,b);
            printf("El resultado de la resta es: %d\n\n",resultadoResta);
            system("pause");
            break;
        case 3:
            resultadoMulti=multiplicarNumeros(a,b);
            printf("El resultado de la multiplicacion es: %d\n\n",resultadoMulti);
            system("pause");
            break;
        case 4:
            resultadoDiv=dividirNumeros(a,b);
            printf("El resultado de la division es: %.2f\n\n",resultadoDiv);
            system("pause");
            break;
        case 5:
            factorialDeA=factorialA(a);
            printf("El factorial de %d es: %d\n\n",a,factorialDeA);
            factorialDeB=factorialB(b);
            printf("El factorial de %d es: %d\n\n",b,factorialDeB);
            break;
        case 6:
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
        case 7:
            break;
        default:
            printf("Error, ingrese un numero valido\n");
            system("pause");
            break;
            system("cls");
        }
    }
    while(eleccion!=7);

    return 0;
}
