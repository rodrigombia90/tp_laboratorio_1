#include <stdio.h>
/** \brief muestra los resultados
 *
 * \param numeros 1
 * \param numero 2
 * \param bandera de hacer los calculos
 * \return la impresion de los resultados
 *
 */
float mostrarCalculos (float a, float b, float banderaCalculos);
/** \brief realiza los calculos llamando a todas las funciones
 *
 * \param numero 1
 * \param numero 2
 * \return los calculos resueltos
 *
 */
float hacerCalculos (float a, float b);
/** \brief Permite modificar el operando 1 (a)
 *
 * \param a float nuevo valor del operando 1
 * \return float nuevo valor del operando 1
 *
 */
float reingresarA(float a);
/** \brief Permite modificar el operando 2 (b)
 *
 * \param b float nuevo valor del operando 2
 * \return float nuevo valor del operando 2
 *
 */
float reingresarB(float b);
/** \brief suma los dos numero
 *
 * \param Operando 1
 * \param Operando 2
 * \return Resultado de la suma
 *
 */
float sumarNumeros (float, float);
/** \brief Resta el numero 1 y 2
 *
 * \param Operando 1
 * \param Operando 2
 * \return Resultaado de la resta
 *
 */
float restarNumeros (float, float);
/** \brief Multiplica los dos numeros
 *
 * \param Operando 1
 * \param Operando 2
 * \return Resultado de la multiplicacion
 *
 */
float multiplicarNumeros (float, float);
/** \brief Divide el numero 1 y 2
 *
 * \param Operando 1
 * \param Operando 2
 * \return Resultado de la division
 *
 */
float dividirNumeros (float a, float b);
/** \brief Calcula el factorial
 *
 * \param Operando 1
 * \return Resultado del factorial
 *
 */
long long int factorial(int num);
