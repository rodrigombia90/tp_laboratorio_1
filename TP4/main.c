#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"
#include "controller.h"
#include "employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menuOpcion();

int main()
{
    char salida;
    int flag=0;
    int id=1;

     LinkedList* listaEmpleados= ll_newLinkedList();
     if( listaEmpleados == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    do
    {
        system("cls");
        switch(menuOpcion())
        {
        case 1:
            if(flag == 0)
            {
                if(controller_loadFromText("data.csv",listaEmpleados)==1)
                {
                    nuevoId(listaEmpleados,&id);

                    printf("***Empleados cargados con exito***\n");
                    system("pause");
                    flag = 1;
                }
            }
            else
            {
                printf("**Ya se cargaron los empleados***\n");
                system("pause");
            }
            break;
        case 2:
            if(flag == 0)
            {
                if(controller_loadFromBinary("databin.csv",listaEmpleados)==1)
                {
                    nuevoId(listaEmpleados,&id);

                    printf("***Empleados cargados con exito***\n");
                    system("pause");
                    flag = 1;
                }
            }
            else
            {
                printf("***Ya se cargaron los empleados***\n");
                system("pause");
            }
            break;
        case 3:
            nuevoId(listaEmpleados,&id);
            if(controller_addEmployee(listaEmpleados,id)!=0)
            {
                printf("Alta exitosa\n");
                system("pause");
            }
            else{
                printf("error en la carga\n");
            }
            break;
        case 4:
            if(flag==1)
            {
                switch(controller_editEmployee(listaEmpleados))
                {
                case 1:
                    printf("\n***Modificacion exitosa***\n");
                    break;
                case -1:
                    printf("\n***Se cancelo la modificacion***\n");
                    break;
                default:
                    printf("\n***Error. No se completo la modificacion o ID Incorrecto***\n");
                    break;
                }
            }
            else
            {
                printf("\n\n***primero debe cargar empleados***\n\n");
                system("pause");
            }
            break;
        case 5:
            if(flag==1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\n***primero debe cargar empleados***\n\n");
                system("pause");
            }
            break;
        case 6:
            if(flag==1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\n***primero debe cargar empleados***\n\n");
                system("pause");
            }

            break;
        case 7:
            if(flag==1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\n***primero debe cargar empleados***\n\n");
                system("pause");
            }
            break;
        case 8:
            if(flag==1 || id>1)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("Empleados guardados con exito\n");
                    system("pause");
                }
                else{
                    printf("Problema para guardar como texto\n");
                    system("pause");
                }
            }
            else
            {
                printf("No hay empleados cargados\n");
                system("pause");
            }
            break;
        case 9:
             if(flag==1 || id>1)
            {
                if(controller_saveAsBinary("databin.csv",listaEmpleados))
                {
                    printf("Empleados guardados con exito\n");
                    system("pause");
                }
                else{
                    printf("Problema para guardar como texto\n");
                    system("pause");
                }
            }
            else
            {
                printf("No hay empleados cargados\n");
                system("pause");
            }
            break;
        case 10:
            printf("Confirma salir?\n s para si - n para no:");
            fflush(stdin);
            scanf("%c", &salida);
            salida = tolower(salida);
            printf("\n\n");
            break;
        default:
            printf("error, opcion incorrecta");
            break;
        }
    }
    while(salida != 's');

    return 0;
}

int menuOpcion()
{
    int opcion;
    printf("*** Menu Principal ***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10.Salir\n");

    do
    {
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);
    }
    while(isdigit(opcion) != 0);

    return opcion;
}
