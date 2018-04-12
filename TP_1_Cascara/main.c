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
                system("cls");
                printf("\n\nIngrese numero:");
                scanf("%f",&A);
                break;
            case 2:
                system("cls");
                printf("\n\nIngrese numero:");
                scanf("%f",&B);
                break;
            case 3:
                system("cls");
                resultado=suma(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 4:
                system("cls");
                resultado=resta(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 5:
                system("cls");
                resultado=division(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 6:
                system("cls");
                resultado=multiplicacion(A,B);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 7:
                system("cls");
                resultado=factorial(A);
                printf("\n\nEl resultado es: %.2f \n\n",resultado);
                break;
            case 8:
                system("cls");
                todasLasOperaciones(A,B);
                break;
            case 9:
                system("cls");
                seguir = 'n';
                break;
        }

    }


        return 0;
}


