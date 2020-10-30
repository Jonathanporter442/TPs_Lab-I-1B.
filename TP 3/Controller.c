#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pedirDato.h"
#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(path,"r");
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        vacio=ll_isEmpty(pArrayListEmployee);
        if(vacio==1)
        {
            retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }

    }
    fclose(pFile);
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(path,"rb");
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        vacio=ll_isEmpty(pArrayListEmployee);
        if(vacio==1)
        {
            retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }

    }
    fclose(pFile);
    return retorno;
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[50];
    int id;
    int horasTrabajadas;
    int sueldo;
    char respuesta;
    int retorno=-1;
    Employee* empleado;
    empleado=employee_new();
   /* int contador;
    contador=ll_len(pArrayListEmployee);
    printf("%d",contador);*/

    if(pArrayListEmployee!=NULL)
    {
        id=buscarMayorId(pArrayListEmployee);
        employee_setId(empleado,id);
        guardarCadenaSoloLetras(nombre,"Ingrese un nombre: ","Error al ingresar el nombre. ",50);
        employee_setNombre(empleado,nombre);

        guardarNumero(&horasTrabajadas,"\nIngrese la cantidad de horas trabajadas: ","Error al ingresar la cantidad de horas trabajas. ",0,300);
        employee_setHorasTrabajadas(empleado,horasTrabajadas);
        guardarNumero(&sueldo,"\ningrese un sueldo. ","Error al ingresar el sueldo. ",0,100000);
        employee_setSueldo(empleado,sueldo);
        guardarChar(&respuesta,"\nIngrese 's' para confirmar o 'n' para cancelar: ","Error al ingresar la confirmacion. ",1);
        if(respuesta=='s' || respuesta=='S')
        {

            ll_add(pArrayListEmployee,empleado);
            retorno=1;
        }

    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[50];
    int idModificar;
    int horasTrabajadas;
    int sueldo;
    int retorno=-1;
    int opcion;
    char confirmar;
    int flag=0;

    Employee* empleado;
    Employee* auxEmpleado;
    empleado=employee_new();
    if(pArrayListEmployee!=NULL)
    {

        controller_ListEmployee(pArrayListEmployee);
        guardarNumero(&idModificar,"Ingrese el id del empleado que desea modificar: ","Error al ingresar el id del empleado. ",0,99999);
        empleado=(Employee*)buscarEmpleadoPorId1(pArrayListEmployee,idModificar);

        if(empleado!=NULL)
        {
            auxEmpleado=empleado;
            do
            {
                printf("______MODICAR EMPLEADO______\n");
                mostrarUnEmpleado(empleado);
                printf("\n1. Nombre\n2. Horas de trabajo\n3. salario\n4. Salir\nElija una opcion: ");
                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                {
                    guardarCadenaSoloLetras(nombre,"Ingrese un nuevo nombre: ","Error al ingresar el nombre. ",50);
                    employee_setNombre(auxEmpleado,nombre);
                    flag=1;
                    break;
                }
                case 2:
                {
                    guardarNumero(&horasTrabajadas,"\nIngrese la nueva cantidad de horas trabajadas: ","Error al ingresar la cantidad de horas trabajas. ",0,300);
                    employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
                    flag=1;

                    break;
                }
                case 3:
                {
                    guardarNumero(&sueldo,"\ningrese el nuevo sueldo. ","Error al ingresar el sueldo. ",0,100000);
                    employee_setSueldo(auxEmpleado,sueldo);
                    flag=1;

                    break;
                }
                case 4:
                {
                    printf("Usted esta saliendo");
                    break;
                }
                }
            }
            while(opcion!=4);
            if(flag==1)
            {
                guardarChar(&confirmar,"Desea guardar los cambios (s/n)?: ","Error ingrese 's' o 'n'. ",1);
                if(confirmar=='s' || confirmar =='S')
                {

                    empleado=auxEmpleado;
                    retorno=1;
                }
                else
                {
                    retorno=2;
                }
            }

        }




    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int idBorrar;
    char respuesta;
    int index;
    Employee* empleado=NULL;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        guardarNumero(&idBorrar,"Ingrese el id del empleado que desea dar de baja: ","Error al ingresar el id. ",0,9999);
        empleado=(Employee*)buscarEmpleadoPorId1(pArrayListEmployee,idBorrar);
        index=ll_indexOf(pArrayListEmployee,empleado);
        if(empleado!=NULL)
        {
            mostrarUnEmpleado(empleado);
            pedirCadena(&respuesta,"Se eliminara ese empleado, desea confirmar?");
            if(respuesta=='s' || respuesta=='S')
            {

                ll_remove(pArrayListEmployee,index);
                employee_delete(empleado);
                retorno=1;
            }
            else
            {
                retorno=2;
            }

        }
    }


    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int cantidad;
    Employee* empleado;
    cantidad=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        retorno=1;
        printf("%4s%15s%20s%8s\n","Id","Nombre","HorasTrabajadas","Sueldo");

        for(i=0; i<cantidad; i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            mostrarUnEmpleado(empleado);

        }
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
        {
            do{
    guardarNumero(&opcion,"Ingrese una opcion\n1. Ordenar por id(mayor a menor)\n2. Ordenar por id(menor a mayor)\n3. Ordenar por nombre(a-z)\n4. Ordenar por nombre(z-a)\n5. Salir\nElija una opcion: ","Error. ",0,5);
        switch(opcion)
        {
        case 1:
            {
                printf("Ordenando espere un momento\n");
                ll_sort(pArrayListEmployee,employee_CompareById,0);//0 de mayor a menor y 1 de menor a mayor
                printf("Se ordeno con exito\n");
                break;
            }
        case 2:
            {
                                printf("Ordenando espere un momento\n");

                ll_sort(pArrayListEmployee,employee_CompareById,1);
                printf("Se ordeno con exito\n");
                break;
            }
        case 3:
            {
                                printf("Ordenando espere un momento\n");

                    ll_sort(pArrayListEmployee,employee_CompareByName,1);//1 ordena de a-z y 0 de z-a
                    printf("Se ordeno con exito\n");
                    break;

            }
        case 4:
            {
                                printf("Ordenando espere un momento\n");

                    ll_sort(pArrayListEmployee,employee_CompareByName,0);//1 ordena de a-z y 0 de z-a
                    printf("Se ordeno con exito\n");
                    break;

            }
        case 5:
            {
                printf("saliendo");
            }
        }
    }while(opcion!=5);
    retorno=1;
        }


    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFIle;
    pFIle=fopen(path,"w");
    int cantidad;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[50];
    int retorno=-1;
    Employee* empleado;
    if(pFIle!=NULL && pArrayListEmployee!=NULL)
    {
        cantidad=ll_len(pArrayListEmployee);
        fprintf(pFIle,"%s, %s, %s, %s\n","ID","NOMBRE","HORAS TABAJADAS","SUELDO");
        for(i=0;i<cantidad;i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&id);
            employee_getNombre(empleado,nombre);
            employee_getSueldo(empleado,&sueldo);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);
            fprintf(pFIle,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        }
        retorno=1;
    }
    fclose(pFIle);

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile=fopen(path,"wb");
    Employee* empleado;
    int cantidad;
    int retorno=-1;
    int i;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        cantidad=ll_len(pArrayListEmployee);
        for(i=0;i<cantidad;i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            fwrite(empleado,sizeof(Employee),1,pFile);

        }
        retorno=1;
    }
    fclose(pFile);
    return retorno;
}

int buscarMayorId(LinkedList* pArrayListEmployee)
{
    int idMayor;
    int largo;
   // int i;
   // int flag=0;
   // Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        largo=ll_len(pArrayListEmployee);

        idMayor=largo;
    }


    return idMayor+1;
}
void* buscarEmpleadoPorId1(LinkedList* pArrayListEmployee,int idEmpleado )
{
    Employee* empleado=NULL;
    int i;
    int cantidad;
    cantidad=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {

        for(i=0; i<cantidad; i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            if(idEmpleado == empleado->id)
            {

                return empleado;
            }
        }
    }
    return empleado;
}
