#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"
#include "Vendedor.h"

void MostrarNotebooksDelTipoSeleccionadoPorElUsuario(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eVendedor listaVE[])
{
    int idTipo;

    printf("*****Mostrar Notebooks del tipo seleccionado por el Usuario*****");

    mostrarTipos(listaT, tammaster);
    printf("\n");
    idTipo = getIdTipo();
    printf("%s %10s %10s %10s %10s %15s %14s %20s %13s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Vendedor","Horas Trabajadas", "Sueldo");

    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idTipo == idTipo)
        {
            mostrarNotebook(listaN[i], listaM, listaT, tammaster, listaC, listaVE );
        }
    }
}

void mostrarNotebooksDeUnaMarcaSeleccionada(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster,eVendedor listaVE[])
{
    int idMarca;

    printf("*****Mostrar Notebooks de las marcas seleccionadas*****");
    mostrarMarcas(listaM, tammaster);
    printf("\n");
    idMarca = getIdMarca();

    printf("%s %10s %10s %10s %10s %15s %14s %20s %13s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Vendedor","Horas Trabajadas", "Sueldo");

    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idMarca == idMarca)
        {
            mostrarNotebook(listaN[i], listaM, listaT, tammaster, listaC, listaVE);
        }
    }
}
int mostrarNotebooksMasBaratas(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    int minPrecio = 0;
    char modelos[20];
    int flag =0;

    for(int i =0; i < tam; i++ )
    {
        if(listaN[i].isEmpty == 0)
        {
            if(listaN[i].precio < minPrecio|| flag ==0)
            {
                minPrecio = listaN[i].precio;
                strcpy(modelos, listaN[i].modelo);
                flag = 1;
            }
        }
    }

    printf("Las notebooks mas baratas son: %s  y valen: %d\n", modelos, minPrecio);

    return flag;
}
void mostrarNotebooksSeparadasPorMarca(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster,eVendedor listaVE[])
{
    printf("*****Mostrar Notebooks separadas por marca*****");
    int flag = 0;
    for(int m =0; m < tammaster; m++)
    {
        flag =0;
        printf("\n\nMarca: %s", listaM[m].descripcionMarca);
        for(int n =0; n < tam; n++)
        {
            if(listaN[n].isEmpty == 0 && listaN[n].idMarca == listaM[m].id)
            {
                mostrarNotebook(listaN[n], listaM, listaT, tammaster, listaC,listaVE);
                flag =1;
            }
        }
        if(flag == 0)
        {
            printf("\n No hay empleados que mostrar");
        }
    }
}
void elejirTipoYMarcaYContarNotebooks(eNotebook unaNot,eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    int idTipo;
    int idMarca;
    int contadorMarca = 0;
    int contadorTipo = 0;
    char marcades[20];
    char tipodes[20];

    cargarDescripcionMarca(marcades, unaNot.idMarca, listaM, tammaster);
    cargarDescripcionTipo(tipodes, unaNot.idTipo, listaT, tammaster);

    printf("*****Mostrar cuantas notebooks hay en los tipos y marcas que elijamos*****\n \n");

    mostrarTipos(listaT, tammaster);
    idTipo = getIdTipo();

    printf("\n \n");

    mostrarMarcas(listaM, tammaster);
    idMarca = getIdMarca();


    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idTipo == idTipo)
        {
            contadorTipo++;
        }
        if(listaN[i].isEmpty == 0 && listaN[i].idMarca == idMarca)
        {
            contadorMarca++;
        }
    }
    printf("\n En la marca hay: %d Notebooks y el en Tipo: %d Notebooks",contadorMarca, contadorTipo);
}

