#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId=0001;
    int rta;
    int criterioOrden;
    eEmpleado list[TAM];
    inicializarEmpleados(list,TAM);
    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 1:
            if(altaEmpleado(list, TAM, proximoId) == 0)//tendria que devolver 0
            {
                proximoId++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n");
            }
            break;
        case 2:
            rta=bajaEmpleado(list, TAM);

            if( rta == 0)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 2)
            {
                printf("Baja cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n");
            }

            break;
        case 3:

            break;
        case 4:
            system("cls");
            ordenarEmpleados(list,TAM,criterioOrden);
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
        system("pause");
    }
    while( seguir == 's');
    return 0;
}
