#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "dataEmpleados.h"

/** \brief inicializa el vector isEmpty, para diferenciar las cargas y evitar pisar datos
 *
 * \param gente[] eEmpleado estructura empleado
 * \param tam int tamaño del vector
 * \return int devuelce 0 si pudo inicializar, 1 si algo fallo
 *
 */
int inicializarEmpleados(eEmpleado gente[],int tam)
{
    int error=-1;
    if(gente!=NULL && tam>0 )
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty=1;
        }
        error=0;
    }

    return error;
}

/** \brief impresion del menu principal
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuOpciones()
{
    int opcion;
    printf("\t***Bienvenido a la base de datos de empleados***\n\n");
    printf("1 Alta\n");
    printf("2 Modificar\n");
    printf("3 Baja\n");
    printf("4 Informar\n");
    printf("5 Salir\n\n");
    utn_getNumero(&opcion,"Ingrese la opcion: ","\nError, ingrese opcion valida!\n",1,5,5);

    return opcion;
}


/** \brief impresion del menu para modificar datos
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuModificacion()
{
    int opcion;
    printf("\n***Ingrese opcion para modificar el dato***\n");
    printf("1 Nombre\n");
    printf("2 Apellido\n");
    printf("3 Salario\n");
    printf("4 Sector\n");
    utn_getNumero(&opcion,"Ingrese la opcion: ","\nError, ingrese opcion valida!\n",1,4,5);

    return opcion;
}


/** \brief imprime un elempleado de la estructura
 *
 * \param unaPersona eEmpleado
 * \return void
 *
 */
void mostrarPersona(eEmpleado unaPersona)
{
    printf(" %2d  %10s  %10s  %15.2f  %5d\n",unaPersona.id,unaPersona.name,unaPersona.lastName,unaPersona.salary,unaPersona.sector);
}


/** \brief imprime todos los empleados cargados
 *
 * \param gente[] eEmpleado estructura empleado
 * \param t int cantidad de empleados
 * \return int devuelve 0 si pudo mostrar, 1 si todavia no se cargaron empleados (isEmpty = 1) o -1 si hubo un problema
 *
 */
int mostrarPersonas(eEmpleado gente[], int t)
{
    int error=-1;
    int flag=0;
    if(gente!=NULL && t>0)
    {
        printf("Legajo    nombre      apellido       salario    sector\n");
        printf("--------------------------------------------------------\n");
        for(int i=0; i<t; i++)
        {
            if(gente[i].isEmpty==0)
            {
                mostrarPersona(gente[i]);
                flag=1;
                error=0;
            }
        }
        if(!flag)
        {
            printf("No hay Empleados cargados");
            error=1;
        }
        printf("\n\n");
        //error estaba aca, pero creo que iba en el else. PRESTAR ATENCION
    }
    return error;
}


/** \brief busca lugar para no pisar datos
 *
 * \param gente[] eEmpleado estructura empleado
 * \param t int tamaño de la estructira
 * \return int devuelve el primer indice que encuentra vacio
 *
 */
