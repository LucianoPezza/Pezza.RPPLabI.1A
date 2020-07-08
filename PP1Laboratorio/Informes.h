#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Noteboocks.h"
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"
#include "Vendedor.h"


/** \brief Muestra las notebooks del tipo seleccionado.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 *
 */
void MostrarNotebooksDelTipoSeleccionadoPorElUsuario(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int,eVendedor listaVE[]);


/** \brief mostrar Notebooks De Una Marca Seleccionada.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 *
 */
void mostrarNotebooksDeUnaMarcaSeleccionada(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int,eVendedor listaVE[]);


/** \brief Mostrar notebooks mas baratas.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 *
 */
int mostrarNotebooksMasBaratas(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);


/** \brief mostrar Notebooks Separadas Por Marca.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 *
 */
void mostrarNotebooksSeparadasPorMarca(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int,eVendedor listaVE[]);


/** \brief elejir Tipo Y Marca Y Contar Notebooks.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 *
 */
void elejirTipoYMarcaYContarNotebooks(eNotebook, eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);


/** \brief mostrar Las Marcas Elejidas PorClientes.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \return void
 */
void mostrarLasMarcasElejidasPorClientes(eNotebook, eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[],eMarcaElejida[], int, int);


/** \brief pedir Una Notebook Y Mostrar Todos los Trabajos Que Se Le Hicieron A La Misma.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \param eTrabajo[] estructura de trabajo
 * \param eServicio[] estructura de Servicio.
 * \return void
 */
void pedirUnaNotebookYMostrarTodosLosTrabajosQueSeLeHicieronALaMisma(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int,eTrabajo [],eServicio[],eVendedor listaVE[]);


/** \brief pedir Una Notebook Y Mostrar ElTotal De Importa De Los Servicios.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \param eTrabajo[] estructura de trabajo
 * \param eServicio[] estructura de Servicio.
 * \return void
 */
void pedirUnaNotebookYMostrarElTotalDeImportaDeLosServicios(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);



/** \brief pedir Un Servicio Y Mostrar Las Notebooks Del Ese Servicio Y La Fecha.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \param eTrabajo[] estructura de trabajo
 * \param eServicio[] estructura de Servicio.
 * \return void
 */
void pedirUnServicioYMostrarLasNotebooksDelEseServicioYLaFecha(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);


/** \brief pedir Una Fecha Y Mostrar Todos Los Servicios Realizados En La Misma.
 *
 * \param eNotebook[] estructura notebook
 * \param eTipo[] estructura tipo
 * \param listaM[] eMarca estructura marca
 * \param listaC[] eCliente estructura cliente
 * \param int tamanio para las notebooks
 * \param int tamanio para el restro de las estructuras
 * \param eTrabajo[] estructura de trabajo
 * \param eServicio[] estructura de Servicio.
 * \return void
 */
void pedirUnaFechaYMostrarTodosLosServiciosRealizadosEnLaMisma(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[]);

/** \brief Muesta el vendedor de la notebook pedida por consola
 *
 * \param listaN[] eNotebook
 * \param listaT[] eTipo
 * \param listaM[] eMarca
 * \param listaC[] eCliente
 * \param tam int
 * \param tammaster int
 * \param listaTR[] eTrabajo
 * \param listaS[] eServicio
 * \param listaVE[] eVendedor
 * \return void
 *
 */
void pedirUnaNotebookYMostrarSusVendedores(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);


/** \brief Muesta a los vendedores segmentados por sus horas trabajadas.
 *
 * \param listaN[] eNotebook
 * \param listaT[] eTipo
 * \param listaM[] eMarca
 * \param listaC[] eCliente
 * \param tam int
 * \param tammaster int
 * \param listaTR[] eTrabajo
 * \param listaS[] eServicio
 * \param listaVE[] eVendedor
 * \return void
 *
 */
void mostarVendedorConMasHorasTrabajadas(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);


/** \brief Le suma del valor del precio a las notebooks.
 *
 * \param listaN[] eNotebook
 * \param listaT[] eTipo
 * \param listaM[] eMarca
 * \param listaC[] eCliente
 * \param tam int
 * \param tammaster int
 * \param listaTR[] eTrabajo
 * \param listaS[] eServicio
 * \param listaVE[] eVendedor
 * \return void
 *
 */
void sumarlePrecioaLasNotebook(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);

/** \brief Muesta el promedio de los sueldos de los vendedores
 *
 * \param listaN[] eNotebook
 * \param listaT[] eTipo
 * \param listaM[] eMarca
 * \param listaC[] eCliente
 * \param tam int
 * \param tammaster int
 * \param listaTR[] eTrabajo
 * \param listaS[] eServicio
 * \param listaVE[] eVendedor
 * \return void
 *
 */
void mostrarPromedioDeSueldosDeVendedores(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);

void pedirUnServicioYMostrarSusTrabajos(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);

void sumarlePrecioaLosservicios(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[]);

#endif // INFORMES_H_INCLUDED

