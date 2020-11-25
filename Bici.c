#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Bici.h"


eBici* bici_New()
{
    eBici* pBici;
    pBici = (eBici*) malloc(sizeof(eBici));

return pBici;
}

void borrarBicis(eBici* this)
{
    if(this != NULL)
        {
            free(this);
        }
}

eBici* bici_NewParametros(char* id_bici, char* nombre, char* tipo, char* tiempo)
{
    eBici* pBici = NULL;
	pBici = bici_New();

	if(id_bici != NULL && nombre != NULL && tipo != NULL && tiempo != NULL)
	{

		if(bici_SetId(pBici, atoi(id_bici)) == -1 || bici_SetNombre(pBici, nombre) == -1 || bici_SetTipo(pBici, tipo) == -1 || bici_SetTiempo(pBici, atoi(tiempo)) == -1)
            {
                borrarBicis(pBici);
                pBici = NULL;
            }
            else
            {
                bici_SetId(pBici, atoi(id_bici));
                bici_SetNombre(pBici, nombre);
                bici_SetTipo(pBici, tipo);
                bici_SetTiempo(pBici, atoi(tiempo));
            }
	}
return pBici;
}

int bici_SetId(eBici* this, int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
        {
            this->id_bici = id;
            retorno = 1;
        }
return retorno;
}

int bici_GetId(eBici* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
        {
            *id = this->id_bici;
            retorno = 1;
        }

return retorno;
}

int bici_SetNombre(eBici* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
return retorno;
}

int bici_GetNombre(eBici* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

int bici_SetTipo(eBici* this, char* tipo)
{
    int retorno = 0;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo);
        retorno = 1;
    }
    return retorno;
}

int bici_GetTipo(eBici* this, char* tipo)
{
    int retorno = 0;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        retorno = 1;
    }

    return retorno;
}

int bici_SetTiempo(eBici* this, int tiempo)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->tiempo = tiempo;
        retorno = 1;
    }

    return retorno;
}

int bici_GetTiempo(eBici* this, int* tiempo)
{
    int retorno = 0;
    if(this != NULL)
        {
            *tiempo = this->tiempo;
            retorno = 1;
        }
return retorno;
}


int filterTipo(void* pFilter, char* temp)
{
    int retorno= 0;


    if(pFilter!=NULL)
    {
        eBici* pBici = (eBici*)pFilter;

        if(strcmp(pBici->tipo, temp)==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int listarBicis(LinkedList* listaBicis)
{
    eBici* pBici;
    int retorno = 0;

    int auxId;
    char auxNombre[100];
    char auxTipo[100];
    int auxTiempo;

    int tamLista;
    int i;

    tamLista= ll_len(listaBicis);

    if(listaBicis != NULL)
    {

        if(tamLista>0)
        {
            printf(" Id          Nombre         Tipo      Tiempo\n");

            for(i = 0; i < tamLista; i++)
            {
                pBici = (eBici*)ll_get(listaBicis, i);

                bici_GetId(pBici, &auxId);
                bici_GetNombre(pBici, auxNombre);
                bici_GetTipo(pBici, auxTipo);
                bici_GetTiempo(pBici, &auxTiempo);

                printf("%2d  %15s   %12s  %8d\n",auxId, auxNombre, auxTipo, auxTiempo);
            }
            retorno = 1;
        }
    }
return retorno;
}


int ordenarPorTipoXTiempo(void* tipo1, void* tipo2)
{
    int retorno=0;

    int compararPorTipo;

    eBici* a1;
    eBici* a2;

    if(tipo1!=NULL && tipo2!=NULL)
    {
        a1=(eBici*)tipo1;
        a2=(eBici*)tipo2;

        compararPorTipo=strcmp(a1->tipo,a2->tipo);

        if(compararPorTipo!=0)
        {
            retorno=compararPorTipo;
        }
        else if(compararPorTipo==0 && a1->tiempo<a2->tiempo)
        {
            retorno=-1;
        }
        else if(compararPorTipo==0 && a1->tiempo>a2->tiempo)
        {
            retorno=1;
        }
    }

    return retorno;
}

