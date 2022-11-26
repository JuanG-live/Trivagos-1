#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include "estructuras.h"
#include "gotoxy.h"
#include "ventanas.h"
#include "usuarios.h"

void settearConsola();
void Color(int Background, int Text);
void mostrarMatriz(stMatriz matriz[80][25], int posX, int posY, int columnas, int filas);
void mostrarMatrizHaciaArriba(stMatriz matriz[80][25], int posX, int posY, int columnas, int filas);
void mostrarBarraMenu(stMatriz matriz[80][5], int posX, int posY, int columnas, int filas);
void ocultarBarraMenu(stMatriz matriz[80][5], int posX, int posY, int columnas, int filas);
void selectHotelFromList(int posicion, int colorLetra);
void selectUsuarioFromList(int posicion, int colorLetra);
void crearMatrizTituloPerfil(stMatriz matriz[43][3]);
void crearMatrizTituloClave(stMatriz matriz[43][3]);
void crearMatrizNombrePerfil(stMatriz matriz[43][3]);
void crearMatrizLinea(stMatriz matriz[43][3]);
void crearMatrizDireccionPerfil(stMatriz matriz[43][3]);
void crearMatrizClaveAnterior(stMatriz matriz[43][3]);
void crearMatrizTelefonoPerfil(stMatriz matriz[43][3]);
void crearMatrizClaveNueva(stMatriz matriz[43][3]);
void crearMatrizCorreoPerfil(stMatriz matriz[43][3]);
void crearMatrizReClaveNueva(stMatriz matriz[43][3]);
void moverLineasPerfil(stMatriz matrizVista[43][3], stMatriz matrizNueva[43][3], int posY);
void mostrarVentanaReserva(int cantidadMayores, int cantidadMenores, stHospedaje hotel);
void mostrarVentanaVotar(int opcion, int voto);
void AnimacionVentanasPerfil();
void limpiarVentanaHoteles(int cantidadFiltrado);
void mostrarHotel(stHospedaje dato, int fav, int reserva, int posY);
void MarcarTipoHotel();
void MarcarTipoHostal();
void MarcarTipoDpto();
void MarcarTipoTodos();
void MarcarDesmarcarPiscina(int* piscina);
void MarcarDesmarcarWifi(int* wifi);
void MarcarDesmarcarParking(int* parking);
void ReiniciarVista(int* cantidadFiltrado, int* posicionSobreLista, int* posicionVista);
void CambioTipoHuesped(int* huesped);
int DevolverCoordenadaHoteles(int posicionVista);
void ModificarReservaEnVista(int estaReservado, int posY);
void ModificarFavoritosEnVista(int estaReservado, int posY);
void MostrarInfoAdminHospedaje(stHospedaje* hospedaje);
void mostrarVistaAdminHoteles(int posicionVista, int* barraOpciones, int* barraBusqueda);
void MarcarDesmarcarPiscinaAdmin(int* piscina);
void MarcarDesmarcarWifiAdmin(int* wifi);
void MarcarDesmarcarParkingAdmin(int* parking);
void ModificarActivoVista(int posY, nodoUsuario* nodoElegido);
void ModificarAdminVista(int posY, nodoUsuario* nodoElegido);

#endif // VISTA_H_INCLUDED