void mostrarLasMarcasElejidasPorClientes(eNotebook unaNot,eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[],eMarcaElejida listaME[], int tam, int tammaster)
{
    int counter;
    int flag = 0;
    int indexMarca = 0;
    int auxMarca;
    eMarcaElejida auxMarcaElejida;


    printf("\n******************* Marca mas elejida por clientes ***************************\n\n");

    for(int c=0; c<tammaster; c++)
    {
        counter = 0;

        for(int m=0; m<tam; m++)
        {
            if(listaN[m].isEmpty == 0 && listaN[m].idMarca == listaM[c].id)
            {
                counter++;
            }
        }

        listaME[indexMarca].id = listaM[c].id;
        listaME[indexMarca].cantidad = counter;
        listaME[indexMarca].isEmpty = 0;
        indexMarca++;

    }

    for(int i=0; i<tammaster; i++)
    {
        if(flag == 0)
        {
            auxMarcaElejida = listaME[i];
            flag = 1;
        }
        else if(listaME[i].cantidad > auxMarcaElejida.cantidad && listaME[i].isEmpty == 0)
        {
            auxMarcaElejida = listaME[i];
        }
    }

    printf("Las marcas mas elegidas son: \n\n");

    for(int i=0; i<tammaster; i++)
    {
        if(auxMarcaElejida.cantidad == listaME[i].cantidad && listaME[i].isEmpty == 0)
        {
            auxMarca = encontrarMarca(listaME[i].id, listaM, tammaster);
            mostrarMarca(listaM[auxMarca]);
            system("pause");
        }
    }


}
void pedirUnaNotebookYMostrarTodosLosTrabajosQueSeLeHicieronALaMisma(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int idNotebooks;
    int indiceId;
    printf("\n********************Todos los trabajos de cada notebook***************************\n\n");

    mostrarNotebooks(listaN, tam, listaM, listaT, tammaster, listaC, listaVE);

    idNotebooks = getInt("\nIngrese el id de la notebook que desee: ","Error. Solo numeros: ");
    indiceId = identificarId(idNotebooks, listaN, tam);
    if(indiceId != -1)
    {
        printf("\n\n%s %12s %20s %15s %20s %8s","ID","NOTEBOOK","PRECIOS NOTEBOOK","SERVICIOS","PECIOS SERVICIO","FECHA");
        for(int i =0; i < tam; i++)
        {
            if(listaTR[i].isEmpty == 0 && listaTR[i].idNotebook == idNotebooks)
            {
                mostrarTrabajo(listaTR[i], listaN, listaS, tammaster, tam);
            }
        }

    }
    else
    {
        printf("No se encontro el id");
        system("pause");
    }
}
void pedirUnaNotebookYMostrarElTotalDeImportaDeLosServicios(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int idNotebooks;
    int indiceId;
    int totalPrecioServicio;
    printf("\n********************EL TOTAL DE LOS SERVICIOS DEL LAS NOTEBOOKS***************************\n\n");

    mostrarNotebooks(listaN, tam, listaM, listaT, tammaster, listaC, listaVE);

    idNotebooks = getInt("\nIngrese el id de la notebook que desee: ","Error. Solo numeros: ");
    indiceId = identificarId(idNotebooks, listaN, tam);
    if(indiceId != -1)
    {
        printf("\n\n%s %12s %20s %15s %20s %8s","ID","NOTEBOOK","PRECIOS NOTEBOOK","SERVICIOS","PECIOS SERVICIO","FECHA");
        for(int i =0; i < tam; i++)
        {
            if(listaTR[i].isEmpty == 0 && listaTR[i].idNotebook == idNotebooks)
            {
                totalPrecioServicio =+ listaN[i].precio + listaS[i].precio;
            }
        }

    }
    else
    {
        printf("No se encontro el id");
        system("pause");
    }
    printf("\n\nEl precio total de los servicios de la notebook vale: %d\n", totalPrecioServicio);
}
void pedirUnServicioYMostrarLasNotebooksDelEseServicioYLaFecha(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int idServicios;
    printf("\n********************Mostrar las notebooks de un servicio con la fecha***************************\n\n");
    listarServicios(listaS, tammaster);
    idServicios = getIdServicio();

    system("cls");
    printf("%s %10s %10s %10s %10s %15s %10s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Fecha\n");

    for(int i =0; i < tam; i++)
    {
        if(listaTR[i].isEmpty == 0 && listaTR[i].idServicio == idServicios)
        {
            mostrarNotebookConFecha(listaN[i], listaM, listaT, tammaster, listaC, listaTR[i]);
        }
    }

}
void pedirUnaFechaYMostrarTodosLosServiciosRealizadosEnLaMisma(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[])
{
    int auxDia;
    int auxMes;
    int auxAnio;
    printf("\n********************Mostrar servicios segun fecha***************************\n\n");


    mostrarTrabajos(listaTR, tammaster, tam, listaN, listaS);
    printf("\n");
    gotFecha(&auxDia, &auxMes, &auxAnio);

    system("cls");
    printf("\n\n%s %20s %10s", "ID", "Servicio", "Precios\n");
    for(int i =0; i < tam; i++)
    {
        if(listaTR[i].isEmpty == 0 && listaTR[i].unaFecha.dia == auxDia && listaTR[i].unaFecha.mes == auxMes && listaTR[i].unaFecha.anio == auxAnio)
        {
            listarServicio(listaS[i]);
        }
    }
}
void pedirUnaNotebookYMostrarSusVendedores(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int idNotebooks;
    int indiceId;
    printf("\n********************VendedorxNotebook***************************\n\n");

    mostrarNotebooks(listaN, tam, listaM, listaT, tammaster, listaC, listaVE);

    idNotebooks = getInt("\nIngrese el id de la notebook que desee: ","Error. Solo numeros: ");
    indiceId = identificarId(idNotebooks, listaN, tam);
    if(indiceId != -1)
    {
        system("cls");
        printf("El vendedos de esta notebook es:\n");
        printf("\n\n%s %10s %10s","ID","Vendedor","Horas Trabajadas");
        for(int i =0; i < tam; i++)
        {
            if(listaTR[i].isEmpty == 0 && listaN[i].isEmpty ==0 && listaTR[i].idNotebook == idNotebooks)
            {
                mostrarVendedor(listaVE[i]);
            }
        }
    }
    else
    {
        printf("No se encontro el id");
        system("pause");
    }
}

