#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param Puntero a linkedlist
 * \return 1 si pudeo cargar, 0 si fallo
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 0;
    FILE* pFile;
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int cant;
    Employee* aux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if( pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return error;
        }
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
            if( cant == 4)
            {
                aux = employee_newParametros(id, nombre, horasTrabajadas,sueldo);
                if( aux != NULL)
                {
                    ll_add(pArrayListEmployee,aux);
                }
            }
            else
            {
                break;
            }
        }

        error = 1;
    }

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param Puntero a linkedlist
 * \return 1 si pudeo cargar, 0 si fallo
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 0;
    FILE* pFile;
    int cant;
    Employee* aux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if( pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return error;
        }

        while(!feof(pFile))
        {
            aux = employee_new();
            if( aux !=NULL)
            {
                cant =  fread( aux, sizeof(Employee),    1,  pFile );
                if( cant==1)
                {
                    ll_add(pArrayListEmployee,aux);
                }
            }
            else
            {
                break;
            }
        }

        error = 1;
    }

    return error;
}

/** \brief Alta de empleados
 *
 * \param Puntero a linkedlist
 * \param ID de nuevoId()
 * \return 1 si pudo dar la alta, 0 si fallo
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee,int id)
{
    system("cls");
    int error=0;
    char auxId[100];
    char auxNombre[100];
    char auxHorasTrabajadas[100];
    char auxSueldo[100];
    if(pArrayListEmployee!=NULL)
    {
        printf("***Alta de empleado***\n");
        printf("ID: %d\n",id);
        enteroACadena(id,auxId);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);
        while(esCadena(auxNombre) != 0)
        {
            printf("Error, reingrese Nombre: ");
            fflush(stdin);
            gets(auxNombre);
        }
        printf("Ingrese horas trabajadas: ");
        fflush(stdin);
        gets(auxHorasTrabajadas);
        while(esNumero(auxHorasTrabajadas) != 0)
        {
            printf("Error, reingrese horas trabajadas: ");
            fflush(stdin);
            gets(auxHorasTrabajadas);
        }
        printf("Ingrese sueldo: ");
        fflush(stdin);
        gets(auxSueldo);
        while(esNumero(auxSueldo) != 0)
        {
            printf("Error, reingrese sueldo: ");
            fflush(stdin);
            gets(auxSueldo);
        }
        ll_add(pArrayListEmployee,employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo));
        error=1;
    }
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param Puntero a linkedlist
 * \return 1 su pudo editar empleado, 0 si fallo y -1 si se cancelo
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int error=0;
    char auxId[100];
    char auxNombre[100];
    int auxHorasTrabajadas;
    int auxSueldo;
    char eleccion='n';
    char rta='n';
    int flag=0;
    Employee* auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {

        printf("Ingrese ID del Empleado a modificar: ");//validar
        fflush(stdin);
        gets(auxId);
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado=(Employee*) ll_get(pArrayListEmployee,i);

            if(auxEmpleado->id==atoi(auxId))
            {
                printf("\n   Id          Nombre   Horas Trabajadas   Sueldo\n\n");
                mostrarEmpleado(auxEmpleado);
                printf("Confirma Modificacion? elija s para si, n para no: ");
                fflush(stdin);
                eleccion=getchar();
                break;
            }
        }

        if(eleccion=='s')
        {
            do
            {
                system("cls");
                printf("\n   Id          Nombre   Horas Trabajadas   Sueldo\n\n");
                mostrarEmpleado(auxEmpleado);
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxNombre);

                    strcpy(auxEmpleado->nombre,auxNombre);
                    flag=1;
                    break;
                case 2:
                    printf("Ingrese nuevas horas trabajadas: ");
                    scanf("%d",&auxHorasTrabajadas);
                    while(auxHorasTrabajadas<0)
                    {
                        printf("reingrese cantidad de horas mayor a 0:");
                        scanf("%d",&auxHorasTrabajadas);
                    }
                    auxEmpleado->horasTrabajadas=auxHorasTrabajadas;
                    flag=1;
                    break;
                case 3:
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%d",&auxSueldo);
                    auxEmpleado->sueldo=auxSueldo;
                    flag=1;
                    break;
                case 4:
                     printf("Confirma salir?: (S/N) ");
                    fflush(stdin);
                     rta= getchar();
                    if(flag == 0){
                        error = -1;
                    }else{
                        error = 1;
                    }
                    break;
                default:
                    break;
                }
                error=1;
            }while(rta=='n');
        }
        else
        {
            printf("Error en la modificacion");
            error=-1;
        }
    }

    return error;

}

/** \brief Baja de empleado
 *
 * \param Puntero a linkedlist
 * \return 1 su pudo borrar empleado, 0 si fallo
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=0;
    char auxId[100];
    Employee* empleado;
    char eleccion;
    int indice;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("***Baja Empleado***");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(auxId);
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                empleado=(Employee*)ll_get(pArrayListEmployee,i);
                if(empleado->id==atoi(auxId))
                {
                    printf("\n   Id          Nombre   Horas Trabajadas   Sueldo\n\n");
                    mostrarEmpleado(empleado);
                    printf("Confirma Modificacion? elija s para si, n para no: ");
                    fflush(stdin);
                    eleccion=getchar();
                    indice=i;
                    break;
                }
            }
        if(eleccion=='s')
        {
            ll_remove(pArrayListEmployee,indice);
            printf("Baja realizada con exito\n");
            error=1;
        }
        else
        {
            printf("error en la baja\n");
        }
    }
    printf("\n\n");
    return error;
}

/** \brief Listar empleados/
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error=0;
    Employee* auxEmpleado;
    int flag=0;
    if(pArrayListEmployee!=NULL)
    {
        printf("  ID          Nombre   Horas de Trabajo    Sueldo\n\n");

        for( int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
            mostrarEmpleado(auxEmpleado);
            flag = 1;
        }
        if(flag == 0)
        {
            printf("No hay empleados cargados para mostrar\n");
            system("pause");
        }

        error = 1;
        system("pause");
    }
    return error;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param Puntero a linkedlist
 * \return 1 si se pudo guardar, 0 si fallo
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error=0;
    FILE* pFile;
    int cantDatos;
    Employee* auxEmpleado;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile==NULL)
        {
            return error;
        }
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmpleado=ll_get(pArrayListEmployee,i);
            cantDatos=fprintf(pFile,"%d,%s,%d,%d\n",
                              auxEmpleado->id,
                              auxEmpleado->nombre,
                              auxEmpleado->horasTrabajadas,
                              auxEmpleado->sueldo);
            if(cantDatos<1)
            {
                return error;
            }
        }
        fclose(pFile);
        error=1;
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param Puntero a linkedlist
 * \return 1 si se pudo guardar, 0 si fallo
 *
 */

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error=0;
    FILE* pFile;
    int cantDatos;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile==NULL)
        {
            return error;
        }
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            cantDatos=fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,pFile);
            if(cantDatos<1)
            {
                return error;
            }
        }
     fclose(pFile);
     error=1;
    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param Puntero a linkedlist
 * \return 1 si se hizo el ordenamiento, 0 si fallo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error=0;
    int opcion;
    int criterio;
    //int rta='n';
    system("cls");
    printf("***Menu ordenamiento***\n\n");
    printf("1- Ordenar por ID.\n");
    printf("2- Ordenar por Horas de Trabajo.\n");
    printf("3- Ordenar por Nombre.\n");
    printf("4- Ordenar por Sueldo.\n");
    printf("5. Salir.\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);



    switch(opcion)
    {
    case 1:// Id
        printf("Ingrese criterio de ordenamiento\n");
        printf("1- ascendente y 0-descendente: ");
        scanf("%d",&criterio);
        ll_sort(pArrayListEmployee,employeeSortById,criterio);
        printf("Ordenado con exito!\n");
        system("pause");
        break;
    case 2://horas
        printf("Ingrese criterio de ordenamiento\n");
        printf("1- ascendente y 0-descendente: ");
        scanf("%d",&opcion);
        ll_sort(pArrayListEmployee,employeeSortByworkedHours,criterio);
        printf("Ordenado con exito!\n");
        system("pause");
        break;
    case 3://nombre
        printf("Ingrese criterio de ordenamiento\n");
        printf("1- ascendente y 0-descendente: ");
        scanf("%d",&opcion);
        ll_sort(pArrayListEmployee,employeeSortByName,criterio);
        printf("Ordenado con exito!\n");
        system("pause");
        break;
    case 4://sueldo
        printf("Ingrese criterio de ordenamiento\n");
        printf("1- ascendente y 0-descendente: ");
        scanf("%d",&opcion);
        ll_sort(pArrayListEmployee,employeeSortBySalary,criterio);
        printf("Ordenado con exito!\n");
        system("pause");
        break;
    case 5:
        break;
        error=1;
    }

    return error;
}

