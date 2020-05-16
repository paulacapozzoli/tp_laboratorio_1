#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validarCampos.h"

/* valores para validar existencia de empleado para baja o modificacion
 o bien registro libre para dar alta de empleado */
#define LIBRE 1
#define OCUPADO 0

int initEmployees(Employee* employees, int len){
    for(int i=0;i<len;i++){
        employees[i].isEmpty=LIBRE;
    }
    return 0;
}

void hardcodearSectores(Sector* sectores,int tamSec){
    Sector auxSectores[]={
    {1,"Sistemas"},
    {2,"Contable"},
    {3,"Mailroom"},
    {4,"Jefatura"},
    {5,"RRHH"},
    };

    for(int i=0;i<tamSec;i++){
        sectores[i]=auxSectores[i];
    }
}

int menuPrincipal(){
    int opcion;
    char auxOpcion[3];

    system("cls");
    printf("****** ABM ******\n\n");
    printf("*** MENU ***\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%s",auxOpcion);

    if(isInteger(auxOpcion)==0){
        printf("Error. Ingrese solo NUMEROS");
        system("pause");
    }else{
        opcion=atoi(auxOpcion);
    }

    return opcion;
}

int addEmployee(Employee* employees, int len, int id, char name[],char lastName[],float salary,int sector, Sector* sectores, int tamSec){
    int validacion=0;
    int indice;

    indice=buscarIndiceLibre(employees,len);

    employees[indice].id=id;
    strcpy(employees[indice].name,name);
    strcpy(employees[indice].lastName,lastName);
    employees[indice].salary=salary;
    employees[indice].sector=sector;
    employees[indice].isEmpty=OCUPADO;

    system("cls");
    printf("EMPLEADO PARA DAR DE ALTA\n\n");
    printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
    mostrarEmpleado(employees[indice],sectores,tamSec);

    printf("\nEmpleado dado de alta con exito\n\n");

    return validacion;
}

int traerIdRandom(Employee* employees, int tamEmp, int* idPedido){
    int primerIdRandom=1000;
    int indice;
    int validacion=-1;

    indice=buscarIndiceLibre(employees,tamEmp);

    if(indice>=0){
        *idPedido=primerIdRandom+indice;
        validacion=0;
    }
    return validacion;
}

