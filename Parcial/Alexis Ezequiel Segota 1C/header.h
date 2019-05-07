#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    char nombre[20];
    int id;
    char paisOrigen[20];
} eActor;


typedef struct
{
    eFecha fecha;
    eActor actor;
    char titulo[20];
    char genero[20];
    int id;
    int estado;
} ePeliculas;

void inicializarPeliculas(ePeliculas peliculas[], int tam);
int buscarLibre( ePeliculas x[], int tam);
int ePelicula_siguienteId(ePeliculas peliculas[],int limite);
void hardcodearPeliculas(ePeliculas[],int tam);

void menuGenero(ePeliculas[], int, int);
void cargarPelicula(ePeliculas[], int,eActor[],int);
void mostrarPelicula(ePelicula);
void mostrarPeliculas(ePeliculas[],int);
void menuActor(ePeliculas,eActor[],int);
#endif // HEADER_H_INCLUDED
