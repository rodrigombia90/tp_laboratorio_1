#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    system("cls");
    int error=1;
    int i=0;
    char id[50];
    char nombre[50];
    char horasTrabajadas[20];
    char sueldo[50];
    int cantidadDatos;

    if(pFile != NULL)
    {

        cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        while(!feof(pFile))
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

            if(cantidadDatos!=4)
            {
                printf("Error en lectura de archivo\n");
                system("pause");
            }
            else
            {

                Employee* empleado=employee_new();

                empleado[i].id=atoi(id);

                strcpy(empleado[i].nombre,nombre);

                empleado[i].horasTrabajadas=atoi(horasTrabajadas);

                empleado[i].sueldo=atof(sueldo);

                i++;
                error=0;

            }
        }
    fclose(pFile);
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        system("pause");
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
