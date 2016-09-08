#include "funciones.h"


float sumar(float x, float y)
{
    float resultado;
    resultado = x + y;
    return resultado;
}

float restar(float x, float y)
{
    float resultado;
    resultado = x - y;
    return resultado;
}

float multiplicar(float x, float y)
{
    float resultado;
    resultado = x * y;
    return resultado;
}

float dividir(float x, float y)
{
    float resultado;
    resultado = x / y;
    return resultado;
}

float factorizar(float n)
{
    if(n==1)
    {
        return 1;
    }
    return n * factorizar(n-1);
}

