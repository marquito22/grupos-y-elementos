#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "grupo.h"

int main()
{
    Grupo g1=crearGrupoPorTeclado();

    agregarElementos(g1,3);

    mostrarGrupo(g1);

    ordenarElementosPorID(g1);

    mostrarGrupo(g1);

    eliminarElemento(g1,"ladrillo");

    mostrarGrupo(g1);

   // guardarGruposYElementos(g1);

    destruirGrupo(g1);



    return 0;
}
