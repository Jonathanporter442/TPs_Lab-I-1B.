/** \brief carga los empleados del archivo "data scv"
 *
 * \param path char* el archivo
 * \param pArrayListEmployee LinkedList* la lista de empleasdos
 * \return int retorna 1 si logro la carga o 0 si no lo logro
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief carga los empleados del archivo "data bin"
 *
 * \param path char* el archivo
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int retorna 1 si logro la carga o 0 si no lo logro
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief carga un empleado a la lista
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int retorna -1 si no logro agregar al empleado o 1 si lo logro
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief modifica a un empleado
 *
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \return int retorna -1 si no logro modificar o 1 si lo logro
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief da de baja un empleado
 *
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \return int retorna -1 si no lo logro, 1 si lo logro o 2 si se cancelo la operacion
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief muestra la lista de los empleados cargados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int retorna -1 si no lo logro o 1 si lo logro
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief ordena los empleados bajo un criterio
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si lo logro 0 -1 si no logro
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief guarda los empleados en una archivo txt
 *
 * \param path char* el archivo
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \return int retorna 1 si lo logro 0 -1 si no logro
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda los empleados en un archivo bin
 *
 * \param path char* el archivo
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \return int retorna 1 si lo logro 0 -1 si no logro
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief busca el id mayor de la lista de empledos
 *
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \return int el id mayor
 *
 */
int buscarMayorId(LinkedList* pArrayListEmployee);
/** \brief busca el empleado por el id
 *
 * \param pArrayListEmployee LinkedList* la lista de empleado
 * \param idEmpleado int el id del empleado que se desea buscar
 * \return void* retorna un empleado
 *
 */
void* buscarEmpleadoPorId1(LinkedList* pArrayListEmployee,int idEmpleado);
