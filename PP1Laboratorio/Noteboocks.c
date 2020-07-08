#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noteboocks.h"
#include "Validaciones.h"
#include "cliente.h"
#include "Marca.h"
#include "Tipo.h"
#include "Vendedor.h"

void hardcodearMarcaTipoYServicios(eTipo unTipo[], eMarca unaMarca[], int tammaster, eServicio unServicio[], eCliente unCliente[], eVendedor unVendedor[])
{
    int idT[] = {5000, 5001, 5002, 5003};
    char descripcionT[][20] = {"Gamer","Disenio","Ultrabook","Normalita"};

    int idM [] = {1000, 1001, 1002, 1003};
    char descripcionM[][20]= {"Compaq","Asus","Acer","HP"};

    int idS [] = {20000, 20001, 20002, 20003};
    char descripcionS[][25] = {"Bateria","Antivirus","Actualizacion","Fuente"};
    int precioS[] = {250, 300, 400, 600};

    char sexosC[] = {'M', 'M','F','F'};
    char nombresC[][20] = {"Luciano", "Christian", "Yanina", "Lucia"};
    int idC []= {700, 701, 702, 703};

    char nombreV[][20]={"Caralos","Marcos","Fernando","Pablo"};
    int horasTrabajadas[] ={50, 24, 120, 110};
    int idE[] = {10, 11, 12, 13};
    int sueldoVE[] = {50000, 20000, 30000, 15000};

    for(int i =0; i<tammaster; i++)
    {
        strcpy(unTipo[i].descripcionTipo, descripcionT[i]);
        unTipo[i].id = idT[i];

        strcpy(unaMarca[i].descripcionMarca, descripcionM[i]);
        unaMarca[i].id = idM[i];

        unServicio[i].id = idS[i];
        strcpy(unServicio[i].descripcion, descripcionS[i]);
        unServicio[i].precio = precioS[i];

        unCliente[i].sexos = sexosC[i];
        strcpy(unCliente[i].nombres , nombresC[i]);
        unCliente[i].id = idC[i];

        unVendedor[i].id = idE[i];
        strcpy(unVendedor[i].nombres, nombreV[i]);
        unVendedor[i].horasTrabajadas= horasTrabajadas[i];
        unVendedor[i].sueldo = sueldoVE[i];
    }

}

