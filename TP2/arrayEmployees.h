#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

typedef struct
{
    int id;
    char description[51];

} Sector;

#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param employees Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* employees, int len);

/** \brief Harcodeo de sectores
 *
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño vector sectores
 * \return void
 *
 */
void hardcodearSectores(Sector* sectores,int tamSec);

/**
* \brief Muestra menu principal del programa
*
* \return Return opcion entero con la opcion del menu seleccionada
*/
int menuPrincipal();


/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param employees Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \param sectores Sector*
 * \param tamSec int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int addEmployee(Employee* employees, int len, int id, char name[],char lastName[],float salary,int sector, Sector* sectores, int tamSec);

/** \brief Asigna nros de id a partir del nro 1000 a cada empleado dado de alta
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño vector de empleados
 * \param idPedido int* puntero a idPedido
 * \return entero de validacion: 0 si es exitoso -1 si fallo
 *
 */
int traerIdRandom(Employee* employees, int tamEmp, int* idPedido);


/** \brief Busca el primer indice libre dentro del vector de empleados
 *         cuando el campo isEmpty es 1
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño vector de empleados
 * \return entero de indice: 0 si es exitoso -1 si fallo
 */
int buscarIndiceLibre(Employee* employees, int tamEmp);

/** \brief find an Employee by Id en returns the indice position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee indice position or (-1) if [Invalid length or NULL
 *         pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* employees, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*         find a employee] - (0) if Ok
*/
int removeEmployee(Employee* employees, int len, Sector* sectores, int tamSec);

/**
* \brief Muestra un menu con las opciones de datos del empleado que se pueden modificar
*
* \return Return opcion seleccionada
*/
int menuModificar();

/** \brief Recibe los vectores empleados y sectores, busca por legajo al empleado
 *         que se desea modificar y luego muestra menu de modificacion
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \return int -1 si no encuentra legajo 0 si encontro legajo
 */
int modificarEmpleado(Employee* employees, int tamEmp, Sector* sectores, int tamSec);

/** \brief Recibe id de empleado, solicita nombre nuevo que guarda en un aux,
 *         realiza validación, si pasa, guarda el nombre con el valor de aux
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \param indice int es el id del empleado
 * \return int -1 si no encuentra legajo 0 si encontro legajo
 *
 */
int modificarNombreEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice);

/** \brief Recibe id de empleado, solicita apellido nuevo que guarda en un aux,
 *         realiza validación, si pasa, guarda el apellido con el valor de aux
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \param indice int es el id del empleado
 * \return int -1 si no encuentra legajo 0 si encontro legajo
 *
 */
int modificarApellidoEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice);

/** \brief Recibe id de empleado, solicita sueldo nuevo que guarda en un aux,
 *         realiza validación, si pasa, guarda el sueldo con el valor de aux
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \param indice int es el id del empleado
 * \return int -1 si no encuentra legajo 0 si encontro legajo
 *
 */
int modificarSalarioEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice);

/** \brief Recibe id de empleado, solicita sector nuevo que guarda en un aux,
 *         realiza validación, si pasa, guarda el sector con el valor de aux
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \param indice int es el id del empleado
 * \return int -1 si no encuentra legajo 0 si encontro legajo
 *
 */
int modificarSectorEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice);


/** \brief Muestra menu de ordenar apellidos y sectores
 *
 * \param employees Employee*
 * \param tamEmp int
 * \return int retorna la opcion si es exitosa, sino -1 si no fue exitosa
 *
 */
int menuOrdenar(Employee* employees, int tamEmp);

/** \brief Sort the elements in the array of employees by name, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeesByName(Employee* employees, int len, int order);


/** \brief Realiza ordenamiento por metodo de burbujeo
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param i int primer elemento a comparar
 * \param j int segundo elemento a comparar
 * \return void
 */
void burbujeo(Employee* employees, int tamEmp, int i, int j);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* employees, int len, Sector* sectores, int tamSec);

/** \brief Carga y muestra un solo registro de empleado del vector de empleados
 *
 * \param employee Employee vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \return 0
 *
 */
int mostrarEmpleado(Employee employee, Sector* sectores, int tamSec);

/** \brief Muestra menu para seleccionar un sector y guardarlo para validarlo.
 *
 * \param input int*
 * \param mensaje[] char mensaje de operacion exitosa
 * \param mensajeError[] char mensaje de error de operacion
 * \param minLimite int limite minimo
 * \param maxLimite int limite maximo
 * \param sectores Sector*
 * \param tamSec int tamaño de vector de sectores
 * \return -1 si no pasa validacion de sector, 0 si esta OK
 *
 */
int elegirSector(int* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite, Sector* sectores, int tamSec);

/** \brief Recorre vector de sectores comparando id de sector con id sector del empleado
 *
 * \param idEmpleado int id de empleado
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \return -1 si no encuentra el id de sector; o id de sector si lo encuentra en el vector de sectores
 *
 */
int traerDescSector(int idEmpleado, Sector* sectores, int tamSec);

/** \brief Recibe vector de sectores y lo muestra por pantalla.
 *
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \return void
 */
void mostrarSectores(Sector* sectores, int tamSec);

/** \brief Muestra menu de opciones de reportes disponibles
 *
 * \return opcion seleccionada del menu
 *
 */
int menuInformes();

/** \brief Muestra menu de informes, valida que la opcion seleccionada sea correcta
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \param sectores Sector* vector de sectores
 * \param tamSec int tamaño de vector de sectores
 * \return -1 si la opcion no es valida, 0 si la opcion es valida
 */
int informes(Employee* employees, int tamEmp, Sector* sectores, int tamSec);

/** \brief Muestra informe de total de salarios, promedio y salarios que superan el promedio
 *
 * \param employees Employee* vector de empleados
 * \param tamEmp int tamaño de vector de empleados
 * \return void
 */
void informesSalary(Employee* employees, int tamEmp);
