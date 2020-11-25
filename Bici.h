#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id_bici;
    char nombre[100];
    char tipo[100];
    int tiempo;

}eBici;

#endif // PAIS_H_INCLUDED

eBici* bici_New();
eBici* bici_NewParametros(char* id_bici, char* nombre, char* tipo, char* tiempo);

void borrarBicis(eBici* this);

int bici_SetId(eBici* this, int id);
int bici_SetNombre(eBici* this, char* nombre);
int bici_SetTipo(eBici* this, char* tipo);
int bici_SetTiempo(eBici* this, int tiempo);

int bici_GetId(eBici* this, int* id);
int bici_GetNombre(eBici* this, char* nombre);
int bici_GetTipo(eBici* this, char* tipo);
int bici_GetTiempo(eBici* this, int* tiempo);

int listarBicis(LinkedList* listaBicis);

int datosRandom(void* a);

int filterTipo(void* pFilter, char* temp);


int ordenarPorTipoXTiempo(void* tipo1, void* tipo2);

