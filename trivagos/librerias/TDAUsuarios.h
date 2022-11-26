#ifndef TDAUSUARIOS_H_INCLUDED
#define TDAUSUARIOS_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include "estructuras.h"

nodoUsuario* inicListaUsuarios();
nodoUsuario* crearNodoUsuario(stUsuario datoUsuario);
nodoUsuario* agregarNodoPpioUsuarios(nodoUsuario* listaUsuarios, nodoUsuario* nuevoNodo);

#endif // TDAUSUARIOS_H_INCLUDED
