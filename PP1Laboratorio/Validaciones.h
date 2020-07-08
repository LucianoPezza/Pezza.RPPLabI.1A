#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Verefica que lo pasado por parametros sea un numero entero
 *
 * \param char[] variable pasada por parametros que luego es convertida en entero.
 * \return int entero validado
 *
 */
int getInti(char[]);



/** \brief Pide un numero entero por consola y lo guarda validandolo.
 *
 * \param char[] mensaje.
 * \param char[] mensajeError.
 * \return int entero validado.
 *
 */
int getInt(char[], char[]);



/** \brief Pide una edad dentro de los rangos posibles y la guarda.
 *
 * \return int edad.
 *
 */
int getEdad();



/** \brief Valida que sea un nombre Valido
 *
 * \param char[] nombre pasado por parametro
 * \return int nombre
 *
 */
int nombresValidos(char[]);


/** \brief valida que lo pasado en parametros sea solo una letra.
 *
 * \param char letra pasada por parametro
 * \return int retorno que si funciona es 1, y caso contrario 0.
 *
 */
int letraValida(char);


/** \brief Pide una letra por consola y la guarda
 *
 * \param [] char mensaje
 * \param [] char mensaje Error

 * \return letra
 *
 */
char getLetra(char[], char[]);



/** \brief Pide un nombre por consola y lo guarda
 *
 * \param [] char mensaje
 * \param [] char mensaje Error
 * \param [] char parametro del nombre recibido.
 *
 */
void getnombre(char [],char [], char []);


/** \brief Pide que ingrese una letra que indique el sexo, sea f o m
 *
 * \param [] char mensaje

 * \return int sexo f o m
 */
int getSexo(char[]);



/** \brief Pide 3 punteros a enteros, dia, fecha y anio y los guarda
 *
 * \param int* dia
 * \param int* mes
 * \param int* anio
 * \return void
 *
 */
void gotFecha(int*, int*, int*);

/** \brief Pide el Id del servicio y lo guarda
 *
 * \return int idServicio
 *
 */
int getIdServicio();


/** \brief pide el idTipo y lo guarda
 *
 * \return int idServicio
 *
 */


int getIdTipo();

/** \brief pide un id y lo guarda
 *
 * \return int id
 *
 */
int getId();


/** \brief pide el id Marca y lo guarda
 *
 * \return int idMarca
 *
 */
int getIdMarca();

/** \brief pide el precio y lo guarda
 *
 * \return int Precio
 *
 */
int getPrecio();



/** \brief pide el id Cliente y lo guarda
 *
 * \return int cliente
 *
 */
int getIdCliente();




/** \brief pide y valida que sea un numero flotante y lo guarda
 *
 *\param char[] mensaje
 * \return float
 *
 */
float getFloat(char[]);

/** \brief Obtiene el id del vendedor y lo guarda
 *
 * \return int idVendedor
 *
 */
int getIdVendedor();

#endif // VALIDACIONES_H_INCLUDED
