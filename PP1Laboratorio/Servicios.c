#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Servicios.h"

void listarServicios(eServicio lista[], int tammaster)
{
    printf("%s %20s %10s", "ID", "Servicio", "Precios");
    for(int i = 0; i<tammaster; i++)
    {
        listarServicio(lista[i]);
    }
}
void listarServicio(eServicio lista)
{
    printf("\n%d %15s %10d", lista.id, lista.descripcion, lista.precio);
}
int cargarDescripcionServicio(char descripcionS[], int id, eServicio listaS[], int tam)
{
    int todoOk = 0;
    for(int i= 0; i<tam; i++)
    {
        if(listaS[i].id == id)
        {
            strcpy(descripcionS, listaS[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}
int cargarPrecioServicio(int* precios, int id, eServicio lista[], int tam)
{
    int todoOk = 0;
    for(int i= 0; i<tam; i++)
    {
        if(lista[i].id == id)
        {
            *precios = lista[i].precio;
            todoOk = 1;
        }
    }
    return todoOk;
}
