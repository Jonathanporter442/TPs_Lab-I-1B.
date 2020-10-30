#include "pedirDato.h"
int pedirCadena(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarCadenaSoloLetras(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarCadenaSoloLetras(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarCadenaSoloLetras(char cadena[],char mensaje[],char mensajeError[],int tam)
{
    char aux[100];
    int retorno=1;
    while(pedirCadena(aux,mensaje)!=1 ||strlen(aux)>tam )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}

int pedirNumero(char texto[],int* numero)
{
    int retorno=0;
    char aux[100];
    printf("%s",texto);
    fflush(stdin);
   // scanf("%s",aux);
   gets(aux);
    if(validarNumero(aux)==1)
    {
        *numero=atoi(aux);
        retorno=1;
    }


    return retorno;
}
int validarNumero(char cadena[])
{
    int cantidad;
    int retorno=1;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0)
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') /*&& cadena[0]==""*/)
        {
            retorno=0;
            break;
        }
    }
    return retorno;

}
int guardarNumero(int* numero,char texto[],char textoError[],int min,int max)
{
    int aux;
    int retorno=1;
    while(pedirNumero(texto,&aux)!=1 || aux<min || aux>max)
    {

        fflush(stdin);
        printf("\n%s.",textoError);

    }
    *numero=aux;
    return retorno;
}

int pedirChar(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarChar(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarChar(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]!='s' &&  cadena[i]!='n') && (cadena[i]!='S' &&  cadena[i]!='N'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarChar(char cadena[],char mensaje[],char mensajeError[],int tam)
{
    char aux[100];
    int retorno=1;
    while(pedirChar(aux,mensaje)!=1 ||strlen(aux)>tam )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}