/** \brief Genera un nuevo Id a partir del ultimo leido
 *
 * \param Puntero a linkedlist
 * \param recibe ultimo ID
 * \return ID siguiente al ultimo que recibe
 *
 */

int nuevoId(LinkedList* pArrayListEmployee,int* id)
{
    int error = -1;
    Employee* empleado = NULL;
    int idAux = *id;
    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee,i);
            if(empleado->id == idAux && ll_len(pArrayListEmployee) != i)
            {
                idAux++;
            }
        }
        *id = idAux;
    }
    return error;
}

/** \brief pasa entero a cadena
 *
 * \param entero
 * \param puntero a cadena
 * \return void
 *
 */

void enteroACadena(int numero, char *bufer)
{
    sprintf(bufer, "%llu", numero);
}

/** \brief IMprime el menu de modificacion
 *
 * \return opcion elegida
 *
 */

int menuModificacion()
{
    int opcion;
    printf("\n\n***Modificacion de empleado***\n");
    printf("1- Modificar Nombre.\n");
    printf("2- Modificar Horas de Trabajo.\n");
    printf("3- Modificar Sueldo.\n");
    printf("4. <-- Volver.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/** \brief valida si el parametro recibido es cadena
 *
 * \param una cadena
 * \return 0 si es cadena, -1 si no es cadena
 *
 */

int esCadena(char* cadena)
{
    int error = -1;
    int len = strlen(cadena);

    for(int i = 0 ; i < len; i++)
    {
        if(isalpha(cadena[i]))
        {
            error = 0;
        }
        else
        {
            error = -1;
            break;
        }
    }

    return error;
}

/** \brief valida si el parametro recibido es numerico
 *
 * \param una cadena
 * \return 0 si es cadena, -1 si no es numero
 *
 */

int esNumero(char* cadena)
{
    int error = -1;
    int len = strlen(cadena);

    for(int i = 0 ; i < len; i++)
    {
        if(isdigit(cadena[i]))
        {
            error = 0;
        }
        else
        {
            error = -1;
            break;
        }
    }

    return error;
}

