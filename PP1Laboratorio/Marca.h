#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcionMarca[20];
}eMarca;

typedef struct{

	int id;
	int cantidad;
	int isEmpty;

}eMarcaElejida;


/** \brief carga la descripcion de eMarca en un char pasado por parametro.
 *
 * \param char[] parametro que recibe el contenido de la descrpcion de eMarca.
 * \param int id para comparar con id de eMarca.
 * \param eMarca[] para acceder a su contenido.
 * \param int tamanio.
 * \return un entero que si funciona es 1, caso contrario 0.
 *
 */
int cargarDescripcionMarca(char[],int,eMarca[], int);



/** \brief muestra todas las marcas.
 *
 * \param eMarca[] estructura marca para acceder al contenido.
 * \param int tamanio.
 */
void mostrarMarcas(eMarca[], int);



/** \brief muesta una marca
 * \param estructura marca para acceder a su contenido.
 */
void mostrarMarca(eMarca);



/** \brief recorre la estructura marca y compara los id, cuando coincide rompe con la iteracion.
 *
 * \param int id que lo ultilizamos para compararlo con el id de la estructura marca.
 * \param eMarca estructura marca para acceder a su contenido.
 * \param int tammaster el tamanio de la marca.
 * \return int ret. Si lo encuentra retorna la marca encontrada. Caso contrario devuelve -1
 *
 */
int encontrarMarca(int id, eMarca listaM[], int tammaster);



/** \brief convierte todos los campos de eMarcaElejida en espacios vacios.
 *
 * \param estructura eMarcaElejida para acceder a su campo isEmpty.
 * \param int tammaster.
 *
 */
void InicializarMarcaMasElejida(eMarcaElejida listaME[],int tammaster);

#endif // MARCA_H_INCLUDED