void hardcodearNotebooks(eNotebook lista[], int tam)
{
    int idT[] = {5000, 5001, 5001, 5003};
    int idM [] = {1000, 1000, 1000, 1001};
  //  int idS [] = {20000, 20001, 20002, 20003};
    int precioS[] = {15000, 10000, 5010, 60000};
    int ids[] = {1, 2, 3, 4};

    char marcas[][20] = {"XRL", "MFULL", "APPEL", "KKJPR"};
    int idC []= {700, 701, 702, 703};
    int idE[]={10, 10, 12, 13};

    for(int i =0; i<tam; i++)
    {
        lista[i].idTipo = idT[i];
        lista[i].idMarca = idM[i];
        lista[i].idCliente = idC[i];
        lista[i].precio = precioS[i];
        lista[i].id = ids[i];
        strcpy(lista[i].modelo, marcas[i]);
        lista[i].idVendedor = idE[i];
        lista[i].isEmpty = 0;
    }

}
void inicializarNoteboocks(eNotebook lista[], int tam)
{

    for(int i =0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}
int altaNotebooks(eNotebook lista[], int tam,eMarca listaM[], eTipo listaT[], int tammaster,eCliente listaC[],eVendedor listaVE[])
{
    int idx;
    int auxidMarca;
    int auxidTipo;
    int indice;
    int confirmo = 0;
    int indiceID;
    eNotebook auxNot;
    indice = buscarLibre(lista, tam);


    if(indice == -1)
    {
        printf("Sistema completo\n");
        system("pause");
    }
    else
    {
        idx =getId();

        indiceID = buscarNotebook(idx, lista, tam);
        if(indiceID ==-1)
        {
            auxNot.id = idx;
            getnombre("Ingres Modelo: ","Error. Solo se pueden ingresar letras: ", auxNot.modelo);
            auxNot.precio =getPrecio();

            mostrarMarcas(listaM, tammaster);
            printf("\n");
            auxidMarca = getIdMarca();

            mostrarTipos(listaT, tammaster);
            printf("\n");
            auxidTipo = getIdTipo();

            mostrarClientes(listaC, tammaster);
            printf("\n");
            auxNot.idCliente = getIdCliente();

            mostrarVendedores(listaVE, tammaster);
            printf("\n");
            auxNot.idVendedor = getIdVendedor();

            auxNot.idTipo =auxidTipo;
            auxNot.idMarca = auxidMarca;
            auxNot.isEmpty=0;
            lista[indice] = auxNot;
            confirmo = 1;
        }
        else
        {
            printf("Esa id ya fue introducido\n");
            system("pause");
        }
    }
    return confirmo;
}

int buscarLibre(eNotebook lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarNotebook(int id, eNotebook lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void bajaNotebook(eNotebook lista[], int tam, eMarca listaM[], eTipo listaT[], int tammaster,eCliente listaC[], eVendedor listaVE[])
{
    int id;
    int indice;
    char confirmacion;
    mostrarNotebooks(lista,tam, listaM, listaT, tammaster, listaC, listaVE);
    id = getInt("\nIngrese legajo: ", "Error. Ingrese numeros: ");

    indice = buscarNotebook(id, lista, tam);

    if(indice == -1)
    {
        printf("No hay registro de ningun empleado con ese legajo \n");
    }
    else
    {
        confirmacion = getLetra("Quiere elminar al usuario? S/N: ","Error. Ingrese lo indicado S/N");

        if(confirmacion == 's' || 'S')
        {
            lista[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito \n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion \n\n");
            system("pause");
        }
    }
}

void modificarNotebook(eNotebook lista[], int tam, eMarca listaM[], eTipo listaT[], int tammaster,eCliente listaC[],eVendedor listaVE[])
{
    int id;
    int opcion;
    int indice;
    int auxPrecio;
    int auxTipo;

    char follow = 's';

    mostrarNotebooks(lista, tam, listaM, listaT, tammaster, listaC, listaVE);
    printf("\n");
    id = getInt("\nIngrese ID: ", "Error. Ingrese numeros: ");
    indice = buscarNotebook(id, lista, tam);

    if(indice == -1)
    {
        printf("No hay registro de ningun empleado con ese ID\n");
        system("pause");
    }
    else
    {
        do
        {
            opcion = getInt("Elija lo que quiera modificar: \n1.Precio\n2.Tipo\n3.Salida \n:.","Opcion Erronea, ingrese numeros: ");
            switch(opcion)
            {
            case 1:
                system("cls");
                auxPrecio= getInt("Ingrese el nuevo precio: ","Error. Solo ingrese numeros: ");
                lista[indice].precio = auxPrecio;
                break;
            case 2:
                system("cls");
                mostrarTipos(listaT, tammaster);
                auxTipo = getIdTipo();
                lista[indice].idTipo = auxTipo;
                break;
            case 3:
                follow = 'n';
                break;
            default:
                opcion = getInt("Ingrese una opcion correcta: ","Solo numeros: ");
                break;
            }
        }
        while(follow == 's');
    }
}

void mostrarNotebook(eNotebook lista, eMarca listaM[],eTipo listaT[], int tammaster,eCliente listaC[], eVendedor listaVE[])
{
    char Tipodes[20];
    char Marcades[20];
    char nombreClientes[20];

    char nombreVendedor[20];
    int horasTrabajadas;
    int sueldoVe;

    cargarDescripcionMarca(Marcades, lista.idMarca, listaM,tammaster);
    cargarDescripcionTipo(Tipodes, lista.idTipo, listaT, tammaster);
    cargarNombreCliente(nombreClientes, lista.idCliente,listaC , tammaster);
    cargarDescripcionVendedor(&sueldoVe,nombreVendedor, &horasTrabajadas, lista.idVendedor,listaVE , tammaster);

    printf("\n%d %10s %10s %13s %10s %10d %15s %15d %20d",lista.id, lista.modelo, Marcades, Tipodes,nombreClientes, lista.precio, nombreVendedor, horasTrabajadas, sueldoVe);
}

void mostrarNotebooks(eNotebook lista[], int tam, eMarca listaM[],eTipo listaT[], int tammaster,eCliente listaC[], eVendedor listaVE[])
{
    int flag;
    printf("%s %10s %10s %10s %10s %15s %14s %20s %13s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Vendedor","Horas Trabajadas", "Sueldo");

    for(int i =0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarNotebook(lista[i],listaM,listaT,tammaster, listaC, listaVE);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay trabajos que mostrar");
    }
}

int cargarModeloNotebook(char modelos[],int* precios,int id, eNotebook lista[], int tam)
{
    int todoOk= 0;
    for(int i =0; i<tam; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(modelos, lista[i].modelo);
            *precios = lista[i].precio;
            todoOk = 1;
        }
    }
    return todoOk;
}
void ordernarNotebooksPorMarcaYPrecio(eNotebook listaN[], int tam)
{
    eNotebook Aux;
    for(int i =0; i<tam-1; i++)
    {
        for(int j= i+1; j< tam; j++)
            if(listaN[i].precio > listaN[j].precio)
            {
                Aux = listaN[i];
                listaN[i]= listaN[j];
                listaN[j]= Aux;
            }else if(listaN[i].precio == listaN[j].precio && listaN[i].idMarca > listaN[j].idMarca)
            {
                Aux = listaN[i];
                listaN[i]= listaN[j];
                listaN[j] = Aux;
            }
    }

}
