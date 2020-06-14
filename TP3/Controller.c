#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validarCampos.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    char buffer[4][140];
    Employee* auxiliarEmp;
    int cantidad;
    FILE* data;

    if(path!=NULL&&pArrayListEmployee!=NULL){
        data=fopen(path,"r");
        if(data==NULL){
            printf("Problema para abrir el archivo\n");
            exit(EXIT_FAILURE);
            todoOK=1;
        }
        fscanf(data,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//lectura para saltear el encabezado del archivo

        while(!feof(data)){
            cantidad=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cantidad==4){
                auxiliarEmp=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,auxiliarEmp);
            }else{
                break;
            }
        }
        fclose(data);
    }
    return todoOK;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK= 0;
    char buffer[4][100];
    Employee* auxiliarEmp;
    int cantidad;
    FILE* data;

    if(path!=NULL&&pArrayListEmployee!=NULL){
        data=fopen(path,"rb");
        if(data==NULL){
            printf("Problema para abrir el archivo\n");
            exit(EXIT_FAILURE);
            todoOK=1;
        }
        fscanf(data,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(data)){
            cantidad=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cantidad==4){
                auxiliarEmp=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,auxiliarEmp);
            }else{
                break;
            }
        }
        fclose(data);
    }
    return todoOK;
}

