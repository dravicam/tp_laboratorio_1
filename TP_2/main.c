#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"

#define R 20





int main()
{
    ePersona Persona[R];

    char seguir='s';
    int opcion=0;
    inicializarPersonas(Persona, R);

    while(seguir=='s')
    {
        switch(menu())
        {
            case 1:
                altaPersona(Persona, R);
                break;

            case 2:
                bajaPersona(Persona, R);
                break;

            case 3:
                ordenarPersona(Persona, R);
                break;

            case 4:
                mostrarGrafico(Persona, R);
                break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("Elija una opcion entre el 1-5");
        }
        system("pause");
    }

    return 0;
}





