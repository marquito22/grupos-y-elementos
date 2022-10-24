#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include <string.h>
#define CANTIDAD_ELEMNTOS 10

struct ElementoE{
    char nombre[20];
    int id;
    int cantidad;
};

///CONSTRUCTORES
Elemento crearElemento(char nom[20],int id ,int cant){
    Elemento e = malloc(sizeof(struct ElementoE));

    strcpy(e->nombre,nom);
    e->id=id;
    e->cantidad=cant;

    return e;
};
Elemento crearElementoVacio(){

    return crearElemento("VACIO",-1,-1);
};

Elemento crearElementoPorTeclado(){
    char nomAux[20];
    int idAux;
    int cantAux;

    printf("Ingrese el nombre del elemento\n");
    fflush(stdin);
    gets(nomAux);
    printf("Ingrese el ID del elemento\n");
    scanf("%d",&idAux);
    printf("Ingrese la cantidad elemento\n");
    scanf("%d",&cantAux);

    return crearElemento(nomAux,idAux,cantAux);

};

///MOSTRAR ELEMENTO
void mostrarElemento(Elemento e){
    if(e->cantidad != -1){
    printf("    - Nombre: %s --- ID: %d --- Cantidad: %d\n",e->nombre,e->id,e->cantidad);
    }
}

///ESCRIBIR ELEMENTO
 void escribirElemento(Elemento e[]){
    FILE * archivo=fopen("elemento.txt","w");

    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        if(e[i]->cantidad != -1){
            fprintf(archivo,"%s+%d+%d\n",e[i]->nombre,e[i]->id,e[i]->cantidad);
        }

    }
    fclose(archivo);
 }

///DESTRUCTOR
 void destruirElemento(Elemento e){
 free(e);
 }

///SETTERS
void setNombre(Elemento e, char nuevoNombre[20]){
    strcpy(e->nombre,nuevoNombre);
};
void setId(Elemento e, int nuevoId){
    e->id=nuevoId;
};
void setcantidad(Elemento e,int nuevaCantidad){
    e->cantidad=nuevaCantidad;
};

///Getters
char * getNombre(Elemento e){
    return e->nombre;
};
int getId(Elemento e){
    return e->id;
};
int getCantidad(Elemento e){
    return e->cantidad;
};

