#include "TDAHoteles.h"

nodoHospedaje* inicListaHoteles(){
    return NULL;
}

nodoFavoritos* inicListaFavoritos(){
    return NULL;
}

nodoReservas* inicListaReservas(){
    return NULL;
}

nodoListaOfListaPuntajes* inicListaOfListaPuntajes(){
    return NULL;
}

arbolFavoritos* inicArbolFavoritos(){
    return NULL;
}

arbolReservas* inicArbolReservas(){
    return NULL;
}

nodoHospedaje* crearNodoHoteles(stHospedaje datoHotel){
    nodoHospedaje*  nuevoNodo = (nodoHospedaje*) malloc (sizeof(nodoHospedaje));
    nuevoNodo->dato = datoHotel;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoFavoritos* crearNodoFavoritos(int dato){
    nodoFavoritos*  nuevoNodo = (nodoFavoritos*) malloc (sizeof(nodoFavoritos));
    nuevoNodo->idHotel = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoReservas* crearNodoReservas(stReserva dato){
    nodoReservas*  nuevoNodo = (nodoReservas*) malloc (sizeof(nodoReservas));
    nuevoNodo->dato.idHotel = dato.idHotel;
    nuevoNodo->dato.precio = dato.precio;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoVoto* crearNodoVoto(int usuario, int voto){
    nodoVoto*  nuevoNodo = (nodoVoto*) malloc (sizeof(nodoVoto));
    nuevoNodo->voto = voto;
    nuevoNodo->idUsuario = usuario;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoListaOfListaPuntajes* crearNodoPuntajes(int idHotel){
    nodoListaOfListaPuntajes*  nuevoNodo = (nodoListaOfListaPuntajes*) malloc (sizeof(nodoListaOfListaPuntajes));
    nuevoNodo->idHotel = idHotel;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->votos = NULL;
    return nuevoNodo;
}

arbolFavoritos* crearNodoArbolFavoritos(int idHotel, int esFavorito){
    arbolFavoritos*  nuevoNodo = (arbolFavoritos*) malloc (sizeof(arbolFavoritos));
    nuevoNodo->idHotel = idHotel;
    nuevoNodo->esFavorito = esFavorito;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

arbolReservas* crearNodoArbolReservas(stReserva dato, int estaReservado){
    arbolReservas*  nuevoNodo = (arbolReservas*) malloc (sizeof(arbolReservas));
    nuevoNodo->dato.idHotel = dato.idHotel;
    nuevoNodo->estaReservado = estaReservado;
    nuevoNodo->dato.precio = dato.precio;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

nodoHospedaje* agregarNodoPpioHoteles(nodoHospedaje* listaHoteles, nodoHospedaje* nuevoNodo){
    if (listaHoteles == NULL){
        listaHoteles = nuevoNodo;
    } else {
        nuevoNodo->siguiente = listaHoteles;
        listaHoteles->anterior = nuevoNodo;
        listaHoteles = nuevoNodo;
    }
    return nuevoNodo;
}

nodoFavoritos* agregarNodoPpioFavoritos(nodoFavoritos* listaFavoritos, nodoFavoritos* nuevoNodo){
    nuevoNodo->siguiente = listaFavoritos;
    return nuevoNodo;
}

nodoReservas* agregarNodoPpioReservas(nodoReservas* listaReservas, nodoReservas* nuevoNodo){
    nuevoNodo->siguiente = listaReservas;
    return nuevoNodo;
}

nodoVoto* agregarNodoPpioVotos(nodoVoto* listaVotos, nodoVoto* nuevoNodo){
    if (listaVotos == NULL){
        listaVotos = nuevoNodo;
    } else {
        nuevoNodo->siguiente = listaVotos;
        listaVotos = nuevoNodo;
    }
    return listaVotos;
}

nodoListaOfListaPuntajes* agregarNodoPpioListaOfListaPuntajes(nodoListaOfListaPuntajes* listaOfListaPuntajes, nodoListaOfListaPuntajes* nuevoNodo){
    if (listaOfListaPuntajes == NULL){
        listaOfListaPuntajes = nuevoNodo;
    } else {
        nuevoNodo->siguiente = listaOfListaPuntajes;
        listaOfListaPuntajes = nuevoNodo;
    }
    return listaOfListaPuntajes;
}

arbolFavoritos* agregarNodoArbol(arbolFavoritos* arbol, arbolFavoritos* nuevoNodo){
    arbolFavoritos* auxiliar = arbol;
    while (auxiliar != NULL){
        if (nuevoNodo->idHotel > auxiliar->idHotel){
            auxiliar = auxiliar->derecha;
        } else {
            auxiliar = auxiliar->izquierda;
        }
    }
    auxiliar = nuevoNodo;
    return arbol;
}

arbolReservas* agregarNodoArbolReservas(arbolReservas* arbol, arbolReservas* nuevoNodo){
    arbolReservas* auxiliar = arbol;
    while (auxiliar != NULL){
        if (nuevoNodo->dato.idHotel > auxiliar->dato.idHotel){
            auxiliar = auxiliar->derecha;
        } else {
            auxiliar = auxiliar->izquierda;
        }
    }
    auxiliar = nuevoNodo;
    return arbol;
}

arbolFavoritos* insertar(arbolFavoritos* arbol, arbolFavoritos* nuevoNodo){
    if(arbol==NULL)
        arbol = nuevoNodo;
    else{
        if(nuevoNodo->idHotel>arbol->idHotel)
            arbol->derecha = insertar(arbol->derecha, nuevoNodo);
        else
            arbol->izquierda = insertar(arbol->izquierda, nuevoNodo);
    }
    return arbol;
}

arbolReservas* insertarReserva(arbolReservas* arbol, arbolReservas* nuevoNodo){
    if(arbol==NULL)
        arbol = nuevoNodo;
    else{
        if(nuevoNodo->dato.idHotel>arbol->dato.idHotel)
            arbol->derecha = insertarReserva(arbol->derecha, nuevoNodo);
        else
            arbol->izquierda = insertarReserva(arbol->izquierda, nuevoNodo);
    }
    return arbol;
}

arbolFavoritos* crearArbolFavoritos(nodoHospedaje* listaHoteles, nodoFavoritos* listaFavoritos){
    arbolFavoritos* nuevoArbol = inicArbolFavoritos();
    nodoHospedaje* iterador = listaHoteles;
    while (iterador != NULL){
        arbolFavoritos* nuevoNodoArbol = crearNodoArbolFavoritos(iterador->dato.id, esHotelFavorito(iterador->dato.id, listaFavoritos));
        nuevoArbol = insertar(nuevoArbol, nuevoNodoArbol);
        iterador = iterador->siguiente;
    }

    return nuevoArbol;
}

arbolReservas* crearArbolReservas(nodoHospedaje* listaHoteles, nodoReservas* listaReservas){
    arbolReservas* nuevoArbol = inicArbolReservas();
    nodoHospedaje* iterador = listaHoteles;
    stReserva dato;
    while (iterador != NULL){
        arbolReservas* nuevoNodoArbol;
        if (esHotelReservado(iterador->dato.id, listaReservas, &dato)){
            nuevoNodoArbol = crearNodoArbolReservas(dato, 1);
        } else {
            dato.idHotel = iterador->dato.id;
            dato.precio = 0;
            nuevoNodoArbol = crearNodoArbolReservas(dato, 0);
        }
        nuevoArbol = insertarReserva(nuevoArbol, nuevoNodoArbol);
        iterador = iterador->siguiente;
    }
    return nuevoArbol;
}

int buscarFavoritoArbol(int idHotel, arbolFavoritos* favoritos){
    int esFavorito = 0;
    int hotelEncontrado = 0;
    while (favoritos != NULL && hotelEncontrado == 0){
        if (idHotel == favoritos->idHotel){
            esFavorito = favoritos->esFavorito;
            hotelEncontrado = 1;
        } else {
            if (idHotel > favoritos->idHotel){
                favoritos = favoritos->derecha;
            } else {
                favoritos = favoritos->izquierda;
            }
        }
    }
    return esFavorito;
}

int buscarReservaArbol(int idHotel, arbolReservas* reservas){
    int esReserva = 0;
    int hotelEncontrado = 0;
    while (reservas != NULL && hotelEncontrado == 0){
        if (idHotel == reservas->dato.idHotel){
            esReserva = reservas->estaReservado;
            hotelEncontrado = 1;
        } else {
            if (idHotel > reservas->dato.idHotel){
                reservas = reservas->derecha;
            } else {
                reservas = reservas->izquierda;
            }
        }
    }
    return esReserva;
}

arbolFavoritos* cambiarEstadoFavorito(arbolFavoritos* arbol, int idHotel){
    int hotelEncontrado = 0;
    arbolFavoritos* favoritos = arbol;
    while (favoritos != NULL && hotelEncontrado == 0){
        if (idHotel == favoritos->idHotel){
            if (favoritos->esFavorito == 1){
                favoritos->esFavorito = 0;
            } else {
                favoritos->esFavorito = 1;
            }
            hotelEncontrado = 1;
        } else {
            if (idHotel > favoritos->idHotel){
                favoritos = favoritos->derecha;
            } else {
                favoritos = favoritos->izquierda;
            }
        }
    }
    return arbol;
}

arbolReservas* cambiarEstadoReserva(arbolReservas* arbol, int idHotel){
    int hotelEncontrado = 0;
    arbolReservas* reservas = arbol;
    while (reservas != NULL && hotelEncontrado == 0){
        if (idHotel == reservas->dato.idHotel){
            if (reservas->estaReservado == 1){
                reservas->estaReservado = 0;
            } else {
                reservas->estaReservado = 1;
            }
            hotelEncontrado = 1;
        } else {
            if (idHotel > reservas->dato.idHotel){
                reservas = reservas->derecha;
            } else {
                reservas = reservas->izquierda;
            }
        }
    }
    return arbol;
}

