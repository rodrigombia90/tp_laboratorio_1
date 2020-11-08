#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* emp;
    emp = (Employee*)malloc(sizeof(Employee));
    emp->id = 0;
    strcpy(emp->nombre, "");
    emp->horasTrabajadas = 0;
    emp->sueldo = 0;

    return emp;
};

/** \brief Ordena los empleados por nombre
 *
 * \param puntero a un empleado
 * \param puntero a otro empleado
 * \return la comparacion entre ambos nombres
 *
 */

int employeeSortByName(void* empleadoA,void* empleadoB)
{
    int error=0;
    char nombreA[128];
    char nombreB[128];

    if(employee_getNombre((Employee*) empleadoA,nombreA) &&//aca lo que devuelve lo casteo a Employee*
            employee_getNombre((Employee*) empleadoB,nombreB))
    {
        error=strcmp(nombreA,nombreB);
    }

    return error;
}

/** \brief Ordena los empleados por ID
 *
 * \param puntero a un empleado
 * \param puntero a otro empleado
 * \return la comparacion entre ambos ID
 *
 */

int employeeSortById(void* empleadoA,void* empleadoB)
{
    int error=0;
    int idEmpleadoA;
    int idEmpleadoB;

    if(employee_getId((Employee*) empleadoA,&idEmpleadoA) &&
            employee_getId((Employee*) empleadoB,&idEmpleadoB))
    {
        error=idEmpleadoA-idEmpleadoB;
    }

    return error;


}

/** \brief Ordena los empleados por ID
 *
 * \param puntero a un empleado
 * \param puntero a otro empleado
 * \return la comparacion entre ambos salarios
 *
 */

int employeeSortBySalary(void* empleadoA,void* empleadoB)
{
    int error=0;
    int salarioEmpleadoA;
    int salarioEmpleadoB;

    if(employee_getSueldo((Employee*) empleadoA,&salarioEmpleadoA) &&
            employee_getSueldo((Employee*) empleadoB,&salarioEmpleadoB))
    {
        error=salarioEmpleadoA-salarioEmpleadoB;
    }

    return error;


}

/** \brief Ordena los empleados por horas trabajadas
 *
 * \param puntero a un empleado
 * \param puntero a otro empleado
 * \return la comparacion entre ambas horas trabajadas
 *
 */

int employeeSortByworkedHours(void* empleadoA,void* empleadoB)
{
    int error=0;
    int horasEmpleadoA;
    int horasEmpleadoB;

    if(employee_getHorasTrabajadas((Employee*) empleadoA,&horasEmpleadoA) &&
            employee_getHorasTrabajadas((Employee*) empleadoB,&horasEmpleadoB))
    {
        error=horasEmpleadoA-horasEmpleadoB;
    }

    return error;


}

 /** \brief Setea los datos del nuevo empleado
  *
  * \param Puntero a cadena
  * \param Puntero a cadena
  * \param Puntero a cadena
  * \param Puntero a cadena
  * \return Los datos del nuevo empleado
  *
  */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* nuevoEmpleado;
    nuevoEmpleado = NULL;
	nuevoEmpleado = employee_new();

	if(nuevoEmpleado != NULL)
	{
		if(employee_setId(nuevoEmpleado,atoi(idStr)) == 1 &&
			employee_setNombre(nuevoEmpleado, nombreStr)== 1&&
            employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))== 1
			&& employee_setSueldo(nuevoEmpleado, atoi(sueldo))== 1)
		{
			//employee_delete(nuevoEmpleado);
		}
	}

	return nuevoEmpleado;

}

/** \brief Setea el ID
 *
 * \param Puntero a Employee
 * \param ID del empleado
 * \return 1 si seteo bien, 0 su fallo
 *
 */

int employee_setId(Employee* this,int id)
{

    int error = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        error = 1;
    }
    return error;
}

/** \brief Setea el nombre
 *
 * \param Puntero a Employee
 * \param Nombre del empleado
 * \return 1 si seteo bien, 0 su fallo
 *
 */

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        error = 1;
    }
    return error;
}

