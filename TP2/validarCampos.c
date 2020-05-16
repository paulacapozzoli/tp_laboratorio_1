#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validarCampos.h"

int getInt(int* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite){
    int todoOk=1;
    int esEntero=0;
    int nroValido=0;
    char auxNum[10]={'0'};

    printf("%s : ", mensaje);
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
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }

    return todoOk;
}

int isInteger(char auxNum[]){
   int i=0;
   int todoOk = 1;
   while(auxNum[i] != '\0'){
       if((atoi(auxNum))==0){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

int getFloat(float* input,char mensaje[],char mensajeError[], float minLimite, float maxLimite){
    int todoOk=1;
    int esFlotante=0;
    int nroValido=0;
    char auxNum[10]={'0'};

    printf("%s : ", mensaje);
    scanf("%s", auxNum);
    esFlotante=isFloat(auxNum);

    if(esFlotante){
        nroValido=atof(auxNum);
        if(nroValido<minLimite || nroValido>maxLimite){
            printf("%s : ", mensajeError);
            scanf("%s", auxNum);
            todoOk=-1;
        }else{
            *input=nroValido;
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }
    return todoOk;
}

int isFloat(char auxNum[]){
   int i=0;
   int todoOk = 1;
   int contDecim=0;

   while(auxNum[i] != '\0'){
       if(auxNum[i]<'0' || auxNum[i]>'9'){
           if(auxNum[i]=='.'){
               contDecim++;
           }
       }
       if((atof(auxNum))==0 || contDecim>1){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

int getChar(char* input,char mensaje[],char mensajeError[], char minLimite, char maxLimite){
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", input);
    *input=toupper(*input);

    while (*input>maxLimite || *input<minLimite){
        printf("Reingrese %s: ", mensajeError);
        fflush(stdin);
        scanf("%c", input);
        *input=toupper(*input);
    }

    return 1;
}

int validarSexo(char* input,char mensaje[],char mensajeError[]){

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", input);
    *input=toupper(*input);

    while (*input!='F' && *input!='M'){
        printf("%s: ", mensajeError);
        fflush(stdin);
        scanf("%c", input);
        *input=toupper(*input);
    }
    return 1;
}

int getString(char* input,char mensaje[],char mensajeError[], int minLimite, int maxLimite){
    char auxStr[100]={"0"};
    int tamStr=0;
    int todoOk=0;
    int esCaracter=0;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%s", auxStr);

    esCaracter=isChar(auxStr);

    if(esCaracter){
      tamStr=strlen(auxStr);
        if(tamStr>maxLimite || tamStr<minLimite){
            system("cls");
            printf("%s ", mensajeError);
            todoOk=-1;

        }else{
            auxStr[0]=toupper(auxStr[0]);
            strcpy(input,auxStr);
            todoOk=1;
        }
    }
    else{
        printf("Ingrese solo letras!\n");
        todoOk=-1;
    }
    return todoOk;
}

int isChar(char auxStr[]){
   int i=0;
   int todoOk = 1;
   while(auxStr[i] != '\0'){
       if((auxStr[i] < 'a' || auxStr[i] > 'z') && (auxStr[i] < 'A' || auxStr[i] > 'Z')){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}
