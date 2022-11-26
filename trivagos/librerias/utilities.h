#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <strings.h>
#include <conio.h>
#include <math.h>
#include "constantes.h"
#include "gotoxy.h"
#include "estructuras.h"

void LimpiarMailErroneo();
void limpiaFormulario(int fromX, int toX, int posY, int caracter, int fondo, int color);
void MensajesErroresRegistro(char mensaje[], int posX, int posY);
void MensajesAdvertencias(char mensaje[], int posX, int posY, int colorLetra);
int ObtenerFecha(char output[]);
int ValidaMailCorrecto(char mail[]);
int CapturarPalabra(char palabra[], int posX, int posY, int cantidadChar, int type, int modo, int colorLetra);
int ModificarPalabra(char palabra[], char dato[],int posX, int posY, int cantidadChar, int colorLetra, int colorBorra, int formaBorra);
void MostrarMensaje(char mensaje[]);
void mostrarOcultarBarra(int* barraOpciones, int* barraBusqueda, int idMenu);
void salirSistema();

#endif // UTILITIES_H_INCLUDED
