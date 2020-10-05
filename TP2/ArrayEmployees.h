#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    int salary;
    int sector;
    int isEmpty;// 1 esta vacia    0 esta lleno
} eEmpleado;

int menuOpciones();
int mostrarPersonas(eEmpleado gente[], int t);
void mostrarPersona(eEmpleado unaPersona);
int inicializarEmpleados(eEmpleado gente[],int tam);
int buscarLugar(eEmpleado gente[], int t);
int altaEmpleado(eEmpleado list[], int t, int id); //devielve 0 todo ok, devuelve 1 hubo falla
int bajaEmpleado(eEmpleado gente[], int t);
int buscarEmpleado(eEmpleado gente[], int t, int id);
int ordenarEmpleados(eEmpleado list[], int t, int criterio);
#endif // INPUT_H_INCLUDED



