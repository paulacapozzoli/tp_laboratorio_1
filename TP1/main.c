/*************************************
*
* Programa: Calculadora TP1
*
* Objetivo: Ingresar dos operandos para calcular suma, resta,
*           division, multiplicacion y factorial, e informar
*           resultados.
*
* Version: 0.1 del 12 de abril de 2020
* Autora:
*
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int menu, x, y, suma, resta, producto, factorial1, factorial2,flag1=0,flag2=0,flag3=0,flag4=0;
    float cociente;
    char continuar ='s';//para control de iteraciones

    do
    {
        system("cls");//limpia consola
        printf("*****MENU*****\n\n");

        //reemplaza la x en el menu
        if(flag1==1){
                printf("1. Ingresar 1er operando (A=%d)\n\n",x);
        }
        //no reemplaza la x
        else{
            printf("1. Ingresar 1er operando (A=x)\n\n");
        }

        //reemplaza la y en el menu
        if(flag2==1){
                printf("2. Ingresar 2do operando (B=%d)\n\n",y);
        }
        //no reemplaza la y
        else{
            printf("2. Ingresar 2do operando (B=y)\n\n");
        }

        printf("3. Calcular todas las operaciones\n");
        printf("    a. Calcular la suma (A+B)\n");
        printf("    b. Calcular la resta (A-B)\n");
        printf("    c. Calcular la division (A/B)\n");
        printf("    d. Calcular la multiplicacion (A*B)\n");
        printf("    e. Calcular el factorial (A!) y (B!)\n\n");

        printf("4. Informar resultados\n\n");

        //no muestra el resultado hasta que el usuario ingrese al menu 4
        switch(flag4){
            case 0:
                printf("    a) El resultado de A+B es: r\n\n");
                printf("    b) El resultado de A-B es: r\n\n");
                printf("    c) El resultado de A/B es: r\n\n");
                printf("    d) El resultado de A*B es: r\n\n");
                printf("    e) El factorial de A es: r1 y el factorial de B es: r2\n\n");
                break;

            case 1:
                printf("    a) El resultado de A+B es: %d\n\n",suma);
                printf("    b) El resultado de A-B es: %d\n\n",resta);
                if(y==0){
                    //indica que no es posible dividir en caso de ingresar 0 como 2do operando
                    printf("    c) ERROR, no es posible dividir por %d\n\n",y);
                }
                else{
                    printf("    c) El resultado de A/B es: %.2f\n\n",cociente);
                }
                printf("    d) El resultado de A*B es: %d\n\n",producto);
                if(x < 1&&y < 1){
                    //indica ERROR si el usuario ingreso un nro menor a 1 en 1er y/o 2do operando
                    printf("    e) ERROR, no es posible calcular A! o B!\n\n");
                }
                else{
                    if(x < 1&&y>0){
                        factorial2 = factorial(y);
                        printf("    e) No es posible calcular A! y el factorial de B es: %d",factorial2);
                    }
                    else{
                        if(x > 0&&y < 1){
                            factorial1 = factorial(x);
                            printf("    e) El factorial de A es: %d y no es posible calcular B!\n\n",factorial1);
                        }
                        else{
                            factorial1 = factorial(x);
                            factorial2 = factorial(y);
                            printf("    e) El factorial de A es: %d y el factorial de B es: %d\n\n",factorial1,factorial2);
                        }
                    }
                }
                break;
        }
        printf("5. Salir\n\n");

        printf("Ingrese al menu nro: ");
        //captura el nro ingresado para validar en los cases de switch de menu
        scanf("%d",&menu);

        switch(menu)
        {
            case 1:
                printf("Ingresar 1er operando (A=x)\n");
                scanf("%d",&x);

                //valida 1er operando
                flag1=1;
                if(flag2==1){
                    //si el 2do operando fue ingresado, se habilitan las operaciones
                    flag3=1;
                }
                break;
            case 2:
                printf("Ingresar 2do operando (B=y)\n");
                scanf("%d",&y);

                //valida 2do operando
                flag2=1;
                if(flag1==1){
                    //si el 1er operando fue ingresado, se habilitan las operaciones
                    flag3=1;
                }
                break;
            case 3:
                //no realiza las operaciones si no se cargaron los operandos
                if(flag1 == 0&&flag2 == 0){
                    printf("ERROR, debe ingresar los operandos\n");
                    system("pause");
                }
                //no realiza las operaciones si no se cargo el 1er operando
                if(flag1 == 0){
                    printf("ERROR, debe ingresar el 1er operando\n");
                    system("pause");
                }
                else{
                    //no realiza las operaciones si no se cargo el 2do operando
                    if(flag2 == 0){
                        printf("ERROR, debe ingresar el 2do operando\n");
                        system("pause");
                    }
                }
                //LLAMADO DE FUNCIONES

                //Calcula suma de enteros x e y; retorna el resultado como entero
                suma = sumar(x,y);

                //Calcula resta de enteros x e y; retorna el resultado como entero
                resta = restar (x, y);

                //Calcula cociente de enteros x e y; retorna el resultado como flotante
                cociente = dividir (x, y);

                //Calcula producto de enteros x e y; retorna el resultado como entero
                producto = multiplicar (x, y);

                //valida para mostrar los resultados en el menu 4
                flag3=2;
                break;
            case 4:
                //no muestra resultados si no se validaron en el menu 3
                if (flag3 != 2){
                    printf("No es posible mostrar resultados sin hacer las operaciones primero\n");
                    system("pause");
                }
                else{
                    flag4 = 1;
                }
                break;
            case 5:
                //se cierra la aplicacion y se interrumpe la iteracion
                continuar='n';
                break;
            default:
                //valida que el usuario ingrese un nro del 1 al 5 del menu
                printf("ERROR, ingrese un numero de menu del 1 al 5\n");
                system("pause");
                break;
        }
    }
    while(continuar=='s');

    return 0;
}
