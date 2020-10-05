#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
int inicializarEmpleados(eEmpleado gente[],int tam)
{
    int error=-1;
    if(gente!=NULL && tam>0 ) //no podemos permitir que la direccion de memoria de "gente" apunte a NULL. Hay que validar eso
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty=1;//asi se recorre cada parte del array y se setea en 1
        }
        error=0;
    }

    return error;
}

int menuOpciones()
{
    int opcion;
    printf("\t***Bienvenido a la base de datos de empleados***\n\n");
    printf("1 Alta\n");
    printf("2 Baja\n");
    printf("3 Modificacion\n");
    printf("4 Informar\n");
    printf("5 Salir\n\n");
    printf("Ingrese la opcion elegida: ");
    scanf("%d",&opcion);
    return opcion;
}

void mostrarPersona(eEmpleado unaPersona)
{
    printf(" %4d  %10s  %10s  %5d  %d\n",unaPersona.id,unaPersona.name,unaPersona.lastName,unaPersona.salary,unaPersona.sector);
}


int mostrarPersonas(eEmpleado gente[], int t)
{
    int error=1;
    int flag=0;
    if(gente!=NULL && t>0)
    {
        //system("cls");
        printf("Legajo   nombre      apellido      salario    sector\n");
        printf("-----------------------------------------------\n");
        for(int i=0; i<t; i++)
        {
            if(gente[i].isEmpty==0)
            {
                mostrarPersona(gente[i]);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay Empleados cargados");
            error=0;
        }
        printf("\n\n");
        //error estaba aca, pero creo que iba en el else. PRESTAR ATENCION
    }
    return error;
}

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
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);
            printf("Ingrese salario: ");
            scanf("%d",&nuevoEmpleado.salary);
            printf("Ingrese sector: ");
            scanf("%d",&nuevoEmpleado.sector);

            list[indice]=nuevoEmpleado;
            error=0;
        }
    }
    return error;
}

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

int bajaEmpleado(eEmpleado gente[], int t)
{
    int error=1;
    int id;
    int indice;
    int flagCarga;
    char confirma;
    if(gente!=NULL && t>0)
    {
        system("cls");
        printf(" ***Baja de persona***\n\n");
        flagCarga=mostrarPersonas(gente,t);
        if(flagCarga==1)
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
                    error=0;
                }
                else
                {
                    error=2;
                }
            }
        }

    }
    return error;
}

int ordenarEmpleados(eEmpleado list[], int t, int criterio)
{
    int error=1;
    int i;
    mostrarPersonas(list,t);
    if(list==0)
    {
        printf("Ingrese criterio de ordenamiento.\n1_Ascendente\n2_Descendente\n");
        printf("Criterio: ");
        scanf("%d",&criterio);
        eEmpleado auxEmpleado;
        if(list !=NULL && t>0 && criterio>=0 && criterio <= 1)
        {
            for(int i=0; i<t-1; i++)
            {
                for(int j=i+1; j<t; j++)
                {
                    if(strcpy(list[i].lastName,list[j].lastName)>0 || strcpy(list[i].sector,list[j].sector)>0 && criterio)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                    else if (strcpy(list[i].lastName,list[j].lastName)<0 || strcpy(list[i].sector,list[j].sector)<0 &&!criterio)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }
            error=0;
        }
    }
    return error;
}


/*
strlen(varialbE) esta variable tiene que estar entre 65 y 90 y 97 y 122
por cada caracter que encuentre en la variable lo compara en esos numeros


*/
