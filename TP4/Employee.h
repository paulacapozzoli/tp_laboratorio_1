#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor(sin parámetros) Crea un nuevo empleado. Da valores iniciales a
 *         las variables y asigna las funciones a sus punteros.
 *
 * \return Retorna un nuevo empleado
 *
 */
Employee* employee_new();

/** \brief Constructor(con parámetros) Crea un nuevo empleado. Da valores a
 *         las variables y asigna las funciones a sus punteros.
 *
 * \param idStr char* cadena id
 * \param nombreStr char* cadena nombre
 * \param horasTrabajadasStr char* cadena horas trabajadas
 * \param sueldoStr char* cadena sueldo
 * \return Retorna un nuevo empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Muestra lista de empleados
 *
 * \param lista LinkedList* lista de empleados
 * \return int
 *
 */
int mostrarEmployees(LinkedList* lista);

/** \brief Muestra un solo empleado
 *
 * \param empleado Employee* puntero a empleado
 * \return int
 *
 */
int mostrarEmployeeP(Employee* empleado);

void employee_delete();

/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED

/** \brief Menu para elegir ordenamiento segun el dato que se desee
 *
 * \return opcion del dato elegido para hacer el ordenamiento
 *
 */
int menuSortEmple();

//REPLICAR PARA TODOS LOS CAMPOS DE STRUCT, PARA LUEGO USAR CON UN SOLO ll_sort
/** \brief Compara empleados por Id
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararEmpleadosId(void* emp1, void* emp2);

/** \brief Menu de ordenamiento por id
 *         1 para ordenar de manera ascendente, 2 para ordenar de manera descendente
 * \return 0
 *
 */
int menuSortId(LinkedList* lista);

/** \brief Compara empleados por Horas Nombre
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararEmpleadosNombre(void* emp1, void* emp2);

/** \brief Menu de ordenamiento por Nombre
 *         1 para ordenar de manera ascendente, 2 para ordenar de manera descendente
 * \return 0
 *
 */
int menuSortNombre(LinkedList* lista);

/** \brief Compara empleados por Horas trabajadas
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararEmpleadosHoras(void* emp1, void* emp2);

/** \brief Menu de ordenamiento por Horas
 *         1 para ordenar de manera ascendente, 2 para ordenar de manera descendente
 * \return 0
 *
 */
int menuSortHoras(LinkedList* lista);

/** \brief Compara empleados por Sueldo
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int compararEmpleadosSueldo(void* emp1, void* emp2);

/** \brief Menu de ordenamiento por Sueldo
 *         1 para ordenar de manera ascendente, 2 para ordenar de manera descendente
 * \return retorna 1 si no pudo ordenar, 0 si ordeno con exito
 *
 */
int menuSortSueldo(LinkedList* lista);

/** \brief Muestra menu principal del programa
 *
 * \return opcion del menu seleccionada
 *
 */
int menuPrincipal();

/** \brief Busca empleado por id y retorna índice donde se encuentre cargado
 *
 * \param lista LinkedList* lista de empleados
 * \param idEmp int id de empleado
 * \return indice del empleado
 *
 */
int buscarEmpleadoId(LinkedList* lista,int idEmp);

/** \brief Muestra menu para seleccionar el dato que se desee modificar
 *
 * \return la opcion seleccionada
 *
 */
int menuEditEmployee();

/** \brief Modifica el campo nombre de un empleado
 *
 * \param lista LinkedList* lista de empleados
 * \param indice int indice de la estructura empleado a modificar
 * \return retorna 1 si no pudo modificar nombre, 0 si modifico con exito
 *
 */
int editNombre(LinkedList* lista, int indice);

/** \brief Modifica el campo horasTrabajadas de un empleado
 *
 * \param lista LinkedList* lista de empleados
 * \param indice int indice de la estructura empleado a modificar
 * \return retorna 1 si no pudo modificar horas, 0 si modifico con exito
 *
 */
int editHoras(LinkedList* lista, int indice);

/** \brief Modifica el campo Sueldo de un empleado
 *
 * \param lista LinkedList* lista de empleados
 * \param indice int indice de la estructura empleado a modificar
 * \return retorna 1 si no pudo modificar Sueldo, 0 si modifico con exito
 *
 */
int editSueldo(LinkedList* lista, int indice);

int filterHours(void* employee);
