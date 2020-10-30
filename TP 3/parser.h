/** \brief lee los datos del archivo de texto y lo guarda a la estructura
 *
 * \param pFile FILE* el archivo
 * \param pArrayListEmployee LinkedList* la lista
 * \return int retorna 1 si lo logro o 0 si no lo logro
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief lee los datos del archivo de bin y lo guarda a la estructura
 *
 * \param pFile FILE* el archivo
 * \param pArrayListEmployee LinkedList* la lista
 * \return int retorna 1 si lo logro o 0 si no lo logro
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
