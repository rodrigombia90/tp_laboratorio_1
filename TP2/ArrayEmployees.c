#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "dataEmpleados.h"

/** \brief inicializa el vector isEmpty, para diferenciar las cargas y evitar pisar datos
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param tam int tamaño del vector
 * \return int devuelce 0 si pudo inicializar, 1 si algo fallo
 *
 */
int inicializarEmpleados(eEmpleado empleados[],int tam)
{
    int error=-1;
    if(empleados!=NULL && tam>0 )
    {
        for(int i=0; i<tam; i++)
        {
            empleados[i].isEmpty=1;
        }
        error=0;
    }

    return error;
}

/** \brief muestra el menu principal
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuOpciones()
{
    int opcion;
    printf("\t------------------------------------------------\n");
    printf("\t---Bienvenido a la base de datos de empleados---\n");
    printf("\t------------------------------------------------\n");
    printf("\t1- Alta\n");
    printf("\t2- Modificar\n");
    printf("\t3- Baja\n");
    printf("\t4- Informar\n");
    printf("\t5- Salir\n");
    printf("\t------------------------------------------------\n");
    utn_getNumero(&opcion,"\tIngrese la opcion: ","\nError, ingrese opcion valida!\n",1,5,5);

    return opcion;
}


/** \brief muestra el menu para modificar datos
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuModificacion()
{
    int opcion;
    printf("\n\t-----------Ingrese opcion para modificar el dato----------\n");
    printf("\t1-Nombre\n");
    printf("\t2-Apellido\n");
    printf("\t3-Salario\n");
    printf("\t4-Sector\n");
    utn_getNumero(&opcion,"\tIngrese la opcion: ","\n\tError, ingrese opcion valida!\n",1,4,5);

    return opcion;
}


/** \brief muestra un elempleado de la estructura
 *
 * \param unaPersona eEmpleado
 * \return void
 *
 */
void mostrarPersona(eEmpleado unaPersona)
{
    printf("\t- %2d   %10s  %10s  %15.2f   %5d  -\n",unaPersona.id,unaPersona.name,unaPersona.lastName,unaPersona.salary,unaPersona.sector);
}


/** \brief muestra todos los empleados cargados
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int cantidad de empleados
 * \return int devuelve 0 si pudo mostrar, 1 si todavia no se cargaron empleados (isEmpty = 1) o -1 si hubo un problema
 *
 */
int mostrarPersonas(eEmpleado empleados[], int t)
{
    int error=-1;
    int flag=0;
    if(empleados!=NULL && t>0)
    {
        printf("\t---------------------------------------------------------\n");
        printf("\t- Legajo    Nombre      Apellido       Salario    Sector-\n");
        printf("\t---------------------------------------------------------\n");
        for(int i=0; i<t; i++)
        {
            if(empleados[i].isEmpty==0)
            {
                mostrarPersona(empleados[i]);
                flag=1;
                error=0;
            }
        }
        printf("\t---------------------------------------------------------\n");
        if(!flag)
        {
            printf("No hay Empleados cargados");
            error=1;
        }

        printf("\n\n");

    }
    return error;
}


/** \brief busca lugar para no pisar datos
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estructira
 * \return int devuelve el primer indice que encuentra vacio
 *
 */