/** \brief Setea las horas trabajadas
 *
 * \param Puntero a Employee
 * \param horas trabajadas del empleado
 * \return 1 si seteo bien, 0 su fallo
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int error = 0;
    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 1;
    }
    return error;
}

/** \brief Setea el sueldo
 *
 * \param Puntero a Employee
 * \param Sueldo del empleado
 * \return 1 si seteo bien, 0 su fallo
 *
 */

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        error = 1;
    }
    return error;
}

/** \brief Consigue Id
 *
 * \param  puntero a Employee
 * \param  puntero a id de empleado
 * \return int error
 *
 */

int employee_getId(Employee* this,int* id)
{
    int error = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        error = 1;
    }
    return error;
}

/** \brief Obtiene Nombre
 *
 * \param Puntero a Employee
 * \param Puntro al nombre
 * \return int error
 *
 */

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 1;
    }
    return error;
}

/** \brief Obtiene Horas Trabajadas
 *
 * \param Puntero a Employee
 * \param Puntro a las horas trabajadas
 * \return int error
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 1;
    }
    return error;
}

/** \brief Obtengo sueldo
 *
 * \param Puntero a Employee
 * \param Puntro al sueldo
 * \return int error
 *
 */

int employee_getSueldo(Employee* e,int* sueldo)
{
    int error = 0;

    if( e != NULL && sueldo != NULL)
    {
        *sueldo = e->sueldo;
        error = 1;
    }
    return error;
}

/** \brief Ordenamiento por ID
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return int error
 *
 */

int employee_CompareById(void* e1,void* e2)
{
    int error = 0;
    int idEmp1;
    int idEmp2;

    if(e1 != NULL && e2 != NULL)
    {
        employee_getId(e1,&idEmp1);
        employee_getId(e2,&idEmp2);

        if(idEmp1 > idEmp2){
            error = 1;
        }
        if(idEmp1 < idEmp2){
            error = -1;
        }

    }
    else
    {
        return -2;
    }
    return error;
}

/** \brief Ordenamiento por Nombre
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return int error
 *
 */

int employee_CompareByName(void* e1,void* e2)
{
    int error = -2;
    char nombrEmp1[128];
    char nombrEmp2[128];

    Employee* emp;
    Employee* emp2;

    emp = (Employee*)e1;
    emp2 = (Employee*)e2;

    if(e1 != NULL && e2 != NULL)
    {
        employee_getNombre(emp,nombrEmp1);
        employee_getNombre(emp2,nombrEmp2);

        error = strcmp(nombrEmp1,nombrEmp2);
    }

    return error;
}

/** \brief Ordenamiento por Horas Trabajadas
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return int error
 *
 */

int employee_CompareByHoras(void* e1,void* e2)
{
    int error = 0;
    int hsEmp1;
    int hsEmp2;

    if(e1 != NULL && e2 != NULL)
    {
        employee_getHorasTrabajadas(e1,&hsEmp1);
        employee_getHorasTrabajadas(e2,&hsEmp2);

        if(hsEmp1 > hsEmp2){
            error = 1;
        }
        if(hsEmp1 < hsEmp2){
            error = -1;
        }
    }
    else
    {
        return -2;
    }
    return error;
}

/** \brief Ordena por sueldo
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return int error
 *
 */

int employee_CompareBySueldo(void* e1,void* e2)
{
    int error = 0;
    int sueldoEmp1;
    int sueldoEmp2;


    if(e1 != NULL && e2 != NULL)
    {
        employee_getSueldo(e1,&sueldoEmp1);
        employee_getSueldo(e2,&sueldoEmp2);

        if(sueldoEmp1 > sueldoEmp2){
            error = 1;
        }
        if(sueldoEmp1 < sueldoEmp2){
            error = -1;
        }
    }
    else
    {
        return -2;
    }
    return error;
}

/** \brief Imprime un empleado
 *
 * \param Puntero a Employee
 * \return 1 si pudo mostrar, 0 si fallo
 *
 */

int mostrarEmpleado(Employee* unEmpleado)
{
    int error=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    employee_getId(unEmpleado,&id);
    employee_getNombre(unEmpleado,nombre);
    employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
    employee_getSueldo(unEmpleado,&sueldo);
    if(unEmpleado!= NULL)
    {
        printf("%4d  %14s        %4d          %6d\n",id,nombre,horasTrabajadas,sueldo);
        error=1;
    }
    return error;
}



