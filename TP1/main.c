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
    float factorialDeA=1;
    float factorialDeB=1;
    int eleccion1;


        printf("***Bienvenido a la calculadora***\n");
        printf("A continuacion ingrese los dos operandos\n");
        printf("Operando 1: ");
        scanf("%f", &a);
        printf("Operando 2: ");
        scanf("%f", &b);
        system("cls");

        printf("desea ver todos los resultados o alguno en especifico?\n");
        printf("1.Resultado de Suma\n2.Resultado de Resta\n3.Resultado de Multiplicacion\n4.Resultado de Division\n5.Resultado de los factoriales\n6.Todos los resultados");
        scanf("%d",&eleccion1);

        switch(eleccion1)
        {
        case 1:
            resultadoSuma=a+b;
            printf("El resultado de la suma es: %.2f",resultadoSuma);
            break;
        case 2:
            resultadoResta=a-b;
            printf("El resultado de la resta es: %.2f",resultadoResta);
            break;
        case 3:
            resultadoMulti=a*b;
            printf("El resultado de la multiplicacion es: %.2f",resultadoMulti);
            break;
        case 4:
            resultadoDiv=a/b;
            printf("El resultado de la division es: %.2f",resultadoDiv);
            break;
        case 5:
            while(a>1)
            {
                factorialDeA*=a;
                printf(" %f x",a);
                a--;
            }
        printf(" 1 = %f\n",factorialDeB);
        while(b>1)
            {
                factorialDeA*=b;
                printf(" %f x",b);
                a--;
            }
        printf(" 1 = %f\n",factorialDeA);

        break;
        }



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