int buscarLugar(eEmpleado gente[], int t)
{
    int indice=-1;
    for(int i=0; i<t; i++)
    {
        if(gente[i].isEmpty ==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief cargar empleados a la lista
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id del proximo empleado a cargar
 * \return int devuelve 0 si pudo cargar el empleado, -1 si hubo un problema
 *
 */
int altaEmpleado(eEmpleado list[], int t, int id)
{
    int error=1;
    int indice;
    eEmpleado nuevoEmpleado;
    if(list!=NULL && t>0)
    {
        indice=buscarLugar(list,t);
        if(indice==-1)
        {
            printf("Sistema completo\n");
        }
        else
        {
            nuevoEmpleado.id=id;
            nuevoEmpleado.isEmpty=0;
            utn_getNombre(&nuevoEmpleado.name,51,"Ingrese nombre: ","\nError, Ingrese nombre valido\n",5);
            fflush(stdin);
            utn_getNombre(&nuevoEmpleado.lastName,51,"Ingrese apellido: ","\nError, ingrese apellido valido\n",5);
            fflush(stdin);
            utn_getNumeroFloat(&nuevoEmpleado.salary,"Ingrese salario: ","Error\n",0,10000,5);
            fflush(stdin);
            utn_getNumero(&nuevoEmpleado.sector,"Ingrese sector: ","\nError, ingrese sector valido\n",0,1000,5);
            fflush(stdin);
            list[indice]=nuevoEmpleado;
            error=0;
        }
    }
    return error;
}


/** \brief recibe un ID y busca ese id en la lista
 *
 * \param gente[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id que usa para buscar en la lista
 * \return int devuelve en que indice esta ese empleado
 *
 */
int buscarEmpleado(eEmpleado gente[], int t, int id)
{
    int indice=-1;
    for(int i=0; i<t; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


/** \brief impide la lectura del empleado modificando el estado el campo isEmpty
 *
 * \param gente[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \return int devuelve 0 si se pudo hacer la baja, 1 si se cancelo por el usuario, y -1 si hubo un problema
 *
 */
int bajaEmpleado(eEmpleado gente[], int t)
{
    int error=-1;
    int id;
    int indice;
    char confirma;
    if(gente!=NULL && t>0)
    {
        system("cls");
        printf(" ***Baja de persona***\n\n");
        if(!mostrarPersonas(gente,t))
        {
            printf("ingrese id: ");
            scanf("%d",&id);

            indice=buscarEmpleado(gente,t,id);
            if(indice==-1)
            {
                printf("No existe una persona con ese legajo\n\n");

            }
            else
            {
                mostrarPersona(gente[indice]);
                printf("Confirma la baja? s/n");
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma=='s')
                {
                    gente[indice].isEmpty=1;
                    printf("Baja exitosa\n");
                    error=0;
                }
                else
                {
                    printf("Baja cancelada por usuario\n");
                    error=1;
                }
            }
        }
    }
    return error;
}


/** \brief permite modificar los datos cargados en un empleado
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la lista
 * \param id int id del empleado a modificar
 * \return int devuelve 0 si se modifico algo, y 1 si hubo un error
 *
 */
int modificarEmpleado(eEmpleado list[],int t, int id)
{
    int error=1;
    char seguir = 's';
    int auxId;
    if(list!=NULL && t>0)
    {
        do
        {
            system("cls");
            printf("\t***Menu Modificacion***\n\n");
            mostrarPersonas(list,t);
            utn_getNumero(&auxId,"\nIngrese el ID del empleado a modificar :","Error, ingrese ID valido",1,id,5);
            switch(menuModificacion())
            {
            case 1:
                modificarNombre(list,t,auxId);
                seguir='n';
                error=0;
                break;
            case 2:
                modificarApellido(list,t,auxId);
                seguir='n';
                error=0;
                break;
            case 3:
                modificarSalario(list,t,auxId);
                seguir='n';
                error=0;
                break;
            case 4:
                modificarSector(list,t,auxId);
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
 * \param list[] eEmpleado estrucutra empleado
 * \param t int
 * \return int devuelve 0 si se pudo ordenar, -1 si hubo un problema
 *
 */
int ordenarEmpleados(eEmpleado list[], int t)
{
    int error=-1;
    int lista;
    int criterio;

    eEmpleado auxEmpleado;
    if(list !=NULL && t>0)
    {
        lista= mostrarPersonas(list,t);
        informeSalarios(list,t);
        if(lista==0)
        {
            if(menuOrdenar()==1)
            {
                utn_getNumero(&criterio,"\nSe ordenara primero por Apellido y luego por Sector\n1 para ordenar de forma ascendente\n2 para ordenar de forma descendente\nSu eleecion: ","Error, ingrse numero valido",1,2,5);
                switch(criterio)
                {
                case 1:
                    for(int i=0; i<t-1; i++)
                    {
                        for(int j=i+1; j<t; j++)
                        {
                            if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                            {
                                auxEmpleado = list[i];
                                list[i] = list[j];
                                list[j] = auxEmpleado;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                            {
                                auxEmpleado = list[i];
                                list[i] = list[j];
                                list[j] = auxEmpleado;
                            }
                        }
                    }
                    printf("\nOrdenamiento Exitoso.\n");
                    system("pause") ;
                    system("cls") ;
                    error=0;
                    break;
                case 2:
                    for(int i=0; i<t-1; i++)
                    {
                        for(int j=i+1; j<t; j++)
                        {
                            if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                            {
                                auxEmpleado = list[i];
                                list[i] = list[j];
                                list[j] = auxEmpleado;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                            {
                                auxEmpleado = list[i];
                                list[i] = list[j];
                                list[j] = auxEmpleado;
                            }
                        }
                    }
                    printf("\nOrdenamiento Exitoso.\n");
                    system("pause") ;
                    system("cls") ;
                    error=0;
                    break;
                default:
                    printf("No ingreso 1 o 2");
                }

            }
            error=0;
        }
        else
        {
            printf("Problema para mostrar empleados");
            system("pause");
            error=1;
        }
    }
    return error;
}


/** \brief imprime el menu que permite decidir si ordenar o no al listar los empleados
 *
 * \return int devuelve la eleccion del usuario
 *
 */
int menuOrdenar()
{
    int opcion;
    utn_getNumero(&opcion,"\n\nDesea ordenar?\n1 para ordenar\n2 para salir del menu listar\nSu eleccion: ","Error, ingrese numero valido",1,2,5);
    return opcion;
}


/** \brief modifica el nombre del empleado
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarNombre(eEmpleado list[],int t, int id)
{
    int error=1;
    int indice;
    eEmpleado modiEmpleado;
    if(list!=NULL && t>0)
    {
        indice=buscarEmpleado(list,t, id);
        if(indice==-1)
        {
            printf("No existe empleado\n");
        }
        else
        {
            utn_getNombre(&modiEmpleado.name,51,"Ingrese nombre: ","\nError, Ingrese nombre valido\n",5);
            strcpy(list[indice].name,modiEmpleado.name);
            error=0;
        }
    }
    return error;
}

/** \brief modifica el apellido del empleado
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarApellido(eEmpleado list[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado modiEmpleado;
    if(list!=NULL && t>0)
    {
        indice=buscarEmpleado(list,t, id);
        if(indice==-1)
        {
            printf("No existe empleado\n");
        }
        else
        {
            utn_getNombre(&modiEmpleado.lastName,51,"Ingrese apellido: ","\nError, Ingrese apellido valido\n",5);
            strcpy(list[indice].lastName,modiEmpleado.lastName);
            error=0;
        }
    }
    return error;
}

/** \brief modifica el salario del empleado
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarSalario(eEmpleado list[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado modiEmpleado;
    if(list!=NULL && t>0)
    {
        indice=buscarEmpleado(list,t, id);
        if(indice==-1)
        {
            printf("No existe empleado\n");
        }
        else
        {
            printf("Ingrese salario: ");
            scanf("%f",&modiEmpleado.salary);
            list[indice].salary=modiEmpleado.salary;
            error=0;
        }
    }
    return error;
}

/** \brief modifica el sector del empleado
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la estructra
 * \param id int id del empleado a modificar el nombre
 * \return int devuelve 0 si pudo modificar, 1 si hubo un problema
 *
 */
int modificarSector(eEmpleado list[],int t, int id)
{
    int error=0;
    int indice;
    eEmpleado modiEmpleado;
    if(list!=NULL && t>0)
    {
        indice=buscarEmpleado(list,t, id);
        if(indice==-1)
        {
            printf("No existe empleado\n");
        }
        else
        {
            utn_getNumero(&modiEmpleado.sector,"Ingrese sector: ","\nError, ingrese sector valido\n",0,1000,5);
            list[indice].sector=modiEmpleado.sector;
            error=0;
        }
    }
    return error;
}


/** \brief calcula y muestra el total de los salarios, el promedio, y cuantos estan por encima del promedio
 *
 * \param list[] eEmpleado estructura empleado
 * \param t int tamaño de la estrucutra
 * \return int devuelve 0 si pudo calcular, y -1 si hubo un problema
 *
 */
int informeSalarios(eEmpleado list[], int t)
{
	int error = -1;
    float acumulador = 0;
    int contador = 0;
    float promedio = 0;
    int contadorSalarioMayor=0;


    if(list!=NULL && t>0)
    {
        for(int i=0; i<t; i++)
         {
             if(list[i].isEmpty == 0)
             {
            	 acumulador +=list[i].salary;
                 contador++;
             }
          }

        promedio = (float) acumulador/ contador;
        for(int i=0; i<t; i++)
        {
        	if(list[i].salary>=promedio && list[i].isEmpty==0)
        	{
        		contadorSalarioMayor++;
            }
        }
        printf("\t**INFORME SALARIOS**\nEl monto total de los salarios es: $%.2f\nEl salario promedio es: $%.2f\n"
        		"La cantidad de empleados que superan el salario promedio son: %d\n",acumulador,promedio,contadorSalarioMayor);

        error=0;
    }
    return error;
}


