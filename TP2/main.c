#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId=0001;
    int flag=0;
    eEmpleado empleados[TAM];

    inicializarEmpleados(empleados,TAM);
    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 1:
            if(altaEmpleado(empleados, TAM, proximoId) == 0)
            {
                proximoId++;
                printf("\n\n\tALTA EXITOSA!\n\n\n");
                flag=1;
            }
            else
            {
                printf("\tProblema para realizar el alta\n");
            }
            system("pause");
            break;
        case 2:
            if(!flag)
            {
                printf("\nTodavia no se cargaron empleados\n");
                system("pause");
            }
            else
            {
                modificarEmpleado(empleados,TAM,proximoId);
            }
            break;
        case 3:
            if(!flag)
            {
                printf("\nTodavia no se cargaron empleados\n");
                system("pause");
            }
            else
            {
                bajaEmpleado(empleados, TAM);
            }
            break;
        case 4:
            if(!flag)
            {
                printf("\nTodavia no se cargaron empleados\n");
                system("pause");
            }
            else
            {
                system("cls");
                ordenarEmpleados(empleados,TAM);
            }
            break;
        case 5:
            fflush(stdin);
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
            break;
        }
    }
    while( seguir == 's');
    return 0;
}
