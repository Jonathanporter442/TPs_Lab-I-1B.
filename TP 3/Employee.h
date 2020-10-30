#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief recerva espacion en memoria para un empleado
 *
 * \return Employee* retorna un puntero empleado
 *
 */
Employee* employee_new();
/** \brief reserva espacio en memoria para un empleado pero se le carga, lo que se pasa como parametro
 *
 * \param idStr char* el id del empleado
 * \param nombreStr char* el nombre del empleado
 * \param horasTrabajadasStr char* horas tabrajadas del empleado
 * \param sueldoStr char* el sueldo del empleado
 * \return Employee* retorna un puntero-empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief libera el espacio en memoria reservado para ese empleado
 *
 * \param this Employee* un empleado
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief le asigna el id al empleado
 *
 * \param this Employee* un empleado
 * \param id int el id que se asigna
 * \return int int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_setId(Employee* this,int id);
/** \brief obtiene el id de un empleado
 *
 * \param this Employee* un empleado
 * \param id int* en donde se va a guardar la id obtenida
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief le asigna un nombre al empleado
 *
 * \param this Employee* un empleado
 * \param nombre char* el nombre que se va asignar
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief se obtiene el nombre se un empleado
 *
 * \param this Employee* un empleado
 * \param nombre char* el anombre que se obtiene
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief se le asinga las horas trabajas al empleado
 *
 * \param this Employee* un empleado
 * \param horasTrabajadas int las horas trabajadas que se le va a asignar
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief se obtiene las horas trabajas se un empleado
 *
 * \param this Employee* un empleado
 * \param horasTrabajadas int* son las horas que se obtiene
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief se le asgina el sueldo al empleado
 *
 * \param this Employee* un empleado
 * \param sueldo int el sueldo que se asigna
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief se obtiene el sueldo de un empleado
 *
 * \param this Employee* el empleado
 * \param sueldo int* el sueldo que se va a obtener
 * \return int retorna 1 si lo logro 0 -1 si no logro
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief se encarga de ordenar por nombre
 *
 * \param e1 void*  parametro a comparar
 * \param e2 void* parametro a comparar
 * \return int retorna 1 o -1 para ordenar para indicarle como ordenar
 *
 */
int employee_CompareByName(void* e1, void* e2);
/** \brief se encarga de ordenar por id
 *
 * \param e1 void*  parametro a comparar
 * \param e2 void*  parametro a comparar
 * \return int retorna 1 o -1 para ordenar para indicarle como ordenar
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief muestra un empleado
 *
 * \param empleado Employee* el empleado
 * \return void
 *
 */
void mostrarUnEmpleado(Employee* empleado);


#endif // employee_H_INCLUDED
