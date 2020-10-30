#include <stdio.h>
#include <stdlib.h>
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
    int opcion;
    int flagCargar1=0;
    int flagCargar2=0;
    int flagEmpleado=0;
    LinkedList* pArrayListEmployee;
    pArrayListEmployee=ll_newLinkedList();
      do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");

        scanf("%d",&opcion);



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                if(controller_loadFromText("data.csv",pArrayListEmployee)==1)
                {
                   printf("se cargo correctamente.\n");
                   flagCargar1=1;
                }
                else
                {
                    printf("no se cargo correctamente.\n");

                }
                break;
            }
            case 2:
            {
                if(controller_loadFromBinary("data.bin",pArrayListEmployee)==1)
                {
                   printf("se cargo correctamente.\n");
                   flagCargar2=1;
                }
                else
                {
                    printf("no se cargo correctamente.\n");

                }
                break;
            }
            case 3:
            {

                if(controller_addEmployee(pArrayListEmployee)==1)
                {
                    if(printf("Se cargo con exito.\n")==1)

                    flagEmpleado=1;
                }
                else
                {
                    printf("Carga cancelada.\n");
                }
                break;
            }
            case 4:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {
                  if(controller_editEmployee(pArrayListEmployee)==1)
                  {
                    printf("Se modifico correctamente");
                  }
                  else
                  {
                      printf("\nNo se pudo modificar\n");
                  }

                }
                else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }

                break;
            }
            case 5:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {

                  if(controller_removeEmployee(pArrayListEmployee)==1)
                  {
                      printf("\nSe dio de baja el empleado correctamente\n");
                  }
                  else
                  {
                      printf("\nNo de dio de baja correctamente\n");
                  }
                }
                 else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }

                break;
            }
            case 6:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {
                   controller_ListEmployee(pArrayListEmployee);

                }
                else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }

                break;
            }
            case 7:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {
                   controller_sortEmployee(pArrayListEmployee);
                }
                 else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }
                break;
            }
            case 8:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {
                   controller_saveAsText("data.csv",pArrayListEmployee);
                }
                 else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }
                break;
            }
            case 9:
            {
                if(flagCargar1==1 || flagCargar2==1 || flagEmpleado==1)
                {
                    controller_saveAsBinary("data.bin",pArrayListEmployee);
                }
                else
                {
                    printf("\nDebe cargar almenos un empleado\n");
                }
                break;
            }

            case 10:
                {
                    printf("Usted esta saliendo\n");

                }
            default:
            {
                printf("No ingreso una opcion valida. Intento de nuevo\n");
                break;
            }

        }
        system("pause");
        system("cls");
    }while(opcion!=10);
}


