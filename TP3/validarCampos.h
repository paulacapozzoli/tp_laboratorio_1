#ifndef VALIDARCAMPOS_H_INCLUDED
#define VALIDARCAMPOS_H_INCLUDED



#endif // VALIDARCAMPOS_H_INCLUDED

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minLimite Limite inferior a validar
* \param maxLimite Limite superior a validar
* \return Si obtuvo el numero [1] si no [-1]
*
*/
int getInt(int* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite);

/**
* \brief Le pasan un STRING, valida si es INT
* \param Recibe el numero ingresado auxNum
* \return Si es entero lo modifica y devuelve [0] si no [1]
*
*/
int isInteger(char auxNum[]);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minLimite Limite inferior a validar
* \param maxLimite Limite superior a validar
* \return Si obtuvo el numero [1] si no [-1]
*
*/
int getFloat(float* input,char mensaje[],char mensajeError[], float minLimite, float maxLimite);

/**
* \brief Le pasan un STRING, valida si es FLOAT
* \param Recibe el numero ingresado auxNum
* \return Si entero lo modifica y devuelve [0] si no [1]
*
*/
int isFloat(char auxNum[]);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minLimite Limite inferior a validar
* \param maxLimite Limite superior a validar
* \return 1
*
*/
int getChar(char* input,char mensaje[],char mensajeError[], char minLimite, char maxLimite);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minLimite Longitud mínima de la cadena
* \param maxLimite Longitud máxima de la cadena
* \return Si obtuvo la cadena [1] si no [-1]
*
*/
int getString(char* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite);

/**
* \brief Le pasan un STRING, valida si tiene solo letras
* \param Recibe un STRING auxiliar
* \return Si es char devuelve [1] si no [0]
*
*/
int isChar(char auxStr[]);
