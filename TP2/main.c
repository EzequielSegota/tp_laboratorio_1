#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployee.h"
#define ELEMENTS 1000



int main()
{
    Employee list[ELEMENTS];
    int flag=0,orden;
    char seguir='s';
    initEmployees(list,ELEMENTS);

    eSector sectores[] =
    {
    {1,"RRHH"},
    {2,"Ventas"},
    {3,"Compras"},
    {4, "Contable"},
    {5,"Sistemas"}
    };

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                if(addEmployee(list, ELEMENTS,sectores,5)==-1)
                {
                    printf("\nError, no se puede agregar usuario.\n");
                    system("pause");
                }
                else
                {
                    flag=flag+1;
                }
                break;
            case 2:
                system("cls");
                if(flag>0)
                {
                    printEmployees(list,ELEMENTS,sectores,5);
                    if(removeEmployee(list,ELEMENTS))
                    {
                        flag=flag-1;
                    }
                }
                else
                {
                    printf("\nNo se han ingresado empleados\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if(flag>0)
                {
                    printEmployees(list,ELEMENTS,sectores,5);
                    modificarEmployee(list,ELEMENTS,sectores,5);
                }
                else
                {
                    printf("\nNo se han ingresado empleados\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                if(flag>0)
                {

                    printf("\n\n0. Descendente\n1. Ascendente:");
                    scanf("%d",&orden);
                    sortEmployees(list,ELEMENTS,sectores,5,orden);
                    printEmployees(list,ELEMENTS,sectores,5);
                    system("pause");
                }
                else
                {
                    printf("\nNo se han ingresado empleados para ordenar\n");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                if(flag>0)
                {

                    salarioPromedio(list,ELEMENTS);
                    system("pause");
                }
                else
                {
                    printf("\nNo se han ingresado empleados para promediar\n");
                    system("pause");
                }
                break;
            case 6:
                printf("\nAdios.");
                seguir='n';
                break;

            default:
                printf("Adios.");
                seguir='n';
                break;
        }
    }while(seguir=='s');


    /*for(int i=0;i<ELEMENTS;i++)
    {
        printf("%d\n",list[i].isEmpty);
    }*/
    return 0;
}
