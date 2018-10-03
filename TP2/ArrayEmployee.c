#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;
    if(list != NULL)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
            list[i].id=0;
        }
        retorno=0;
    }

    return retorno;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n\t\t****MENU****\n");
    printf("\n1. Ingresar empleado.");
    printf("\n2. Dar de baja empleado.");
    printf("\n3. Modificar empleado.");
    printf("\n4. Listar ordenando por apellido.");
    printf("\n5. Total,promedio,cantidad que supera el promedio.\n");
    printf("\n6. Salir.");
    scanf("%d",&opcion);

    return opcion;
}

int buscarLugar(Employee* list, int len)
{
    int i,retorno=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int comprobarID(Employee* list,int len,int id)
{
    int i,retorno=0;
    for(i=0;i<len;i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
            retorno=-1;
    }
    return retorno;
}

int addEmployee(Employee* list, int len,eSector* sectores, int tamSec)
{
        int retorno=-1,espacioLibre,id;

        Employee aux;

        system("cls");
        id=siguienteID(list,len);
        aux.id=id;
        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(aux.name);
        printf("\nIngrese apellido:");
        fflush(stdin);
        gets(aux.lastName);
        printf("\nIngrese salario:");
        scanf("%f",&aux.salary);
        aux.sector=elegirSector(sectores,tamSec);
        aux.isEmpty=0;
        system("cls");

        espacioLibre=buscarLugar(list,len);

        while(comprobarID(list,len,aux.id)==-1)
        {
            printf("\nError,ID ya en uso, ingrese nuevo ID:");
            scanf("%d",&aux.id);
        }
        if(espacioLibre!=-1)
        {
            list[espacioLibre]=aux;
            retorno=1;
        }


    return retorno;
}

void cargarDescripcion(eSector sec[],int tamSec,int idSector,char cadena[])
{
    int i;
    for(i=0;i<tamSec;i++)
    {
        if(sec[i].id == idSector)
        {
            strcpy(cadena,sec[i].description);
            break;
        }
    }
}

int elegirSector(eSector sectores[],int tam)
{
    int idSector;
    int i;
    printf("\nSectores\n\n");
    for(i=0;i<tam;i++)
    {
        printf("%d. %s\n",sectores[i].id,sectores[i].description);
    }
    printf("\nSeleccione sector: ");
    scanf("%d",&idSector);

    while(idSector>5 || idSector<1)
    {
        printf("\nError seleccione sector 1-5: ");
        scanf("%d",&idSector);
    }

    return idSector;
}


void printEmploye(Employee list,eSector sec[],int tamSec)
{
    char descripcion[20];
    cargarDescripcion(sec,tamSec,list.sector,descripcion);
    printf("\nID:%d\tNombre:%s\tApellido:%s\tSalario:%.2f\tSector:%s\n",list.id,list.name,list.lastName,list.salary,descripcion);

}

int printEmployees(Employee* list, int length,eSector* sectores,int tamSec)
{
    int i;
    for(i=0; i< length; i++)
    {
        if( list[i].isEmpty == 0)
        {
            printEmploye(list[i],sectores,tamSec);
        }
    }
}

int buscarPorID(Employee* list, int len,int id)
{
    int i,retorno=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int removeEmployee(Employee* list, int len)
{
    int flag=-1,id,i;

    printf("\nIngrese id a eliminar:");
    scanf("%d",&id);
    i=buscarPorID(list,len,id);
    if(i!=-1)
    {
        list[i].isEmpty=1;
        list[i].id=0;
        flag=1;
    }

    if(flag==-1)
    {
        printf("\nID no encontrado:%d\n",id);
        system("pause");
    }

    return flag;
}

int siguienteID(Employee list[],int len)
{
    int retorno = 0;
    int i;

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                    if(list[i].id>retorno)
                    {
                         retorno=list[i].id;
                    }

            }
        }

    return retorno+1;
}

void modificarEmployee(Employee list[] ,int len, eSector* sec, int tamSec)
{
    int id, indice=-1, opcion,opcionMenu;

    printf("\nIngrese ID de usuario a modificar: ");
    scanf("%d",&id);

    indice=buscarPorID(list,len,id);

    if(indice>=0)
    {
        printEmploye(list[indice],sec,tamSec);

        printf("\nEsta seguro que desea modificar a: \n");
        printEmploye(list[indice],sec,tamSec);
        printf("1. Si\n2. No\n");
        scanf("%d",&opcion);

        if(opcion==1)
        {
            printf("\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\nQue desea modificar:");
            scanf("%d",&opcionMenu);

            switch(opcionMenu)
            {
                case 1:
                    system("cls");
                    printf("\nIngrese nombre:");
                    fflush(stdin);
                    gets(list[indice].name);
                    break;
                case 2:
                    system("cls");
                    printf("\nIngrese apellido:");
                    fflush(stdin);
                    gets(list[indice].lastName);
                    break;
                case 3:
                    system("cls");
                    printf("\nIngrese salario:");
                    scanf("%f",&list[indice].salary);
                    break;
                case 4:
                    system("cls");
                    list[indice].sector=elegirSector(sec,tamSec);
                    break;
            }
        }

    }
    else
    {
        printf("El ID ingresado no coincide con ningun usuario.\n");
        system("pause");
    }


}

int sortEmployees(Employee* list, int len,eSector* sectores,int tamSec,int order)
{

    Employee aux;
    while(order>1 || order<0)
    {
        printf("\n\n0. Descendente\n1. Ascendente\n");
        scanf("%d",&order);
    }
    if(order==0 && len > 0 && list != NULL)
    {
         for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    else
    {
        if(len > 0 && list != NULL)
            {
                for(int i=0; i<len - 1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) < 0)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }
    }

}

void salarioPromedio(Employee* list, int len)
{
    float promedio=0;
    float total=0;
    int contadorEmpleados=0;
    int contadorSalarios=0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            contadorEmpleados++;
            total=total+list[i].salary;
        }
    }
    promedio= total/contadorEmpleados;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].salary>promedio)
            {
                contadorSalarios++;
            }
        }
    }
    printf("Total Salarios: %.2f\n", total);
    printf("Promedio Salarios: %.2f\n", promedio);
    printf("Cantidad de Empleados que superan el promedio: %d\n", contadorSalarios);
}
