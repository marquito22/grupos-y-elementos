#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

struct ElementoE;
typedef struct ElementoE * Elemento;

///CONSTRUCTORES
Elemento crearElemento(char nom[20],int id ,int cant);
Elemento crearElementoPorTeclado();
Elemento crearElementoVacio();

///MOSTRAR ELEMENTO
void mostrarElemento(Elemento e);

///SETTERS
void setNombre(Elemento e, char nuevoNombre[20]);
void setId(Elemento e, int nuevoId);
void setcantidad(Elemento e,int nuevaCantidad);
///GETTERS
char * getNombre(Elemento e);
int getId(Elemento e);
int getCantidad(Elemento e);

///ESCRIBIR ELEMENTO
 void escribirElemento(Elemento e[]);

 ///DESTRUCTOR
 void destruirElemento(Elemento e);

#endif // ELEMENTO_H_INCLUDED
