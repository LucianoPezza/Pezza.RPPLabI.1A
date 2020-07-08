#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marca.h"
#include "Validaciones.h"

int cargarDescripcionMarca(char descripcion[],int id,eMarca lista[], int tammaster)
{
    int todoOk= 0;
    for(int i =0; i<tammaster; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(descripcion, lista[i].descripcionMarca);
            todoOk = 1;
        }
    }
    return todoOk;
}
void mostrarMarcas(eMarca lista[], int tammaster)
{
    printf("%s %10s", "ID", "MARCAS");
    for(int i = 0; i<tammaster; i++)
    {
        printf("\n%d %8s ", lista[i].id, lista[i].descripcionMarca);
    }
}
void mostrarMarca(eMarca lista)
{
    printf("\n%d %8s ", lista.id, lista.descripcionMarca);
}

void InicializarMarcaMasElejida(eMarcaElejida listaME[],int tammaster)
{
    for(int i=0; i<tammaster; i++)
    {
        listaME[i].isEmpty = 0;
    }
}
/*
void buscarMarcaMasElejida(int id,eMarcaElejida listaMe[], int tammaster)
{
    int indice = -1;

    for(int i=0; i < tammaster; i++)
    {
        if(listaMe[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}*/
int encontrarMarca(int id, eMarca listaM[], int tammaster)
{
    int ret = -1;

    for(int i=0; i<tammaster; i++)
    {
        if(listaM[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
