#include <stdio.h>
#include <stdlib.h>
#include "input.h"
int main()
{
    float a;
    float b;
    int eleccion;
    int banderaCalculos=0;

    system("cls");
    printf("***Bienvenido a la calculadora***\n");
    printf("A continuacion ingrese los dos operandos\n");
    printf("Operando 1: ");
    scanf("%f", &a);
    printf("Operando 2: ");
    scanf("%f", &b);
    system("cls");

    do
    {
        system("cls");
        printf("El operando 1 es: %.2f \nEl operando 2 es: %.2f\n***********************\n",a,b);
        printf("A continuacion elija una opcion\n1.Reingresar Operando 1\n2.Reingresar Operando 2\n3.Hacer calculos\n4.Mostrar resultados\n5.Salir\n\n");
        printf("Su eleccion: ");
        scanf("%d",&eleccion);

        switch(eleccion)
        {
        case 1:
            a = reingresarA(a);
            printf("Reingreso de a: %f",a);
            banderaCalculos=0;
            break;
        case 2:
            b = reingresarB(b);
            printf("Reingreso de b: %f",b);
            banderaCalculos=0;
            break;
        case 3:
            hacerCalculos(a,b);
            banderaCalculos=1;
            system("pause");
            break;
        case 4:
            mostrarCalculos(a,b,banderaCalculos);
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        default:
            printf("Error, ingrese un numero valido\n");
            system("pause");
            break;
            system("cls");
        }
    }
    while(eleccion!=5);
    return 0;
}
