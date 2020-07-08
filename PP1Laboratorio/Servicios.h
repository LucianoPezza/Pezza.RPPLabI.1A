#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;




/** \brief Lista los servicios
 *
 * \param estructura eServicio
 * \param int tamanio
 */
void listarServicios(eServicio[], int);

/** \brief Lista un servicio
 *
 * \param estructura eServicio
 */
void listarServicio(eServicio);


/** \brief  Carga la descripcion del a estructura eServicio en una variable char recibida por parametros.
 *
 * \param char[] descripcion que le cargo lo que hay en la estructura.
 * \param int id para comparar los id con la estructura.
 * \param eServicio[] para acceder a los campos de eServicio.
 * \param int tamanio para recorrer eServicio.
 * \return int bandera que confirma que retorna 1 si esta todo bien y 0 en caso contrario.
 *
 */
int cargarDescripcionServicio(char[], int, eServicio[], int);





/** \brief
 *
 * \param int* puntero de entero pasado por parametros para guardar el precio de eServicio.
 * \param int id para comparar los id con la estructura.
 * \param eServicio[] para acceder a los campos de eServicio.
 * \param int tamanio para recorrer eServicio.
 * \return int bandera que confirma que retorna 1 si esta todo bien y 0 en caso contrario.
 *
 */
int cargarPrecioServicio(int*, int, eServicio[], int);

#endif // SERVICIOS_H_INCLUDED
