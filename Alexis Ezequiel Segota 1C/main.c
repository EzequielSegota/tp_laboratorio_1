#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define TAMPELICULAS 1000
#define TAMACTORES 10
int menuDeOpciones(char[]);

int main()
{
    int opcion;

    ePeliculas Peliculas[TAMPELICULAS];
    eActor Actores[TAMACTORES];
    inicializarPeliculas(Peliculas, TAMPELICULAS);
    hardcodearPeliculas(Peliculas, 5);
    do
    {
        opcion = menuDeOpciones("\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                system("cls");
                cargarPelicula(Peliculas,TAMPELICULAS,Actores,TAMACTORES);
                break;
            case 2:
                system("cls");

                break;
            case 3:
                system("cls");

                break;
            case 4:
                system("cls");
                mostrarPeliculas(Peliculas,TAMPELICULAS);
                break;

        }
    }while(opcion!=5);



    return 0;
}
