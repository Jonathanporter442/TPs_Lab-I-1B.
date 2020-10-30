#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    char id[40];
    char nombre[40];
    char sueldo[40];
    char horasTrabajadas[40];
    int retorno=0;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
        {
            empleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListEmployee,empleado);
                            retorno=1;

        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    }

    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=0;
    int cantidad;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        retorno=1;

    do
    {

            empleado=employee_new();
            cantidad=fread(empleado,sizeof(Employee),1,pFile);
            if(cantidad!=1)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
                    break;
                }

            }
            ll_add(pArrayListEmployee,empleado);

            /*if(cantidad==1)
            {

            }*/



    }while(!feof(pFile));

    }

    return retorno;

}
