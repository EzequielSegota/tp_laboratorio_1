#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float A, float B)
{
    float s;

    s = A + B;

    return (s);
}

float resta(float A, float B)
{
    float r;

    r = A - B;

    return (r);
}


float division(float A, float B)
{
    float d;

    while(B==0)
    {
        printf("\n\nIngrese un valor distinto de 0 para el divisor:\n\n");
        scanf("%f",&B);
    }
    d = A / B;


    return d;
}


float multiplicacion(float A, float B)
{
    float m;

    m= A*B;

    return m;
}


float factorial(float A)
{
    int X;
    float Y;
    int f;

    X=A;
    Y=A;

    Y=Y-X;

    while(Y>0 || A<0)
    {
        printf("\n\nError, no se puede factorear un numero decimal o negativo, ingrese nuevo numero:");
        scanf("%f",&A);
    }
    if(A==0)
    {
        f=1;
    }
    else
    {
        f=A*factorial(A-1);
    }

    return f;
}


