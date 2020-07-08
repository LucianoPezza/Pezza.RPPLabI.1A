#ifndef NOTEBOOCKS_H_INCLUDED
#define NOTEBOOCKS_H_INCLUDED
#include "Marca.h"
#include "Tipo.h"
#include "Vendedor.h"
#include "Servicios.h"
#include "cliente.h"
#include "Vendedor.h"

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int idCliente;
    int idVendedor;
    int precio;
    int isEmpty;

} eNotebook;


/** \brief da de alta una notebook
 *
 * \param eNotebook estructura
 * \param int tamanio para ntoebook
* \param eMarca estructura
 * \param eTipo estructura
  * \param int tamanio para las estructuras que no sean notebook
 * \param  eCliente estructura
 * \return confirmo si es igual a 0 no se registo ningun empleado. Si es igual a 1 si.
 *
 */

int altaNotebooks(eNotebook[], int,eMarca [], eTipo [], int,eCliente [],eVendedor listaVE[]);




/** \brief hardcodea todas las estructuras menos notebook y trabajo
 *
 * \param eTipo estructura
 * \param eMarca estructura
* \param int tamanio de las estructuras
 * \param eServicio estructura
  * \param eCliente estructura
 * \return void
 *
 */
void hardcodearMarcaTipoYServicios(eTipo[], eMarca[], int, eServicio [], eCliente[],eVendedor []);






/** \brief Inicializa los campos de las notebooks en 1(libre)
 *
 * \param eNotebook estructura
 * \param int tamanio
 * \return void
 *
 */
void inicializarNoteboocks(eNotebook[], int);





/** \brief Busca noteboos mediante el id
 *
 * \param int id para comparar con el id de la notebook.
 * \param eNotebook estructura
 * \param int tamanio
 * \return indice si es -1 no encontro nada. Caso contrario si la encontro
 *
 */
int buscarNotebook(int, eNotebook[], int);






/** \brief da de baja una notebook
 *
 * \param eNotebook estructura
 * \param int tamanio para ntoebook
* \param eMarca estructura
 * \param eTipo estructura
  * \param int tamanio para las estructuras que no sean notebook
 * \param  eCliente estructura

 */
void bajaNotebook(eNotebook [], int, eMarca[], eTipo[], int,eCliente[],eVendedor listaVE[]);






/** \brief modifica una noteboock elejida
 *
 * \param eNotebook estructura
 * \param int tamanio para ntoebook
* \param eMarca estructura
 * \param eTipo estructura
  * \param int tamanio para las estructuras que no sean notebook
 * \param  eCliente estructura
 */
void modificarNotebook(eNotebook[], int, eMarca[], eTipo[], int, eCliente[],eVendedor listaVE[]);





/** \brief muestras todas las notebooks
 *
 * \param eNotebook estructura
 * \param int tamanio para ntoebook
* \param eMarca estructura
 * \param eTipo estructura
  * \param int tamanio para las estructuras que no sean notebook
 * \param  eCliente estructura
 */
void mostrarNotebooks(eNotebook[], int, eMarca[], eTipo[], int,eCliente[], eVendedor listaVE[]);









/** \brief muestras una notebook
 *
 * \param eNotebook estructura
* \param eMarca estructura
 * \param eTipo estructura
 * \param  eCliente estructura
 */
void mostrarNotebook(eNotebook, eMarca[], eTipo[], int,eCliente[], eVendedor listaVE[]);



/** \brief busca un lugar libre para una noteboock
 *
 * \param eNotebook estructura
 * \param int tamanio para recorrer la estructura
 * \return una lugar libre
 *
 */
int buscarLibre(eNotebook [], int );








/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ordenarPorMarcaYPrecio(eMarca[], int, eNotebook[]);









/** \brief agrega datos a los campos de la estructura eNotebook.
 *
 * \param eNotebook estructura
 * \param int tamanio para recorrer la estructura
 *
 */
void hardcodearNotebooks(eNotebook [], int );







/** \brief carga el modelo de la notebook y su precio en 2 variables pasadas por parametro.
 *
 * \param char[] pasado por parametro para recibir el modelo de la estructura notebook.
 * \param int* pasado por parametro para recibir el precio de la estructura notebook.
 * \param int  id pasado por parametros para comparar con la estrucutra.
 * \param eNotebook[] para acceder a la estructura.
 * \param int tam para recorrer eNotebook.
 * \return un entero que si vale uno funciona y caso contrario vale 0.
 *
 */
int cargarModeloyPrecioNotebook(char [],int*,int, eNotebook[], int);



/** \brief Ordena la lista de notebooks por precio y marca
 *
 * \param [] eNotebook estructura notebook para acceder a sus campos
 * \param int tamanio
 * \return void
 *
 */
void ordernarNotebooksPorMarcaYPrecio(eNotebook [], int);

#endif // NOTEBOOCKS_H_INCLUDED

