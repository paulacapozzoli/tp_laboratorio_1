#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validarCampos.h"
#include "LinkedList.h"


Employee* employee_new(){
    Employee* nuevoEmployee;
    nuevoEmployee= (Employee*)malloc(sizeof(Employee));

    return nuevoEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* nuevoEmployee;
    nuevoEmployee=employee_new();

    if(nuevoEmployee!=NULL)
    {
        if(employee_setId(nuevoEmployee,atoi(idStr))
         ||employee_setNombre(nuevoEmployee,nombreStr)
         ||employee_setHorasTrabajadas(nuevoEmployee,atoi(horasTrabajadasStr))
         ||employee_setSueldo(nuevoEmployee,atoi(sueldoStr))){

            free(nuevoEmployee);
            nuevoEmployee=NULL;
        }
    }
    return nuevoEmployee;
}

int mostrarEmployees(LinkedList* lista){
    int todoOk=0;
    int flag=0;
    int tamEmp=ll_len(lista);
    Employee* auxEmpleado;

    if(lista!=NULL){
        todoOk=1;
        printf("****Empleados cargados en sistema***\n\n");
        printf("%5s %20s %13s %7s\n", "Id", "Nombre", "Hs Trabajadas", "Sueldo");
        printf("%5s %20s %13s %7s\n", "--", "------", "-------------", "------");
        for(int i=0;i<tamEmp;i++){
            auxEmpleado=(Employee*)ll_get(lista,i);
            if( auxEmpleado!=NULL){
                mostrarEmployeeP(auxEmpleado);
                flag=1;
            }
        }
        if(flag==0){
            printf("No hay empleados\n");
        }
        printf("\n\n");
    }
    return todoOk;
}

