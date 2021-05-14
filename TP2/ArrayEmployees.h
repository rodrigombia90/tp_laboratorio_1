#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;// 1 esta vacia/0 esta lleno
} eEmpleado;

int menuOpciones();
int mostrarPersonas(eEmpleado empleados[], int t);
void mostrarPersona(eEmpleado unaPersona);
int inicializarEmpleados(eEmpleado empleados[],int tam);
int buscarLibre(eEmpleado empleados[], int t);
int altaEmpleado(eEmpleado empleados[], int t, int id);
int bajaEmpleado(eEmpleado empleados[], int t);
int buscarEmpleado(eEmpleado empleados[], int t, int id);
int ordenarEmpleados(eEmpleado empleados[], int t);
int menuModificacion();
int modificarNombre(eEmpleado empleados[],int t, int id);
int modificarApellido(eEmpleado empleados[],int t, int id);
int modificarSalario(eEmpleado empleados[],int t, int id);
int modificarSector(eEmpleado empleados[],int t, int id);
int modificarEmpleado(eEmpleado empleados[],int t, int id);
int informeSalarios(eEmpleado empleados[], int t);
int menuOrdenar();
#endif // INPUT_H_INCLUDED



