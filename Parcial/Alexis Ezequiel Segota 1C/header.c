#include "header.h"

void inicializarPeliculas(ePeliculas peliculas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        peliculas[i].estado = LIBRE;
    }
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre( ePeliculas x[], int tam)
{
    int indice = -1,i;

    for( i=0; i< tam; i++)
    {

        if( x[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int ePelicula_siguienteId(ePeliculas peliculas[],int limite)
{
    int retorno = 1000;
    int i;

        for(i=0; i<limite; i++)
        {
            if(peliculas[i].estado == OCUPADO)
            {
                    if(peliculas[i].id>retorno)
                    {
                         retorno=peliculas[i].id;
                    }

            }
        }

    return retorno+1;
}

void hardcodearPeliculas(ePeliculas peliculas[],int tam)
{
    int i;
    char titulos[][50]={"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13  Going on 30"};
    int id[]={1000,1001,1002,1003,1004,1005};
    char genero[][50]={"COMEDIA","COMEDIA","COMEDIA","COMEDIA","COMEDIA","ROMANCE"};
    int dia[]={20,10,2,10,5,7};
    int mes[]={4,6,5,7,9,5};
    int anio[]={2019,2013,2004,2019,2012,2004};
    int actorId[]={2,5,4,5,2,3};
    char actorNombre[][50]={"Robert  Downey Jr","Chris Hemsworth","Chris Evans","Chris Hemsworth","Robert  Downey Jr","Mark Ruffalo"};
    char actorPais[][50]={"EEUU","Argentina","EEUU","Argentina","EEUU","Canada"};
    for(i=0; i<tam; i++)
    {
        strcpy(peliculas[i].titulo, titulos[i]);
        strcpy(peliculas[i].genero, genero[i]);
        peliculas[i].id=id[i];
        peliculas[i].fecha.dia=dia[i];
        peliculas[i].fecha.mes=mes[i];
        peliculas[i].fecha.anio=anio[i];
        strcpy(peliculas[i].actor.nombre, actorNombre[i]);
        peliculas[i].actor.id=actorId[i];
        strcpy(peliculas[i].actor.paisOrigen, actorPais[i]);


        peliculas[i].estado = OCUPADO;

    }
}

void menuGenero(ePeliculas pelicula[], int tam, int posicion)
{
    int opcion;
        printf("\nElija un genero:");
        printf("\n1.ACCION.");
        printf("\n2.COMEDIA.");
        printf("\n3.DRAMA.");
        printf("\n4.ROMANCE.");
        printf("\n5.TERROR.\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                strcpy(pelicula[posicion].genero,"ACCION");
                break;
            case 2:
                strcpy(pelicula[posicion].genero,"COMEDIA");
                break;
            case 3:
                strcpy(pelicula[posicion].genero,"DRAMA");
                break;
            case 4:
                strcpy(pelicula[posicion].genero,"ROMANCE");
                break;
            case 5:
                strcpy(pelicula[posicion].genero,"TERROR");
                break;


        }
}

void menuActor(ePeliculas pelicula,eActor actores[],int tamActor)
{
    int opcion;
    printf("\n1.Scarlett Johansson");
    printf("\n2.Robert  Downey Jr");
    printf("\n3.Mark Ruffalo");
    printf("\n4.Chris Evans");
    printf("\n5.Chris Hemsworth");
    printf("\n6.Samuel Jackson");
    printf("\n7.Gwyneth Paltrow");
    printf("\n8.Paul Rudd");
    printf("\n9.Bradley Cooper");
    printf("\n10.Josh Brolin");
    printf("\nIngrese actor:");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            strcpy(pelicula.actor.nombre, "Scarlett Johansson");
            strcpy(pelicula.actor.paisOrigen,"Argentina");
            pelicula.actor.id=1;
            break;
        case 2:
            strcpy(pelicula.actor.nombre, "Robert  Downey Jr");
            strcpy(pelicula.actor.paisOrigen,"EEUU");
            pelicula.actor.id=2;
            break;
        case 3:
            strcpy(pelicula.actor.nombre, "Mark Ruffalo");
            strcpy(pelicula.actor.paisOrigen,"Canada");
            pelicula.actor.id=3;
            break;
        case 4:
            strcpy(pelicula.actor.nombre, "Chris Evans");
            strcpy(pelicula.actor.paisOrigen,"EEUU");
            pelicula.actor.id=4;
            break;
        case 5:
            strcpy(pelicula.actor.nombre, "Chris Hemsworth");
            strcpy(pelicula.actor.paisOrigen,"Argentina");
            pelicula.actor.id=5;
            break;
        case 6:
            strcpy(pelicula.actor.nombre, "Samuel Jackson");
            strcpy(pelicula.actor.paisOrigen,"EEUU");
            pelicula.actor.id=6;
            break;
        case 7:
            strcpy(pelicula.actor.nombre, "Gwyneth Paltrow");
            strcpy(pelicula.actor.paisOrigen,"Canada");
            pelicula.actor.id=7;
            break;
        case 8:
            strcpy(pelicula.actor.nombre, "Paul Rudd");
            strcpy(pelicula.actor.paisOrigen,"Argentina");
            pelicula.actor.id=8;
            break;
        case 9:
            strcpy(pelicula.actor.nombre, "Bradley Cooper");
            strcpy(pelicula.actor.paisOrigen,"EEUU");
            pelicula.actor.id=9;
            break;
        case 10:
            strcpy(pelicula.actor.nombre, "Josh Brolin");
            strcpy(pelicula.actor.paisOrigen,"Canada");
            pelicula.actor.id=10;
            break;

    }
}


void cargarPelicula(ePeliculas peliculas[], int tam, eActor actores[],int tamActor)
{
    int i;

    i = buscarLibre(peliculas, tam);
    if(i!=-1)
    {
        printf("Ingrese titulo: ");
        fflush(stdin);
        gets(peliculas[i].titulo);

        menuGenero(peliculas,tam, i);

        printf("\nIngrese dia de estreno:");
        scanf("%d",&peliculas[i].fecha.dia);
        printf("\nIngrese mes de estreno:");
        scanf("%d",&peliculas[i].fecha.mes);
        printf("\nIngrese año de estreno:");
        scanf("%d",&peliculas[i].fecha.anio);

        menuActor(peliculas[i],actores,tamActor);

        peliculas[i].id=ePelicula_siguienteId(peliculas, tam);

        peliculas[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }



}

void mostrarPelicula(ePeliculas pelicula)
{
    printf("\n\nTitulo:%s\nFecha de Estreno:%d/%d/%d\nGenero:%s\nActor:%s",pelicula.titulo,pelicula.fecha.dia,pelicula.fecha.mes,pelicula.fecha.anio,pelicula.genero,pelicula.actor.nombre);

}
void mostrarPeliculas(ePeliculas peliculas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(peliculas[i].estado==OCUPADO)
        {
            mostrarPelicula(peliculas[i]);
        }

    }
}