static int conseguirId()
{
    static int id = 1000;
    id++;
    return id;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int id=conseguirId();
    char nombre[128];
    int hsTrabajadas;
    int sueldo;
    int contIntentos=0;
    int validarNombre;
    int validarHs;
    int validarSueldo;
    Employee* nuevoEmployee;

    nuevoEmployee=employee_new();

    if(nuevoEmployee!=NULL&&pArrayListEmployee!=NULL){
        do{
            validarNombre=getString(nombre,"Ingrese nombre de empleado","ERROR. Ingrese minimo 3 letras y maximo 127 letras\n",3,127);
            if(validarNombre==-1){
                contIntentos++;
                if(contIntentos>2){
                    break;
                }
            }
        }while(validarNombre==-1);
        if(validarNombre!=-1){
            contIntentos=0;
            do{
                validarHs=getInt(&hsTrabajadas,"Ingrese horas mensuales trabajadas del empleado","ERROR. Rango de horas de 1 a 699\n",1,699);
                if(validarHs==-1){
                    contIntentos++;
                    if(contIntentos>2){
                        break;
                    }
                }
            }while(validarHs==-1);
        }
        if(validarNombre!=-1&&validarHs!=-1){
            contIntentos=0;
            do{
                validarSueldo=getInt(&sueldo,"Ingrese sueldo mensual del empleado","ERROR. Rango de sueldo de 30000 a 100000\n",30000,100000);
                if(validarSueldo==-1){
                    contIntentos++;
                    if(contIntentos>2){
                        break;
                    }
                }
            }while(validarSueldo==-1);
        }
        if(validarNombre!=-1&&validarHs!=-1&&validarSueldo!=-1){

            if(employee_setId(nuevoEmployee,id)
             ||employee_setNombre(nuevoEmployee,nombre)
             ||employee_setHorasTrabajadas(nuevoEmployee,hsTrabajadas)
             ||employee_setSueldo(nuevoEmployee,sueldo)){

                 free(nuevoEmployee);
                 nuevoEmployee=NULL;
            }else{
                ll_add(pArrayListEmployee,nuevoEmployee);
                error=0;
                printf("Empleado dado de alta\n\n");
                system("pause");
            }
        }else{
            printf("No se pudo validar al empleado\n\n");
        }
    }
    return error;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int idEmple;
    int indice;

    system("cls");
    mostrarEmployees(pArrayListEmployee);
    printf("Ingrese el Id del empleado a modificar: ");
    scanf("%d",&idEmple);

    printf("****Empleado para modificar***\n\n");
    printf("%5s %20s %13s %7s\n", "Id", "Nombre", "Hs Trabajadas", "Sueldo");
    printf("%5s %20s %13s %7s\n", "--", "------", "-------------", "------");

    indice=buscarEmpleadoId(pArrayListEmployee,idEmple);

    if(indice==-1){
        printf("No se encontro el empleado con el id ingresado\n");
        system("pause");
    }else{
        switch(menuEditEmployee()){
            case 1:
                printf("1. Modificar Nombre\n");
                error=editNombre(pArrayListEmployee,indice);
                break;
            case 2:
                printf("2. Modificar Horas Trabajadas\n");
                error=editHoras(pArrayListEmployee,indice);
                break;
            case 3:
                printf("3. Modificar Sueldo\n");
                error=editSueldo(pArrayListEmployee,indice);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }
    return error;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int idEmple;
    int indice;
    char confirma;

    system("cls");
    mostrarEmployees(pArrayListEmployee);
    printf("Ingrese el Id del empleado a dar de baja: ");
    scanf("%d",&idEmple);

    printf("****Empleado para dar de baja***\n\n");
    printf("%5s %20s %13s %7s\n", "Id", "Nombre", "Hs Trabajadas", "Sueldo");
    printf("%5s %20s %13s %7s\n", "--", "------", "-------------", "------");

    indice=buscarEmpleadoId(pArrayListEmployee,idEmple);

    if(indice==-1){
        printf("No se encontro el empleado con el id ingresado\n");
        system("pause");
    }else{
        printf("Confirma baja?\n");
        fflush(stdin);
        printf("Ingrese s/n: ");
        scanf("%c",&confirma);
        if(confirma=='s'){
            ll_remove(pArrayListEmployee,indice);
            error=0;
            printf("\nEmpleado dado de baja con exito\n\n");
        }else{
            error=-1;
        }
    }
    return error;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(!mostrarEmployees(pArrayListEmployee)){
        printf("No hay empleados para mostrar");
    }else
    {
        error=0;
    }
    return error;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;

    if(pArrayListEmployee!=NULL){
        switch(menuSortEmple()){
            case 1:
                printf("1. Ordenar por Id\n");
                error=menuSortId(pArrayListEmployee);
                printf("Empleados ordenados por Id\n");
                mostrarEmployees(pArrayListEmployee);
                break;
            case 2:
                printf("2. Ordenar por Nombre\n");
                error=menuSortNombre(pArrayListEmployee);
                printf("Empleados ordenados por Nombre\n");
                mostrarEmployees(pArrayListEmployee);
                break;
            case 3:
                printf("3. Ordenar por Horas Trabajadas\n");
                error=menuSortHoras(pArrayListEmployee);
                printf("Empleados ordenados por Horas Trabajadas\n");
                mostrarEmployees(pArrayListEmployee);
                break;
            case 4:
                printf("4. Ordenar por sueldo\n");
                error=menuSortSueldo(pArrayListEmployee);
                printf("Empleados ordenados por Sueldo\n");
                mostrarEmployees(pArrayListEmployee);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }
    return error;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK= 0;
    int tamEmp=ll_len(pArrayListEmployee);
    Employee* auxEmpleado;

    FILE* data;

    if(path!=NULL&&pArrayListEmployee!=NULL){
        data=fopen(path,"w");
        if(data==NULL){
            printf("Problema para abrir el archivo\n");
            exit(EXIT_FAILURE);
            todoOK=1;
        }
        for(int i=0;i<tamEmp;i++){
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            if( auxEmpleado!=NULL){
               fprintf(data,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            }
        }

        fclose(data);
    }
    return todoOK;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK= 0;
    int tamEmp=ll_len(pArrayListEmployee);
    Employee* auxEmpleado;

    FILE* data;

    if(path!=NULL&&pArrayListEmployee!=NULL){
        data=fopen(path,"wb");
        if(data==NULL){
            printf("Problema para abrir el archivo\n");
            exit(EXIT_FAILURE);
            todoOK=1;
        }
        for(int i=0;i<tamEmp;i++){
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            if( auxEmpleado!=NULL){
               fwrite(&auxEmpleado,sizeof(Employee),1,data);
            }
        }
        fclose(data);
    }
    return todoOK;
}

