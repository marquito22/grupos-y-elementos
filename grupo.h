#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
struct GrupoE;
typedef struct GrupoE * Grupo;

///CONSTRUCTOR
Grupo crearGrupo(char nombre[20],int id);
Grupo crearGrupoPorTeclado();

///MOSTRAR GRUPO
void mostrarGrupo(Grupo g);

//void iniciarElementosEnGrupo(Grupo g);

///AGREGAR ELEMENTOS
void agregarElementos(Grupo g,int cantidad);

///MODIFICAR ELEMENTO
void modificarElemento(Grupo g, char nombreElemento[20]);

///ELIMINAR ELEMENTO
void eliminarElemento(Grupo g, char nombreElemento[20]);

///ORDENAR ELEMENTOS
void ordenarElementosPorID(Grupo g);

///ESCRIBIR EN UN ARCHIVO GRUPO Y ELEMENTO
void guardarGruposYElementos(Grupo g);

///DESTRUCTOR
void destruirGrupo(Grupo g);

#endif // GRUPO_H_INCLUDED
