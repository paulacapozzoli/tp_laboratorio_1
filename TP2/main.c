/*************************************
*
* Programa: TP2 ABM e INFORMES de empleados
*
* Objetivo: Realizar altas, bajas y modificaciones
*           de una nomina de empleados y obtener
*           informes en base a los datos de cada
*           empleado
*
* Version: 1.2 del 16 de mayo de 2020
* Autora: PAULA CAPOZZOLI
*
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validarCampos.h"

#define TAMEMP 1000
#define TAMSEC 5

int main()
{
    char  seguir='s';
    char  confirmar;
    char  nombrePedido[51];
    char  apellidoPedido[51];
    float sueldoPedido;
    int idPedido;
    int sectorPedido;
    int lugarLibre;
    int contReintentos;
    int contEmpleados=0;
    int validarNombre=0;
    int validarApellido=0;
    int validarSueldo=0;
    int validarIngresoSector=0;
    Employee employees[TAMEMP];
    Sector sectors[TAMSEC];

    initEmployees(employees,TAMEMP);

    hardcodearSectores(sectors,TAMSEC);

    do{
        switch(menuPrincipal()){
            case 1:
                //se reinicia contador cada vez que se haga un alta
                contReintentos=0;

                //Busco el primer lugar libre
                lugarLibre=buscarIndiceLibre(employees,TAMEMP);
                //Si es mayor o igual a 0 comienzo el proceso de alta
                if(lugarLibre>=0){
                    //Obtengo randomId del empleado
                    traerIdRandom(employees,TAMEMP,&idPedido);
                    do{
                        //Obtengo nombre validando el largo y que sean solo solo letras
                        validarNombre=getString(nombrePedido,"Ingrese el nombre del empleado","ERROR, cantidad de caracteres de nombre [min 2 - max 50]",2,50);

                        //si validacion: exitosa = 1 , pido apellido; sino = -1, vuelvo a pedir nombre
                        if(validarNombre==-1){
                            //Incremento en 1 el contador de Reintentos
                            contReintentos++;
                            //Si es mayor a 2, dejo de iterar y no sigo pidiendo datos
                            if(contReintentos>2){
                                break;
                            }
                        }
                    }while(validarNombre==-1);
                    //Si validacion nombre OK, continuo pidiendo datos
                    if(validarNombre!=-1){
                        contReintentos=0;
                        do{
                            //Obtengo apellido validando el largo y que sean solo solo letras
                            validarApellido=getString(apellidoPedido,"Ingrese el apellido del empleado","ERROR, cantidad de caracteres de apellido [min 2 - max 50]",2,50);

                            //si validacion: exitosa = 1 , pido sueldo; sino = -1, vuelvo a pedir apellido
                            if(validarApellido==-1){
                                contReintentos++;
                                if(contReintentos>2){
                                    break;
                                }
                            }
                        }while(validarApellido==-1);
                    }
                        //Si validacion nombre y apellido OK, continuo pidiendo datos
                        if(validarNombre!=-1 && validarApellido!=-1){
                            contReintentos=0;
                            do{
                                //Obtengo salario
                                validarSueldo=getFloat(&sueldoPedido,"Ingrese el salario del empleado","ERROR, rango de salario [min 1 - max 999999]",1,1000000);

                                //si validacion: exitosa = 1 , elegir sector; sino = -1, vuelvo a pedir sueldo
                                if(validarSueldo==-1){
                                    contReintentos++;
                                    if(contReintentos>2){
                                        break;
                                    }
                                }
                            }while(validarSueldo==-1);
                        }
                        //Si validacion nombre, apellido y sueldo OK, continuo pidiendo datos
                        if(validarNombre!=-1 && validarApellido!=-1 && validarSueldo!=-1){
                            do{
                                //seleccion de sector deseado
                                validarIngresoSector=elegirSector(&sectorPedido,"Elegir sector al que pertenece el empleado","ERROR, rango de sector [1-5]",1,5,sectors,TAMSEC);

                                //si validacion: exitosa = 1 , paso datos a addEmployees; sino = -1, vuelvo a pedir sector
                                if(validarIngresoSector==-1){
                                    contReintentos++;
                                    if(contReintentos>2){
                                        break;
                                    }
                                }
                            }while(validarIngresoSector==-1);
                        }
                        //Si los datos fueron validados correctamente, se los envio a la funcion addEmployees
                        if((validarNombre!=-1) && (validarApellido!=-1) && (validarSueldo!=-1) && (validarIngresoSector!=-1)){
                            //Envio los datos validados del empleado pendiente a cargar a la funcion addEmployee
                            addEmployee(employees,TAMEMP,idPedido,nombrePedido,apellidoPedido,sueldoPedido,sectorPedido,sectors,TAMSEC);
                            contEmpleados++;
                        }else{
                            printf("No se pudo validar al empleado\n\n");
                        }
                    }else{
                        //si no hay espacio libre advierto al empleado
                        printf("No hay espacio para cargar mas empleados\n");
                    }
                system("pause");
                break;
            case 2:
                if(contEmpleados>0){
                    modificarEmpleado(employees,TAMEMP,sectors,TAMSEC);
                }else{
                    printf("\nNo existen empleados para modificar\n\n");
                }
                system("pause");
                break;

            case 3:
                if(contEmpleados>0){
                    removeEmployee(employees,TAMEMP,sectors,TAMSEC);
                    contEmpleados--;
                }else{
                    printf("\nNo existen empleados para dar de baja\n\n");
                }
                system("pause");
                break;
            case 4:
                if(contEmpleados>0){
                    informes(employees,TAMEMP,sectors,TAMSEC);
                }else{
                    printf("\nNo existen empleados para informar!!\n\n");
                }
                system("pause");
                break;
            case 5:
                printf("Confirma salir? s/n\n");
                fflush(stdin);
                confirmar=getche();

                if(tolower(confirmar)=='s'){
                    seguir='n';
                    printf("FIN DE PROGRAMA\n");
                    system("pause");
                }
                break;
        }
    }while(seguir=='s');

    return 0;
}
