#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializarPeliculas(EMovie *pMovie, int tamanio)
{
    int i;

    for(i=0;i<tamanio;i++)
    {
        strcpy((pMovie+i)->titulo," ");
        strcpy((pMovie+i)->genero," ");
        (pMovie+i)->duracion=0;
        strcpy((pMovie+i)->descripcion," ");
        (pMovie+i)->puntaje=0;
        strcpy((pMovie+i)->linkImagen," ");
    }
}

int cargarArchivo(EMovie *pMovie,int tamanio)
{
    int flag=0;
	FILE *A;

	A=fopen("archivo.bin", "rb");

	if(A==NULL)
	{
		A = fopen("archivo.bin", "wb");

		if(A==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag==0)
	{
	    fread(pMovie,sizeof(EMovie),tamanio,A);
    }

	fclose(A);

	return 0;
}

int agregarPelicula(EMovie *pMovie, int tamanio)
{
    int indiceVacio;

    indiceVacio=buscarVacio(pMovie, tamanio);

    if(indiceVacio>=0)
    {
        printf("Ingrese titulo de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->titulo);

        printf("Ingrese genero de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->genero);

        do{
            printf("Ingrese duracion de la pelicula: ");
            fflush(stdin);
            scanf("%d", &(pMovie+indiceVacio)->duracion);
            if((pMovie+indiceVacio)->duracion<=0)
            {
                printf("Error");
            }
        }while((pMovie+indiceVacio)->duracion<=0 && !isdigit((pMovie+indiceVacio)->duracion));


        printf("Ingrese descripcion de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->descripcion);


        do{
            printf("Ingrese puntaje de la pelicula (del 0 al 10): ");
            fflush(stdin);
            scanf("%d", &(pMovie+indiceVacio)->puntaje);
            if((pMovie+indiceVacio)->puntaje<0 || (pMovie+indiceVacio)->puntaje>10)
            {
                printf("Error! ");
            }
        }while(((pMovie+indiceVacio)->puntaje<0 || (pMovie+indiceVacio)->puntaje>10) && !isdigit((pMovie+indiceVacio)->puntaje));

        printf("Ingrese link de imagen de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->linkImagen);
    }
    else
        printf("No hay mas espacio disponible.");

    return indiceVacio;
}

int borrarPelicula(EMovie *pMovie, int tamanio)
{
    int opcion;
    char opcionDos;

    printf("Seleccione pelicula que desea eliminar: \n");

    mostrarPeliculas(pMovie,tamanio);

    scanf("%d",&opcion);

    printf("Esta seguro que desea eliminar s/n: %s\n",(pMovie+(opcion-1))->titulo);

    fflush(stdin);
    opcionDos=getchar();

    if(opcion>=1 && opcion<=tamanio && opcionDos=='s')
    {
        strcpy((pMovie+(opcion-1))->titulo,"");
        strcpy((pMovie+(opcion-1))->genero,"");
        (pMovie+(opcion-1))->duracion=0;
        strcpy((pMovie+(opcion-1))->descripcion,"");
        (pMovie+(opcion-1))->puntaje=0;
        strcpy((pMovie+(opcion-1))->linkImagen,"");
    }

    return opcion;
}

int modificarPelicula(EMovie *pMovie, int tamanio)
{
    int opcion, opcionDos;

    printf("Seleccione pelicula que desea modificar: \n");

    mostrarPeliculas(pMovie,tamanio);

    scanf("%d",&opcion);

    printf("1- Modificar Titulo\n");
    printf("2- Modificar Genero\n");
    printf("3- Modificar Duracion\n");
    printf("4- Modificar Descripcion\n");
    printf("5- Modificar Puntaje\n");
    printf("6- Modificar Link de Imagen\n");
    printf("7- Volver al menu principal\n");

    fflush(stdin);
    scanf("%d",&opcionDos);

    system("cls");

    if(opcion>=1 && opcion<=tamanio)
    {
        switch(opcionDos)
        {
            case 1:
                {
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->titulo);
                }
                break;
            case 2:
                {

                    fflush(stdin);
                    gets((pMovie+(opcion-1))->genero);
                }
                break;
            case 3:
                {
                    do{
                    fflush(stdin);
                    scanf("%d", &(pMovie+(opcion-1))->duracion);
                    if((pMovie+(opcion-1))->duracion<=0)
                    {
                        printf("Error");
                    }
                    }while((pMovie+(opcion-1))->duracion<=0 && !isdigit((pMovie+(opcion-1))->duracion));
                }
               break;
            case 4:
                {
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->descripcion);
                }
                break;
            case 5:
                {
                    do{
                    printf("Ingrese puntaje de la pelicula (del 0 al 10): ");
                    fflush(stdin);
                    scanf("%d", &(pMovie+(opcion-1))->puntaje);
                    if((pMovie+(opcion-1))->puntaje<0 || (pMovie+(opcion-1))->puntaje>10)
                    {
                        printf("Error! ");
                    }
                    }while(((pMovie+(opcion-1))->puntaje<0 || (pMovie+(opcion-1))->puntaje>10) && !isdigit((pMovie+(opcion-1))->puntaje));
                }
                break;
            case 6:
                {
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->linkImagen);
                }
                break;
            default:
                break;
        }
    }

    return opcion;
}

int buscarVacio(EMovie *pMovie, int tamanio)
{
    int indiceVacio=-1;
	int i;
	for( i=0; i < tamanio; i++)
    {
        if((pMovie+i)->duracion==0)
        {
            indiceVacio=i;
            break;
        }
    }

	return indiceVacio;
}

void mostrarPeliculas(EMovie *pMovie,int tamanio)
{
    int i;

    printf("\tTitulo\tGenero\tDuracion\tDescripcion\t\t\tPuntaje\n");

    for(i=0;i<tamanio;i++)
    {
        if((pMovie+i)->duracion>0)
        {
            printf("%d\t%s\t%s\t%d\t\t%s\t\t\t%d\n",i+1, (pMovie+i)->titulo, (pMovie+i)->genero,(pMovie+i)->duracion, (pMovie+i)->descripcion,(pMovie+i)->puntaje);
        }
    }
}

int guardarArchivo(EMovie *pMovie,int tamanio)
{
	FILE *A;
	int flag=0;

    A=fopen("archivo.bin","wb");

    if(A == NULL)
    {
        flag=1;
    }
    else
    {
        fwrite(pMovie,sizeof(EMovie),tamanio,A);
        fclose(A);
        flag=0;
    }

	return flag;
}

void generarHTML(EMovie *pMovie,int tamanio)
{
     int i;
     FILE *A;
     A=fopen("index.html", "w");

     if(A == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         for(i=0; i<tamanio; i++)
         {
             fprintf(A,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");
             fprintf(A,"<img class='img-responsive img-rounded' src='");
             if((pMovie+i)->duracion != 0)
             {
                 fprintf(A,"%s'\n\nalt=''>\n </a>\n <h3>\n <a href='#'>", (pMovie+i)->linkImagen);
                 fprintf(A,"%s</a>\n </h3>\n<ul>\n<li>", (pMovie+i)->titulo);
                 fprintf(A,"Genero: %s</li>\n<li>", (pMovie+i)->genero);
                 fprintf(A,"Puntaje: %d</li>\n<li>", (pMovie+i)->puntaje);
                 fprintf(A,"Duracion: %d</li>\n</ul>\n <p>", (pMovie+i)->duracion);
                 fprintf(A,"%s</p>\n</article>\n", (pMovie+i)->descripcion);
             }
         }
      }

      fclose(A);

      printf("Archivo HTML creado con exito.\n");
      system("pause");
}
