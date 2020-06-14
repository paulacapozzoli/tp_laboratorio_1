/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si cargó los datos con éxito
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si cargó los datos con éxito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega a una lista existente de empleados los valores recibidos
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realizó el alta con éxito
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modifica los datos de un empleado que se busca por id, eligiendo el campo que se desee modificar
 *         mediante un menu de opciones
  *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realizó la modificación con éxito
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de un empleado que se busca por id
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si realizó la baja con éxito
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si listó los empleados con éxito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados segun el dato seleccionado en un menu
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si ordenó los empleados con éxito
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si guardó los datos con éxito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 1 si da error, y 0 si guardó los datos con éxito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