void mostarSegunHorasTrabajadas(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    printf("\n********************Vendedor dividido en horas trabajadas***************************\n\n");

    printf("Vendedores con muchas horas: ");
    for(int i =0; i < tammaster; i++)
    {
        if(listaVE[i].horasTrabajadas >100)
        {
            mostrarVendedor(listaVE[i]);
        }
    }
    printf("\n\nVendedores con la media de horas: ");
    for(int i =0; i < tammaster; i++)
    {
        if(listaVE[i].horasTrabajadas <=100 && listaVE[i].horasTrabajadas >=50)
        {
            mostrarVendedor(listaVE[i]);
        }
    }
    printf("\n\nVendedores con pocas horas: ");
    for(int i =0; i < tammaster; i++)
    {
        if(listaVE[i].horasTrabajadas < 50)
        {
            mostrarVendedor(listaVE[i]);
        }
    }

}

void sumarlePrecioaLasNotebook(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int sumador;
    int total;
    int idnotebook;
    mostrarNotebooks(listaN,tam, listaM, listaT, tammaster, listaC, listaVE);
    printf("\n");
    idnotebook = getId();

    system("cls");

    printf("%s %10s %10s %10s %10s %15s %14s %20s %13s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Vendedor","Horas Trabajadas", "Sueldo");

    for(int i =0; i < tam; i++)
    {
        if(listaTR[i].isEmpty == 0 && listaN[i].isEmpty == 0 && listaTR[i].idNotebook == idnotebook)
        {
            mostrarNotebook(listaN[i],listaM,listaT,tammaster,listaC,listaVE);

            sumador = getInt("\nIngrese el Agregado al precio: ", "Error. Solo numeros");
            listaN[i].precio += sumador;

            printf("\nEl nuevo precio es: ");
            mostrarNotebook(listaN[i],listaM,listaT,tammaster,listaC,listaVE);
        }
    }

}

void mostrarPromedioDeSueldosDeVendedores(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    printf("\n********************Vendedor dividido en horas trabajadas***************************\n\n");
    int totalsueldo = 0;
    int promedio;
    for(int i=0;i<tammaster;i++)
    {
       totalsueldo+=listaVE[i].sueldo;

    }
    promedio = totalsueldo /4;
    printf("el promedio es: %d", promedio);
}


void mostrarPromedioDelPrecioDeLosServicios(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    printf("\n********************Vendedor dividido en horas trabajadas***************************\n\n");
    int totalsueldo = 0;
    int promedio;
    for(int i=0;i<tammaster;i++)
    {
       totalsueldo+=listaS[i].precio;

    }
    promedio = totalsueldo /4;
    printf("el promedio es: %d", promedio);
}

void sumarlePrecioaLosservicios(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster, eTrabajo listaTR[], eServicio listaS[],eVendedor listaVE[])
{
    int sumador;
    int total;
    int idServicio;
    listarServicios(listaS,tammaster);
    printf("\n");
    idServicio = getIdServicio();

    system("cls");

    printf("%s %10s %10s %10s %10s %15s %14s %20s %13s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio","Vendedor","Horas Trabajadas", "Sueldo");

    for(int i =0; i < tam; i++)
    {
        if(listaTR[i].isEmpty == 0 && listaN[i].isEmpty == 0 && listaTR[i].idServicio == idServicio)
        {
            listarServicio(listaS[i]);

            sumador = getInt("\nIngrese el Agregado al precio: ", "Error. Solo numeros");
            listaN[i].precio += sumador;

            printf("\nEl nuevo precio es: ");
            listarServicio(listaS[i]);
        }
    }
}
