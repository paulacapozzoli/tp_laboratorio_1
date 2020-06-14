/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si carg� los datos con �xito
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si carg� los datos con �xito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega a una lista existente de empleados los valores recibidos
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realiz� el alta con �xito
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modifica los datos de un empleado que se busca por id, eligiendo el campo que se desee modificar
 *         mediante un menu de opciones
  *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realiz� la modificaci�n con �xito
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de un empleado que se busca por id
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realiz� la baja con �xito
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si list� los empleados con �xito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados segun el dato seleccionado en un menu
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si orden� los empleados con �xito
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si guard� los datos con �xito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si guard� los datos con �xito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


