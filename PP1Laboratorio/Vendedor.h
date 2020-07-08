#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

typedef struct
{
    int horasTrabajadas;
    char nombres[20];
    int id;
    int sueldo;
}eVendedor;

/** \brief Muesta todos los vendedores
 *
 * \param eVendedor[]
 * \param int
 * \return void
 *
 */
void mostrarVendedores(eVendedor[], int );



/** \brief Muestra un vendedor
 *
 * \param eVendedor
 * \return void
 *
 */
void mostrarVendedor(eVendedor);






/** \brief guarda el nombre y las horas trabjadas de un vendedor segun el id.
 *
 * \param char[] pasado por parametro para guardar el nombre.
 * \param int* pasado por parametro para guardar las horas trabajadas.
 * \param int id para comparar ocn la estructura.
 * \param [] eVendedor.
 * \param int tamanio.
 * \return int si funciona retorna 1, caso contrario 0.
 *
 */
int cargarDescripcionVendedor(int*,char[],int* ,int , eVendedor [], int);


#endif // VENDEDOR_H_INCLUDED