int buscarLibre(eEmpleado empleados[], int t)
{
    int indice=-1;
    for(int i=0; i<t; i++)
    {
        if(empleados[i].isEmpty ==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief cargar empleados a la lista
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id del proximo empleado a cargar
 * \return int devuelve 0 si pudo cargar el empleado, -1 si hubo un problema
 *
 */
int altaEmpleado(eEmpleado empleados[], int t, int id)
{
    int error=1;
    int indice;
    eEmpleado nuevoEmpleado;
    system("cls");
    printf("\t---------------------------------------------------------\n");
    printf("\t------------------- Alta de Empleado --------------------\n");
    printf("\t---------------------------------------------------------\n");
    if(empleados!=NULL && t>0)
    {
        indice=buscarLibre(empleados,t);
        if(indice==-1)
        {
            printf("Sistema completo\n");
        }
        else
        {
            nuevoEmpleado.id=id;
            nuevoEmpleado.isEmpty=0;
            utn_getNombre(&nuevoEmpleado.name,sizeof(nuevoEmpleado.name),"\n\tIngrese nombre: ","\n\tError, Ingrese nombre valido\n",5);
            fflush(stdin);
            printf("\n");
            utn_getNombre(&nuevoEmpleado.lastName,sizeof(nuevoEmpleado.lastName),"\tIngrese apellido: ","\n\tError, ingrese apellido valido\n",5);
            fflush(stdin);
            printf("\n");
            utn_getNumeroFloat(&nuevoEmpleado.salary,"\tIngrese salario: ","\n\tError\n",0,10000,5);
            fflush(stdin);
            printf("\n");
            utn_getNumero(&nuevoEmpleado.sector,"\tIngrese sector: ","\n\tError, ingrese sector valido\n",0,1000,5);
            fflush(stdin);
            empleados[indice]=nuevoEmpleado;
            error=0;
        }
    }
    return error;
}


/** \brief recibe un ID y busca ese id en la lista
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id que usa para buscar en la lista
 * \return int devuelve en que indice esta ese empleado
 *
 */
int buscarEmpleado(eEmpleado empleados[], int t, int id)
{
    int indice=-1;
    for(int i=0; i<t; i++)
    {
        if(empleados[i].id == id && empleados[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief impide la lectura del empleado modificando el estado el campo isEmpty
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \return int devuelve 0 si se pudo hacer la baja, 1 si se cancelo por el usuario, y -1 si hubo un problema
 *
 */
int bajaEmpleado(eEmpleado empleados[], int t)
{
    int error=-1;
    int id;
    int indice;
    char confirma;
    if(empleados!=NULL && t>0)
    {
        system("cls");
        printf("\t---------------------------------------------------------\n");
        printf("\t------------------- Baja de Empleado --------------------\n");
        if(!mostrarPersonas(empleados,t))
        {
            printf("\tingrese id: ");
            scanf("%d",&id);

            indice=buscarEmpleado(empleados,t,id);
            if(indice==-1)
            {
                printf("No existe una persona con ese legajo\n\n");

            }
            else
            {
                printf("\n");
                mostrarPersona(empleados[indice]);
                printf("\n");
                fflush(stdin);
                utn_getNumero(&confirma,"\tConfirma la baja?\n\n\t1- SI\n\t2- NO\n\tSu eleccion:","\n\tError, ingrese 1 o 2",1,2,5);
                fflush(stdin);
                if(confirma==1)
                {
                    empleados[indice].isEmpty=1;
                    printf("\n\tBaja exitosa\n");
                    error=0;
                }
                else
                {
                    printf("\n\tBaja cancelada por usuario\n");
                    error=1;
                }
            }
        }
    }
    printf("\n\n");
    system("pause");
    return error;
}


/** \brief permite modificar los datos cargados en un empleado
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id del empleado a modificar
 * \return int devuelve 0 si se modifico algo, y 1 si hubo un error
 *
 */
int modificarEmpleado(eEmpleado empleados[],int t, int id)
{
    int error=1;
    char seguir = 's';
    int auxId;
    if(empleados!=NULL && t>0)
    {
        do
        {
            system("cls");
            printf("\t---------------------------------------------------------\n");
            printf("\t------------------- Menu Modificacion -------------------\n");
            mostrarPersonas(empleados,t);
            utn_getNumero(&auxId,"\n\tIngrese el ID del empleado a modificar :","\n\tError, ingrese ID valido",1,id,5);
            switch(menuModificacion())
            {
            case 1:
                modificarNombre(empleados,t,auxId);
                seguir='n';
                error=0;
                break;
            case 2:
                modificarApellido(empleados,t,auxId);
                seguir='n';
                error=0;
                break;
            case 3:
                modificarSalario(empleados,t,auxId);
                seguir='n';
                error=0;
                break;
            case 4:
                modificarSector(empleados,t,auxId);
                seguir='n';
                error=0;
                break;
            default:
                printf("Opcion invalida!!!\n");
                break;
            }
        }
        while( seguir == 's');
    }
    return error;
}


/** \brief ordena la lista de empleados por apellido, y si coinciden los apéllidos, por sector, segun criterio que ingresa el usuario (ascendente o descendente)
 *
 * \param empleados[] eEmpleado estrucutra empleado
 * \param t int
 * \return int devuelve 0 si se pudo ordenar, -1 si hubo un problema
 *
 */

int ordenarEmpleados(eEmpleado empleados[], int t)
{
    int error=-1;
    int lista;
    int criterio;

    eEmpleado auxEmpleado;
    if(empleados !=NULL && t>0)
    {
        lista= mostrarPersonas(empleados,t);
        informeSalarios(empleados,t);
        if(lista==0)
        {
            if(menuOrdenar()==1)
            {
                utn_getNumero(&criterio,"\n\tSe ordenara primero por Apellido y luego por Sector\n\t1 para ordenar de forma ascendente\n\t2 para ordenar de forma descendente\n\tSu eleecion: ","\n\tError, ingrse numero valido",1,2,5);
                switch(criterio)
                {
                case 1:
                    for(int i=0; i<t-1; i++)
                    {
                        for(int j=i+1; j<t; j++)
                        {
                            if(strcmp(empleados[j].lastName, empleados[i].lastName) < 0  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                            {
                                auxEmpleado = empleados[i];
                                empleados[i] = empleados[j];
                                empleados[j] = auxEmpleado;
                            }
                            else if(strcmp(empleados[j].lastName, empleados[i].lastName) == 0 && empleados[j].sector < empleados[i].sector  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                            {
                                auxEmpleado = empleados[i];
                                empleados[i] = empleados[j];
                                empleados[j] = auxEmpleado;
                            }
                        }
                    }
                    printf("\n\tOrdenamiento Exitoso.\n");
                    system("pause") ;
                    system("cls") ;
                    error=0;
                    break;
                case 2:
                    for(int i=0; i<t-1; i++)
                    {
                        for(int j=i+1; j<t; j++)
                        {
                            if(strcmp(empleados[j].lastName, empleados[i].lastName) > 0 && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                            {
                                auxEmpleado = empleados[i];
                                empleados[i] = empleados[j];
                                empleados[j] = auxEmpleado;
                            }
                            else if(strcmp(empleados[j].lastName, empleados[i].lastName) == 0 && empleados[j].sector > empleados[i].sector  && empleados[j].isEmpty == 0 && empleados[i].isEmpty == 0)
                            {
                                auxEmpleado = empleados[i];
                                empleados[i] = empleados[j];
                                empleados[j] = auxEmpleado;
                            }
                        }
                    }
                    printf("\n\tOrdenamiento Exitoso.\n");
                    system("pause") ;
                    system("cls") ;
                    error=0;
                    break;
                default:
                    printf("\tNo ingreso 1 o 2");
                }

            }
            error=0;
        }
        else
        {
            printf("\tProblema para mostrar empleados");
            system("pause");
            error=1;
        }
    }
    return error;
}


/** \brief muestra el menu que permite decidir si ordenar o no al listar los empleados
 *
 * \return int devuelve la eleccion del usuario
 *
 */
int menuOrdenar()
{
    int opcion;
    utn_getNumero(&opcion,"\n\n\tDesea ordenar?\n\t1 para ordenar\n\t2 para salir del menu listar\n\tSu eleccion: ","\n\tError, ingrese numero valido",1,2,5);
    return opcion;
}


/** \brief modifica el nombre del empleado
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarNombre(eEmpleado empleados[],int t, int id)
{
    int error=1;
    int indice;
    eEmpleado auxEmpleado;
    if(empleados!=NULL && t>0)
    {
        indice=buscarEmpleado(empleados,t, id);
        if(indice==-1)
        {
            printf("\tNo existe empleado\n");
        }
        else
        {
            utn_getNombre(&auxEmpleado.name,sizeof(auxEmpleado.name),"\tIngrese nombre: ","\n\tError, Ingrese nombre valido\n",5);
            strcpy(empleados[indice].name,auxEmpleado.name);
            error=0;
        }
    }
    return error;
}

/** \brief modifica el apellido del empleado
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarApellido(eEmpleado empleados[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado auxEmpleado;
    if(empleados!=NULL && t>0)
    {
        indice=buscarEmpleado(empleados,t, id);
        if(indice==-1)
        {
            printf("\tNo existe empleado\n");
        }
        else
        {
            utn_getNombre(&auxEmpleado.lastName,sizeof(auxEmpleado.lastName),"\tIngrese apellido: ","\nError, Ingrese apellido valido\n",5);
            strcpy(empleados[indice].lastName,auxEmpleado.lastName);
            error=0;
        }
    }
    return error;
}

/** \brief modifica el salario del empleado
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarSalario(eEmpleado empleados[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado auxEmpleado;
    if(empleados!=NULL && t>0)
    {
        indice=buscarEmpleado(empleados,t, id);
        if(indice==-1)
        {
            printf("\tNo existe empleado\n");
        }
        else
        {
            printf("\tIngrese salario: ");
            scanf("%f",&auxEmpleado.salary);
            empleados[indice].salary=auxEmpleado.salary;
            error=0;
        }
    }
    return error;
}

/** \brief modifica el sector del empleado
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarSector(eEmpleado empleados[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado auxEmpleado;
    if(empleados!=NULL && t>0)
    {
        indice=buscarEmpleado(empleados,t, id);
        if(indice==-1)
        {
            printf("\tNo existe empleado\n");
        }
        else
        {
            utn_getNumero(&auxEmpleado.sector,"\tIngrese sector: ","\n\tError, ingrese sector valido\n",0,1000,5);
            empleados[indice].sector=auxEmpleado.sector;
            error=0;
        }
    }
    return error;
}


/** \brief calcula y muestra el total de los salarios, el promedio, y cuantos estan por encima del promedio
 *
 * \param empleados[] eEmpleado estructura empleado
 * \param t int tamaño de la estrucutra
 * \return int devuelve 0 si pudo calcular, y -1 si hubo un problema
 *
 */
int informeSalarios(eEmpleado empleados[], int t)
{
	int error = -1;
    float acumulador = 0;
    int contador = 0;
    float promedio = 0;
    int contadorSalarioMayor=0;


    if(empleados!=NULL && t>0)
    {
        for(int i=0; i<t; i++)
         {
             if(empleados[i].isEmpty == 0)
             {
            	 acumulador +=empleados[i].salary;
                 contador++;
             }
          }

        promedio = (float) acumulador/ contador;
        for(int i=0; i<t; i++)
        {
        	if(empleados[i].salary>=promedio && empleados[i].isEmpty==0)
        	{
        		contadorSalarioMayor++;
            }
        }
        printf("\t\t**INFORME SALARIOS**\n\tEl monto total de los salarios es: $%.2f\n\tEl salario promedio es: $%.2f\n"
        		"\tLa cantidad de empleados que superan el salario promedio son: %d\n",acumulador,promedio,contadorSalarioMayor);

        error=0;
    }
    return error;
}


