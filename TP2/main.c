#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 7

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId=0001;
    int flag=0;
    eEmpleado list[TAM];

    inicializarEmpleados(list,TAM);
    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 1:
            if(altaEmpleado(list, TAM, proximoId) == 0)
            {
                //proximoId++;
                printf("ALTA EXITOSA!\n");
                flag=1;
            }
            else
            {
                printf("Problema para realizar el alta\n");
            }
            break;
        case 2:
            if(!flag)
            {
                printf("\nTodavia no se cargaron empleados\n");
                system("pause");
            }
            else
            {
                modificarEmpleado(list,TAM,proximoId);
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
                bajaEmpleado(list, TAM);
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
                ordenarEmpleados(list,TAM);
            }
            break;
        case 5:
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
