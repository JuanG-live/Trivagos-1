#ifndef TDAHOTELES_H_INCLUDED
#define TDAHOTELES_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include "estructuras.h"

nodoHospedaje* inicListaHoteles();
nodoFavoritos* inicListaFavoritos();
nodoReservas* inicListaReservas();
nodoListaOfListaPuntajes* inicListaOfListaPuntajes();
arbolFavoritos* inicArbolFavoritos();
arbolReservas* inicArbolReservas();
nodoHospedaje* crearNodoHoteles(stHospedaje datoHotel);
nodoFavoritos* crearNodoFavoritos(int dato);
nodoReservas* crearNodoReservas(stReserva dato);
nodoVoto* crearNodoVoto(int usuario, int voto);
nodoListaOfListaPuntajes* crearNodoPuntajes(int idHotel);
arbolFavoritos* crearNodoArbolFavoritos(int idHotel, int esFavorito);
arbolReservas* crearNodoArbolReservas(stReserva dato, int estaReservado);
nodoHospedaje* agregarNodoPpioHoteles(nodoHospedaje* listaHoteles, nodoHospedaje* nuevoNodo);
nodoFavoritos* agregarNodoPpioFavoritos(nodoFavoritos* listaFavoritos, nodoFavoritos* nuevoNodo);
nodoReservas* agregarNodoPpioReservas(nodoReservas* listaReservas, nodoReservas* nuevoNodo);
nodoVoto* agregarNodoPpioVotos(nodoVoto* listaVotos, nodoVoto* nuevoNodo);
nodoListaOfListaPuntajes* agregarNodoPpioListaOfListaPuntajes(nodoListaOfListaPuntajes* listaOfListaPuntajes, nodoListaOfListaPuntajes* nuevoNodo);
arbolFavoritos* agregarNodoArbol(arbolFavoritos* arbol, arbolFavoritos* nuevoNodo);
arbolReservas* agregarNodoArbolReservas(arbolReservas* arbol, arbolReservas* nuevoNodo);
arbolFavoritos* insertar(arbolFavoritos* arbol, arbolFavoritos* nuevoNodo);
arbolReservas* insertarReserva(arbolReservas* arbol, arbolReservas* nuevoNodo);
arbolFavoritos* crearArbolFavoritos(nodoHospedaje* listaHoteles, nodoFavoritos* listaFavoritos);
arbolReservas* crearArbolReservas(nodoHospedaje* listaHoteles, nodoReservas* listaReservas);
int buscarFavoritoArbol(int idHotel, arbolFavoritos* favoritos);
int buscarReservaArbol(int idHotel, arbolReservas* reservas);
arbolFavoritos* cambiarEstadoFavorito(arbolFavoritos* arbol, int idHotel);
arbolReservas* cambiarEstadoReserva(arbolReservas* arbol, int idHotel);


#endif // TDAHOTELES_H_INCLUDED