int buscarIndiceLibre(Employee* employees, int tamEmp){
    int indice=-1;

    for(int i=0;i<tamEmp;i++){
        if(employees[i].isEmpty==1){
            indice=i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee* employees, int len,int id){
    int indice=-1;

    for(int i=0;i<len;i++){
        if(employees[i].id==id){
            indice=i;
        }
    }
    return indice;
}

int removeEmployee(Employee* employees, int len, Sector* sectores, int tamSec){
    int idEmpleado;
    int validacion=0;
    int indice;
    char confirmar;

    printEmployees(employees,len,sectores,tamSec);
    printf("Ingrese el legajo del empleado a dar de baja: ");
    scanf("%d",&idEmpleado);

    indice=findEmployeeById(employees,len,idEmpleado);

    if(indice==-1){
        printf("No se encontro el empleado ingresado\n");
        system("pause");
        validacion=-1;
    }else{
        system("cls");
        printf("*** EMPLEADO PARA ELIMINAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
        printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
        mostrarEmpleado(employees[indice],sectores,tamSec);
        printf("Confirma baja?\n");
        fflush(stdin);
        printf("Ingrese s/n: ");
        scanf("%c",&confirmar);

        if(confirmar=='s'){
            employees[indice].isEmpty=LIBRE;
            validacion=0;
            printf("\nEmpleado dado de baja con exito\n\n");
        }else{
            validacion=-1;
        }
    }
    return validacion;
}

int menuModificar(){
    int opcion;

    system("cls");
    printf("Que dato quiere modificar?\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int modificarEmpleado(Employee* employees, int tamEmp, Sector* sectores, int tamSec){
    int validacion=0;
    int indice;
    int opcion;
    int idEmpleado;

    printEmployees(employees,tamEmp,sectores,tamSec);
    printf("Ingrese el legajo del empleado a modificar: ");
    scanf("%d",&idEmpleado);

    indice=findEmployeeById(employees,tamEmp,idEmpleado);

    if(indice==-1){
        printf("No se encontro el empleado ingresado\n");
        validacion=-1;
    }else{
        opcion=menuModificar();

        switch(opcion){
            case 1:
                modificarNombreEmple(employees,tamEmp,sectores,tamSec,indice);
                break;
            case 2:
                modificarApellidoEmple(employees,tamEmp,sectores,tamSec,indice);
                break;
            case 3:
                modificarSalarioEmple(employees,tamEmp,sectores,tamSec,indice);
                break;
            case 4:
                modificarSectorEmple(employees,tamEmp,sectores,tamSec,indice);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }
    return validacion;
}

int modificarNombreEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice){
    char auxName[51];
    char confirmar;
    int validacion;

    validacion=getString(auxName,"Ingrese el NUEVO nombre del empleado","ERROR, cantidad de caracteres de nombre [min 2 - max 50]",2,50);

    if(validacion==1){
        system("cls");

        printf("*** EMPLEADO PARA MODIFICAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
        printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
        mostrarEmpleado(employees[indice],sectores,tamSec);

        printf("Confirma nombre: %s? s/n\n",auxName);
        fflush(stdin);
        scanf("%c",&confirmar);

        if(confirmar=='s'){
            strcpy(employees[indice].name,auxName);
            validacion=0;
        }else{
            validacion=-1;
        }
    }else{
        validacion=-1;
    }
    return validacion;
}

int modificarApellidoEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice){
    char auxLastName[51];
    char confirmar;
    int validacion;

    validacion=getString(auxLastName,"Ingrese el NUEVO apellido del empleado","ERROR, cantidad de caracteres de apellido [min 2 - max 50]",2,50);

    if(validacion==1){
        system("cls");

        printf("*** EMPLEADO PARA MODIFICAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
        printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
        mostrarEmpleado(employees[indice],sectores,tamSec);

        printf("Confirma apellido: %s? s/n\n",auxLastName);
        fflush(stdin);
        scanf("%c",&confirmar);

        if(confirmar=='s'){
            strcpy(employees[indice].lastName,auxLastName);
            validacion=0;
        }else{
            validacion=-1;
        }
    }else{
        validacion=-1;
    }

    return validacion;
}

int modificarSalarioEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice){
    float auxSalary;
    int validacion;
    char confirmar;

    validacion=getFloat(&auxSalary,"Ingrese el NUEVO salario del empleado","ERROR, rango de salario [min 1 - max 999999]",1,100000);

    if(validacion==1){
        system("cls");

        printf("*** EMPLEADO PARA MODIFICAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
        printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
        mostrarEmpleado(employees[indice],sectores,tamSec);

        printf("Confirma salario: %.2f? s/n\n",auxSalary);
        fflush(stdin);
        scanf("%c",&confirmar);

        if(confirmar=='s'){
            employees[indice].salary=auxSalary;
            validacion=0;
        }else{
            validacion=-1;
        }
    }else{
        validacion=-1;
    }

    return validacion;
}

int modificarSectorEmple(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int indice){
    int auxIdSector=0;
    int validacion;
    char confirmar;

    printf("AUXILIAR ID SECTOR(envio): %d\n\n",auxIdSector);
    validacion=elegirSector(&auxIdSector,"Elija el NUEVO sector del empleado","ERROR, rango de sector[0-5]",0,5,sectores,tamSec);

    if(validacion==1){
        system("cls");

        printf("*** EMPLEADO PARA MODIFICAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
        printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");
        mostrarEmpleado(employees[indice],sectores,tamSec);

        printf("AUXILIAR ID SECTOR(recibo): %d\n\n",auxIdSector);
        printf("Confirmara sector: %s? s/n\n",sectores[auxIdSector-1].description);
        fflush(stdin);
        scanf("%c",&confirmar);

        if(confirmar=='s'){
            employees[indice].sector=auxIdSector;
            validacion=0;
        }else{
            validacion=-1;
        }
    }else{
        validacion=-1;
    }
    return validacion;
}

int menuOrdenar(Employee* employees, int tamEmp){
    int order;

    system("cls");
    printf("Ordenar de [A-Z] o de [Z-A]\n");
    printf("1- [A-Z]\n");
    printf("2- [Z-A]\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    sortEmployeesByName(employees,tamEmp,order);

    return order;
}

int sortEmployeesByName(Employee* employees, int len, int order){
    int ordenOk=0;

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(employees[i].isEmpty==OCUPADO)
            {
                if(order==1){
                    if(employees[i].sector>employees[j].sector)
                    {
                        burbujeo(employees,len,i,j);
                    }else
                    {
                        if((employees[i].sector==employees[j].sector)&&(stricmp(employees[i].lastName,employees[j].lastName)>0))
                        {
                            burbujeo(employees,len,i,j);
                        }
                    }

                }else if(order==2)
                {
                   if(employees[i].sector<employees[j].sector)
                    {
                        burbujeo(employees,len,i,j);
                    }else
                    {
                        if((employees[i].sector==employees[j].sector)&&(stricmp(employees[i].lastName,employees[j].lastName)<0))
                        {
                            burbujeo(employees,len,i,j);
                        }
                    }

                }
            }
        }
    }
    return ordenOk;
}

void burbujeo(Employee* employees, int length, int i, int j){

    Employee auxEmp;

    auxEmp=employees[i];
    employees[i]=employees[j];
    employees[j]=auxEmp;
}

int printEmployees(Employee* employees, int len, Sector* sectores, int tamSec){
    system("cls");
    printf("Empleados ACTIVOS en sistema\n\n");
    printf("%8s %12s %12s %12s %12s\n", "Sector", "Legajo", "Apellido", "Nombre", "Sueldo");
    printf("%8s %12s %12s %12s %12s\n", "------", "------", "--------", "------", "------");

    for(int i=0;i<len;i++){
        if(employees[i].isEmpty==OCUPADO){
            mostrarEmpleado(employees[i],sectores,tamSec);
        }
    }
    return 0;
}

int mostrarEmpleado(Employee employee, Sector* sectores, int tamSec){
    int indice;

    indice=traerDescSector(employee.sector,sectores,tamSec);

    printf("%8s %12d %12s %12s %12.2f\n", sectores[indice].description, employee.id, employee.lastName, employee.name, employee.salary);

    return 0;
}

int elegirSector(int* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite, Sector* sectores, int tamSec){
    int todoOk=0;
    int esEntero=0;
    int nroValido=0;
    char auxNum[10]={'0'};

    system("cls");
    mostrarSectores(sectores,tamSec);
    printf("\n%s : ", mensaje);
    scanf("%s", auxNum);
    esEntero=isInteger(auxNum);

    if(esEntero){
        nroValido=atoi(auxNum);

        if(nroValido<minLimite || nroValido>maxLimite){

            printf("%s : ", mensajeError);
            scanf("%s", auxNum);
            todoOk=-1;
        }else{
            *input=nroValido;
            todoOk=1;
        }
    }else{
        printf("ERROR. Ingrese solo NUMEROS\n");
        todoOk=-1;
    }
    return todoOk;
}

int traerDescSector(int idEmpleado, Sector* sectores, int tamSec){
    int indice=-1;

    for(int i=0;i<tamSec;i++){
        if(idEmpleado==sectores[i].id){
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarSectores(Sector* sectores, int tamSec){
    system("cls");
    printf("SECTORES\n\n");
    for(int i=0;i<tamSec;i++){
        if(sectores[i].id>0){
            printf("%d %4s\n",sectores[i].id, sectores[i].description);
        }
    }
}

int menuInformes(){
    int opcion;

    system("cls");
    printf("*** MENU INFORMES *** \n\n");
    printf("1- Listado de empleados ordenados alfabeticamente Sector/Apellido\n");
    printf("2- Total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int informes(Employee* employees, int tamEmp, Sector* sectores, int tamSec){

    int validacion=0;

    switch(menuInformes()){
        case 1:
            menuOrdenar(employees,tamEmp);
            printf("EMPLEADOS ORDENADOS ALFABETICAMENTE\n\n");
            printEmployees(employees,tamEmp,sectores,tamSec);
            break;
        case 2:
            informesSalary(employees,tamEmp);
            break;
        default:
            printf("Opcion no valida");
            system("pause");
            validacion=-1;
            break;
    }
    return validacion;
}

void informesSalary(Employee* employees, int tamEmp){

float promedioSueldos=0;
float acumuladorSueldos=0;
int contadorSuperaPromedio=0;
int contEmpleados=0;

    for(int i=0;i<tamEmp;i++){
        if(employees[i].isEmpty==OCUPADO){
           acumuladorSueldos+=employees[i].salary;
            contEmpleados++;
        }
    }

    promedioSueldos=acumuladorSueldos/contEmpleados;

    for(int i=0;i<tamEmp;i++){
        if(employees[i].isEmpty==OCUPADO){
            if(employees[i].salary>promedioSueldos){
                contadorSuperaPromedio++;
            }
        }
    }

    system("cls");
    printf("INFORME\n\n");
    printf("TOTAL de salarios: %.2f\n\n",acumuladorSueldos);
    printf("PROMEDIO de salarios: %.2f\n\n",promedioSueldos);
    printf("Cantidad de empleados que superan promedio: %d\n\n",contadorSuperaPromedio);
}
