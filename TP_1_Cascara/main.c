#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float A;
    float B;
    float resultado;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\n\nIngrese numero:");
                scanf("%f",&A);
                break;
            case 2:
                printf("\n\nIngrese numero:");
                scanf("%f",&B);
                break;
            case 3:
                resultado=suma(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 4:
                resultado=resta(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 5:
                resultado=division(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 6:
                resultado=multiplicacion(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 7:
                resultado=factorial(A);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 8:

                break;
            case 9:
                seguir = 'n';
                break;
        }

    }


        return 0;
}
