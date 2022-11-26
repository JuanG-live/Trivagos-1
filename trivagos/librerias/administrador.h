#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "vista.h"
#include "utilities.h"
#include "estructuras.h"
#include "ventanas.h"
#include "persistencia.h"
#include "TDAHoteles.h"
#include "TDAUsuarios.h"
#include "ventanasAdmin.h"

void mostrarMatrizHotel(stMatriz matriz[COLUMNAS][FILASHOTEL], int posX, int posY, int columnas, int filas);
void mostrarMatrizAdministrador(stMatriz matriz[COLUMNAS][FILASADMIN], int posX, int posY, int columnas, int filas, int cantidadLineas);
void mostrarMatrizEditar(int posX, int posY);
void mostrarHotelElegido(int posicionLista, stHospedaje hotel);
void limpiarVentanaHotelesAdmin(int cantidadFiltrado);
void adminHoteles(int posicionVista, nodoHospedaje* hotelElegido);
void ModificarNombreHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado, stHospedaje* hospedaje);
void ModificaTipoHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
void ModificaEstrellasHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
void ModificaPrecioHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
void ModificaWifiHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
void ModificaPiscinaHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
void ModificaParkingHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado);
int modificarHospedajeSeleccionado(stHospedaje* hospedaje);
nodoHospedaje* agregarHospedajeEnOrdenNombre(nodoHospedaje* lista, nodoHospedaje* nuevo);
nodoHospedaje* agregarHospedajeEnOrdenPrecio(nodoHospedaje* lista, nodoHospedaje* nuevo);
nodoHospedaje* ordenarListaHospedajes(nodoHospedaje* primeroLista, int* cantidadFiltrado, int tipoOrden);
void darDeBaja_AltaHotel(nodoHospedaje* hotel);
void selectHotelFromListAdmin(int posicion, int colorLetra);
nodoHospedaje* mostrarCuatroHoteles(nodoHospedaje* listaHoteles);
void IngresarNombreHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeAux);
void IngresarTipoHospedaje(char* teclaNuevoHospedaje, int* tipoAlojamiento);
void IngresarEstrellasHospedaje(char* teclaNuevoHospedaje, int* cantidadEstrellas);
void IngresarPrecioHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeAux);
void IngresarWifiHospedaje(char* teclaNuevoHospedaje, int* wifi);
void IngresarPiscinaHospedaje(char* teclaNuevoHospedaje, int* pileta);
void IngresarParkingHospedaje(char* teclaNuevoHospedaje, int* parking);
void agregarAlojamientoBD(stHospedaje* hospedajeAux);
void administrarHospedaje();
nodoUsuario* modificarListaUsuarios(nodoUsuario* firstLista, stUsuario usuario);
int obtenerCoordenadaActivoAdminUsuario(int posicionVista, int opcion);
nodoUsuario* obtenerNodoElegidoUsuario(nodoUsuario* primeroLista, int posicionVista);
nodoUsuario* filtrarPorNombreUsuario(nodoUsuario* listaUsuarios, char busqueda[NAME], int* cantidadFiltrado);
void limpiarVentanaHotelesAdminByUser(int cantidadFiltrado);
void selectHotelFromListAdminByUser(int posicion, int colorLetra);
void mostrarUsuario(stUsuario dato, int posY);
nodoUsuario* mostrarCincoUsuarios(nodoUsuario* listaUsuarios);
void limpiarVentanaCincoUsuarios(int cantidadFiltrado);
nodoUsuario* agregarUsuarioEnOrden(nodoUsuario* lista, nodoUsuario* nuevo);
nodoUsuario* ordenarPorNombreListaUsuarios(nodoUsuario* primeroLista, int* cantidadFiltrado);
nodoUsuario* administrarFavoritosReservasUsuario(nodoUsuario* firstLista, int posVista);
void administrarUsuarios();
void administrador();


#endif //ADMINISTRADOR_H_INCLUDED
