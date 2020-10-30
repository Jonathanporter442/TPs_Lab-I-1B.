#include "Employee.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();
    if( !employee_setId(this,atoi(idStr)) &&
        !employee_setNombre(this,nombreStr) &&
        !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) &&
        !employee_setSueldo(this,atof(sueldoStr)))
    {
        return this;
    }
    employee_delete(this);
    return NULL;
}
void employee_delete(Employee* this)
{
    free(this);
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre!= NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre!= NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this != NULL && sueldo>-1)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
   int retorno=-1;
    if(this != NULL && *sueldo>-1)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;

}

int employee_setId(Employee* this,int id)
{
        int retorno=-1;
    if(this != NULL && id>-1)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
        int retorno=-1;
    if(this != NULL && *id>-1)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && horasTrabajadas>-1)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
        int retorno=-1;
    if(this != NULL && *horasTrabajdas>-1)
    {
        *horasTrabajdas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;

}


int employee_CompareByName(void* e1, void* e2)
{
     Employee* empleado1;
    Employee* empleado2;
    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;
    char nombre_1[50];
    char nombre_2[50];
    employee_getNombre(empleado1,nombre_1);
    employee_getNombre(empleado2,nombre_2);
    int comparacion;

        if(strcmp(nombre_1,nombre_2)>0)
        {
            comparacion=1;
        }
        else if(strcmp(nombre_1,nombre_2)<0)
        {
          comparacion =-1 ;
        }

    return comparacion;
}

int employee_CompareById(void* e1, void* e2)
{
    Employee* empleado1;
    Employee* empleado2;
    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;
    int id_1;
    int id_2;
    employee_getId(empleado1,&id_1);
    employee_getId(empleado2,&id_2);

    int comparacion;

        if(id_1 >id_2)
        {
            comparacion=1;
        }
        else if(id_1<id_2)
        {
          comparacion =-1 ;
        }



    return comparacion;

}
void mostrarUnEmpleado(Employee* empleado)
{
    if(empleado!=NULL)
    {
        printf("%4d%15s%15i%13i\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
    }
}



