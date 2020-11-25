#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Bici.h"
#include "parcer.h"

int main()
{
    int opcion = 0;
    char salir[3];
    char rta;

    int opcionBici;

    LinkedList* listaPrincipal = ll_newLinkedList();
    LinkedList* listaOrdenada= NULL;
    LinkedList* listaMap = NULL;
    LinkedList* listaTipo = NULL;
    do
    {   strcpy(salir,"no");

        getInt("\MENU\n 1) Cargar archivo bici.csv (modo texto)\n2) Imprimir lista\n3) Asignar tiempos\n4) Filtrar por tipo\n5) Mostrar posiciones \n6) Guardar posiciones\n7) Salir\n","Error\n", 1, 3, 0, &opcion);

        printf("\n\n");
        switch(opcion)
        {
        case 1:
                if(cargarTexto("bicicletas.csv", listaPrincipal) == 0)
                    {
                        printf("Archivo cargado con exito\n");
                    }
                else
                    {
                        printf("ERROR");
                    }


            system("pause");
            break;
        case 2:
                if(listarBicis(listaPrincipal))
                    {
                        printf("Lista cargada con exito\n");
                    }
                else
                    {
                        printf("ERROR");
                    }

            system("pause");
            break;
        case 3:

            listaMap = ll_map(listaPrincipal, datosRandom);
            listarBicis(listaMap);
            system("pause");

            break;
        case 4:
            getInt("- Elija opcion\n1. PASEO\n2. PLAYERA\n3. MTB\n4. BMX\n>","Error, escriba un numero del 1 al 4", 1,4,4, &opcionBici);

            char temp[20];

            switch(opcionBici)
            {
                case 1:
                    strcpy(temp,"PASEO");
                break;
                case 2:
                    strcpy(temp,"PLAYERA");
                break;
                case 3:
                    strcpy(temp, "MTB");
                break;
                case 4:
                    strcpy(temp, "BMX");
                break;
            }

            listaTipo= ll_filter_parametro(listaPrincipal, filterTipo, temp);


            guardarComoTexto("bicicletasPorTipo.csv", listaTipo);

            system("pause");
            break;
        case 5:
            listaOrdenada= ll_clone(listaPrincipal);

            if(listaOrdenada!=NULL)
            {
                ll_sort(listaOrdenada, ordenarPorTipoXTiempo, 1);
            }
            listarBicis(listaOrdenada);
            system("pause");
            break;
        case 6:

            break;
        case 7:
            printf("Los datos no seran guardados\n Seguro que desea salir? ");
            fflush(stdin);
            scanf("%c", &rta);
            while(rta != 's' && rta != 'n')
            {
                printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                printf(" s/n : \n");
                fflush(stdin);
                scanf("%c", &rta);
            }

            if(rta == 's')
            {
                printf("Hasta luego!!!\n");
                return 0;
            }

            system("pause");
            break;;
        default:
            printf("Opcion incorrecta. Reingrese\n");
            system("pause");
        }

        system("cls");
    }
    while(strcmp(salir,"si")!= 0);

    ll_deleteLinkedList(listaMap);
    ll_deleteLinkedList(listaOrdenada);
    ll_deleteLinkedList(listaPrincipal);
    ll_deleteLinkedList(listaTipo);
    return 0;
}

