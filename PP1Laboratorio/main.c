#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"
#include "Vendedor.h"

#define TAM 10
#define HARDCODEADOS 4

int main()
{
    int opcion;
    char seguis = 's';
    char opcionInformes;
    int idtrabajo= 100;
    int flag = 0;
    int flag2 =0;

    eNotebook unaNotebook[TAM];
    eNotebook unaNotebookSola;
    eTipo unTipo[HARDCODEADOS];
    eMarca unaMarca[HARDCODEADOS];
    eServicio unServicio[HARDCODEADOS];
    eCliente unCliente [HARDCODEADOS];
    eTrabajo unTrabajo[TAM];
    eMarcaElejida unaMarcaElejida[HARDCODEADOS];
    eVendedor unVendedor[HARDCODEADOS];


    inicializarNoteboocks(unaNotebook, TAM);
    incializarTrabajos(unTrabajo, TAM);
    //InicializarMarcaMasElejida(unaMarcaElejida, HARDCODEADOS);
    hardcodearMarcaTipoYServicios(unTipo, unaMarca, HARDCODEADOS, unServicio, unCliente, unVendedor);
    hardcodearNotebooks(unaNotebook, HARDCODEADOS);
    hardcodearTrabajos(unTrabajo, HARDCODEADOS);

    do
    {
        printf("********************Primer Parcial********************\n");
        opcion = getInt("Ingrese una opcion \n1.Alta\n2.Modificacion\n3.Baja\n4.Listar Notebooks\n5.Listar Vendedor\n6.Listar Marcas\n7.Listar Tipos\n8.Listar Servicios\n9.Alta Trabajo\n10.Listar trabajos\n11.Listar Clientes\n12.Informes\n13.Salir.\nElija:","Ingrese solo numeros: ");
        switch(opcion)
        {
        case 1:
            if(flag == 0 || flag ==1)
            {
                system("cls");
                altaNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS, unCliente, unVendedor);
                flag =1;
            }
            break;
        case 2:
            if(flag ==1)
            {
                system("cls");
                modificarNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente, unVendedor);
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 3:
            if(flag ==1)
            {
                system("cls");
                bajaNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente, unVendedor);
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 4:
            //    if(flag ==1)
            //  {
            system("cls");
            ordernarNotebooksPorMarcaYPrecio(unaNotebook, TAM);
            mostrarNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente, unVendedor);
            printf(" \n\n");
            system("pause");
            //}
            //else
            //{
            //printf("Primero tiene quedar de alta\n");
            //  system("pause");
            //}
            break;
        case 5:
            system("cls");
            mostrarVendedores(unVendedor,HARDCODEADOS);
            printf("\n");
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarMarcas(unaMarca,HARDCODEADOS);
            printf("\n");
            system("pause");
            break;
        case 7:
            system("cls");
            mostrarTipos(unTipo, HARDCODEADOS);
            printf(" \n\n");
            system("pause");
            break;
        case 8:
            system("cls");
            listarServicios(unServicio, HARDCODEADOS);
            printf(" \n\n");
            system("pause");
            break;
        case 9:
            if((flag2 == 0 || flag2 == 1)&& flag == 1)
            {
                if(altaTrabajos(idtrabajo, unTrabajo, TAM,HARDCODEADOS, unaNotebook, unServicio, unaMarca, unTipo, unCliente, unVendedor))
                {
                    idtrabajo++;
                }
                flag2 =1;
            }
            else
            {
                printf("Primero debe dar de alta 1 notebook, con su respectivo id");
            }
            break;
        case 10:

            system("cls");
            mostrarTrabajos(unTrabajo, TAM, HARDCODEADOS, unaNotebook, unServicio);
            printf("\n");
            system("pause");
            break;
        case 11:
            system("cls");
            mostrarClientes(unCliente, HARDCODEADOS);
            printf(" \n\n");
            system("pause");
            break;
        case 12:
            system("cls");
            opcionInformes = getLetra("Ingrese El informe que quiera \na.Mostrar las notebooks del tipo seleccionado por el usuario\nb.Mostrar Notebooks de una marca seleccionada\nc.Mostrar la o las notebooks mas baratas\nd.Mostrar notebooks separadas por marca\ne.Elejir tipo y marca y contar cuantas Notebooks hay\nf.Mostrar la o las marcas mas elegidas por los clientes\ng.pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma\nh pedir una notebook y mostrar el total de importe de los servicios\ni.pedir un servicio y mostrar las notebooks del ese servicio y la fecha\nj.pedir una fecha y mostrar todos los servicios realizados en la misma \nk. pedir una notebook y mostrar sus vendedores\nl Mostrar El vendedor con mas horas trabajadas\nm.sumarle precio a las notebook\nn.mostrar promedio de sueldos de vendedores\no mostar proemdio de servicios.\np. sumarle precio al os servicios\nElija: ","Error. solo letras: ");
            switch(opcionInformes)
            {
            case 'a':
                system("cls");
                MostrarNotebooksDelTipoSeleccionadoPorElUsuario(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unVendedor);
                printf("\n\n");
                system("pause");
                break;
            case 'b':
                system("cls");
                mostrarNotebooksDeUnaMarcaSeleccionada(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unVendedor);
                printf("\n\n");
                system("pause");
                break;
            case 'c':
                system("cls");
                mostrarNotebooksMasBaratas(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                system("pause");
                break;
            case 'd':
                system("cls");
                mostrarNotebooksSeparadasPorMarca(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unVendedor);
                printf("\n\n");
                system("pause");
                break;
            case 'e':
                system("cls");
                elejirTipoYMarcaYContarNotebooks(unaNotebookSola,unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                printf("\n\n");
                system("pause");
                break;
            case 'f':
                mostrarLasMarcasElejidasPorClientes(unaNotebookSola,unaNotebook, unTipo, unaMarca, unCliente,unaMarcaElejida, TAM, HARDCODEADOS);
                system("cls");

                system("pause");
                break;
            case 'g':
                pedirUnaNotebookYMostrarTodosLosTrabajosQueSeLeHicieronALaMisma(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'h':
                pedirUnaNotebookYMostrarElTotalDeImportaDeLosServicios(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio,unVendedor);
                system("pause");
                break;
            case 'i':
                pedirUnServicioYMostrarLasNotebooksDelEseServicioYLaFecha(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'j':
                pedirUnaFechaYMostrarTodosLosServiciosRealizadosEnLaMisma(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio);
                printf("\n");
                system("pause");
                break;
            case 'k':
                pedirUnaNotebookYMostrarSusVendedores(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'l':
                mostarSegunHorasTrabajadas(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'm':
                sumarlePrecioaLasNotebook(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'n':
                mostrarPromedioDeSueldosDeVendedores(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'o':
                mostrarPromedioDelPrecioDeLosServicios(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");
                break;
            case 'p':
                sumarlePrecioaLosservicios(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS, unTrabajo, unServicio, unVendedor);
                printf("\n");
                system("pause");

                break;
            default:
                opcionInformes = getLetra("Ingrese una opcion valida","Error. Solo letras: ");
                break;
            }
            break;
        case 13:
            seguis = 'n';
            break;
        default:
            opcion = getInt("Ingrese una opcion correcta: ", "Solo numeros: ");
            break;
        }
        system("cls");
    }
    while(seguis == 's');
    return 0;
}
