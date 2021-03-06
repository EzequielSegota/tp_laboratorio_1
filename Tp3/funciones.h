#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}EMovie;

#endif // FUNCIONES_H_INCLUDED

void inicializarPeliculas(EMovie *pMovie, int);

int cargarArchivo(EMovie *pMovie,int);

/** \brief Agrega una pelicula al archivo binario
 *  \param movie la estructura a ser agregada al archivo
 *  \return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *pMovie, int);

/** \brief Borra una pelicula del archivo binario
 *  \param movie la estructura a ser eliminada al archivo
 *  \return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *pMovie,int);

/** \brief Modifica la pelicula
 *
 * \param pMovie EMovie* Recibe la estructura
 * \param int recibe el largo
 * \return int
 *
 */
int modificarPelicula(EMovie *pMovie, int);

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 *  \param lista la lista de peliculas a ser agregadas en el archivo.
 *  \param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

/** \brief Busca un lugar vacio dentro de la estructura
 *
 * \param pMovie EMovie*   Recibe la estructura
 * \param int   recibe el largo
 * \return int devuelve el indice
 *
 */
int buscarVacio(EMovie *pMovie, int);

void mostrarPeliculas(EMovie *pMovie,int length);

int guardarArchivo(EMovie *pMovie,int length);

void generarHTML(EMovie *pMovie,int length);
