/*************************************
*
* Programa: TP4
*
* Objetivo: Realizar altas, bajas y modificaciones
*           de una nomina de empleados
*
* Version: 1.5 del 27 de junio de 2020
* Autora: PAULA CAPOZZOLI
*
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    char seguir='s';

    LinkedList* listaEmployees = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
            case 1:
                printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
                if(controller_loadFromText("data.csv",listaEmployees)){
                    printf("Error al cargar empleados\n\n");
                }else{
                    printf("Empleados cargados con exito\n\n");
                }
                break;

            case 2:
                printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
                if(controller_loadFromBinary("data.csv",listaEmployees)){
                    printf("Error al cargar empleados\n\n");
                }else{
                    printf("Empleados cargados con exito\n\n");
                }
                break;

            case 3:
                printf("3. Alta de empleado\n");
                if(controller_addEmployee(listaEmployees)){
                    printf("Error en alta de empleados\n\n");
                }else{
                    printf("Empleados dados de alta con exito\n\n");
                }
                break;

            case 4:
                printf("4. Modificar datos de empleado\n");
                if(controller_editEmployee(listaEmployees)){
                    printf("Error en modificacion de empleados\n\n");
                }else{
                    printf("Empleados modificados con exito\n\n");
                }
                break;

            case 5:
                printf("5. Baja de empleado\n");
                if(controller_removeEmployee(listaEmployees)||controller_removeEmployee(listaEmployees)==-1){
                    printf("Error en baja de empleados\n\n");
                }else{
                    printf("Empleados dados de baja con exito\n\n");
                }
                break;

            case 6:
                printf("6. Listar empleados\n");
                if(controller_ListEmployee(listaEmployees)){
                    printf("Error al listar empleados\n\n");
                }else{
                    printf("Empleados listados con exito\n\n");
                }
                break;

            case 7:
                printf("7. Ordenar empleados\n");
                if(controller_sortEmployee(listaEmployees)){
                    printf("Error al ordenar empleados\n\n");
                }else{
                    printf("Empleados ordenados con exito\n\n");
                }
                break;

            case 8:
                printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
                if(controller_saveAsText("data.csv",listaEmployees)){
                    printf("Error al guardar empleados\n\n");
                }else{
                    printf("Empleados guardados con exito\n\n");
                }
                break;

            case 9:
                printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
                if(controller_saveAsBinary("data.bin",listaEmployees)){
                    printf("Error al guardar empleados\n\n");
                }else{
                    printf("Empleados guardados con exito\n\n");
                }
                break;

            case 10:
                printf("10. Filtrar empleados con hs trabajadas que superan 180hs\n");
                if(controller_filterHours(listaEmployees)){
                    printf("Error al filtrar empleados\n\n");
                }else{
                    printf("Empleados filtrados segun horas trabajadas con exito\n\n");
                }
                break;

            case 11:
                printf("\n*** Programa finalizado ***\n\n");
                seguir='n';
                break;

            default:
                printf("Opcion no valida - Ingrese numero en el rango 1-11\n\n");
                break;
        }
        system("pause");

    }while(seguir!='n');

    ll_deleteLinkedList(listaEmployees);

    return 0;
}
