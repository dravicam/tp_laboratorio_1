#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float suma;
    float resta;
    float multiplico;
    float divido;

    float factorial;
    float factorial2;

    float dato1=0;
    float dato2=0;

    while(seguir=='s')
    {
        system("cls");

        printf("\n1- Ingresar 1er operando (A=%.2f)\n", dato1);
        printf("2- Ingresar 2do operando (B=%.2f)\n", dato2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la multiplicacion (A/B)\n");
        printf("6- Calcular la division (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nIngrese un numero: ");
                scanf("%f", &dato1);
                break;


            case 2:
                printf("\nIngrese otro numero: ");
                scanf("%f", &dato2);
                break;


            case 3:
                suma = sumar(dato1, dato2);
                printf("La suma es: %f\n", suma);
                break;


            case 4:
                resta = restar(dato1, dato2);
                printf("La resta es: %f\n", resta);
                break;


            case 5:
                multiplico = multiplicar(dato1, dato2);
                printf("La multiplicacion es: %f\n", multiplico);
                break;


            case 6:
                divido = dividir(dato1, dato2);
                printf("La division es: %f\n", divido);
                break;


            case 7:
                factorial = factorizar(dato1);
                printf("La factorizacion es: %f\n", factorial);
                factorial2 = factorizar(dato2);
                printf("La factorizacion es: %f\n", factorial2);
                break;


            case 8:
                suma = dato1 + dato2;
                resta = dato1 - dato2;
                multiplico = dato1 * dato2;
                divido = (float) dato1 / dato2;
                factorial = factorizar(dato1);
                factorial2 = factorizar(dato2);
                printf("La suma es: %.2f \nLa resta es: %.2f \nLa multiplicacion es: %.2f \nLa division es: %f\nLa factorizacion del dato A es: %.2f\nLa factorizacion del dato B es: %.2f\n", suma, resta, multiplico, divido, factorial, factorial2);
                break;


            case 9:
                seguir = 'n';
                break;

        }

        system("pause");
    }
    return 0;
}

/*ALUMNO: Matias Dravica
  CURSO: 1°A
*/