int mostrarEmployeeP(Employee* empleado){
    int todoOk=0;
    if (empleado!=NULL){
        printf("%5d %20s %13d %7d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        todoOk=1;
    }
    return todoOk;
}

int employee_setId(Employee* this,int id){
    int error=1;
    if(this!=NULL&&id>0){
        this->id=id;
        error=0;
    }
    return error;
}

int employee_getId(Employee* this,int* id){
    int error=1;
    if(this!=NULL&&id!=NULL){
        *id=this->id;
        error=0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre){
    int error=1;
    if(this!=NULL&&nombre!=NULL&&strlen(nombre)>=3&&strlen(nombre)<128){
        strcpy(this->nombre,nombre);
        error=0;
    }
    return error;
}

int employee_getNombre(Employee* this,char* nombre){
    int error=1;
    if(this!=NULL&&nombre!=NULL){
        strcpy(nombre,this->nombre);
        error=0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int error=1;
    if(this!=NULL&&horasTrabajadas>0&&horasTrabajadas<700){
        this->horasTrabajadas=horasTrabajadas;
        error=0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int error=1;
    if(this!=NULL&&horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        error=0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo){
    int error=1;
    if(this!=NULL&&sueldo>9999&&sueldo<100000){
        this->sueldo=sueldo;
        error=0;
    }
    return error;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int error=1;
    if(this!=NULL&&sueldo!=NULL){
        *sueldo=this->sueldo;
        error=0;
    }
    return error;
}

int menuSortEmple()
{
    int opcion;
    system("cls");

    printf("********** ORDENAR *************\n\n");
    printf("1. Ordenar por Id\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por Horas Trabajadas\n");
    printf("4. Ordenar por sueldo\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int compararEmpleadosId(void* emp1,void* emp2){
    int rta;
    if(emp1!=NULL&&emp2!=NULL){
        Employee* a=(Employee*) emp1;
        Employee* b=(Employee*) emp2;

        if(a->id==b->id){
            rta=0;
        }
        else if (a->id>b->id){
            rta=-1;
        }
        else{
            rta=1;
        }
    }
    return rta;
}

int menuSortId(LinkedList* lista){
    int order;

    system("cls");
    printf("Ordenar Ascendente o Descendente\n");
    printf("0- Ascendente\n");
    printf("1- Descendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    ll_sort(lista,compararEmpleadosId,order);
    return 0;
}

int compararEmpleadosNombre(void* emp1, void* emp2){
    int rta;
    if(emp1!=NULL&&emp2!=NULL){
        Employee* a=(Employee*) emp1;
        Employee* b=(Employee*) emp2;

        if(strcmp(a->nombre,b->nombre)==0){
            rta=0;
        }
        else if (strcmp(a->nombre,b->nombre)==-1){
            rta=-1;
        }
        else{
            rta=1;
        }
    }
    return rta;
}

int menuSortNombre(LinkedList* lista){
    int order;
    system("cls");
    printf("Ordenar Ascendente o Descendente\n");
    printf("0- Ascendente\n");
    printf("1- Descendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    ll_sort(lista,compararEmpleadosNombre,order);
    return 0;
}

int compararEmpleadosHoras(void* emp1, void* emp2){
    int rta;
    if(emp1!=NULL&&emp2!=NULL){
        Employee* a=(Employee*) emp1;
        Employee* b=(Employee*) emp2;

        if(a->horasTrabajadas==b->horasTrabajadas){
            rta=0;
        }
        else if (a->horasTrabajadas>b->horasTrabajadas){
            rta=-1;
        }
        else{
            rta=1;
        }
    }
    return rta;
}

int menuSortHoras(LinkedList* lista){
    int order;

    system("cls");
    printf("Ordenar Ascendente o Descendente\n");
    printf("0- Descendente\n");
    printf("1- Ascendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    ll_sort(lista,compararEmpleadosHoras,order);
    return 0;
}

int compararEmpleadosSueldo(void* emp1,void* emp2){
    int rta;
    if(emp1!=NULL&&emp2!=NULL){
        Employee* a=(Employee*) emp1;
        Employee* b=(Employee*) emp2;

        if(a->sueldo==b->sueldo){
            rta=0;
        }
        else if (a->sueldo>b->sueldo){
            rta=-1;
        }
        else{
            rta=1;
        }
    }
    return rta;
}

int menuSortSueldo(LinkedList* lista){
    int order;

    system("cls");
    printf("Ordenar Ascendente o Descendente\n");
    printf("0- Ascendente\n");
    printf("1- Descendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    ll_sort(lista,compararEmpleadosSueldo,order);
    return 0;
}

int menuPrincipal()
{
    int opcion;
    system("cls");

    printf("********** MENU *************\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarEmpleadoId(LinkedList* lista,int idEmp){
    int index=-1;
    int flag=0;
    int tamEmp=ll_len(lista);
    Employee* auxEmp;

    if(lista!=NULL){
        for(int i=0;i<tamEmp;i++){
            auxEmp=(Employee*)ll_get(lista,i);
            if(auxEmp!=NULL){
                flag=1;
                if(auxEmp->id==idEmp){
                    mostrarEmployeeP(auxEmp);
                    index=i;
                }
            }
        }
        if(flag==0){
            printf("No hay empleados\n");
        }
        printf("\n\n");
    }
    return index;
}

int menuEditEmployee()
{
    int opcion;
    system("cls");

    printf("********** MODIFICAR *************\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Horas Trabajadas\n");
    printf("3. Modificar Sueldo\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int editNombre(LinkedList* lista, int indice){
    int error=1;
    char nombre[128];
    int contIntentos=0;
    int validarNombre;
    char confirma;
    Employee* auxEmp;

    if(lista!=NULL){
        system("cls");
        auxEmp=(Employee*)ll_get(lista,indice);
        if(auxEmp!=NULL){
            do{
                validarNombre=getString(nombre,"Ingrese nombre de empleado","ERROR. Ingrese minimo 3 letras y maximo 127 letras\n",3,127);
                if(validarNombre==-1){
                    contIntentos++;
                    if(contIntentos>2){
                        break;
                    }
                }
            }while(validarNombre==-1);
            if(validarNombre!=1){
                mostrarEmployeeP(auxEmp);
                printf("Confirma nombre nuevo?\n");
                fflush(stdin);
                printf("Ingrese s/n: ");
                scanf("%c",&confirma);
                if(confirma=='s'){
                        if(employee_setNombre(auxEmp,nombre)!=1){
                            error=0;
                            printf("Se modifico el nombre del empleado\n\n");
                            system("pause");
                        }
                }else{
                    error=-1;
                }
            }else{
                printf("No se pudo validar el nombre nuevo\n\n");
            }
        }
    }
    return error;
}

int editHoras(LinkedList* lista, int indice){
    int error=1;
    int hsTrabajadas;
    int contIntentos=0;
    int validarHs;
    char confirma;
    Employee* auxEmp;

    if(lista!=NULL){
        system("cls");
        auxEmp=(Employee*)ll_get(lista,indice);
        if(auxEmp!=NULL){
            do{
                validarHs=getInt(&hsTrabajadas,"Ingrese horas mensuales trabajadas del empleado","ERROR. Rango de horas de 1 a 699\n",1,699);
                if(validarHs==-1){
                    contIntentos++;
                    if(contIntentos>2){
                        break;
                    }
                }
            }while(validarHs==-1);
            if(validarHs!=1){
                mostrarEmployeeP(auxEmp);
                printf("Confirma horas?\n");
                fflush(stdin);
                printf("Ingrese s/n: ");
                scanf("%c",&confirma);
                if(confirma=='s'){
                        if(employee_setHorasTrabajadas(auxEmp,hsTrabajadas)!=1){
                            error=0;
                            printf("Se modificaron las horas del empleado\n\n");
                            system("pause");
                        }
                }else{
                    error=-1;
                }
            }else{
                printf("No se pudieron validar las horas\n\n");
            }
        }
    }
    return error;
}

int editSueldo(LinkedList* lista, int indice){
    int error=1;
    int sueldo;
    int contIntentos=0;
    int validarSueldo;
    char confirma;
    Employee* auxEmp;

    if(lista!=NULL){
        system("cls");
        auxEmp=(Employee*)ll_get(lista,indice);
        if(auxEmp!=NULL){
            do{
                validarSueldo=getInt(&sueldo,"Ingrese sueldo mensual del empleado","ERROR. Rango de sueldo de 30000 a 100000\n",30000,100000);
                if(validarSueldo==-1){
                    contIntentos++;
                    if(contIntentos>2){
                        break;
                    }
                }
            }while(validarSueldo==-1);
            if(validarSueldo!=1){
                mostrarEmployeeP(auxEmp);
                printf("Confirma sueldo?\n");
                fflush(stdin);
                printf("Ingrese s/n: ");
                scanf("%c",&confirma);
                if(confirma=='s'){
                        if(employee_setSueldo(auxEmp,sueldo)!=1){
                            error=0;
                            printf("Se modifico el sueldo del empleado\n\n");
                            system("pause");
                        }
                }else{
                    error=-1;
                }
            }else{
                printf("No se pudieron validar las horas\n\n");
            }
        }
    }
    return error;
}
