#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tamanio 100

int main()
{
    char seguir='s';
    int opcion=0;
    int i;

    EMovie *pMovie;
    EMovie pelicula[tamanio];

    pMovie=&pelicula;

    inicializarPeliculas(pMovie,tamanio);

    if(!cargarArchivo(pMovie, tamanio))
	{
	    printf("Archivo cargado.\n");
	}
	else
	{
		printf("No se pudo abrir el archivo.");
	}


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                agregarPelicula(pMovie,tamanio);
                break;
            case 2:
                modificarPelicula(pMovie,tamanio);
                break;
            case 3:
                borrarPelicula(pMovie,tamanio);
               break;
            case 4:
                generarHTML(pMovie,tamanio);
                break;
            case 5:
                printf("\nGuardar cambios s/n ?: ");
				opcion = tolower(getche());

				if(opcion == 's')
				{
					if(guardarArchivo(pMovie, tamanio))
					{
						printf("\nNo se pudo abrir el archivo\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
                break;
        }
    }

    return 0;
}
