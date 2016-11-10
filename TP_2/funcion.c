#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"

#define R 20



int menu()
{
    int opcion=0;
    system("cls");
    printf("***Menu de opciones***\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    printf("\nElija la opcion: ");
    scanf("%d",&opcion);
    return opcion;
}


void mostrarPersona(ePersona unaPersona)
{
    printf("%10ld  %10s    %4d   \n",unaPersona.dni, unaPersona.nombre, unaPersona.edad);
}


void mostrarPersonas(ePersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1)
        {
            mostrarPersona(personas[i]);
        }
    }
}


void inicializarPersonas(ePersona personas[], int tam)
{
     int i;
     for(i=0; i<tam; i++)
     {
       personas[i].estado = 0;
     }

}


int buscarLibre(ePersona personas[], int tam)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].estado ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPersona(ePersona personas[], int tam, int dni)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void altaPersona(ePersona personas[], int tam)
{
    int indice;
    long int dni;
    int esta;

    indice = buscarLibre(personas, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        scanf("%ld", &dni);

        esta = buscarPersona(personas, tam, dni);

        if(esta)
        {
            personas[indice].dni = dni;

            printf("\nIngrese el nombre completo: ");
            fflush(stdin);
            gets(personas[indice].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &personas[indice].edad);

            personas[indice].estado = 1;

            printf("\nPersona agregada con exito!!!\n\n");
        }
        else
        {
            printf("\nLa persona ya esta en el sistema\n");
        }

    }
}


void bajaPersona(ePersona persona[], int tam)
{



    int indice;
    int dni;
    char baja;

    printf("\nIngrese DNI: ");
    scanf("%ld", &dni);

    indice = buscarPersona(persona, tam, dni);

    if(indice == -1)
    {
        printf("\nLa persona de indice %ld no se encuentra en el sistema\n\n", dni);
    }
    else
    {
        printf("\nDatos de la persona\n\n");
        printf(" Documento  Nombre y Apellido   Edad \n\n");
        mostrarPersona(persona[indice]);

        printf("\n\nConfirma la baja de la persona? Si(s) / No(n): ");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            persona[indice].estado = 2;
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada por el usuario\n\n");
        }
    }
}

void ordenarPersona(ePersona persona[], int tam)
{
    int i;
    int j;
    for(i=0; i<R-1; i++)
    {
        for(j=i+1; j<R; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)==1)
            {
            ePersona auxiliar=persona[i];
            persona[i]=persona[j];
            persona[j]=auxiliar;
            }
        }
    }
        printf(" Documento  Nombre y Apellido   Edad \n\n");
        mostrarPersonas(persona, tam);
}




void mostrarGrafico(ePersona personas[], int tam)
{
    int i, j;
    int ninios=0;
    int jovenes=0;
    int adultos=0;
    int mayor=0;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado)
        {
            if(personas[i].edad<=18)
            {
                ninios++;
            }
            else if(personas[i].edad>=19 && personas[i].edad<=35)
            {
                jovenes++;
            }
            else if(personas[i].edad>35)
            {
                    adultos++;
            }
        }
    }

    if(ninios>jovenes)
    {
        if(ninios>adultos)
        {
            mayor=ninios;
        }
    }
    else
    {
        if(jovenes>=adultos)
        {
            mayor=jovenes;
        }
        else
        {
            mayor=adultos;
        }
    }


    char MZ[mayor][3];

    for(i=0; i<mayor; i++)
    {
        for(j=0; j<3; j++)
        {
            switch(j)
            {
            case 0:
                if(ninios>i)
                {
                    MZ[i][j]='*';
                }
                else
                {
                    MZ[i][j]=' ';
                }
                break;
            case 1:
                if(jovenes>i)
                {
                    MZ[i][j]='*';
                }
                else
                {
                    MZ[i][j]=' ';
                }
                break;
            case 2:
                if(adultos>i)
                {
                    MZ[i][j]='*';
                }
                else
                {
                    MZ[i][j]=' ';
                }
                break;
            }
        }
    }

    for(i=mayor-1; i>=0; i--)
    {
        printf("%c      %c      %c      \n",MZ[i][0],MZ[i][1],MZ[i][2]);
    }

    printf("\n<18  18-35  >35\n\n");
}
