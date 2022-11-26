#include "TDAUsuarios.h"

nodoUsuario* inicListaUsuarios(){
    return NULL;
}

nodoUsuario* crearNodoUsuario(stUsuario datoUsuario){
    nodoUsuario*  nuevoNodo = (nodoUsuario*) malloc (sizeof(nodoUsuario));
    nuevoNodo->dato = datoUsuario;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoUsuario* agregarNodoPpioUsuarios(nodoUsuario* listaUsuarios, nodoUsuario* nuevoNodo){
    nuevoNodo->siguiente = listaUsuarios;
    if (listaUsuarios != NULL)
        listaUsuarios->anterior = nuevoNodo;
    return nuevoNodo;
}
