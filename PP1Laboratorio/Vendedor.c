#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Vendedor.h"

void mostrarVendedor(eVendedor unVendedor)
{
    printf("\n%d %10s %10d %10d",unVendedor.id, unVendedor.nombres, unVendedor.horasTrabajadas, unVendedor.sueldo);
}

void mostrarVendedores(eVendedor unVendedor[], int tammaster)
{
    printf("%s %10s %10s %10s", "ID", "Vendedor", "Horas Trabajadas", "Sueldo");

    for(int i = 0; i<tammaster; i++)
    {
        mostrarVendedor(unVendedor[i]);
    }
}

int cargarDescripcionVendedor(int* sueldo,char nombre[],int* horasTrabajadas,int id, eVendedor unVendedor[], int tammaster)
{
   int todoOk= 0;
    for(int i =0; i<tammaster; i++)
    {
        if(unVendedor[i].id == id)
        {
            strcpy(nombre, unVendedor[i].nombres);
            *horasTrabajadas = unVendedor[i].horasTrabajadas;
            *sueldo = unVendedor[i].sueldo;
            todoOk = 1;
        }
    }
    return todoOk;
}
