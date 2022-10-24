#include <stdio.h>
#include <stdlib.h>
#include "grupo.h"
#include "elemento.h"
#include <string.h>
#define CANTIDAD_ELEMNTOS 10

///DEFINIMOS LOS COMPONENTES QUE ALMACENARA EL STRUCT
struct GrupoE{
    char nombre[20];
    int id;
    Elemento elementos[CANTIDAD_ELEMNTOS];

};

///CONSTRUCTOR
Grupo crearGrupo(char nombre[20],int id){
    Grupo g = malloc(sizeof(struct GrupoE));

    strcpy(g->nombre,nombre);
    g->id=id;

    for (int i=0;i<CANTIDAD_ELEMNTOS;i++){
        g->elementos[i]=crearElementoVacio();
    }
    return g;
};

Grupo crearGrupoPorTeclado(){
    char nomAux[20];
    int idAux;
    printf("Ingrese el nombre del grupo\n");
    fflush(stdin);
    gets(nomAux);
    printf("Ingrese el ID del grupo\n");
    scanf("%d",&idAux);

    return crearGrupo(nomAux,idAux);
};

///AGREGAR ELEMENTOS
int buscarPosVacia(Grupo g){
    int posVacia;

    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        if(getCantidad(g->elementos[i])== -1){
            posVacia=i;
            i=CANTIDAD_ELEMNTOS+1;
        }

    }

    return posVacia;
}

void agregarElementos(Grupo g,int cantidad){
    int posVacia=buscarPosVacia(g);
        if(posVacia != -1){
            for(int i=0;i<cantidad;i++){
                int posVacia=buscarPosVacia(g);
                if(posVacia != -1){
                g->elementos[posVacia]=crearElementoPorTeclado();
            }
        }
    }
}

///MOSTRAR GRUPO Y SUS ELEMENTOS
void mostrarGrupo(Grupo g){

    printf("\n---DATOS DEL GRUPO\n");
    printf("    -Nombre de grupo: %s\n",g->nombre);
    printf("    -ID del grupo: %d\n",g->id);

    printf("---DATOS DE LOS ELEMEMTOS\n");
    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        mostrarElemento(g->elementos[i]);
    }
};

 ///MODIFICAR EL ID Y CANTIDAD DE UN ELEMENTO
void modificarElemento(Grupo g, char nombreElemento[20]){

    int encontrado=-1;
    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        if(strcmp (getNombre(g->elementos[i]),nombreElemento)== 0){
            int idAux;
            int cantAux;
            printf("Ingrese el nuevo ID para %s\n",nombreElemento);
            scanf("%d",&idAux);
            printf("Ingrese la nueva cantidad para %s\n",nombreElemento);
            scanf("%d",&cantAux);

            setcantidad(g->elementos[i],cantAux);
            setId(g->elementos[i],idAux);

            encontrado=i;
            i=CANTIDAD_ELEMNTOS+1;

        }
    }
    if(encontrado == -1){
        printf("\n ----ELEMENTO NO ENCONTRADO----\n");
    }

}

///ELIMINAR UN ELEMENTO MEDIANTE SU NOMBRE
void eliminarElemento(Grupo g, char nombreElemento[20]){

    int encontrado=-1;

    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        if(strcmp (getNombre(g->elementos[i]),nombreElemento)== 0){
            setNombre(g->elementos[i],"VACIO");
            setcantidad(g->elementos[i],-1);
            setId(g->elementos[i],-1);

            encontrado=i;
            i=CANTIDAD_ELEMNTOS+1;

        }
    }
    if(encontrado == -1){
        printf("\n----NO SE PUDO ELIMINAR EL ELEMENTO----\n");
    }

}

///ORDENAMOS LOS ELEMENTOS DE MENOR A MAYOR
void ordenarElementosPorID(Grupo g){
    Elemento aux;
    for(int i=0;i<CANTIDAD_ELEMNTOS;i++){
        for(int j=0;j<CANTIDAD_ELEMNTOS - 1 ;j++){
            if( getId(g->elementos[j]) > getId(g->elementos[j+1]) ){
                aux=g->elementos[j];
                g->elementos[j]=g->elementos[j+1];
                g->elementos[j+1]=aux;
            }

        }
    }

};

///GUARDAMOS EL GRUPOS CON SUS CORRESPONDIENTES ELEMENTOS EN UN ARCHIVO
void guardarGruposYElementos(Grupo g){

    FILE * archivoGrupo = fopen("grupo.txt","w");
    if(g->id != -1){
        fprintf(archivoGrupo, "%s+%d\n",g->nombre,g->id);
        escribirElemento(g->elementos);
    }
    fclose(archivoGrupo);

}

///DESTRUCTOR
void destruirGrupo(Grupo g){

    for (int i=0;i<CANTIDAD_ELEMNTOS;i++){
        destruirElemento(g->elementos[i]);
    }
    free(g);
};


