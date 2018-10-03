#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

typedef struct
{
    int id;
    char description[20];

}eSector;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Menu de opciones.
 *
 * \param void
 * \return int Opcion elegida
 *
 */
int menu(void);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len,eSector* sectores,int tamSec);


/** \brief Busca en el array un lugar libre
 *
 * \param list Employee*
 * \param len int
 * \return int Devuelve el indice del lugar vacio o -1 si no hay lugar
 *
 */
int buscarLugar(Employee* list, int len);

/** \brief Comprueba que el id no este en uso
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int comprobarID(Employee* list,int len,int id);

/** \brief muestra sectores a elegir
 *
 * \param sectores[] eSector
 * \param tam int
 * \return int devuelve el id del sector elegido
 *
 */
int elegirSector(eSector sectores[],int tam);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length,eSector* sectores,int tamSec);

/** \brief print the content of one employe
 *
 * \param emp eEmpleado
 * \param sec[] eSector
 * \param tamSec int
 * \return void
 *
 */
void printEmploye(Employee emp,eSector sec[],int tamSec);

/** \brief Carga nombre del sector en una cadena
 *
 * \param sec[] eSector sector
 * \param tamSec int tamaño de sector
 * \param idSector int id de donde saca el nombre
 * \param cadena[] char cadena donde se guarda
 * \return void
 *
 */
void cargarDescripcion(eSector sec[],int tamSec,int idSector,char cadena[]);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len);

/** \brief Asigna el siguiente id libre.
 *
 * \param list[] Employee
 * \param len int
 * \return int
 *
 */
int siguienteID(Employee list[],int len);

/** \brief modifica el usuario por id, pide id a modificar, posee submenu y pueden elegirse que campos modificar
 *
 * \param list[] Employee
 * \param len int
 * \param sec eSector*
 * \param tamSec int
 * \return void
 *
 */
void modificarEmployee(Employee list[] ,int len,eSector* sec,int tamSec);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len,eSector* sectores,int tamSec,int order);

/** \brief Muestra cantidad de salarios, promedio y cantidad que supera el promedio
 *
 * \param list Employee*
 * \param len int
 * \return void
 *
 */
void salarioPromedio(Employee* list, int len);

#endif // FUNCIONES_H_INCLUDED
