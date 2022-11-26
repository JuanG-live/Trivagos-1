#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "estructuras.h"
#include "utilities.h"

nodoHospedaje* crearListaHoteles(const char nombreArchivo[NAME], int* cantidadFiltrado);
nodoHospedaje* crearListaHotelesUser(const char nombreArchivo[NAME], int* cantidadFiltrado);
nodoHospedaje* crearListaFavoritos(stUsuario usuario);
nodoReservas* crearListaReservas(stUsuario usuario);
nodoListaOfListaPuntajes* crearListaOfListaVotos();
void VerificarUserPassword(const char fileName[], stUsuario* usuario, int* userLogued, char username[], char password[]);
int validaExistenciaMail(const char fileName[],char mail[]);
int CantidadRegistros(const char nombreArchivo[], int sizeStruct);
int registrarUsuario(stUsuario usuario, const char fileName[]);
void obtenerDirectorio(stUsuario usuario, char buffer[], int* error);
void grabarFavoritosArchivo(stUsuario usuario, nodoFavoritos* listaFinalFavoritos);
void grabarReservasArchivo(stUsuario usuario, nodoReservas* listaFinalReservas);
void grabarUsuariosArchivo(nodoUsuario* listaUsuarios);
void GuardarInfoUsuario(const char nombreArchivo[], stUsuario usuarioModificado);
void modificarVotacion(const char nombreArchivo[], stPuntos puntosNuevos);
void agregarVotacion(const char nombreArchivo[], stPuntos puntosNuevos);
void guardarPromedioHotel(const char nombreArchivo[], stHospedaje hospedajeActualizado);
void guardarHotel(const char nombreArchivo[], nodoHospedaje* hospedajeActualizado);
void GuardarInfoHotel(const char nombreArchivo[], stHospedaje hotelModificado);
int grabarHospedaje(stHospedaje hospedaje);
nodoUsuario* crearListaUsuarios(const char nombreArchivo[NAME], int* cantidadFiltrado);
/// FUNCION QUE CARGO LOS PRIMEROS HOTELES

void DarDeAltaHoteles(const char nombreArchivo[NAME]);
#endif // PERSISTENCIA_H_INCLUDED
