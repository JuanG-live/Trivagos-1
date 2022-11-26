#ifndef HOTELES_H_INCLUDED
#define HOTELES_H_INCLUDED
#include "estructuras.h"
#include "utilities.h"
#include "persistencia.h"

int esHotelFavorito(int idHotel, nodoFavoritos* listaFavoritos);
int esHotelReservado(int idHotel, nodoReservas* listaReservas, stReserva* dato);
nodoHospedaje* mostrarTresHoteles(nodoHospedaje* listaHoteles, arbolFavoritos* favoritos, arbolReservas* reservas);
nodoHospedaje* aplicarFiltroTipo(nodoHospedaje* listaHoteles, int filtroTipo, int* cantidadFiltrado);
nodoHospedaje* aplicarFiltroWifi(nodoHospedaje* listaHoteles, int* cantidadFiltrado);
nodoHospedaje* aplicarFiltroPiscina(nodoHospedaje* listaHoteles, int* cantidadFiltrado);
nodoHospedaje* aplicarFiltroParking(nodoHospedaje* listaHoteles, int* cantidadFiltrado);
nodoHospedaje* filtrarPorNombre(nodoHospedaje* listaHoteles, char busqueda[NAME], int* cantidadFiltrado);
nodoHospedaje* aplicarFiltro(nodoHospedaje* listaHoteles, int filtroTipo, int wifi, int piscina, int parking, int* cantidadFiltrado, int totalHoteles);
nodoFavoritos* pasarArbolFavToListaFav(nodoFavoritos* listaFinalFavoritos, arbolFavoritos* arbolHotelesFavoritos);
nodoReservas* pasarArbolReservasToListaReservas(nodoReservas* listaFinalReservas, arbolReservas* arbolHotelesReservados);
nodoHospedaje* obtenerNodoElegido(nodoHospedaje* primeroLista, int posicionVista);
int puntuarHotel(int yaVoto, int respuesta);
void AgregaModificaVotoArchivo(int idHotel, int idUsuario, int nuevoVoto, int tipo);
float verificarSiUsuarioVoto(nodoListaOfListaPuntajes* listaPuntajes, int idUsuario, int idHotel);
void IncrementaHuespedes(int huesped, int* cantidadMayores, int* cantidadMenores);
void DecrementaHuespedes(int huesped, int* cantidadMayores, int* cantidadMenores);
void hotelesPorUsuario(stUsuario usuario);

#endif // HOTELES_H_INCLUDED
