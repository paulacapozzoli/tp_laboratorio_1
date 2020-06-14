/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas

/** \brief Constructor: Crea un nuevo LinkedList. Da valores iniciales a
 *         las variables y asigna las funciones a sus punteros.
 * \param void
 * \return retorna un nuevo LinkedList
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief Retorna el tama�o del LinkedList.
 *         Verifica que el puntero this sea distinto de NULL.
 *
 * \param this LinkedList*
 * \return Si la verificaci�n falla la funci�n retorna (-1) y
 *         si tiene �xito retorna la longitud del array.
 */
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Agrega un elemento al final de LinkedList.
 *         Verifica que el puntero this sea distinto de NULL.
 * \param this LinkedList* puntero this
 * \param pElement void*
 * \return Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Verifica que el puntero this sea distinto de NULL
 *         y que index sea positivo e inferior al tama�o del array
 *
 * \param this LinkedList* puntero this
 * \param index int indice del elemento
 * \return Si la verificaci�n falla la funci�n retorna (NULL)
 *         y si tiene �xito retorna el elemento.
 */
void* ll_get(LinkedList* this, int index);

int ll_set(LinkedList* this, int index,void* pElement);

/** \brief Elimina un elemento del LinkedList, en el �ndice especificado.
 *         Verifica que el puntero this sea distinto de NULL
 *         y que index sea positivo e inferior al tama�o del array.
 *
 * \param this LinkedList* puntero this
 * \param index int indice del elemento a eliminar
 * \return Si la verificaci�n falla la funci�n retorna (-1) y si tiene �xito (0).
 *
 */
int ll_remove(LinkedList* this,int index);

int ll_clear(LinkedList* this);

/** \brief Elimina el LinkedList. Verifica que el puntero this sea distinto de NULL.
 *
 * \param this LinkedList* puntero this
 * \return  Si la verificaci�n falla la funci�n retorna (-1)
 *          si esta vac�o (1)
 *          si contiene elementos (0).
 */
int ll_deleteLinkedList(LinkedList* this);

int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);

/** \brief Ordena los elementos del array recibiendo la funci�n que compare elementos
 *         y determine si se ordenan de forma ascendente o descendente; verifica que
 *         tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 *
 * \param void*
 * \param void*
 * \return  Si la verificaci�n falla (-1) caso contrario retorna (1).
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
