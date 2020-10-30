#include "Employee.h"

/** \brief pide un numero entero
 *
 * \param texto[] char el mensaje para pedir un numero
 * \param numero int* el numero a pedir
 * \return int retorna si lo logro o no
 *
 */
int pedirNumero(char texto[],int* numero);
/** \brief valida el numero
 *
 * \param texto[] char es el numero pasado a un char[] para validarlo
 * \return int retorna si lo logro o no
 *
 */
int validarNumero(char texto[]);
/** \brief guarda el valor del numero ingresado si es valido
 *
 * \param numero int* el numero a verificar
 * \param texto[] char mensaje para pedir el numero
 * \param textoError[] char mensaje de error
 * \param min int el numero minimo
 * \param max int el numero maximo
 * \return int retorna si lo logro o no
 *
 */
int guardarNumero(int* numero,char texto[],char textoError[],int min,int max);

/** \brief pide una cadena
 *
 * \param cadena[] char la cadena a pedir
 * \param mensaje[] char el mensaje para pedir una cadena
 * \return int retorna si lo logro o no
 *
 */
int pedirCadena(char cadena[],char mensaje[]);
/** \brief valida la cadena (solo letras)
 *
 * \param cadena[] char la cadena a validar
 * \return int retorna si lo logro o no
 *
 */
int validarCadenaSoloLetras(char cadena[]);
/** \brief guarda la cadena validada
 *
 * \param cadena[] char la cadena que se pide
 * \param mensaje[] char el mensaje para pedir la cadena
 * \param mensajeError[] char mensaje de error
 * \param tam int el tamaño
 * \return int  retorna si lo logro o no
 *
 */
int guardarCadenaSoloLetras(char cadena[],char mensaje[],char mensajeError[],int tam);

/** \brief pide un char
 *
 * \param cadena[] char el char que se pide
 * \param mensaje[] char el mensaje para pedir el char
 * \return int retor si lo logro o no
 *
 */
int pedirChar(char cadena[],char mensaje[]);
/** \brief valida el char
 *
 * \param cadena[] char el char a validar
 * \return int retorna si lo logro o no
 *
 */
int validarChar(char cadena[]);
/** \brief guarda el char validado
 *
 * \param cadena[] char el char a pedir
 * \param mensaje[] char el mensaje para pedir el char
 * \param mensajeError[] char es el mensaje de error
 * \param tam int el tamaño maximo
 * \return int retorna si lo logro o no
 *
 */
int guardarChar(char cadena[],char mensaje[],char mensajeError[],int tam);
